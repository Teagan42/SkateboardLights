#include <avdweb_AnalogReadFast.h>

#include <MPU6050_tockn.h>
#include <Wire.h>

#include "Lights.h"

#define SENSOR_PIN A2

int isStopping = false;

MPU6050 mpu6050(Wire);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Wire.begin();
  mpu6050.begin();
  
  setupLights();
  pinMode(SENSOR_PIN, INPUT);
  //mpu6050.calcGyroOffsets(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = 0;
  FastLED.clear();

  if (isStopping) {
    turnLeft();
    braking();
  } else {
    turnRight();
    going();
  }

  FastLED.show();
  isStopping = !isStopping;

  light = analogReadFast(SENSOR_PIN);
  mpu6050.update();
  Serial.println("=======================================================");
  Serial.print("Light : ");
  Serial.println(light);
  Serial.print("temp : ");Serial.println(mpu6050.getTemp());
  Serial.print("accX : ");Serial.print(mpu6050.getAccX());
  Serial.print("\taccY : ");Serial.print(mpu6050.getAccY());
  Serial.print("\taccZ : ");Serial.println(mpu6050.getAccZ());

  Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
  Serial.print("\tgyroY : ");Serial.print(mpu6050.getGyroY());
  Serial.print("\tgyroZ : ");Serial.println(mpu6050.getGyroZ());

  Serial.print("accAngleX : ");Serial.print(mpu6050.getAccAngleX());
  Serial.print("\taccAngleY : ");Serial.println(mpu6050.getAccAngleY());
//  Serial.print("\taccAngleZ : ");Serial.println(mpu6050.getAccAngleZ());

  Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
  Serial.print("\tgyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
  Serial.print("\tgyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());
  
  Serial.print("angleX : ");Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");Serial.println(mpu6050.getAngleZ());
  Serial.println("=======================================================\n");

  delay(2000);
  
//  for (int i = 0; i < 2000; i++) {
//    light = analogReadFast(SENSOR_PIN);
//    Serial.print("Light : ");
//    Serial.println(light);
//
//    delay(1);
//  }
}
