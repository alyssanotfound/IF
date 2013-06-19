import processing.serial.*;
Serial port;
String button = "Submit";
String myText = "A";
int rectX, rectY;      // Position of square button
int rectSize = 20;     // Diameter of rect
color rectColor, baseColor;
color rectHighlight;
boolean rectOver = false;

void setup() {
   port = new Serial(this,Serial.list()[1], 9600);
   size(300, 300);
   rectColor = color(0);
   rectHighlight = color(51);
   rectX = 25;
   rectY = 20;
   textAlign(CENTER, CENTER);
   textSize(20);
   fill(0);
}
void draw() {
  update(mouseX, mouseY);
  background(255);

  text(myText, 0, 0, width, height);
  text(button, 0, 0, width/1.8, height/5);
  
  if (rectOver) {
    fill(rectHighlight);
  } else {
    fill(rectColor);
  }
  rect(rectX, rectY, rectSize, rectSize);
}




void mousePressed() {
  if (rectOver) {
    String sendMe = myText;
    port.write(sendMe);
  }
} 


void mouseReleased() {
  if (rectOver) {
   port.write("B");
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
  println(myText);
}


void update(int x, int y) {
  if ( overRect(rectX, rectY, rectSize, rectSize) ) {
    rectOver = true;
  } else {
    rectOver = false;
  }
}

boolean overRect(int x, int y, int width, int height)  {
  if (mouseX >= x && mouseX <= x+width && 
      mouseY >= y && mouseY <= y+height) {
    return true;
  } else {
    return false;
  }
}
