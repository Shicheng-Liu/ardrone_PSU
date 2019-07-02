import olympe
from olympe.messages.ardrone3.Piloting import TakeOff

# drone = olympe.Drone("10.202.0.1")
drone = olympe.Drone("10.202.0.1", logfile=open("/tmp/olympe.log", "a+"))
drone.connection()
drone(TakeOff()).wait()
drone.disconnection()
