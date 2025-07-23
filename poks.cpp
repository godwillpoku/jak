// Diode Signal Detector on ESP32
// GPIO 25 is used to detect high/low voltage after a diode.
// Ensure the ground is shared between the signal source and ESP32.

const int signalPin = 25; // GPIO25 (connected after diode)

void setup() {
  Serial.begin(115200);
  
  // Use INPUT_PULLDOWN if the line could be floating when low
  pinMode(signalPin, INPUT_PULLDOWN);
}

void loop() {
  bool signalState = digitalRead(signalPin);

  if (signalState == HIGH) {
    Serial.println("High voltage detected!");
  } else {
    Serial.println("No high voltage detected (safe).");
  }

  delay(500); // wait 500 ms
}