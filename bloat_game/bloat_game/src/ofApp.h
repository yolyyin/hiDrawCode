#pragma once

#include "ofMain.h"

#include "ofxCv.h"




class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	bool lineLine(ofVec3f vec1, ofVec3f vec2, ofVec3f vec3, ofVec3f vec4) {
		float x1 = vec1.x;
		float y1 = vec1.y;
		float x2 = vec2.x;
		float y2 = vec2.y;
		float x3 = vec3.x;
		float y3 = vec3.y;
		float x4 = vec4.x;
		float y4 = vec4.y;

		//x1 float y1, float x2, float y2, float x3, float y3, float x4, float y4

		// calculate the distance to intersection point
		float uA = ((x4 - x3)*(y1 - y3) - (y4 - y3)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));
		float uB = ((x2 - x1)*(y1 - y3) - (y2 - y1)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));

		// if uA and uB are between 0-1, lines are colliding
		if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {

			// optionally, draw a circle where the lines meet
			/*float intersectionX = x1 + (uA * (x2 - x1));
			float intersectionY = y1 + (uA * (y2 - y1));*/
			float intersectionX = x1 + (uA * (x2 - x1));
			float intersectionY = y1 + (uA * (y2 - y1));
			ofSetColor(255, 26, 0, 127);
			ofDrawCircle(intersectionX, intersectionY, 10);
			ofSetColor(255);


			return true;
		}
		return false;
	};


	class Obstacle {
	public:
		int cX;
		int cY;
		int cR;
		int xspeed, yspeed;
		int xdirection, ydirection;
		ofPath path;

		void setup(int d) {
			if (d == 0) {
				cX = ofRandom(0, ofGetHeight());
				cY = 0;
				cR = ofRandom(10, 100);
				xdirection = 1;
				ydirection = 1;
				xspeed = 10;
				yspeed = 10;
			}
			else if (d == 1) {
				cX = ofRandom(0, ofGetHeight());
				cY = ofGetHeight();
				cR = ofRandom(10, 100);
				xdirection = -1;
				ydirection = -1;
				xspeed = -10;
				yspeed = -10;
			};


		};

		void update() {

			cY += yspeed; cX += xspeed;
			if ((cY > ofGetHeight() || cY < 0) && cX <= ofGetWidth() && cX >= 0) {
				cR = ofRandom(10, 100);
				cX = ofRandom(0, ofGetHeight());
				ydirection *= -1;
				yspeed = ofRandom(5, 10)*ydirection;
				cY += ydirection * 5;
			};
			if ((cX > ofGetWidth() || cX < 0) && cY <= ofGetHeight() && cY >= 0) {
				cR = ofRandom(10, 100);
				cY = ofRandom(0, ofGetHeight());
				xdirection *= -1;
				xspeed = ofRandom(5, 10)*xdirection;
				cX += xdirection * 5;
			};
			if ((cX > ofGetWidth() || cX < 0) && (cY > ofGetHeight() || cY < 0)) {
				cX = ofRandom(0, ofGetHeight());
				cY = 0;
				cR = ofRandom(10, 100);
				xdirection = 1;
				ydirection = 1;
				xspeed = 5;
				yspeed = 5;

			};


		};
		ofPath getPath() {
			path.circle(cX, cY, cR);
			return path;
		};
		void draw() {
			ofDrawCircle(cX, cY, cR);
		};
	};



	int loose = 0;
	ofTrueTypeFont message;

	bool start = false;
	Obstacle o1;
	Obstacle o2;
	//ofPolyline cline1, cline2;
	//ofPolyline pline;

	int blowR;
	int blowSpeed;


	ofVideoGrabber grabber;


	ofxCv::ContourFinder finder;
	ofColor targetColor;





};
