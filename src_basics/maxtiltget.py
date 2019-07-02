from __future__ import print_function
import olympe
from olympe.messages.ardrone3.PilotingSettingsState import MaxTiltChanged

# drone = olympe.Drone("10.202.0.1")
drone = olympe.Drone("10.202.0.1", logfile=open("/tmp/olympe_gettilt.log", "a+"))
drone.connection()
print("Drone MaxTilt = ", drone.get_state(MaxTiltChanged)["current"])
drone.disconnection()
