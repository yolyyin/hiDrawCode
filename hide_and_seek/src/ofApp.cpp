#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    osc.setup(PORT);
    mousepoint.x=640;
    mousepoint.y=-20;
    mouseshadow.x=20;
    mouseshadow.y=-20;

}

//--------------------------------------------------------------
void ofApp::update(){

    while (osc.hasWaitingMessages()){
        ofxOscMessage m;
        osc.getNextMessage(&m);
        
        if(m.getAddress()=="/position/x"){
            oscx=m.getArgAsFloat(0);
        };
        
        if(m.getAddress()=="/position/y"){
            oscy=m.getArgAsFloat(0);
        };
    };
    
    checkCollide(touchpoint,mouseshadow);
    
    if(drawPath){
        t++;
    };
    
    if(t>30){
        t=0;
        drawPath=false;
    };
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetLineWidth(2);
    ofNoFill();
    ofDrawRectangle(0,0, 720, 720);
    ofDrawRectangle(720, 0, 720, 720);
    ofFill();
    
    ofColor pink(255,49,99);
    ofSetColor(pink);
    ofDrawCircle(mousepoint, 10);
    //ofDrawCircle(mouseshadow, 10);
    ofSetColor(255);
    
    
    
    touchpoint.x=20+oscx*700;
    touchpoint.y=20+ofMap(oscy, 1, 0, 0, 1)*700;
    touchshadow.x=touchpoint.x+720;
    touchshadow.y=touchpoint.y;
    
    ofDrawCircle(touchpoint, 10);
    //ofDrawCircle(touchshadow, 10);
    
    Apath.setColor(pink);
    Apath.draw();
    Ashadow.setColor(pink);
    Ashadow.draw();
    
    
    Bpath.setColor(255);
    //Bpath.draw();
    Bshadow.setColor(255);
    Bshadow.draw();
    
    
    if(drawPath){
        
        Apath.circle(mousepoint, 5);
        Ashadow.circle(mouseshadow,5);
        
        Bpath.circle(touchpoint, 5);
        Bshadow.circle(touchshadow,5);
                
    };
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='a'){
        Apath.clear();
        Bshadow.clear();
    };
    
    if(key=='b'){
        Bpath.clear();
        Ashadow.clear();
    };

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
        mousepoint.x=x;
        mousepoint.y=y;
        mouseshadow.x = x-720;
        mouseshadow.y=y;
    

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
   


}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
 

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
