# How to work with Olympe and Sphinx
In this directory, you will go through the procedures of controlling a drone in a simulator via python scripts.

We are referring from [this page](https://developer.parrot.com/docs/olympe/userguide.html).

This readme will only show brief things. For futher info, go to the page above.

## Side Notes
~~__NOTE:__ I couldn't see any actual results (for example2) because there were so many log outputs. Trying to figure out how I could disable them. I did see the `print` line so the program did succesfully catch the state. 2019/06/20~~

__NOTE:__ UPDATE! Found out a way to put logs into a file instead of the terminal stdout. Do as follow. `olympe.Drone("10.202.0.1", logfile=open("/tmp/olympe.log", "a+"))` The file placement and name can be set to anyhting. 2019/07/02 [Refer here for more](://github.com/shulace13/parrot_PSU/tree/master/src_adv#logging-policies)

__NOTE:__ If you have problems such as, executing the script but not initially working and then it works the second time, or the program isn't waiting for the drone to be in a certain state, restart your computer. It might be the solution. 2019/07/01

# Example 1 - Initial take off
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
sudo systemctl start firmwared.service
sphinx /opt/parrot-sphinx/usr/share/sphinx/drones/anafi4k.drone::stolen_interface=::simple_front_cam=true
```

Here, we are starting up the drone with a simplified front camera and without a wifi interface.

Not just this example, but throughout the next procedures, any drone will be able to be reached with the virtual ethernet interface. The drones can be reached by "10.202.0.1".

Now create a shell environment for your Olympe, if haven't done so.
```
source <path_to_your_groundsdk_place>/./products/olympe/linux/env/shell
```

In the shell environment, do `python takeoff.py`.
You should see your drone taking off into the air.

# Example 2 - Get the state of the drone
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

If all goes well, you should see the following results. 



Here, in the arsdk protocol defined in arsdk-xml does not provide a way to report errors. Thus, Olympe associates to each command a default timeout that can be overdriven with the *_timeout* message parameter.
```
maxTiltAction = drone(MaxTilt(10, _timeout=1)).wait()
```

# Example 3 - Changing the drone state

In this example, we will change the _maximum tilt_ drone setting.
For ANAFI the maximum tilt setting must be within 5 and 40 degrees.

First, reset the simulation (Ctrl+R inside gazebo)


```python
from __future import print_function
import olympe
from olympe.messages.ardrone3.PilotingSettings import MaxTilt

drone = olympe.Drone("10.202.0.1")
drone.connection()
maxTiltAction = drone(MaxTilt(10)).wait()
if maxTiltAction.success():
    print("MaxTilt(10) success")
elif maxtiltAction.timedout():
    print("MaxTilt(10) timedout):
else:
    # If ".wait()" is called on the _maxTiltAction_ this shouldn't happen
    print("MaxTilt(10) is still in progress")
maxtiltAction = drone(MaxTilt(1)).wait()
if maxTiltAction.success():
    print("MaxTilt(1) success")
elif maxTiltAction.timedout():
    print("MaxTilt(1) timedout")
else:
    # If ".wait()" is called on the _maxTiltAction_ this shouldn't happen
    print("MaxTilt(1) is still in progress")
drone.disconnection()
```

The `MaxTilt()` command is from the `ardrone3` feature. The first one with a 10 degree tilt and the second wih a 1 degree tilt value.

Here, we assigned the `maxTiltAction` variable the object returned by the `.wait()` method. for now, all you need to know is you can call `.success()` on an action object if you want to know whether your commad succeeded or not. This is a straight forward command, it returns `True` if the command was a success and `False` otherwise. You could also use `.timedout()`. However, this is typically not used because the we have a `.wait()` assigned to the action where we will be waiting for its success or being timed out.

If all goes well, you should get the following.

```
MaxTilt(10) success
MaxTilt(1) timeout
```

# Example 4 - Move the drone

Write the following python script `moveby.py`.
```python
import olympe
from olympe.messages.ardrone3.Piloting import TakeOff, moveBy, Landing

drone = olympe.Drone("10.202.0.1")
drone.connection()
drone(TakeOff()).wait()
drone(moveBy(10, 0 0, 0)).wait()
drone(Landing()).wait()
drone.disconnection()
```

Then execute by doing `python moveby.py`.

Here you will see that the drone will takeoff but won't execute the moveBy command. (If it does not move at all try executing it again)

When olympe sends a command message to the drone it expects an acknowledgement event message. Here `drone(TakeOff()).wait()` sends the `TakeOff()` command to the drone and then waits for the drone taking off event message. After TakeOff(), the flying state should be `FlyingStateChanged(state='takingoff')`. 

The problem with the command `moveBy()` is that it only works if the drone is in "hovering" state. Thus, in this case it is rejected because the drone is still in "takingoff" state. Furthermore, to correct this script, we will need it to wait for the drone to be in "hovering" state.
