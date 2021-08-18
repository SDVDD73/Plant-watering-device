#include "SoilSensor.h"
#include "GyverPower.h"
//Soil Sensor 235(wet)-400(dry)

#define  SENSOR1   A2
#define  SENSOR2   A3
#define  SENSOR3   A4
#define  SENSOR4   A5
#define  SENSOR5   A6
#define  SENSOR6   A7
#define  soli_sensor_power_pin 9 //  Common soli sensor power pin
//Water motor
#define pin_water_motor1 7
#define pin_water_motor2 6
#define pin_water_motor3 5
#define pin_water_motor4 4
#define pin_water_motor5 3
#define pin_water_motor6 2

#define time_watering 6000
#define min_value_watering 235
#define max_value_watering 400

//
#define time_break 43200000
#define sensor_warering_value 680

SoilSensor soilSensor1;
SoilSensor soilSensor2;
SoilSensor soilSensor3;
SoilSensor soilSensor4;
SoilSensor soilSensor5;
SoilSensor soilSensor6;

#define soilSensorsSize 6
SoilSensor soilSensors[soilSensorsSize] = {soilSensor1, soilSensor2, soilSensor3, soilSensor4, soilSensor5, soilSensor6};
int water_motor_pins[soilSensorsSize] = {pin_water_motor1, pin_water_motor2, pin_water_motor3, pin_water_motor4, pin_water_motor5, pin_water_motor6};;


void setup() {
  power.setSleepMode(POWERDOWN_SLEEP);

  initSoilSensors();
  initPinWaterMotors();

  //Serial.begin(9600);
  //Serial.println("Start");

  delay(50);
}

void loop() {
  power.autoCalibrate();

  for (int index_soil_sensor = 0; index_soil_sensor < soilSensorsSize; index_soil_sensor++) {
    int soil = soilSensors[index_soil_sensor].readSoilValue();

    //Serial.print(index_soil_sensor);
    //Serial.print(" ");
    //Serial.print(soil);
    //Serial.println();
    if (soil >= sensor_warering_value) {
      int water_motor_pin = water_motor_pins[index_soil_sensor];
      turn_on_watering(water_motor_pin);
    }
  }

  //delay(2000);
  power.sleepDelay(time_break);
}

void turn_on_watering(int pin_pomp) {

  digitalWrite(pin_pomp, HIGH);
  delay(time_watering);
  digitalWrite(pin_pomp, LOW);
}

void initSoilSensors() {
  soilSensors[0].initSensor(SENSOR1, soli_sensor_power_pin);
  soilSensors[1].initSensor(SENSOR2, soli_sensor_power_pin);
  soilSensors[2].initSensor(SENSOR3, soli_sensor_power_pin);
  soilSensors[3].initSensor(SENSOR4, soli_sensor_power_pin);
  soilSensors[4].initSensor(SENSOR5, soli_sensor_power_pin);
  soilSensors[5].initSensor(SENSOR6, soli_sensor_power_pin);
}

void initPinWaterMotors() {
  pinMode(pin_water_motor1, OUTPUT);
  digitalWrite(pin_water_motor1, LOW);

  pinMode(pin_water_motor2, OUTPUT);
  digitalWrite(pin_water_motor2, LOW);

  pinMode(pin_water_motor3, OUTPUT);
  digitalWrite(pin_water_motor3, LOW);

  pinMode(pin_water_motor4, OUTPUT);
  digitalWrite(pin_water_motor4, LOW);

  pinMode(pin_water_motor5, OUTPUT);
  digitalWrite(pin_water_motor5, LOW);

  pinMode(pin_water_motor6, OUTPUT);
  digitalWrite(pin_water_motor6, LOW);
}
