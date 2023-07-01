#include "Ticker.h"
#include <LedControl.h> 

void impresion(void);

Ticker Interrupcion(impresion, 3000); 
LedControl MATLED = LedControl(11,13,10,1);	


//fueguito
byte caracter_1[8]{
0x1c, 0x3e, 0x7f, 0x7f, 0x3e, 0x1c, 0x8, 0x0
};
//D
byte caracter_2[8]{
0x0, 0x70, 0x48, 0x48, 0x48, 0x48, 0x70, 0x0
};
//A
byte caracter_3[8]{
0x0, 0x18, 0x24, 0x24, 0x3c, 0x24, 0x24, 0x0
};
//N
byte caracter_4[8]{
0x0, 0x44, 0x64, 0x54, 0x4c, 0x44, 0x0, 0x0
};
//I
byte caracter_5[8]{
0x0, 0x38, 0x10, 0x10, 0x10, 0x38, 0x0, 0x0
};
//2
byte caracter_6[8]{
0x0, 0x7c, 0x44, 0x4, 0x7c, 0x40, 0x40, 0x7c
};
//0
byte caracter_7[8]{
0x0, 0x3c, 0x24, 0x24, 0x24, 0x24, 0x3c, 0x0
};
//2
byte caracter_8[8]{
0x0, 0x7c, 0x44, 0x4, 0x7c, 0x40, 0x40, 0x7c
};
//2
byte caracter_9[8]{
0x0, 0x7c, 0x44, 0x4, 0x7c, 0x40, 0x40, 0x7c
};
//2
byte caracter_10[8]{
0x0, 0x7c, 0x44, 0x4, 0x7c, 0x40, 0x40, 0x7c
};
//1
byte caracter_11[8]{
0x0, 0x18, 0x28, 0x8, 0x8, 0x1c, 0x0, 0x0
};
//3
byte caracter_12[8]{
0x0, 0x3c, 0x4, 0x4, 0x1c, 0x4, 0x3c, 0x0
};



int evalua;
int buzer=2;
int sensor=A1; 


void setup() {
  Serial.begin(9600); 	
  MATLED.shutdown(0,false);		
  MATLED.setIntensity(0,4);			// establece brillo
  MATLED.clearDisplay(0);	//se indica para limpiar la matriz led
  Interrupcion.start();   //Inicializa la libreria y las interrupciones por software
  pinMode(buzer, OUTPUT); 
  //IMPRIMA TODO LOS CARACTERES INDICADOS 
 
  figura_1();
  delay(1000);
  figura_2();
  delay(1000);
  figura_3();
  delay(1000);
  figura_4();
  delay(1000);
  figura_5();
  delay(1000);
  figura_6();
  delay(1000);
  figura_7();
  delay(1000);
  figura_8();
  delay(1000);
  figura_9();
  delay(1000);
  figura_10();
  delay(1000);
  figura_11();
  delay(1000);
  figura_12();
  delay(1000);
 

}

void loop() {
  Interrupcion.update(); //Actualiza la libreria para poder mantener la interrupcion al pendiente

  evalua = analogRead(sensor);
  if(evalua <400){
    digitalWrite(buzer, HIGH);
    delay(1000);
    MATLED.clearDisplay(0);
    figura_1();
    delay(1000);
    MATLED.clearDisplay(0);	
  }else{
    digitalWrite(buzer, LOW);
    delay(10);
    MATLED.clearDisplay(0);	
  }

}


//funcion para fueguito
void figura_1(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++) 
     {
     MATLED.setRow(0,i,caracter_1[i]);
     delay(100);
     }
}

//funcion para D
void figura_2(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		
     {
     MATLED.setRow(0,i,caracter_2[i]);	
     delay(100);
     }
}

//funcion para A
void figura_3(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		
     {
     MATLED.setRow(0,i,caracter_3[i]);	
     delay(100);
     }
}

//funcion para N
void figura_4(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  	
     {
     MATLED.setRow(0,i,caracter_4[i]);	
     delay(100);
     }
}

//funcion para I
void figura_5(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  	
     {
     MATLED.setRow(0,i,caracter_5[i]);	
     delay(100);
     }
}

//funcion para 2
void figura_6(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  	
     {
     MATLED.setRow(0,i,caracter_6[i]);	
     delay(100);
     }
}

//funcion para 0
void figura_7(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  	
     {
     MATLED.setRow(0,i,caracter_7[i]);	
     delay(100);
     }
}

//funcion para 2
void figura_8(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		
     {
     MATLED.setRow(0,i,caracter_8[i]);	
     delay(100);
     }
}

//funcion para 2
void figura_9(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		
     {
     MATLED.setRow(0,i,caracter_9[i]);		
     delay(100);
     }
}

//funcion para 2
void figura_10(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  	
     {
     MATLED.setRow(0,i,caracter_10[i]);	
     delay(100);
     }
}

//funcion para 1
void figura_11(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++) 
     {
     MATLED.setRow(0,i,caracter_11[i]);		
     delay(100);
     }
}

//funcion para 3
void figura_12(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		
     {
     MATLED.setRow(0,i,caracter_12[i]);	
     delay(100);
     }
}



//par la interrupcion 
void impresion(void){
 Serial.println(evalua);//se imprima el valor del sensor
}

