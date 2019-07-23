Use Node.js to control Ardrone2
==================================
You need to downlaod the folder _ardrone_module_ and the files _repl.js_ and _first_try.js_ in your home directory. Then, install _Node.js_ and _npm_ and everything will work.
<br> **NOTE**: You may have cloned all this repository before, once you have downloaded the whole repository, please copy the folder _ardrone_module_ and the files _repl.js_ and _first_try.js_, and paste in your home directory. <br>**THE MOST IMPORTANT**: change the name of foldler _ardrone_module_ to _node_modules_, otherwise it cannot work.
<br> Node.js can work on both Linux and Windows, and now we run on Ubuntu.

Node.js and npm installation
----------
You may have installed Node.js and npm already, then you can see the version of them.
```
node -v
npm -v
```
 If your Node.js and npm work well, please move to the next part in this readme **Make it fly**
<br> **But**  if you only have node, I recommend you to uninstall your node and install the latest version of Node.js and npm, or you may meet trouble while installing npm.
<br> **First step**, unistall your Node.js(If you do not have Node installed on your computer, just skip this step)
```
sudo apt-get remove --purge npm
sudo apt-get remove --purge nodejs
sudo apt-get remove --purge nodejs-legacy
sudo apt-get autoremove
```
You also need to delete several packages:
```
rm -r /usr/local/bin/npm
rm -r /usr/local/lib/node-moudels
find / -name npm
rm -r /tmp/npm*
```
 **Second step**, install the latest version of Node.js and npm:
 ```
curl -sL https://deb.nodesource.com/setup_8.x | sudo -E bash -
```
 If you do not have `curl`, please install. After you have installed `curl`, you can run the code below:
```
sudo apt-get install nodejs
```
Now, you have successfully installed, to see the version:
```
node -v
npm -v
```
<br>

Make it fly
--
Now you have all requirements setup, just turn on a terminal, Connect with your ardrone's WIFI
```
node repl.js
```
Then you can control simply, just choose the following commands:
```
takeoff(), land(), front(), back(), left(), right(), clockwise(), counterClockwise(), up(), down()
```
These commands show their meaning clearly, so I will not explain again.
<br>
<br> **NOTE**: Except the first two commands, the rest eight commands need speed parameter that ranges from 0 to 1. For example, if you want the drone to move forward, type in _front(0.05)_. The drone flies fast so make sure your parameter is small and 0.05 is enough. But if your space is large, you can increase it. Now, your drone is flying forward, _front(0)_ can make it stop. The other seven commands are the same.
<br>
<br> Also, if you want control it automatically, you can create a node script and run it. 
<br> Here is a script, open your terminal, connect with the WIFI and type in `node first_try.js`. You will see the drone takeoff, move forward for a while, then backward, clockwise and land.
<br> If you want to write your own script, you can refer [first_try.js](https://github.com/Shicheng-Liu/parrot_PSU/blob/master/control%20a%20physical%20drone/Node.js/first_try.js).
<br>
<br>
<br> Reference: https://github.com/felixge/node-ar-drone
