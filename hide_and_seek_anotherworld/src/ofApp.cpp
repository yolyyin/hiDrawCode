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
    
//what happens when collide
    
    checkCollide(touchpoint,mouseshadow);
    
    if(collide){
        if(mint==0){
            ifB=!ifB;};
        mint++;
    };
    
    if(mint>0 && collide==false){
        
    if(!ifB){
        Btouchlines.push_back(touchline);
        Amouselines.push_back(mouseline);
        Btslines.push_back(tshadowline);
        Amslines.push_back(mshadowline);
        
        mouseline.clear();
        mshadowline.clear();
        touchline.clear();
        tshadowline.clear();
        
        mint=0;
        };
        
    if(ifB){
        Atouchlines.push_back(touchline);
        Bmouselines.push_back(mouseline);
        Atslines.push_back(tshadowline);
        Bmslines.push_back(mshadowline);
        
        collide=false;
        mouseline.clear();
        mshadowline.clear();
        touchline.clear();
        tshadowline.clear();
        
        mint=0;
        };
        
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
 
//add vertex to touchline and touchshadow
    touchline.addVertex(touchpoint);
    tshadowline.addVertex(touchshadow);
    
    touchline.getSmoothed(3);
    tshadowline.getSmoothed(3);
    mouseline.getSmoothed(3);
    mshadowline.getSmoothed(3);
    

    
//draw A world lines
    
    if(!ifB)
    {
        //mouse
        ofSetColor(pink);
        for (int i=0;i<Amslines.size();i++){
            ofPolyline line=Amslines[i];
            line.draw();
        };
        
        for (int i=0;i<Bmouselines.size();i++){
            ofPolyline line=Bmouselines[i];
            line.draw();
        };
        mouseline.draw();
        
        //touch
        ofSetColor(255);
        for (int i=0;i<Atouchlines.size();i++){
            ofPolyline line=Atouchlines[i];
            line.draw();
        };
        
        for (int i=0;i<Btslines.size();i++){
            ofPolyline line=Btslines[i];
            line.draw();
        };
        touchline.draw();
        
    };
    
//draw B world lines
    
    if(ifB)
    {
        //mouse
        ofSetColor(pink);
        for (int i=0;i<Bmslines.size();i++){
            ofPolyline line=Bmslines[i];
            line.draw();
        };
        
        for (int i=0;i<Amouselines.size();i++){
            ofPolyline line=Amouselines[i];
            line.draw();
        };
        mouseline.draw();
        
        //touch
        ofSetColor(255);
        for (int i=0;i<Btouchlines.size();i++){
            ofPolyline line=Btouchlines[i];
            line.draw();
        };
        
        for (int i=0;i<Atslines.size();i++){
            ofPolyline line=Atslines[i];
            line.draw();
        };
        touchline.draw();
        
    };
    
    
  
    
  




    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
 
    if(key=='c'){
        Atouchlines.clear();
        Atslines.clear();
        Amouselines.clear();
        Amslines.clear();
        Btouchlines.clear();
        Btslines.clear();
        Bmouselines.clear();
        Bmslines.clear();
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
    
    
    mouseline.addVertex(x,y);
    mshadowline.addVertex(x-720,y);
        
    

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    if(ifB){
        Amouselines.push_back(mouseline);
        mouseline.clear();
        Amslines.push_back(mshadowline);
        mshadowline.clear();
    };

    if(!ifB){
        Bmouselines.push_back(mouseline);
        mouseline.clear();
        Bmslines.push_back(mshadowline);
        mshadowline.clear();
    };
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
