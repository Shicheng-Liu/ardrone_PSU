How to use indigo to control ardrone2 (keyboard control)
=====================================
Here we go
<br>
<br> First, you need Ubuntu14 since indigo can only be used on Ubuntu14. 
<br> You can use [VirtualBox](https://www.virtualbox.org/wiki/Downloads) to start with your virtual [Ubuntu14](http://old-releases.ubuntu.com/releases/14.04.0/)
<br> 
<br> Once you have installed VirtualBox and downloaded image of Ubuntu14, open VirtualBox.
<br>  * Click on “New”
<br>  * give your virtual machine a name such as “Ubuntu14”
<br>  * 2GB of RAM is good, but if you are tight with RAM, 1GB is already enough for keyboard control.
<br>  * Select a dynamically allocated disk of 25GB to give yourself room
<br>  * Once created, click settings
<br>  * Goto: Storage > Controller, IDE > ‘Choose Virtual Disk’ and select the Ubuntu .ISO you downloaded
<br>  * Goto: Network options.   Make sure you have two connections: one is NAT and the other is bridged connection.
<br>  * Goto: Display. allocate 32MB of video memory to your virtual Ubuntu14.
<br>
<br> PS: If you find the resolution cannot match  your computer, you can open your terminal and follow these steps:
<br> `$ xrandr`
<br> Then you will see a list of resolutions to choose. Choose the one that matches your computer.
<br> `$ xrandr -s yourchoice`
<br>
<br> If you cannot find the resolution you want, please follow these steps: (Take 1920x1080 as an example)
<br> `cvt 1920 1080`
<br> `xrandr --newmode "1920x1080_60.00"  173.00  1920 2048 2248 2576  1080 1083 1088 1120 -hsync +vsync`
<br> `xrandr --addmode Virtual1 "1920x1080_60.00"`
<br> Then, go to the setting, find the _Display_ , you can see the choice 1920x1080, choose and apply.
<br>
<br> You still need to add two codes
 to your /etc/profile
<br> `sudo chmod 777 /etc/profile` 
<br> `vim /etc/profile`
<br> Then, add `xrandr --newmode "1920x1080_60.00"  173.00  1920 2048 2248 2576  1080 1083 1088 1120 -hsync +vsync` and `xrandr --addmode Virtual1 "1920x1080_60.00"`
at the bottom. Use button _ESC_ and type in `:wq`, then _ENTER_.        FINISHED!
<br>

<br> ROS indigo installation
------------------------------
<br> Since indigo is out of support now, we can only install with source code.
<br> `sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'`
<br> `sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 0xB01FA116`
<br> `sudo apt-get update`
<br> If you find error reported in this step, please search in Google. It's a simple problem, easy to handle.
<br> `sudo apt-get install ros-indigo-desktop-full`
<br> `sudo rosdep init`
<br> `rosdep update`
<br> `echo "source /opt/ros/indigo/setup.bash" >> ~/.bashrc`
<br> `source ~/.bashrc`
<br> `sudo apt-get install python-rosinstall`
<br>
<br> For now, we have successfully installed ROS indigo. The next step is to build a workspace:
<br> `mkdir -p ~/ros_workspace/src`
<br> `cd ~/ros_workspace/`
<br> `catkin_make`
<br> `source devel/setup.bash`
<br>
<br> Okay, now you have successfully installed ROS and built a workspace.
<br>

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


