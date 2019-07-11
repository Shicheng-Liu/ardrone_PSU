HOW TO MAKE THE DRONE FLIP
==========================
<br>
<br>
We can use the function Flip() to command the drone to do such action  

Refer [Here](https://developer.parrot.com/docs/olympe/arsdkng_ardrone3_animations.html)
<br>
<br>
**NOTE** : The _Flip_ function can only work on Bebop drone. The ANAFI does not know how to flip and will ignore this command.
If you follow the previous instructions in this repository, your simulated drone is ANAFI which cannot flip.
<br>
<br>
To address this problem, we need to simulate Bebop in your Gazebo. Follow this instruction:<br>
<br> Start the Simulation:
<br> `$ sudo systemctl start firmwared`
<br> `$ sphinx /opt/parrot-sphinx/usr/share/sphinx/drones/bebop2.drone::stolen_interface=::simple_front_cam=true`
<br>**ATTENTION**: The commands are similar to the one you used to setup ANAFI simulation but they are actually different, so please copy this one.
<br>
<br>Setup your shell environment:
<br>`source ~/code/parrot-groundsdk/./products/olympe/linux/env/shell`
<br>
<br>The IP address of Bebop is still 10.202.0.1, but we need to give the drone type to the Olympe after the IP address is given
<br>`drone = olympe.Drone("10.202.0.1", drone_type=od.ARSDK_DEVICE_TYPE_BEBOP_2)`
<br>
<br>
The details will be shown in python script.
<br>
<br>
**NOTE**: The difference between Bebop simulation and ANAFI simulation is mentioned above, you can use the same commands like TakeOff(), Landing(), and some else in both Bebop and ANAFI
