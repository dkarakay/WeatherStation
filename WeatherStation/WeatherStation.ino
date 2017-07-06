// Written by Deniz Karakay 06.07.2017
// WeatherStation

#include <Wire.h>
#include <rgb_lcd.h> //LCD library
#include "DHT.h"     //DHT Library

#define DHTTYPE DHT11 //DHT11
#define DHTPIN 2   

DHT dht(DHTPIN, DHTTYPE);
rgb_lcd lcd;

byte zeroFill[8] = { //LCD Brigtness Bar custom icons
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B00000
};
byte zero[8] = { //LCD Brigtness Bar custom icons
  B00000,
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
  B11111
};

int light,i=0,brightnessBar = 0;
float h,t;
float lTemp,fTemp,temp; //latestTemp, floatTemp, Temperature --> Grove Temperature v1.2
const int colorR = 255;
const int colorG = 140;
const int colorB = 0;

void setup(){
  Serial.begin(9600); //SerialCommunication starts
  
  lcd.begin(16,2); //LCD starts
  
  lcd.createChar(0,zero);
  lcd.createChar(1,zeroFill);
  
  lcd.setRGB(255,255,0);
  //lcd.print("Welcome!");
  delay(1000);
  lcd.clear();

  // 'Welcome' in different languages with different colors
  lcd.setRGB(255,0,0);
  lcd.print("Welcome!");
  delay(1000);
  lcd.clear();
  
  lcd.setRGB(0,0,255);
  lcd.print("Bienvenue!");
  delay(1000);
  lcd.clear();
  
  lcd.setRGB(255,0,0);
  lcd.print("Wilkommen!");
  delay(1000);
  lcd.clear();
  
  lcd.setRGB(255,255,0);
  lcd.print("Bienvenido!");
  delay(1000);
  lcd.clear();
  
  lcd.setRGB(0,255,0);
  lcd.print("Dobre doshli!");
  delay(1000);
  lcd.clear();
  
  lcd.setRGB(255,0,0);
  lcd.print("Hosgeldiniz!");
  delay(1000);
  lcd.clear();

  lcd.setRGB(0,255,0);
  lcd.print("Weather Station
  ,");
  lcd.setCursor(0,1);
  lcd.print("by Deniz Karakay");
  breath(REG_BLUE);
  delay(2000);
  
  lcd.clear();
}

void loop(){
  int temp35 = analogRead(A3); //LM35 Temperature Sensor
  float tempL35 = temp35 /  7.3; /* I have to make an operation like this because this sensor and also
  * Grove Temperature v1.2 gave me so much problem. These sensors normaly work fine (checked with 
  * Arduino UNO) When I switch to 5V the values change immediately. I use Arduino101 with Baseshield.
  * and I have to switch 5V because LCD works only in 5V. But normal codes on the internet work with 3.3V
  * I mean all datasheets say these two sensors can work with the range of 3V to 5V, but maybe LCD gets so
  * voltage or something causes problem for both these sensors thus I try and get data many many and many times,
  * to get snd organize the optimum for getting real value. I work with almost three thermometres. In the end
  * I figure out and now I'm getting optimum and true values.
  */
  h = dht.readHumidity(); //DHT11 read Humidity
  t = dht.readTemperature(); //DHT11 read Temperature
  
  
  temp = analogRead(A0); //Grove Temperature v1.2
  temp = (float)(1023 - temp)*10000 /temp; //Formula
  temp = 1/(log(temp/10000)/3975+1/298.15)-273.15; //Formula
  temp /= 2.3; //For optimum and true value. Look up for details 

  int iTemp =(int)round(temp); 
  int decimalPart;
  fTemp = (float) iTemp;
  if(temp >= fTemp){
    decimalPart = 100 * (temp - iTemp);
  }else if (fTemp > iTemp){
    decimalPart = 100 * (iTemp - temp);
  }

  if(decimalPart > 50 || decimalPart == 0){
      lTemp = iTemp; 
  }else if (decimalPart > 1 && decimalPart < 50){
      lTemp = iTemp + 0.5;
  }
  //I wrote these decimal parts to get stable values because Grove Temperature v1.2 is so sensitive that I reckon thus Arduino made round operation. 
   
  light = analogRead(A1); //Light-Brightness
  light = map(light, 0, 800, 0, 10);
  
  brightnessBar = map(light,0,12,0,9); //Map for Brightness Bar

  //LCD Operations
  lcd.setRGB(colorR,colorG,colorB);

  lcd.setCursor(0,0);
  lcd.print("Inside : ");
  lcd.setCursor(9,0);
  lcd.print(tempL35);
  lcd.setCursor(13,0);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Outside:");
  lcd.setCursor(9,1);  
  lcd.print(lTemp);  
  lcd.setCursor(13,1);
  lcd.print("C");
  

  //Serial Communication
  Serial.print("Isik: ");
  Serial.println(light);
  Serial.print("Sicaklik: ");
  Serial.println(temp35);
  Serial.print("lTemp: ");
  Serial.println(lTemp);  
  Serial.print("DHT11 Sicaklik: ");
  Serial.println(t);
  Serial.print("DHT11 Nem: ");
  Serial.println(h);
  Serial.print("//////////////////////");
  Serial.println("");

  breath(REG_RED); //Fade
  delay(500);

  lcd.clear();
  lcd.setRGB(220,20,60);
  lcd.setCursor(0,0);
  lcd.print("Humid: %");
  lcd.setCursor(8,0);
  lcd.print(h);
  
  lcd.setCursor(0,1);
  lcd.print("Light:");
  lcd.setCursor(7,1);
  for(i=7; i < 16; i++){ //For Brightness Bar 
    lcd.setCursor(i,1);
    lcd.write(byte(0)); 
  }
  {
    lcd.setCursor(i+7, 1);   
    lcd.write(byte(1));  
  }
  breath(REG_GREEN); //FAde
  delay(1000);
  lcd.clear();
}
//This is the fade code I didn't write it, I took it from Grove LCD's examples. But I understood the code and like it that's why I use many times :)
void breath(unsigned char color){

    for(int i=0; i<255; i++)
    {
        lcd.setPWM(color, i);
        delay(5);
    }

    delay(500);
    for(int i=254; i>=0; i--)
    {
        lcd.setPWM(color, i);
        delay(5);
    }

    delay(500);
}

 


