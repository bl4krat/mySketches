// Arduino Due - sendMessage - Sample 1
// Sends a short (>= 8 bit) message
// 
// By Bl4krat 2018 

// Required libraries
#include "variant.h"
#include <due_can.h>

#define CAN_MSG_ID               0x059

// CAN frame max data length
#define MAX_CAN_FRAME_DATA_LEN   8

// Message variable to be send
uint32_t CAN_MSG_1 = 0;

//Leave defined if you use native port, comment if using programming port
#define Serial SerialUSB

CAN_FRAME output;

void setup()
{
  
  // start serial port:
  Serial.begin(115200);
  //Serial.println("Type CAN message to send");
  //while (Serial.available() == 0);

    // Initialize CAN0, baudrate is 250kb/s
  Can0.begin(CAN_BPS_500K);
}
void loop()
{

  // Prepare the frame
  output.id = CAN_MSG_ID;
  output.rtr = 0;
  output.priority = 4;
  output.extended = 0;
  output.length = 8;
  //Set the message
  //output.data.value = 0x0102030405060708;
  output.data.byte[0] = 0x01;
  output.data.byte[1] = 0x02;
  output.data.byte[2] = 0x03;
  output.data.byte[3] = 0x04;
  output.data.byte[4] = 0x05;
  output.data.byte[5] = 0x06;
  output.data.byte[6] = 0x07;
  output.data.byte[7] = 0x08;
  

  
  //Send out the frame on whichever mailbox is free or queue it for
  //sending when there is an opening.
  Can0.sendFrame(output);
  
  Serial.println(Can0.numBusErrors,HEX);

  delay(100);  //100 milis
}

