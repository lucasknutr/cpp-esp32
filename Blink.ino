int LED_BUILTIN = 2;
int BUTTON_PIN = 5;
int RELE1 = 21;
int RELE2 = 19;
int SONDA = 23;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SONDA, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(1000);
    Serial.println("SIGNAL");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
  } else if (digitalRead(SONDA) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("SINAL TA MASSA");
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
