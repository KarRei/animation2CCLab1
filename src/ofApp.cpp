#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(90);
    xpos = 50;  // horizontal start position
    ypos = 50;
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
    
    if ((xpos == 50 && ypos == 50) or (xpos < ofGetWidth()-50 && ypos == 50)){ // LAB1: Move along TOP
        xpos = xpos + steps;
    } else if (xpos > ofGetWidth()-50) { // Stop condition for upper right corner
        xpos = ofGetWidth()-50;
    } else if ((xpos == ofGetWidth()-50 && ypos == 50) or (ypos < ofGetHeight()-50 && xpos == ofGetWidth()-50)) { // Move along RIGHT
        ypos = ypos + steps;
    } else if (ypos > ofGetHeight()-50){ // Stop condition for lower right corner
        ypos = ofGetHeight()-50;
    } else if ((xpos == ofGetWidth()-50 && ypos == ofGetHeight()-50) or (xpos > 50 && ypos == ofGetHeight()-50)) { // Move along BOTTOM
        xpos = xpos - steps;
    } else if (xpos < 50) { // Stop condition for lower left corner
        xpos = 50;
    } else if ((xpos == 50 && ypos == ofGetHeight()-50) or (ypos > 50 && xpos == 50)){ // Move along LEFT
        ypos = ypos - steps;
    } else if (ypos < 50) { // Stop condition for upper left corner
        ypos = 50;
    }
    
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(230, 123, 10); //sets the color of the circle below
    ofDrawCircle(xpos, ypos, 50);   // draw a circle at the (variable) horizontal position, starting at the top of the screen and with a diameter of 50

    ofSetColor(20, 213, 10);
    string info = "x-position: " + ofToString(xpos,2);
    ofDrawBitmapString(info , 100, 100);
    
    string info1 = "y-position: " + ofToString(ypos,2);
    ofDrawBitmapString(info1 , 100, 120);
    
    string info2 = "steps: " + ofToString(steps,2);
    ofDrawBitmapString(info2 , 100, 140);
    
    string info3 = "frame rate: " + ofToString(ofGetFrameRate(),2);
    ofDrawBitmapString(info3 , 100, 160);
    
    string info4 = "height: " + ofToString(ofGetHeight(),2);
    ofDrawBitmapString(info4 , 100, 180);
    
    string info5 = "width: " + ofToString(ofGetWidth(),2);
    ofDrawBitmapString(info5 , 100, 200);

    

    
}
