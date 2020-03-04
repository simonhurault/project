const byte diodePin = 2;
volatile int timePulse = 0;
volatile int lastTimePulse = 0;
volatile int frame[10];
volatile bool frameStart;
volatile int indexFrame = 0;
volatile bool frameIsComplete = false;

void setup() {
  pinMode(diodePin, INPUT); 
  attachInterrupt(digitalPinToInterrupt(diodePin), addValue, CHANGE);
  Serial.begin(9600);
  frameStart = false;
}

void loop() {
  if(frameIsComplete)
  {
    for(int i; i < 10; i++)
    {
      Serial.print(frame[i]);
    }
    Serial.println(" ");
  }
}

void addValue(){
  timePulse = millis() - lastTimePulse;
  lastTimePulse = timePulse;
  if(!frameStart)
  {
    frame[0] = 0;
    indexFrame = 0;
  }
  else
  {
    if(timePulse < 60 && timePulse > 40)
    {
      frame[indexFrame] = 1;
    }
    else if(timePulse < 110 && timePulse > 90)
    {
      frame[indexFrame] = 0;
    }
  }

  if(indexFrame == 9)
      {
        indexFrame=0;
        frameIsComplete = true;
      }
  else
    indexFrame++;
    frameIsComplete = false;
}
