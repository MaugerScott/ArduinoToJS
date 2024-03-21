#include <SimpleWebSerial.h>
SimpleWebSerial WebSerial;

int switchState = 0;

void setup() {
  Serial.begin(57600);

  pinMode(2, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  WebSerial.on("led", toggleLed);
  WebSerial.send("log", "hello world");
}


void toggleLed(JSONVar state) {
    // digitalWrite(10, HIGH);
  WebSerial.send("log", "hello world");
  WebSerial.send("log", state);
  if ((bool)state == true) {
    // digitalWrite(ledPin, HIGH);
    digitalWrite(9, LOW);

  } else {
    // digitalWrite(ledPin, LOW);  //     
    digitalWrite(9, HIGH);

  }
}
int heat = 0;

void loop() {
  heat ++;
  WebSerial.check();
  delay(5);

  switchState = digitalRead(2);

  if (switchState == HIGH) {
   WebSerial.send("log", "CLICKEDDDDDDD");
   WebSerial.send("clicked", heat);
  }
  
}