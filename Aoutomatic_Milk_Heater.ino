
#include <LiquidCrystal.h>
const int rs = 10, en = 11, d4 = 8, d5 = 9, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 9}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 12
int relay=1; 
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

 float Celcius=0;
 int compare;


void setup() {
  Serial.begin(9600);
  
 void Milking();
 
  {
     sensors.requestTemperatures(); 
 Celcius=sensors.getTempCByIndex(0);
  lcd.println(" temp in celcius  ");
  lcd.print(Celcius);
 compare=(Serial.available());
if( compare >27)
  digitalWrite(relay,LOW);
if( compare >22)
  digitalWrite(relay,HIGH);
  delay(2000);
  }
  
void  Heating();

  {
     sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  lcd.println(" temp in celcius ");
  lcd.print(Celcius);
  compare=(Serial.available());
if( compare >27)
  digitalWrite(relay,LOW);
if( compare >22)
  digitalWrite(relay,HIGH);
  delay(2000);
    
  }
}

void loop()
{
  //lcd.begin(16, 2);  
  //lcd.print("Milking-1");
// lcd.setCursor(0, 1); 
 // lcd.print("Heating-2");
 // delay(2000);
  // lcd.clear();
  // delay(1000);
  char customKey = customKeypad.getKey();
  if (customKey)
  Serial.println(customKey);
  
    if (customKey==1)
    digitalWrite(relay,HIGH);
    //delay(1000);
    
   
   
}


