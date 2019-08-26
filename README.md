# Pan tilt camera 
Pan Tilt servo motor camera controller through Arduino and ROS: https://www.youtube.com/watch?v=o5tCGbW4WF0


# Installations

Note: the demo has been conducted on Ubuntu 16.04 PC


1) ROS (tested with Kinetic on Ubuntu 16.04): http://wiki.ros.org/kinetic/Installation


Create a catkin workspace and add the contents of the node "pan_tilt_camera"



2) Arduino IDE for Ubuntu: https://www.arduino.cc/en/guide/linux .Add the following libraries:

   - Rosserial Arduino Library

   - Servo



3)Install usb_cam driver to connect the laptop to the Logitech camera

$sudo apt-get install ros-kinetic-usb-cam




4) Install rosserial python node (included) and place ROS node on Arduino: http://wiki.ros.org/rosserial_python

$ sudo apt-get install ros-kinetic-rosserial-arduino ros-kinetic-rosserial

$cd catkin_ws/src
 
$git clone https://github.com/ros-drivers/rosserial.git

$cd ..

$catkin_make




4) find_object_2d: https://gihub.com/introlab/find-object




## How to run

1) Run the ROS master

$roscore


2) Plug in and run the Logitech USB camera


$roslaunch pan_tilt_camera usb_cam.launch


3)Run find_object_2d for object detection. 


$roslaunch pan_tilt_camera start_find_object_2d.launch


First take an image of the captured object to add to the recognised objects folder so that it can be recognised.


4) If not done already compile and load the arduino code "servo_ros.ino", which enables ROS control of servos


5) Run the rosserial node that establishes the ROS node and connection of ROS with Arduino. Ensure the Arduino is recognised as /dev/ttyACM0, else change accordingly
    


$ rosrun rosserial_python serial_node.py /dev/ttyACM0 _baud:=57600



6) Run the object tracker

$rosrun pan_tilt_camera center_camera


7) Place the object in front of the Logitech camera and, visualising the output of find_object_2d, move the object slowly and see pan tilt camera track the object



To see the Rviz model, run the corresponding launch file:


$ roslaunch pan_tilt_camera my_display.launch



From the joint_state_publisher GUI slide the pan and tilt bars to see the movement of the joints






