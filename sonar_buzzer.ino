#define trigPin 12
#define echoPin 13

int buzzer = 8;
int ledPin = 6;
int duration, distance;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  //condition
  if (distance >= 100 || distance <= 0)
  {
    digitalWrite(buzzer, 0);
    Serial.println("object not Detected \n");

    digitalWrite(ledPin, LOW);

  }
  else
  {

    Serial.println("object Detected \n");
    Serial.println("Distance: ");
    Serial.print(distance);
    tone(buzzer, 50);
    digitalWrite(ledPin, HIGH);
  }
}
