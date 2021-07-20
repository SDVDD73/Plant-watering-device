class SoilSensor {

  public:
    SoilSensor() {}

    void initSensor(int pin_sensor, int pin_vcc) {
      this->pin_sensor = pin_sensor;
      this->pin_vcc = pin_vcc;

      initSensor();
    }

    int readSoilValue() {
      digitalWrite(pin_vcc, HIGH);
      delay(1000);

      unsigned int sensorValueAcum = 0;
      int sensorValue = 0;
      for (int i = 0; i < count_measurements; i++) {
        sensorValue = analogRead(pin_sensor);
        sensorValueAcum = sensorValueAcum + sensorValue;
        delay(delay_beetween_measurements_ms);
      }

      digitalWrite(pin_vcc, LOW);
      delay(100);
      return sensorValueAcum / count_measurements;
    }


  private:
    byte pin_sensor;
    byte pin_vcc;
    byte count_measurements = 50;
    byte delay_beetween_measurements_ms = 5;

    void initSensor() {
      pinMode     (pin_sensor, INPUT);
      pinMode     (pin_vcc, OUTPUT);
      digitalWrite(pin_vcc, LOW);
    }

};

