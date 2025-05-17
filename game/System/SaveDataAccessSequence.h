#pragma once

#include "Library/Nerve/Nerve.h"
#include "Library/Nerve/IUseNerve.h"

#include "Project/SaveDataSequenceBase.h"

#include "sead/container/seadPtrArray.h"
#include "sead/prim/seadSafeString.h"

#include "types.h"

class GameDataHolder; // Forward Declaration

class SaveDataAcessSequenceLayoutCtrl;

class SaveDataAccessSequence : public al::IUseNerve, protected al::SaveDataSequenceBase {
public:
    GameDataHolder* mGameData;
    SaveDataAcessSequenceLayoutCtrl* mLayoutCtrl;
    bool mIsDisableSave; // Disables manual and auto saves
    bool mIsDevEnabled; // Causes the game to constantly autosave I think
    sead::PtrArray<sead::SafeString> mFileNames; // Common.bin comes first, then File1-5.bin, 6 entries
    sead::PtrArray<void*> mPtrArray2; // Each entry is 0x18 size
    sead::PtrArray<void*> mPtrArray3;
    bool mIsStartWrite; // Flag set for first bit of save process
};