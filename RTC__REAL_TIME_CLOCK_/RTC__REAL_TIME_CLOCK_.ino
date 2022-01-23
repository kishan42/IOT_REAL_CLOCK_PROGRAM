
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>// Arduino Uno/2009:
// ----------------------
// DS3231:  SDA pin   -> Arduino Analog 4 or the dedicated SDA pin
//                   SCL pin   -> Arduino Analog 5 or the dedicated SCL pin
#include <DS3231.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(115200);
  rtc.begin();
  lcd.begin();
  lcd.backlight();

  // The following lines can be uncommented to set the date and time
//  rtc.setDOW(FRIDAY);     // Set Day-of-Week to SUNDAY
//  rtc.setTime(6, 5, 0);     // Set the time to 12:00:00 (24hr format)
//  rtc.setDate(21, 01, 2022);   // Set the date to January 1st, 2014
}
void loop()
{
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
   lcd.setCursor(0,0);
   lcd.print(rtc.getDOWStr());
 //  lcd.print(" ");
   lcd.print(rtc.getDateStr());
  // lcd.scrollDisplayLeft();
   lcd.setCursor(0,1);
   lcd.print((String)"time:" + rtc.getTimeStr());
   
  
  // Wait one second before repeating :)
  delay (1000);
}
