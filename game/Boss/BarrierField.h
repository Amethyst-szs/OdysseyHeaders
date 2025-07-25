#pragma once

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class BarrierField : public al::LiveActor {
public:
    BarrierField(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void appear() override;
    void kill() override;
    void disappearByShineGet();

    void exeAppear();
    void exeAppearBreedaMoonWorld();
    void exeHide();
    void exeDisappear();

public:
    bool mIsDisappearByShineGet = false;
    bool mIsMoon = false;
};
