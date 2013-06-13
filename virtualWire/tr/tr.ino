// from http://communityofrobots.com/tutorial/kawal/using-rf-link-reciever-and-transmitter-arduino
#include <VirtualWire.h>  // you must download and install the VirtualWire.h to your hardware/libraries folder
#undef int
#undef abs
#undef double
#undef float
#undef round

void setup()
{
     // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for RF Link module
    vw_setup(2000);                 // Bits per sec
    vw_set_tx_pin(3);                // pin 3 is used as the transmit data out into the TX Link module, change this as per your needs  
}

void loop()
{
    const char *msg = "Community of Robots";       // this is your message to send

   vw_send((uint8_t *)msg, strlen(msg));
   vw_wait_tx();                                          // Wait for message to finish
   delay(200);
}

