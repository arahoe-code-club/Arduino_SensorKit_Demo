#include <Arduino.h>
#include <U8x8lib.h>
#include "Arduino_SensorKit.h"

U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

const int light_sensor = A3;
const int sound_sensor = A2;
float temperature = 0.0;
unsigned int humidity = 0;
float pressure = 0.0;
unsigned int soundLevel = 0;
unsigned int lightLevel = 0;
float accelerationX = 0;
float accelerationY = 0;
float accelerationZ = 0;


void setup() {
  u8x8.begin();
  u8x8.setFlipMode(true);
  u8x8.setFont(u8x8_font_chroma48medium8_r);    // 8 rows, 16 columns
  u8x8.clear();

  Serial.begin(9600);
  Environment.begin();
  Pressure.begin();
  Accelerometer.begin();
  delay(1000);
}

 
void loop() {
  for (int i = 0; i < 16; i++) {
    soundLevel += analogRead(sound_sensor);
  }
  soundLevel >>= 4;
  soundLevel = map(soundLevel, 0, 1023, 0, 100);
  temperature = Environment.readTemperature();
  humidity = Environment.readHumidity();
  pressure = Pressure.readPressure() / 100.0;
  lightLevel = map(analogRead(light_sensor), 0, 1023, 0, 100);
  accelerationX = Accelerometer.readX();
  accelerationY = Accelerometer.readY();
  accelerationZ = Accelerometer.readZ();    // positive Z appears to be straight down respective to board - SensorKit docs were incorrect when code was created.
 
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
 
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println("hPa");

  Serial.print("Light level: "); 
  Serial.print(lightLevel);
  Serial.println(" %");

  Serial.print("Sound level: "); 
  Serial.print(soundLevel);
  Serial.println(" %");

  Serial.print("Accelerometer: x=");
  Serial.print(accelerationX);
  Serial.print("m, y=");
  Serial.print(accelerationY);
  Serial.print("m, z=");
  Serial.print(accelerationZ);
  Serial.println("m");

  Serial.println("\n");

  u8x8.setCursor(0, 0);
  u8x8.print("T ");
  u8x8.print(temperature);
  u8x8.print("C, H ");
  u8x8.print(humidity);
  u8x8.print("%");
  // These if statements overwrite stale data in the u8x8 oled buffers when necessary
  if (humidity < 10) {
    u8x8.print("  ");
  }
  else if (humidity < 100) {
    u8x8.print(" ");
  }

  u8x8.setCursor(0, 1);
  u8x8.print(pressure);
  u8x8.print(" hPa ");

  u8x8.setCursor(0, 2);
  u8x8.print("S ");
  u8x8.print(soundLevel);
  u8x8.print("%");
  if (soundLevel < 10) {
    u8x8.print("  ");
  }
  else if (soundLevel < 100) {
    u8x8.print(" ");
  }
  u8x8.print(" L ");
  u8x8.print(lightLevel);
  u8x8.print("% ");
  if (lightLevel < 10) {
    u8x8.print(" ");
  }
  
  u8x8.setCursor(0, 3);
  u8x8.print(" x ");
  u8x8.print(accelerationX);
  u8x8.print("   ");

  u8x8.setCursor(0, 4);
  u8x8.print(" y ");
  u8x8.print(accelerationY);
  u8x8.print("   ");

  u8x8.setCursor(0, 5);
  u8x8.print(" z ");
  u8x8.print(accelerationZ);
  u8x8.print("   ");

  u8x8.refreshDisplay();

  delay(500);

}
