const int ledVermelho = 13;
const int ledAmarelo = 12;
const int ledVerde = 11;
const int ledVermelhoPedestre = 10;
const int ledVerdePedestre = 9;

void sinalVermelho(int vermelho) {
  digitalWrite(vermelho, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);
}
void sinalVerde(int verde,int intervalo) {
  digitalWrite(verde, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  sinalVermelhoPedestre(ledVermelhoPedestre);
  delay(intervalo);
  sinalAmarelo(ledAmarelo,2000);
}

void sinalVerdePedestre(int verde, int intervalo) {
  digitalWrite(verde, HIGH);
  digitalWrite(ledVermelhoPedestre, LOW);
  delay(intervalo);
}

void sinalVermelhoPedestre(int vermelho) {
  digitalWrite(ledVermelhoPedestre, HIGH);
  digitalWrite(ledVerdePedestre, LOW);
}

void sinalAmarelo(int amarelo,int intervalo) {
  digitalWrite(ledAmarelo,HIGH);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);
  delay(intervalo);
}


void sinalVermelhoPiscantePedestre(int tempoTotal) {
  unsigned long tempoInicial = millis();
  while(millis() - tempoInicial < tempoTotal) {
    digitalWrite(ledVermelhoPedestre, HIGH);
    delay(500);
    digitalWrite(ledVermelhoPedestre, LOW);
    delay(500);
  }
}

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelhoPedestre, OUTPUT);
  pinMode(ledVerdePedestre, OUTPUT);
}

void loop() {
  sinalVermelho(ledVermelho);
  sinalVerdePedestre(ledVerdePedestre, 5000);
  sinalVermelhoPiscantePedestre(5000);
  sinalVerde(ledVerde,5000);
}

