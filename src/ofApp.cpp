#include "include/ofApp.hpp"
const float timeSec = 1 / 60.0;


void ofApp::setup()
{
    //loading media
    mySound.load("Fireworks.wav");
    mySound1.load("bgm.wav");
    mySound.play();
    bg.load("background.jpg");
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    ofSetCircleResolution(10);
    isClicked=false;
    time = ofGetCurrentTime();
    light.setPointLight();
    light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
    light.setPosition(ofGetWidth()*.5, ofGetHeight()*.5, 300);
    ofEnableNormalizedTexCoords();
    camera.setGlobalPosition(0, 6, 10);
    camera.setTarget(glm::vec3(0, 3, 0));
    camera.setDistance(800);

    
    //each particleScr goes into one vector, so that the forces applied to it do not being self contradictory
    std::shared_ptr<ParticleScr> scr=std::make_shared<ExplosionScr> (5000, ofVec3f(200, 125, -50), 75, ofColor(0), ofColor(255));
    //constructor:   ParticleScr(float emit_rate, ofVec3f PosOrigin) : emit_rate(emit_rate), PosOrigin(PosOrigin){};
    particle_system.addScr(scr);
    
    std::shared_ptr<ParticleScr> scr1=std::make_shared<FireScr> (450, ofVec3f(0, 0, 0),5);
    
    particle_system1.addScr(scr1);

    std::shared_ptr<ParticleScr> scr2=std::make_shared<SnowfallScr> (1000, ofVec3f(0, 500, 0), 600);
    particle_system2.addScr(scr2);

    std::shared_ptr<ParticleScr> scr3=std::make_shared<FireScr> (450, ofVec3f(0, 0, 0),25);
    
    particle_system3.addScr(scr3);
 
    //loading media
    face2.load("face.jpg");
    face3.load("face3.jpg");
    cw.load("cw.png");
    ground.load("ground.jpg");
    left.load("left.jpg");
    right.load("right.jpg");
    wall1.setWidth(10);
    
    wall1.setHeight(200);
    wall1.setDepth(150);

    wall2.setWidth(10);
    wall2.setHeight(200);
    wall2.setDepth(150);

    wall3.setWidth(200);
    wall3.setHeight(200);
    wall3.setDepth(10);
    
    wall4.setWidth(75);
    wall4.setHeight(200);
    wall4.setDepth(10);
    
    wall5.setWidth(75);
    wall5.setHeight(200);
    wall5.setDepth(10);
    
    wall6.setWidth(200);
    wall6.setHeight(200);
    wall6.setDepth(10);
    
    Kirby2.setPosition(-95, 174, 100);
    Kirby1.setPosition(95, 174, 100);
    
    
    floor.set(2560, 1, 1600);
    floor.setPosition(0, -2.5, (1600 / 2) - 300);
    

    characterPos = ofVec3f (0, 30, 150);
    bot.setPosition(characterPos.x,characterPos.y,characterPos.z);

    // Set cube size
    cube.set(50);
    cube.setPosition(100, 50, 150);
    cube1.set(80);
    cube1.setPosition(-200, 100, 150);
    
    // Load my shader (vert and frag) files
    shader.load("textureDemo");
    shader1.load("textureDemo");

    // This disables use of legacy rectangular textures (the default)
    ofDisableArbTex();

    // Ensure texture coordinates are in [0,1] range
    ofEnableNormalizedTexCoords();
    
    // Load my image from file into RAM
    image.load("shader1.jpg");
    image1.load("shader2.jpg");
    // Configure how the texture gets sampled
    // Set minification and magnification interpolation policies
    image.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_LINEAR);
    image1.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_LINEAR);
    // Set wrapping modes for x and y directions
    image.getTexture().setTextureWrap(GL_REPEAT, GL_MIRRORED_REPEAT);
    image1.getTexture().setTextureWrap(GL_REPEAT, GL_MIRRORED_REPEAT);
   
}

void ofApp::update()
{
    if (ofGetCurrentTime().getAsSeconds() - timeSec> 1.0f)
     {
         int numOfScr=particle_system.scrs.size();
         //set number of the source to numOfScr,because if looping beyong the num of source will cause crush
         //update the position of firworks randomly to a range
            for (size_t j = 0; j < numOfScr; j++){
                particle_system.scrs[j]->PosOrigin = ofVec3f(ofRandom(500, -500), ofRandom(250, 400), ofRandom(-100, 500));
        }
      }
    //if space bar is clicked, do these updates(fireworks, fire, music)
    if(isClicked==true){
        particle_system.update(timeSec);
        particle_system1.update(timeSec);
        particle_system3.update(timeSec);
        Kirby2.update();
        Kirby1.update();
    }
    //always do this update(snowing)
    particle_system2.update(timeSec);

}



void ofApp::draw()
{
    camera.begin();
    ofEnableLighting();
    light.enable();
    ofEnableDepthTest();
    //if the space bar is clicked, draw these
    if(isClicked==true){
        particle_system.draw();
        particle_system1.draw();
        particle_system3.draw();
        shader.begin();
        // Send my constant parameters (uniforms) over to the GPU
        shader.setUniformTexture("tex", image, 1);
        // Draw the cube
        ofPushMatrix();
        cube.draw();
        ofRotateX(-6); // rotate the cube
        ofRotateY(26);
        ofRotateZ(6);
        cube1.draw();
        ofPopMatrix();
        // Tell GPU im done with our shaders
        shader.end();
        shader1.begin();
        // Send my constant parameters (uniforms) over to the GPU
        shader.setUniformTexture("tex", image, 1);
        // Draw the cube
        ofPushMatrix();
        ofRotateX(16); // rotate the cube
        ofRotateY(-6);
        cube.draw();
        ofPopMatrix();
        // Tell GPU I am done with my shaders
        shader1.end();
        mySound1.play();
    }
    particle_system2.draw();
 
    
    ofSetColor(155,0,0);
    ofDrawBox(0, 200, 30, 200, 10, 200);
    ofSetColor(100, 100, 0, 255);
    //ground image binding
    ground.getTexture().bind();
    floor.draw();
    ground.getTexture().unbind();
    
    ofSetColor(255);
    wall1.draw();
    wall2.draw();
    wall3.draw();
    //door
    left.getTexture().bind();
    wall4.draw();
    left.getTexture().unbind();
    //door
    right.getTexture().bind();
    wall5.draw();
    right.getTexture().unbind();
    //Spring festival gala
    cw.getTexture().bind();
    wall6.draw();
    cw.getTexture().unbind();
    
    ofSetColor(155);
    glPointSize(5);
   //bot skin
    face3.getTexture().bind();
    bot.draw();
    face3.getTexture().unbind();
    //kirby skin
    face2.getTexture().bind();
    Kirby2.draw();
    Kirby1.draw();
    face2.getTexture().unbind();
    
    light.disable();
    ofDisableLighting();
    ofDisableDepthTest();
    camera.end();

    ofSetColor(255);
    ofDrawBitmapString("Press space to animate" , 10, 20);
    ofDrawBitmapString("up,down,left,right arrow to move", 10, 40);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key == ' '){
        isClicked=!isClicked;
    }
    
    if (key == OF_KEY_LEFT){
        bot.walkLeft(0,-200,0);
            bot.update1();
        }
    if (key == OF_KEY_RIGHT){
        bot.walkRight(0,-200,0);
        bot.update();
        }
    if (key == OF_KEY_UP){
        bot.walkFar(0,-200,0);
        bot.update1();
        }
    if (key == OF_KEY_DOWN){
        bot.walkClose(0,-200,0);
        bot.update();
        }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
