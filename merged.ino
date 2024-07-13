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
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE html>");
  client.println("<html>");
  client.println("    <head>");
  client.println("        <link rel='preconnect' href='https://fonts.googleapis.com'>");
  client.println("        <link rel='preconnect' href='https://fonts.gstatic.com' crossorigin>");
  client.println("        <link href='https://fonts.googleapis.com/css2?family=Poppins:wght@500&display=swap' rel='stylesheet'>");
  client.println("        <style>");
  client.println("            body{margin: 0;padding: 0;font-family: 'Poppins', sans-serif;background-color: rgb(14, 16, 79);}");
  client.println("            header{background-color: rgb(0, 0, 0);color: white;text-align: center;padding: 20px;}");
  client.println("            #iotButton{background-color: transparent;color: white;border: none;cursor: pointer;font-size: 16px;}");
  client.println("            #dropdownMenu{display: none;position: absolute;background-color: black;min-width: 160px;box-shadow: 0 8px 16px rgba(0, 0, 0, 0.2);z-index: 1;}");
  client.println("            #dropdownMenu a {color: white;padding: 12px 16px;text-decoration: none;display: block;}");
  client.println("            #dropdownMenu a:hover {background-color: #555;}");
  client.println("            #imageSection {width: 100%;height: 50vh;overflow: hidden;}");
  client.println("            #imageSection img {width: 100%;height: 100%;object-fit: cover;}");
  client.println("            #mainContent {width: 50%;margin: 0 auto;padding: 20px;}");
  client.println("            .toggle-container {display: flex;align-items: center;}");
  client.println("            .toggle-label h1 {margin-right: 20px;color: rgb(0, 255, 174);}");
  client.println("            .toggle-switch {position: relative;display: inline-block;width: 60px;height: 30px;}");
  client.println("            .toggle-slider {position: absolute;cursor: pointer;top: 0;left: 0;right: 0;bottom: 0;background-color: #ccc;border-radius: 30px;transition: .4s;}");
  client.println("            .toggle-slider:before {position: absolute;content: '';height: 26px;width: 26px;left: 2px;bottom: 2px;background-color: white;border-radius: 50%;transition: .4s;}");
  client.println("            .toggle-input {display: none;}");
  client.println("            .toggle-input:checked+.toggle-slider {background-color: #2196F3;}");
  client.println("            .toggle-input:checked+.toggle-slider:before {transform: translateX(30px);}");
  client.println("            .option-button {margin-bottom: 10px;padding: 12px 20px;font-size: 18px;border-radius: 15px;}");
  client.println("            #statusMessage {margin-top: 20px;font-size: 18px;text-align: center;}");
  client.println("            #statusMessage.on {color: blue;}");
  client.println("            #statusMessage.off {color: red;}");
  client.println("            #textMessage {position: absolute;bottom: 20px;right: 20px;font-size: 24px;color: rgb(83, 242, 242);}");
  client.println("            #initialMessage {position: absolute;bottom: -30px;right: 14px;font-size: 38px;color: rgb(0, 255, 174);animation: fadeIn 2s;padding-bottom: 220px;}");
  client.println("            #ledStatus, #fanStatus {margin-top: 10px;font-size: 16px;color: white;}");
  client.println("            @keyframes fadeIn {from {opacity: 0;}to {opacity: 1;}}");
  client.println("        </style>");
  client.println("    </head>");
  client.println("    <body>");
  client.println("        <header>");
  client.println("            <div><h2>Sri Radhe Shyam</h2></div>");
  client.println("            <div><h3>Welcome to Sri Ji's Smart Home</h3></div>");
  client.println("            <button id='iotButton' onclick='toggleDropdown()'>Control Panel For Different Rooms</button>");
  client.println("            <div id='dropdownMenu'>");
  client.println("                <a href='#' onclick='showLivingRoomOptions()'>Living Room</a>");
  client.println("                <a href='#' onclick='showKitchenOptions()'>Kitchen</a>");
  client.println("                <a href='#' onclick='showBathRoomOptions()'>Bed Room</a>");
  client.println("                <a href='#' onclick='showBedRoomOptions()'>Bath Room</a>");
  client.println("            </div>");
  client.println("        </header>");
  client.println("        <div id='imageSection'><img src='https://www.checkboxtechnology.com/wp-content/uploads/2020/09/1_WtdyFZNDahpaoaxMGSCXIw.jpeg' alt='IOT Image'></div>");
  client.println("        <div id='mainContent'>");
  client.println("            <div id='livingRoomOptions' style='display: none;'>");
  client.println("                <img src='https://th.bing.com/th/id/OIP.4hy_hgjhkHUpHrYnki2cOgAAAA?rs=1&pid=ImgDetMain' alt='Living Room Image'>");
  client.println("                <div class='toggle-container'>");
  client.println("                    <span class='toggle-label'><h1>Living Room Light :-</h1></span>");
  client.println("                    <a href=\'/switch_on_the_living_room_light\'\'><button class='option-button' onclick='updateStatus('Living Room Light', true)'>ON</button></a>");
  client.println("                    <a href=\'/switch_off_the_living_room_light\'\'><button class='option-button' onclick='updateStatus('Living Room Light', false)'>OFF</button></a>");
  client.println("                </div>");
  client.println("            <div class='toggle-container'>");
  client.println("                <span class='toggle-label'><h1>Living Room Fan :-</h1></span>");
  client.println("                <a href=\'/switch_on_the_living_room_fan\'\'><button class='option-button' onclick='updateStatus('Living Room Fan', true)'>ON</button></a>");
  client.println("                <a href=\'/switch_off_the_living_room_fan\'\'><button class='option-button' onclick='updateStatus('Living Room Fan', false)'>OFF</button></a>");
  client.println("            </div>");
  client.println("        </div>");
  client.println("        <div id='kitchenOptions' style='display: none;'>");
  client.println("            <img src='https://img.freepik.com/free-photo/3d-rendering-white-minimal-kitchen-with-wood-decoration_105762-2218.jpg?size=626&ext=jpg&ga=GA1.1.1412446893.1705190400&semt=ais' width='500' height='300' alt='Kitchen Image'>");
  client.println("            <div class='toggle-container'>");
  client.println("                <span class='toggle-label'><h1>Kitchen Light :-</h1></span>");
  client.println("                <a href=\'/switch_on_the_kitchen_light\'\'><button class='option-button' onclick='updateStatus('Kitchen Light', true)'>ON</button></a>");
  client.println("                <a href=\'/switch_off_the_kitchen_light\'\'><button class='option-button' onclick='updateStatus('Kitchen Light', false)'>OFF</button></a>");
  client.println("            </div>");
  client.println("        </div>");
  client.println("        <div id='bathRoomOptions' style='display: none;'>");
  client.println("            <img src='https://hips.hearstapps.com/hmg-prod/images/bedroom-ideas-rupp-studiodmitchell-ruppstudio-parkave-06a-1675097820.jpg' width='500' height='300' alt='Bedroom Image'>");
  client.println("            <div class='toggle-container'>");
  client.println("                <span class='toggle-label'><h1>Bedroom Light :-</h1></span>");
  client.println("                <a href=\'/switch_on_the_bedroom_light\'\'><button class='option-button' onclick='updateStatus('Bedroom Light', true)'>ON</button></a>");
  client.println("                <a href=\'/switch_off_the_bedroom_light\'\'><button class='option-button' onclick='updateStatus('Bedroom Light', false)'>OFF</button></a>");
  client.println("            </div>");
  client.println("            <div class='toggle-container'>");
  client.println("                <span class='toggle-label'><h1>Bedroom Fan :-</h1></span>");
  client.println("                <a href=\'/switch_on_the_bedroom_fan\'\'><button class='option-button' onclick='updateStatus('Bedroom Fan', true)'>ON</button></a>");
  client.println("                <a href=\'/switch_off_the_bedroom_fan\'\'><button class='option-button' onclick='updateStatus('Bedroom Fan', false)'>OFF</button></a>");
  client.println("            </div>");
  client.println("        </div>");
  client.println("        <div id='bedRoomOptions' style='display: none;'>");
  client.println("            <img src='https://images.unsplash.com/photo-1584622650111-993a426fbf0a?q=80&w=1000&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxzZWFyY2h8Mnx8YmF0aHJvb218ZW58MHx8MHx8fDA%3D' width='500' height='300' alt='Bathroom Image'>");
  client.println("            <div class='toggle-container'>");
  client.println("                <span class='toggle-label'><h1>Bathroom Light :-</h1></span>");
  client.println("                <a href=\'/switch_on_the_bathroom_light\'\'><button class='option-button' onclick='updateStatus('Bathroom Light', true)'>ON</button></a>");
  client.println("                <a href=\'/switch_off_the_bathroom_light\'\'><button class='option-button' onclick='updateStatus('Bathroom Light', false)'>OFF</button></a>");
  client.println("            </div>");
  client.println("        </div>");
  client.println("        <div id='statusMessage'></div>");
  client.println("        <div id='ledStatus'></div>");
  client.println("        <div id='fanStatus'></div>");
  client.println("        <div id='initialMessage'>Getting A Smart Home is Like Getting <br>A Smart Phone... Life Just Gets So Much Easier.</div>");
  client.println("    </div>");
  client.println("    <script src='https://unpkg.com/typed.js@2.1.0/dist/typed.umd.js'></script>");
  client.println("    <script>var typed = new Typed('#element', {strings: ['A project to make your life Modern,', 'Comfortable,', 'and Amazing...'],typeSpeed: 50,});</script>");
  client.println("    <script>");
  client.println("        function toggleDropdown() {");
  client.println("            var dropdownMenu = document.getElementById('dropdownMenu');");
  client.println("            var statusMessage = document.getElementById('statusMessage');");
  client.println("            var isDisplayed = dropdownMenu.style.display === 'block';");
  client.println("            hideAllOptions();");
  client.println("            dropdownMenu.style.display = isDisplayed ? 'none' : 'block';");
  client.println("            statusMessage.textContent = '';");
  client.println("            var textMessage = document.createElement('div');");
  client.println("            textMessage.id = 'textMessage';");
  client.println("            textMessage.innerHTML = 'Hello My Friend, this is the SmartHome Automation Prototype which helps you control devices.'");
  client.println("            document.body.appendChild(textMessage);}");
  client.println("        function showLivingRoomOptions() {hideAllOptions();document.getElementById('livingRoomOptions').style.display = 'block';}");
  client.println("        function showKitchenOptions() {hideAllOptions();document.getElementById('kitchenOptions').style.display = 'block';}");
  client.println("        function showBathRoomOptions() {hideAllOptions();document.getElementById('bathRoomOptions').style.display = 'block';}");
  client.println("        function showBedRoomOptions() {hideAllOptions();document.getElementById('bedRoomOptions').style.display = 'block';}");
  client.println("        function showLedOptions() {hideAllOptions();document.getElementById('ledOptions').style.display = 'block';}");
  client.println("        function showFanOptions() {hideAllOptions();document.getElementById('fanOptions').style.display = 'block';}");
  client.println("        function hideAllOptions() {");
  client.println("            var options = document.querySelectorAll('#livingRoomOptions, #kitchenOptions, #bathRoomOptions,#bedRoomOptions, #ledOptions, #fanOptions');");
  client.println("            options.forEach(function (option) {option.style.display = 'none';});");
  client.println("            var textMessage = document.getElementById('textMessage');");
  client.println("            if (textMessage) {textMessage.remove();}}");
  client.println("        function updateStatus(device, isOn) {");
  client.println("            var statusMessage = document.getElementById('statusMessage');");
  client.println("            statusMessage.textContent = 'Your ' + device + ' is ' + (isOn ? 'ON' : 'OFF');");
  client.println("            statusMessage.className = isOn ? 'on' : 'off';");
  client.println("            if (device === 'Living Room Light'){");
  client.println("                var ledStatus = document.getElementById('ledStatus');");
  client.println("                ledStatus.textContent = 'Light Status :- ' + (isOn ? 'ON' : 'OFF');}");
  client.println("            if (device === 'Living Room Fan'){");
  client.println("                var fanStatus = document.getElementById('fanStatus');");
  client.println("                fanStatus.textContent = 'Fan Status :- ' + (isOn ? 'ON' : 'OFF');}");
  client.println("            if (device === 'Bedroom Light'){");
  client.println("                var ledStatus = document.getElementById('ledStatus');");
  client.println("                ledStatus.textContent = 'Light Status :- ' + (isOn ? 'ON' : 'OFF');}");
  client.println("            if (device === 'Bedroom Fan'){");
  client.println("                var fanStatus = document.getElementById('fanStatus');");
  client.println("                fanStatus.textContent = 'Fan Status :- ' + (isOn ? 'ON' : 'OFF');}");
  client.println("            if (device === 'Kitchen Light'){");
  client.println("                var ledStatus = document.getElementById('ledStatus');");
  client.println("                ledStatus.textContent = 'Light Status :- ' + (isOn ? 'ON' : 'OFF');}");
  client.println("            if (device === 'Bathroom Light'){");
  client.println("                var ledStatus = document.getElementById('ledStatus');");
  client.println("                ledStatus.textContent = 'Light Status :- ' + (isOn ? 'ON' : 'OFF');}}");
  client.println("    </script>");
  client.println("    </body>");
  client.println("</html>");
}