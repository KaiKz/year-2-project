#pragma once
#include "include/ParticleSystem.hpp"
#include "include/ParticleGenerators.hpp"
#include "include/ParticleUpdaters.hpp"

//classes to the sources
class ExplosionScr : public ParticleScr
{
public:
    ExplosionScr(float emit_rate, ofVec3f PosOrigin, float power, ofColor min_color, ofColor max_color);
};

class SnowfallScr : public ParticleScr
{
public:
    SnowfallScr(float emit_rate, ofVec3f PosOrigin, float radius);
};

class FireScr : public ParticleScr
{
public:
    FireScr(float emit_rate, ofVec3f PosOrigin, float radius);
};
