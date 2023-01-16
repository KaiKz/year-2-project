#include "include/ParticleSystem.hpp"

void ParticleData::generate(size_t count)
{
    this->count = count;
    alive.resize(count, false);
    time.resize(count);
    color.resize(count);
    position.resize(count);
    velocity.resize(count);
    acceleration.resize(count);
}

//The ParticleData class, which has a generate function that sets the count of particles and resizes several attributes (alive, time, color, position, velocity, and acceleration) to the specified count. It also includes functions to kill and wake a particle, and swap the values of two particles.

void ParticleData::kill(size_t index)
{
    alive.at(index) = false;
    swap(index, alive_count - 1);
    --alive_count;
}

void ParticleData::wake(size_t index)
{
    alive.at(index) = true;
    ++alive_count;
}

void ParticleData::swap(size_t first, size_t second)
{
    time.at(first) = time.at(second);
    color.at(first) = color.at(second);
    position.at(first) = position.at(second);
    velocity.at(first) = velocity.at(second);
    acceleration.at(first) = acceleration.at(second);
}

//The ParticleScr class, which has an emit function that creates new particles and assigns them values using a set of generators, and updates the values of existing particles using a set of updaters. It also has functions to add generators and updaters to the particle scr.
void ParticleScr::emit(ParticleData *particles, float dt)
{
    size_t max_new_particles = size_t(dt * emit_rate);
    size_t start_id = particles->alive_count;
    size_t end_id = std::min(start_id + max_new_particles, particles->count - 1);

    for (auto &generator : generators)
        generator->generate(particles, dt, start_id, end_id);

    for (size_t i = start_id; i < end_id; ++i)
        particles->wake(i);
    
    for (auto &updater : updaters)
        updater->update(particles, dt);
}

//The ParticleSystem class, which has a constructor that creates a particle system with a specified maximum number of particles, and a draw function that draws spheres for each alive particle in the system. It also has an update function that updates the particle system and a function to add particle scr to the system and returns the number of alive particles in the system.



ParticleSystem::ParticleSystem(size_t max_particle_count)
{
    particles.generate(max_particle_count);
}

void ParticleSystem::draw()
{
    for (size_t i = 0; i < particles.alive_count; ++i)
    {
        ofSetColor(particles.color.at(i));
        ofDrawSphere(particles.position.at(i), 1);
    }
}

void ParticleSystem::update(float dt)
{
    for (auto &scr : scrs)
        scr->emit(&particles, dt);

    
}

void ParticleScr::addGenerator(std::shared_ptr<ParticleGenerator> generator)
{
    generators.push_back(generator);
}

void ParticleSystem::addScr(std::shared_ptr<ParticleScr> scr)
{
    scrs.push_back(scr);
}

void ParticleScr::addUpdater(std::shared_ptr<ParticleUpdater> updater)
{
    updaters.push_back(updater);
}
size_t ParticleSystem::numAliveParticles() const
{
    return particles.alive_count;
}
