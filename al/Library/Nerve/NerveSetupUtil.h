#pragma once

#include <prim/seadStorageFor.h>

#include "Library/Base/Macros.h"
#include "Library/Nerve/Nerve.h"
#include "Library/Nerve/NerveAction.h"
#include "Library/Nerve/NerveKeeper.h"

#define NERVE_IMPL_(Class, Action, ActionFunc)                                                                                                       \
    class Class##Nrv##Action : public al::Nerve {                                                                                                    \
    public:                                                                                                                                          \
        void execute(al::NerveKeeper* keeper) const override { (keeper->getParent<Class>())->exe##ActionFunc(); }                                    \
    };

#define NERVE_IMPL_INSTANCE_(Class, Action, ActionFunc)                                                                                              \
    Class##Nrv##Action Class##Nrv##Action::sInstance = {};                                                                                           \
    void Class##Nrv##Action::execute(al::NerveKeeper* keeper) const { (keeper->getParent<Class>())->exe##ActionFunc(); }                             \

#define NERVE_HEADER_INSTANCE_(Class, Action, ActionFunc)                                                                                            \
    class Class##Nrv##Action : public al::Nerve {                                                                                                    \
    public:                                                                                                                                          \
        void execute(al::NerveKeeper* keeper) const override;                                                                                        \
        static Class##Nrv##Action sInstance;                                                                                                         \
    };

#define NERVE_IMPL(Class, Action) NERVE_IMPL_(Class, Action, Action)

#define NERVE_MAKE(Class, Action) Class##Nrv##Action Action;