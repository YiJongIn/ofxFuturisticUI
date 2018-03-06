#include "futureGauge.h"


futureGauge::futureGauge(void)
{
	    x=0;
        y=0;
        s=200;
        str="futureGauge";
		gaugeSize = s*0.42;
        gauge = 0.7;
        gaugeAngle = 180-middleAngle/2;
        middleAngle = 90;
        minVal = 0.0; maxVal = 100;

		arcPath.arc(0,0,s*0.5,s*0.5,180-middleAngle/2,360+middleAngle/2);
        arcPath.setCircleResolution(200);
        arcPath.setFillColor(ofColor(100,255,205));
        
        gaugePath.arc(0,0,gaugeSize,gaugeSize,180-middleAngle/2,180-middleAngle/2+1);
        gaugePath.setCircleResolution(200);
        gaugePath.setFillColor(ofColor(100,255,205,150));
        font.loadFont("Autobus-Bold.ttf", s*0.15);
        valuefont.loadFont("Autobus-Bold.ttf", s*0.1);
}

futureGauge::futureGauge(float _x, float _y, float _s, string _str) {
        x=_x;
        y=_y;
        s=_s;
        str=_str;
        gaugeSize = s*0.42;
        gauge = 0.7;
        gaugeAngle = 180-middleAngle/2;
        middleAngle = 90;
        minVal = 0.0; maxVal = 100;
        
        arcPath.arc(0,0,s*0.5,s*0.5,180-middleAngle/2,360+middleAngle/2);
        arcPath.setCircleResolution(200);
        arcPath.setFillColor(ofColor(100,255,205));
        
        gaugePath.arc(0,0,gaugeSize,gaugeSize,180-middleAngle/2,180-middleAngle/2+1);
        gaugePath.setCircleResolution(200);
        gaugePath.setFillColor(ofColor(100,255,205,150));
        font.loadFont("Autobus-Bold.ttf", s*0.15);
        valuefont.loadFont("Autobus-Bold.ttf", s*0.1);
}

void futureGauge::draw() {
//        ofSetLineWidth(s*0.008);
        //    ofNoFill();
        ofSetColor(100, 255, 205);
        
        ofFill();
        
        arcPath.draw(x,y);
        ofSetColor(0);
        ofEllipse(x,y,s*0.9,s*0.9);
        ofSetColor(100, 255, 205);
        int i=0;
        for(float a=ofDegToRad(180-middleAngle/2);a<=ofDegToRad(360+middleAngle/2);a+=ofDegToRad(4)) {
            if(i%5==0) ofSetLineWidth(s*0.01);
            else ofSetLineWidth(s*0.002);
            ofLine(x,y,x+s*0.5*cos(a),y+s*0.5*sin(a));
               i++;
        }
        ofSetColor(0);
        ofEllipse(x,y,s*0.85,s*0.85);
        gaugePath.draw(x,y);
        ofSetColor(0);
        ofEllipse(x,y,s*0.7,s*0.7);
        
        ofRectangle strRect = font.getStringBoundingBox(str, x, y);
        ofFill();
        ofSetColor(100, 255, 205);
        font.drawString(str, x-strRect.getWidth()/2, y+strRect.getHeight()/4+s*0.4);
        
        string str2 = ofToString(value);
        ofRectangle str2Rect = valuefont.getStringBoundingBox(str2, x, y);
        valuefont.drawString(str2, x-str2Rect.getWidth()/2, y+str2Rect.getHeight()/4);
}
    
void futureGauge::setGaugeValue(float val) {
    if(val>1)
        gauge = 1;
    else
        gauge = val;    // gauge value = 0~1;
    value = gauge*maxVal;
        
    gaugeAngle = 180-middleAngle/2 + (gauge+0.01)*(360-middleAngle);
    gaugePath.clear();
    gaugePath.arc(0,0,gaugeSize,gaugeSize,180-middleAngle/2, gaugeAngle);

}

void futureGauge::setValue(float _value) {
    if(_value>maxVal)
        value = maxVal;
    else if(_value<minVal) {
        value = minVal;
    }
    else
        value = (int)(_value*100.0)*0.01f;
        
    gaugeAngle = 180-middleAngle/2 + (value/maxVal+0.0001)*(360-middleAngle);
    gaugePath.clear();
    gaugePath.arc(0,0,gaugeSize,gaugeSize,180-middleAngle/2, gaugeAngle);
        
}


