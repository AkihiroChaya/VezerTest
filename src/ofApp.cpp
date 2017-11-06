#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // of settings
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    _vezerOscReceiver.setup(VEZER_OSC_PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    while(_vezerOscReceiver.hasWaitingMessages())
    {
        ofxOscMessage m;
        _vezerOscReceiver.getNextMessage(m);
        
        for(int i=0; i<m.getNumArgs(); i++){
            if(m.getAddress() == "/radius"){
                for(int i = 0; i < m.getNumArgs(); i ++)
                {
                    radius = m.getArgAsInt32(i);
                }
            }else if(m.getAddress() == "/color"){
                for(int i = 0; i < m.getNumArgs(); i +=4)
                {
                    color.r = ofMap(m.getArgAsFloat(i),0,1,0,255);
                    color.g = ofMap(m.getArgAsFloat(i+1),0,1,0,255);
                    color.b = ofMap(m.getArgAsFloat(i+2),0,1,0,255);
                    color.a = ofMap(m.getArgAsFloat(i+3),0,1,0,255);
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0,0);
    myDrawCircle(color,radius);
}

//--------------------------------------------------------------
void ofApp::myDrawCircle(ofColor c , int r){
    ofSetColor(c);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, r);
}

//--------------------------------------------------------------
void ofApp::myDrawRect(){
    
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
