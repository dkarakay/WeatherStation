# WeatherStation

Detailed link: https://devpost.com/software/weatherstation

## Inspiration
I created this project to help people and I found my problem myself because I encountered with it. I wake up very early to go to school. At that time my family is sleeping and I don't want them to wake up. Our windows and curtains are closed at that time that's why I can't see the weather condition. I had a problem with rain and temperature last school year. In the end I want to make a Weather Station to see and get real time data and be ready for it.

## What it does
It gets temperature, humidity, brightness and rain situation with sensors. My Arduino 101 gets temperature, humidity and brightness. I can see these data from bright and colorful LCD. I put also inside a sensor too. With this I can feel and predict the temperature easily. With Arduino Uno I can get water sensor data and according to data, LED's will light up. If it is too heavy all of them will light up.

## How I built it
I built it with Arduino 101 and Arduino Uno. I used LM35 for inside temperature, DHT11 for outside humidity and temperature, Grove Temperature Sensor v1.2 for outside temperature, Grove Light Sensor for brightness, Water sensor for detecting rain, BaseShield for connecting Grove sensors and also some LED's for showing Rain situation,  
of course some jumple wires, Grove to jumper wires and a colorful LCD. I wrote two Sketches for Arduino 101 and Arduino Uno to detect and show the stable, optimum and true data with LCD. 

## Challenges I ran into
I have encountered many challenges. First I have to optimize and try many and many times to work LM35 and Grove Temperature sensors because their values are different so the example codes get wrong data. When I switch BaseShield working voltage to 5, problems start. Although these sensors can work with 5V but I solved with trying and anlaysing. I also had a problem with connecting water sensor to Arduino 101 with LCD because LCD sticks when sensor is connected. So I used another Arduino. At last I think this is a problem for water sensor. I bought these sensor for detect rain but these water sensor is for water level not for the rain. I will go to my village and I can't get the Rain Drop sensor that's why I had to use.     

## Accomplishments that I'm proud of
I'm happy to write proper codes for Arduino 101 and Uno and I'm proud of finishing this project.

## What I learned
I learned many things like Grove Sensors, analyze and organize data to be able to get right one. I also learned how to use this colorful LCD.

## What's next for WeatherStation
I have ideas for future too. I want to see data from my mobile phone with Bluetooth and want to create an app for seeing both real time data and online weather broadcaster's data.
