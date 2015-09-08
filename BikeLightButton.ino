 /*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledR1 = 11;
int ledR2 = 6;
int ledY1 = 10;
int ledY2 = 9;
int button = 8;
unsigned long time;
int count = 0;
int prevState = 0;

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
  int buttonState = digitalRead(button);
  time = millis();
    Serial.println(buttonState);
    Serial.println(count);
    Serial.println(prevState);
  
  
  if(prevState == 1 && buttonState == 0) {
    count ++;
  }
  
  if (count%2 == 0) {
    digitalWrite(ledR1, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledR2, HIGH);
    
    if (time%2000 < 1000) {
      digitalWrite(ledY1, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(ledY2, HIGH);
    }
    else {
      digitalWrite(ledY1, LOW);    // turn the LED off by making the voltage LOW
      digitalWrite(ledY2, LOW);
    }   
     
  }
  
  else {
    if (time%2000 < 1000) {
      digitalWrite(ledR1, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(ledR2, HIGH);
    }
    else {
    digitalWrite(ledR1, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(ledR2, LOW);
    }
  }
 prevState = digitalRead(button); 
}