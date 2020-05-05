#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 12345

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
    
    ofPoint mousepoint,mouseshadow;
    ofPoint touchpoint,touchshadow;
    
    bool hasmouse;
    
    ofPath Apath,Ashadow;
    ofPath Bpath,Bshadow;
    
    int t;
    bool drawPath=false;
    bool drawMshadow=false;
    bool drawTshadow=false;
    
    ofxOscReceiver osc;
    
    float oscx=0.0;
    float oscy=0.0;
    
    void checkCollide(ofPoint a,ofPoint b){
        if((a-b).length()<=20){
            drawPath=true;
        }
    };
		
};
