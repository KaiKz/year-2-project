#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(150);
    textParameter.addListener(this, &ofApp::onTextChange);
    textParameter.addListener(this, &ofApp::onTextChangeBig);
    
    parameters.setName("Text input");
    parameters.add(textParameter.set("", ""));
    gui.setDefaultWidth(ofGetWidth()-20);
    gui.setup(parameters);
    

    gui.setPosition(10,10);
    lineHeight = 40;
    
    messageBuffer.push_front("LiLi>> Hi there, how are you doing today?");
    
    
    ifstream fileIn(ofToDataPath("shortLines.txt", true));
    string input;

    while(getline(fileIn,input)){
//        phrases.push_back(input);
        wordChain = addWordsToLiLi(wordChain, input);
        //cout << input << endl;
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    
    for(int i = 0; i < messageBuffer.size(); i++){
        ofDrawBitmapString(messageBuffer[i], 10, 70 + lineHeight * i);
    }
    
    for(int i = 0; i < messageBufferBig.size(); i+=10){
        ofDrawBitmapString(messageBufferBig[i], 80, 170 + lineHeight * i);
    }
        
    float messagePxHeight = messageBuffer.size() * lineHeight + 70;
    float messagePxHeightBig = messageBufferBig.size() * lineHeight + 70;
    if(messagePxHeight > ofGetHeight()){
        messageBuffer.pop_back();
    }
    if(messagePxHeightBig > ofGetHeight()){
        messageBufferBig.pop_back();
    }
    
}

void ofApp::onTextChange(string& text){
    if(text != ""){
        cout << text << endl;
        messageBuffer.push_front("user>> " + text);
        LiLiBot(text);
        textParameter.set("");
    }
}
void ofApp::onTextChangeBig(string& text){
    if(text != ""){
        cout << text << endl;
        messageBufferBig.push_front("user>> " + text);
        LiLiBot(text);
        textParameter.set("");
    }
}

void ofApp::LiLiBot(string inputText){
    string nexts, lastWord, output;
    vector<string> words;
    int index;
    
    wordChain = addWordsToLiLi(wordChain, inputText); // process the input into the LiLi
    // split the input into words
    words = tokenise(inputText, ' ');
    lastWord = words.back();// use the last word they said as the first query for the LiLi chain
    output = "";
    for (int i=0;i<ofRandom(10);i++){
      
        nexts = wordChain[lastWord];
        words = tokenise(nexts, ' ');
        if (nexts.size() == 0){
            words = getMapKeys(wordChain);
        }
        else {
            //    std::cout << "got something "<<  std::endl;
        }
        index = ofRandom(words.size());
        lastWord = words[index];
        output += lastWord + " ";
    }
    
    messageBuffer.push_front("LiLi>> " + output);
//    messageBufferBig.push_front("LiLi>> " + output);
    
}

vector<string> ofApp::tokenise(string input, char sep){
    vector<string> vec;
    int end;
    //https://cplusplus.com/reference/string/string/find_first_not_of/
    //params: seperator string, char position to start searching
    int start = input.find_first_not_of(sep, 0);
    string token;

    //  std::cout << "processing '"<< input << "'" << input.length() << std::endl;
    do{
        end = input.find_first_of(sep, start);
        //std::cout << start << " - " << end << std::endl;
        if (start == input.length() || start == end){
            break;
        }
        if (end >= 0){
            token = input.substr(start, end - start);
        }
        else {
            token = input.substr(start, input.length() - start);
        }
        //std::cout << "got token " << token << std::endl;
        vec.push_back(token);
       
        start = end + 1;
    } while (end > 0);
  
    return vec;
}


map <string, string> ofApp::addWordsToLiLi(map <string,string> LiLi, string words){
  string now, prev, nexts;
  vector <string> tempStrings = tokenise(words, ' ');
  // iterate the word sequence
  
  for (int i=1; i<tempStrings.size();i++){
    //    std::cout << " adding " << tempStrings[i] << " to the chain ";
    now = tempStrings[i];
    prev = tempStrings[i-1];
    nexts = LiLi[prev];
    nexts += now + " ";
    LiLi[prev] = nexts;
    //    std::cout << "obs following " << prev << " updated to '" << nexts << "'" << std::endl;
  }
  
  return LiLi;
}

vector<string> ofApp::getMapKeys(map<string,string> theMap){
  vector<string> vec;
  for (map<string,string>::iterator it=theMap.begin(); it!=theMap.end(); ++it){
    //std::cout << it->first << " => " << it->second << '\n';
    vec.push_back(it->first);
  }
  return vec;
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
