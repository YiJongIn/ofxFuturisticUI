#pragma once
#include "ofMain.h"

class futureGauge
{
public:
float x, y, s, middleAngle, gauge, gaugeSize, gaugeAngle, minVal, maxVal, value;

    string str;
    ofPath arcPath, gaugePath;
    ofTrueTypeFont valuefont, font;
    
    futureGauge();
    futureGauge(float _x, float _y, float _s, string _str);
    
    void draw();
    
    void setGaugeValue(float val);
    void setValue(float _value);

};

