How to make the ardrone2 recognize the environment and autopilot
=
<br> Now, attention! This stuff is much cooler than keyboard control.
<br> Please make sure that you have followed the keyboard control tutorial and finished successfully before you work on this project because
 this project needs the package _ardrone_autonomy_ which you should have installed when you work on keyboard control.
<br>
<br>

How to work on this project
--
<br> First, download the workspace _catkin_ws_ in your home directory. Since the core package _tum_ardrone_ we need to use in this project
 does not have kinetic version and is hard to install in kinetic, I will not give you the steps of installing the package. You just 
  download my worksapce _catkin_ws_ and everything will be fine.
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
