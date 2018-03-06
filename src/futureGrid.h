#pragma once
#include "ofMain.h"

class futureGrid
{
public:
	 float x, y, w, h,verticesShow;
	vector<float> vertices1, vertices2,vertices3,vertices4;
    string str;
    ofTrueTypeFont font;
    futureGrid();
    futureGrid(float _x, float _y, float _w, float _h, string _str);
    void draw();
	void addVertex(int,float);
	void setFontSize(float);
	~futureGrid(void);
};

