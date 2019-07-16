import jsonrpclib
import olympe
import olympe_deps as od
from olympe.messages.ardrone3.Piloting import TakeOff

sphinx_client = jsonrpclib.Server("http://127.0.0.1:8383")
drone = olympe.Drone("10.202.0.1", od.ARSDK_DEVICE_TYPE_EVINRUDE)
drone.connection()
sphinx_client.TriggerAction(
    machine="disco",   # this should match the drone name in the .drone file
    object="fixedwings_shake/handling",
    action="start"
)
drone(TakeOff()).wait()
