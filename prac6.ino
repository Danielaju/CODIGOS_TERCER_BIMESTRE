  /*
  Arduino     Accelerometer ADXL345
    A5            SCL
    A4            SDA
    3.3V          CS
    3.3V          VCC
    GND           GND

  Conexión de servomotores:
  Arduino     Servo No. 1
    5V          5V
  GND         GND
  D3          CTRL

  Arduino     Servo No. 2
    5V          5V
    GND         GND
    D5          CTRL
  */

#include <Wire.h>
#include <SparkFun_ADXL345.h>
#include <Servo.h>


Servo servo_hori;
Servo servo_vert;
ADXL345 adxl;             //Declaramos nuestro acelerometro ADXL345

int RawX, maedejeY;//Declaramos variables

void setup() { // inicializamos nuestro programa

  inicializar();
  configurarServos();
  esperarInicializacion();

}

void loop() { //lee y espera a los a servos

  leerAcelerometro();
  actualizarServos();
  esperar(100);

}


void inicializar() {  // iniciamos el  programa principal

  Serial.begin(9600);
  adxl.powerOn();
  adxl.setRangeSetting(2);

}


void configurarServos() {

  servo_hori.attach(7);
  servo_vert.attach(6);
  servo_hori.write(90);
  servo_vert.write(90);

}


void esperarInicializacion() { // bucle de tiempo para esperar a los servos

  delay(2000);

}

void leerAcelerometro() {

  int ejeX, ejeY, ejeZ;

  adxl.readAccel(&ejeX, &ejeY, &ejeZ);
  RawX = map(ejeX, -255, 255, 179, 0);
  maedejeY = map(ejeY, -255, 255, 0, 179);

}


void actualizarServos() {

  servo_hori.write(RawX);
  servo_vert.write(maedejeY);

}


void esperar(int ms) {  //Esta función generaliza la espera durante un período de tiempo específico en milisegundos.

  delay(ms);

}