#include "common-chax.h"
#include "debuff.h"
#include "weapon-range.h"
#include "kernel-lib.h"
#include "map-anims.h"
#include "skill-system.h"
#include "unit-expa.h"
#include "action-expa.h"
#include "constants/skills.h"
#include "constants/texts.h"

STATIC_DECLAR void AddTargetForGoddessDance(struct Unit * unit)
{
    if (UNIT_ALIVE(unit) && AreUnitsAllied(gSubjectUnit->index, unit->index))
        AddTarget(unit->xPos, unit->yPos, unit->index, 1);
}

STATIC_DECLAR void MakeTargetListForGoddessDance(struct Unit * unit)
{
    int x = unit->xPos;
    int y = unit->yPos;

    gSubjectUnit = unit;
    BmMapFill(gBmMapRange, 0);
    MapAddInBoundedRange(x, y, 1, 1);

    InitTargets(x, y);
    ForEachUnitInRange(AddTargetForGoddessDance);
}

u8 GoddessDance_Usability(const struct MenuItemDef * def, int number)
{
    if (gActiveUnit->state & US_CANTOING)
        return MENU_NOTSHOWN;

    if (!HasSelectTarget(gActiveUnit, MakeTargetListForGoddessDance))
        return MENU_DISABLED;

    return MENU_ENABLED;
}

int GoddessDance_Hover(struct MenuProc * menu, struct MenuItemProc * item)
{
    BmMapFill(gBmMapMovement, -1);
    BmMapFill(gBmMapRange, 0);
    GenerateUnitStandingReachRange(gActiveUnit, 0b11);
    DisplayMoveRangeGraphics(MOVLIMITV_MMAP_BLUE | MOVLIMITV_RMAP_GREEN);
    return 0;
}

int GoddessDance_Unhover(struct MenuProc * menu, struct MenuItemProc * menuItem)
{
    HideMoveRangeGraphics();
    return 0;
}

u8 GoddessDance_OnSelected(struct MenuProc * menu, struct MenuItemProc * item)
{
    if (item->availability == MENU_DISABLED)
    {
        MenuFrozenHelpBox(menu, MSG_MenuSkill_GoddessDance_FRtext);
        return MENU_ACT_SND6B;
    }

    gActionData.unk08 = SID_GoddessDance;
    gActionData.unitActionType = CONFIG_UNIT_ACTION_EXPA_ExecSkill;

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SND6A | MENU_ACT_CLEAR;
}

static void callback_anim(ProcPtr proc)
{
    StartNinianPrayfx(proc, SCREEN_TILE_X(gActiveUnit->xPos), SCREEN_TILE_Y(gActiveUnit->yPos));
}

static void callback_exec(ProcPtr proc)
{
    int i;

    MakeTargetListForGoddessDance(gActiveUnit);

    for (i = 0; i < GetSelectTargetCount(); i++)
    {
        struct Unit * unit = GetUnit(GetTarget(i)->uid);
        if (!UNIT_ALIVE(unit) && unit != gActiveUnit)
            continue;

        SetBitUES(unit, UES_BIT_TSZUKU_SKILL_USED);
        unit->state &= ~(US_UNSELECTABLE);
    }
}

bool Action_GoddessDance(ProcPtr parent)
{
    NewMuSkillAnimOnActiveUnit(gActionData.unk08, callback_anim, callback_exec);
    return true;
}
