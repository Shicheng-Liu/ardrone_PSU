Create your workspace
=====================================

<br> Relevant packages installation
-------------------------------------
<br> We need to use keyboard to control the motion of the drone, so now we need two packages: _ardrone_autonomy_ and _ardrone_tutorials_
<br> Here, we will install these two packages into your workspace just built, _ros_workspace_
<br> `cd ros_workspace/src`
<br> `sudo apt-get install ros-indigo-joystick-drivers python-rosinstall`
<br> `sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev libpulse-dev libxt-dev openssh-server`
<br> `cd ros_workspace/src`
<br> `catkin_init_workspace`
<br> `cd ..`
<br> `catkin_make`
<br> `source /home/server/ros_workspace/devel/setup.bash`
<br> `echo "source /home/server/ros_workspace/setup.bash" >> ~/.bashrc`
<br> **NOTE**: The username is _server_, if yours is not, please change it.
<br> `cd /home/server/ros_workspace/src/`
<br> `git clone https://github.com/AutonomyLab/ardrone_autonomy.git`
<br> `git clone https://github.com/mikehamer/ardrone_tutorials.git`
<br> `ls -la`
<br> `cd /home/server/ros_workspace/`
<br> `rosdep install --from-paths src -i`
<br> `catkin_make`
<br> `rosmake -a`
<br> `sudo apt-get install python-pyside`
<br>

<br> Launch your package and make the drone fly
---------------------------------------------------
<br> Now, you have successfully installed all we need. The next step is to connect with your Ardrone and make it fly!
<br> First, you need connect the WIFI of your drone.
<br> Open a terminal, run `roscore`; <br>Open a second terminal, run `cd ros_workspace` followed by `source devel/setup.bash` and then 
`roslaunch ardrone_tutorials keyboard_controller.launch`
<br> You will see a video popup showing the videostream from the front camera of your drone.
<br> Now Press your keys and make if fly!
<br> 
W – Pitch Forward     <br>S – Pitch Backward            
A – Roll Left                                        <br>D – Roll Right
<br>
Q – Yaw Left                                        <br> R – Yaw Right
<br>
Z – Increase Altitude                                <br>C – Decrease Altitude
<br>
Y – Takeoff                                         <br> H – Land
<br>
SPACEBAR – EMERGENCY STOP
<br>
