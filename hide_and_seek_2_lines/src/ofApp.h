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
  
 //things shown
    ofPoint mousepoint,mouseshadow;
    ofPoint touchpoint,touchshadow;
    
    ofPolyline mouseline;
    ofPolyline touchline;
    ofPolyline tshadowline;
    
    vector <ofPolyline> mouselines;
    vector <ofPolyline> touchlines;
    vector <ofPolyline> tshadowlines;
    
  //osc
    ofxOscReceiver osc;
    float oscx=0.0;
    float oscy=0.0;
    
 //about collide
    int t;
    bool drawLine=false;
    bool drawMshadow=false;
    bool drawTshadow=false;

    
    void checkCollide(ofPoint a,ofPoint b){
        if((a-b).length()<=10){
            drawLine=true;
        }
    };
		
};
