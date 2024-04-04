void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int state= digitalRead(12);
  Serial.println(state);

  if (state==HIGH)
  {
    digitalWrite(13,HIGH);
    
  }
  else{
    digitalWrite(13,LOW);
  }

}
