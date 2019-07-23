How to make the drone Circle
=============================
We can use the function _Circle()_ to make the drone circle. Refer <a href="https://developer.parrot.com/docs/olympe/arsdkng_ardrone3_piloting.html?highlight=circle#olympe.messages.ardrone3.Piloting.Circle" rel="nofollow noopener">Circle</a>
<br>
<br> The function _Circle()_ can only be applied to a fixed-wing drone(to be specific, DISCO only).
<br> Like Bebop, DISCO needs different commands to simulate in Parrot-Sphinx:
<br>`sudo systemctl start firmwared`
<br>`sphinx /opt/parrot-sphinx/usr/share/sphinx/drones/disco.drone::stolen_interface=::simple_front_cam=true`
<br>
<br> Start the Olympe environment:
<br>`source ~/code/parrot-groundsdk/./products/olympe/linux/env/shell`
<br>Then, install a jsonrpc client library in your python environment :
<br> `(olympe-python3) $ pip3 install jsonrpclib-pelix`
<br> From your script, use the jsonrpclib module to trigger the “fixedwings_shake/handling” action :
 <br>       import jsonrpclib  
<br>    import olympe
<br>    import olympe_deps as od
<br>    from olympe.messages.ardrone3.Piloting import TakeOff

<br>    sphinx_client = jsonrpclib.Server("http://127.0.0.1:8383")
<br>    drone = olympe.Drone("10.202.0.1", od.ARSDK_DEVICE_TYPE_EVINRUDE)
<br>    drone.connection()
<br>    sphinx_client.TriggerAction(
<br>        machine="disco",   # this should match the drone name in the .drone file
    <br>    object="fixedwings_shake/handling",
   <br>    action="start"
<br>    )
<br>    drone(TakeOff()).wait()```
