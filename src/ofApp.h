#pragma once
#include "ofMain.h"
#include <string>
enum AnimationMode {NONE,ROTATION,OSCILLATING_ROTATION,TRANSLATION,SCALING};
enum UserFlowMode {PAINTING_MODE,START_MENU,  INSTRUCTION_MODE, MY_WORKS_MODE, ANGER_MODE, SAD_MODE, HAPPY_MODE};
enum meshBrushTypes {MESH_BRUSH_DOT,MESH_BRUSH_TRIANGLE,MESH_BRUSH_SUN,MESH_BRUSH_SQUARE,MESH_BRUSH_CIRCLE,MESH_BRUSH_STAR,MESH_BRUSH_HEART,MESH_BRUSH_HEXAGON,MESH_BRUSH_WAVYCIRCLE,MESH_BRUSH_SPIRAL};
enum Emotion { HAPPY, SAD, ANGRY };
// Custom comparator for ofColor_<float>
struct ofFloatColorComparator {
    bool operator()(const ofFloatColor& a, const ofFloatColor& b) const {
        if (a.r != b.r) {
            return a.r < b.r;
        } else if (a.g != b.g) {
            return a.g < b.g;
        } else {
            return a.b < b.b;
        }
    }
};


namespace std {
    template <>
    struct hash<Emotion> {
        std::size_t operator()(const Emotion& e) const {
            return static_cast<std::size_t>(e);
        }
    };

    template <>
    struct equal_to<Emotion> {
        bool operator()(const Emotion& lhs, const Emotion& rhs) const {
            return static_cast<int>(lhs) == static_cast<int>(rhs);
        }
    };
}

namespace std {
    template <>
    struct hash<meshBrushTypes> {
        std::size_t operator()(const meshBrushTypes& m) const {
            return static_cast<std::size_t>(m);
        }
    };

    template <>
    struct equal_to<meshBrushTypes> {
        bool operator()(const meshBrushTypes& lhs, const meshBrushTypes& rhs) const {
            return static_cast<int>(lhs) == static_cast<int>(rhs);
        }
    };
}



class ofApp : public ofBaseApp{
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
    void drawBrush ();
    void setupMeshBrushTriangle();
    void setupMeshBrushSquare();
    void setupMeshBrushCircle();
    void setupMeshBrushHexagon();
    void setupMeshBrushHeart();
    void setupMeshBrushStar();
    void setupMeshBrushWavyCircle();
    void setupMeshBrushSpiral();
    void setupMeshBrushSun();
    void drawStartMenu();
    void drawInstructionMode();
    void saveCurrentWork();
    void drawMyWorksMode() ;
    void printVisualElementsProportions();
    Emotion classifyEmotion() ;
    void launchAngryInterfaceFlowMode();
    void launchSadInterfaceFlowMode();
    void launchHappyInterfaceFlowMode();
    void drawAngerMode();
    void drawSadMode();
    void drawHappyMode();
    
    void simpleEffect(float x, float y);
    void simpleEraser(float x, float y);
    void dynamicEffect(float x, float y, float speed, glm::vec2 direction);
    
    
    void staticEffect1(float x, float y,float size);
    void dynamicEffect1(float x, float y,float size, int red,int green,int blue);
    void dynamicEffect2(float x, float y);
    void dynamicEffect3(float x, float y, float speed, glm::vec2 direction);
    void dynamicEffect4(float x, float y, float speed, glm::vec2 direction);
    void dynamicEffect5(float x, float y, float speed);
    void dynamicEffect_3(float x, float y, float speed, glm::vec2 direction);
private:
    bool earaserIsOn=false;
    ofImage img;
    ofImage gs;
    
    ofImage img1;
    ofImage img2;
    ofImage img3;
    ofImage img4;
    ofImage img5;
    ofImage img6;
    ofImage img7;
    ofImage imgRed;
    ofImage imgGreen;
    ofImage imgBlue;
    ofImage imgDark;
    ofImage img8;
    ofImage imgEraser;
    
    int modes;
    int r;
    int g;
    int b;
    
    bool eraserIsOn;
    bool paintIsOn;
    bool dBrushIsOn;
    bool sb1IsOn;
    bool db1IsOn;
    bool db2IsOn;
    bool db3IsOn;
    bool db4IsOn;
    bool db5IsOn;
    bool db6IsOn;
    
    ofRectangle botton1;
    bool box1IsClicked;
    ofRectangle botton2;
    bool box2IsClicked;
    ofRectangle botton3;
    bool box3IsClicked;
    ofRectangle botton4;
    bool box4IsClicked;
    ofRectangle botton5;
    bool box5IsClicked;
    ofRectangle botton6;
    bool box6IsClicked;
    ofRectangle botton7;
    bool box7IsClicked;
    ofRectangle botton8;
    bool box8IsClicked;
    ofRectangle botton9;
    bool box9IsClicked;
    ofRectangle botton0;
    bool box0IsClicked;
    
    ofRectangle red;
    bool redIsClicked;
    ofRectangle green;
    bool greenIsClicked;
    ofRectangle blue;
    bool blueIsClicked;
    ofRectangle dark;
    bool darkIsClicked;
    ofRectangle light;
    bool lightIsClicked;
    
    int angerModeCounter = 0;
    int sadModeCounter = 0;
    bool completedAngerMode = false;
    bool completedSadMode = false;
    std::map<meshBrushTypes, int> brushCounters;
    std::map<ofFloatColor, int, ofFloatColorComparator> colorCounters;
    std::map<float, int> sizeCounters;

    bool hasDrawn =false;
    ofFbo canvasFbo ;
    ofFbo prevCanvasFbo;
    std::vector<ofFbo> savedWorks;
    std::vector<std::string> savedWorkNames;
    std::vector<ofFbo> prevCanvasStates;// store the strokes for undo function
    std::vector<ofFbo> redoCanvasStates;// store the strokes for redo function
    ofFloatColor brushColor {0.5 , 0.5 , 0.5 , 1.};
    float brushSize = .5;
    ofBlendMode blendMode;
    bool changeBlendMode;
    bool changeColor;
    bool changeSize;
    bool changeBrush;
    bool cycleColors;
    bool animations;
    bool SPECIAL_BRUSHES_MODE;
    ofImage softCircleBrush;
    ofImage teapotBrush;
    int activeBrush;
    int activeBrushMesh;
    ofMesh meshBrushTriangle;
    ofMesh meshBrushFlower;
    ofMesh meshBrushSquare;
    ofMesh meshBrushCircle;
    ofMesh meshBrushStar;
    ofMesh meshBrushHexagon;
    ofMesh meshBrushHeart;
    ofMesh meshBrushSpiral;
    ofMesh meshBrushWavyCircle;
    ofMesh meshBrushSun;
    static const int MESH_BRUSH_DOT = 0;
    static const int MESH_BRUSH_SUN = 2;
    static const int MESH_BRUSH_TRIANGLE = 3;
    static const int MESH_BRUSH_SQUARE = 4;
    static const int MESH_BRUSH_CIRCLE= 5;
    static const int MESH_BRUSH_STAR= 6;
    static const int MESH_BRUSH_HEXAGON=7;
    static const int MESH_BRUSH_HEART=8;
    static const int MESH_BRUSH_WAVYCIRCLE=1;
    static const int MESH_BRUSH_SPIRAL=9;
    ofVec2f prevMousePos;
    float mouseSpeed;
    float prevRotationAngle = 0;
    float smoothedRotationAngle = 0;
    UserFlowMode userFlowMode;
    UserFlowMode previousUserFlowMode;
    AnimationMode animationMode;
    ofRectangle backButton;
    ofRectangle instructionButton;
    ofRectangle specialBrushesButton;
    ofRectangle myWorksButton;
    ofRectangle saveButton;
    
    ofRectangle b1;
    ofRectangle b2;
    ofRectangle b3;
    ofRectangle b4;
    ofRectangle b5;

    bool undoEnabled; // Added to track when undo is enabled
    int count;
    bool snapped;
    glm::vec2 previousMousePos;
    glm::vec2 gestureDirection;
    float gestureMagnitude;
    float prevMouseAmt;
    float currentMouseAmount;
};
