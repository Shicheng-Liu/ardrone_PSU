# parrot_PSU
Documenting and some works for the parrot_PSU

# System worked on
* Ubuntu 16.04
* OpenGL 4.6.0 NVIDIA 390.87
* Parrot-Sphinx 1.2.1
* Parrot-Olympe 1.0.0

# Parrot-Sphinx
## Installation Procedure
Refer to [here](https://developer.parrot.com/docs/sphinx/installation.html)

### Add new apt repository
Setup your computer to accept packages from Parrot's public server.
```
echo "deb'http://plf.parrot.com/sphinx/binary `lsb_release -cs`/" | sudo tee /etc/apt/sources.list.d/sphinx.list > /dev/null
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 508B1AE5
```

### Install the packages
```
sudo apt-get update
sudo apt-get install parrot-sphinx
```
NOTE! You will be asked to add users from firmwared. Enter the username you are logged in as and once the installation has completed, make sure to log out and back in to complete the installation.

## Initial Step
### Firmwared
Launch systemd as follow.
```
sudo systemctl start firmwared.service
```

In a case where you reboot/started your computer, you will need to restart the firmwared service.

#### Check that firmwared is alive
Enter the following command:
```
fdc ping
```

Then you should be returned with `PONG` in response. Otherwise, refer to [troubleshooting](https://developer.parrot.com/docs/sphinx/troubleshooting.html).

### Check your wifi interface name
Enter the following command:
```
iwconfig
```
and remember the host wifi interface name.

Or you could connect to your drones via bluetooth. In this case refer to the coming steps.

### Launch your first simulation
The .drone files (where it contains the information of each drone) are located under `/opt/parrot-sphinx/usr/share/sphinx/drones/`. Start with any but here we are starting with mambo for example. Start up sphinx with the drone as follow.
```
sphinx /opt/parrot-sphinx/usr/share/sphinx/drones/mambo.drone
```

To override the interface name, do as follow.
```
sphinx /opt/parrot-sphinx/usr/share/sphinx/drones/anafi4k.drone::stolen_interface=<your_interface_name>:eth0:192.168.42.1/24
```

NOTE: For the initial run of each drone, it may take a while to start up.

Once simulation has started up, you will see your drone sitting at the origin of the gazebo simulator.

