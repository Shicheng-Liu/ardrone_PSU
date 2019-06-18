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

__NOTE:__ There will be a ton of log messages so keep an eye out for the `print` command in this example.

We will receive the drone's states in this example. There is a function caled `olympe.Drone.get_state()`. This will always return the current drone state associated to an __event message__ when Olympe is connected to a drone.

Here, we will be passing `MaxTiltChanged()` message to the `olympe.Drone.get_state()` command. This will return a dictionary of the `MaxTiltChanged()` even mesage which provide the following parameters:
* current (float) - Current max tilt
* min (float) - Range min of tilt
* max (float) - Range max of tilt

__NOTE:__ Here the _min_ and _max_ parameters are actually the minimum and the maximum values for the __maximum tilt__ setting. We are only interested in the _current_ value of this setting.

Just like Example 1 create the following python script. Name it as `maxtiltget.py`.
```python
from __future__ import print_function
import olympe
from olympe.messages.ardrone3.PilotingSettingsSate import MaxTiltChanged

drone = olympe.Drone("10.202.0.1")
drone.connection()
print("Drone MaxTilt = ", drone.get_state(MaxTiltChanged)["currnet"])
drone.disconnection()
```

Execute this script in the same shell environment you prepared in Example 1
```
(olympe-python3)$ python ./maxtiltget.py
```
