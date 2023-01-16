#include "include/ParticleGenerators.hpp"
//more detialed explaination can be found in the report
void TimeGenerator::generate(ParticleData *particles, float dt, size_t start_id, size_t end_id)
{
    for (size_t i = start_id; i < end_id; ++i)
    {
        float lifetime = ofRandom(min, max);
        particles->time.at(i) = ofVec3f(lifetime, 1.0f / lifetime, 0.f);
    }
}
//this is the generartor affect the life of particle

void RandomColorGenerator::generate(ParticleData *particles, float dt, size_t start_id, size_t end_id)
{
    for (size_t i = start_id; i < end_id; ++i)
    {
        particles->color.at(i) = ofColor(
            ofRandom(min.r, max.r),
            ofRandom(min.g, max.g),
            ofRandom(min.b, max.b));
    }
}
//this generator pointers to change color of particles

void BoxPositionGenerator::generate(ParticleData *particles, float dt, size_t start_id, size_t end_id)
{
    for (size_t i = start_id; i < end_id; ++i)
    {
        particles->position.at(i) = ofVec3f(
            ofRandom(PosOrigin.x - range.x, PosOrigin.x + range.x),
            ofRandom(PosOrigin.y - range.y, PosOrigin.y + range.y),
            ofRandom(PosOrigin.z - range.z, PosOrigin.z + range.z));
    }
}

//this is the generator generates particles in a cube area

void CylinderPositionGenerator::generate(ParticleData *particles, float dt, size_t start_id, size_t end_id)
{
    for (size_t i = start_id; i < end_id; ++i)
    {
        float theta = ofRandom(2 * PI);
        float u = ofRandom(radius) + ofRandom(radius);
        float r = u > radius ? 2 - u : u;
        float x = PosOrigin.x + r * cos(theta);
        float y = PosOrigin.y + ofRandom(-height / 2, height / 2);
        float z = PosOrigin.z + r * sin(theta);
        particles->position.at(i) = ofVec3f(x, y, z);
    }
}
//this is the generator generates particles in a sphere area, by assigning x,y,z to sin and cos
void SpherePositionGenerator::generate(ParticleData *particles, float dt, size_t start_id, size_t end_id)
{
    for (size_t i = start_id; i < end_id; ++i)
    {
        float theta = ofRandom(0, 2 * PI);
        float phi = ofRandom(0, 2 * PI);
        float x = PosOrigin->x + radius * sin(theta) * cos(phi);
        float y = PosOrigin->y + radius * sin(theta) * sin(phi);
        float z = PosOrigin->z + radius * cos(theta);
        particles->position.at(i) = ofVec3f(x, y, z);
    }
}
//this is the generator generates velocity of each particle randomly
void VelocityGenerator::generate(ParticleData *particles, float dt, size_t start_id, size_t end_id)
{
    for (size_t i = start_id; i < end_id; ++i)
    {
        particles->velocity.at(i) = ofVec3f(
            ofRandom(min.x, max.x),
            ofRandom(min.y, max.y),
            ofRandom(min.z, max.z));
    }
}
