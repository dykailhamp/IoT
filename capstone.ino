#define BUTTON_PIN 32  // Pin tempat tombol terhubung
#define BUZZER_PIN 25
#define PIR_PIN 13

void setup() {
  Serial.begin(115200);            // Memulai komunikasi serial
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);      // Set pin 14 sebagai input
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  int pirState = digitalRead(PIR_PIN);

  if (buttonState == HIGH) {  // Jika tombol ditekan dan ada aliran listrik (HIGH)
    Serial.println("Tombol ditekan!");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);  // Delay kecil untuk debouncing
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

 if (pirState == HIGH) {
     Serial.println("Gerakan Terdeteksi!");
   }

  Serial.println(pirState);

  delay(1000);
}
