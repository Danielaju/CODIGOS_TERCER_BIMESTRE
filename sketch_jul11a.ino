#include <SPI.h>			// incluye libreria bus SPI
#include <MFRC522.h>			// incluye libreria especifica para MFRC522
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>             


int Luzgri = 7;
int Luzred = 6;
const int servoPin1 = 8;
int buzzer = 5;
Servo servo;
#define RST_PIN  9			
#define SS_PIN  10		


MFRC522 mfrc522(SS_PIN, RST_PIN);	// crea objeto mfrc522 enviando pines de slave select y reset
LiquidCrystal_I2C lcd(0x27, 16, 2);// Inicializa el objeto LiquidCrystal_I2C para la pantalla LCD

byte LecturaUID[4]; 				// crea array para almacenar el UID 
byte Usuario1[4]= {0x93, 0x004, 0x63, 0xA6} ;    
byte Usuario2[4]= {0xB2, 0x054, 0x9E, 0x1C} ;    



void setup() {
  Serial.begin(9600);			
  SPI.begin();				// inicializa bus SPI
  mfrc522.PCD_Init();			// inicializa modulo lector
  Serial.println("Listo");		
  servo.attach(servoPin1);
  servo.write(0);
  pinMode(Luzred, OUTPUT);
  pinMode(Luzgri, OUTPUT);
  pinMode(buzzer, OUTPUT);

   Wire.begin();// Inicializa la comunicación I2C
  lcd.backlight();// 

  lcd.begin(16, 2);
  lcd.print("Pon la tarjeta");//Imprime el texto en la LCD

}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent())		
    return;						
  
  if ( ! mfrc522.PICC_ReadCardSerial()) 		// si no puede obtener datos de la tarjeta
    return;						
    
    
    Serial.print("UID:");				// muestra texto UID:
    for (byte i = 0; i < mfrc522.uid.size; i++) {	// bucle recorre de a un byte por vez el UID
      if (mfrc522.uid.uidByte[i] < 0x10){		// si el byte leido es menor a 0x10
        Serial.print(" 0");				// imprime espacio en blanco y numero cero
        }
        else{						
          Serial.print(" ");				
          }
          Serial.print(mfrc522.uid.uidByte[i], HEX);   	
          LecturaUID[i]=mfrc522.uid.uidByte[i];   	      
          }
          
          Serial.print("\t");   			            
                    
          if(comparaUID(LecturaUID, Usuario1)){//llama a funcion comparaUID con Usuario1
            lcd.clear();
            Serial.println("Bienvenido Usuario 1");	// si retorna verdadero muestra texto bienvenida
            servo.write(90);
            delay(20);
            lcd.print("Hola Daniel");
            tone(5, 449, 3000);
            digitalWrite(Luzgri, HIGH);
            digitalWrite(Luzred, LOW);
            delay(3000);
            digitalWrite(Luzgri, LOW);
            digitalWrite(Luzred, HIGH);
            digitalWrite(buzzer, LOW);
            lcd.clear();
            lcd.print("Pon la tarjeta");//Imprime el texto en la LCD
            servo.write(0);
          }
          else if(comparaUID(LecturaUID, Usuario2)){// llama a funcion comparaUID con Usuario2
            lcd.clear();
            Serial.println("Bienvenido Usuario2");	// si retorna verdadero muestra texto bienvenida
            servo.write(90);
            delay(20);
            lcd.print("que tal Profe");
            tone(5, 449, 3000);
            digitalWrite(Luzgri, HIGH);
            digitalWrite(Luzred, LOW);
            delay(3000);
            digitalWrite(Luzgri, LOW);
            digitalWrite(Luzred, HIGH);
            digitalWrite(buzzer, LOW);
            lcd.clear();
            lcd.print("Pon la tarjeta");
            servo.write(0);
          }	 
          else{						
            Serial.println("No te conozco");	// muestra texto equivalente a acceso denegado          
            lcd.clear(); 
            servo.write(0);
            lcd.print("acceso denegado");
            digitalWrite(Luzred, HIGH);   
            delay(3000);
            lcd.clear();
            lcd.print("Pon la tarjeta");
          }
                  mfrc522.PICC_HaltA();  		// detiene comunicacion con tarjeta                
}

boolean comparaUID(byte lectura[],byte usuario[])	// funcion comparaUID
{
  for (byte i=0; i < mfrc522.uid.size; i++){		// bucle recorre de a un byte por vez el UID
  if(lectura[i] != usuario[i])				// si byte de UID leido es distinto a usuario
    return(false);					
  }
  return(true);						// si los 4 bytes coinciden retorna verdadero
}