// Huso
// developed by Huso

#define TRIG_PIN 7
#define ECHO_PIN 6
#define BUZZER_PIN 8

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  long duration, distance;

  // Mesafe sensöründen okuma için tetikleme
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Echo süresini ölçme
  duration = pulseIn(ECHO_PIN, HIGH);

  // Mesafeyi hesaplama (ses hızı 340 m/s olarak kabul edilir)
  distance = (duration * 0.0343) / 2;

  // Burası boşta by Huso
  // Mesafeyi seri monitöre yazdırma
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");

//Detaylı Frekans Ms Ayarları // by Huso

  // Mesafe değerine göre buzzer kontrolü
  if (distance < 10) {
    // Mesafe 10 cm'den küçükse buzzer daha hızlı çalar
    tone(BUZZER_PIN, 1000, 100); // Frekans: 1000 Hz, Süre: 100 ms
  } else if (distance < 20) {
    // Mesafe 20 cm'den küçükse buzzer orta hızda çalar
    tone(BUZZER_PIN, 1000, 150); // Frekans: 1000 Hz, Süre: 150 ms
  } else if (distance < 30) {
    // Mesafe 30 cm'den küçükse buzzer daha düşük bir frekansta çalar
    tone(BUZZER_PIN, 1000, 200); // Frekans: 1000 Hz, Süre: 200 ms
  } else if (distance < 50) {
    // Mesafe 50 cm'den küçükse buzzer daha düşük bir frekansta çalar
    tone(BUZZER_PIN, 1000, 250); // Frekans: 1000 Hz, Süre: 250 ms
  } else {
    // Mesafe 50 cm veya daha fazlaysa buzzer kapatılır
    noTone(BUZZER_PIN);
  }

  // Bekleme süresi
  delay(200);
}

//tone(BUZZER_PIN, frekans, süre); bu değerleri kullanarak veri işliyoruz

// developed by Huso
// HUSO
