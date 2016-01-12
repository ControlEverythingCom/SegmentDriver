// This #include statement was automatically added by the Particle IDE.
#include "SegmentDriver/SegmentDriver.h"

SegmentLEDDriver display;

//Particle cloud functions
int writeInt(String command);
int selectAntenna(String command);

int wifiRSSI;

int antennaSelection;

STARTUP(WiFi.selectAntenna(EEPROM.read(0) == 0 ? ANT_INTERNAL : ANT_EXTERNAL));

void setup() {
    antennaSelection = EEPROM.read(0);
    display.init();
    //Publish vairable and funcion to Particle Cloud
    Particle.function("WriteInt", writeInt);
    Particle.function("SelectAnt", selectAntenna);
    Particle.variable("RSSI", wifiRSSI);
}

void loop() {
    //Get RSSI and publish to cloud as variable
    wifiRSSI = WiFi.RSSI();
    //Convert RSSI value to positive value
    int rssi = wifiRSSI * -1;
    //display positive rssi reading to display
    display.displayWriteInt(rssi);
    Serial.println(rssi);
    delay(1000);
}

//Function to write to display from Particle Cloud Function
int writeInt(String command){
    if(!display.displayWriteInt(command)){
        return 0;
    }
    return 1;
}

//Function to select antenna
int selectAntenna(String command){
    if(command.equalsIgnoreCase("External")){
        EEPROM.write(0,1);
        System.reset();
    }
    if(command.equalsIgnoreCase("Internal")){
        EEPROM.write(0,0);
        System.reset();
    }
    return 0;
}