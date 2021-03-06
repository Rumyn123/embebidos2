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
 Serial.println("Presione 0 para iniciar");
}

void mensaje(char m[]){
  Serial.println(m);
}

void on(){
  for(int i = 8; i <12; i++){
        digitalWrite(i, LOW);
      }
  //mensaje("Entrando al on sin parametros");
}

void on(int q){
  for(int i = 8; i <12; i++){
        digitalWrite(i, LOW);
      }
  digitalWrite(q, HIGH);
  //mensaje("Entrando al on con 1 parametro");
}

void on(int q, int w){
  for(int i = 8; i <12; i++){
        digitalWrite(i, LOW);
      }
  digitalWrite(q, HIGH);
  digitalWrite(w, HIGH);
  //mensaje("Entrando al on con 2 parametros");
}

void paso(int p){
  switch(p){
    case 0:
      on();
      mensaje("Apagando pines");
    break;
    case 1:
      on(A);
      mensaje("Paso 1");
    break;
    case 2:
      on(A,B);
      mensaje("Paso 2");
    break;
    case 3:
      on(B);
      mensaje("Paso 3");
    break;
    case 4:
      on(B,C);
      mensaje("Paso 4");
    break;
    case 5:
      on(C);
      mensaje("Paso 5");
    break;
    case 6:
      on(C,D);
      mensaje("Paso 6");
    break;
    case 7:
      on(D);
      mensaje("Paso 7");
    break;
    case 8:
      on(D,A);
      mensaje("Paso 8");
    break;
  }
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
  mensaje("Temperatura enviada es: ");
  Serial.println(t);
  delay(2500);
  if(cont == 0){
    pActual = t*8;
    pasoDerecha(pActual);
    cont++;
    tActual = t;
    //mensaje("Temperatura actual es ");
    //Serial.println(t);
    delay(100);
  } else if(t > tActual){
    //mensaje("Entro en el t mayor a tActual");
    //mensaje("tActual es: ");
    //Serial.println(tActual);
    //mensaje("t es: ");
    //Serial.println(t);
    delay(100);
    cambio = t - tActual;
    pasoDerecha(cambio*8);
    tActual = t;
  } else if(t == tActual){
    mensaje("Temperatura enviada por el sensor es igual a la temperatura actual");
    //mensaje("tActual es: ");
    //Serial.println(tActual);
    //mensaje("t es: ");
    //Serial.println(t);
    delay(100);
  } else if(t < tActual){
    //mensaje("Entro en el t menor a tActual");
    //mensaje("tActual es: ");
    //Serial.println(tActual);
    //mensaje("t es: ");
    //Serial.println(t);
    delay(100);
    cambio = tActual - t;
    pasoIzquierda(cambio*8);
    tActual = t;
    
  }
  
}
int z=0;
void loop() {
  //mensaje("Comenzando medicion");
  //delay(5000);
  while(z==0){
    if(Serial.read()==48){
      mensaje("Comenzando medicion!");
      z++;
    }
  }
  float temperatura = dht.readTemperature();
  int help = (int) temperatura;
  mensaje("Temperatura del sensor es de");
  Serial.println(help);
  delay(2500);
  temp(help);
  

}
