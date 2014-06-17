#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    height = ofGetHeight();
    width = ofGetWidth();
    
    // Work out number of triangles x and y
    numTriY = 50;
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
            vertices.push_back(point);
            posX += triSide;
        }
    }
    
    vgrabber.setDeviceID(0);
    vgrabber.setDesiredFrameRate(30);
    vgrabber.initGrabber(numTriX*2,numTriY);
}

void ofApp::setColour(int x, int y){
    ofSetColor( vgrabber.getPixelsRef().getColor(x, y));
}

//--------------------------------------------------------------
void ofApp::update(){
    vgrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Create the triangles
    for(int y = 0; y<numTriY; y++){ // Row by row
        // first vertice of row = (y * numtri) + floor(y/2)
        int firstVert = (y * numTriX) + floor(y/2);
        
        if(y % 2 == 0){ // even rows
            for(int x = 0; x < (numTriX * 2)-1; x++){
                float floatX = x;
                if(x % 2 == 0){ // even tris
                    setColour(x, y);
                    ofTriangle (
                               vertices[(x/2) + firstVert],
                               vertices[(x/2) + 1 + numTriX + firstVert],
                               vertices[(x/2) + numTriX + firstVert]
                               );
                } else { // odd tris
                    setColour(x+1, y);
                    ofTriangle(
                               vertices[((x-1)/2) + firstVert],
                               vertices[((x+1)/2) + firstVert],
                               vertices[ceil(floatX/2) + numTriX + firstVert]
                               );
                }
//                cout << floor(x/2) + 1 + numTriX + firstVert << endl;
            }
        } else { // odd rows
            for(int x = 0; x < (numTriX * 2)-1; x++){
                float floatX = x;
                if(x % 2 == 0){ // even tris
                    setColour(x, y);
                    ofTriangle(
                               vertices[(x/2) + firstVert],
                               vertices[ceil((floatX+1)/2) + firstVert],
                               vertices[ceil(floatX/2) + 1 + numTriX + firstVert]
                               );
                } else { // odd tris
                    setColour(x+1, y);
                    ofTriangle(
                               vertices[((x-1)/2) + firstVert + 1],
                               vertices[ceil(floatX/2) + 1 + numTriX + firstVert],
                               vertices[ceil(floatX/2) + numTriX + firstVert]
                               );
                }
            }
        }
        
    }
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
