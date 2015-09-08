 /*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Define pin locations
int ledR1 = 11;
int ledR2 = 6;
int ledY1 = 10;
int ledY2 = 9;
int button = 8;
String IRsensor = 'A0';

// Initialize variables
unsigned long time;
int count = 0;
int buttonState = 0;
int prevState = 0;
int distance = 0;

// the setup routine runs once when you press reset:
void setup() {
	// Initialize pin modes
	pinMode(ledR1, OUTPUT);
	pinMode(ledR2, OUTPUT);
	pinMode(ledY1, OUTPUT);
	pinMode(ledY2, OUTPUT);
	pinMode(button, INPUT);

	// Initialize serial output
	Serial.begin(9600);  
}

void loop() {
	distance = analogRead(IRsensor);
  	buttonState = digitalRead(button);
	time = millis();
	Serial.println(distance);
    // Serial.println(buttonState);
    // Serial.println(count);
    // Serial.println(prevState);
  
  
	// if(prevState == 1 && buttonState == 0) {
	// 	count ++;
	// }

	// if (count%2 == 0) {
	// 	digitalWrite(ledR1, HIGH);   // turn the LED on (HIGH is the voltage level)
	// 	digitalWrite(ledR2, HIGH);

	// 	if (time%2000 < 1000) {
	// 		digitalWrite(ledY1, HIGH);   // turn the LED on (HIGH is the voltage level)
	// 		digitalWrite(ledY2, HIGH);
	// 	}
	// 	else {
	// 		digitalWrite(ledY1, LOW);    // turn the LED off by making the voltage LOW
	// 		digitalWrite(ledY2, LOW);
	// 	}   
	 
	// }

	// else {
	// 	if (time%2000 < 1000) {
	// 		digitalWrite(ledR1, HIGH);   // turn the LED on (HIGH is the voltage level)
	// 		digitalWrite(ledR2, HIGH);
	// 	}
	// 	else {
	// 		digitalWrite(ledR1, LOW);    // turn the LED off by making the voltage LOW
	// 		digitalWrite(ledR2, LOW);
	// 	}
	// }

	// prevState = digitalRead(button);
}