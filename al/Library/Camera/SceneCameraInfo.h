#pragma once

#include <basis/seadTypes.h>

namespace al {

class CameraViewInfo;

class SceneCameraInfo {
public:
    SceneCameraInfo(s32 maxViewNum);

    void initViewInfo(CameraViewInfo* cameraViewInfo);
    const char* getViewName(s32 num) const;

    s32 getViewNumMax() const { return mViewNumMax; }

    CameraViewInfo* getViewAt(s32 viewIdx) const { return mViewArray[viewIdx]; }

public:
    s32 mViewNumMax;
    CameraViewInfo** mViewArray;
};

}  // namespace al
