void setup(){
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop(){
  int time = 200;
  for(int i=2;i<12;i++){
    digitalWrite(i, HIGH);
    delay(time);
    digitalWrite(i, LOW);
  }
  for(int i=10;i>2;i--){
    digitalWrite(i, HIGH);
    delay(time);
    digitalWrite(i, LOW);
  }  
}
