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
  
 //control point
    ofPoint mousepoint,mouseshadow;
    ofPoint touchpoint,touchshadow;

//current line
    ofPolyline mouseline;
    ofPolyline mshadowline;
    ofPolyline touchline;
    ofPolyline tshadowline;
    
//lines shown
    vector <ofPolyline> Amouselines;
    vector <ofPolyline> Bmouselines;
    vector <ofPolyline> Atouchlines;
    vector <ofPolyline> Btouchlines;
    vector <ofPolyline> Amslines;
    vector <ofPolyline> Bmslines;
    vector <ofPolyline> Atslines;
    vector <ofPolyline> Btslines;
    
//which world
    bool ifB=false;
    
  //osc
    ofxOscReceiver osc;
    float oscx=0.0;
    float oscy=0.0;
    
 //about collide
    
    //a minimum time to judge next collide
    int mint ;
    
    bool collide=false;
    bool drawMshadow=false;
    bool drawTshadow=false;

    
    void checkCollide(ofPoint a,ofPoint b){
        if((a-b).length()<=10){
            collide=true;
        } else {
            collide=false;
        };
    };
		
};
