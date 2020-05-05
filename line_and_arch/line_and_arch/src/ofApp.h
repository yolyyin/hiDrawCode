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

		int mX;
		int mY;
		int xOn;
		int arcsize;
		int yOn;
		int yV;
		int t,t0,tRelease;

		int tUp;
		int tDown;
		float vX;

		int iterator = 0;
		bool ifOn = false;

		ofPoint p,pRelease;

		float rs,rs0;
		float rl,rl0;
		float arcs,arcs0;
		float arce,arce0;
		ofColor color,color0;
		float v,v0;
		bool release = false;



		ofEasyCam cam;
		
		

		ofPolyline line;
		
};
