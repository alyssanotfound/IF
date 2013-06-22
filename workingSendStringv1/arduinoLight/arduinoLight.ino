  #include <VirtualWire.h>
  #undef int
  #undef abs
  #undef double
  #undef float
  #undef round
  char inData[3] = {'A', 'A','A'}; // Allocate some space for the string
  char inChar=-1; // Where to store the character read
  byte index = 0; // Index into array; where to store the character
  int ledPin = 13; // Set the pin to digital I/O 4
  
  void setup(){
   pinMode(ledPin, OUTPUT); 
   Serial.begin(9600);
   Serial.write("Power On");
   vw_set_ptt_inverted(true); // Required for RF Link module
   vw_setup(2000);                 // Bits per sec
   vw_set_tx_pin(3);
  }
  
  
  
  
  void loop()
  {
    const char *msg = inData;       // this is your message to send
   
   vw_send((uint8_t *)msg, strlen(msg));
   
   vw_wait_tx();                                          // Wait for message to finish
   delay(200);
   
    unsigned int data;
   if (Serial.available() > 0) {
     data = Serial.read();
     Serial.write(data);  
   }
   
  if(Comp("A")==0){
       digitalWrite(ledPin, HIGH); // turn the LED on when the byte coming in from the serial is A
   }
   if(Comp("B")==0){
       digitalWrite(ledPin, LOW); // turn the LED off
   }
   
   delay(100); // Wait 100 milliseconds for next reading

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
   else if(strcmp(inData,This)  == 1){ // if dont match
   
   return(1);
  
   }
  }
  
