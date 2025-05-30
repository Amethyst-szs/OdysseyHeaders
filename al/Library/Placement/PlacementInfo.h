#pragma once

#include "Library/Yaml/ByamlIter.h"

namespace al {
class PlacementInfo {
public:
    PlacementInfo();

    void set(const ByamlIter& placement_iter, const ByamlIter& zone_iter);

    const ByamlIter& getPlacementIter() const { return mPlacementIter; }

    const ByamlIter& getZoneIter() const { return mZoneIter; }

public:
    void setPlacementIter(const ByamlIter& placementIter) { mPlacementIter = placementIter; }

    void setZoneIter(const ByamlIter& zoneIter) { mZoneIter = zoneIter; }

public:
    ByamlIter mPlacementIter;
    ByamlIter mZoneIter;
};
}  // namespace al
