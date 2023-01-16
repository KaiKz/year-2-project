#pragma once

#include "ofMain.h"
class myBot{
public:
    myBot();
    ~myBot();
    
    void draw();
    void update();
    void update1();
    void setPosition(float x, float y, float z);
    void walkLeft(float x, float y, float z);
    void walkRight(float x, float y, float z);
    void walkFar(float x, float y, float z);
    void walkClose(float x, float y, float z);
    void getPos();
    
private:
    float xPos;
    float yPos;
    float zPos;
//    ofTexture mTex;
    ofBoxPrimitive botBody;
    ofBoxPrimitive botArm1;
    ofBoxPrimitive botArm2;
    ofSpherePrimitive botHead;
};



