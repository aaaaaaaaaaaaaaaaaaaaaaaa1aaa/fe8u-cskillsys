#pragma once

#include "common-chax.h"

#define STAT_BAR_MAX_INDENTIFIER 41

typedef const struct HelpBoxInfo _DECL_INFO;
extern _DECL_INFO * const RTextPageUnit, * const RTextPageSupport;

extern struct {
    u8 talkee;
    u8 _pad_[3];
} gStatScreenStExpa;

void HbPopuplate_Page1TrvTalk(struct HelpBoxProc * proc);

void StartSkillScreenHelp(int pageid, struct Proc * proc);

void DrawSkillPage_MokhaPlanA(void);
void HbPopuplate_SkillPageCommon(struct HelpBoxProc * proc);
void HbRedirect_SkillPageCommon(struct HelpBoxProc * proc);
extern _DECL_INFO * const RTextSkillPage_MokhaPlanA;
