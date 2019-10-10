// Define the state of the buttons.
bool ButtonState1 = HIGH;
bool ButtonState2 = HIGH;
bool ButtonState3 = HIGH;
bool ButtonState4 = HIGH;
bool ButtonState5 = HIGH;
bool ButtonState6 = HIGH;
bool ButtonState7 = HIGH;

//Define boolean State as LOW at the beginning.
bool State = LOW;

//Define the five nodes with fixed frequencies.
long a = 440;
long c = 261.63;
long d = 293.66;
long e = 329.63;
long g = 392.00;

//Initialise the frequencies of five variables.
long frequency1 = c;
long frequency2 = d;
long frequency3 = e;
long frequency4 = g;
long frequency5 = a;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  ButtonState1 = digitalRead(8);
  ButtonState2 = digitalRead(7);
  ButtonState3 = digitalRead(6);
  ButtonState4 = digitalRead(5);
  ButtonState5 = digitalRead(4);
  ButtonState6 = digitalRead(3);
  ButtonState7 = digitalRead(2);

  if(ButtonState1 == LOW | ButtonState2 == LOW | ButtonState3 == LOW | ButtonState4 == LOW | ButtonState5 == LOW){
    State = HIGH;
  }
  
  if(ButtonState1 == HIGH && ButtonState2 == HIGH && ButtonState3 == HIGH && ButtonState4 == HIGH && ButtonState5 == HIGH){
    State = LOW;
  }

  if(ButtonState6 == LOW){
    frequency1 = c/2;
    frequency2 = d/2;
    frequency3 = e/2;
    frequency4 = g/2;
    frequency5 = a/2; 
  }
  else if(ButtonState7 == LOW){
    frequency1 = c*2;
    frequency2 = d*2;
    frequency3 = e*2;
    frequency4 = g*2;
    frequency5 = a*2; 
  }
  else{
    frequency1 = c;
    frequency2 = d;
    frequency3 = e;
    frequency4 = g;
    frequency5 = a; 
  }

  if(State == HIGH){
    if(ButtonState1 == LOW){
      tone(13,frequency1);
      // delay(100);
      //noTone(13);
    }
    if(ButtonState2 == LOW){
      tone(13,frequency2);
      // delay(100);
      //noTone(13);
    }
    if(ButtonState3 == LOW){
      tone(13,frequency3);
      // delay(100);
      //noTone(13);
    }
    if(ButtonState4 == LOW){
      tone(13,frequency4);
      // delay(100);
      //noTone(13);
    }
    if(ButtonState5 == LOW){
      tone(13,frequency5);
      // delay(100);
      //noTone(13);
    }
  }
  else{
    noTone(13);
  }
  Serial.print(ButtonState6);
  Serial.print(frequency1);
  Serial.println();
}
