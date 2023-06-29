#include <LedControl.h> //libreria para las led matricial
#include <Adafruit_NeoPixel.h>//libreria para la rueda led
#include <Servo.h>//se instala esta libreria para el servo motor
#include <SoftwareSerial.h>//para el bluetoo


SoftwareSerial miBT(8, 9);
Adafruit_NeoPixel tira = Adafruit_NeoPixel(7,12);
LedControl MATLED = LedControl(11,13,10,1);	

byte caracter[8] = {			
0x0, 0xff, 0xff, 0x7e, 0x7e, 0x3c, 0x18, 0x0
};

byte caracter_2[8] = { 
0x0, 0x4c, 0xd2, 0x52, 0x52, 0x52, 0x4c, 0x0
};
byte caracter_3[8] = { /
0x0, 0x54, 0x38, 0x7c, 0x38, 0x54, 0x10, 0x10
};

 
char Dato = 0;
int LED_1=2;
int LED_2=3;
int LED_3=4;
int LED_4=5;
bool estado = 0;
bool estado1=0;
bool estado2=0;
bool estado3=0;
int valor;
Servo dota;

void setup() {
  miBT.begin(9600);
  Serial.begin(9600);
  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);
  pinMode(LED_3,OUTPUT);
  pinMode(LED_4,OUTPUT);
  tira.begin();
  tira.show();//
  MATLED.shutdown(0,false);			
  MATLED.setIntensity(0,4);			
  MATLED.clearDisplay(0);	
  dota.attach(6);

}

 

void loop() {
  if (miBT.available() > 0){
    Dato = miBT.read();
   Serial.println(Dato);

   if(Dato == 'B1')
   estado=!estado;
   digitalWrite(LED_1, estado);

    if(Dato == 'B2')
   estado1=!estado1;
   digitalWrite(LED_2, estado1);

    if(Dato == 'B3')
   estado2=!estado2;
   digitalWrite(LED_3, estado2);

    if(Dato == 'B4')
   estado3=!estado3;
   digitalWrite(LED_4, estado3);


   if(Dato == 'B5')
   figura_1();

   if(Dato == 'B6')
   figura_2();


   if(Dato == 'B7')
   figura_3();


   if(Dato == 'B8')
     for(int i = 0; i<7; i = i+3 ){
      tira.setBrightness(100);
      tira.setPixelColor(i, 0,148,226);
      tira.show();
      delay(100);
    }

  }
 }
 void figura_1(){
     for (int i = 0; i < 8; i++)  		
      {
     MATLED.setRow(0,i,caracter[i]);	
     delay(100);
     }
 }

void figura_2(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		
     {
     MATLED.setRow(0,i,caracter_2[i]);		
     delay(100);
     }

}
void figura_3(){
     for (int i = 0; i < 8; i++)  		
     {
     MATLED.setRow(0,i,caracter_3[i]);		
     delay(100);
     }
}

void servo(){
  while ( miBT.available() > 0){
    valor = miBT.read();
    Serial.println(valor);
    dota.write(valor);
  }
}


