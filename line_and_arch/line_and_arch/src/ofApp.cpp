#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	cam.setDistance (900);
	cam.disableMouseInput();
	ofVec3f yAxis(0, 1, 0);
	ofVec3f origin(0, 0, 0);
	ofVec3f lineStart(0, 0, 300);
	cam.rotateAroundDeg(45,yAxis,origin);
	cam.lookAt(lineStart, yAxis);
	
	yOn = ofGetWindowHeight()/2;

	p.x = 0;
	p.y = 0;
	
	t = 0;
	tDown = 0;
	arcs = 0;
	arce = 0;
	rs = 0;
	rl = 0;
	v = 0;
	yV = ofGetWindowHeight() / 2;
	vX = 0;


	color.r = 255;
	color.g = 255;
	color.b = 0;
	color.a = 0;
	iterator = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ifOn) {
		t0 = t;
		v0 = v;

		color0 = color;


		arcs0 = arcs;
		arce0 = arce;



		rl0 = rl;
		rs0 = rs;
		pRelease = p;

		t = 0;
		tDown = 0;
		arcs = 0;
		arce = 0;
		rs = 0;
		rl = 0;
		v = 0;
		yV = ofGetWindowHeight() / 2;
		color.a = 0;
		vX = 0;
		
		
		
		
	}


	if ((rl0 != 0)&&(tRelease<=10*t0)) {
		tRelease++;
		//pRelease.x +=  0.1*tRelease;
		//pRelease.y +=  0.1*tRelease;
		release = true;
	}
	


	if ((iterator != 0) && (ifOn == false)) {
		/*rl = 300;
		rs = 200;
		arcs = 0;
		arce = 270;*/

		t++;
		
		
		arcsize = mX - xOn;
		if(mY>yOn){ 
			yV = fmax(mY, yV);
			
			if (mY >= yV) {
				tUp = t;
			};
			if (mY < yV) {
				tDown = t - tUp;
			}
			
		};
		if (mY<yOn) {
			yV = fmin(mY, yV);
			
			if (mY <= yV) {
				tUp = t;
			};
			if (mY > yV) {
				tDown = t - tUp;
			}

		};

		vX = arcsize / t;
		v = (yV - yOn) / 1000.0;
		arcs += v * t;
		arce = arcs + arcsize * 2;

		color.a = tUp * 4;
		color.r = 255 - 100 * vX;
		color.g = 255 - 300 * vX;
		color.b = 150 * vX;

		rl = 3 * t;
		rs = 0.6*t+2.1*tDown;
		p.z = ofGetWindowWidth() / 2 - mX;
		p.y = ofGetWindowHeight() / 2 - mY;
		
		
		

		
	};

	

	


}

//--------------------------------------------------------------
void ofApp::draw(){

	ofDrawLine(0, ofGetWindowHeight()/2, ofGetWindowWidth(), ofGetWindowHeight()/2);
	cam.begin();

	ofSetColor(255, 255, 255, 127);
	ofDrawLine(0,0,-1000, 0,0, 1000);
	ofSetColor(255);
	
	ofEnableSmoothing();
	line.draw();

	ofPath curve;
	

	
	curve.arc(p, rl, rl, arcs, arce);
	curve.arcNegative(p, rs, rs, arce, arcs);
	curve.close();
	curve.setArcResolution(60);
	curve.setFillColor(color);
	curve.setFilled(true);

	curve.draw();

	if (release) {
		ofPath curve2;

		curve2.arc(pRelease, rl0, rl0, arcs0, arce0);
		curve2.arcNegative(pRelease, rs0, rs0, arce0, arcs0);
		curve2.close();
		curve2.setArcResolution(60);
		curve2.setFillColor(color0);
		curve2.setFilled(true);

		curve2.draw();
	};



	cam.end();
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
	mX = x;
	mY = y;
	line.addVertex(0, ofGetWindowHeight() / 2-mY,ofGetWindowWidth() / 2-mX);

	

	/*if (ifOn) {
		t = 0;
		arcs = 0;
		arce = 0;
		rs = 0;
		rl = 0;
		v = 0;
		yMax = 0;

	}*/
	



	if ((mY>yOn-5)&&(mY<yOn+5)){
		iterator++;
		ifOn = true;
		xOn = mX;
	}
	else {
		ifOn = false;
	};
	//else {
		//ifOn = false;
	//}
	

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	line.clear();
	

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	

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
