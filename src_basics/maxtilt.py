from __future__ import print_function
import olympe
from olympe.messages.ardrone3.PilotingSettings import MaxTilt

drone = olympe.Drone("10.202.0.1")
drone.connection()
maxTiltAction = drone(MaxTilt(10)).wait()
if maxTiltAction.success():
    print("MaxTilt(10) success")
elif maxTiltAction.timedout():
    print("MaxTilt(10) success")
else:
    # If ".wait()" is called on the _maxTiltAction_ this shouldn't happen
    print("MaxTilt(10) is still in progress")
maxTiltAction = drone(MaxTilt(1)).wait()
if maxTiltAction.success():
    print("MaxTilt(1) success")
elif maxTiltAction.timedout():
    print("MaxTilt(1) timedout")
else:
    # If ".wait()" is called on the _maxTiltAction_ this shouldn't happen
    print("Maxtilt(1) is still in progress")
drone.disconnection()
