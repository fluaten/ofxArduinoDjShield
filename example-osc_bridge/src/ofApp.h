#pragma once

#include "ofMain.h"
#include "ofxArduinoDjShield.h"
#include "ofxOsc.h"
#include "ofxIniSettings.h"




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
    void LoadConfig();

    
    ofxArduinoDjShield DjShield;
    ofTrueTypeFont		font;
    
    float PotA0, PotA1, PotA2;
    
    bool ButtonD2, ButtonD3, ButtonD4, ButtonD5, ButtonD6;
    
    string OscIdPotA0, OscIdPotA1, OscIdPotA2;
    
    string OscIdButtonD2, OscIdButtonD3, OscIdButtonD4, OscIdButtonD5, OscIdButtonD6;
    
    string Host, ArduinoDevice;
    int Port;
    
	ofxOscSender sender;
    ofxOscReceiver  Oscreceive;
    ofxIniSettings conf;
};
