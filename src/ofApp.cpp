#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(90);
    xpos = 50;  // horizontal start position
    steps = ofRandom(1, 10);
    ofBackground(ofColor::black);  // black background
}

//--------------------------------------------------------------
void ofApp::update(){
   
    // LAB1: Change speed every 5sec
    if (ofGetFrameNum() % (60*5) == 0) {
        
        int tempSteps = ofRandom(1, 10);
        
        if(steps < 0) {
            steps = -tempSteps;
        }
        else{
            steps = tempSteps;
        }
    }
    xpos = xpos + steps;
   
    if (xpos > ofGetWidth()){
        xpos = ofGetWidth();
        steps = -steps;
        
    } else if (xpos < 0){
        xpos = 0;
        steps = -steps;
        
    }
    
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(230, 123, 10); //sets the color of the circle below
    ofDrawCircle(xpos, 50, 50);   // draw a circle at the (variable) horizontal position, starting at the top of the screen and with a diameter of 50

    ofSetColor(20, 213, 10);
    string info = "position: " + ofToString(xpos,2);
    ofDrawBitmapString(info , 100, 100);
    
    string info2 = "steps: " + ofToString(steps,2);
    ofDrawBitmapString(info2 , 100, 120);
    
    string info3 = "frame rate: " + ofToString(ofGetFrameRate(),2);
    ofDrawBitmapString(info3 , 100, 140);

    

    
}
