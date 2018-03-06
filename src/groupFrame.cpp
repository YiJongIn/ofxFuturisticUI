#include "groupFrame.h"

groupFrame::groupFrame(){
};
   
groupFrame::groupFrame(float _x, float _y, float _w, float _h, string _str) {
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
    
void groupFrame::draw() {
    ofNoFill();
    ofSetLineWidth(0.5);
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
    
void groupFrame::setFrame(float _x, float _y, float _w, float _h) {
    x=_x;
    y=_y;
    w=_w;
    h=_h;
}
    
void groupFrame::setMargin(float _marginWidth, float _marginHeight) {
    marginWidth=_marginWidth;
    marginHeight=_marginHeight;
}
    
void groupFrame::addUIelement(ofRectangle UIref){
    UIelements.push_back(UIref);
}