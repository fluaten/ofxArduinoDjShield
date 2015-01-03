//
// ofxArduinoDjShield.cpp
// ofxArduinoDjShield
//
// Created by Nicolas Boillot on 15-01-02.
// Copyright 2015 fluate.net All rights reserved.
// Addon to use easly the DJ Shield for Arduino by Nootropic Design
// https://nootropicdesign.com/djshield/
// Arduino source from examples/communication/firmataExample

/*
   DJ Shield for Arduino by Nootropic Design :

   5 tactile buttons, connected to digital pins 2-6
   3 10K linear potentiometers connected to analog pins 0,1,2. (shaft is 1/4")
   2 LEDs (one red, one blue) connected to analog pins 4 and 5 (analog pins can also be used as digital pins)
   3 ABS plastic or aluminium knobs for the potentiometers.

 */

//
// To use this addon, open Arduino (preferably Arduino 1.0) and
// navigate to File -> Examples -> Firmata and open StandardFirmata.
// Compile and upload StandardFirmata for your board, then close
// the Arduino application and run this application.


#include "ofxArduinoDjShield.h"


//--------------------------------------------------------------
void ofxArduinoDjShield::setup(string ArduinoPort) {
	ArduinoUno.connect(ArduinoPort);
	ofAddListener(ArduinoUno.EInitialized, this, &ofxArduinoDjShield::setupArduino);
	bSetupArduino   = false;
}

void ofxArduinoDjShield::udpate() {
	ArduinoUno.update();
}

void ofxArduinoDjShield::setupArduino(const int & version) {
	ofRemoveListener(ArduinoUno.EInitialized, this, &ofxArduinoDjShield::setupArduino);

	bSetupArduino = true;

	// print firmware name and version to the console
	ofLogNotice() << ArduinoUno.getFirmwareName();
	ofLogNotice() << "firmata v" << ArduinoUno.getMajorFirmwareVersion() << "." << ArduinoUno.getMinorFirmwareVersion();

	for (int i = 0; i < 3; i++) {
		ArduinoUno.sendAnalogPinReporting(i, ARD_ANALOG);
	}

	ArduinoUno.sendDigitalPinMode(18, ARD_OUTPUT);
	ArduinoUno.sendDigitalPinMode(19, ARD_OUTPUT);

	for (int i = 2; i < 7; i++) {
		ArduinoUno.sendDigitalPinMode(i, ARD_INPUT);
		ArduinoUno.sendDigital(i, ARD_HIGH);
	}


	// Listen for changes on the digital and analog pins
	ofAddListener(ArduinoUno.EDigitalPinChanged, this, &ofxArduinoDjShield::digitalPinChanged);
	ofAddListener(ArduinoUno.EAnalogPinChanged, this, &ofxArduinoDjShield::analogPinChanged);
}

// digital pin event handler, called whenever a digital pin value has changed
// note: if an analog pin has been set as a digital pin, it will be handled
// by the digitalPinChanged function rather than the analogPinChanged function.

//--------------------------------------------------------------
void ofxArduinoDjShield::digitalPinChanged(const int & pinNum) {
	// do something with the digital input. here we're simply going to print the pin number and
	// value to the screen each time it changes
	//buttonState = "digital pin: " + ofToString(pinNum) + " = " + ofToString(ArduinoUno.getDigital(pinNum));
}

// analog pin event handler, called whenever an analog pin value has changed

//--------------------------------------------------------------
void ofxArduinoDjShield::analogPinChanged(const int & pinNum) {
	// do something with the analog input. here we're simply going to print the pin number and
	// value to the screen each time it changes
	//potValue = "analog pin: " + ofToString(pinNum) + " = " + ofToString(ArduinoUno.getAnalog(pinNum));
}

// ofxArduinoDjShield ---------------------------


float ofxArduinoDjShield::PotA0(bool rescale, int min, int max) {
	float AnalogPotentiometer = ArduinoUno.getAnalog(0);

	if (rescale) {
		AnalogPotentiometer = ofMap(float (AnalogPotentiometer), 0.0f, 1023.0f, min, max);
	}
	return AnalogPotentiometer;
}

float ofxArduinoDjShield::PotA1(bool rescale, int min, int max) {
	float AnalogPotentiometer = ArduinoUno.getAnalog(1);

	if (rescale) {
		AnalogPotentiometer = ofMap(float (AnalogPotentiometer), 0.0f, 1023.0f, min, max);
	}
	return AnalogPotentiometer;
}

float ofxArduinoDjShield::PotA2(bool rescale, int min, int max) {
	float AnalogPotentiometer = ArduinoUno.getAnalog(2);

	if (rescale) {
		AnalogPotentiometer = ofMap(float (AnalogPotentiometer), 0.0f, 1023.0f, min, max);
	}
	return AnalogPotentiometer;
}

bool ofxArduinoDjShield::ButtonD2() {
	bool DigitalButton = ArduinoUno.getDigital(2);
	return !DigitalButton;
}

bool ofxArduinoDjShield::ButtonD3() {
	bool DigitalButton = ArduinoUno.getDigital(3);
	return !DigitalButton;
}

bool ofxArduinoDjShield::ButtonD4() {
	bool DigitalButton = ArduinoUno.getDigital(4);
	return !DigitalButton;
}

bool ofxArduinoDjShield::ButtonD5() {
	bool DigitalButton = ArduinoUno.getDigital(5);
	return !DigitalButton;
}

bool ofxArduinoDjShield::ButtonD6() {
	bool DigitalButton = ArduinoUno.getDigital(6);
	return !DigitalButton;
}

void ofxArduinoDjShield::LedA4(bool Active) {
	if (Active) {
		ArduinoUno.sendDigital(18, ARD_HIGH);
	}
	else {
		ArduinoUno.sendDigital(18, ARD_LOW);
	}
}

void ofxArduinoDjShield::LedA5(bool Active) {
	if (Active) {
		ArduinoUno.sendDigital(19, ARD_HIGH);
	}
	else {
		ArduinoUno.sendDigital(19, ARD_LOW);
	}
}