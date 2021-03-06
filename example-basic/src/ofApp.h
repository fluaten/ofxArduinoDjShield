#pragma once

#include "ofMain.h"
#include "ofxArduinoDjShield.h"


class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxArduinoDjShield DjShield;
    ofTrueTypeFont		font;
    
    float PotA0, PotA1, PotA2;
    
    bool ArduinoUSB;
    string deviceInit;

    bool ButtonD2, ButtonD3, ButtonD4, ButtonD5, ButtonD6;
    
    
private:
    
};

