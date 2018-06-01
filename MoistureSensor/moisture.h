#ifndef MOISTURE_H
#define MOISTURE_H




class moisture
{
public:
	moisture();
	moisture(int mPin);
	moisture(int mPin, int mPowerPin);
	int moistureTest();
	int percent(int value);
	int getMoisture();


private:
	int moisturePin,
		moisturePowerPin;
	

	int checkMoisture();
};

#endif
