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
  // Verifica se a sonda está conectada
  while(digitalRead(SONDA) == HIGH) {
    // Se a sonda não estiver conectada e o botão for pressionado, liga os reles e o led
    if(digitalRead(BUTTON_PIN) == LOW){
      digitalWrite(RELE2, HIGH);
      delay(1000);
      digitalWrite(RELE1, HIGH);
    }
    else if (digitalRead(LED_BUILTIN) == HIGH) {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
  // Se a sonda estiver conectada, e o botão for pressionado, desliga os reles e o led
  if(digitalRead(BUTTON_PIN) == LOW){
    digitalWrite(RELE2, LOW);
    delay(1000);
    digitalWrite(RELE1, LOW);
    Serial.println("SIGNAL");
  }
  else if (digitalRead(LED_BUILTIN) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
