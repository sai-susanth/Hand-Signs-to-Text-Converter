#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX

int flex1 = A0;
int flex2 = A1;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  int val1 = analogRead(flex1);
  int val2 = analogRead(flex2);

  Serial.print("Flex1: "); Serial.print(val1);
  Serial.print(" | Flex2: "); Serial.println(val2);

  // Example thresholds - you’ll calibrate these!
  if (val1 > 169 ) {
    BTSerial.println("Hello");
    Serial.println("Sent: hello");
    delay(500);
  }
  else if (val1 < 168 ) {
    BTSerial.println("Hi");
    Serial.println("Sent: Hi");
    delay(500);
  }
}
