#pragma once

#include "ofMain.h"

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
    
        void draw_person(ofPoint pos);
    
        vector<ofPoint> people;
    
    
        const float person_size {20};
        const int person_count {10};
        const int ring_count {6};
        float radius_interval;
    
        bool focused {false};
        ofPoint focus_offset;
    
		
};
