#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // http://sasj.tumblr.com/post/162953278415/geometric-animations-170713
    counter = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    counter++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    sas4(counter);
}


//--------------------------------------------------------------
void ofApp::sas4(int phase) {

    // layout config
    float gridSize = ofGetWidth()/5;
    float arcDist = gridSize/18;

    // define colors and line width
    ofColor red = ofColor(200,20,0);
    ofColor white = ofColor(255,255,255);
    ofSetBackgroundColor(0);
    ofSetLineWidth(4);

    // grid rectangles
    ofPushMatrix();
    ofPushStyle();
    ofNoFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(white);
    ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/2, gridSize*3, gridSize*3);
    ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/2, gridSize, gridSize);
    ofSetColor(red);
    ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/2, gridSize*2, gridSize*2);
    ofPopStyle();
    ofPopMatrix();

    
    // set of white arc units
    ofPushMatrix();
    ofTranslate(gridSize, gridSize);
    for(int j=1; j<5; j++) {
        for(int k=1; k<5; k++) {
            float rotate = ofMap(sin(ofDegToRad(phase*1.5) - (j*k/1.5)),-1,1,0,360);
            ofPushMatrix();
                ofTranslate(gridSize*k - gridSize, gridSize*j-gridSize);
                arcs(white,rotate, arcDist);
            ofPopMatrix();
        }
    }
    
    // set of red arc units
    ofPopMatrix();
    ofPushMatrix();
    ofTranslate(gridSize+gridSize/2, gridSize+gridSize/2);
    for(int j=1; j<4; j++) {
        for(int k=1; k<4; k++) {
            float rotate = ofMap(sin(ofDegToRad(phase*1.5) - (j*k/1.5)),-1,1,0,360);
            ofPushMatrix();
                ofTranslate(gridSize*k - gridSize, gridSize*j-gridSize);
                arcs(red,rotate, arcDist);
            ofPopMatrix();
        }
    }
    ofPopMatrix();
}


void ofApp::arcs(ofColor arcColor, int rotation, float arcDiameter) {
    // single unit of 4 arcs
    ofPath path;
    path.setMode(ofPath::POLYLINES);
    path.setCircleResolution(200);
    path.setFilled(false);
    path.setStrokeWidth(4);
    path.setCurveResolution(200);
    path.setStrokeColor(arcColor);
    path.newSubPath();
    path.arc(0,0, arcDiameter, arcDiameter, rotation, rotation + 180);
    path.newSubPath();
    path.arc(0,0, arcDiameter*3, arcDiameter*3, rotation,rotation + 180);
    path.newSubPath();
    path.arc(0,0, arcDiameter*2, arcDiameter*2, 180 - rotation, 360 - rotation);
    path.newSubPath();
    path.arc(0,0, arcDiameter*4, arcDiameter*4,180 - rotation, 360 - rotation);
    path.draw();
}















