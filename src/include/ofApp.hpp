#pragma once

#include "ParticleSystem.hpp"
#include "ParticleScrs.hpp"
#include "ParticleGenerators.hpp"
#include "ParticleUpdaters.hpp"
#include "ofMain.h"
#include "kirby.h"
#include "superbox.h"
#include "myBot.hpp"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    bool isClicked;
    
private:
	ofTime time;
	ofEasyCam camera;


    ParticleSystem particle_system{20000};
    ParticleSystem particle_system1{20000};
    ParticleSystem particle_system2{20000};
    ParticleSystem particle_system3{20000};
    
    //create systems with particle num

    ofSoundPlayer mySound;
    ofSoundPlayer mySound1;
    ofLight light;
    kirby Kirby2;
    kirby Kirby1;
    myBot bot;
    ofImage face2;
    ofImage face3;
    ofImage bg;
    ofImage ground;
    ofImage left;
    ofImage right;
    ofImage cw;
    ofShader shader;
    ofShader shader1;
    ofImage image;
    ofImage image1;
    ofBoxPrimitive cube;
    ofBoxPrimitive cube1;
    
    //media defining
   
    SuperBox wall1{-100,100, 0};
    SuperBox wall2{100, 100, 0};
    SuperBox wall3{0, 100, -70};
    
    SuperBox wall4{-100,100, 70};
    SuperBox wall5{100, 100, 70};
    ofVec3f characterPos;
    
    //OOP 3d walls
    
    SuperBox wall6{0, 130, -70};
    ofBoxPrimitive floor;
};
