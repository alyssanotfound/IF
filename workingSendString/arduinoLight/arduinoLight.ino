char inData[3]; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character
int ledPin = 13; // Set the pin to digital I/O 4

void setup(){
 pinMode(ledPin, OUTPUT); 
 Serial.begin(9600);
 Serial.write("Power On");
}





char Comp(char* This){

 while(Serial.available() > 0) // Don't read unless
   // there you know there is data
 {
   for(int i=0;i<3;i++){
     inData[i]=0;
   }
   index=0;
   
   if(index < 3) // One less than the size of the array
   {
     inChar = Serial.read(); // Read a character
     inData[index] = inChar; // Store it
     index++; // Increment where to write next
     inData[index] = '\0'; // Null terminate the string
   }
 }

 if(strcmp(inData,This)  == 0){ //string compare function returns 0 if the incoming data matches "light on" etc 
   for(int i=0;i<3;i++){
     inData[i]=0;
   }
   index=0;
   return(0);

 }
 else if(strcmp(inData,This)  == 1){ // if dont match, delete everything
   
   return(1);

 }
}


void loop()
{
 if(Comp("1")==0){
       digitalWrite(ledPin, HIGH); // turn the LED on
 }
 if(Comp("2")==0){
       digitalWrite(ledPin, LOW); // turn the LED off
 }
delay(100); // Wait 100 milliseconds for next reading
}
