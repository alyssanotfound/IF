import processing.serial.*;
Serial port;
String myText = "light on";

void setup() {
   port = new Serial(this,Serial.list()[1], 9600);
   size(300, 300);
   textAlign(CENTER, CENTER);
   textSize(30);
   fill(0);
}
void draw() {
  background(255);
  text(myText, 0, 0, width, height);
}




void mousePressed() {
 String sendMe = myText;
 port.write(sendMe);
} 
void mouseReleased() {
 port.write("light off");
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
  //println(myText);
}
