#include <VirtualWire.h>    // you must download and install the VirtualWire.h to your hardware/libraries folder
#undef int
#undef abs
#undef double
#undef float
#undef round
const int greenPin = 9; 
const int bluePin = 10; 
const int redPin = 5; 
void setup()
{
    Serial.begin(9600);    
    pinMode(redPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);
// Initialise the IO and ISR
    vw_set_ptt_inverted(true);    // Required for RX Link Module
    vw_setup(2000);                   // Bits per sec
    vw_set_rx_pin(2);           // We will be receiving on pin 4 i.e the RX pin from the module connects to this pin. 
    vw_rx_start();                      // Start the receiver 
    analogWrite(greenPin, 255); //255 is off and 0 is on
    analogWrite(bluePin, 255); 
    analogWrite(redPin, 255);
    
}

void loop()
{
    ramp(greenPin, 0, 255);
    ramp(redPin, 255, 0);
    ramp(bluePin, 0, 255);
    ramp(greenPin, 255, 0);
    ramp(redPin, 0, 255);
    ramp(bluePin, 255, 0);
  
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // check to see if anything has been received
    {
int i;
     // Message with a good checksum received.
       
    for (i = 0; i < buflen; i++)
    {
        //Serial.println(i);
        Serial.write(buf[i]); // the received data is stored in buffer 
        }
        
    Serial.println("START of first three characters.");
    Serial.write(buf[0]);
    Serial.write(buf[1]);
    Serial.write(buf[2]);
     if (buf[0] == 'C' && buf[1] == 'o' && buf[2] == 'm') 
          {
            //success lights
  
          }
     Serial.println("END");
    Serial.println("");
     }
}

void ramp(int pin, int from, int to)
{
  int i ;
   
  if (from < to) {
    for (i=from; i<= to; i++) {
      analogWrite(pin, i) ;
      delay(5) ;
    }
  } else {
    for (i=from; i>= to; i--) {
      analogWrite(pin, i) ;
      delay(5) ;
    }
  }    
}
 
