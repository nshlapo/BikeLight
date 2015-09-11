 /*
  BikeLight
  Different LED patterns execute based on the state defined by button presses.
 */

// define pin numbers
int ledR1 = 11;
int ledR2 = 6;
int ledY1 = 10;
int ledY2 = 9;
int button = 2;

// initialize variables to be used later
unsigned long time;
int count = 0;
int prevState = 0;
int buttonState = 0;
boolean increment = false;
int dBounce = 100;
int timePressed = 0;
int prevTimePress = 0;
int blinkTime = 300;

void setup() {
  // define pin modes
  pinMode(ledR1, OUTPUT);
  pinMode(ledR2, OUTPUT);
  pinMode(ledY1, OUTPUT);
  pinMode(ledY2, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  buttonState = digitalRead(button);
  time = millis();

  // check for the release of the button
  if(prevState == 1 && buttonState == 0) {
    count ++;
  }

  // this switch case executes certain light patterns based on the number of
  //times the button has been pressed
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

      if (time%(2*blinkTime) < (1.5*blinkTime)) {      //red flashing
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

      if (time%(2*blinkTime) < (1.5*blinkTime)) {      // yelow flashing
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
  prevState = buttonState; // define old button state to use in the next loop
}