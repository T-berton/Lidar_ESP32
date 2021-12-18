#include <LIDAR.H>
#include <Plotter.h>




LIDAR my_Lidar;
Plotter p; // create plotter
int distance;


void setup() {
	//delay(2000);
	//Serial.begin(115200);
	//Serial.println("\nBenewake TFmini-S UART LiDAR Program");
  my_Lidar.initialize_Lidar(&Serial2,18,19);
  p.Begin();
  p.AddTimeGraph( "Some title of a graph", 1500, "distance", distance ); // add any graphs you want
}

void loop() {
	distance=my_Lidar.get_distance(&Serial2);
  p.Plot(); // plot all current data -- usually called within loop()

  //Serial.println(distance);
  //my_Lidar.print_distance(&Serial2);
}
