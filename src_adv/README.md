# Advanced Usages
In this directory, we will go through advanced methods and commands of parrot-Olympe.
Refer to [here](https://developer.parrot.com/docs/olympe/arsdkng.html#messages-reference-documentation) for documentations of each features.
You could also look into multiple methods by using the interactive python development, `ipython`. In the olympe shell environment, do as follow.
```
(olympe-python3) $ ipython
In [1]: import olympe                                                                                

In [2]: from olympe.messages.<TAB>
    olympe.messages.animation       olympe.messages.common          olympe.messages.follow_me
    olympe.messages.ardrone3        olympe.messages.controller_info olympe.messages.generic
    olympe.messages.battery         olympe.messages.debug           olympe.messages.gimbal
    olympe.messages.camera          olympe.messages.drone_manager   olympe.messages.jpsumo

In [3]: from olympe.messages.ardrone3 import  
    AccessoryState        Camera                GPSState              
    MediaStreaming        NetworkSettingsState  PictureSettingsState  
    PilotingSettingsState SoundState            Animations

In [4]: from olympe.messages.ardrone3.Piloting import TakeOff
In [5]: help(TakeOff)
Help on ardrone3.Piloting.TakeOff object:

class ardrone3.Piloting.TakeOff(ArsdkMessage)
|  Ardrone3.Piloting.TakeOff
|  
|  
|  
|  Ask the drone to take off. On the fixed wings (such as Disco): not
|  used except to cancel a land.
|  
|  :param _timeout: command message timeout (defaults to 10)
|  :type _timeout: int
|  :param _no_expect: if True for,do not expect the usual command expectation (defaults to False)
|  :type _no_expect: bool
|  :param _float_tol: specify the float comparison tolerance, a 2-tuple containing a relative tolerance float value and an absolute tolerate float value (default to (1e-07, 1e-09)). See python 3 stdlib `math.isclose` documentation for more information
|  :type _float_tol: `tuple`
|  
|  
|  **Result**: On the quadcopters: the drone takes off if its :py:func:`FlyingStateChanged()<olympe.messages.ardrone3.PilotingState.FlyingStateChanged>`
|  was landed. On the fixed wings, the landing process is aborted if the
|  :py:func:`FlyingStateChanged()<olympe.messages.ardrone3.PilotingState.FlyingStateChanged>` was landing. Then, event :py:func:
```

Now you should be able to write your own scripts. We will provide some advanced usages in this directory.
