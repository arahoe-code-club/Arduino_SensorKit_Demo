# Arduino_SensorKit_Demo
Custom Arduino Sensor Kit Demo for code club students.

## Components Used
- Sound Microphone                      (A2 pin)
- Light Sensor                          (A3 pin)
- DHT Temperature and Humidity Sensor   (D3 pin)
- Pressure Sensor                       (I2C)
- Accelerometer                         (I2C)
- 128x64 pixel Oled                     (I2C)

## I2C Notes
I2C allows multiple devices to communicate using the same data lines.

Each device is given an address code, and a controller device sends to and receives data from each device, using the address codes to know which it is receiving from, and to send commands to the correct devices.

Due to a hardware design fault in the Oled, it cannot usually work when other I2C devices are being used. A workaround solution to make it work has been used in the code, study it carefully to understand what is happening.

## Sensor Readout Notes
- Temperature is in Celsius
- Humidity is a percentage (%)
- Sound meter is converted to a percentage (%) using the map() function
- Light level is a percentage (%)
- Acceleration is given in 3 axis components relative to the orientation of the component board. Read the Sensor Kit documentation to understand better. Experiment with holding the component board in different orientations and checking the readouts.
- Acceleration units are PROBABLY in meters per second per second (ms^-2)

## Future changes
- introduce button, readouts will not be shown until the button is pressed
- introduce LED, to light up when button is pressed
- introduce potentiometer, to readout as a percentage (%) of how high the resistance is
- introduce Buzzer, to play a tone when the button is pressed

## Project challenges
- Make the temperature readout as Fahrenheit (F)
- Make the LED only light up if the microphone detects a loud sound, or the true acceleration magnitude is high enough, or something else in relation to other sensors.
- Make the OLED show readouts in a sideways orientation (check the setFlipMode() method)
- Make acceleration readouts in feet per second per second, or yards, or other Imperial distance measurements
- Make turning the potentiometer change the loudness or pitch of the buzzer
