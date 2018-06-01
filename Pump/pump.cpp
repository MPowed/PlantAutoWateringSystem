#include "pump.h"
#include "Arduino.h"






pump::pump() {
}

void pump::pumpBegin(int pumpP) {
	this->_pumpPin = pumpP;
	pinMode(_pumpPin, OUTPUT);
}

void pump::setPumpCycle(int cycle) {
	this->_pumpCycle = cycle;
}

void pump::setPumpTimerWatered(long pTimerW) {
	this->_pumpTimerWatered = pTimerW;
}

void pump::setPumpTimerDry(long pTimerD) {
	this->_pumpTimerDry = pTimerD;
}

void pump::setPumpDelayOn(long pDelayOn) {
	this->_pumpDelayOn = pDelayOn;
}

void pump::setPumpDelayOff(long pDelayOff) {
	this->_pumpDelayOff = pDelayOff;
}

void pump::setMoistureThreshold(int mThresh) {
	this->_moistureThreshold = mThresh;
}

void pump::setMoisture(int moisture) {
	this->_val = moisture;
}

void pump::setLedPin(int led) {
	this->_ledPin = led;
	pinMode(_ledPin, OUTPUT);
}

void pump::setPumpData(int cycle, int mThresh, int led) {
	this->_pumpCycle = cycle;
	this->_moistureThreshold = mThresh;
	this->_ledPin = led;
	pinMode(_ledPin, OUTPUT);
}

void pump::setPumpTimers(long pTimerW, long pTimerD, long pDelayOn, long pDelayOff) {
	this->_pumpTimerWatered = pTimerW;
	this->_pumpTimerDry = pTimerD;
	this->_pumpDelayOn = pDelayOn;
	this->_pumpDelayOff = pDelayOff;
}

void pump::setPumpSafetyShutOff(unsigned long shutOffValue) {
	this->_pumpSafetyShutOff = shutOffValue;
}

int pump::getMoistureThreshold() {
	return _moistureThreshold;
}

int pump::getMoistureValue() {
	return _val;
}

long pump::getPumpDelayOn() {
	return _pumpDelayOn;
}

long pump::getPumpDelayOff() {
	return _pumpDelayOff;
}

long pump::getPumpTimer() {
	return _pumpTimer;
}

long pump::getPumpTimerWatered() {
	return _pumpTimerWatered;
}

long pump::getPumpTimerDry() {
	return _pumpTimerDry;
}

unsigned long pump::getCurrentMillis() {
	return _currentMillis;
}

unsigned long pump::getPreviousMillis() {
	return _previousMillis;
}

unsigned long pump::getPumpSafetyShutOff() {
	return _pumpSafetyShutOff;
}

void pump::pumpFailSafe()
{
	unsigned long _cMils = millis();
	if (_cMils - _previousMillis >= _pumpSafetyShutOff)
	{
		digitalWrite(_pumpPin, LOW);
		digitalWrite(_ledPin, LOW);
	}
}

void pump::runPump() {
	runThePump();
}



	void pump::runThePump()
	{
unsigned long _currentMillis = millis();
  if (_currentMillis - _previousMillis >= _pumpTimer) {
    _previousMillis = _currentMillis;

    if (_val < _moistureThreshold) {
      _test = true;
    } else {
      _test = false;
    }

    if (_test) {
      if (_pumpSwitch == 0) {
        Serial.println("Turning pump On");
        Serial.println(_test);
        digitalWrite(_pumpPin, HIGH);
        digitalWrite(_ledPin, HIGH);
        _pumpSwitch = 1;
        _pumpTimer = _pumpDelayOn;
        _x++;
      }
      else if (_pumpSwitch == 1) {
        Serial.println("Turning pump Off");
        digitalWrite(_pumpPin, LOW);
        digitalWrite(_ledPin, LOW);
        _pumpSwitch = 0;
        _pumpTimer = _pumpDelayOff;
      }
    }
    else {
      _pumpTimer = _pumpTimerDry;
      Serial.println("Plant moisture is fine, Will check again in 6 hours");
    }
    if (_x == _pumpCycle) {
      _x = 0;
      _pumpTimer = _pumpTimerWatered;;
      digitalWrite(_pumpPin, LOW);
      digitalWrite(_ledPin, LOW);
    }
  }
	}
