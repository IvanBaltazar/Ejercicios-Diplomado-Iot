#define POWER_PIN  12 // 
#define SIGNAL_PIN 13 // 

int nivel = 0; 

void setup() {
  Serial.begin(115200);
  pinMode(POWER_PIN, OUTPUT);   
  digitalWrite(POWER_PIN, LOW); 
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  
  delay(10);                      
  nivel = analogRead(SIGNAL_PIN); 
  digitalWrite(POWER_PIN, LOW);   

  Serial.print("Nivel: ");
  Serial.println(nivel);

  delay(1000);
}