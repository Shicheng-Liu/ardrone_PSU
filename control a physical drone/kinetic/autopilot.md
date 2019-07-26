How to make the ardrone2 recognize the environment and autopilot
=
<br> Now, attention! This stuff is much cooler than keyboard control.
<br> Please make sure that you have followed the keyboard control tutorial and finished successfully before you work on this project because
 this project needs the package _ardrone_autonomy_ which you should have installed when you work on keyboard control.
<br>
<br>

Setup your workspace
--
<br> First, you need to create a workspace `catkin_ws` in your home directory or you can still use the workspace `ros_workspace` we have already created in keyboard_control. 
<br> Then go to the _src_ directory, Take `catkin_ws`as an example:
```
cd catkin_ws/src
git clone https://github.com/tum-vision/tum_ardrone.git
cd ..
rosdep install tum_ardrone
```
 Now, we need to edit a file to make tum_ardrone compatible with Ubuntu16:
<br> Search the file `RosThread.h` in your computer, and then you need to add two lines: `#ifndef Q_MOC_RUN`, `#endif`
<br> It will look like this after you have added these two lines:
```
#ifndef Q_MOC_RUN
#include "cvd/thread.h"
#include "tum_ardrone/filter_state.h
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "ardrone_autonomy/Navdata.h"
#include "ros/ros.h"
#include "sensor_msgs/Joy.h"
#include "std_srvs/Empty.h"
#include "std_msgs/Empty.h"
#endif
```
Then, you can `catkin_make`
<br> Now, everything is done.
 <br>
 <br>
 
 Work on your Ardrone2 now
 ------
 <br> First, we need to invoke `ardrone_driver` in you `tum_ardrone.launch`:
 <br> Open the file `tum_ardrone.launch` and add this line `<include file="$(find tum_ardrone)/launch/ardrone_driver.launch"/>`
<br> The file will end looking like this:
```
<launch>
<include file="$(find tum_ardrone)/launch/ardrone_driver.launch"/>
  <node name="drone_stateestimation" pkg="tum_ardrone" type="drone_stateestimation">
  </node>
  <node name="drone_autopilot" pkg="tum_ardrone" type="drone_autopilot">
  </node>
  <node name="drone_gui" pkg="tum_ardrone" type="drone_gui">
  </node>
</launch>
```
<br> Connect with the WIFI of your ardrone
 <br> Then you should open a terminal: `roscore`
 <br> Open another terminal:
 ```
cd catkin_ws
source devel/setup.bash
roslaunch tum_ardrone tum_ardrone.launch
```
 I do not like to add my path to _bashrc_, so I need to source my workspace everytime. If you find it annoying, you can export the path to your _bashrc_.
<br>  You will see three windows on your desktop, load the file _initDemo.txt_ in your **drone_gui** window, then click **reset** followed
by **clear and send**.
<br> Then, you will see the drone to takeoff, fly around and finally stabilize at its original location, at the meanwhile, the video will show many points and the 3D map will show the same points and the track of your drone. Choose one point on your video and click it, the drone will move to a specific location that aligns the point you just clicks.
<br> Once the drone is in place, it will move back to the point wherever you push it. 
