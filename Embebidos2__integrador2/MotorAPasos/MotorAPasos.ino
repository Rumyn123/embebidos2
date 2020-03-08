int A = 8;
int B = 9;
int C = 10;
int D = 11;

void setup() {
 for(int i = 8; i <12; i++){
  pinMode(i, OUTPUT);
 }
 Serial.begin(9600); 
}

void mensaje(char m[]){
  Serial.println(m);
}

void on(){
  for(int i = 8; i <12; i++){
        digitalWrite(i, LOW);
      }
  mensaje("Entrando al on sin parametros");
}

void on(int q){
  for(int i = 8; i <12; i++){
        digitalWrite(i, LOW);
      }
  digitalWrite(q, HIGH);
  mensaje("Entrando al on con 1 parametro");
}

void on(int q, int w){
  for(int i = 8; i <12; i++){
        digitalWrite(i, LOW);
      }
  digitalWrite(q, HIGH);
  digitalWrite(w, HIGH);
  mensaje("Entrando al on con 2 parametros");
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
}

void loop() {
  switch(Serial.read()){
    case 48: //es cuando presionas 0
    paso(0);
    break;
    case 49: //es cuando presionas 1
    paso(1);
    break;
    case 50: //es cuando presionas 2
    paso(2);
    break;
  }
  delay(1000);
}
