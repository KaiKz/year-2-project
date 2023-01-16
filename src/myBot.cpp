#include "include/myBot.hpp"

myBot::myBot(){
    
    botBody.setWidth(25);
    botBody.setDepth(25);
    botBody.setHeight(40);
    botBody.setPosition(0,0,0);
    
    botArm1.setWidth(5);
    botArm1.setDepth(5);
    botArm1.setHeight(20);
    botArm1.setPosition(25,0,0);
    
    botArm2.setWidth(5);
    botArm2.setDepth(5);
    botArm2.setHeight(20);
    botArm2.setPosition(-25,0,0);
    
    botHead.setParent(botBody);
    botArm2.setParent(botBody);
    botArm1.setParent(botBody);
    botHead.setRadius(40);
   
    // these positions are relative to the botBody
    botHead.setPosition(0, 36, 0);
    
    
}

myBot::~myBot(){
    
}

void myBot::draw(){
    botBody.draw();
    botHead.draw();
    botArm1.draw();
    botArm2.draw();
}

void myBot::update(){
    botBody.rotateDeg(10, 0, 1, 0);
}

void myBot::update1(){
    botBody.rotateDeg(-10, 0, 1, 0);
}

void myBot::setPosition(float x, float y, float z)
{
   //check pos, i don't trust data
    // coming in to my functions!
    if (x < 5000 && x > 0) xPos = x;
    // you could check the others if you want...
    if (y < 5000 && y > 0)yPos = y;
    if (z < 5000 && z > 0)zPos = z;

    botBody.setPosition(xPos, yPos, zPos);
    

   
}
void myBot::walkLeft(float x, float y, float z)
{
if (x < 5000 && x > 0) xPos = x;
    xPos-=20;
    botBody.setPosition(xPos, yPos, zPos);
}
void myBot::walkRight(float x, float y, float z)
{
if (x < 5000 && x > 0) xPos = x;
    xPos+=20;
    botBody.setPosition(xPos, yPos, zPos);
}

void myBot::walkFar(float x, float y, float z)
{
if (y < 5000 && y > 0) zPos = z;
    zPos-=20;
    botBody.setPosition(xPos, yPos, zPos);
}
void myBot::walkClose(float x, float y, float z)
{
if (y < 5000 && y > 0) zPos = z;
    zPos+=20;
    botBody.setPosition(xPos, yPos, zPos);
}




