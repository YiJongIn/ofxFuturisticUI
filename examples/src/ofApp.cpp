#include "ofApp.h"

vector<float> gainCurve;

//--------------------------------------------------------------
void ofApp::setup(){
	//we run at 60 fps!
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	//ofSetWindowPosition(ofGetScreenWidth(),0);


    //create the socket and bind to port 11999
	udpConnection.Create();
	udpConnection.Bind(7777);
	udpConnection.SetNonBlocking(true);

	ofSetBackgroundAuto(false);
	//ofBackground(255, 255, 255);
	ofSetCircleResolution(200);
	ofSetLineWidth(2);

	gap = 130/1280.0*ofGetWidth();

	g1 = futureGauge(ofGetWidth()/2-gap*3,200.0/720.0*ofGetHeight(),200.0/1280.0*ofGetWidth(),"Cmu");
	g1.maxVal = 1.0;
	g2 = futureGauge(ofGetWidth()/2-gap,200.0/720.0*ofGetHeight(),200.0/1280.0*ofGetWidth(),"Csigma");
	g2.maxVal = 0.2;
	g3 = futureGauge(ofGetWidth()/2+gap,200.0/720.0*ofGetHeight(),200.0/1280.0*ofGetWidth(),"delta");
	g3.maxVal = 1.0;
	g4 = futureGauge(ofGetWidth()/2+gap*3,200.0/720.0*ofGetHeight(),200.0/1280.0*ofGetWidth(),"nu");
	g4.maxVal = 50.0;

    
    grid1 = futureGrid(135/1280.0*ofGetWidth(),375/720.0*ofGetHeight(),460/1280.0*ofGetWidth(),250/720.0*ofGetHeight(),"Moving Target Selection");
    grid2 = futureGrid(685/1280.0*ofGetWidth(),375/720.0*ofGetHeight(),460/1280.0*ofGetWidth(),250/720.0*ofGetHeight(),"Autogain Curve");
    
    gaugeGroup = groupFrame(50,50,1000,200,"User Performance");
	gaugeGroup.addUIelement(ofRectangle(g1.x-g1.s/2, g1.y-g1.s/2, g1.s, g1.s));
    gaugeGroup.addUIelement(ofRectangle(g2.x-g2.s/2, g2.y-g2.s/2, g2.s, g2.s));
    gaugeGroup.addUIelement(ofRectangle(g3.x-g3.s/2, g3.y-g3.s/2, g3.s, g3.s));
    gaugeGroup.addUIelement(ofRectangle(g4.x-g4.s/2, g4.y-g4.s/2, g4.s, g4.s));
    gaugeGroup.setMargin(15, 15);


}

//--------------------------------------------------------------
void ofApp::update(){
	char udpMessage[100000];
	udpConnection.Receive(udpMessage,100000);
	string message=udpMessage;
	if(message!=""){
		cout<<"RECEIVED : "<<message<<endl;
		vector<string> strPoints = ofSplitString(message,",");
	
		if(!strPoints[0].compare("autogain")) {
			gainCurve.clear();
			int i=0;
			for(string s:strPoints) {
				if(i!=0) {
					cout<<"value "<<i<<": "<<ofToFloat(s)<<endl;
					gainCurve.push_back(ofToFloat(s));
				}
				i++;
			}
		}
		if(!strPoints[0].compare("bottom")) {
			for(int i=1;i<=4;i++) {
				grid1.addVertex(i,ofToFloat(strPoints[i]));
				cout<<"vertex "<<i<<": "<<ofToFloat(strPoints[i]) <<" added"<<endl;
			}
		}
		if(!strPoints[0].compare("top")) {
			g1.setGaugeValue(ofToFloat(strPoints[1])/g1.maxVal);
			g2.setGaugeValue(ofToFloat(strPoints[2])/g2.maxVal);
			g3.setGaugeValue(ofToFloat(strPoints[3])/g3.maxVal);
			g4.setGaugeValue(ofToFloat(strPoints[4])/g4.maxVal);
		}
		strPoints.clear();		
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofPushMatrix();
	//ofTranslate(-ofGetWidth()*0.1, -ofGetHeight()*0.1);
	//ofScale(1.2,1.2);
	
	ofBackground(0);
    
    g1.draw();
    g2.draw();
    g3.draw();
    g4.draw();
    gaugeGroup.draw();
    
    //g2.setValue(ofNoise(ofGetElapsedTimef()*0.1)*100);
    //g3.setValue(ofNoise(ofGetElapsedTimef()*0.15+100)*100);
    //g4.setValue(ofNoise(ofGetElapsedTimef()*0.2+200)*100);
    
    grid1.draw();
    grid2.draw();

    
    // data for plots

    //drawSamplePlot1(165, 415);
    //drawSamplePlot2(685, 625);

	int	i=0;
	//ofSetPolyMode();
	ofNoFill();
    ofSetColor(100, 255, 205);

	float maximumGain = 0;
	for(float val:gainCurve) {	
		if(maximumGain < val) {
			maximumGain = val;
		}
	}
	maximumGain = (int)(maximumGain / 10) *10 +10 ;

	ofBeginShape();
	for(float val:gainCurve) {
		if(i<128) ofVertex(1+i/128.0*grid2.w+685,625-val/(float)maximumGain*grid2.h);
		i++;
	}
	ofEndShape();

	//ofPopMatrix();
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

void ofApp::drawSamplePlot1(float _x, float _y) {
    ofSetLineWidth(5);
    ofLine(_x, _y, 20+_x, _y+80);
    ofLine(20+_x, 80+_y, 70+_x, 30+_y);
    ofLine(70+_x, 30+_y, 170+_x,_y+100);
    ofLine(170+_x,100+_y, 240+_x, 30+_y);
    ofLine(240+_x, 30+_y, 340+_x, 150+_y);
    ofLine(340+_x, 150+_y, 400+_x, _y+120);
}

void ofApp::drawSamplePlot2(float _x, float _y) {
    ofLine(_x, _y, _x+20, _y-30);
    ofLine(_x+20, _y-30,_x+50, _y-60);
    ofLine(_x+50, _y-60, _x+80, _y-100);
    ofLine(_x+80, _y-100, _x+160, _y-170);
    ofLine(_x+160, _y-170, _x+230, _y-190);
    ofLine(_x+230, _y-190, _x+330, _y-200);
    ofLine(_x+330, _y-200, _x+460, _y-205);
}