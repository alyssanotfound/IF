#include <VirtualWire.h>
#undef int
#undef abs
#undef double
#undef float
#undef round
char inData[4] = {'A','A','A'}; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character
  
void setup() {
   Serial.begin(9600);
   vw_set_ptt_inverted(true); 
   vw_setup(2000); 
   vw_set_tx_pin(3);
}

void loop() {
   while(Serial.available() > 0) { // START getting the value of inData from Processing (serial)
     for(int i=0;i<4;i++){
       inData[i]=0;
     }
     index=0;
 
     if(index < 3) {
       inChar = Serial.read(); //Reads one byte
       inData[index] = inChar; 
       index++; 
       inData[index] = '\0';  // END getting inData
     }
   }  
   
   char *msg = inData;  // set the message to send equal to the value of inData 
   vw_send((uint8_t *)msg, strlen(msg));
   vw_wait_tx();              
   delay(200);
 
   unsigned int data;
   if (Serial.available() > 0) {
     data = Serial.read();
     Serial.write(data);  
   }
   delay(500); 
  Serial.write("this is inData: ");
  Serial.write(inData);
}

