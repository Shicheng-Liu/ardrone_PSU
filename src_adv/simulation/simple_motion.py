import olympe
from olympe.messages.ardrone3.PilotingState import FlyingStateChanged
from olympe.enums.ardrone3.PilotingState import FlyingStateChanged_State as FlyingState
from olympe.messages.ardrone3.Piloting import TakeOff, moveBy, Landing

drone = olympe.Drone("10.202.0.1", loglevel=2)
drone.connection()

flying_states = FlyingState._bitfield_type_("takingoff|hovering|flying")

drone(
    TakeOff()
    >> FlyingStateChanged(state="hovering", _timeout=5)
).wait()

if drone.get_state(FlyingStateChanged)["state"] in flying_states:
    print("The drone is in flight")
else:
    print("The drone is not in flight")

drone(Landing()).wait()
drone.disconnection()
