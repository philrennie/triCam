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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void setColour(int x, int y);
    
    ofVideoGrabber vgrabber;
	
    // Screen
    int width;
    int height;
    
    // Number of Tri's x and y
    float triHeight;
    float triSide;
    int numTriX;
    int numTriY; // will be 100
    
    int numTri; // total number of triangles
    
    vector<ofPoint> vertices;
    vector<ofColor> colours;
};
