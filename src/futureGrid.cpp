#include "futureGrid.h"


futureGrid::futureGrid(void)
{
	    x=0;
        y=0;
        w=460;
        h=250;
        str = "futureGrid";
		verticesShow = 128;
        font.loadFont("Autobus-Bold.ttf",h*0.06);
}

futureGrid::futureGrid(float _x, float _y, float _w, float _h, string _str){
        x=_x;
        y=_y;
        w=_w;
        h=_h;
        str = _str;
		verticesShow = 128;
        font.loadFont("Autobus-Bold.ttf",h*0.06);
}

void futureGrid::draw() {
    ofNoFill();
    ofSetLineWidth(0.5);
    ofSetColor(100, 255, 205);
        
    ofRect(x,y,w,h);
    font.drawString(str,x,y-w*0.03*0.5);
        
    ofSetLineWidth(0.5);
    for(int i=1;i<5;i++) {
        ofLine(x,y+h/5.0*i,x+w,y+h/5.0*i);
    }
    for(int i=1;i<5;i++) {
        ofLine(x+w/5.0*i,y,x+w/5.0*i,y+h);
    }
        
    for(int i=0;i<=5;i++) {
        if(i==0)
            ofDrawBitmapString(ofToString((int)(i*128/5)),x+w/5.0*i-5,y+h+20);
        else
            ofDrawBitmapString(ofToString((int)(i*128/5)),x+w/5.0*i-10,y+h+20);
            
    }

	ofSetLineWidth(2);
    // draw vertices1
	if(vertices1.size()<verticesShow ) {
		ofBeginShape();
		for(int i=0;i<vertices1.size();i++){
			ofVertex(x+i*w/verticesShow,y+h-vertices1[i]*h);
		}
		ofEndShape();
	}
	else {
		ofBeginShape();
		for(int i=vertices1.size()-verticesShow;i<vertices1.size();i++){
			ofVertex(x+(i-(vertices1.size()-verticesShow))*w/verticesShow,y+h-vertices1[i]*h);
		}
		ofEndShape();
	}

	    // draw vertices2
	ofSetColor(255, 92, 28);
	if(vertices2.size()<verticesShow ) {
		ofBeginShape();
		for(int i=0;i<vertices2.size();i++){
			ofVertex(x+i*w/verticesShow,y+h-vertices2[i]*h);
		}
		ofEndShape();
	}
	else {
		ofBeginShape();
		for(int i=vertices2.size()-verticesShow;i<vertices2.size();i++){
			ofVertex(x+(i-(vertices2.size()-verticesShow))*w/verticesShow,y+h-vertices2[i]*h);
		}
		ofEndShape();
	}
	    // draw vertices3
	ofSetColor(255, 165, 250);
	if(vertices3.size()<verticesShow ) {
		ofBeginShape();
		for(int i=0;i<vertices3.size();i++){
			ofVertex(x+i*w/verticesShow,y+h-vertices3[i]*h);
		}
		ofEndShape();
	}
	else {
		ofBeginShape();
		for(int i=vertices3.size()-verticesShow;i<vertices3.size();i++){
			ofVertex(x+(i-(vertices3.size()-verticesShow))*w/verticesShow,y+h-vertices3[i]*h);
		}
		ofEndShape();
	}
	// draw vertices4
	ofSetColor(221, 253, 255);
	if(vertices4.size()<verticesShow ) {
		ofBeginShape();
		for(int i=0;i<vertices4.size();i++){
			ofVertex(x+i*w/verticesShow,y+h-vertices4[i]*h);
		}
		ofEndShape();
	}
	else {
		ofBeginShape();
		for(int i=vertices4.size()-verticesShow;i<vertices4.size();i++){
			ofVertex(x+(i-(vertices4.size()-verticesShow))*w/verticesShow,y+h-vertices4[i]*h);
		}
		ofEndShape();
	}
}

void futureGrid::addVertex(int num, float _vert) {
	switch(num) {
		case 1:
			vertices1.push_back(_vert);
			break;
		case 2:
			vertices2.push_back(_vert);
			break;
		case 3:
			vertices3.push_back(_vert);
			break;
		case 4:
			vertices4.push_back(_vert);
			break;
	}
}

void futureGrid::setFontSize(float fontSize) {
	font.unbind();
	font.loadFont("Autobus-Bold.ttf",fontSize);
}

futureGrid::~futureGrid(void)
{
}
