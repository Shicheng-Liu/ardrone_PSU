# How to work with Olympe and Sphinx
In this directory, you will go through the procedures of controlling a drone in a simulator via python scripts.

We are referring from [this page](https://developer.parrot.com/docs/olympe/userguide.html).

This readme will only show brief things. For futher info, go to the page above.

# Example 1
## Write a Python script
We will create a simple python script (Just like a "Hello, World" program).

In your working directory, create the following python script.
```python
import olympe
from olympe.messages.ardrone3.Piloting impor TakeOff

drone = olympe.Drone("10.202.0.1")
drone.connection()
drone(TakeOff()).wait()
drone.disconnection()
```

## Start up sphinx
Before executing the script, you will need to prepare your sphinx environment. For this example, we will be using _anafi4k_ drone.

Execute the following commands.
```
sudo systemctl start firmwared
sphinx /opt/parrot-sphinx/usr/share/sphinx/drones/anafi4k.drone::stolen_interface=::simple_front_cam=true
```

Here, we are starting up the drone with a simplified front camera and without a wifi interface.

Not just this example, but throughout the next procedures, any drone will be able to be reached with the virtual ethernet interface. The drones can be reached by "10.202.0.1".

# Example 2
_You can leave the simulation windows open._


