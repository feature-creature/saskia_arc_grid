#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        void sas4(int phase);
        void arcs(ofColor arcColor, int rotation, float arcDiameter);
    
        float counter;
    
		
};
