const uint8_t DRLoutPin = 3;  // DRL output
const uint8_t offPin  = 7;    // "parking lights on", "handbrake on" input
const uint8_t pwmDRL = 77;    // brightness: 77 = 30%, 90 = 35% ...

uint8_t pwmOut = 0;           // current brightness
uint8_t delta  = 3;           // brightness step

void setup()
{
  pinMode(brakePin, INPUT);
  pinMode(lightPin, INPUT);
  pinMode(DRLoutPin, OUTPUT);

  TCCR2B = TCCR2B & 0xF8 | 6; // set the PWM frequency on pins D3 and D11 to 122 Hz
}

void loop()
{
  if ((digitalRead(offPin) == HIGH) && (pwmOut < pwmDRL)) { // softly light the DRL lamps
    pwmOut = pwmOut + delta;
    if (pwmOut > pwmDRL) { pwmOut = pwmDRL; } 
    analogWrite(DRLoutPin, pwmOut);
  } 
  else {					// DRL lamps Off
    pwmOut = 0;
    digitalWrite(DRLoutPin, LOW);                 
  }
  delay(50);                                    // wait 50 ms        
}
