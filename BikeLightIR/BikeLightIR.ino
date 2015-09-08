 /*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

// Define pin numbers
int ledR1 = 11;
int ledR2 = 6;
int ledY1 = 10;
int ledY2 = 9;
int button = 8;

unsigned long time;
int count = 0;
int prevState = 0;
int buttonState = 0;
boolean increment = false;
int dBounce = 100;
int timePressed = 0;
int prevTimePress = 0;
int blinkTime;
float distance;
float blinkRatio;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(ledR1, OUTPUT);
  pinMode(ledR2, OUTPUT);
  pinMode(ledY1, OUTPUT);
  pinMode(ledY2, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
	distance = analogRead(A0);
	distance = map(distance, 0, 1023, 0, 500);
	distance = float(distance)/100;
	if (distance < .8) {
		blinkTime = 300;
		blinkRatio = 1;
	}
	else if (distance < 2) {
		blinkTime = 150;
		blinkRatio = 1.5;
	}
	else {
		blinkTime = 50;
		blinkRatio = 1;
	}
	Serial.println(distance);
  buttonState = digitalRead(button);
  time = millis();
    // Serial.println(String(buttonState) + "//" + String(prevState) + "//" + String(count));
    // Serial.println(distance/100);
  if(prevState == 1 && buttonState == 0) { //check for button press and release
    count ++;
  }

  switch(count%6) {
    case 0:                       // all off
      digitalWrite(ledY1, LOW);
      digitalWrite(ledY2, LOW);
      digitalWrite(ledR1, LOW);
      digitalWrite(ledR2, LOW);
      break;

    case 1:
    case 5:
      digitalWrite(ledY1, LOW);    //yellow off
      digitalWrite(ledY2, LOW);

      if (time%(2*blinkTime) < (blinkRatio*blinkTime)) {      //red flashing
        digitalWrite(ledR1, HIGH);
        digitalWrite(ledR2, HIGH);
      }

      else {
      digitalWrite(ledR1, LOW);
      digitalWrite(ledR2, LOW);
      }

      break;

    case 2:
    case 4:
      digitalWrite(ledR1, HIGH);   // red on
      digitalWrite(ledR2, HIGH);

      if (time%(2*blinkTime) < (blinkRatio*blinkTime)) {  // yelow flashing
        digitalWrite(ledY1, HIGH);
        digitalWrite(ledY2, HIGH);
      }

      else {
        digitalWrite(ledY1, LOW);
        digitalWrite(ledY2, LOW);
      }

      break;

    case 3:                      // all on
      digitalWrite(ledY1, HIGH);
      digitalWrite(ledY2, HIGH);
      digitalWrite(ledR1, HIGH);
      digitalWrite(ledR2, HIGH);
      break;
  }
  prevState = buttonState; // check if button was released
}