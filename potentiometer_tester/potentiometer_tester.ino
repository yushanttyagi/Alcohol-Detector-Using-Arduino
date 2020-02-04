const int led=13;
int val=0;
const int pot=2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(pot,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val=analogRead(pot);
  Serial.print(val);
  Serial.print('\n');
  digitalWrite(led,HIGH);
  delay(val);
  digitalWrite(led,LOW);
  delay(val);
}
