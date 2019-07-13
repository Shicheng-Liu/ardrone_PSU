How to control a physical drone
==============================
You can still use Olympe to control a physical drone and only need to change the IP address. The other things is same with your simulated drone.
<br>
<br> **However**, Olympe can only support three types of parrot drones(ANAFI, Bebop,and disco). Accordingly, if you want to control other types, you need to figure out another way.
Now, the lab has only one series: Ardrone2.
<br> **Here**, we have two ways to control Ardrone2: one is using node.js, the other way is using ROS.

<br> Node.js
----------------------
There is a great tutorial already conprehensively developed. Following the instructions, you can do a nice work. Refer [Here](https://github.com/felixge/node-ar-drone)
<br> You can use node.js both on Windows and Linux.

<br> ROS
------------
You can also use ROS to control your Ardrone2, which seems to be cooler. Refer [Here](https://fidel.ie/2017/01/18/getting-started-with-ardrone2-part3.html)
<br> The tutorial has three parts.
<br>
<br> **ATTENTION**: There is an imperfection in this tutorial: After following all the steps, you will meet an error after you run the command `roslaunch ardrone_tutorials keyboard_controller.launch` in your second terminal.
That is because you do not source your _setup_ file in your workspace. Run the code below first in your second terminal:
<br> `cd ros_workspace`
<br> `source devel/setup.bash`
<br> And then you can run the command `roslaunch ardrone_tutorials keyboard_controller.launch` , everthing will be fine.(ros_workspace is the name of the environment you create to control your ardrone
, which is same with the one in the tutorial. But if you use another name when creating your working environment, please change ros_workspace to your own name)
<br>
<br>  **NOTE**: If your Ubuntu version is not 16.04, please use VirtualBox to work in Ubuntu 16.04 env(The steps are mentioned in the tutorial part1 and part2)
That is because Ubuntu18 can only use ROS melodic which will generate annoying bugs if you follow this tutorial. ROS kinetic will give you satisfying results and can only be run 
on Ubuntu16
<br> If your ubuntu version is 14.04, you can also use ROS indigo which can also work. You can also use this tutorial, just changing _kinetic_ in your command into _indigo_. 
