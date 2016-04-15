#include <Wire.h>
#include <Dwenguino.h>
#include <LiquidCrystal.h>
#include <DwenguinoSensorPanel.h>
#include <DwenguinoMotor.h>

int sensor1 = 0 ;
SensorPanel sensorpanel;
int sensor2 = 0 ;
int sensor3 = 0 ;
DCMotor dcMotor1(MOTOR_1_0, MOTOR_1_1);
DCMotor dcMotor2(MOTOR_2_0, MOTOR_2_1);

void setup()
{
  sensorpanel = SensorPanel();
  sensorpanel.init();
  sensorpanel.powerLongRange(true);
  initDwenguino();
}

void loop()
{
  sensor1 = 	sensorpanel.readSensor(D1,DIFF_MODE) ;
  sensor2 = 	sensorpanel.readSensor(D2,DIFF_MODE) ;
  sensor3 = 	sensorpanel.readSensor(OS8,DIFF_MODE) ;
  dwenguinoLCD.setCursor(0,0);
  dwenguinoLCD.print("D1:" );
  dwenguinoLCD.print(sensor1 );
  dwenguinoLCD.setCursor(0,1);
  dwenguinoLCD.print("D2:" );
  dwenguinoLCD.print(sensor2 );
  dwenguinoLCD.setCursor(8,1);
  dwenguinoLCD.print("D3:" );
  dwenguinoLCD.print(sensor3 );
  delay( 100 );
  dwenguinoLCD.clear();	
  dcMotor1.setSpeed(100);
  dcMotor2.setSpeed(100);
  if (( ( ( sensor3 ) > ( 130 ) ) && ( ( sensor3 ) < ( 160 ) ) ))
  {
    dcMotor1.setSpeed(0);
    dcMotor2.setSpeed(0);
  }
  else
  {
    if (( ( sensor1 ) > ( ( sensor2 + 5 ) ) ))
    {
      dcMotor2.setSpeed(200);
      dcMotor1.setSpeed(0);
    }
    if (( ( sensor2 ) > ( ( sensor1 + 5 ) ) ))
    {
      dcMotor1.setSpeed(200);
      dcMotor2.setSpeed(0);
    }
  }
}


