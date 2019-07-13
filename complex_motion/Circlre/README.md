How to make the drone Circle
=============================
We can use the function _Circle()_ to make the drone circle. Refer <a href="https://developer.parrot.com/docs/olympe/arsdkng_ardrone3_piloting.html?highlight=circle#olympe.messages.ardrone3.Piloting.Circle" rel="nofollow noopener">Circle</a>
<br>
<br> The function _Circle()_ can only be applied to a fixed-wing drone(to be specific, DISCO only).
<br> Like Bebop, DISCO needs different commands to simulate in Parrot-Sphinx:
<br>`sudo systemctl start firmwared`
<br>`sphinx /opt/parrot-sphinx/usr/share/sphinx/drones/disco.drone::stolen_interface=::simple_front_cam=true`
<br>
<br> Start the Olympe env:
<br>`source ~/code/parrot-groundsdk/./products/olympe/linux/env/shell`
<br>
<br>