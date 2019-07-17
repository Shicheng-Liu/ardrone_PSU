How to control a physical drone
==============================
You can still use Olympe to control a physical drone and only need to change the IP address. The other things is same with your simulated drone.
<br>
<br> **However**, Olympe can only support three types of parrot drones(ANAFI, Bebop,and disco). Accordingly, if you want to control other types, you need to figure out another way.
Now, the lab has only one series: Ardrone2.
<br> **Here**, we have two ways to control Ardrone2: one is using node.js, the other way is using ROS.

<br> Node.js
----------------------
<br> _Node.js_ is an awesome tool, it can help you get started with Ardrone quikly and easily. Just click [here](https://github.com/Shicheng-Liu/parrot_PSU/tree/master/control%20a%20physical%20drone/Node.js) and you will have fun soon.

<br> ROS
------------
You can also use ROS to control your Ardrone2, which seems to be cooler. 
<br>
<br>  **NOTE**: If your Ubuntu version is 18.04, please use VirtualBox to work in Ubuntu 16.04 or 14.04 environment(The steps will be mentioned)
That is because Ubuntu18 can only use ROS melodic which will generate annoying bugs. 
<br> ROS kinetic will give you satisfying results and can only be run on Ubuntu16, I personally recommend you to use ROS kinetic, click [here]()
<br> If your ubuntu version is 14.04, you can also use ROS indigo which can also work. However, since indigo is too old and out of support, you can only use source code to install and may miss some funtions. click [here](https://github.com/Shicheng-Liu/parrot_PSU/tree/master/control%20a%20physical%20drone/indigo) 
<br> Repeat, I personally recommend you to use ROS kinetic since some projects here can only work successfully on kinetic.
