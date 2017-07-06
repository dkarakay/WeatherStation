// Written by Deniz Karakay 06.07.2017
float previous;

void setup() {
   pinMode(7,OUTPUT);
   pinMode(8,OUTPUT);
   pinMode(9,OUTPUT);
   pinMode(A0,INPUT);
   Serial.begin(9600);

}

void loop() {
  //I use Arduino UNO for this project because it doesn't work with Arduino 101 (I mean work with LCD) I think it causes because of lack of voltage. So I use my Arduino. 
  float water = analogRead(A0);
  float waterT = water + previous;   //For getting previous data and compare to new one to see difference.
  
  if(waterT <= 1000){
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }else if(waterT >= 1000 && waterT < 1200){
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }else if(waterT >= 1200 && waterT < 1500){
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
  }else if(waterT >= 1500){
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
  }
  Serial.print("Rain: "); //Detect Rain
  Serial.println(water);
  previous = water;
  delay(1000);

}
