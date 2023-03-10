#pragma once

#include "ParticleSystem.hpp"

// all the classes in this file is baby class of ParticleGenerator class

class TimeGenerator : public ParticleGenerator
{
public:
    TimeGenerator(float min = 1, float max = 1) : min(min), max(max){};

    void generate(ParticleData *particles, float dt, size_t start_id, size_t end_id) override;

    float min;
    float max;
};

class RandomColorGenerator : public ParticleGenerator
{
public:
    RandomColorGenerator(ofColor min = 0, ofColor max = 255) : min(min), max(max){};

    void generate(ParticleData *particles, float dt, size_t start_id, size_t end_id) override;

    ofColor min;
    ofColor max;
};

class BoxPositionGenerator : public ParticleGenerator
{
public:
    BoxPositionGenerator(ofVec3f PosOrigin, ofVec3f range) : PosOrigin(PosOrigin), range(range){};

    void generate(ParticleData *particles, float dt, size_t start_id, size_t end_id) override;

    ofVec3f PosOrigin;
    ofVec3f range;
};

class CylinderPositionGenerator : public ParticleGenerator
{
public:
    CylinderPositionGenerator(ofVec3f PosOrigin, float radius, float height) : PosOrigin(PosOrigin), radius(radius), height(height){};

    void generate(ParticleData *particles, float dt, size_t start_id, size_t end_id) override;

    ofVec3f PosOrigin;
    float radius;
    float height;
};

class SpherePositionGenerator : public ParticleGenerator
{
public:
    SpherePositionGenerator(ofVec3f *PosOrigin, float radius) : PosOrigin(PosOrigin), radius(radius){};

    void generate(ParticleData *particles, float dt, size_t start_id, size_t end_id) override;

    ofVec3f *PosOrigin;
    float radius;
};

class VelocityGenerator : public ParticleGenerator
{
public:
    VelocityGenerator(ofVec3f min, ofVec3f max) : min(min), max(max){};

    void generate(ParticleData *particles, float dt, size_t start_id, size_t end_id) override;

    ofVec3f min;
    ofVec3f max;
};
