int buzzerPin = 10; // Buzzer pin 
int buttonPin = 11; //button pin number
int ledPin = 6; //LED pin number
const int toneFreq = 520; //the tone frequency that I decided to use


void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
  pinMode(12, INPUT);// Input from sensor
  pinMode(13, OUTPUT);// OUTPUT to alarm or LED
  pinMode(buzzerPin, OUTPUT); // output to buzzer
  pinMode(ledPin, OUTPUT); // output to LED
  pinMode(buttonPin, INPUT); // input to Button
}

void loop() {
 int buttonState = digitalRead(buttonPin);
  if (buttonState==HIGH) 
  {
    digitalWrite(ledPin, HIGH); // if the button is pressed LED turns on 
    tone(buzzerPin, toneFreq); // if the button is pressed buzzer will sound
  } 
  else
  {
    digitalWrite(ledPin, LOW); 
    noTone(buzzerPin);  // if the button is not pressed the buzzer and LED turn off
  }                       
  int motion =digitalRead(2);
  if(motion){ 
    Serial.println("Motion detected"); // if there is motion prints Motion detected. 
    digitalWrite(13,HIGH);
  }else{
     Serial.println("=nothing moves"); // when there is no motion it will print "nothing moves"
     digitalWrite(13,LOW);
  }
  delay(500);
}
  
 
