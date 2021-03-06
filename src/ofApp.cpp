#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    ofSetColor(0);
    
    ofSetCircleResolution(100);
    
    float spacing = ofGetWidth() / person_count;
    float start_x = spacing / 2.0;
    for(int i=0 ; i <person_count ; i++) {
        people.push_back(ofPoint(start_x + i*spacing, ofGetHeight()/2.0));
    }
    
    radius_interval = (ofGetWidth()/2.0 - 50) / ring_count;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    ofPushStyle();
    ofNoFill();
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
    for(int i=0 ; i < ring_count ; i++) {
        ofDrawCircle(0,0,(i+1)*radius_interval);
    }
    ofPopStyle();
    ofPopMatrix();
    
    for(int i=0 ; i < people.size() ; i++) {
        draw_person(people[i]);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ') {
        ofSaveScreen(ofToString(ofGetFrameNum()) + ".png");
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
    if(focused) {
        people[people.size()-1] = ofPoint(x,y) - focus_offset;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofPoint mouse_pos = ofPoint(x,y);
    int focus = -1;
    // cycle backwards to pick up top elements first
    for(int i=people.size()-1 ; i >= 0 ; i--) {
        ofPoint delta = mouse_pos - people[i];
        float dist = sqrt(delta.x * delta.x + delta.y * delta.y);
        if(dist <= person_size) {
            focus = i;
            focus_offset = delta;
            break;
        }
    }
    if(focus >= 0) {
        ofPoint focused_person = people[focus];
        people.erase(people.begin() + focus);
        people.push_back(focused_person);
        focused = true;
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    focused = false;
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

// utilities

void ofApp::draw_person(ofPoint pos) {
    
    ofPushStyle();
    
    ofPoint delta = pos - ofPoint(ofGetWidth()/2.0, ofGetHeight()/2.0);
    float dist = sqrt(delta.x * delta.x + delta.y * delta.y);
    if(dist > ring_count*radius_interval) {
        ofSetColor(255,0,0, 30);
    } else {
        ofSetColor(255,0,0, 255);
    }
    
    
    ofFill();
    ofDrawCircle(pos.x, pos.y, person_size);
    ofSetColor(0, 255);
    ofNoFill();
    ofDrawCircle(pos.x, pos.y, person_size);
    ofPopStyle();
    
}
