#pragma once

#include <random>

#include "ECS/ECS.h"
#include "ECS/System/BasicSystem.h"

namespace Sourcehold {
    namespace ECS {
        namespace System {
            class TestTeleportingDeerSystem: public BasicSystem<const Component::EntityType, Component::Position> {
                public:
                TestTeleportingDeerSystem() {};
                virtual void each(entt::registry &registry, EachEntityType entity) override;
                virtual void beforeRun() override {};
            };
        }
    }
}
