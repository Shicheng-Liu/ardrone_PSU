How to make the drone Circle
=============================
We can use the function _Circle()_ to make the drone circle. Refer <a href="https://developer.parrot.com/docs/olympe/arsdkng_ardrone3_piloting.html?highlight=circle#olympe.messages.ardrone3.Piloting.Circle" rel="nofollow noopener">Circle</a>
<br>
<br> The function _Circle()_ can only be applied to a fixed-wing drone(to be specific, DISCO only).
<br> Like Bebop, DISCO needs different commands to simulate in Parrot-Sphinx:
```
sudo systemctl start firmwared
sphinx /opt/parrot-sphinx/usr/share/sphinx/drones/disco.drone::stolen_interface=::simple_front_cam=true
```
 Start the Olympe environment:
```
source ~/code/parrot-groundsdk/./products/olympe/linux/env/shell
```
Then, install a jsonrpc client library in your python environment :
```
(olympe-python3) $ pip3 install jsonrpclib-pelix
```
 From your script, use the jsonrpclib module to trigger the “fixedwings_shake/handling” action :
```
import jsonrpclib
import olympe
import olympe_deps as od
from olympe.messages.ardrone3.Piloting import TakeOff

sphinx_client = jsonrpclib.Server("http://127.0.0.1:8383")
drone = olympe.Drone("10.202.0.1", od.ARSDK_DEVICE_TYPE_EVINRUDE)
drone.connection()
sphinx_client.TriggerAction(
    machine="disco",   # this should match the drone name in the .drone file
    object="fixedwings_shake/handling",
    action="start"
)
drone(TakeOff()).wait()
```
This script is a _takeoff_ you can directly use. I will show  `Circle.py` where you can see more details.
