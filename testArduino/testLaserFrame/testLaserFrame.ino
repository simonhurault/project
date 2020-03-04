const int pinLaser = 3;
int frame[10] = {0,1,1,1,1,0,0,0,1,0};
volatile int state = 1;

void setup() {
  pinMode(pinLaser, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  // Send first bit
  digitalWrite(pinLaser, state);
  state = !state;

  // Send the rest of the frame
  for(int i = 1; i < 10; i++)
  {
  //Serial.println("A");
    if( frame[i] == 1)
    {
      delay(45);
      Serial.println("1");
      digitalWrite(pinLaser, state);
    }
    else
    {
      delay(95);
      Serial.println("2");
      digitalWrite(pinLaser, state);
    }
    state = !state;
  }
  state = 1;
  delay(5000);
  
}
