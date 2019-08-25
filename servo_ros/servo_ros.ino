
   #if defined(ARDUINO) && ARDUINO >= 100
     #include "Arduino.h"
   #else
     #include <WProgram.h>
   #endif
   
   #include <Servo.h> 
   #include <ros.h>
   #include <std_msgs/Int32.h>
    
   ros::NodeHandle  nh;
   int angle_x; //variable to store the pan angle
   int angle_y; //variable to store the tilt order
   Servo servoPan, servoTilt; //variable to change the angles of the motors
   
   void servoPan_cb(const std_msgs::Int32& cmd_msg){ 
  //cmd_msg contains the step we predefined to change the angle of the servos
  
     angle_x = servoPan.read();
     servoPan.write(angle_x + cmd_msg.data); //set servo angle, should be from 0-180  
   }

   void servoTilt_cb( const std_msgs::Int32& cmd_msg){
     angle_y = servoTilt.read();
     servoTilt.write(angle_y + cmd_msg.data); //set servo angle, should be from 0-90
   }
   
   
   ros::Subscriber<std_msgs::Int32> subP("/shift_x", servoPan_cb); //subscriber to Vision node, offset of object in x
   ros::Subscriber<std_msgs::Int32> subT("/shift_y", servoTilt_cb); //subscriber to Vision node, offset of object in y
   void setup(){
     pinMode(13, OUTPUT);
     
     Serial.begin(9600);
     
     nh.initNode();
     nh.subscribe(subP);
     nh.subscribe(subT);
     
     servoPan.attach(6); //attach it to pin 6
     servoTilt.attach(7); //attach it to pin 7
   }
   
   void loop(){
     
     nh.spinOnce();
     delay(1); 
   }
