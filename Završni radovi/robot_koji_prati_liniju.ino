#include <IRremote.h>
#include <NewTone.h>

#define NOTA_E4  330
#define NOTA_F4  349
#define NOTA_G4  392
#define NOTA_A4  440
#define NOTA_AS4 466
#define NOTA_B4  494
#define NOTA_C5  523
#define NOTA_D5  587
#define NOTA_E5  659
#define NOTA_F5  698

int EnA=5;
int In1=4;
int In2=3;
int In3=8;
int In4=7;
int EnB=6;
int lijevo=2;
int sredina=9;
int desno=10;
int najlijevo=11;
int najdesno=12;
int a=0;
int b=0;
int c=0;
int d=0;
int e=0;
int x=0;
int y=0;
int z=0;
int i=0;
int j=0;
int k=0;

int ledl=19;
int ledd=14;
int zuj=18;
int senzor=15;
IRrecv IC(senzor);
decode_results mjesto;

void setup() {
  pinMode(EnA, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(lijevo, INPUT);
  pinMode(sredina, INPUT);
  pinMode(desno, INPUT);
  pinMode(najlijevo, INPUT);
  pinMode(najdesno, INPUT);
  pinMode(ledl, OUTPUT);
  pinMode(ledd, OUTPUT);
  pinMode(zuj, OUTPUT);

  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  digitalWrite(ledl, LOW);
  digitalWrite(ledd, LOW);

  IC.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  while(IC.decode(&mjesto)==0){ }
  Serial.println(mjesto.value, HEX);
  delay(1500);
  IC.resume();

  if(mjesto.value==0xE318261B){
    x=!x;
    if(x==1){
      Kretanje();}
  }

  if(mjesto.value==0x511DBB){
    y=!y;
    if(y==1){
      Ledice();}
  }

  if(mjesto.value==0xEE886D7F){
    z=!z;
    if(z==1){
      Zujalica();}
  }
}

void Kretanje() {
  for(i=0; i<3; i++){
    digitalWrite(ledl, HIGH);
    digitalWrite(ledd, HIGH);
    NewTone(zuj, 1200);
    delay(500);
    digitalWrite(ledl, LOW);
    digitalWrite(ledd, LOW);
    NewTone(zuj, 800);
    delay(500);
  }
  
  while(x==1){
    a=digitalRead(najlijevo);
    b=digitalRead(lijevo);
    c=digitalRead(sredina);
    d=digitalRead(desno);
    e=digitalRead(najdesno);

    if ((a==0)&&(b==0)&&(c==1)&&(d==0)&&(e==0)){
      Naprijed();}
    if ((a==0)&&(b==1)&&(c==1)&&(d==1)&&(e==0)){
      Naprijed();}

    if ((a==0)&&(b==0)&&(c==1)&&(d==1)&&(e==0)){
      Ulijevo();}
    if ((a==0)&&(b==0)&&(c==0)&&(d==1)&&(e==0)){
      Ulijevo();}
    if ((a==0)&&(b==0)&&(c==1)&&(d==1)&&(e==1)){
      Ostrolijevo();}
    if ((a==0)&&(b==0)&&(c==0)&&(d==1)&&(e==1)){
      Ostrolijevo();}
    if ((a==0)&&(b==0)&&(c==0)&&(d==0)&&(e==1)){
      Ostrolijevo();}
    if ((a==0)&&(b==1)&&(c==1)&&(d==1)&&(e==1)){
      Ostrolijevo();}
    
    if ((a==0)&&(b==1)&&(c==1)&&(d==0)&&(e==0)){
      Udesno();}
    if ((a==0)&&(b==1)&&(c==0)&&(d==0)&&(e==0)){
      Udesno();}
    if ((a==1)&&(b==1)&&(c==1)&&(d==0)&&(e==0)){
      Ostrodesno();}
    if ((a==1)&&(b==1)&&(c==0)&&(d==0)&&(e==0)){
      Ostrodesno();}
    if ((a==1)&&(b==0)&&(c==0)&&(d==0)&&(e==0)){
      Ostrodesno();}
    if ((a==1)&&(b==1)&&(c==1)&&(d==1)&&(e==0)){
      Ostrodesno();}

    if ((a==0)&&(b==0)&&(c==0)&&(d==0)&&(e==0)){
      Stani();}
    if ((a==1)&&(b==0)&&(c==0)&&(d==0)&&(e==1)){
      Stani();}

    if ((a==1)&&(b==1)&&(c==1)&&(d==1)&&(e==1)){
      Kraj();}
    }
}

void Ledice() {
  int stanka=2400;
  
    for(j=0; j<4; j++){
      stanka=stanka/2;
      digitalWrite(ledl, HIGH);
      digitalWrite(ledd, LOW);
      delay(stanka);
      digitalWrite(ledl, LOW);
      digitalWrite(ledd, HIGH);
      delay(stanka);
    }
    digitalWrite(ledd, LOW);
    delay(75);
    digitalWrite(ledl, HIGH);
    digitalWrite(ledd, HIGH);
    delay(5000);
    digitalWrite(ledl, LOW);
    digitalWrite(ledd, LOW);
    y=!y;
}

void Zujalica() {
  int note[]={
   NOTA_E4, NOTA_G4, NOTA_A4, NOTA_A4, 0, 
   NOTA_A4, NOTA_B4, NOTA_C5, NOTA_C5, 0, 
   NOTA_C5, NOTA_D5, NOTA_B4, NOTA_B4, 0,
   NOTA_A4, NOTA_G4, NOTA_A4, 0,
   
   NOTA_E4, NOTA_G4, NOTA_A4, NOTA_A4, 0, 
   NOTA_A4, NOTA_B4, NOTA_C5, NOTA_C5, 0, 
   NOTA_C5, NOTA_D5, NOTA_B4, NOTA_B4, 0,
   NOTA_A4, NOTA_G4, NOTA_A4, 0,
   
   NOTA_E4, NOTA_G4, NOTA_A4, NOTA_A4, 0, 
   NOTA_A4, NOTA_C5, NOTA_D5, NOTA_D5, 0, 
   NOTA_D5, NOTA_E5, NOTA_F5, NOTA_F5, 0,
   NOTA_E5, NOTA_D5, NOTA_E5, NOTA_A4, 0,
   
   NOTA_A4, NOTA_B4, NOTA_C5, NOTA_C5, 0, 
   NOTA_D5, NOTA_E5, NOTA_A4, 0, 
   NOTA_A4, NOTA_C5, NOTA_B4, NOTA_B4, 0,
   NOTA_C5, NOTA_A4, NOTA_B4, 0 };
   
  int trajanje[]={
   125, 125, 250, 125, 125, 
   125, 125, 250, 125, 125,
   125, 125, 250, 125, 125,
   125, 125, 375, 125, 
  
   125, 125, 250, 125, 125, 
   125, 125, 250, 125, 125,
   125, 125, 250, 125, 125,
   125, 125, 375, 125, 
  
   125, 125, 250, 125, 125, 
   125, 125, 250, 125, 125,
   125, 125, 250, 125, 125,
   125, 125, 125, 250, 125,

   125, 125, 250, 125, 125, 
   250, 125, 250, 125, 
   125, 125, 250, 125, 125,
   125, 125, 375, 375 };
  
  int n=0;
  int pauza=0;

  for (n=0; n<76; n++){
    pauza=trajanje[n]*1.1;
    NewTone(zuj, note[n], pauza);
    delay(pauza);
    noNewTone(zuj);
    } 
  z=!z;
}

void Naprijed() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(EnA, 80);
  analogWrite(EnB, 100);
  digitalWrite(ledl, LOW);
  digitalWrite(ledd, LOW);
  noNewTone(zuj);
  delay(20);
  }

void Ulijevo() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(EnB, 100);
  digitalWrite(ledl, LOW);
  digitalWrite(ledd, LOW);
  noNewTone(zuj);
  delay(20);
  }

void Udesno() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  analogWrite(EnA, 80);
  digitalWrite(ledl, LOW);
  digitalWrite(ledd, LOW);
  noNewTone(zuj);
  delay(20);
  }

void Stani() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  analogWrite(EnA, 0);
  analogWrite(EnB, 0);
  digitalWrite(ledl, LOW);
  digitalWrite(ledd, LOW);
  noNewTone(zuj);
  delay(20);
  }

void Ostrolijevo() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(EnB, 130);
  digitalWrite(ledl, LOW);
  digitalWrite(ledd, HIGH);
  NewTone(zuj, 1000);
  delay(20);
  }

void Ostrodesno() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  analogWrite(EnA, 110);
  digitalWrite(ledl, HIGH);
  digitalWrite(ledd, LOW);
  NewTone(zuj, 1000);
  delay(20);
  }
  
void Kraj() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  analogWrite(EnA, 0);
  analogWrite(EnB, 0);
  digitalWrite(ledl, LOW);
  digitalWrite(ledd, LOW);

  int note[] = {
   NOTA_C5, NOTA_AS4, NOTA_A4, NOTA_F4,
   NOTA_G4, 0, NOTA_G4, NOTA_D5,
   NOTA_C5, 0, NOTA_AS4, 0,
   NOTA_A4, 0, NOTA_A4, NOTA_A4,
   NOTA_C5, 0, NOTA_AS4, NOTA_A4,
   NOTA_G4, 0 };

  int trajanje[] = {
   188, 188, 188, 188,
   188, 188, 188, 188,
   188, 188, 188, 188,
   188, 188, 188, 188,
   188, 188, 188, 188,
   188, 188 };

  int n=0;
  int pauza=0;

  for (n=0; n<22; n++) {
    pauza=trajanje[n]*1.2;
    NewTone(zuj, note[n], trajanje);
    delay(pauza);
    noNewTone(zuj);
  }
  
  for(k=0;  k<5; k++){
    digitalWrite(ledl, HIGH);
    digitalWrite(ledd, HIGH);
    delay(200);
    digitalWrite(ledl, LOW);
    digitalWrite(ledd, LOW);
    delay(200);
    }
  x=!x;
}
 
