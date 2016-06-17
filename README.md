# About

This Library intended for the operation of AS1115 3 character LED 7 segment driver I²C Mini Module.

The intention of this library is to make use of the AS1115 3 character LED 7 segment driver I²C Mini Module with Particle development web IDE(build) as simple as possible for users.
###Developer information
NCD has been designing and manufacturing computer control products since 1995.  We have specialized in hardware design and manufacturing of Relay controllers for 20 years.  We pride ourselves as being the industry leader of computer control relay products.  Our products are proven reliable and we are very excited to support Particle.  For more information on NCD please visit www.controlanything.com

###Requirements
- AS1115 3 character LED 7 segment driver I²C Mini Module
- Particle Core/Photon module
- Knowledge base for developing and programming with Particle Core/Photon modules.

### Version
1.0.0

### How to use this library

The libary must be imported into your application.  This can be done through the Particle WEB IDE by selecting Libraries, then select the SEGMENTDRIVER.  Click Include in App button.  Select the App you want to include the library in.  Finally click Add to this app.  For more information see [Particle's documentation] [sparkIncludeLibrary].

This Library also has an example application which can be flashed directly to your Photon module by clicking the Use This Example button.  This example application will display your Particle Photon module's RSSI on the 3 character display.  It will also post the module's RSSI as a variable on the Particle cloud.
The example will post two functions to the particle cloud.  1 allowing the user to post a int value to the display from 0-999.  The second function allows the user to select the internal or external WiFi antenna, after this function is called the module will reboot.

### Example use

Once the Library is included in your applicaiton you should see an include statement at the top like this:
```cpp
//This #include statement was automatically added by the Particle IDE.
#include "SegmentDriver/SegmentDriver.h"
```

Now you need to instanciate an object of the library for use in your application like this:
```cpp
SegmentLEDDriver display;
```

Here is an example use case for the class(counts from 0 to 999):
```cpp
// This #include statement was automatically added by the Particle IDE.
#include "SegmentDriver/SegmentDriver.h"
SegmentLEDDriver display;

void setup() {
//Initialize 3 character display
display.init();
}

void loop() {
for(int i = 0; i < 1000; i++){
display..displayWriteInt(i);
delay(100);
}
}
```

###Public accessible methods
```cpp
void init();
```
>Must be called first before using the object.  This method sets required settings to the AS1115 3 character driver and returns true if setup of the driver is successful.  


```cpp
bool displayWriteInt(String val);
```
>This method accepts 1 int argument from 0-999 and displays that value on the 3 character display.  False is returned if there is an error communicating with the device.

```cpp
bool displayWriteInt(String val);
```
>This method accepts 1 String which should be a number from 0-999 and displays that value on the 3 character display.  False is returned if there is an error communicating with the device.


License
----

GNU
[sparkIncludeLibrary]:https://docs.particle.io/guide/getting-started/build/photon/
