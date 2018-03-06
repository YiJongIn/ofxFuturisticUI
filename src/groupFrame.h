#pragma once
#include "ofMain.h"

class groupFrame{
public:
    float x, y, w, h, marginWidth, marginHeight;
    string str;
    ofTrueTypeFont font;
    list<ofRectangle> UIelements;
    ofPoint leftCorner, rightCorner;
    
    groupFrame();
    groupFrame(float _x, float _y, float _w, float _h, string _str);
    
    void draw() ;
    
    void setFrame(float _x, float _y, float _w, float _h);
    
    void setMargin(float _marginWidth, float _marginHeight);
    
    void addUIelement(ofRectangle UIref);
    
    
};