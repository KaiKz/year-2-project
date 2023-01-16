#include "ofMain.h"
#include "include/ofApp.hpp"

int main()
{
//	ofGLWindowSettings settings;
//	settings.windowMode = ofWindowMode::OF_GAME_MODE;
//
//	auto window = ofCreateWindow(settings);

//	ofRunApp(window, make_shared<ofApp>());
//	ofRunMainLoop();
    ofGLFWWindowSettings settings;
    settings.setGLVersion(3, 2);
    settings.setSize(1280, 720);
    ofCreateWindow(settings);
//    ofSetupOpenGL(1024,768,OF_WINDOW);            // <-------- setup the GL context

    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());
}
