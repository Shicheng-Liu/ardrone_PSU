Create your workspace
=====================================

<br> **server is my username, if yours is different, please change it to yours**
<br> `mkdir /home/server/ros_workspace/src/`
<br> `cd /home/server/ros_workspace/src/`
<br> `catkin_init_workspace`
<br> `cd /home/server/ros_workspace/`
<br> `catkin_make`
<br> `source /home/server/ros_workspace/devel/setup.bash`
<br> Configure ardrone_tutorials package
<br>`cd /home/server/ros_workspace/src/`
<br> `git clone https://github.com/mikehamer/ardrone_tutorials.git`
<br> `ls -la`
<br> `cd /home/server/ros_workspace/`
<br> `catkin_make`
<br> `rosmake -a`
<br> `sudo apt-get install python-pyside`
<br>
<br>
Reference:https://fidel.ie//2017/01/16/getting-started-with-ardrone2.html

<br> Launch your package and make the drone fly
---------------------------------------------------
<br> Now, you have successfully installed all we need. The next step is to connect with your Ardrone and make it fly!
<br> First, you need connect the WIFI of your drone.
<br> Open a terminal, run `roscore`; <br>Open a second terminal, run `cd ros_workspace` followed by `source devel/setup.bash` and then 
`roslaunch ardrone_tutorials keyboard_controller.launch`
<br> You will see a video popup showing the videostream from the front camera of your drone.
<br> Now Press your keys and make if fly!
<br> 
E – Pitch Forward     <br>D – Pitch Backward            
S – Roll Left                                        <br>F – Roll Right
<br>
W – Yaw Left                                        <br> R – Yaw Right
<br>
Q – Increase Altitude                                <br>A – Decrease Altitude
<br>
Y – Takeoff                                         <br> H – Land
<br>
SPACEBAR – EMERGENCY STOP
<br>
<br> **ATTENTION**: You may find the command keys are different from those in the README, that is because if you use my _ros_workspace_, the code related to key command has been changed, which I think will be easiler to control. However, if you build the workspace yourself, you are using original package from the website so the keys are different.
