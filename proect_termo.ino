// Parametrii pentru conversie
float resolutionADC = .0049;   // 5V / 1023
float resolutionSensor = .01;  // 10mV per grad (0.01V)

void setup() {
  Serial.begin(9600);
}

void loop() {
  // --- TEMPERATURA ---
  // Citim de pe pinul A0 (verifica daca acolo ai senzorul temp!)
  // Daca senzorul de temperatura e pe alt pin, schimba A0 cu A2 de exemplu
  float temp = readTempInCelsius(10, A0); 
  
  Serial.print("Temp [C]: ");
  Serial.print(temp);

  // --- LUMINA ---
  // Citim de pe pinul A1
  int lightValue = analogRead(A1); 

  Serial.print(" | Lumina (");
  Serial.print(lightValue); // Afisam si numarul ca sa vedem ce se intampla
  Serial.print("): ");

  // --- AICI SUNT NOILE VALORI CALIBRATE ---
  if (lightValue < 20) {
    // Daca valoarea scade sub 40 (cand acoperi senzorul)
    Serial.println("INTUNERIC");
  }
  else if (lightValue < 80) {
    // Daca e intre 40 si 80 (valorile tale de camera sunt 50-70)
    Serial.println("NORMAL");
  }
  else {
    // Daca e mai mare de 80 (cand pui lanterna)
    Serial.println("LUMINAT");
  }

  delay(500); // O mică pauză ca să poți citi datele
}

// Funcție pentru citirea temperaturii cu mediere
float readTempInCelsius(int count, int pin) {
  float sumTemp = 0;

  for (int i = 0; i < count; i++) {
    int reading = analogRead(pin);
    float voltage = reading * resolutionADC;
    float tempCelsius = (voltage - 0.5) / resolutionSensor; 
    
    sumTemp = sumTemp + tempCelsius;
    delay(10); 
  }

  return sumTemp / (float)count;
}
