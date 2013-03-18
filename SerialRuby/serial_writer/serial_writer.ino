/*   
  Feed Simulated data via serial(COM) port to computer.  
  This simulated data will be used by a program on the computer to handle serial data from a device.    
*/  
  
void setup()   
{   
  Serial.begin(9600);   
  Serial.println("Begin Simulated Serial Data Generation!");   
}   
  
  
  
int interval_time = 500; // Interval between data being sent. (in ms)  
int min_num = 1; // min value to generate data, must be above 1  
int max_num = 100; // max value to generate  
int sim_data = 0; // initialize data var  
  
void loop()   
{   
  sim_data = random(min_num, max_num);  
  Serial.println(sim_data);  
  delay(interval_time); // wait  
}
