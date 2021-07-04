#include "SoilSensor.h"
#include "GyverPower.h"
//Soil Sensor 235(wet)-400(dry)

#define  SENSOR1   A2                    //   Р В РЎвЂєР В РЎвЂ”Р РЋР вЂљР В Р’ВµР В РўвЂ�Р В Р’ВµР В Р’В»Р РЋР РЏР В Р’ВµР В РЎпїЅ Р В Р вЂ¦Р В РЎвЂўР В РЎпїЅР В Р’ВµР РЋР вЂљ Р В Р’В°Р В Р вЂ¦Р В Р’В°Р В Р’В»Р В РЎвЂўР В РЎвЂ“Р В РЎвЂўР В Р вЂ Р В РЎвЂўР В РЎвЂ“Р В РЎвЂў Р В Р вЂ Р РЋРІР‚В¦Р В РЎвЂўР В РўвЂ�Р В Р’В°, Р В РЎвЂќ Р В РЎвЂќР В РЎвЂўР РЋРІР‚С™Р В РЎвЂўР РЋР вЂљР В РЎвЂўР В РЎпїЅР РЋРЎвЂњ Р В РЎвЂ”Р В РЎвЂўР В РўвЂ�Р В РЎвЂќР В Р’В»Р РЋР вЂ№Р РЋРІР‚РЋР В Р’ВµР В Р вЂ¦ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ Р В Р вЂ Р В Р’В»Р В Р’В°Р В Р’В¶Р В Р вЂ¦Р В РЎвЂўР РЋР С“Р РЋРІР‚С™Р В РЎвЂ� Р В РЎвЂ”Р В РЎвЂўР РЋРІР‚РЋР В Р вЂ Р РЋРІР‚в„–
#define  SENSOR2   A3                     //   Р В РЎвЂєР В РЎвЂ”Р РЋР вЂљР В Р’ВµР В РўвЂ�Р В Р’ВµР В Р’В»Р РЋР РЏР В Р’ВµР В РЎпїЅ Р В Р вЂ¦Р В РЎвЂўР В РЎпїЅР В Р’ВµР РЋР вЂљ Р В Р’В°Р В Р вЂ¦Р В Р’В°Р В Р’В»Р В РЎвЂўР В РЎвЂ“Р В РЎвЂўР В Р вЂ Р В РЎвЂўР В РЎвЂ“Р В РЎвЂў Р В Р вЂ Р РЋРІР‚В¦Р В РЎвЂўР В РўвЂ�Р В Р’В°, Р В РЎвЂќ Р В РЎвЂќР В РЎвЂўР РЋРІР‚С™Р В РЎвЂўР РЋР вЂљР В РЎвЂўР В РЎпїЅР РЋРЎвЂњ Р В РЎвЂ”Р В РЎвЂўР В РўвЂ�Р В РЎвЂќР В Р’В»Р РЋР вЂ№Р РЋРІР‚РЋР В Р’ВµР В Р вЂ¦ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ Р В Р вЂ Р В Р’В»Р В Р’В°Р В Р’В¶Р В Р вЂ¦Р В РЎвЂўР РЋР С“Р РЋРІР‚С™Р В РЎвЂ� Р В РЎвЂ”Р В РЎвЂўР РЋРІР‚РЋР В Р вЂ Р РЋРІР‚в„–
#define  SENSOR3   A4                     //   Р В РЎвЂєР В РЎвЂ”Р РЋР вЂљР В Р’ВµР В РўвЂ�Р В Р’ВµР В Р’В»Р РЋР РЏР В Р’ВµР В РЎпїЅ Р В Р вЂ¦Р В РЎвЂўР В РЎпїЅР В Р’ВµР РЋР вЂљ Р В Р’В°Р В Р вЂ¦Р В Р’В°Р В Р’В»Р В РЎвЂўР В РЎвЂ“Р В РЎвЂўР В Р вЂ Р В РЎвЂўР В РЎвЂ“Р В РЎвЂў Р В Р вЂ Р РЋРІР‚В¦Р В РЎвЂўР В РўвЂ�Р В Р’В°, Р В РЎвЂќ Р В РЎвЂќР В РЎвЂўР РЋРІР‚С™Р В РЎвЂўР РЋР вЂљР В РЎвЂўР В РЎпїЅР РЋРЎвЂњ Р В РЎвЂ”Р В РЎвЂўР В РўвЂ�Р В РЎвЂќР В Р’В»Р РЋР вЂ№Р РЋРІР‚РЋР В Р’ВµР В Р вЂ¦ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ Р В Р вЂ Р В Р’В»Р В Р’В°Р В Р’В¶Р В Р вЂ¦Р В РЎвЂўР РЋР С“Р РЋРІР‚С™Р В РЎвЂ� Р В РЎвЂ”Р В РЎвЂўР РЋРІР‚РЋР В Р вЂ Р РЋРІР‚в„–
#define  SENSOR4   A5                     //   Р В РЎвЂєР В РЎвЂ”Р РЋР вЂљР В Р’ВµР В РўвЂ�Р В Р’ВµР В Р’В»Р РЋР РЏР В Р’ВµР В РЎпїЅ Р В Р вЂ¦Р В РЎвЂўР В РЎпїЅР В Р’ВµР РЋР вЂљ Р В Р’В°Р В Р вЂ¦Р В Р’В°Р В Р’В»Р В РЎвЂўР В РЎвЂ“Р В РЎвЂўР В Р вЂ Р В РЎвЂўР В РЎвЂ“Р В РЎвЂў Р В Р вЂ Р РЋРІР‚В¦Р В РЎвЂўР В РўвЂ�Р В Р’В°, Р В РЎвЂќ Р В РЎвЂќР В РЎвЂўР РЋРІР‚С™Р В РЎвЂўР РЋР вЂљР В РЎвЂўР В РЎпїЅР РЋРЎвЂњ Р В РЎвЂ”Р В РЎвЂўР В РўвЂ�Р В РЎвЂќР В Р’В»Р РЋР вЂ№Р РЋРІР‚РЋР В Р’ВµР В Р вЂ¦ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ Р В Р вЂ Р В Р’В»Р В Р’В°Р В Р’В¶Р В Р вЂ¦Р В РЎвЂўР РЋР С“Р РЋРІР‚С™Р В РЎвЂ� Р В РЎвЂ”Р В РЎвЂўР РЋРІР‚РЋР В Р вЂ Р РЋРІР‚в„–
#define  SENSOR5   A6                     //   Р В РЎвЂєР В РЎвЂ”Р РЋР вЂљР В Р’ВµР В РўвЂ�Р В Р’ВµР В Р’В»Р РЋР РЏР В Р’ВµР В РЎпїЅ Р В Р вЂ¦Р В РЎвЂўР В РЎпїЅР В Р’ВµР РЋР вЂљ Р В Р’В°Р В Р вЂ¦Р В Р’В°Р В Р’В»Р В РЎвЂўР В РЎвЂ“Р В РЎвЂўР В Р вЂ Р В РЎвЂўР В РЎвЂ“Р В РЎвЂў Р В Р вЂ Р РЋРІР‚В¦Р В РЎвЂўР В РўвЂ�Р В Р’В°, Р В РЎвЂќ Р В РЎвЂќР В РЎвЂўР РЋРІР‚С™Р В РЎвЂўР РЋР вЂљР В РЎвЂўР В РЎпїЅР РЋРЎвЂњ Р В РЎвЂ”Р В РЎвЂўР В РўвЂ�Р В РЎвЂќР В Р’В»Р РЋР вЂ№Р РЋРІР‚РЋР В Р’ВµР В Р вЂ¦ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ Р В Р вЂ Р В Р’В»Р В Р’В°Р В Р’В¶Р В Р вЂ¦Р В РЎвЂўР РЋР С“Р РЋРІР‚С™Р В РЎвЂ� Р В РЎвЂ”Р В РЎвЂўР РЋРІР‚РЋР В Р вЂ Р РЋРІР‚в„–
#define  SENSOR6   A7                     //   Р В РЎвЂєР В РЎвЂ”Р РЋР вЂљР В Р’ВµР В РўвЂ�Р В Р’ВµР В Р’В»Р РЋР РЏР В Р’ВµР В РЎпїЅ Р В Р вЂ¦Р В РЎвЂўР В РЎпїЅР В Р’ВµР РЋР вЂљ Р В Р’В°Р В Р вЂ¦Р В Р’В°Р В Р’В»Р В РЎвЂўР В РЎвЂ“Р В РЎвЂўР В Р вЂ Р В РЎвЂўР В РЎвЂ“Р В РЎвЂў Р В Р вЂ Р РЋРІР‚В¦Р В РЎвЂўР В РўвЂ�Р В Р’В°, Р В РЎвЂќ Р В РЎвЂќР В РЎвЂўР РЋРІР‚С™Р В РЎвЂўР РЋР вЂљР В РЎвЂўР В РЎпїЅР РЋРЎвЂњ Р В РЎвЂ”Р В РЎвЂўР В РўвЂ�Р В РЎвЂќР В Р’В»Р РЋР вЂ№Р РЋРІР‚РЋР В Р’ВµР В Р вЂ¦ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ Р В Р вЂ Р В Р’В»Р В Р’В°Р В Р’В¶Р В Р вЂ¦Р В РЎвЂўР РЋР С“Р РЋРІР‚С™Р В РЎвЂ� Р В РЎвЂ”Р В РЎвЂўР РЋРІР‚РЋР В Р вЂ Р РЋРІР‚в„–
#define  Vcc      A1                      //   Р В РЎвЂєР В РЎвЂ”Р РЋР вЂљР В Р’ВµР В РўвЂ�Р В Р’ВµР В Р’В»Р РЋР РЏР В Р’ВµР В РЎпїЅ Р В Р вЂ¦Р В РЎвЂўР В РЎпїЅР В Р’ВµР РЋР вЂљ Р В Р вЂ Р РЋРІР‚в„–Р В Р вЂ Р В РЎвЂўР В РўвЂ�Р В Р’В°, Р В РЎвЂўР РЋРІР‚С™ Р В РЎвЂќР В РЎвЂўР РЋРІР‚С™Р В РЎвЂўР РЋР вЂљР В РЎвЂўР В РЎвЂ“Р В РЎвЂў Р В Р’В·Р В Р’В°Р В РЎвЂ”Р В РЎвЂ�Р РЋРІР‚С™Р В Р’В°Р В Р вЂ¦ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ (Р В Р вЂ Р РЋРІР‚в„–Р В Р вЂ Р В РЎвЂўР В РўвЂ� Vcc)
#define  GND      A0                      //   Р В РЎвЂєР В РЎвЂ”Р РЋР вЂљР В Р’ВµР В РўвЂ�Р В Р’ВµР В Р’В»Р РЋР РЏР В Р’ВµР В РЎпїЅ Р В Р вЂ¦Р В РЎвЂўР В РЎпїЅР В Р’ВµР РЋР вЂљ Р В Р вЂ Р РЋРІР‚в„–Р В Р вЂ Р В РЎвЂўР В РўвЂ�Р В Р’В°, Р В РЎвЂўР РЋРІР‚С™ Р В РЎвЂќР В РЎвЂўР РЋРІР‚С™Р В РЎвЂўР РЋР вЂљР В РЎвЂўР В РЎвЂ“Р В РЎвЂў Р В Р’В·Р В Р’В°Р В РЎвЂ”Р В РЎвЂ�Р РЋРІР‚С™Р В Р’В°Р В Р вЂ¦ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ (Р В Р вЂ Р РЋРІР‚в„–Р В Р вЂ Р В РЎвЂўР В РўвЂ� GND)

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
#define sensor_warering_value 370

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
  //Serial.begin(9600);

  power.setSleepMode(POWERDOWN_SLEEP);
  power.autoCalibrate(); // Р В Р’В°Р В Р вЂ Р РЋРІР‚С™Р В РЎвЂўР В РЎпїЅР В Р’В°Р РЋРІР‚С™Р В РЎвЂ�Р РЋРІР‚РЋР В Р’ВµР РЋР С“Р В РЎвЂќР В Р’В°Р РЋР РЏ Р В РЎвЂќР В Р’В°Р В Р’В»Р В РЎвЂ�Р В Р’В±Р РЋР вЂљР В РЎвЂўР В Р вЂ Р В РЎвЂќР В Р’В° Р РЋРІР‚С™Р В Р’В°Р В РІвЂћвЂ“Р В РЎпїЅР В Р’ВµР РЋР вЂљР В Р’В° Р РЋР С“Р В Р вЂ¦Р В Р’В° (Р РЋРІР‚РЋР РЋРІР‚С™Р В РЎвЂўР В Р’В±Р РЋРІР‚в„– Р РЋР С“Р В РЎвЂ”Р В Р’В°Р В Р’В» Р РЋРІР‚С™Р В РЎвЂўР РЋРІР‚РЋР В Р вЂ¦Р В РЎвЂўР В Р’Вµ Р В Р вЂ Р РЋР вЂљР В Р’ВµР В РЎпїЅР РЋР РЏ) ~2 Р РЋР С“Р В Р’ВµР В РЎвЂќ

  initSoilSensors();
  initPinWaterMotors();

  delay(50);
}

void loop() {

  for (int index_soil_sensor = 0; index_soil_sensor < soilSensorsSize; index_soil_sensor++) {
    int soil = soilSensors[index_soil_sensor].readSoilValue();
    if (soil >= sensor_warering_value) {
      int water_motor_pin = water_motor_pins[index_soil_sensor];
      turn_on_watering(water_motor_pin);
    }
    delay(500);
  }

   power.sleepDelay(time_break); //Р В Р Р‹Р В РЎвЂ”Р В РЎвЂ�Р В РЎпїЅ Р В РЎвЂ“Р В Р’В»Р РЋРЎвЂњР В Р’В±Р В РЎвЂўР В РЎвЂќР В РЎвЂ�Р В РЎпїЅ Р РЋР С“Р В Р вЂ¦Р В РЎвЂўР В РЎпїЅ time_break ms
}

void turn_on_watering(int pin_pomp) {

  digitalWrite(pin_pomp, HIGH);
  delay(time_watering);
  digitalWrite(pin_pomp, LOW);
}

void initSoilSensors() {
  soilSensors[0].initSensor(SENSOR1, Vcc, GND); //Р В РЎвЂ�Р В Р вЂ¦Р В РЎвЂ�Р РЋРІР‚В Р В РЎвЂ�Р РЋРІР‚С›Р В Р’В»Р В РЎвЂ�Р В Р’В·Р В РЎвЂ�Р РЋР вЂљР РЋРЎвЂњР В Р’ВµР В РЎпїЅ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ Р В Р вЂ Р В Р’В»Р В Р’В°Р В Р’В¶Р В Р вЂ¦Р В РЎвЂўР РЋР С“Р РЋРІР‚С™Р В РЎвЂ�
  soilSensors[1].initSensor(SENSOR2, Vcc, GND); //Р В РЎвЂ�Р В Р вЂ¦Р В РЎвЂ�Р РЋРІР‚В Р В РЎвЂ�Р РЋРІР‚С›Р В Р’В»Р В РЎвЂ�Р В Р’В·Р В РЎвЂ�Р РЋР вЂљР РЋРЎвЂњР В Р’ВµР В РЎпїЅ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ Р В Р вЂ Р В Р’В»Р В Р’В°Р В Р’В¶Р В Р вЂ¦Р В РЎвЂўР РЋР С“Р РЋРІР‚С™Р В РЎвЂ�
  soilSensors[2].initSensor(SENSOR3, Vcc, GND); //Р В РЎвЂ�Р В Р вЂ¦Р В РЎвЂ�Р РЋРІР‚В Р В РЎвЂ�Р РЋРІР‚С›Р В Р’В»Р В РЎвЂ�Р В Р’В·Р В РЎвЂ�Р РЋР вЂљР РЋРЎвЂњР В Р’ВµР В РЎпїЅ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ Р В Р вЂ Р В Р’В»Р В Р’В°Р В Р’В¶Р В Р вЂ¦Р В РЎвЂўР РЋР С“Р РЋРІР‚С™Р В РЎвЂ�
  soilSensors[3].initSensor(SENSOR4, Vcc, GND); //Р В РЎвЂ�Р В Р вЂ¦Р В РЎвЂ�Р РЋРІР‚В Р В РЎвЂ�Р РЋРІР‚С›Р В Р’В»Р В РЎвЂ�Р В Р’В·Р В РЎвЂ�Р РЋР вЂљР РЋРЎвЂњР В Р’ВµР В РЎпїЅ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ Р В Р вЂ Р В Р’В»Р В Р’В°Р В Р’В¶Р В Р вЂ¦Р В РЎвЂўР РЋР С“Р РЋРІР‚С™Р В РЎвЂ�
  soilSensors[4].initSensor(SENSOR5, Vcc, GND); //Р В РЎвЂ�Р В Р вЂ¦Р В РЎвЂ�Р РЋРІР‚В Р В РЎвЂ�Р РЋРІР‚С›Р В Р’В»Р В РЎвЂ�Р В Р’В·Р В РЎвЂ�Р РЋР вЂљР РЋРЎвЂњР В Р’ВµР В РЎпїЅ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ Р В Р вЂ Р В Р’В»Р В Р’В°Р В Р’В¶Р В Р вЂ¦Р В РЎвЂўР РЋР С“Р РЋРІР‚С™Р В РЎвЂ�
  soilSensors[5].initSensor(SENSOR6, Vcc, GND); //Р В РЎвЂ�Р В Р вЂ¦Р В РЎвЂ�Р РЋРІР‚В Р В РЎвЂ�Р РЋРІР‚С›Р В Р’В»Р В РЎвЂ�Р В Р’В·Р В РЎвЂ�Р РЋР вЂљР РЋРЎвЂњР В Р’ВµР В РЎпїЅ Р В РўвЂ�Р В Р’В°Р РЋРІР‚С™Р РЋРІР‚РЋР В РЎвЂ�Р В РЎвЂќ Р В Р вЂ Р В Р’В»Р В Р’В°Р В Р’В¶Р В Р вЂ¦Р В РЎвЂўР РЋР С“Р РЋРІР‚С™Р В РЎвЂ�
}

void initPinWaterMotors() {
  pinMode(pin_water_motor1, OUTPUT); //Р В РЎвЂ�Р В Р вЂ¦Р В РЎвЂ�Р РЋРІР‚В Р В РЎвЂ�Р В Р’В°Р В Р’В»Р В РЎвЂ�Р В Р’В·Р В РЎвЂ�Р РЋР вЂљР РЋРЎвЂњР В Р’ВµР В РЎпїЅ Р В РЎвЂ”Р В РЎвЂўР В РЎпїЅР В РЎвЂ”Р РЋРЎвЂњ Р В РўвЂ�Р В Р’В»Р РЋР РЏ Р В РЎвЂ”Р В РЎвЂўР В Р’В»Р В РЎвЂ�Р В Р вЂ Р В Р’В°
  digitalWrite(pin_water_motor1, LOW);

  pinMode(pin_water_motor2, OUTPUT); //Р В РЎвЂ�Р В Р вЂ¦Р В РЎвЂ�Р РЋРІР‚В Р В РЎвЂ�Р В Р’В°Р В Р’В»Р В РЎвЂ�Р В Р’В·Р В РЎвЂ�Р РЋР вЂљР РЋРЎвЂњР В Р’ВµР В РЎпїЅ Р В РЎвЂ”Р В РЎвЂўР В РЎпїЅР В РЎвЂ”Р РЋРЎвЂњ Р В РўвЂ�Р В Р’В»Р РЋР РЏ Р В РЎвЂ”Р В РЎвЂўР В Р’В»Р В РЎвЂ�Р В Р вЂ Р В Р’В°
  digitalWrite(pin_water_motor2, LOW);

  pinMode(pin_water_motor3, OUTPUT); //Р В РЎвЂ�Р В Р вЂ¦Р В РЎвЂ�Р РЋРІР‚В Р В РЎвЂ�Р В Р’В°Р В Р’В»Р В РЎвЂ�Р В Р’В·Р В РЎвЂ�Р РЋР вЂљР РЋРЎвЂњР В Р’ВµР В РЎпїЅ Р В РЎвЂ”Р В РЎвЂўР В РЎпїЅР В РЎвЂ”Р РЋРЎвЂњ Р В РўвЂ�Р В Р’В»Р РЋР РЏ Р В РЎвЂ”Р В РЎвЂўР В Р’В»Р В РЎвЂ�Р В Р вЂ Р В Р’В°
  digitalWrite(pin_water_motor3, LOW);

  pinMode(pin_water_motor4, OUTPUT); //Р В РЎвЂ�Р В Р вЂ¦Р В РЎвЂ�Р РЋРІР‚В Р В РЎвЂ�Р В Р’В°Р В Р’В»Р В РЎвЂ�Р В Р’В·Р В РЎвЂ�Р РЋР вЂљР РЋРЎвЂњР В Р’ВµР В РЎпїЅ Р В РЎвЂ”Р В РЎвЂўР В РЎпїЅР В РЎвЂ”Р РЋРЎвЂњ Р В РўвЂ�Р В Р’В»Р РЋР РЏ Р В РЎвЂ”Р В РЎвЂўР В Р’В»Р В РЎвЂ�Р В Р вЂ Р В Р’В°
  digitalWrite(pin_water_motor4, LOW);

  pinMode(pin_water_motor5, OUTPUT); //Р В РЎвЂ�Р В Р вЂ¦Р В РЎвЂ�Р РЋРІР‚В Р В РЎвЂ�Р В Р’В°Р В Р’В»Р В РЎвЂ�Р В Р’В·Р В РЎвЂ�Р РЋР вЂљР РЋРЎвЂњР В Р’ВµР В РЎпїЅ Р В РЎвЂ”Р В РЎвЂўР В РЎпїЅР В РЎвЂ”Р РЋРЎвЂњ Р В РўвЂ�Р В Р’В»Р РЋР РЏ Р В РЎвЂ”Р В РЎвЂўР В Р’В»Р В РЎвЂ�Р В Р вЂ Р В Р’В°
  digitalWrite(pin_water_motor5, LOW);

  pinMode(pin_water_motor6, OUTPUT); //Р В РЎвЂ�Р В Р вЂ¦Р В РЎвЂ�Р РЋРІР‚В Р В РЎвЂ�Р В Р’В°Р В Р’В»Р В РЎвЂ�Р В Р’В·Р В РЎвЂ�Р РЋР вЂљР РЋРЎвЂњР В Р’ВµР В РЎпїЅ Р В РЎвЂ”Р В РЎвЂўР В РЎпїЅР В РЎвЂ”Р РЋРЎвЂњ Р В РўвЂ�Р В Р’В»Р РЋР РЏ Р В РЎвЂ”Р В РЎвЂўР В Р’В»Р В РЎвЂ�Р В Р вЂ Р В Р’В°
  digitalWrite(pin_water_motor6, LOW);
}


