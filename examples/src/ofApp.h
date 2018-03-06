#pragma once

#include "ofMain.h"
#include "ofxFuturisticUI.h"

class ofApp : public ofBaseApp{
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
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

    float gap;
    futureGauge g1;
    futureGauge g2;
    futureGauge g3;
    futureGauge g4;
    
    futureGrid grid1;
    futureGrid grid2;
    
    groupFrame gaugeGroup;
};
