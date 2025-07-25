#pragma once

#include "Amiibo/HelpAmiiboExecutor.h"

namespace al {
struct NfpInfo;

struct ActorInitInfo;
class LiveActor;
}  // namespace al

class LifeMaxUpItem;
class LifeMaxUpItem2D;

class HelpAmiiboLifeMaxUpItem : public HelpAmiiboExecutor {
public:
    HelpAmiiboLifeMaxUpItem(HelpAmiiboDirector* director, al::LiveActor* actor);

    void initAfterPlacement(const al::ActorInitInfo& initInfo) override;
    bool isTriggerTouch(const al::NfpInfo& nfpInfo) const override;
    bool isEnableUse() override;
    bool execute() override;
    void activate() override;

    HelpAmiiboType getType() const override { return HelpAmiiboType::Peach; }

public:
    LifeMaxUpItem* mItem = nullptr;
    LifeMaxUpItem2D* mItem2D = nullptr;
};
