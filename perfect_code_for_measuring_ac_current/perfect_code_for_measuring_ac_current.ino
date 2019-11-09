// ACS712 AC/DC Current Sensor
//
// This version adapted from the libraries here:
//    https://github.com/rkoptev/ACS712-arduino
//    https://github.com/muratdemirtas/ACS712-arduino-1
//
// Added inputs to switch between AC or DC measurement mode
// as well as to perform offset zero calibration when ready
// (when there is no current flowing through the sensor)
//
// Gadget Reboot

#include "ACS712.h"

#define sensorInput A0  // sensor connects to analog 0 

// Sensor options:  ACS712_05B = 5 amp, ACS712_20A = 20 amp, ACS712_30A = 30 amp
ACS712 sensor(ACS712_30A, sensorInput);

void setup() {
  Serial.begin(9600);
Serial.println("Calibrating... there must be no current flow through sensor during calibration.");
    sensor.calibrate();
    Serial.println("Done!");
}

void loop() {

  float currentReading;
    

  currentReading = sensor.getCurrentAC(50);   // measure AC current at specified frequency (Hz)
  Serial.print("I = ");
  Serial.print(currentReading);
  Serial.print(" A");
  Serial.println(" AC");

  delay(1000);
}
