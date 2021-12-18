#ifndef LIDAR_H
#define LIDAR_H

#include <Arduino.h>
#include <HardwareSerial.h>

class LIDAR {
    private:
    int dist; /*----actual distance measurements of LiDAR---*/
    int strength; /*----signal strength of LiDAR----------------*/
    float temprature;
    unsigned char check;        /*----save check value------------------------*/
    int i;
    unsigned char uart[9];  /*----save data measured by LiDAR-------------*/
    const int HEADER=0x59; /*----frame header of data package------------*/
    int rec_debug_state = 0x01;//receive state for frame

    public :
    LIDAR();
    ~LIDAR();
    void initialize_Lidar(HardwareSerial *my_Serial, int8_t my_RX, int8_t my_TX);
    int get_distance(HardwareSerial *my_Serial);
    void print_distance(HardwareSerial *my_Serial);


};

#endif