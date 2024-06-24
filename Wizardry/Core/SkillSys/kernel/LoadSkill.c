#include "global.h"
#include "bmunit.h"

#include "common-chax.h"
#include "bwl.h"
#include "kernel-lib.h"
#include "skill-system.h"
#include "constants/skills.h"

#define LOCAL_TRACE 0

bool CanRemoveSkill(struct Unit * unit, const u16 sid)
{
    int i;
    u8 * list = UNIT_RAM_SKILLS(unit);

    if (!GENERIC_SKILL_VALID(sid))
        return false;

    for (i = 0; i < UNIT_RAM_SKILLS_LEN; i++)
        if (sid == list[i])
            return true;

    return false;
}

int RemoveSkill(struct Unit * unit, const u16 sid)
{
    int i;
    u8 * list = UNIT_RAM_SKILLS(unit);

    if (!GENERIC_SKILL_VALID(sid))
        return -1;

    for (i = 0; i < UNIT_RAM_SKILLS_LEN; i++)
        if (sid == list[i])
        {
            list[i] = 0;
            ResetSkillLists();
            return 0;
        }
    return -1;
}

int AddSkill(struct Unit * unit, const u16 sid)
{
    int i;
    u8 * list = UNIT_RAM_SKILLS(unit);

    if (sid >= MAX_GENERIC_SKILL_NUM)
        return -1;

    LearnSkill(unit, sid);

    for (i = 0; i < UNIT_RAM_SKILLS_LEN; i++)
    {
        if (!GENERIC_SKILL_VALID(list[i]))
        {
            list[i] = sid;
            ResetSkillLists();
            return 0;
        }
    }
    return -1;
}

void UnitAutoLoadSkills(struct Unit * unit)
{
    u16 sid;
    int i;
    const struct SkillPreloadPConf * pConf = &gSkillPreloadPData[UNIT_CHAR_ID(unit)];
    const struct SkillPreloadJConf * jConf = &gSkillPreloadJData[UNIT_CLASS_ID(unit)];
    int level = simple_div(unit->level, 5) * 5;

    LIMIT_AREA(level, 0, UNIT_LEVEL_MAX_RE);

    while (level >= 0)
    {
        for (i = 0; i < 5; i++)
        {
            sid = pConf->skills[level + i];
            if (GENERIC_SKILL_VALID(sid))
            {
                if (UNIT_FACTION(unit) == FACTION_BLUE)
                    LearnSkill(unit, sid);

                AddSkill(unit, sid);
            }

            sid = jConf->skills[level + i];
            if (GENERIC_SKILL_VALID(sid))
            {
                if (UNIT_FACTION(unit) == FACTION_BLUE)
                    LearnSkill(unit, sid);

                AddSkill(unit, sid);
            }
        }
        level = level - 5;
    }

#ifdef CONFIG_DEBUG_UNIT_LOAD_SKILL
    /* For debug, we enable unit learn all of skills */
    if (UNIT_FACTION(unit) == FACTION_BLUE)
    {
        LTRACEF("Character %#x auto learned skill", UNIT_CHAR_ID(unit));

        for (i = 1; i < 254; i++)
            LearnSkill(unit, i);
    }
#endif
}

STATIC_DECLAR void TryAddSkillLvupJConf(struct Unit * unit, int level)
{
    int i;
    u16 sid;

    const struct SkillPreloadPConf * pConf = &gSkillPreloadPData[UNIT_CLASS_ID(unit)];
    int _level = simple_div(level, 5) * 5;

    for (i = 0; i < 5; i++)
    {
        sid = pConf->skills[_level + i];

        if (GENERIC_SKILL_VALID(sid))
            AddSkill(unit, sid);
    }
}

STATIC_DECLAR void TryAddSkillLvupPConf(struct Unit * unit, int level)
{
    int i;
    u16 sid;

    const struct SkillPreloadJConf * jConf = &gSkillPreloadJData[UNIT_CLASS_ID(unit)];
    int _level = simple_div(level, 5) * 5;

    for (i = 0; i < 5; i++)
    {
        sid = jConf->skills[_level + i];

        if (GENERIC_SKILL_VALID(sid))
            AddSkill(unit, sid);
    }
}

void TryAddSkillLvup(struct Unit * unit, int level)
{
    int _level;

    if (!UNIT_IS_VALID(unit))
        return;

    _level = level;
    if (simple_mod(_level, 5))
        TryAddSkillLvupJConf(unit, _level);

    _level = level + GetUnitHiddenLevel(unit);
    if (simple_mod(_level, 5))
        TryAddSkillLvupPConf(unit, _level);
}

void TryAddSkillPromotion(struct Unit * unit, int jid)
{
    int i;
    u16 sid;

    const struct SkillPreloadJConf * jConf = &gSkillPreloadJData[jid];

    if (!UNIT_IS_VALID(unit))
        return;

    for (i = 0; i < 5; i++)
    {
        sid = jConf->skills[0 + i];

        if (GENERIC_SKILL_VALID(sid))
            AddSkill(unit, sid);
    }
}
