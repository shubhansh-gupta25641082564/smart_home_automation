#include <ESP8266WiFi.h>
#include <Servo.h>
WiFiClient client;
WiFiServer server(80);
Servo myservo;
const int relayPins[] = {D0, D1, D2, D3, D4, D5};
int trigPin = D6;
int echoPin = D7;
int servoPin = D8;
void setup()
{
  Serial.begin(9600);
  WiFi.begin("Radha rani ki jai" , "Rachit1234");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".........");
    delay(2000);
  }
  Serial.println();
  Serial.println("NodeMCU is Connected!");
  Serial.println(WiFi.localIP());
  server.begin();
  for (int i = 0; i < 6; i++)
  {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], HIGH);
  }
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
  myservo.write(0);
}
void loop()
{
  client = server.available();
  if (client == 1)
  {
    String request = client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /switch_on_the_living_room_light HTTP/1.1")
    {
      digitalWrite(relayPins[0], LOW);
    }
    if(request == "GET /switch_off_the_living_room_light HTTP/1.1")
    {
      digitalWrite(relayPins[0], HIGH);
    }
    if(request == "GET /switch_on_the_living_room_fan HTTP/1.1")
    {
      digitalWrite(relayPins[1], LOW);
    }
    if(request == "GET /switch_off_the_living_room_fan HTTP/1.1")
    {
      digitalWrite(relayPins[1], HIGH);
    }
    if(request == "GET /switch_on_the_bedroom_light HTTP/1.1")
    {
      digitalWrite(relayPins[2], LOW);
    }
    if(request == "GET /switch_off_the_bedroom_light HTTP/1.1")
    {
      digitalWrite(relayPins[2], HIGH);
    }
    if(request == "GET /switch_on_the_bedroom_fan HTTP/1.1")
    {
      digitalWrite(relayPins[3], LOW);
    }
    if(request == "GET /switch_off_the_bedroom_fan HTTP/1.1")
    {
      digitalWrite(relayPins[3], HIGH);
    }
    if(request == "GET /switch_on_the_kitchen_light HTTP/1.1")
    {
      digitalWrite(relayPins[4], LOW);
    }
    if(request == "GET /switch_off_the_kitchen_light HTTP/1.1")
    {
      digitalWrite(relayPins[4], HIGH);
    }
    if(request == "GET /switch_on_the_bathroom_light HTTP/1.1")
    {
      digitalWrite(relayPins[5], LOW);
    }
    if(request == "GET /switch_off_the_bathroom_light HTTP/1.1")
    {
      digitalWrite(relayPins[5], HIGH);
    }
  }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  if (distance<15)
  {
    myservo.write(90);
    delay(2000);
  }
  else
  {
    myservo.write(0);
    delay(1000);
  }
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}