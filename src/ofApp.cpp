#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    canvasFbo . allocate ( ofGetWidth () , ofGetHeight ()-180 , GL_RGB );
    prevCanvasFbo . allocate ( ofGetWidth () , ofGetHeight ()-180 , GL_RGB );
    ofBackground(0);
    canvasFbo . begin () ;
        prevCanvasFbo . begin () ;
        ofClear ( ofFloatColor (0.1 , 0.2 , 0.3) );
        canvasFbo . end () ;
        prevCanvasFbo . end () ;
    softCircleBrush.load("softCircleWithAlpha.png");
    teapotBrush.load("teapotWithAlpha.png");
    activeBrush = 0;
    blendMode = OF_BLENDMODE_ALPHA;
    changeBlendMode = false;
    changeColor= false;
    changeSize= false;
    changeBrush=false;
    cycleColors = false;
    animations = false;
    SPECIAL_BRUSHES_MODE=false;

    activeBrushMesh = MESH_BRUSH_TRIANGLE;
    setupMeshBrushTriangle();
    setupMeshBrushSun();
    setupMeshBrushSquare();
    setupMeshBrushCircle();
    setupMeshBrushStar();
    setupMeshBrushHexagon();
       setupMeshBrushHeart();
    setupMeshBrushSpiral();
    setupMeshBrushWavyCircle();

    animationMode = NONE;
    userFlowMode = START_MENU;

    backButton.set(ofGetWidth() - 120, ofGetHeight() - 20, 100, 25);
    instructionButton.set(ofGetWidth() - 120, ofGetHeight() - 50, 100, 25);
    specialBrushesButton.set(ofGetWidth() - 120, ofGetHeight() - 80, 100, 25);
    myWorksButton.set(ofGetWidth() - 120, ofGetHeight() - 110, 100, 25);
    saveButton.set(ofGetWidth() - 120, ofGetHeight() - 80, 100, 25);
    
    b1.set(20, ofGetHeight() - 20, 300, 25);
    b2.set(20, ofGetHeight() - 50, 300, 25);
    b3.set(20, ofGetHeight() - 80, 300, 25);
    b4.set(20, ofGetHeight() - 110, 300, 25);
    b5.set(320, ofGetHeight() - 80, 300, 25);
    
    
    
    
    
    
    gs.load("gs.jpg");
    img2.load("2.png");
    img2.resize(50, 80);
    img1.resize(50, 80);
    img3.resize(50, 80);
    img4.resize(50, 80);
    img5.resize(50, 80);
    img6.resize(50, 80);
    img7.resize(50, 80);
    img8.resize(50, 80);
    imgRed.resize(50, 80);
    imgGreen.resize(50, 80);
    imgBlue.resize(50, 80);
    imgDark.resize(50, 80);
    imgEraser.resize(50, 80);
    img3.load("3.png");
    img4.load("4.png");
    img5.load("5.png");
    img6.load("6.png");
    img7.load("7.png");
    img8.load("8.png");
    img1.load("1.png");
    imgRed.load("red.png");
    imgGreen.load("green.png");
    imgBlue.load("blue.png");
    imgDark.load("do.png");
    imgEraser.load("Eraser.png");
   
    gs.resize(100, 100);
    
    //below sets the size of bottons
     botton1.set(20,ofGetHeight()-80, 50, 80);// x, y, width, height
     botton2.set(80,ofGetHeight()-80, 50, 80);
     botton3.set(140,ofGetHeight()-80, 50, 80);
     botton4.set(200,ofGetHeight()-80, 50, 80);
     botton5.set(260,ofGetHeight()-80, 50, 80);
     botton6.set(320,ofGetHeight()-80, 50, 80);
     botton7.set(380,ofGetHeight()-80, 50, 80);
     botton8.set(440,ofGetHeight()-80, 50, 80);
     botton9.set(500,ofGetHeight()-80, 50, 80);
     light.set(540, ofGetHeight()-80, 50, 80);
     dark.set(600, ofGetHeight()-80, 50, 80);
     green.set(660, ofGetHeight()-80, 50, 80);
     blue.set(720, ofGetHeight()-80, 50, 80);
     red.set(780, ofGetHeight()-80, 50, 80);
//     botton0.set(840, ofGetHeight()-80, 50, 80);


    ofSetWindowTitle("Follow your emotionm, draw whatever you want");
    prevMouseAmt = 0.9;
    currentMouseAmount = 1 - prevMouseAmt;
}

void ofApp::saveCurrentWork() {
    ofFbo currentWork;
       currentWork.allocate(ofGetWidth(), ofGetHeight() - 180, GL_RGBA);
       currentWork.begin();
       canvasFbo.draw(0, 0);
       currentWork.end();
       savedWorks.push_back(currentWork);
       savedWorkNames.push_back("Work_" + ofGetTimestampString());
}

void ofApp::drawMyWorksMode() {
    ofBackground(0);
    ofSetColor(255);

    for (size_t i = 0; i < savedWorkNames.size(); i++) {
        ofDrawBitmapString(savedWorkNames[i], 50, 50 + i * 30);
    }
    ofSetColor(200, 50, 50);
    ofDrawRectangle(backButton);
    ofSetColor(255);
    ofDrawBitmapString("Back", backButton.getPosition() + ofPoint(35, 20));

}


//--------------------------------------------------------------
void ofApp::update(){
    if (userFlowMode == HAPPY_MODE) {
        ofSetWindowTitle("LILI bot >> What a great day! Here is a gift for you -- a set of special brushes, pick one, explore and enjoy it!");
    }else if(userFlowMode == SAD_MODE){
        ofSetWindowTitle("LILI bot >> Cheer up! Here is a creative challenge for you. Try use Wabycircle, Sun, Star and Heart bursh to draw something after press key 'h'");
    }else if(userFlowMode == ANGER_MODE){
        ofSetWindowTitle("LILI bot >> Calm down! Here is a creative challenge for you. Try use Dot, Circle, Square, Triangle and Hexagon brush to draw something after both press key 'm' and any key from 2-5");
    }else if(userFlowMode == START_MENU){
        ofSetWindowTitle("LILI bot >> Hi there, Welcome!! How's your day?");
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (userFlowMode == HAPPY_MODE) {
        drawHappyMode();
//        std::cout<<userFlowMode<<std::endl;
    }else if (userFlowMode == ANGER_MODE) {
        drawAngerMode();
//        std::cout<<userFlowMode<<std::endl;
    } else if (userFlowMode == SAD_MODE) {
        drawSadMode();
//        std::cout<<userFlowMode<<std::endl;
    } else {
        if (userFlowMode == MY_WORKS_MODE) {
            drawMyWorksMode();
            std::cout<<userFlowMode<<std::endl;
        } else {
            if (userFlowMode == START_MENU) {
                drawStartMenu();
            } else if (userFlowMode == PAINTING_MODE) {
                canvasFbo.draw(0, 0);
                ofSetColor(200, 50, 50);
                ofDrawRectangle(backButton);
                ofSetColor(255);
                ofDrawBitmapString("Back", backButton.getPosition() + ofPoint(35, 17));
                ofSetColor(50, 200, 50);
                ofDrawRectangle(instructionButton);
                ofSetColor(255);
                ofDrawBitmapString("Instructions", instructionButton.getPosition() + ofPoint(5, 17));
                ofSetColor(50, 50, 200);
                ofDrawRectangle(saveButton);
                ofSetColor(255);
                ofDrawBitmapString("Continue", saveButton.getPosition() + ofPoint(25, 17));
            } else if (userFlowMode == INSTRUCTION_MODE) {
                drawInstructionMode();
            }
        }
    }
    

    
}

void ofApp::drawStartMenu() {
    ofBackground(0);
    ofSetColor(255);
    
    ofRectangle startButton;
    startButton.set(ofGetWidth() / 2 - 100, ofGetHeight() / 2 - 60, 200, 40);
    ofSetColor(0, 175, 255);
    ofDrawRectangle(startButton);
    ofSetColor(255);
    ofDrawBitmapString("Start painting", ofGetWidth() / 2 - 60, ofGetHeight() / 2 - 30);
    
    ofRectangle instructionsButton;
    instructionsButton.set(ofGetWidth() / 2 - 100, ofGetHeight() / 2, 200, 40);
    ofSetColor(255, 150, 0);
    ofDrawRectangle(instructionsButton);
    ofSetColor(255);
    ofDrawBitmapString("Instructions", ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 30);
    
    ofRectangle exitButton;
    exitButton.set(ofGetWidth() / 2 - 100, ofGetHeight() / 2 + 60, 200, 40);
    ofSetColor(255, 50, 50);
    ofDrawRectangle(exitButton);
    ofSetColor(255);
    ofDrawBitmapString("Exit", ofGetWidth() / 2 - 20, ofGetHeight() / 2 + 90);
    
    ofRectangle myWorksButton;
    myWorksButton.set(ofGetWidth() / 2 - 100, ofGetHeight() / 2 + 120, 200, 40);
    ofSetColor(150, 100, 255);
    ofDrawRectangle(myWorksButton);
    ofSetColor(255);
    ofDrawBitmapString("My Works", ofGetWidth() / 2 - 35, ofGetHeight() / 2 + 150);

}

void ofApp::drawInstructionMode() {
    ofBackground(0);
    ofSetColor(255);
    ofTranslate(50, -70);
    ofDrawBitmapString("Instructions(some features may only work under certain conditions:", ofGetWidth() / 2 - 450, ofGetHeight() / 2 - 160);
    ofDrawBitmapString("Drag mouse to paint", ofGetWidth() / 2 - 450, ofGetHeight() / 2 - 120);
    ofDrawBitmapString("-Press 'm' to enable black and white mode, this is for the users with anger", ofGetWidth() / 2 - 430, ofGetHeight() / 2 -100);
    ofDrawBitmapString("-Press 'w' to enable changing brush size, 'e' for bigger size, 's' for smaller size", ofGetWidth() / 2 -  430, ofGetHeight() / 2-80);
    ofDrawBitmapString("-Press 'b' to enable changing brushes, click 0 - 9 to pick different brushes", ofGetWidth() / 2 -  430, ofGetHeight() / 2-60);
    ofDrawBitmapString("-Press 'c' to enable changing color, press r,g,b to increase, R,G,B to decrease red green blue respectively", ofGetWidth() / 2 -  430, ofGetHeight() / 2-40);
    ofDrawBitmapString("-Press 'h' to enable cycle color, this is for the users with sadness", ofGetWidth() / 2 -  430, ofGetHeight() / 2-20);
    ofDrawBitmapString("-Press 'a' to enable animations, click 1-5 to choose different animatons", ofGetWidth() / 2 -  430, ofGetHeight() / 2);
    ofDrawBitmapString("-Press 'x' to screenshot, result can be find in bin", ofGetWidth() / 2 -  430, ofGetHeight() / 2+20);
    ofDrawBitmapString("-Press 'z' to undo, 'y' to redo ", ofGetWidth() / 2 -  430, ofGetHeight() / 2+40);
    
    ofDrawBitmapString("-Click 'Instruction' to check instructions ", ofGetWidth() / 2 -  430, ofGetHeight() / 2+60);
    ofDrawBitmapString("-Click 'Back' to go back to starting menu, note: your work may not be saved", ofGetWidth() / 2 -  430, ofGetHeight() / 2+80);
    ofDrawBitmapString("-Click 'My Works' to check previous saved works and choose one to continue", ofGetWidth() / 2 -  430, ofGetHeight() / 2+100);
    ofDrawBitmapString("-Click 'Continue' to save current work in 'My Works', and proceed creative challenge or get a hidden gift\n based on your emotion", ofGetWidth() / 2 -  430, ofGetHeight() / 2+120);
    ofDrawBitmapString("-Creative challenge for the user with sadness: pick a brush with non-basic shape\n(Star, Heart etc.) draw something, with cycle color mode enabled\n\n-Creative challenge for the user with anger: pick a brush with \n basic shape(Circle, spuare etc.) draw something, with black and white mode enable", ofGetWidth() / 2 -  430, ofGetHeight() / 2+160);


    ofDrawBitmapString("Click anywhere to go back to last page, remenber to click the same key again before click other keys to \nenable mode", ofGetWidth() / 2 - 450, ofGetHeight() / 2 + 240);

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    if (userFlowMode == ANGER_MODE){
        if (key == 'm') {
            
            std::cout<<"BlendMode is changing!"<<std::endl;
            changeSize=false;
            changeBrush=false;
            changeColor=false;
            cycleColors=false;
            animations=false;
            changeBlendMode = !changeBlendMode;
        }
        if (changeBlendMode) {
            switch (key) {
                case '1':
                    blendMode = OF_BLENDMODE_ALPHA;
                    break;
                case '2':
                    blendMode = OF_BLENDMODE_ADD;
                    break;
                case '3':
                    blendMode = OF_BLENDMODE_MULTIPLY;
                    break;
                case '4':
                    blendMode = OF_BLENDMODE_SUBTRACT;
                    break;
                case '5':
                    blendMode = OF_BLENDMODE_SCREEN;
                    break;
                default:
                    break;
            }
        }
    }
    
    if (userFlowMode == PAINTING_MODE||userFlowMode == HAPPY_MODE){
        if (key == 'w') {
            
            std::cout<<"Size is changing!"<<std::endl;
            changeBlendMode=false;
            changeBrush=false;
            changeColor=false;
            cycleColors=false;
            animations=false;
            changeSize = !changeSize;
        }
        if (changeSize) {
            
            float dc = 0.05; // color delta value
            switch ( key ){
                case 'e': brushSize = ofClamp ( brushSize + dc , 0. ,1.) ; break ;//expanding brush size
                case 's': brushSize = ofClamp ( brushSize - dc , 0. ,1.) ; break ;//shrinking brush size
                default:;
            }
        }
    }
    
    if (userFlowMode == PAINTING_MODE||userFlowMode == HAPPY_MODE||userFlowMode == ANGER_MODE||userFlowMode == SAD_MODE){
        if (key == 'b') {
            if(changeColor==false){
                std::cout<<"Brush is changing!"<<std::endl;
                changeBlendMode=false;
                changeSize=false;
                changeColor=false;
                cycleColors=false;
                animations=false;
                changeBrush = !changeBrush;
            }
        }
        if (changeBrush) {
            if (key == '1') {
                activeBrush = MESH_BRUSH_DOT; // softCircleBrush
                std::cout<<activeBrush<<std::endl;
            } else if (key == '2') {
                activeBrush = MESH_BRUSH_WAVYCIRCLE;
                std::cout<<activeBrush<<std::endl;
            }else if (key == '3') {
                activeBrush = MESH_BRUSH_TRIANGLE; // meshBrush
                std::cout<<activeBrushMesh<<std::endl;
            } else if (key == '4') {
                activeBrush = MESH_BRUSH_SUN; // meshBrush
                std::cout<<activeBrushMesh<<std::endl;
            }else if (key == '5') {
                activeBrush = MESH_BRUSH_SQUARE; // meshBrushSquare
                std::cout << activeBrushMesh << std::endl;
            } else if (key == '6') {
                activeBrush = MESH_BRUSH_CIRCLE; // meshBrushCircle
                std::cout << activeBrushMesh << std::endl;
            } else if (key == '7') {
                activeBrush = MESH_BRUSH_STAR; // meshBrushStar
                std::cout << activeBrushMesh << std::endl;
            }else if (key == '8') {
                activeBrush = MESH_BRUSH_HEXAGON; // meshBrushStar
                std::cout << activeBrushMesh << std::endl;
            }else if (key == '9') {
                activeBrush = MESH_BRUSH_HEART; // meshBrushStar
                std::cout << activeBrushMesh << std::endl;
            }else if (key == '0') {
                activeBrush = MESH_BRUSH_SPIRAL; // meshBrushStar
                std::cout << activeBrushMesh << std::endl;
            }
        }
    }
    
    if (userFlowMode == PAINTING_MODE){
        if (key == 'c') {
            
            std::cout<<"Color is changing!"<<std::endl;
            changeBlendMode=false;
            changeSize=false;
            changeBrush=false;
            cycleColors=false;
            animations=false;
            changeColor = !changeColor;
        }
        if (changeColor) {
            
            float dc = 0.05; // color delta value
            switch ( key ){
                case 'r': brushColor .r = ofClamp ( brushColor .r + dc , 0. ,1.) ; break ;
                case 'R': brushColor .r = ofClamp ( brushColor .r - dc , 0. ,1.) ; break ;
                case 'g': brushColor .g = ofClamp ( brushColor .g + dc , 0. ,1.) ; break ;
                case 'G': brushColor .g = ofClamp ( brushColor .g - dc , 0. ,1.) ; break ;
                case 'b': brushColor .b = ofClamp ( brushColor .b + dc , 0. ,1.) ; break ;
                case 'B': brushColor .b = ofClamp ( brushColor .b - dc , 0. ,1.) ; break ;
                case 'e': brushSize = ofClamp ( brushSize + dc , 0. ,1.) ; break ;//expanding brush size
                case 's': brushSize = ofClamp ( brushSize - dc , 0. ,1.) ; break ;//shrinking brush size
                default:;
            }
        }
        
        
    }
    
    if (userFlowMode == SAD_MODE){
        
        if (key == 'h') {
            
            std::cout<<"cycle color is enabled!"<<std::endl;
            changeBlendMode=false;
            changeSize=false;
            changeBrush=false;
            changeColor=false;
            animations=false;
            cycleColors = !cycleColors;
        }
    }
    
    if (key == 'a') {
        
        std::cout<<"animations are enabled!"<<std::endl;
        changeBlendMode=false;
        changeSize=false;
        changeBrush=false;
        changeColor=false;
        cycleColors=false;
        animations = !animations;
    }
     
    if (animations) {
        if (key == '1') {
            animationMode = ROTATION;
        } else if (key == '2') {
            animationMode = OSCILLATING_ROTATION;
        } else if (key == '3') {
            animationMode = TRANSLATION;
        } else if (key == '4') {
            animationMode = SCALING;
        }
    }
    
    if(key=='x'){
        snapped=true;
    }
    if(snapped==true){
        ofPixels pixels;
        canvasFbo.readToPixels(pixels);
        string filename="result_"+ofToString(count,2,'0')+".png";
        img.setFromPixels(pixels);
        
        img.save(filename);
        count++;
        
    }
    
    //undo feature
    if (userFlowMode == PAINTING_MODE||userFlowMode == HAPPY_MODE){
        if (key == 'z' || key == 'Z') {
            if (!prevCanvasStates.empty()) {
                // Move the current state to the redoCanvasStates stack
                redoCanvasStates.push_back(canvasFbo);
                
                // Pop the previous state from prevCanvasStates stack and set it as the current canvasFbo
                canvasFbo = prevCanvasStates.back();
                prevCanvasStates.pop_back();
            }
        } else if (key == 'y' || key == 'Y') {
            //redo feature
            if (!redoCanvasStates.empty()) {
                // Move the current state to the prevCanvasStates stack
                prevCanvasStates.push_back(canvasFbo);
                
                // Pop the next state from redoCanvasStates stack and set it as the current canvasFbo
                canvasFbo = redoCanvasStates.back();
                redoCanvasStates.pop_back();
            }
        }else if (key == 'v' || key == 'V') {
            // Clear the canvas
            canvasFbo.begin();
            ofClear(0); // Set the background to black
            canvasFbo.end();
            brushCounters[static_cast<meshBrushTypes>(activeBrush)]-10;
            colorCounters[brushColor]=0;
            sizeCounters[brushSize]=0;
        }
}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if (userFlowMode == ANGER_MODE) {
        hasDrawn = true;
        canvasFbo.begin();
        ofEnableBlendMode(blendMode);
        ofSetColor(brushColor);
        ofPushMatrix();
        drawBrush();
        ofPopMatrix();
        ofDisableBlendMode();
        canvasFbo.end();
    } else if (userFlowMode == SAD_MODE) {
        hasDrawn = true;
        canvasFbo.begin();
        ofSetColor(brushColor);
        ofPushMatrix();
        drawBrush();
        ofPopMatrix();
        canvasFbo.end();
    }else if (userFlowMode == HAPPY_MODE) {
        hasDrawn = true;
//        if(SPECIAL_BRUSHES_MODE==true){
            canvasFbo.begin();
            ofSetColor(brushColor);
            ofPushMatrix();
            float time=ofGetElapsedTimef();
            
            //the loop below is just for set some interesting color while drawing
            for(int i=0; i<900; i+=5){
                if(sb1IsOn==true){
                    staticEffect1(mouseX, mouseY,1);
                }
                
                if(db1IsOn==true){
                    dynamicEffect1(mouseX+10*sin(i*0.01+time),
                                   mouseY+i/20,
                                   10+sin(i*0.005+time),
                                   127+127*sin(i*0.001+time),
                                   127+127*sin(i*0.0056+time),
                                   127+127*sin(i*0.0057+time));
                }
            }
            //start drawing while mouse is pressing
            if(paintIsOn==true){
                simpleEffect(mouseX, mouseY);
                
            }
            
            if(dBrushIsOn==true){
                dynamicEffect(previousMousePos.x, previousMousePos.y, gestureMagnitude, gestureDirection);
            }
            
            if(db2IsOn==true){
                dynamicEffect2(mouseX, mouseY);
            }
            if(db3IsOn==true){
                dynamicEffect3(previousMousePos.x, previousMousePos.y, gestureMagnitude, gestureDirection);
            }
            if(db4IsOn==true){
                dynamicEffect4(mouseX, mouseY, gestureMagnitude, gestureDirection);
                
            }
            
            if(db5IsOn==true){
                dynamicEffect5(mouseX, mouseY, gestureMagnitude);
                dynamicEffect5(mouseX, mouseY, gestureMagnitude);
                dynamicEffect5(mouseX, mouseY, gestureMagnitude);
                dynamicEffect5(mouseX, mouseY, gestureMagnitude);
                dynamicEffect5(mouseX, mouseY, gestureMagnitude);
                dynamicEffect5(mouseX, mouseY, gestureMagnitude);
                dynamicEffect5(mouseX, mouseY, gestureMagnitude);
                dynamicEffect5(mouseX, mouseY, gestureMagnitude);
            }
            
            
            
            if(db6IsOn==true){
                dynamicEffect_3(previousMousePos.x, previousMousePos.y, gestureMagnitude * 2, gestureDirection *-1);
            }
            
            
            glm::vec2 mousePos = glm::vec2(mouseX,mouseY);
            //subtract previous mouse position vector from currrent pos
            glm::vec2 gesture = mousePos - previousMousePos;
            gestureMagnitude = length(gesture);
            gestureDirection = normalize(gesture);
            previousMousePos.x = prevMouseAmt*previousMousePos.x + mouseX*currentMouseAmount;
            previousMousePos.y = prevMouseAmt*previousMousePos.y + mouseY*currentMouseAmount;
            ofPopMatrix();
            canvasFbo.end();
    
    } else {
        if (userFlowMode == PAINTING_MODE){
            brushCounters[static_cast<meshBrushTypes>(activeBrush)]++;
            colorCounters[brushColor]++;
            sizeCounters[brushSize]++;
            if (undoEnabled) {
                prevCanvasFbo.begin();
                canvasFbo.draw(0, 0);
                prevCanvasFbo.end();
            }
            hasDrawn = true;
            canvasFbo.begin();
            ofSetColor(brushColor);
            ofPushMatrix();
            drawBrush();
            ofPopMatrix();
            canvasFbo.end();
        }
    }
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (userFlowMode == PAINTING_MODE) {
           ofFbo currentState;
           currentState.allocate(ofGetWidth(), ofGetHeight()-180, GL_RGB);
           currentState.begin();
           canvasFbo.draw(0, 0);
           currentState.end();
           prevCanvasStates.push_back(currentState);
        redoCanvasStates.clear();
       }
    if (userFlowMode == HAPPY_MODE) {
        if(modes==6){
            db3IsOn=true;
        }
        if(modes==1){
            paintIsOn=true;
        }
        if(earaserIsOn==true){
            eraserIsOn=!eraserIsOn;
            SPECIAL_BRUSHES_MODE=false;
            if(eraserIsOn==false){
                userFlowMode == PAINTING_MODE;
            }
            std::cout<<"Eraser is on, status is easing, no painting is shown"<<std::endl;
        }
        if(modes==2){
            dBrushIsOn=true;
        }
        if(modes==3){
            sb1IsOn=true;
        }
        if(modes==4){
            db1IsOn=true;
        }
        if(modes==5){
            
            db2IsOn=true;
        }
        if(modes==7){
            db4IsOn=true;
        }
        if(modes==8){
            db5IsOn=true;
        }
        if(modes==8){
            db6IsOn=true;
        }
        
        //below check if inside the botton is pressed
        box1IsClicked = botton1.inside(x,y);
        box2IsClicked = botton2.inside(x,y);
        box3IsClicked = botton3.inside(x,y);
        box4IsClicked = botton4.inside(x,y);
        box5IsClicked = botton5.inside(x,y);
        box6IsClicked = botton6.inside(x,y);
        box7IsClicked = botton7.inside(x,y);
        box8IsClicked = botton8.inside(x,y);
//        box9IsClicked = botton9.inside(x,y);
        box0IsClicked = botton0.inside(x,y);
        redIsClicked = red.inside(x, y);
        blueIsClicked = blue.inside(x, y);
        greenIsClicked = green.inside(x, y);
        darkIsClicked = dark.inside(x, y);
        lightIsClicked = light.inside(x, y);
        
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    if (userFlowMode == HAPPY_MODE) {
        if (specialBrushesButton.inside(x, y)){
            SPECIAL_BRUSHES_MODE=!SPECIAL_BRUSHES_MODE;
            std::cout<<SPECIAL_BRUSHES_MODE<<std::endl;
        }
        //when mouse is released, stop drawing
        paintIsOn=false;
        eraserIsOn=false;
        dBrushIsOn=false;
        sb1IsOn=false;
        db1IsOn=false;
        db2IsOn=false;
        db3IsOn=false;
        db4IsOn=false;
        db5IsOn=false;
        db6IsOn=false;
        if (instructionButton.inside(x, y)) {
            previousUserFlowMode = userFlowMode;
            userFlowMode = INSTRUCTION_MODE;
        }
        if (backButton.inside(x, y)) {
            userFlowMode = START_MENU;
        }
    }else if (userFlowMode == ANGER_MODE) {
        if (backButton.inside(x, y)) {
            userFlowMode = START_MENU;
            canvasFbo.begin();
            ofClear(0); // Set the background to black
            canvasFbo.end();
        } else if (instructionButton.inside(x, y)) {
            previousUserFlowMode = userFlowMode;
            userFlowMode = INSTRUCTION_MODE;
        }
        if (angerModeCounter < 15) {
            if(activeBrush == MESH_BRUSH_DOT || activeBrush == MESH_BRUSH_TRIANGLE||activeBrush ==MESH_BRUSH_SQUARE||activeBrush ==MESH_BRUSH_CIRCLE||activeBrush ==MESH_BRUSH_HEXAGON){
                if (blendMode == OF_BLENDMODE_ADD||blendMode == OF_BLENDMODE_ADD||blendMode == OF_BLENDMODE_MULTIPLY||blendMode == OF_BLENDMODE_SUBTRACT||blendMode == OF_BLENDMODE_SCREEN){
                    // angry mode specific drawing conditions
                    angerModeCounter++;
  
                }
            }
            if (angerModeCounter == 15) {
                userFlowMode = HAPPY_MODE;
                canvasFbo.begin();
                ofClear(0); // Set the background to black
                canvasFbo.end();
            }
            hasDrawn = false;
        }
    } else if (userFlowMode == SAD_MODE) {
        if (backButton.inside(x, y)) {
            userFlowMode = START_MENU;
            canvasFbo.begin();
            ofClear(0); // Set the background to black
            canvasFbo.end();
        } else if (instructionButton.inside(x, y)) {
            previousUserFlowMode = userFlowMode;
            userFlowMode = INSTRUCTION_MODE;
        }
        if (sadModeCounter < 15) {
            if(activeBrush == MESH_BRUSH_WAVYCIRCLE || activeBrush == MESH_BRUSH_SUN||activeBrush ==MESH_BRUSH_STAR||activeBrush ==MESH_BRUSH_HEART||activeBrush == MESH_BRUSH_WAVYCIRCLE){
                if (cycleColors==true){
                    // Sad mode specific drawing conditions
                    sadModeCounter++;
                    
//                    std::cout <<sadModeCounter << std::endl;
                }
            }
            if (sadModeCounter == 15) {
                userFlowMode = HAPPY_MODE;
                canvasFbo.begin();
                ofClear(0); // Set the background to black
                canvasFbo.end();
            }
            hasDrawn = false;
        }
    } else {
        if (userFlowMode == PAINTING_MODE && saveButton.inside(x, y)) {
            if (hasDrawn) {
                saveCurrentWork();
                printVisualElementsProportions();
                Emotion classifiedEmotion = classifyEmotion();
                switch (classifiedEmotion) {
                    case HAPPY:
                        std::cout << "Happy" << std::endl;
                        launchHappyInterfaceFlowMode();
                        SPECIAL_BRUSHES_MODE==true;
                        break;
                    case SAD:
                        std::cout << "Sad" << std::endl;
                        launchSadInterfaceFlowMode();
                        break;
                    case ANGRY:
                        std::cout << "Angry" << std::endl;
                        launchAngryInterfaceFlowMode();
                        break;
                }
                hasDrawn = false;
            }
//            userFlowMode = MY_WORKS_MODE;
        }
        if (userFlowMode == START_MENU) {
            if (y >= ofGetHeight() / 2 - 60 && y <= ofGetHeight() / 2 - 20) {
                userFlowMode = PAINTING_MODE;
                hasDrawn = false;
            } else if (y >= ofGetHeight() / 2 && y <= ofGetHeight() / 2 + 40) {
                previousUserFlowMode = userFlowMode;
                userFlowMode = INSTRUCTION_MODE;
            } else if (y >= ofGetHeight() / 2 + 60 && y <= ofGetHeight() / 2 + 100) {
                ofExit();
            } else if (y >= ofGetHeight() / 2 + 120 && y <= ofGetHeight() / 2 + 160) {
                userFlowMode = MY_WORKS_MODE;
            }
        } else if (userFlowMode == INSTRUCTION_MODE) {
            userFlowMode = previousUserFlowMode;
        } else if (userFlowMode == PAINTING_MODE) {
            if (backButton.inside(x, y)) {
                userFlowMode = START_MENU;
            } else if (instructionButton.inside(x, y)) {
                previousUserFlowMode = userFlowMode;
                userFlowMode = INSTRUCTION_MODE;
            } else if (specialBrushesButton.inside(x, y)) {
                SPECIAL_BRUSHES_MODE = !SPECIAL_BRUSHES_MODE;
            }
        } else if (userFlowMode == MY_WORKS_MODE) {
            if (backButton.inside(x, y)) {
                userFlowMode = START_MENU;
            }
            else {
                for (size_t i = 0; i < savedWorkNames.size(); i++) {
                    if (y >= 50 + i * 30 && y <= 50 + (i + 1) * 30) {
                        canvasFbo = savedWorks[i];
                        userFlowMode = PAINTING_MODE;
                        break;
                    }
                }
            }
        }
    }
}

void ofApp::drawBrush() {
    ofPushStyle();
    ofPushMatrix();
    ofEnableBlendMode(blendMode);
    ofTranslate(ofGetMouseX(), ofGetMouseY());
    //======================================================================================//
    //implementing cycle color
    if (cycleColors) {
        float hue = std::fmod(ofGetElapsedTimef(), 1.0f);
        ofFloatColor color;
        color.setHsb(hue, 1.0, 1.0);
        ofSetColor(color);
    } else {
        ofSetColor(brushColor);
    }
    //======================================================================================//
    //implementing animations
    float animationTime = ofGetElapsedTimef();
    if (animationMode == ROTATION) {
        float rotationSpeed = 90; // degrees per second
        float rotationAngle = std::fmod(animationTime * rotationSpeed, 360.0);
        ofRotateZDeg(rotationAngle);
    } else if (animationMode == OSCILLATING_ROTATION) {
        float rotationSpeed = 90; // degrees per second
        float rotationAngle = std::fmod(animationTime * rotationSpeed, 360.0);
        float oscillatingFactor = sin(animationTime * 2 * PI);
        ofRotateZDeg(rotationAngle * oscillatingFactor);
    } else if (animationMode == TRANSLATION) {
        float translationAmplitude = 50; // pixels
        float translationX = translationAmplitude * sin(animationTime);
        ofTranslate(translationX, 0);
    } else if (animationMode == SCALING) {
        float scaleAmplitude = 0.5;
        float scaleFactor = 1 + scaleAmplitude * sin(animationTime);
        ofScale(scaleFactor, scaleFactor);
    }
    ofScale(brushSize);
    if (activeBrush == 0) {
        softCircleBrush.draw(-0.5 * softCircleBrush.getWidth(), -0.5 * softCircleBrush.getHeight());
    } else if (activeBrush == MESH_BRUSH_TRIANGLE) {
        meshBrushTriangle.draw();
    } else if (activeBrush == MESH_BRUSH_SUN) {
        meshBrushSun.draw();
    } else if (activeBrush == MESH_BRUSH_SQUARE) {
        meshBrushSquare.draw();
    } else if (activeBrush == MESH_BRUSH_CIRCLE) {
        meshBrushCircle.draw();
    } else if (activeBrush == MESH_BRUSH_STAR) {
        ofScale(0.4);
        meshBrushStar.draw();
    }else if (activeBrush == MESH_BRUSH_HEART) {
        ofScale(1.2);
        meshBrushHeart.draw();
    }else if (activeBrush == MESH_BRUSH_HEXAGON) {
        meshBrushHexagon.draw();
    }else if (activeBrush == MESH_BRUSH_WAVYCIRCLE) {
        meshBrushWavyCircle.draw();
    }else if (activeBrush == MESH_BRUSH_SPIRAL) {
        meshBrushSpiral.draw();
    }
    ofDisableBlendMode();
    ofPopMatrix();
    ofPopStyle();
}

void ofApp::setupMeshBrushTriangle() {
    float brushWidth = -0.5 *softCircleBrush.getWidth();
    float brushHeight = -0.5 *softCircleBrush.getHeight();
    
    meshBrushTriangle.addVertex(ofVec3f(0, -0.5 * brushHeight, 0));
    meshBrushTriangle.addVertex(ofVec3f(0.5 * brushWidth, 0.5 * brushHeight, 0));
    meshBrushTriangle.addVertex(ofVec3f(-0.5 * brushWidth, 0.5 * brushHeight, 0));
}




void ofApp::setupMeshBrushSquare() {
    float brushWidth = softCircleBrush.getWidth();
    float brushHeight = softCircleBrush.getHeight();

    // First triangle
    meshBrushSquare.addVertex(ofVec3f(-0.5 * brushWidth, -0.5 * brushHeight, 0));
    meshBrushSquare.addVertex(ofVec3f(0.5 * brushWidth, -0.5 * brushHeight, 0));
    meshBrushSquare.addVertex(ofVec3f(0.5 * brushWidth, 0.5 * brushHeight, 0));

    // Second triangle
    meshBrushSquare.addVertex(ofVec3f(-0.5 * brushWidth, -0.5 * brushHeight, 0));
    meshBrushSquare.addVertex(ofVec3f(0.5 * brushWidth, 0.5 * brushHeight, 0));
    meshBrushSquare.addVertex(ofVec3f(-0.5 * brushWidth, 0.5 * brushHeight, 0));
}




void ofApp::setupMeshBrushCircle() {
    int numVertices = 100; // Number of vertices for the circle
    float brushRadius = 0.5 * softCircleBrush.getWidth();
    float angleStep = 360.0 / numVertices;

    for (int i = 0; i < numVertices; ++i) {
        float angle1 = ofDegToRad(i * angleStep);
        float angle2 = ofDegToRad((i + 1) * angleStep);

        meshBrushCircle.addVertex(ofVec3f(0, 0, 0)); // Center point
        meshBrushCircle.addVertex(ofVec3f(brushRadius * cos(angle1), brushRadius * sin(angle1), 0));
        meshBrushCircle.addVertex(ofVec3f(brushRadius * cos(angle2), brushRadius * sin(angle2), 0));
    }
}



void ofApp::setupMeshBrushStar() {
    int numPoints = 5; // Number of points on the star
    float innerRadius = 0.5 * softCircleBrush.getWidth();
    float outerRadius = innerRadius * 2.0;
    float angleStep = 360.0 / (2 * numPoints);
    for (int i = 0; i < numPoints; ++i) {
        float innerAngle1 = ofDegToRad(2 * i * angleStep);
                float innerAngle2 = ofDegToRad((2 * i + 2) * angleStep);
                float outerAngle = ofDegToRad((2 * i + 1) * angleStep);

                meshBrushStar.addVertex(ofVec3f(innerRadius * cos(innerAngle1), innerRadius * sin(innerAngle1), 0));
                meshBrushStar.addVertex(ofVec3f(outerRadius * cos(outerAngle), outerRadius * sin(outerAngle), 0));
                meshBrushStar.addVertex(ofVec3f(innerRadius * cos(innerAngle2), innerRadius * sin(innerAngle2), 0));
            }
        }

void ofApp::setupMeshBrushHexagon() {
    int numSides = 6;
    float radius = 50;
    float angleStep = 360.0 / numSides;

    for (int i = 0; i < numSides; ++i) {
        float angle1 = ofDegToRad(i * angleStep);
        float angle2 = ofDegToRad((i + 1) * angleStep);

        meshBrushHexagon.addVertex(ofVec3f(0, 0, 0)); // Center point
        meshBrushHexagon.addVertex(ofVec3f(radius * cos(angle1), radius * sin(angle1), 0));
        meshBrushHexagon.addVertex(ofVec3f(radius * cos(angle2), radius * sin(angle2), 0));
    }
}




void ofApp::setupMeshBrushHeart() {
    float width = 50;
    float height = 50;
    // Upper half of the heart
    meshBrushHeart.addVertex(ofVec3f(0, -height / 4, 0));
    meshBrushHeart.addVertex(ofVec3f(-width / 4, -height / 4, 0));
    meshBrushHeart.addVertex(ofVec3f(-width / 2, 0, 0));
    
    meshBrushHeart.addVertex(ofVec3f(0, -height / 4, 0));
    meshBrushHeart.addVertex(ofVec3f(width / 4, -height / 4, 0));
    meshBrushHeart.addVertex(ofVec3f(width / 2, 0, 0));

    // Lower half of the heart
    meshBrushHeart.addVertex(ofVec3f(0, -height / 4, 0));
    meshBrushHeart.addVertex(ofVec3f(-width / 2, 0, 0));
    meshBrushHeart.addVertex(ofVec3f(0, height / 2, 0));

    meshBrushHeart.addVertex(ofVec3f(0, -height / 4, 0));
    meshBrushHeart.addVertex(ofVec3f(width / 2, 0, 0));
    meshBrushHeart.addVertex(ofVec3f(0, height / 2, 0));
}



void ofApp::setupMeshBrushSpiral() {
    int numPoints = 100;
    float radiusStep = 2;
    float angleStep = 10;

    for (int i = 0; i < numPoints - 1; ++i) {
        float angle1 = ofDegToRad(i * angleStep);
        float angle2 = ofDegToRad((i + 1) * angleStep);
        float radius1 = i * radiusStep;
        float radius2 = (i + 1) * radiusStep;

        meshBrushSpiral.addVertex(ofVec3f(radius1 * cos(angle1), radius1 * sin(angle1), 0));
        meshBrushSpiral.addVertex(ofVec3f(radius2 * cos(angle1), radius2 * sin(angle1), 0));
        meshBrushSpiral.addVertex(ofVec3f(radius2 * cos(angle2), radius2 * sin(angle2), 0));

        meshBrushSpiral.addVertex(ofVec3f(radius1 * cos(angle1), radius1 * sin(angle1), 0));
        meshBrushSpiral.addVertex(ofVec3f(radius2 * cos(angle2), radius2 * sin(angle2), 0));
        meshBrushSpiral.addVertex(ofVec3f(radius1 * cos(angle2), radius1 * sin(angle2), 0));
    }
}


void ofApp::setupMeshBrushWavyCircle() {
    int numPoints = 50;
    float radius = 50;
    float angleStep = 360.0 / numPoints;
    float waveAmplitude = 10;
    float waveFrequency = 8;

    for (int i = 0; i < numPoints; ++i) {
        float angle = ofDegToRad(i * angleStep);
        float angle2 = ofDegToRad((i + 1) * angleStep);
        float currentRadius = radius + waveAmplitude * sin(waveFrequency * angle);
        float nextRadius = radius + waveAmplitude * sin(waveFrequency * angle2);

        meshBrushWavyCircle.addVertex(ofVec3f(0, 0, 0)); // Center point
        meshBrushWavyCircle.addVertex(ofVec3f(currentRadius * cos(angle), currentRadius * sin(angle), 0));
        meshBrushWavyCircle.addVertex(ofVec3f(nextRadius * cos(angle2), nextRadius * sin(angle2), 0));
    }
}


void ofApp::setupMeshBrushSun() {
    int numPoints = 18; // Number of points on the star
    float innerRadius = 0.5 * softCircleBrush.getWidth();
    float outerRadius = innerRadius * 2.0;
    float angleStep = 360.0 / (2 * numPoints);

    for (int i = 0; i < numPoints; ++i) {
        float innerAngle1 = ofDegToRad(2 * i * angleStep);
        float innerAngle2 = ofDegToRad((2 * i + 2) * angleStep);
        float outerAngle = ofDegToRad((2 * i + 1) * angleStep);

        meshBrushSun.addVertex(ofVec3f(innerRadius * cos(innerAngle1), innerRadius * sin(innerAngle1), 0));
        meshBrushSun.addVertex(ofVec3f(outerRadius * cos(outerAngle), outerRadius * sin(outerAngle), 0));
        meshBrushSun.addVertex(ofVec3f(innerRadius * cos(innerAngle2), innerRadius * sin(innerAngle2), 0));
    }

    // Add the tail of the shooting star
    float tailLength = 80;
    meshBrushSun.addVertex(ofVec3f(0, -innerRadius, 0));
    meshBrushSun.addVertex(ofVec3f(0, -innerRadius - tailLength, 0));
}



void ofApp::printVisualElementsProportions() {
    int totalBrushCount = 0;
    for (auto &kv : brushCounters) {
        totalBrushCount += kv.second;
    }

    int totalColorCount = 0;
    for (auto &kv : colorCounters) {
        totalColorCount += kv.second;
    }

    int totalSizeCount = 0;
    for (auto &kv : sizeCounters) {
        totalSizeCount += kv.second;
    }

    std::cout << "Brush Proportions:" << std::endl;
    for (auto &kv : brushCounters) {
        std::cout << kv.first << ": " << (static_cast<float>(kv.second) / totalBrushCount) << std::endl;
    }

    std::cout << "Color Proportions:" << std::endl;
    for (auto &kv : colorCounters) {
        std::cout << "Color(" << kv.first.r << ", " << kv.first.g << ", " << kv.first.b << "): " << (static_cast<float>(kv.second) / totalColorCount) << std::endl;
    }

    std::cout << "Size Proportions:" << std::endl;
    for (auto &kv : sizeCounters) {
        std::cout << "Size(" << kv.first << "): " << (static_cast<float>(kv.second) / totalSizeCount) << std::endl;
    }
}


std::unordered_map<meshBrushTypes, std::unordered_map<Emotion, float>> initializeBrushEmotionWeights() {
    std::unordered_map<meshBrushTypes, std::unordered_map<Emotion, float>> brushEmotionWeights;
    
    brushEmotionWeights[MESH_BRUSH_DOT] = { {HAPPY, 0.1}, {SAD, 0.05}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_TRIANGLE] = { {HAPPY, 0.05}, {SAD, 0.1}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_SQUARE] = { {HAPPY, 0.05}, {SAD, 0.05}, {ANGRY, 0.1} };
    brushEmotionWeights[MESH_BRUSH_CIRCLE] = { {HAPPY, 0.1}, {SAD, 0.05}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_HEXAGON] = { {HAPPY, 0.05}, {SAD, 0.1}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_HEART] = { {HAPPY, 0.1}, {SAD, 0.05}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_STAR] = { {HAPPY, 0.1}, {SAD, 0.05}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_WAVYCIRCLE] = { {HAPPY, 0.05}, {SAD, 0.1}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_SPIRAL] = { {HAPPY, 0.05}, {SAD, 0.05}, {ANGRY, 0.1} };
    brushEmotionWeights[MESH_BRUSH_SUN] = { {HAPPY, 0.1}, {SAD, 0.05}, {ANGRY, 0.05} };
    
    return brushEmotionWeights;
}

Emotion ofApp::classifyEmotion() {
    // Emotion scores based on brush proportions
    std::unordered_map<Emotion, float> emotionScores = {
        {HAPPY, 0},
        {SAD, 0},
        {ANGRY, 0}
    };
    
    // Brush emotion weights
    std::unordered_map<meshBrushTypes, std::unordered_map<Emotion, float>> brushEmotionWeights = initializeBrushEmotionWeights();
    
    
    // Calculate the emotion score based on the brush proportions
    for (const auto& brushCounter : brushCounters) {
        for (const auto& emotionScore : emotionScores) {
            Emotion emotion = emotionScore.first;
            emotionScores[emotion] += brushCounter.second * brushEmotionWeights[brushCounter.first][emotion];
        }
    }
    
    // Calculate emotion scores based on color and size proportions
    for (const auto& colorCounter : colorCounters) {
        float saturation = colorCounter.first.getSaturation();
        float brightness = colorCounter.first.getBrightness();
        float size = colorCounter.second;
        // Factor in saturation and brightness for happy emotion
        emotionScores[HAPPY] += (saturation * brightness * size * 0.1);
        
        // Factor in low saturation and brightness for sad emotion
        emotionScores[SAD] += ((1 - saturation) * (1 - brightness) * size * 0.1);
        
        // Factor in saturation and low brightness for angry emotion
        emotionScores[ANGRY] += (saturation * (1 - brightness) * size * 0.1);
    }
    
    // Find the emotion with the highest score
    Emotion detectedEmotion = HAPPY;
    float maxScore = 0;
    for (const auto& emotionScore : emotionScores) {
        if (emotionScore.second > maxScore) {
            maxScore = emotionScore.second;
            detectedEmotion = emotionScore.first;
        }
    }
    
    return detectedEmotion;
}



void ofApp::launchAngryInterfaceFlowMode() {
    previousUserFlowMode = userFlowMode;
    userFlowMode = ANGER_MODE;
    angerModeCounter = 0;
    canvasFbo.begin();
    ofClear(0); // Set the background to black
    canvasFbo.end();
    completedAngerMode = false;
//        std::cout << "launched1" << std::endl;
}

void ofApp::launchSadInterfaceFlowMode() {
    previousUserFlowMode = userFlowMode;
    userFlowMode = SAD_MODE;
    sadModeCounter = 0;
    canvasFbo.begin();
    ofClear(0); // Set the background to black
    canvasFbo.end();
    completedSadMode = false;
//    std::cout << "launched1" << std::endl;
}

void ofApp::launchHappyInterfaceFlowMode(){
    previousUserFlowMode = userFlowMode;
    userFlowMode = HAPPY_MODE;
    canvasFbo.begin();
    ofClear(0); // Set the background to black
    canvasFbo.end();
    db2IsOn==true;
}

void ofApp::drawAngerMode() {
    canvasFbo.draw(0, 0);
    ofSetColor(200, 50, 50);
    ofDrawRectangle(backButton);
    ofSetColor(255);
    ofDrawBitmapString("Back", backButton.getPosition() + ofPoint(35, 20));
    ofSetColor(50, 200, 50);
    ofDrawRectangle(instructionButton);
    ofSetColor(255);
    ofDrawBitmapString("Instructions", instructionButton.getPosition() + ofPoint(5, 20));
//        std::cout << "launched2" << std::endl;
}

void ofApp::drawSadMode() {
    canvasFbo.draw(0, 0);
    ofSetColor(200, 50, 50);
    ofDrawRectangle(backButton);
    ofSetColor(255);
    ofDrawBitmapString("Back", backButton.getPosition() + ofPoint(35, 20));
    ofSetColor(50, 200, 50);
    ofDrawRectangle(instructionButton);
    ofSetColor(255);
    ofDrawBitmapString("Instructions", instructionButton.getPosition() + ofPoint(5, 20));
//    std::cout << "launched2" << std::endl;
}
void ofApp::drawHappyMode() {
    ofSetColor(200, 50, 50);
    ofDrawRectangle(backButton);
    ofSetColor(255);
    ofDrawBitmapString("Back", backButton.getPosition() + ofPoint(35, 20));

//    ofSetColor(50, 50, 200);
//    ofDrawRectangle(specialBrushesButton);
//    ofSetColor(255);
//    ofDrawBitmapString("Spec Effects", specialBrushesButton.getPosition() + ofPoint(1, 20));
    
    ofSetColor(50, 200, 50);
    ofDrawRectangle(instructionButton);
    ofSetColor(255);
    ofDrawBitmapString("Instructions", instructionButton.getPosition() + ofPoint(5, 20));
    
    canvasFbo.draw(0, 0);
    
    if(box1IsClicked){
        
        modes=1;
    }
    if(box2IsClicked){
        
        modes=2;
    }
    if(box3IsClicked){
        
        modes=3;
    }
    if(box4IsClicked){
        modes=4;
    }
    if(box5IsClicked){
        modes=5;
    }
    if(box6IsClicked){
        modes=6;
    }
    if(box7IsClicked){
        std::cout<<"box7IsClicked"<<std::endl;
        modes=7;
    }
    if(box8IsClicked){
        modes=8;
    }
    if(box0IsClicked){
        earaserIsOn=!earaserIsOn;
    }
    if(box9IsClicked){
        
        modes=9;
    }
    if(redIsClicked){
        r=255;
        g=0;
        b=0;// draw red when botton clicked
    }
    if(greenIsClicked){
        g=255;
        r=0;
        b=0;// draw green  when botton clicked
    }
    if(blueIsClicked){
        b=255;
        r=0;
        g=0;// draw blue  when botton clicked
    }
    if(darkIsClicked){
        b=0;
        r=0;
        g=0;// draw black when botton clicked
    }
    if(lightIsClicked){
        b=255;
        r=255;
        g=255;// draw white  when botton clicked
    }
    
//    if(SPECIAL_BRUSHES_MODE==true){
        if(earaserIsOn==false){
            //drawing each clickable botton
            
            img1.draw(botton1);
            img2.draw(botton2);
            img3.draw(botton3);
            img4.draw(botton4);
            img5.draw(botton5);
            img6.draw(botton6);
            img7.draw(botton7);
            img8.draw(botton8);
            imgRed.draw(red);
            imgGreen.draw(green);
            imgBlue.draw(blue);
            imgDark.draw(dark);
            ofDrawRectangle(light);
        }
//    }else{
//        imgEraser.draw(botton0);
//    }
}


void ofApp::dynamicEffect_3(float x, float y, float speed, glm::vec2 direction) {

    ofSetLineWidth(10);
    glm::vec2 limited = direction * ofClamp(speed, 10, 300);
    //map speed paramater to scale, clamp it in this range
    float scale = ofMap(speed, 1, 70, 10, 40, true);
    
    //Drawing from right to left. Mowing towards left increases the value of colour_changes_x.
    int colour_changed_x = ofMap(direction.x, -1, 1, 0, 255);
    //Drawing from top to bottom. Mowing downwards increases the value of colour_changes_y.
    int colour_changed_y = ofMap(direction.y, 0, -1, 0, 255);
    //As speed increases, alpha value decreases
    int alpha_changed = ofMap(speed,1,400, 255,0);
    
    
    ofPushMatrix();
  
    ofTranslate(x, y);
    // sets the colour value;
    //Red channel value increases as mouse moves towards left of the screen
    //Green channel value increases as mouse moves downwards
    //Blue channel set to 100
    //Alpha channel dcreases as speed of the mouse movement increases
    ofSetColor(colour_changed_x, colour_changed_y, 100, alpha_changed);
    //draws the curve line at the following points mouseX and mouse Y & limited.x , limited.y, which account for float x1 , float y1, float x2 , float y2 , respectively
    // the control points are set to the opposite values ammended by the scale variable
    ofDrawCurve(10*scale, 10*scale, 0, 0, limited.x, limited.y, -10 *scale, -10 * scale);
    ofPopMatrix();
    
}

void ofApp::staticEffect1(float x,float y,float size){
    ofSetRectMode(OF_RECTMODE_CENTER);//set the rectmode to centre
    ofSetColor(r,g,b,100);//pass the r,g,b vairable to color so it can be changed by GUI
    ofDrawRectangle(x+ofRandom(-20,20), y+ofRandom(-20,20), size*ofRandom(2),size*ofRandom(2));//draw random size rectangles at random pos between -20,20
    ofDrawRectangle(x+ofRandom(-13,14), y+ofRandom(-13,13), size*ofRandom(2),size*ofRandom(2));
    
}


void ofApp::dynamicEffect1(float x, float y,float size, int red, int green, int blue){
    ofSetColor(red+r/2, green+g/2, blue+b/2 );//globle variable color r,g,b controled by GUI plus the flowing color controlled by sin wave, so the color of brush is flowing also contrallable by GUI
    ofDrawCircle(x, y, size);
}


void ofApp::simpleEffect(float x, float y){
    float time=ofGetElapsedTimef();//set time to odgetellapsedtime to let brush flow/wave back up and down
    for(int j=-10;j<10;j++){
        for(int i=-20; i<20; i++){
            ofSetColor(r+127*sin(i*0.001+time*j), g+127*sin(i*0.0056+time*j), b+127*sin(i*0.0057+time));//again, flowing color plus globle variable r,g,b, so it can be changed by GUI
            ofDrawCircle(x+sin(i*0.01+time)*j,y+i, 1+sin(i*0.005+time));//some interesting values setting brush wave
        }
    }
}


void ofApp::dynamicEffect3(float x, float y, float speed, glm::vec2 direction){
    ofNoFill();
    //map speed paramater to scale, clamp it in this range
    float scale = ofMap(speed,1,20,0.1,0.3,true);
    ofSetLineWidth(5);//you can play around this, different firework effct
    // "forward" direction of my triangle drawing
    glm::vec2 drawingDir = glm::vec2(0,-1);
    //roation angle between "forward" of drawing and mouse move direction
    float angle = atan2(direction.x, direction.y) - atan2(drawingDir.x,drawingDir.y);//in radians
    //multiply unit vector by clamped value
    glm::vec2 limited = direction * ofClamp(speed,1,10);
    ofPushMatrix();
    //    translate to mouse position
    ofTranslate(x, y);
    ofScale(scale);
    float time=ofGetElapsedTimef();
    for(int x=-20;x<20;x++){
        for(int i=0; i<5; i+=5){
            ofRotateRad(-angle);
            ofSetColor(r/2+127*sin(i*0.001+time), g/2+127*sin(i*0.0056+time), b/2+127*sin(i*0.0057+time));//change r,g,b while dragging mouse, more beautiful
            // ofDrawCircle(1, i, 50);         //uncomment this and comment out the line, it is a new eery simple dynamic brush
            ofDrawCircle(50*x*sin(i*0.01+time),50+i, sin(i*0.005+time));
        }
    }
    ofPopMatrix();
}


void ofApp::dynamicEffect4(float x, float y, float speed, glm::vec2 direction){
    ofNoFill();
    //map speed paramater to scale, clamp it in this range
    float scale = ofMap(speed,1,50,0.05,0.1,true);
    // "forward" direction of my triangle drawing
    glm::vec2 drawingDir = glm::vec2(0,-1);
    //roation angle between "forward" of drawing and mouse move direction
    float angle = atan2(direction.x, direction.y) - atan2(drawingDir.x,drawingDir.y);//in radians
    ofSetLineWidth(1);
    //multiply unit vector by clamped value
    glm::vec2 limited = direction * ofClamp(speed,1,30);
    ofPushMatrix();
    //    translate to mouse position
    ofTranslate(x, y);
    //simple line
    //rotating and scaling a drawing
    ofScale(scale);
    //-angle aligns the rotation direction with direction of mouse
    ofRotateRad(-angle);
    float time=ofGetElapsedTimef();// again, flowing effect
    for(int j=0;j<40;j++){
        for(int i=0; i<900; i+=5){
            ofSetColor(r/2+127*sin(i*0.001+time+j), g/2+127*sin(i*0.0056+time+j), b/2+127*sin(i*0.0057+time));//flowing color plus globle variable r,g,b, so it can be changed by GUI
            ofDrawCircle(5+100*sin(i*0.01+time),20+i, 50+40*sin(i*0.005+time+j));
        }
    }
    ofPopMatrix();
}




void ofApp::dynamicEffect2(float x, float y){
    ofSetCircleResolution(100);
    float time=ofGetElapsedTimef();
    int n=5*2+3;
    for(int j=-10;j<40;j++){
        for(int i=0; i<90; i+=5){
            x+=50*(4/(n*M_PI))*cosf(n*time);//here I used concept from fourier series, so x and y of two circle are circling to each other, // https://thecodingtrain.com/challenges/125-fourier-series
            y+=50*(4/(n*M_PI))*sinf(n*time);
            ofSetColor(r+127*sin(i*0.001+time+j), g+127*sin(i*0.0056+time+j),b+127*sin(i*0.0057+time));
            ofDrawCircle(x, y, 13);
            ofSetColor(127+127*sin(i*0.001+time),127+127*sin(i*0.0056+time+j),127+127*sin(i*0.0057+time+j),30);
            x+=50*(4/(n*M_PI))*-cosf(n*time);//again, here I used concept from fourier series, set -sin and -cos so one circle is circling another
            y+=50*(4/(n*M_PI))*-sinf(n*time);
            ofDrawCircle(x, y, 13);
        }
    }
}

void ofApp::dynamicEffect5(float x, float y, float speed){
//map speed paramater to scale, clamp it in this range
float scale = ofMap(speed,1,50,0.1,2,true);

    ofPushMatrix();
    //    translate to mouse position
    ofTranslate(x, y);
    //rotating and scaling a drawing
    ofFill();
    ofSetColor(r,g,b);
    ofScale(scale);
    //code below is so redundant, just to intensify the brush
    ofDrawCircle(ofRandom(-10,10), ofRandom(-10,10), 0.3);
    ofDrawCircle(ofRandom(-10,10), ofRandom(-10,10), 0.3);
    ofDrawCircle(ofRandom(-10,10), ofRandom(-10,10), 0.3);
    ofDrawCircle(ofRandom(-10,10), ofRandom(-10,10), 0.3);
    ofDrawCircle(ofRandom(-10,10), ofRandom(-10,10), 0.3);
    ofDrawCircle(ofRandom(-10,10), ofRandom(-10,10), 0.3);
    ofDrawCircle(ofRandom(-10,10), ofRandom(-10,10), 0.3);
    ofDrawCircle(ofRandom(-10,10), ofRandom(-10,10), 0.3);
    ofDrawCircle(ofRandom(-10,10), ofRandom(-10,10), 0.3);
    ofDrawCircle(ofRandom(-8,8), ofRandom(-8,8), 0.5);
    ofDrawCircle(ofRandom(-8,8), ofRandom(-8,8), 0.5);
    ofDrawCircle(ofRandom(-8,8), ofRandom(-8,8), 0.5);
    ofDrawCircle(ofRandom(-5,5), ofRandom(-5,5), 0.5);
    ofDrawCircle(ofRandom(-5,5), ofRandom(-5,5), 0.5);
    ofDrawCircle(ofRandom(-5,5), ofRandom(-5,5), 0.5);
    ofDrawCircle(ofRandom(-5,5), ofRandom(-5,5), 0.5);
    ofDrawCircle(ofRandom(-2,2), ofRandom(-2,2), 0.5);
    ofDrawCircle(ofRandom(-2,2), ofRandom(-2,2), 0.5);
    ofDrawCircle(ofRandom(-2,2), ofRandom(-2,2), 0.5);
    ofDrawCircle(ofRandom(-2,2), ofRandom(-2,2), 0.5);
    ofPopMatrix();
}

void ofApp::dynamicEffect(float x, float y, float speed, glm::vec2 direction){
    gs.draw(x,y);
  }

void ofApp::simpleEraser(float x, float y){
    ofSetColor(0);
    ofDrawCircle(x, y, 50);//nothing fancy, just a erser
}
