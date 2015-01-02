//
// ofxArduinoDjShield.h
// ofxArduinoDjShield
//
// Created by Nicolas Boillot on 15-01-01.
// Copyright 2015 fluate.net All rights reserved.
// Arduino source from examples/communication/firmataExample



#pragma once

#include "ofMain.h"
#include "ofEvents.h"

//========================================================================

class ofxArduinoDjShield
{
public:
	ofArduino ArduinoUno;

	void setup(string ArduinoPort = "/dev/tty.usbmodem1421");
	void udpate();

	bool bSetupArduino;

	int PotA0(bool rescale = false, int min = 0, int max = 100);
	int PotA1(bool rescale = false, int min = 0, int max = 100);
	int PotA2(bool rescale = false, int min = 0, int max = 100);

	bool ButtonD2();
	bool ButtonD3();
	bool ButtonD4();
	bool ButtonD5();
	bool ButtonD6();

	void LedA4(bool Active);
	void LedA5(bool Active);

	void digitalPinChanged(const int & pinNum);
	void analogPinChanged(const int & pinNum);

private:
	void setupArduino(const int & version);

	string buttonState;
	string potValue;
};
