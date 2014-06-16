#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    height = ofGetHeight();
    width = ofGetWidth();
    
    // Work out number of triangles x and y
    numTriY = 100;
    triHeight = height/numTriY; // we want 100 triangles deep so get the height(altitude) of each trianle
    triSide = (2/sqrt(3)) * triHeight ; // get the length of the edge of a triangle a = (2 / Ã3) * h
    numTriX = floor(width/triSide); // Number of whole tris we can fit across the screen
    numTri = numTriX * numTriY;
    
    // Create the points
    for(int y = 0; y<=numTriY; y++){ // Row by row
        int posX = 0;
        int rowPoints = numTriX + 1;
        if(y % 2 == 0){ // Odd numbered rows have 1 point less
            rowPoints = numTriX;
            posX += triSide/2; // add a half tri offset to point
        }
        
        for(int x = 0; x < rowPoints; x++){ // column by column
            ofPoint point = ofPoint(posX, y * triSide);
//            cout << "X: " << ofToString(point.x) << " Y: " << ofToString(point.y) << endl;
            vertices.push_back(point);
            posX += triSide;
        }
    }
//    cout << "Vertices: " << vertices.size() << endl; // 12776
    // Create the
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int y = 0; y<=numTriY; y++){ // Row by row
        for(int x = 0; x < (numTriX *2) -1; x++){ // column by column
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Draw the triangles
    
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
