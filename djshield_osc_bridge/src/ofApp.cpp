#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    
    ofBackground(100,100,100);
    
    LoadConfig();
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    DjShield.setup(ArduinoDevice);
    
    font.loadFont("franklinGothic.otf", 20);
    
    sender.setup(Host, Port);
    
    Oscreceive.setup(87878);

}

//--------------------------------------------------------------
void ofApp::update() {
    
    DjShield.udpate();
    
    if (DjShield.bSetupArduino) {
        
        
        PotA0 = DjShield.PotA0();
        PotA1 = DjShield.PotA1();
        PotA2 = DjShield.PotA2();
        
        ButtonD2 = DjShield.ButtonD2();
        ButtonD3 = DjShield.ButtonD3();
        ButtonD4 = DjShield.ButtonD4();
        ButtonD5 = DjShield.ButtonD5();
        ButtonD6 = DjShield.ButtonD6();
        
        
        
        ofxOscMessage m;
        m.setAddress(OscIdPotA0);
        m.addFloatArg(DjShield.PotA0());
        sender.sendMessage(m);
        
        ofxOscMessage m2;
        m2.setAddress(OscIdPotA1);
        m2.addFloatArg(DjShield.PotA1());
        sender.sendMessage(m2);
        
        ofxOscMessage m3;
        m3.setAddress(OscIdPotA2);
        m3.addFloatArg(DjShield.PotA2());
        sender.sendMessage(m3);
        
        
        
        ofxOscMessage b2;
        b2.setAddress(OscIdButtonD2);
        b2.addIntArg((int)DjShield.ButtonD2());
        sender.sendMessage(b2);

        ofxOscMessage b3;
        b3.setAddress(OscIdButtonD3);
        b3.addIntArg((int)DjShield.ButtonD3());
        sender.sendMessage(b3);
        
        ofxOscMessage b4;
        b4.setAddress(OscIdButtonD4);
        b4.addIntArg((int)DjShield.ButtonD4());
        sender.sendMessage(b4);
        
        ofxOscMessage b5;
        b5.setAddress(OscIdButtonD5);
        b5.addIntArg((int)DjShield.ButtonD5());
        sender.sendMessage(b5);
        
        ofxOscMessage b6;
        b6.setAddress(OscIdButtonD6);
        b6.addIntArg((int)DjShield.ButtonD6());
        sender.sendMessage(b6);
        
       /*
        if (ButtonD5) {
            DjShield.LedA4(true);
            DjShield.LedA5(true);
            DjShield.LedA4(false);
        }
        else {
            DjShield.LedA4(false);
            DjShield.LedA5(false);
        }
        */
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(255, 255, 255);
    if (!DjShield.bSetupArduino) {
        font.drawString("arduino not ready...\n", 10, 30);
    }
    else {
        string msg;
        
        msg += "/PotA0 " + ofToString(PotA0) + "\n";
        msg += "/PotA1 " + ofToString(PotA1) + "\n";
        msg += "/PotA2 " + ofToString(PotA2) + "\n";
        msg += "/ButtonD2 " + ofToString(ButtonD2) + "\n";
        msg += "/ButtonD3 " + ofToString(ButtonD3) + "\n";
        msg += "/ButtonD4 " + ofToString(ButtonD4) + "\n";
        msg += "/ButtonD5 " + ofToString(ButtonD5) + "\n";
        msg += "/ButtonD6 " + ofToString(ButtonD6) + "\n";
        msg += "IP Sender " + ofToString(Host) + "\n";
        msg += "Port Sender " + ofToString(Port) + "\n";
        
        font.drawString(msg, 10, 30);
        
        ofSetColor(255, 255, 255);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    switch (key) {
        case OF_KEY_RIGHT:
            break;
            
        case OF_KEY_LEFT:
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}

void ofApp::LoadConfig(){
    if(conf.load("settings.txt")){
        ofLogNotice("Config. Loaded");
    }
    else{
        ofLogNotice("Config. Error");
    }
    
    ArduinoDevice = conf.get("OSCDevice.ArduinoDevice", (string)"/dev/tty.usbmodem1411");
    
    Host = conf.get("OSCSender.Host", (string)"127.0.0.1");
    Port = conf.get("OSCSender.Port", 12345);
    
    OscIdPotA0 = conf.get("OSCPathPot.PotA0", (string)"/PotA0");
    OscIdPotA1 = conf.get("OSCPathPot.PotA1", (string)"/PotA1");
    OscIdPotA2 = conf.get("OSCPathPot.PotA2", (string)"/PotA2");
    
    OscIdButtonD2 = conf.get("OSCPathButton.ButtonD2", (string)"/ButtonD2");
    OscIdButtonD3 = conf.get("OSCPathButton.ButtonD3", (string)"/ButtonD3");
    OscIdButtonD4 = conf.get("OSCPathButton.ButtonD4", (string)"/ButtonD4");
    OscIdButtonD5 = conf.get("OSCPathButton.ButtonD5", (string)"/ButtonD5");
    OscIdButtonD6 = conf.get("OSCPathButton.ButtonD6", (string)"/ButtonD6");
    
    conf.clear();
}
