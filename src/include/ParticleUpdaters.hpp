#pragma once
#include "ofApp.hpp"
#include "ParticleSystem.hpp"
#include "ofMain.h"


//
class FloorUpdater : public ParticleUpdater
{
public:
    FloorUpdater(float floor_level = 0.0f) : floor_level(floor_level){};

    void update(ParticleData *particles, float dt) override;

    float floor_level;
};

class BuildingUpdater : public ParticleUpdater
{
public:
    BuildingUpdater(ofVec3f roof_level = ofVec3f(0, 200, 30),ofVec3f roof_size = ofVec3f(500.f, 40.f, 300.f)): roof_level(roof_level),roof_size(roof_size){};

    void update(ParticleData *particles, float dt) override;

    ofVec3f roof_level;
    ofVec3f roof_size;
};


class GravityUpdater : public ParticleUpdater
{
public:
    GravityUpdater(ofVec3f gravity = ofVec3f(0, -9.81f, 0)) : gravity(gravity){};

    void update(ParticleData *particles, float dt) override;

    ofVec3f gravity;
};

class EulerUpdater : public ParticleUpdater
{
public:
    void update(ParticleData *particles, float dt) override;
};

class TimeUpdater : public ParticleUpdater
{
public:
    void update(ParticleData *particles, float dt) override;
};

class TimeColorUpdater : public ParticleUpdater
{
public:
    void update(ParticleData *particles, float dt) override;

    ofColor min_color;
    ofColor max_color;
};
