#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define pino_trigger  7
#define pino_echo 6
#define pressao A0
#define bomba 8

int agua;


void setup() {
  pinMode(bomba, OUTPUT);
  pinMode(pressao, INPUT);
  pinMode(pino_trigger, OUTPUT);
  pinMode(pino_echo, INPUT);
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Projeto SE ETEC");
  delay (1000);
}

void loop() {
  
  agua = distancia();
  
  //quando o botão não esta pressionado
 // while (digitalRead(pressao) == LOW){
  
    digitalWrite(motor, 0);
   lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("sem pressao");
    
    if (agua <= 100){
      
      
      lcd.setCursor(0,1);
      lcd.print("caixa cheia");
      	
    
    }
    
    if (agua > 100 && agua <= 250 ){
    
      lcd.setCursor(0,1);
      lcd.print("caixa na metade");
      	
    }
    
    if (agua >250){
      
      
      lcd.setCursor(0,1);
      lcd.print("caixa vazia");
      	
    
    }
    delay(500);
 // }
  
 
 
  // quando o botão esta pressionado
  while (digitalRead(pressao) == HIGH){ 
    
     lcd.clear();
    if (agua > 100 && agua < 300){
    
      lcd.setCursor(0,0);
      lcd.print("enchendo a caixa");
       lcd.setCursor(0,1);
      lcd.print("motor ligado");
      digitalWrite(motor, 36);
    }
    
    if (agua <= 100){
    
      lcd.setCursor(0,0);
      lcd.print("caixa cheia");
      lcd.setCursor(0,1);
      lcd.print("motor desligado");
      digitalWrite(motor, 0);
      	
    }
    delay(500);
  }
  // fim dos testes
  
  
}

//FUNÇÃO
float distancia(){ 

  float dur;
  digitalWrite(pino_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pino_trigger, LOW);
  dur = pulseIn(pino_echo, HIGH);
  
  return dur/58.82; 
  
} 