#include "common-chax.h"
#include "combat-art.h"
#include "debuff.h"
#include "constants/combat-arts.h"
#include "constants/texts.h"
#include "constants/gfx.h"

const struct CombatArtInfo gCombatArtInfos[0x100] = {
    /* Sword arts */
    [CID_WrathStrike] = {
        .name = MSG_COMART_NAME_WrathStrike,
        .icon = GFX_CombatArtIcon_SwordArtAtk,
        .wtype = ITYPE_SWORD,
        .cost = 3,
        .battle_status.atk = 5,
        .battle_status.hit = 10,
    },
    [CID_Grounder] = {
        .name = MSG_COMART_NAME_Grounder,
        .desc = MSG_COMART_DESC_Grounder,
        .icon = GFX_CombatArtIcon_SwordArtAtk,
        .wtype = ITYPE_SWORD,
        .cost = 4,
        .battle_status.atk = 5,
        .battle_status.hit = 20,
        .battle_status.crit = 5,
        .effectiveness = COMBART_EFF_FLIER,
    },
    [CID_Soulblade] = {
        .name = MSG_COMART_NAME_Soulblade,
        .desc = MSG_COMART_DESC_Soulblade,
        .icon = GFX_CombatArtIcon_SwordArtMag,
        .wtype = ITYPE_SWORD,
        .cost = 2,
        .battle_status.atk = 1,
        .battle_status.hit = 10,
        .magic_attack = true,
    },
    [CID_BaneOfMonsters] = {
        .name = MSG_COMART_NAME_BaneOfMonsters,
        .desc = MSG_COMART_DESC_BaneOfMonsters,
        .icon = GFX_CombatArtIcon_SwordArtAtk,
        .wtype = ITYPE_SWORD,
        .cost = 4,
        .battle_status.atk = 6,
        .battle_status.crit = 10,
        .effectiveness = COMBART_EFF_MONSTER,
    },
    [CID_Sunder] = {
        .name = MSG_COMART_NAME_Sunder,
        .icon = GFX_CombatArtIcon_SwordArtCrit,
        .wtype = ITYPE_SWORD,
        .cost = 3,
        .battle_status.atk = 4,
        .battle_status.crit = 15,
    },
    [CID_Hexblade] = {
        .name = MSG_COMART_NAME_Hexblade,
        .desc = MSG_COMART_DESC_Hexblade,
        .icon = GFX_CombatArtIcon_SwordArtMag,
        .wtype = ITYPE_SWORD,
        .cost = 3,
        .battle_status.atk = 7,
        .battle_status.hit = 10,
        .magic_attack = true,
    },
    [CID_HazeSlice] = {
        .name = MSG_COMART_NAME_HazeSlice,
        .icon = GFX_CombatArtIcon_SwordArtAtk,
        .wtype = ITYPE_SWORD,
        .cost = 5,
        .battle_status.atk = 4,
        .battle_status.avo = 30,
    },
    [CID_FinesseBlade] = {
        .name = MSG_COMART_NAME_FinesseBlade,
        .desc = MSG_COMART_DESC_FinesseBlade,
        .icon = GFX_CombatArtIcon_SwordArtAtk,
        .wtype = ITYPE_SWORD,
        .cost = 4,
        .battle_status.atk = 2,
        .battle_status.avo = 10,
    },
    [CID_Assassinate] = {
        .name = MSG_COMART_NAME_Assassinate,
        .desc = MSG_COMART_DESC_Assassinate,
        .icon = GFX_CombatArtIcon_SwordArtCrit,
        .wtype = ITYPE_SWORD,
        .cost = 4,
        .battle_status.hit = 15,
        .battle_status.silencer = 50,
        .battle_status.crit = 15,
    },
    [CID_FoudroyantStrike] = {
        .name = MSG_COMART_NAME_FoudroyantStrike,
        .desc = MSG_COMART_DESC_FoudroyantStrike,
        .icon = GFX_CombatArtIcon_SwordArtCrit,
        .wtype = ITYPE_SWORD,
        .cost = 3,
        .battle_status.atk = 6,
        .battle_status.hit = 30,
        .battle_status.crit = 30,
        .effectiveness = COMBART_EFF_ARMOR,
    },

    /* Lance arts */
    [CID_TempestLance] = {
        .name = MSG_COMART_NAME_TempestLance,
        .desc = 0,
        .icon = GFX_CombatArtIcon_LanceArtAtk,
        .wtype = ITYPE_LANCE,
        .cost = 5,
        .battle_status.atk = 8,
        .battle_status.hit = 10,
    },
    [CID_Knightkneeler] = {
        .name = MSG_COMART_NAME_Knightkneeler,
        .desc = MSG_COMART_DESC_Knightkneeler,
        .icon = GFX_CombatArtIcon_LanceArtAtk,
        .wtype = ITYPE_LANCE,
        .cost = 4,
        .battle_status.atk = 5,
        .battle_status.hit = 15,
        .battle_status.crit = 10,
        .effectiveness = COMBART_EFF_CAVALRY,
    },
    [CID_ShatterSlash] = {
        .name = MSG_COMART_NAME_ShatterSlash,
        .desc = MSG_COMART_DESC_ShatterSlash,
        .icon = GFX_CombatArtIcon_LanceArtAtk,
        .wtype = ITYPE_LANCE,
        .cost = 3,
        .battle_status.atk = 4,
        .battle_status.hit = 10,
        .debuff = NEW_UNIT_STATUS_PIERCE_ARMOR,
    },
    [CID_MonsterPiercer] = {
        .name = MSG_COMART_NAME_MonsterPiercer,
        .desc = MSG_COMART_DESC_MonsterPiercer,
        .icon = GFX_CombatArtIcon_LanceArtCrit,
        .wtype = ITYPE_LANCE,
        .cost = 4,
        .battle_status.atk = 5,
        .battle_status.crit = 10,
        .effectiveness = COMBART_EFF_MONSTER,
    },
    [CID_SwiftStrikes] = {
        .name = MSG_COMART_NAME_SwiftStrikes,
        .desc = MSG_COMART_DESC_SwiftStrikes,
        .icon = GFX_CombatArtIcon_LanceArtAtk,
        .wtype = ITYPE_LANCE,
        .cost = 2,
        .battle_status.atk = 2,
        .battle_status.crit = 5,
        .double_attack = COMBART_DOUBLE_FORCE_ENABLED,
    },
    [CID_FrozenLance] = {
        .name = MSG_COMART_NAME_FrozenLance,
        .desc = MSG_COMART_DESC_FrozenLance,
        .icon = GFX_CombatArtIcon_LanceArtMag,
        .wtype = ITYPE_LANCE,
        .cost = 4,
        .battle_status.atk = 2,
        .battle_status.crit = 10,
        .magic_attack = true,
    },
    [CID_Vengeance] = {
        .name = MSG_COMART_NAME_Vengeance,
        .desc = MSG_COMART_DESC_Vengeance,
        .icon = GFX_CombatArtIcon_LanceArtCrit,
        .wtype = ITYPE_LANCE,
        .cost = 4,
        .battle_status.atk = 5,
        .battle_status.hit = 20,
        .battle_status.crit = 5,
    },
    [CID_LanceJab] = {
        .name = MSG_COMART_NAME_LanceJab,
        .desc = MSG_COMART_DESC_LanceJab,
        .icon = GFX_CombatArtIcon_LanceArtAtk,
        .wtype = ITYPE_LANCE,
        .cost = 5,
        .battle_status.atk = 3,
        .battle_status.crit = 10,
    },

    /* Axe arts */
    [CID_Smash] = {
        .name = MSG_COMART_NAME_Smash,
        .icon = GFX_CombatArtIcon_AxeArtAtk,
        .wtype = ITYPE_AXE,
        .cost = 5,
        .battle_status.atk = 3,
        .battle_status.hit = 20,
        .battle_status.crit = 20,
    },
    [CID_HelmSplitter] = {
        .name = MSG_COMART_NAME_HelmSplitter,
        .desc = MSG_COMART_DESC_HelmSplitter,
        .icon = GFX_CombatArtIcon_AxeArtAtk,
        .wtype = ITYPE_AXE,
        .cost = 5,
        .battle_status.atk = 7,
        .battle_status.crit = 5,
        .effectiveness = COMBART_EFF_ARMOR,
    },
    [CID_MonsterBreaker] = {
        .name = MSG_COMART_NAME_MonsterBreaker,
        .desc = MSG_COMART_DESC_MonsterBreaker,
        .icon = GFX_CombatArtIcon_AxeArtCrit,
        .wtype = ITYPE_AXE,
        .cost = 5,
        .battle_status.atk = 5,
        .battle_status.crit = 15,
        .effectiveness = COMBART_EFF_MONSTER,
    },
    [CID_FocusedStrike] = {
        .name = MSG_COMART_NAME_FocusedStrike,
        .icon = GFX_CombatArtIcon_AxeArtAtk,
        .wtype = ITYPE_AXE,
        .cost = 3,
        .battle_status.hit = 30,
    },
    [CID_WildAbandon] = {
        .name = MSG_COMART_NAME_WildAbandon,
        .icon = GFX_CombatArtIcon_AxeArtCrit,
        .wtype = ITYPE_AXE,
        .cost = 5,
        .battle_status.atk = 10,
        .battle_status.hit = -30,
        .battle_status.crit = 30,
    },
    [CID_Spike] = {
        .name = MSG_COMART_NAME_Spike,
        .icon = GFX_CombatArtIcon_AxeArtAtk,
        .wtype = ITYPE_AXE,
        .cost = 5,
        .battle_status.atk = 5,
        .battle_status.hit = 15,
        .battle_status.crit = 10,
    },
    [CID_DiamondAxe] = {
        .name = MSG_COMART_NAME_DiamondAxe,
        .icon = GFX_CombatArtIcon_AxeArtAtk,
        .wtype = ITYPE_AXE,
        .cost = 7,
        .battle_status.atk = 14,
        .battle_status.hit = -20,
    },
    [CID_LightningAxe] = {
        .name = MSG_COMART_NAME_LightningAxe,
        .desc = MSG_COMART_DESC_LightningAxe,
        .icon = GFX_CombatArtIcon_AxeArtMag,
        .wtype = ITYPE_AXE,
        .cost = 3,
        .battle_status.atk = 4,
        .magic_attack = true,
    },
    [CID_ArmoredStrike] = {
        .name = MSG_COMART_NAME_ArmoredStrike,
        .desc = MSG_COMART_DESC_ArmoredStrike,
        .icon = GFX_CombatArtIcon_AxeArtAtk,
        .wtype = ITYPE_AXE,
        .cost = 4,
        .battle_status.atk = 3,
        .battle_status.hit = 10,
    },
    [CID_WarMasterStrike] = {
        .name = MSG_COMART_NAME_WarMasterStrike,
        .desc = MSG_COMART_DESC_WarMasterStrike,
        .icon = GFX_CombatArtIcon_AxeArtCrit,
        .wtype = ITYPE_AXE,
        .cost = 5,
        .battle_status.atk = 3,
        .battle_status.hit = 30,
        .battle_status.crit = 10,
        .effectiveness = COMBART_EFF_ALL,
    },
    [CID_FlickeringFlower] = {
        .name = MSG_COMART_NAME_FlickeringFlower,
        .desc = MSG_COMART_DESC_FlickeringFlower,
        .icon = GFX_CombatArtIcon_AxeArtDebuff,
        .wtype = ITYPE_AXE,
        .cost = 3,
        .battle_status.atk = 10,
        .battle_status.hit = 10,
        .debuff = NEW_UNIT_STATUS_HEAVY_GRAVITY,
    },

    /* Bow arts */
    [CID_CurvedShot] = {
        .name = MSG_COMART_NAME_CurvedShot,
        .icon = GFX_CombatArtIcon_BowArtAtk,
        .desc = 0,
        .wtype = ITYPE_BOW,
        .cost = 3,
        .range_bonus = 1,
        .battle_status.atk = 1,
        .battle_status.crit = 30,
    },
    [CID_Deadeye] = {
        .name = MSG_COMART_NAME_Deadeye,
        .icon = GFX_CombatArtIcon_BowArtAtk,
        .desc = 0,
        .wtype = ITYPE_BOW,
        .cost = 5,
        .range_bonus = 3,
        .battle_status.atk = 6,
    },
    [CID_Encloser] = {
        .name = MSG_COMART_NAME_Encloser,
        .desc = MSG_COMART_DESC_Encloser,
        .icon = GFX_CombatArtIcon_BowArtDebuff,
        .wtype = ITYPE_BOW,
        .cost = 5,
        .range_bonus = 1,
        .battle_status.hit = 10,
        .debuff = NEW_UNIT_STATUS_HEAVY_GRAVITY,
    },
    [CID_EncloserPlus] = {
        .name = MSG_COMART_NAME_EncloserPlus,
        .desc = MSG_COMART_DESC_EncloserPlus,
        .icon = GFX_CombatArtIcon_BowArtDebuff,
        .wtype = ITYPE_BOW,
        .cost = 7,
        .range_bonus = 2,
        .battle_status.hit = 20,
        .debuff = NEW_UNIT_STATUS_HEAVY_GRAVITY,
        .aoe_debuff = true,
    },
    [CID_MonsterBlast] = {
        .name = MSG_COMART_NAME_MonsterBlast,
        .desc = MSG_COMART_DESC_MonsterBlast,
        .icon = GFX_CombatArtIcon_BowArtCrit,
        .wtype = ITYPE_BOW,
        .cost = 4,
        .battle_status.atk = 5,
        .battle_status.crit = 10,
        .effectiveness = COMBART_EFF_MONSTER,
    },
    [CID_SchismShot] = {
        .name = MSG_COMART_NAME_SchismShot,
        .desc = MSG_COMART_DESC_SchismShot,
        .icon = GFX_CombatArtIcon_BowArtMag,
        .wtype = ITYPE_BOW,
        .cost = 3,
        .range_bonus = 1,
        .battle_status.atk = 4,
        .battle_status.hit = 15,
        .magic_attack = true,
        .debuff = NEW_UNIT_STATUS_PIERCE_MAGIC,
    },
    [CID_BreakShot] = {
        .name = MSG_COMART_NAME_BaneOfMonsters,
        .desc = MSG_COMART_DESC_BaneOfMonsters,
        .icon = GFX_CombatArtIcon_BowArtDebuff,
        .wtype = ITYPE_BOW,
        .cost = 3,
        .range_bonus = 1,
        .battle_status.hit = 10,
        .debuff = NEW_UNIT_STATUS_PIERCE_ARMOR,
    },
    [CID_BreakShotPlus] = {
        .name = MSG_COMART_NAME_BreakShotPlus,
        .desc = MSG_COMART_DESC_BreakShotPlus,
        .icon = GFX_CombatArtIcon_BowArtDebuff,
        .wtype = ITYPE_BOW,
        .cost = 5,
        .range_bonus = 2,
        .battle_status.hit = 20,
        .debuff = NEW_UNIT_STATUS_PIERCE_ARMOR,
        .aoe_debuff = true,
    },
    [CID_WaningShot] = {
        .name = MSG_COMART_NAME_WaningShot,
        .desc = MSG_COMART_DESC_WaningShot,
        .icon = GFX_CombatArtIcon_BowArtDebuff,
        .wtype = ITYPE_BOW,
        .cost = 3,
        .range_bonus = 1,
        .battle_status.atk = 4,
        .battle_status.hit = 10,
        .debuff = NEW_UNIT_STATUS_WEAKEN,
    },
    [CID_WaningShotPlus] = {
        .name = MSG_COMART_NAME_WaningShotPlus,
        .desc = MSG_COMART_DESC_WaningShotPlus,
        .icon = GFX_CombatArtIcon_BowArtDebuff,
        .wtype = ITYPE_BOW,
        .cost = 5,
        .range_bonus = 2,
        .battle_status.hit = 20,
        .debuff = NEW_UNIT_STATUS_WEAKEN,
        .aoe_debuff = true,
    },
    [CID_HuntersVolley] = {
        .name = MSG_COMART_NAME_HuntersVolley,
        .desc = MSG_COMART_DESC_HuntersVolley,
        .icon = GFX_CombatArtIcon_BowArtAtk,
        .wtype = ITYPE_BOW,
        .cost = 2,
        .range_bonus = 1,
        .battle_status.atk = 1,
        .battle_status.hit = 15,
        .battle_status.crit = 10,
        .double_attack = COMBART_DOUBLE_FORCE_ENABLED,
    },
    [CID_Galeforce] = {
        .name = MSG_COMART_NAME_Galeforce,
        .desc = MSG_SKILL_CA_Galeforce,
        .icon = GFX_SkillIcon_Galeforce,
        .wtype = CA_WTYPE_ANY,
        .cost = 3,

        .battle_status.atk = 3,
        .battle_status.display_en_n = true,
    },
    [CID_Gamble] = {
        .name = MSG_SKILL_CA_Gamble_NAME,
        .desc = MSG_SKILL_CA_Gamble,
        .icon = GFX_SkillIcon_Gamble,
        .wtype = CA_WTYPE_ANY,
        .cost = 1,
        .battle_status.display_en_n = true,
        .double_attack = COMBART_DOUBLE_ENABLED,
    },
};
