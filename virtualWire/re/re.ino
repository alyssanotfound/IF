#include <VirtualWire.h>    // you must download and install the VirtualWire.h to your hardware/libraries folder
#undef int
#undef abs
#undef double
#undef float
#undef round
int redPin = 9; 

void setup()
{
    Serial.begin(9600);    
    pinMode(redPin, OUTPUT);
// Initialise the IO and ISR
    vw_set_ptt_inverted(true);    // Required for RX Link Module
    vw_setup(2000);                   // Bits per sec
    vw_set_rx_pin(4);           // We will be receiving on pin 4 i.e the RX pin from the module connects to this pin. 
    vw_rx_start();                      // Start the receiver 
}

void loop()
{
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
            digitalWrite(redPin, HIGH);
            delay(10);
            digitalWrite(redPin, LOW);
            delay(10);
          }
     Serial.println("END");
    Serial.println("");
     }
}
