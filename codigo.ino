// SENSOR ULTRASSONICO
const int echo = 5;
const int trigger = 13;

// BUZZER
const int buzzer = 7;
 
// BOTOES
const int btn_um = 4;
const int btn_dois = 2; 

// DISPLAY 7 SEGMENTOS
const int pino_a = 12;
const int pino_b = 9;
const int pino_c = 10;
const int pino_d = 11;


int cont_btn1 = 0;
int cont_btn2 = 0;

int valor_botao;

int inches = 0;

int cm = 0;
 
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void Alzheimer(){
  float cm = 0.01723 * readUltrasonicDistance(trigger,echo);
  if (cm > 200){
    digitalWrite(buzzer, HIGH);
  }  else {
    digitalWrite(buzzer, LOW);
    
  }
}

void Perigo(){
  float cm = 0.01723 * readUltrasonicDistance(trigger,echo);
  if (cm > 20){
    digitalWrite(buzzer, HIGH);
  }  else {
    digitalWrite(buzzer, LOW);
    
  }
}

void setup(){  
    pinMode(buzzer, OUTPUT);
    pinMode(btn_um, INPUT);
    pinMode(btn_dois, INPUT_PULLUP);
    Serial.begin(9600);
  
}

void loop(){

  
  
 if(digitalRead(btn_um)==  0){  // se o botão for pressionado
  cont_btn1++;  // atribui +1 a variavel cont
  delay(300); // da um tempo para o pressionamento, senao o arduino endoida
  }
  
  if(digitalRead(btn_dois)==  0){  // se o botão for pressionado
  cont_btn2++;  // atribui +1 a variavel cont
  delay(300); // da um tempo para o pressionamento, senao o arduino endoida
  }
  
 if(cont_btn1 == 3){
    cont_btn1 = 1;
   digitalWrite(pino_a, HIGH);
   digitalWrite(pino_b, LOW);
   digitalWrite(pino_c, LOW);
   digitalWrite(pino_d, LOW);
 }   //  deixa o valor somente de 1 a 3
 
 if(cont_btn2==3){
    cont_btn2=1;
   digitalWrite(pino_a, HIGH);
   digitalWrite(pino_b, LOW);
   digitalWrite(pino_c, LOW);
   digitalWrite(pino_d, LOW);
 }   //  deixa o valor somente de 1 a 3
  
  
 if(cont_btn1==1){
  cont_btn2 = 0;
   
  Alzheimer();
   
   digitalWrite(pino_a, 1);
   digitalWrite(pino_b, 0);
   digitalWrite(pino_c, 0);
   digitalWrite(pino_d, 0);
  
 } else if(cont_btn1 == 2){
    digitalWrite(buzzer, LOW);
   
     digitalWrite(pino_a, 1);
     digitalWrite(pino_b, 0);
     digitalWrite(pino_c, 0);
     digitalWrite(pino_d, 0);
  }
  
  if(cont_btn2==1){
    cont_btn1 = 0;
    
  Perigo();
   
   digitalWrite(pino_a, 0);
   digitalWrite(pino_b, 1);
   digitalWrite(pino_c, 0);
   digitalWrite(pino_d, 0);
   
 }else if(cont_btn2==2){
  digitalWrite(buzzer, LOW);
   
   digitalWrite(pino_a, 0);
   digitalWrite(pino_b, 1);
   digitalWrite(pino_c, 0);
   digitalWrite(pino_d, 0);
 }
}	