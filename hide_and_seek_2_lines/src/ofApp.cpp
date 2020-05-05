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
    
    if(drawLine){
        t++;
    };
    
    if(t>100){
        
        mouselines.push_back(mouseline);
        touchlines.push_back(touchline);
        tshadowlines.push_back(tshadowline);
        
        t=0;
        drawLine=false;
        mouseline.clear();
        touchline.clear();
        tshadowline.clear();
    };
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetLineWidth(2);
    ofNoFill();
    ofDrawRectangle(0,0, 720, 720);
    ofDrawRectangle(720, 0, 720, 720);
    ofFill();
   
//show mousepoint and mouseshadow
    ofColor pink(255,49,99);
    ofSetColor(pink);
    
    
    ofDrawCircle(mousepoint, 10);
    ofDrawCircle(mouseshadow, 10);
    

    
    
//move and show touchpoint and touchshadow
    ofSetColor(255);
    touchpoint.x=20+oscx*700;
    touchpoint.y=20+ofMap(oscy, 1, 0, 0, 1)*700;

    touchshadow.x=touchpoint.x+720;
    touchshadow.y=touchpoint.y;
    
    ofDrawCircle(touchpoint, 10);
    ofDrawCircle(touchshadow, 10);
    

    
//draw saved lines
    ofSetColor(pink);
    for (int i=0;i<mouselines.size();i++){
        ofPolyline mline=mouselines[i];
        mline.draw();
    };
    
    mouseline.draw();
    
    
    ofSetColor(255);
    ofSetLineWidth(2);
    for(int i=0;i<touchlines.size();i++){
        ofPolyline tline=touchlines[i];
        tline.draw();
    };
    
    for(int i=0;i<tshadowlines.size();i++){
        ofPolyline tsline=tshadowlines[i];
        tsline.draw();
    };
    
    //draw touchline if collide
    if(drawLine){
    touchline.addVertex(touchpoint);
    touchline.draw();
    tshadowline.addVertex(touchshadow);
    tshadowline.draw();
    };
    ofSetLineWidth(2);

    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
 
    if(key=='a'){
        touchlines.clear();
    };
    

    
    if(key=='j'){
        mouselines.clear();
        tshadowlines.clear();
    };

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    mousepoint.x=x;
    mousepoint.y=y;
    mouseshadow.x=x-720;
    mouseshadow.y=y;
    
    if(drawLine){
        mouseline.addVertex(x,y);
        
    };

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
