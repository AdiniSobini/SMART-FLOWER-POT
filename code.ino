
#define LED_PIN     2
#define LED_PIN_2   4
#define POWER_PIN   8
#define SIGNAL_PIN  A0
#define THRESHOLD   400


int value = 0; // variable to store the sensor value

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN,   OUTPUT);   // configure D2 pin as an OUTPUT
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
  digitalWrite(LED_PIN,   LOW); // turn LED OFF



}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF









  if (value > THRESHOLD) {
    Serial.print("The water is detected");
    digitalWrite(LED_PIN, HIGH);  // turn LED ON
  } 
  else {
    digitalWrite(LED_PIN, LOW);   // turn LED OFF
  
 
  }

  if (value < THRESHOLD){
  
  Serial.print("The water isn't detected");
  digitalWrite(LED_PIN_2, HIGH);   // turn LED OFF
  }
  else {  
    digitalWrite(LED_PIN_2, LOW);  // turn LED ON



   





  }
}
