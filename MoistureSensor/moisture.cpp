#include "moisture.h"
#include "Arduino.h"

int moisturePin,
moisturePowerPin,
soil;



moisture::moisture() 
{

}

	moisture::moisture(int  mPin) 
	{
		moisturePin = mPin;
	}

	moisture::moisture(int mPin, int mPowerPin) 
	{
		moisturePin = mPin;
		moisturePowerPin = mPowerPin;
		pinMode(moisturePowerPin, OUTPUT);
	}

	int moisture::moistureTest()
	{
		checkMoisture();
		soil = percent(soil);
		return soil;
	}

	int moisture::getMoisture()
	{
	return soil;
	}

	int moisture::percent(int value)
	{
			//change analog reading to percentage number
			value = map(value, 0, 1025, 0, 100);
			value = map(value, 0, 100, 100, 0);
			return value;
	}

	int moisture::checkMoisture()
	{
		digitalWrite(moisturePowerPin, HIGH);
		// digitalWrite(led, HIGH); not included at this time
		delay(500);
		soil = analogRead(moisturePin);
		delay(50);
		digitalWrite(moisturePowerPin, LOW);
		// digitalWrite(led, LOW);
		return soil;
	}