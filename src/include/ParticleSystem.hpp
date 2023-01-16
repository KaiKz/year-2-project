#pragma once

#include "ofMain.h"

class ParticleData
{
public:
    ParticleData(){};

    void generate(size_t count);
    void kill(size_t index);
    void wake(size_t index);
    void swap(size_t first, size_t second);

    size_t count{0};
    size_t alive_count{0};
    std::vector<bool> alive;
    std::vector<ofVec3f> time;
    std::vector<ofColor> color;
    std::vector<ofVec3f> position;
    std::vector<ofVec3f> velocity;
    std::vector<ofVec3f> acceleration;
};
//--------------------------------------------------------------------------------//

class ParticleUpdater
{
public:
    ParticleUpdater(){};

    virtual void update(ParticleData *particles, float dt) = 0;
    
    //baby class of void update(ParticleData *particles, float dt) override;
};

//--------------------------------------------------------------------------------//
class ParticleGenerator
{
public:
    ParticleGenerator(){};
    virtual ~ParticleGenerator(){};
    virtual void generate(ParticleData *particles, float dt, size_t start_id, size_t end_id) = 0;
};
//--------------------------------------------------------------------------------//

class ParticleScr
{
public:
    ParticleScr(float emit_rate, ofVec3f PosOrigin) : emit_rate(emit_rate), PosOrigin(PosOrigin){};

    void emit(ParticleData *particles, float dt);
    void addGenerator(std::shared_ptr<ParticleGenerator> generator);
    void addUpdater(std::shared_ptr<ParticleUpdater> updater);

    ofVec3f PosOrigin;
    float emit_rate;
    std::vector<std::shared_ptr<ParticleGenerator>> generators;
    std::vector<std::shared_ptr<ParticleUpdater>> updaters;
};

//--------------------------------------------------------------------------------//

class ParticleSystem
{
public:
    ParticleSystem(size_t max_particle_count);
    virtual size_t numAliveParticles() const;
    void draw();
    void update(float dt);

    void addScr(std::shared_ptr<ParticleScr> scr);


    ParticleData particles;
    std::vector<std::shared_ptr<ParticleScr>> scrs;
  
};




