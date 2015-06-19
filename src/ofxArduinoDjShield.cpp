//
// ofxArduinoDjShield.cpp
// ofxArduinoDjShield
// https://github.com/fluaten/ofxArduinoDjShield
// Created by Nicolas Boillot on 15-01-02.
// Copyright 2015 fluate.net All rights reserved.
// Addon to use easily the DJ Shield for Arduino by Nootropic Design
// https://nootropicdesign.com/djshield/
// Arduino source from examples/communication/firmataExample


#include "ofxArduinoDjShield.h"


//--------------------------------------------------------------
void ofxArduinoDjShield::setup(string ArduinoPort){
	ArduinoUno.connect(ArduinoPort);
	ofAddListener(ArduinoUno.EInitialized, this, &ofxArduinoDjShield::setupArduino);
	bSetupArduino = false;
}

void ofxArduinoDjShield::udpate(){
	ArduinoUno.update();
}

void ofxArduinoDjShield::setupArduino(const int & version){
	ofRemoveListener(ArduinoUno.EInitialized, this, &ofxArduinoDjShield::setupArduino);

	bSetupArduino = true;

	// print firmware name and version to the console
	ofLogNotice() << ArduinoUno.getFirmwareName();
	ofLogNotice() << "firmata v" << ArduinoUno.getMajorFirmwareVersion() << "." << ArduinoUno.getMinorFirmwareVersion();

	for(int i = 0; i < 3; i++){
		ArduinoUno.sendAnalogPinReporting(i, ARD_ANALOG);
	}

	ArduinoUno.sendDigitalPinMode(18, ARD_OUTPUT);
	ArduinoUno.sendDigitalPinMode(19, ARD_OUTPUT);

	for(int i = 2; i < 7; i++){
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
void ofxArduinoDjShield::digitalPinChanged(const int & pinNum){
	// do something with the digital input. here we're simply going to print the pin number and
	// value to the screen each time it changes
	//buttonState = "digital pin: " + ofToString(pinNum) + " = " + ofToString(ArduinoUno.getDigital(pinNum));
}

// analog pin event handler, called whenever an analog pin value has changed

//--------------------------------------------------------------
void ofxArduinoDjShield::analogPinChanged(const int & pinNum){
	// do something with the analog input. here we're simply going to print the pin number and
	// value to the screen each time it changes
	//potValue = "analog pin: " + ofToString(pinNum) + " = " + ofToString(ArduinoUno.getAnalog(pinNum));
}

// ofxArduinoDjShield ---------------------------


float ofxArduinoDjShield::PotA0(bool rescale, int min, int max){

	float AnalogPotentiometer = ArduinoUno.getAnalog(0) / 1023.00f;

	if(rescale){
		AnalogPotentiometer = AnalogPotentiometer * max;

		if(AnalogPotentiometer < min){
			AnalogPotentiometer = min;
		}

	}
	return AnalogPotentiometer;
}

float ofxArduinoDjShield::PotA1(bool rescale, int min, int max){
	float AnalogPotentiometer = ArduinoUno.getAnalog(1) / 1023.00f;

	if(rescale){
		AnalogPotentiometer = AnalogPotentiometer * max;

		if(AnalogPotentiometer < min){
			AnalogPotentiometer = min;
		}

	}
	return AnalogPotentiometer;
}

float ofxArduinoDjShield::PotA2(bool rescale, int min, int max){
	float AnalogPotentiometer = ArduinoUno.getAnalog(2) / 1023.00f;

	if(rescale){
		AnalogPotentiometer = AnalogPotentiometer * max;

		if(AnalogPotentiometer < min){
			AnalogPotentiometer = min;
		}

	}

	return AnalogPotentiometer;
}

bool ofxArduinoDjShield::ButtonD2(float DelayTime){
	bool DigitalButton = ArduinoUno.getDigital(2);
	if(DelayTime != 0){
		if((((startTime2 + (DelayTime * 1000)) < actualTime2))
		   && (DigitalButton == false)){
			startTime2 = actualTime2;
			return !DigitalButton;
		}
		else{
			actualTime2 = ofGetElapsedTimeMillis();
			return false;
		}
	}
	else{
		return !DigitalButton;
	}
}

bool ofxArduinoDjShield::ButtonD3(float DelayTime){
	bool DigitalButton = ArduinoUno.getDigital(3);
    if(DelayTime != 0){
        if((((startTime3 + (DelayTime * 1000)) < actualTime3))
           && (DigitalButton == false)){
            startTime3 = actualTime3;
            return !DigitalButton;
        }
        else{
            actualTime3 = ofGetElapsedTimeMillis();
            return false;
        }
    }
    else{
        return !DigitalButton;
    }
}


bool ofxArduinoDjShield::ButtonD4(float DelayTime){
	bool DigitalButton = ArduinoUno.getDigital(4);
    if(DelayTime != 0){
        if((((startTime4 + (DelayTime * 1000)) < actualTime4))
           && (DigitalButton == false)){
            startTime4 = actualTime4;
            return !DigitalButton;
        }
        else{
            actualTime4 = ofGetElapsedTimeMillis();
            return false;
        }
    }
    else{
        return !DigitalButton;
    }
}


bool ofxArduinoDjShield::ButtonD5(float DelayTime){
	bool DigitalButton = ArduinoUno.getDigital(5);
    if(DelayTime != 0){
        if((((startTime5 + (DelayTime * 1000)) < actualTime5))
           && (DigitalButton == false)){
            startTime5 = actualTime5;
            return !DigitalButton;
        }
        else{
            actualTime5 = ofGetElapsedTimeMillis();
            return false;
        }
    }
    else{
        return !DigitalButton;
    }
}


bool ofxArduinoDjShield::ButtonD6(float DelayTime){
	bool DigitalButton = ArduinoUno.getDigital(6);
    if(DelayTime != 0){
        if((((startTime6 + (DelayTime * 1000)) < actualTime6))
           && (DigitalButton == false)){
            startTime6 = actualTime6;
            return !DigitalButton;
        }
        else{
            actualTime6 = ofGetElapsedTimeMillis();
            return false;
        }
    }
    else{
        return !DigitalButton;
    }
}


void ofxArduinoDjShield::LedA4(bool Active){
	if(Active){
		ArduinoUno.sendDigital(18, ARD_HIGH);
	}
	else{
		ArduinoUno.sendDigital(18, ARD_LOW);
	}
}

void ofxArduinoDjShield::LedA5(bool Active){
	if(Active){
		ArduinoUno.sendDigital(19, ARD_HIGH);
	}
	else{
		ArduinoUno.sendDigital(19, ARD_LOW);
	}
}
