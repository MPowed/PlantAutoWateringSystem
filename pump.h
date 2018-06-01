#ifndef PUMP_H
#define PUMP_H



class pump
{

public:
	pump();
	void pumpBegin(int pumpP);
	void setPumpCycle(int cycle);
	void setPumpTimerWatered(long pTimerW);
	void setPumpTimerDry(long pTimerDry);
	void setPumpDelayOn(long pDelayOn);
	void setPumpDelayOff(long pDelayOff);
	void setMoistureThreshold(int mThresh);
	void setMoisture(int moisture);
	void setLedPin(int led);
	void setPumpData(int cycle, int mThresh, int led);
	void setPumpTimers(long pTimerW, long pTimerD, long pDelayOn, long pDelayOff);
	void setPumpSafetyShutOff(unsigned long shutOffValue);
	int getMoistureThreshold();
	int getMoistureValue();
	long getPumpDelayOn();
	long getPumpDelayOff();
	long getPumpTimer();
	long getPumpTimerWatered();
	long getPumpTimerDry();
	unsigned long getCurrentMillis();
	unsigned long getPreviousMillis();
	unsigned long getPumpSafetyShutOff();
	void pumpFailSafe();
	void runPump();

private:
	bool _test = false;
	int _pumpPin,
		_ledPin,
		_pumpCycle,
		_pumpSwitch = 0,
		_moistureThreshold,
		_val,
		_x;
	long _pumpDelayOn,
		_pumpDelayOff,
		_pumpTimer = 0, //value takes on others, so pump will test immediately when plugged in
		_pumpTimerWatered,
		_pumpTimerDry;
	unsigned long _currentMillis,
		_previousMillis = 0,
		_pumpSafetyShutOff = 3600000;


	void runThePump();
};

#endif
