# How to work with Olympe and Sphinx
In this directory, you will go through the procedures of controlling a drone in a simulator via python scripts.

We are referring from [this page](https://developer.parrot.com/docs/olympe/userguide.html).

This readme will only show brief things. For futher info, go to the page above.

## Write a python script
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

