Use Node.js to control Ardrone2
==================================
You need to downlaod the folder _ardrone_module_ and the files _repl.js_ and _first_try.js_ in your home directory. Then, install _Node.js_ and _npm_ and everything will work.
<br> Node.js can work on both Linux and Windows, and now we run on Ubuntu.

Node.js and npm installation
----------
You may have installed Node.js and npm already, then you can see the version of them.
<br> `node -v`
<br> `npm -v`
<br> If your Node.js and npm work well, please move to the next part in this readme **Make it fly**
<br> **But**  if you only have node, I recommend you to uninstall your node and install the latest version of Node.js and npm, or you may meet trouble while installing npm.
First step, unistall your Node.js(If you do not have Node installed on your computer, just skip this step)
<br>`sudo apt-get remove --purge npm`
<br> `sudo apt-get remove --purge nodejs`
<br>`sudo apt-get remove --purge nodejs-legacy`
<br> `sudo apt-get autoremove`
<br> You also need to delete several packages:
<br> `rm -r /usr/local/bin/npm`
<br> `rm -r /usr/local/lib/node-moudels`
<br> ` find / -name npm`
<br> `rm -r /tmp/npm*`
<br> Second step, install the latest version of Node.js and npm:
<br> `curl -sL https://deb.nodesource.com/setup_8.x | sudo -E bash -` 
<br> If you do not have curl, please install.
<br> `sudo apt-get install nodejs`
<br> Now, you have successfully installed, to see the version:
<br> `node -v`
<br> `npm -v`
<br>

Make it fly
--
Now you have all requirements setup, just turn on a terminal, Connect with your ardrone's WIFI
<br> `node repl.js`
<br> Then you can control simply, just choose the following commands:
<br> `takeoff(), land(), front(), back(), left(), right(), clockwise(), counterClockwise(), up(), down()`
<br> These commands show their meaning clearly, so I will not explain again.
<br> **NOTE**: Except the first two commands, the rest eight commands need speed parameter that ranges from 0 to 1. For example, if you want the drone to move forward, type in _front(0.05)_. The drone flies fast so make sure your parameter is small and 0.05 is enough. But if your space is large, you can increase it. Now, your drone is flying forward, _front(0)_ can make it stop. The other seven commands are the same.
<br> Also, if you want control it automatically, you can create a node script and run it. 
<br> Here is a script, open your terminal, connect with the WIFI and type in `node first_try.js`. You will see the drone takeoff, move forward for a while, then backward, clockwise and land.
<br> If you want to write your own script, you can refer _first_try.js_.
<br>
<br>
<br> Reference: https://github.com/felixge/node-ar-drone
