import olympe
import olympe_deps as od
from olympe.messages.ardrone3.Piloting import TakeOff, moveBy, Landing
from olympe.messages.ardrone3.PilotingState import FlyingStateChanged
from olympe.messages.ardrone3.Animations import Flip
drone = olympe.Drone("10.202.0.1",drone_type=od.ARSDK_DEVICE_TYPE_BEBOP_2)
drone.connection()
drone(
    TakeOff()
    >> FlyingStateChanged(state="hovering", _timeout=5)
).wait()
drone(
    moveBy(5, 5, 0, 0)
    >> FlyingStateChanged(state="hovering", _timeout=5)
).wait()
drone(
    Flip(0,_timeout=5, _no_expect=False, _float_tol=(1e-07, 1e-09))
    >> FlyingStateChanged(state="hovering", _timeout=5)
).wait()
drone(Landing()).wait()
drone.disconnection()
