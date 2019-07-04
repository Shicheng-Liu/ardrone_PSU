import olympe
from olympe.messages.ardrone3.PilotingState import FlyingStateChanged
from olympe.enums.ardrone3.PilotingState import FlyingStateChanged_State as FlyingState
from olympe.messages.ardrone3.Piloting import TakeOff, moveBy, Landing

drone = olympe.Drone("10.202.0.1", loglevel=2)
drone.connection()

flying_states = FlyingState._bitfield_type_("takingoff|hovering|flying")

print("Drone about to take off!")

drone(
    TakeOff()
    >> FlyingStateChanged(state="hovering", _timeout=5)
).wait()

if drone.get_state(FlyingStateChanged)["state"] in flying_states:
    print("The drone is in flight")
else:
    print("The drone is not in flight")

drone(
    # Parameters are as follow (dx[m], dy[m], dz[m], dPsi[rad], timeout(default 20)) Two more but refer to README)
    moveBy(4, 2, 0, 1)
    >> FlyingStateChanged(state="hovering", _timeout=5)
).wait()

print("Drone landing...")
drone(Landing()).wait()

print("Drone landed!")
print("Drone taking off...")
drone(
    TakeOff()
    >> FlyingStateChanged(state="hovering", _timeout=5)
).wait()

print("Drone moving...")
drone(
    moveBy(-4, -2, 0, 0)
    >> FlyingStateChanged(state="hovering", _timeout=5)
).wait()

print("Drone landing...")
drone(Landing()).wait()
drone.disconnection()
