int LED_BUILTIN = 2;
int SONDA = 23;
int RELE1 = 21;
int RELE2 = 19;
int TERMOMETRO = 12;
int BUTTON_PIN = 5;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SONDA, INPUT_PULLUP);
  pinMode(RELE1, OUTPUT);
  pinMode(RELE2, OUTPUT);
  pinMode(TERMOMETRO, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // Envia sinal para o receptor (no caso, a Jetson), será utilizado para desligamento do aparelho 
  // Verifica se a sonda está conectada
  while(digitalRead(SONDA) == HIGH) {
    if(digitalRead(BUTTON_PIN) == LOW){
      digitalWrite(RELE2, HIGH);
      delay(1000);
      digitalWrite(RELE1, HIGH);
    }
    else if (digitalRead(LED_BUILTIN) == HIGH) {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }

  if(digitalRead(BUTTON_PIN) == LOW){
    digitalWrite(RELE2, LOW);
    delay(1000);
    digitalWrite(RELE1, LOW);
  }
  else if (digitalRead(LED_BUILTIN) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
