#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//we run at 60 fps!
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	ofSetBackgroundAuto(false);
	
	ofSetCircleResolution(200);
	ofSetLineWidth(2);

	gap = 130/1280.0*ofGetWidth();

	g1 = futureGauge(ofGetWidth()/2-gap*3,200.0/720.0*ofGetHeight(),200.0/1280.0*ofGetWidth(),"gauge 1");
	g1.maxVal = 1.0;
	g1.setGaugeValue(ofRandom(g1.maxVal));

	g2 = futureGauge(ofGetWidth()/2-gap,200.0/720.0*ofGetHeight(),200.0/1280.0*ofGetWidth(),"gauge 2");
	g2.maxVal = 0.2;
	g2.setGaugeValue(ofRandom(g2.maxVal));

	g3 = futureGauge(ofGetWidth()/2+gap,200.0/720.0*ofGetHeight(),200.0/1280.0*ofGetWidth(),"gauge 3");
	g3.maxVal = 1.0;
	g3.setGaugeValue(ofRandom(g3.maxVal));

	g4 = futureGauge(ofGetWidth()/2+gap*3,200.0/720.0*ofGetHeight(),200.0/1280.0*ofGetWidth(),"gauge 4");
	g4.maxVal = 1.0;
	g4.setGaugeValue(ofRandom(g4.maxVal));

	grid1 = futureGrid(135/1280.0*ofGetWidth(),375/720.0*ofGetHeight(),460/1280.0*ofGetWidth(),250/720.0*ofGetHeight(),"Grid 1");
    grid2 = futureGrid(685/1280.0*ofGetWidth(),375/720.0*ofGetHeight(),460/1280.0*ofGetWidth(),250/720.0*ofGetHeight(),"Grid 2");
    
    gaugeGroup = groupFrame(50,50,1000,200,"Group Frame");
	gaugeGroup.addUIelement(ofRectangle(g1.x-g1.s/2, g1.y-g1.s/2, g1.s, g1.s));
    gaugeGroup.addUIelement(ofRectangle(g2.x-g2.s/2, g2.y-g2.s/2, g2.s, g2.s));
    gaugeGroup.addUIelement(ofRectangle(g3.x-g3.s/2, g3.y-g3.s/2, g3.s, g3.s));
    gaugeGroup.addUIelement(ofRectangle(g4.x-g4.s/2, g4.y-g4.s/2, g4.s, g4.s));
    gaugeGroup.setMargin(15, 15);



	for(int i=0; i<129; i++) {
		grid1.addVertex( 1, ofNoise(ofRandom(100))*0.25 );
		grid1.addVertex( 2, ofNoise(ofRandom(50))*0.25 +0.25 );
		grid1.addVertex( 3, ofNoise(ofRandom(70))*0.25 +0.5 );
		grid1.addVertex( 4, ofNoise(ofRandom(200))*0.25 +0.75 );

		grid2.addVertex( 1, ofNoise(ofRandom(100))*0.25 );
		grid2.addVertex( 2, ofNoise(ofRandom(50))*0.25 +0.25 );
		grid2.addVertex( 3, ofNoise(ofRandom(70))*0.25 +0.5 );
		grid2.addVertex( 4, ofNoise(ofRandom(200))*0.25 +0.75 );
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);
    
    g1.draw();
    g2.draw();
    g3.draw();
    g4.draw();
    gaugeGroup.draw();
    
    grid1.draw();
    grid2.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key) {
		case 'a':
			grid1.addVertex(1,ofRandom(0.25,0.75));
			grid1.addVertex(2,ofRandom(0.25,0.75));
			grid1.addVertex(3,ofRandom(0.25,0.75));
			grid1.addVertex(4,ofRandom(0.25,0.75));
			break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	 //g1.setValue(ofMap(x,0,ofGetWidth(),0,g1.maxVal));
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
