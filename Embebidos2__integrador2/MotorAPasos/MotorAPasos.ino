
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
  delay(5000);
  if(cont == 0){
    pActual = t*8;
    pasoDerecha(pActual);
    cont++;
    tActual = t;
    mensaje("Temperatura actual es ");
    Serial.println(t);
    delay(2000);
  } else if(t > tActual){
    mensaje("Entro en el t mayor a tActual");
    mensaje("tActual es: ");
    Serial.println(tActual);
    mensaje("t es: ");
    Serial.println(t);
    delay(2000);
    cambio = t - tActual;
    pasoDerecha(cambio*8);
    tActual = t;
  } else if(t == tActual){
    mensaje("Entro en el t igual a tActual");
    mensaje("tActual es: ");
    Serial.println(tActual);
    mensaje("t es: ");
    Serial.println(t);
    delay(2000);
  } else if(t < tActual){
    mensaje("Entro en el t menor a tActual");
    mensaje("tActual es: ");
    Serial.println(tActual);
    mensaje("t es: ");
    Serial.println(t);
    delay(2000);
    cambio = tActual - t;
    pasoIzquierda(cambio*8);
    tActual = t;
    
  }
  
}

void loop() {
  switch(Serial.read()){
    case 48: //es cuando presionas 0
    paso(0);
    break;
    case 49: //es cuando presionas 1
    pasoIzquierda(512);
    break;
    case 50: //es cuando presionas 2
    pasoDerecha(512);
    break;
    case 51: //es cuando presionas 3
    temp(10);
    break;
    case 52: //es cuando presionas 4
    temp(20);
    break;
    case 53: //es cuando presionas 5
    temp(30);
    break;
    case 54: //es cuando presionas 6
    temp(40);
    break;
    case 55: //es cuando presionas 7
    temp(50);
    break;
    case 56: //es cuando presionas 8
    temp(60);
    break;
  }
  delay(1000);
}
