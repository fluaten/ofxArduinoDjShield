/*
 * This is a simple example use of ofxArduinoDjShield based on ofArduino
 *
 * ofArduino currently only supports the standard Arduino boards
 * (UNO, Duemilanove, Diecimila, NG, and other boards based on the
 * ATMega168 or ATMega328 microcontrollers
 * The Arduio FIO and Arduino Mini should also work.
 * The Arduino MEGA and other variants based on microcontrollers
 * other than the ATMega168 and ATMega328 are not currently supported.
 *
 * To use this example, open Arduino (preferably Arduino 1.0) and
 * navigate to File -> Examples -> Firmata and open StandardFirmata.
 * Compile and upload StandardFirmata for your board, then close
 * the Arduino application and run this application.

 */

#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

    vector <ofSerialDeviceInfo> devices = (ofSerial()).getDeviceList();

	for(auto & device : devices){
		if(device.getDeviceID() == 0){
			deviceInit = device.getDeviceName();
		}
	}

	// Here the list of 4 USB Port of the computer, change them in case..
    
    // replace the string below with the serial port for your Arduino board
    // you can get this from the Arduino application or via command line
    // for OSX, in your terminal type "ls /dev/tty.*" to get a list of serial devices

	string ArduinoPort01 = "tty.usbmodem1411";
	string ArduinoPort02 = "tty.usbmodem1d11421";
	string ArduinoPort03 = "tty.usbmodem1421";
	string ArduinoPort04 = "tty.usbmodem1431";

	if((deviceInit == ArduinoPort01) || (deviceInit == ArduinoPort02)  || (deviceInit == ArduinoPort03)  || (deviceInit == ArduinoPort04)){
		ArduinoUSB = true;
	}
	else{
		ArduinoUSB = false;
	}

	if(ArduinoUSB){
		DjShield.setup("/dev/" + deviceInit);
	}

	ofBackground(0, 0, 0);

	font.loadFont("franklinGothic.otf", 20);
}

//--------------------------------------------------------------
void ofApp::update(){

	if(ArduinoUSB){

		DjShield.udpate();

		if(DjShield.bSetupArduino){
			PotA0 = DjShield.PotA0();
			PotA1 = DjShield.PotA1(TRUE, 0.0, 255.00);
			PotA2 = DjShield.PotA2(TRUE, 3.0, 10.0);

			ButtonD2 = DjShield.ButtonD2(1);
			ButtonD3 = DjShield.ButtonD3();
			ButtonD4 = DjShield.ButtonD4();
			ButtonD5 = DjShield.ButtonD5(2);
			ButtonD6 = DjShield.ButtonD6();

			if((ButtonD5) || (ButtonD6)){
				DjShield.LedA4(true);
				DjShield.LedA5(true);
				DjShield.LedA4(false);
			}
			else{
				DjShield.LedA4(false);
				DjShield.LedA5(false);
			}
		}

	}

	ofBackground(PotA1, PotA1, PotA1);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);

	if(ArduinoUSB){

		if(!DjShield.bSetupArduino){
			font.drawString("arduino not ready...\n", 10, 30);
		}
		else{
			string msg;

			msg += "PotA0 " + ofToString(PotA0) + "\n";
			msg += "PotA1 " + ofToString(PotA1) + "\n";
			msg += "PotA2 " + ofToString(PotA2) + "\n";
			msg += "ButtonD2 " + ofToString(ButtonD2) + "\n";
			msg += "ButtonD3 " + ofToString(ButtonD3) + "\n";
			msg += "ButtonD4 " + ofToString(ButtonD4) + "\n";
			msg += "ButtonD5 " + ofToString(ButtonD5) + "\n";
			msg += "ButtonD6 " + ofToString(ButtonD6) + "\n";

			font.drawString(msg, 10, 30);

			ofSetColor(255, 255, 255);
		}

	}
	else{

		font.drawString("No arduino connected...\n", 10, 30);

	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
	 case OF_KEY_RIGHT:
		 break;

	 case OF_KEY_LEFT:
		 break;

	 default:
		 break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
}
