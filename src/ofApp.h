#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        vector<string> tokenise(string input, char sep);

        map<string,string> addWordsToLiLi(map<string,string> LiLi, string words);
   
        vector<string> getMapKeys(map<string,string> theMap);

        void onTextChange(string& text);
        void onTextChangeBig(string& text);
        void LiLiBot(string inputText);

      
        ofxGuiGroup gui;
        ofParameterGroup parameters;
        ofParameter<string> textParameter;
    
        deque<string> messageBuffer;
        deque<string> messageBufferBig;
        float lineHeight;
		
       
        vector<string> phrases;
        vector<string> words;
        map <string,string> wordChain;
};
