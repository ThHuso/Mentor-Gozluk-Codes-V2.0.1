// Huso Dev
// By Huso

const int buzzerPin = 3;
long buzzerBeepDuration = 40;
long buzzerBeepMillis = 0;
long buzzerFrequencyDuration = 0;
long buzzerPreviousBeepMillis = 0;
float mmToBuzzerFrequencyMultiplier = 0.6;
const int thresholdDistance = 500; // Buzzerın çalmasının durması için eşik uzaklık değeri (mm cinsinden)

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  calibrationWarning(3000, 500, 100);
}

void loop() {
  long mm = analogRead(0) * 5;
  
  // Eşik değerin üzerindeyse buzzer'ın çalmasını durdur
  if (mm >= thresholdDistance) {
    digitalWrite(buzzerPin, LOW);
    Serial.println("Buzzer durduruldu.");
  } else {
    buzzerFrequencyDuration = mm * mmToBuzzerFrequencyMultiplier;
    if (buzzerPreviousBeepMillis + buzzerFrequencyDuration < millis()) {
      buzzerPreviousBeepMillis = millis();
      buzzerBeepMillis = millis() + buzzerBeepDuration;
      digitalWrite(buzzerPin, HIGH);
    }
    if (buzzerBeepMillis < millis()) {
      digitalWrite(buzzerPin, LOW);
    }
    Serial.println(buzzerFrequencyDuration);
  }

  delay(5);
}

void calibrationWarning(int totalDur, int beepDur, int silenceDur) {
  int oneBeep = beepDur + silenceDur;
  for (int i = 0; i < totalDur; i += oneBeep) {
    digitalWrite(buzzerPin, HIGH);
    delay(beepDur);
    digitalWrite(buzzerPin, LOW);
    delay(silenceDur);
  }
}

// Huso Dev
// By Huso
