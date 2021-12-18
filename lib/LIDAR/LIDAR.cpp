#include "LIDAR.h"

LIDAR::LIDAR()
{
}

LIDAR::~LIDAR()
{
}

void LIDAR::initialize_Lidar(HardwareSerial *my_Serial, int8_t my_RX, int8_t my_TX){
    my_Serial->begin(115200,SERIAL_8N1,my_RX,my_TX);
}

void LIDAR::print_distance(HardwareSerial *my_Serial)
{
     if (my_Serial->available()) //check if serial port has data input
    {
        if(rec_debug_state == 0x01)
        {  //the first byte
          uart[0]=my_Serial->read();
          if(uart[0] == 0x59)
              {
                check = uart[0];
                rec_debug_state = 0x02;
              }
        }
    else if(rec_debug_state == 0x02)
     {//the second byte
      uart[1]=my_Serial->read();
      if(uart[1] == 0x59)
          {
            check += uart[1];
            rec_debug_state = 0x03;
          }
      else{
            rec_debug_state = 0x01;
          }
      }

    else if(rec_debug_state == 0x03)
        {
          uart[2]=my_Serial->read();
          check += uart[2];
          rec_debug_state = 0x04;
        }
    else if(rec_debug_state == 0x04)
        {
          uart[3]=my_Serial->read();
          check += uart[3];
          rec_debug_state = 0x05;
        }
    else if(rec_debug_state == 0x05)
        {
          uart[4]=my_Serial->read();
          check += uart[4];
          rec_debug_state = 0x06;
        }
    else if(rec_debug_state == 0x06)
        {
          uart[5]=my_Serial->read();
          check += uart[5];
          rec_debug_state = 0x07;
        }
    else if(rec_debug_state == 0x07)
        {
          uart[6]=my_Serial->read();
          check += uart[6];
          rec_debug_state = 0x08;
        }
    else if(rec_debug_state == 0x08)
        {
          uart[7]=my_Serial->read();
          check += uart[7];
          rec_debug_state = 0x09;
        }
    else if(rec_debug_state == 0x09)
        {
          uart[8]=my_Serial->read();
          if(uart[8] == check)
            {
              
              dist = uart[2] + uart[3]*256;//the distance                  
              Serial.print("dist = ");
              Serial.print(dist); //output measure distance value of LiDAR
              Serial.print('\n');
                                                    
              while(my_Serial->available()){my_Serial->read();} // This part is added becuase some previous packets are there in the buffer so to clear serial buffer and get fresh data.
              delay(100);             
             }
          rec_debug_state = 0x01;
        }
    }
}
 

int LIDAR::get_distance(HardwareSerial *my_Serial){
    if (my_Serial->available()) //check if serial port has data input
    {
        if(rec_debug_state == 0x01)
        {  //the first byte
          uart[0]=my_Serial->read();
          if(uart[0] == 0x59)
              {
                check = uart[0];
                rec_debug_state = 0x02;
              }
        }
    else if(rec_debug_state == 0x02)
     {//the second byte
      uart[1]=my_Serial->read();
      if(uart[1] == 0x59)
          {
            check += uart[1];
            rec_debug_state = 0x03;
          }
      else{
            rec_debug_state = 0x01;
          }
      }

    else if(rec_debug_state == 0x03)
        {
          uart[2]=my_Serial->read();
          check += uart[2];
          rec_debug_state = 0x04;
        }
    else if(rec_debug_state == 0x04)
        {
          uart[3]=my_Serial->read();
          check += uart[3];
          rec_debug_state = 0x05;
        }
    else if(rec_debug_state == 0x05)
        {
          uart[4]=my_Serial->read();
          check += uart[4];
          rec_debug_state = 0x06;
        }
    else if(rec_debug_state == 0x06)
        {
          uart[5]=my_Serial->read();
          check += uart[5];
          rec_debug_state = 0x07;
        }
    else if(rec_debug_state == 0x07)
        {
          uart[6]=my_Serial->read();
          check += uart[6];
          rec_debug_state = 0x08;
        }
    else if(rec_debug_state == 0x08)
        {
          uart[7]=my_Serial->read();
          check += uart[7];
          rec_debug_state = 0x09;
        }
    else if(rec_debug_state == 0x09)
        {
          uart[8]=my_Serial->read();
          if(uart[8] == check)
            {
              
              dist = uart[2] + uart[3]*256;//the distance                  
             /* Serial.print("dist = ");
              Serial.print(dist); //output measure distance value of LiDAR
              Serial.print('\n');*/
                                                    
              while(my_Serial->available()){my_Serial->read();} // This part is added becuase some previous packets are there in the buffer so to clear serial buffer and get fresh data.
              delay(100);             
             }
          rec_debug_state = 0x01;
        }
    }
    return dist;
}
