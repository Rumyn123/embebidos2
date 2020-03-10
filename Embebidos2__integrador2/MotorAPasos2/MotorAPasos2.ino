#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int A = 8;
int B = 9;
int C = 10;
int D = 11;

int pActual;
void setup() {
 for(int i = 8; i <12; i++){
  pinMode(i, OUTPUT);
 }
 Serial.begin(9600);
 pActual=0; 
 dht.begin();
}

void mensaje(char m[]){
  Serial.println(m);
}

void on(){
  for(int i = 8; i <12; i++){
        digitalWrite(i, LOW);
      }
}

void on(int q){
  for(int i = 8; i <12; i++){
        digitalWrite(i, LOW);
      }
  digitalWrite(q, HIGH);
}

void on(int q, int w){
  for(int i = 8; i <12; i++){
        digitalWrite(i, LOW);
      }
  digitalWrite(q, HIGH);
  digitalWrite(w, HIGH);
}

void paso(int p){
  switch(p){
    case 0:
      on();
      
    break;
    case 1:
      on(A);
      
    break;
    case 2:
      on(A,B);
      
    break;
    case 3:
      on(B);
      
    break;
    case 4:
      on(B,C);
      
    break;
    case 5:
      on(C);
      
    break;
    case 6:
      on(C,D);
      
    break;
    case 7:
      on(D);
      
    break;
    case 8:
      on(D,A);
      
    break;
  }
  delay(10);
}

void pasoIzquierda(int c){
  for(int a = 0; a < c; a++){
      paso(8);
      paso(7);
      paso(6);
      paso(5);
      paso(4);
      paso(3);
      paso(2);
      paso(1);
    }
    paso(0);
}

void pasoDerecha(int c){
  for(int a = 0; a < c; a++){
      paso(1);
      paso(2);
      paso(3);
      paso(4);
      paso(5);
      paso(6);
      paso(7);
      paso(8);
    }
    paso(0);
}
int cont=0;
int tActual=0;
int cambio=0;
void temp(int t){
  delay(100);
  if(cont == 0){
    pActual = t*8;
    pasoDerecha(pActual);
    cont++;
    tActual = t;
    delay(100);
  } else if(t > tActual){
    delay(100);
    cambio = t - tActual;
    pasoDerecha(cambio*8);
    tActual = t;
  } else if(t == tActual){
    delay(100);
  } else if(t < tActual){
    delay(100);
    cambio = tActual - t;
    pasoIzquierda(cambio*8);
    tActual = t;
    
  }
  
}
int z=0;
int anterior =100;
void loop() {
  while(z==0){
    if(Serial.read()==48){
      z++;
    }
  }
  float temperatura = dht.readTemperature();
  int help = (int) temperatura;
  if(anterior != help){
    Serial.println(help);
    anterior = help;  
  }
  delay(100);
  temp(help);
  

}
