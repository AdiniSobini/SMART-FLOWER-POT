#define LED_PIN     5
#define LED_PIN_2   0  
#define POWER_PIN   8
#define SIGNAL_PIN  A3
#define THRESHOLD   400
#define ERROR_MARGIN 0.05  // ±10%

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

  // Calculate the upper and lower bounds for the threshold with error margin
  int lowerBound = THRESHOLD - (THRESHOLD * ERROR_MARGIN);
  int upperBound = THRESHOLD + (THRESHOLD * ERROR_MARGIN);

  // Check if the value is within the acceptable error margin range
  if (value > upperBound) {
    Serial.print("The water is detected");
    digitalWrite(LED_PIN, HIGH);  // turn LED ON
    digitalWrite(LED_PIN_2, LOW); // turn second LED OFF
  } 
  else if (value < lowerBound) {
    Serial.print("The water isn't detected");
    digitalWrite(LED_PIN, LOW);   // turn LED OFF
    digitalWrite(LED_PIN_2, HIGH); // turn second LED ON
  }
  else {
    Serial.print("The water detection is uncertain");
    digitalWrite(LED_PIN, LOW);   // turn LED OFF
    digitalWrite(LED_PIN_2, LOW); // turn second LED OFF
  }

  delay(500);  // delay for a while to stabilize the reading
}
