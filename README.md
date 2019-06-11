# parrot_PSU
Documenting and some works for the parrot_PSU

# System worked on
* Ubuntu 16.04
* OpenGL 4.6.0 NVIDIA 390.87
* Parrot-Sphinx 1.2.1
* Parrot-Olympe 1.0.0

# Parrot-Olympe
This is a SDK for working with remotely controlling the drones. It works with Python.

## Installing Procedure
Olympe is part of the parrot-groundsdk. Thus, we will clone that workspace first by using repo.

__NOTE:__ If you don't have the utility tool "repo" installed just do `sudo apt-get install repo`.

### Create and clone repo
Create your groundsdk repo anywhere.
```
cd <desired_workspace>
mkdir -p parrot-groundsdk
repo init -u https://github.com/Parrot-Developers/groundsdk-manifest.git
repo sync
```

### Installing olympe-linux dependencies
You can install the needed packages through the script they provided. It is located at `<your_working_repo>/parrot-groundsdk/products/olympe/linux/env/postinst`. However, this script will upgrade and install multiple packages. 

Thus, if you're consirned about this, I recommend you to manually install each repo's listed in this script.

__NOTE:__ This script must be run from the root directory of the workspace. 

### Build olympe-linux
This repo will be needed to (re)built after each _repo sync_.

The following command will be the build command. This will need to be executed from the root of the workspace.

```
./build.sh -p olympe-linux -A all final -j
```

### Set up the environment
Whenever you would like to execute an Olympe script, you will need to run it from the shell environment. The following command will create one.
```
source ./products/olympe/linux/env/shell
```

This shell script can be executed outside of the workspace, the following command is an example:
```
source ~/<your_workspace>/parrot-groundsdk/./products/olympe/linux/env/shell
```
I recommend you to write this command down in the .bashrc or .bash_alias file as another command such as `shellOlympe` to save time.

#### Check your installation
In the shell environment you've created in the previous step, you can check if the installation was successfull by the following command.
```
python -c 'import olympe; print("Installation OK")'
```
If it is surely ok, you should receive a return saying `Installation OK`.

#### Execute a script
In the shell environment you've created in the previous step, you can execute an olympe script as follow.
```
python your_olympe_script.py
```

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
__NOTE:__ You will be asked to add users from firmwared. Enter the username you are logged in as and once the installation has completed, make sure to log out and back in to complete the installation.

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

__NOTE:__ For the initial run of each drone, it may take a while to start up.

Once simulation has started up, you will see your drone sitting at the origin of the gazebo simulator.

## Next step...!
Now move onto the src directory where you will launch the simulator and write a python script to control the drone there.
