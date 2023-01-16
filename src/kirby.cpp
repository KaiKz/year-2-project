#include "include/kirby.h"

kirby::kirby()
{
    //set parent which is the body of the kirby
    hand1.setParent(body);
    hand2.setParent(body);
    foot1.setParent(body);
    foot2.setParent(body);
    hat.setParent(body);
    //set the position
    hand1.setPosition(-15, 0, 0);
    hand2.setPosition(15, 0, 0);
    foot1.setPosition(-5, -15, 5);
    foot2.setPosition(5, -15, 5);
    hat.setPosition(0, 19, 0);
    hat.rotate(180, 1.0, 0.0, 0.0);
    
    //set the radius
    hand1.setRadius(6);
    hand2.setRadius(6);
    foot1.setRadius(5);
    foot2.setRadius(5);
    hat.set(8, 10);
    body.setRadius(15);
    
    //set the material
    face.load("face.jpg");
    cone.load("cone.png");
    handMaterial.setDiffuseColor(ofColor(243,195,199));
    feetMaterial.setDiffuseColor(ofColor(216,62,60));
    
}

kirby::~kirby()
{

}

void kirby::setPosition(float x, float y, float z)
{
    xPos = x;
    yPos = y;
    zPos = z;

    body.setPosition(xPos, yPos, zPos);
}

void kirby::update()
{

    body.rotateDeg(1, 0, 1, 0);
}

void kirby::draw()
{
    // call draw on all the prims
    face.getTexture().bind();
    body.draw();
    face.getTexture().unbind();
    
    //draw hands
    handMaterial.begin();
    hand1.draw();
    hand2.draw();
    handMaterial.end();
    
    //draw feet
    feetMaterial.begin();
    foot1.draw();
    foot2.draw();
    feetMaterial.end();
    
    //draw hat
    cone.getTexture().bind();
    hat.draw();
    cone.getTexture().unbind();
    
}
