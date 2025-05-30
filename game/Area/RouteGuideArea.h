#pragma once

#include <math/seadVector.h>

#include "Library/Area/AreaObj.h"

class RouteGuideArea : public al::AreaObj {
public:
    RouteGuideArea(const char* name);

    void init(const al::AreaInitInfo& areaInitInfo) override;
    void calcGuidePos(sead::Vector3f* guidePos) const;

public:
    sead::Vector3f mTargetPosition = {0.0f, 0.0f, 0.0f};
    bool mIsGuide3D = false;
};
