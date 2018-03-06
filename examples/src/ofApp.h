#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"
#include "ofxTrueTypeFontUC.h"
#include "ofxFuturisticUI.h"
//#include "futureGauge.h"
//#include "futureGrid.h"
//#include "groupFrame.h"

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
	void drawSamplePlot1(float _x, float _y);
	void drawSamplePlot2(float _x, float _y) ;
	ofxUDPManager udpConnection;

	//ofTrueTypeFont font;
	ofxTrueTypeFontUC font;
    ofPath arcPath, gaugePath;

    float gap;
    futureGauge g1;
    futureGauge g2;
    futureGauge g3;
    futureGauge g4;
    
    futureGrid grid1;
    futureGrid grid2;
    
    groupFrame gaugeGroup;
};
