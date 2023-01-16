#include "include/ParticleScrs.hpp"


namespace common
{
    auto short_time_generator = std::make_shared<TimeGenerator>(2, 4);
    auto long_time_generator = std::make_shared<TimeGenerator>(6, 12);
    auto random_color_generator = std::make_shared<RandomColorGenerator>();
}


ExplosionScr::ExplosionScr(float emit_rate, ofVec3f PosOrigin, float power, ofColor min_color, ofColor max_color) : ParticleScr(emit_rate, PosOrigin)
{
    addGenerator(std::make_shared<TimeGenerator>(0.5f, 1.f));
    addGenerator(std::make_shared<RandomColorGenerator>(min_color, max_color));
    addGenerator(std::make_shared<SpherePositionGenerator>(&this->PosOrigin, 1));
    addGenerator(std::make_shared<VelocityGenerator>(ofVec3f(-power), ofVec3f(power)));
    addUpdater(std::make_shared<GravityUpdater>());
    addUpdater(std::make_shared<EulerUpdater>());
    addUpdater(std::make_shared<TimeUpdater>());
    addUpdater(std::make_shared<TimeColorUpdater>());
}

SnowfallScr::SnowfallScr(float emit_rate, ofVec3f PosOrigin, float radius) : ParticleScr(emit_rate, PosOrigin)
{
    addGenerator(common::long_time_generator);
    addGenerator(std::make_shared<RandomColorGenerator>(ofColor(255, 230, 255), ofColor(255, 255, 255)));
    addGenerator(std::make_shared<CylinderPositionGenerator>(PosOrigin, radius, 1));
    addGenerator(std::make_shared<VelocityGenerator>(ofVec3f(0), ofVec3f(0)));
    addUpdater(std::make_shared<GravityUpdater>());
    addUpdater(std::make_shared<EulerUpdater>());
    addUpdater(std::make_shared<FloorUpdater>());
    addUpdater(std::make_shared<TimeUpdater>());
    addUpdater(std::make_shared<TimeColorUpdater>());
    addUpdater(std::make_shared<BuildingUpdater>());
}

FireScr::FireScr(float emit_rate, ofVec3f PosOrigin, float radius) : ParticleScr(emit_rate, PosOrigin)
{
    addGenerator(common::short_time_generator);
    addGenerator(std::make_shared<RandomColorGenerator>(ofColor(255, 0, 0), ofColor(255, 205, 0)));
    addGenerator(std::make_shared<CylinderPositionGenerator>(PosOrigin, radius, 1));
    addGenerator(std::make_shared<VelocityGenerator>(ofVec3f(0, 30, 0), ofVec3f(0, 50, 0)));
    addUpdater(std::make_shared<GravityUpdater>());
    addUpdater(std::make_shared<EulerUpdater>());
    addUpdater(std::make_shared<TimeUpdater>());

}
