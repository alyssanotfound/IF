import processing.serial.*;

import cc.arduino.*;

Arduino arduino;

String myText = "Type something";

color off = color(4, 79, 1);
color on = color(84, 145, 8);

int[] values = { Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW,
 Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW,
 Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW };

void setup() {
  size(500, 500);
  textAlign(CENTER, CENTER);
  textSize(30);
  fill(0);
  
  println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[0], 57600);
  
  for (int i = 0; i <= 13; i++)
    arduino.pinMode(i, Arduino.OUTPUT);
}

void draw() {
  background(off);
  stroke(on);
  text(myText, 0, 0, width, height);
  
  for (int i = 0; i <= 13; i++) {
    if (values[i] == Arduino.HIGH)
      fill(on);
    else
      fill(off);
      
    rect(420 - i * 30, 30, 20, 20);
    
  }
}

void mousePressed()
{
  int pin = (450 - mouseX) / 30;
  
  if (values[pin] == Arduino.LOW) {
    arduino.digitalWrite(pin, Arduino.HIGH);
    values[pin] = Arduino.HIGH;
  } else {
    arduino.digitalWrite(pin, Arduino.LOW);
    values[pin] = Arduino.LOW;
  }
}

void keyPressed() {
  if (keyCode == BACKSPACE) {
    if (myText.length() > 0) {
      myText = myText.substring(0, myText.length()-1);
    }
  } else if (keyCode == DELETE) {
    myText = "";
  } else if (keyCode != SHIFT && keyCode != CONTROL && keyCode != ALT) {
    myText = myText + key;
  }
}
