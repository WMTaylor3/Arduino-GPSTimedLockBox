/*
 Name:		Arduino_MomentMaker.ino
 Created:	6/8/2019 2:17:32 PM
 Author:	William Taylor
*/

#include "Display.h"
#define screenI2C 0x38
//#define screenI2C 0x27

Display::Display()
{
	lcd = new LiquidCrystal_I2C(screenI2C, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
}

void Display::Initialize()
{
	lcd->begin(16, 2);
}

void Display::LcdOn()
{
	lcd->on();
}

void Display::LcdOff()
{
	lcd->off();
}

void Display::Write(String lineOne, String lineTwo = "")
{
	Clear();
	lcd->setCursor(0, 0);
	lcd->print(lineOne);
	if (lineTwo != "")
	{
		lcd->setCursor(0, 1);
		lcd->print(lineTwo);
	}
}

void Display::WriteLocationRevealedIn(uint32_t days, uint32_t hours, uint32_t minutes)
{
	Write("Location will be", "revealed in...");
	delay(3000);
	if (days + hours + minutes <= 0)
	{
		Write("Less than", "a minute");
	}
	String dayString = String(days);
	String hourString = String(hours);
	String minuteString = String(minutes);
	Write(dayString + " Days " + hourString + " Hours", minuteString + " Minutes");
	delay(3000);
	Clear();
}

void Display::WriteObtainingGPSLocationFix()
{
	Write("Obtaining GPS", "location fix...");
}

void Display::WriteDistanceRemaining(uint32_t distance)
{
	Write("Distance to", "location...");
	delay(3000);
	String distanceString = String(distance);
	Write(distanceString + " Meters");
	delay(3000);
}

void Display::WriteLocationReached()
{
	Write("Location has", "been found");
	delay(3000);
}

void Display::WriteTimeToUnlock(uint32_t days, uint32_t hours, uint32_t minutes)
{
	Write("Unlock window", "will start in...");
	delay(3000);
	if (days + hours + minutes <= 0)
	{
		Write("Less than", "a minute");
	}
	String dayString = String(days);
	String hourString = String(hours);
	String minuteString = String(minutes);
	Write(dayString + " Days " + hourString + " Hours", minuteString + " Minutes");
	delay(3000);
	Clear();
}

void Display::WriteUnlockTimeRemaining(uint32_t days, uint32_t hours, uint32_t minutes)
{
	Write("Unlock window", "will last for...");
	delay(3000);
	if (days + hours + minutes <= 0)
	{
		Write("Less than", "a minute");
	}
	String dayString = String(days);
	String hourString = String(hours);
	String minuteString = String(minutes);
	Write(dayString + " Days " + hourString + " Hours", minuteString + " Minutes");
	delay(3000);
	Clear();
}

void Display::WriteEnterPasscode()
{
	Write("Passcode:");
}

void Display::CharTyped(uint8_t dotCount)
{
	lcd->setCursor(dotCount, 1);
	lcd->print("*");
}

void Display::WriteInsertBothKeys()
{
	Write("Insert second", "key to unlock");
	delay(3000);
}

void Display::WriteAccessGranted()
{
	Write("Access Granted", "Welcome William");
	delay(3000);
}

void Display::WriteAccessDenied()
{
	Write("Access Denied");
	delay(3000);
}

void Display::WriteTooLate()
{
	Write("Too Late", "Window Missed");
	delay(3000);
}

void Display::WriteGoodbye()
{
	Write("Goodbye");
	delay(3000);
}

void Display::Clear()
{
	lcd->setCursor(0, 0);
	lcd->print("                ");
	lcd->setCursor(0, 1);
	lcd->print("                ");
}