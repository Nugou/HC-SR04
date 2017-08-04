/**********************************************************************************************
 * Arduino HC-SR04 Library - Version 1.0
 * by Alessandro Vinicius <alessandro.vncs@gmail.com>
 *
 **********************************************************************************************/

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <ULTRAX.h>


ULTRAX::ULTRAX(int echo, int trigger){	
	pinEcho = echo;
	pinTrigger = trigger;
	lastCompute = 0;
	timeCompute = 10;
	minDistance = 0;
	maxDistance = 4000;
	ePowerMin = 0;
	ePowerMax = 255;
	
}

double ULTRAX::getDistance_MM(){
	if(lastCompute <= millis()){
		lastCompute += timeCompute;
		digitalWrite(pinTrigger, LOW);
		for(int i = 10; i > -1; i -= 10){
			digitalWrite(pinTrigger, !digitalRead(pinTrigger));
			delayMicroseconds(i);
		}
		
		duration = pulseIn(pinEcho,HIGH);
		distance = duration / 294.1176470588235 / 2.0;
		
		if(distance > minDistance && distance < maxDistance && eBip){
			tone(pinBip, 440);
			delay(duration / 15.0);
			noTone(pinBip);
			delay(50);
		}else if(minDistance < distance < maxDistance && eMotor){
			timeM = map(distance, 0, minDistance, ePowerMax, ePowerMin);
			analogWrite(pinMotor, timeM);
		}else if(minDistance < distance < maxDistance && eAlert){
			digitalWrite(pinAlert, HIGH);
		}else if(eMotor){
			timeM = ePowerMin;
			analogWrite(pinBip, timeM);
		}else if(eAlert){
			digitalWrite(pinAlert, LOW);
		}
	}
	return distance;
}

void ULTRAX::enableMotor(int _pinMotor){
	pinMotor = _pinMotor;
	eMotor = true;
	eBip = false;
	eAlert = false;
}

void ULTRAX::enableBip(int _pinBip){
	pinBip = _pinBip;
	eMotor = false;
	eBip = true;
	eAlert = false;
}

void ULTRAX::enableAlert(int _pinAlert){
	pinAlert = _pinAlert;
	eMotor = false;
	eBip = false;
	eAlert = true;
}

void ULTRAX::disableCOM(int com){
	if(MOTOR == com){
		eMotor = false;
	}else if(BIP == com){
		eBip = false;
	}else if(ALERT == com){
		eAlert = false;
	}
}

void ULTRAX::setMinDistance(double _minDistance){
	if(_minDistance > 0 && _minDistance < maxDistance){
		minDistance = _minDistance;
	}
}

void ULTRAX::setMaxDistance(double _maxDistance){
	if(_maxDistance < 4000 && _maxDistance > minDistance){
		maxDistance = _maxDistance;
	}
}

void ULTRAX::setMinPower(int minPower){
	if(minPower > 0 && minPower < ePowerMax){
		ePowerMin = minPower;
	}
}

void ULTRAX::setMaxPower(int maxPower){
	if(maxPower < 255 && maxPower > ePowerMin){
		ePowerMax = maxPower;
	}
}

double ULTRAX::getDistance_ME(){
	return getDistance_MM() / 1000.0;
}

double ULTRAX::getDistance_CM(){
	return getDistance_MM() / 10.0;
}

double ULTRAX::getDistance_IN(){
	return getDistance_MM() / 0.0393701;
}
