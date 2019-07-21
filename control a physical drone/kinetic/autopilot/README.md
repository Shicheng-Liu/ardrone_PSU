How to make the ardrone2 recognize the environment and autopilot
=
<br> Now, attention! This stuff is much cooler than keyboard control.
<br> Please make sure that you have followed the keyboard control tutorial and finished successfully before you work on this project because
 this project needs the package _ardrone_autonomy_ which you should have installed when you work on keyboard control.
<br>
<br>

Setup your workspace
--
<br> First, you need to create a workspace _catkin_ws_ in your home directory or you can still use the workspace _ros_workspace_ we have already created in keyboard_control. 
<br> Then go to the _src_ directory, Take _ros_workspace_ as an example:
<br> `cd ros_workspace/src`
<br> `git clone https://github.com/tum-vision/tum_ardrone.git`
<br> `cd ..`
<br> `rosdep install tum_ardrone`
<br> Now, we need to edit a file to make tum_ardrone compatible with Ubuntu16:
<br> Search the file _RosThread.h_ in your computer, and then you need to add two lines: `#ifndef Q_MOC_RUN`, `#endif`
<br> The first one needs to be added at the top and the second one needs to be added at the bottom.
<br> Then, you can `catkin_make`
<be> Now, everything is done.
 <br>
 <br>
 
 Work on your Ardrone2 now
 ------
<br> Connect with the WIFI of your ardrone
 <br> Then you should open a terminal: `roscore`
 <br> Open another terminal:
 <br> `cd catkin_ws`
 <br> `source devel/setup.bash`
 <br> `roslaunch tum_ardrone tum_ardrone.launch`
 <br> I do not like to add my path to _bashrc_, so I need to source my workspace everytime. If you find it annoying, you can export the path to your _bashrc_.
<br>  You will see three windows on your desktop, load the file _initDemo.txt_ in your **drone_gui** window, then click **reset** followed
by **clear and send**.
<br> Then, you will see the drone to takeoff, fly around and finally stabilize at its original location, at the meanwhile, the video will show many points and the 3D map will show the same points and the track of your drone. Choose one point on your video and click it, the drone will move to a specific location that aligns the point you just clicks.
<br> Once the drone is in place, it will move back to the point wherever you push it. 
