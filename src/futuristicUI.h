//
//  futuristicUI.h
//  emptyExample
//
//  Created by LEEJONGIN on 2018. 2. 26..
//
//

#include "ofMain.h"

#ifndef futuristicUI_h
#define futuristicUI_h


#endif /* futuristicUI_h */


class futureGauge {
public:
    float x, y, s, middleAngle, gauge, gaugeSize, gaugeAngle, minVal, maxVal, value;

    string str;
    ofPath arcPath, gaugePath;
    ofTrueTypeFont valuefont, font;
    
    futureGauge();
    futureGauge(float _x, float _y, float _s, string _str) {
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
        arcPath.setCircleResolution(100);
        arcPath.setFillColor(ofColor(100,255,205));
        
        gaugePath.arc(0,0,gaugeSize,gaugeSize,180-middleAngle/2,180-middleAngle/2+1);
        gaugePath.setCircleResolution(100);
        gaugePath.setFillColor(ofColor(100,255,205,150));
        font.loadFont("Autobus-Bold.ttf", s*0.15);
        valuefont.loadFont("Autobus-Bold.ttf", s*0.1);
    }
    
    void draw() {
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
            else ofSetLineWidth(s*0.005);
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
    
    void setGaugeValue(float val) {
        if(val>1)
            gauge = 1;
        else
            gauge = val;    // gauge value = 0~1;
        value = gauge*maxVal;
        
        gaugeAngle = 180-middleAngle/2 + (gauge+0.01)*(360-middleAngle);
        gaugePath.clear();
        gaugePath.arc(0,0,gaugeSize,gaugeSize,180-middleAngle/2, gaugeAngle);

    }
    void setValue(float _value) {
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

    
    
};

class futureGrid{
public:
    float x, y, w, h;
    string str;
    ofTrueTypeFont font;
    futureGrid();
    futureGrid(float _x, float _y, float _w, float _h, string _str){
        x=_x;
        y=_y;
        w=_w;
        h=_h;
        str = _str;
        font.loadFont("Autobus-Bold.ttf",14);
        
    }
    void draw() {
        ofNoFill();
        ofSetLineWidth(1);
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
                ofDrawBitmapString(ofToString(i*15),x+w/5.0*i-5,y+h+20);
            else
                ofDrawBitmapString(ofToString(i*15),x+w/5.0*i-10,y+h+20);
            
        }
    
    }

};

class groupFrame{
public:
    float x, y, w, h, marginWidth, marginHeight;
    string str;
    ofTrueTypeFont font;
    list<ofRectangle> UIelements;
    ofPoint leftCorner, rightCorner;
    
    groupFrame();
    groupFrame(float _x, float _y, float _w, float _h, string _str) {
        x=_x;
        y=_y;
        w=_w;
        h=_h;
        marginWidth =0;
        marginHeight =0;
        str = _str;
        font.loadFont("Autobus-Bold.ttf",14);
        leftCorner = ofPoint(ofGetWidth(),ofGetHeight());
        rightCorner = ofPoint(0,0);
    }
    
    void draw() {
        ofNoFill();
        ofSetLineWidth(1);
        ofSetColor(100, 255, 205);
        
        if(UIelements.size()>0) {
            for(ofRectangle rec:UIelements){
                if(leftCorner.x > rec.x)
                    leftCorner.x = rec.x;
                
                if(leftCorner.y > rec.y)
                    leftCorner.y = rec.y;
                
            }
            for(ofRectangle rec:UIelements){
                if(rightCorner.x < rec.x+rec.width)
                    rightCorner.x = rec.x+rec.width;
                
                if(rightCorner.y < rec.y+rec.height)
                    rightCorner.y = rec.y+rec.height;
            }
            
            x = leftCorner.x;
            y = leftCorner.y;
            w = rightCorner.x - leftCorner.x;
            h = rightCorner.y - leftCorner.y;
        }

        ofRect(x-marginWidth,y-marginHeight,w+marginWidth*2,h+marginHeight*2);
        font.drawString(str,x-marginWidth,y-font.getSize()*0.4-marginHeight);
    }
    
    void setFrame(float _x, float _y, float _w, float _h) {
        x=_x;
        y=_y;
        w=_w;
        h=_h;
    }
    
    void setMargin(float _marginWidth, float _marginHeight) {
        marginWidth=_marginWidth;
        marginHeight=_marginHeight;
    }
    
    void addUIelement(ofRectangle UIref){
        UIelements.push_back(UIref);
    }
    
    
};
