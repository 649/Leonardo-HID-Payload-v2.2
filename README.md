## ARDUINO LEONARDO HID PAYLOAD v2.2
 
Human Interface Device Payload that allows your Arduino Leonardo board to execute commands with elevated privileges. Methods of activating and obfuscating the command prompt interface while code is being executed is listed in comments within the code. Feel free to modify the delay times for your own calibration. An optional LED switch is also hard coded (uses pins 7 & 8) for payload execution completion. Future versions will use an LCD interface mounted to the Leonardo itself.

## What's New

- Added button execution (payload will only start once a button is pushed)
- Added command deletion (gets rid of exec history upon exiting)
- Better method of bypassing UAC
- Better method for launching CMD RunAs (before used Windows search, now it's straight from powershell)
- Code is much shorter and much more efficient
- Delay times are calibrated for faster execution