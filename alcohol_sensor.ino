const int AOUTpin=0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
#define DOUTpin 8//the DOUT pin of the alcohol sensor goes into digital pin D8 of the arduino
#define ledPin 13//the anode of the LED connects to digital pin D13 of the arduino

int limit;
int value;

void setup() {
Serial.begin(115200);//sets the baud rate
pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
pinMode(ledPin, OUTPUT);//sets the pin as an output of the arduino
}

void loop()
{
  float adcValue=0;
  for(int i=0;i<10;i++)
  {
    adcValue+= analogRead(AOUTpin);
    delay(10);
  }
    float v= (adcValue/10) * (5.0/1024.0);
    float mgL= 0.67 * v;
    Serial.print("BAC:");
    Serial.print(mgL);
    Serial.print(" mg/L");
value= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pin
limit= digitalRead(DOUTpin);//reads the digital value from the alcohol sensor's DOUT pin
Serial.print("Alcohol value: ");
Serial.println(value);//prints the alcohol value
Serial.print("Limit: ");
Serial.print(limit);//prints the limit reached as either LOW or HIGH (above or underneath)
Serial.print('\n');
delay(100);
if (limit == HIGH){

digitalWrite(ledPin, LOW);//if limit has been reached, LED turns on as status indicator

}
else{
 
digitalWrite(ledPin, HIGH);//if threshold not reached, LED remains off

}}
/*#include "LiquidCrystal.h"

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 8, 9, 10, 11);
void setup()

{

// set up the LCD's number of columns and rows:

lcd.begin(16, 2); // Print a message to the LCD.

lcd.print("TechPonder"); }

void loop()

{ // set the cursor to column 0, line 1 // (note: line 1 is the second row, since counting begins with 0): lcd.setCursor(0, 0);

lcd.print(" TechPonder ");

lcd.setCursor(0,1);

lcd.print(" Arduino LCD ");

}*/
