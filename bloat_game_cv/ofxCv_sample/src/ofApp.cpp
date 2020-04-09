#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	
	o1.setup(0);
	o2.setup(1);
	
	blowSpeed = 1;
	message.load("OpenSans.ttf", 40);
	


	grabber.setup(1280, 720);

	



}

//--------------------------------------------------------------
void ofApp::update() {

	grabber.update();
	if (loose == 0) {
		


		if (grabber.isFrameNew() && start == true) {
			finder.setTargetColor(targetColor, ofxCv::TRACK_COLOR_HS);
			finder.setThreshold(50);
			finder.setSortBySize(true);
			finder.findContours(grabber);
		};

		o1.update();
		o2.update();

		blowR += blowSpeed;
		if (blowR <0 || blowR>ofGetWidth()) {
			blowSpeed *= -1;
		};
	}



	
	






}

//--------------------------------------------------------------
void ofApp::draw() {


	ofSetColor(255);


	grabber.draw(0,0);


	ofSetLineWidth(2);

	//finder.draw();
	ofPoint pointer(-1000,-1000);
	if (finder.size() > 0) {
		//finder.getPolyline(0).draw();

		
		pointer = finder.getPolyline(0).getBoundingBox().getCenter();
		ofSetColor(190, 99, 189);
		ofDrawCircle(pointer, blowR);
	


	};

	ofSetColor(100,149,237);
	o1.draw();
	o2.draw();

	ofPath cpath1,cpath2, ppath;
	ppath.circle(pointer, blowR);
	cpath1.circle(o1.cX, o1.cY, o1.cR);
	cpath2.circle(o2.cX, o2.cY, o2.cR);
	cline1= cpath1.getOutline()[0];
	cline2 = cpath2.getOutline()[0];
	pline = ppath.getOutline()[0];




	for (int i = 0; i < pline.size()-1; i++) {
		ofSetColor(0, 255, 0);
		//ofDrawLine(pline[i], pline[i + 1]);
		for (int j=0; j < cline1.size()-1;j++){
			//ofDrawLine(cline1[j], cline1[j + 1]);
			
			//ofLineSegmentIntersection
			if (lineLine(pline[i],pline[i+1],cline1[j],cline1[j+1])==true && start==true) {
				loose ++;		
			}	
		}
		for (int k = 0; k < cline2.size() - 1; k++) {
			//ofDrawLine(cline2[k], cline2[k + 1]);

			if (lineLine(pline[i], pline[i + 1], cline2[k], cline2[k + 1]) == true && start == true) {
				loose ++;
			}
		}

	};


	if (loose != 0) {
		ofSetColor(100, 100, 100, 127);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		ofSetColor(190, 99, 189);
		ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, blowR);
		ofSetColor(255);
		string text = "A bloat of " + to_string(blowR) + " !";
		message.drawString(text, ofGetWidth() / 2 - message.stringWidth(text) / 2, ofGetHeight() / 2 - message.stringHeight(text) / 2);
	};



	ofSetColor(targetColor);
	ofDrawRectangle(0, 0, 64, 64);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ') {
		blowSpeed = 0;
	};
	if (key == 'r'){
		loose = 0;
		blowR = 0;
	};



}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == ' ') {
		blowSpeed = 1;
	};

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

	start = true;
	targetColor = grabber.getPixels().getColor(x, y);
	blowR = 10;


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
