#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "settings.h"



WiFiClient wifiClient;
PubSubClient client(wifiClient);


// put function declarations here:
int measure(int, int, int);
float medianValue();
float timeToMetric();
void goToBed (int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println("*******************************************");
  Serial.println("LIR-TANK Projekt");
  Serial.println("by 705Marc");
  Serial.println("*******************************************");
  Serial.println();
  Serial.println("Starting . . .");

  //Connect to WiFi
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("connecting to WiFi...");
  }
  Serial.println("successfully connected");
  Serial.print("IP-Address: ");
  Serial.println(WiFi.localIP());

  //connect to MQTT Broker
  client.setServer(BROKER_ADDR, BROKER_PORT);
  while (!client.connected()) {
    Serial.print("Attempting connection to MQTT... ");
    // Attempt to connect
    if (client.connect(HOSTNAME)) {
      Serial.println("Success.");
      client.loop();
    } else {
      Serial.println("Failed.");
      Serial.println("Could not connect to MQTT-Server. Retry in 500ms.");
      delay(500);
    }
  }


  //Set up GPIO Pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.println("Running!");
}

void loop() {
  String metric = String(timeToMetric());
  client.publish(TOPIC, metric.c_str(), true);
  Serial.println(metric);
  delay(1000);
  goToBed(SLEEP_TIME);
}

//trigtime is the time the Trigger needs to trigger the sensor (mS)
int measure(int triggerPin, int echoPin,int trigtime ) {

  digitalWrite(triggerPin, HIGH);
  delay(trigtime);
  digitalWrite(triggerPin, LOW);

  unsigned long measureTime = pulseIn(echoPin, HIGH);
  return measureTime;
  
}


float medianValue(){
  int total = 0;  
  
  for (int i = 0; i < REPEAT; i++)
  {
    Serial.print("Measure Nr: ");
    Serial.println(i+1);
    total += measure(TRIG, ECHO, TRIG_TIME);
    delay(500);
  }

  float median = total / REPEAT;
    
  return median;
}


float timeToMetric(){
  float time = medianValue();
  float metricValue = 10000;
  float cm = time / CalculationFactor;
  if (String(UNIT) == "mm")
  {
    metricValue = cm*10;
  }
  else if (String(UNIT) == "cm")
  {
    metricValue = cm;
  }
  else if (String(UNIT) == "dm")
  {
    metricValue = cm/10;
  }
  else if (String(UNIT) == "m")
  {
    metricValue = cm/100;
  }
  
  return metricValue;
}



/**
 * Sending device into deep sleep
 */
void goToBed (int minutes) {
    Serial.print("Uaaah. I'm tired. Going back to bed for ");
    Serial.print(minutes);
    Serial.println(" minutes. Good night!");
    Serial.println("---");
    ESP.deepSleep(minutes * 60 * 1000000, WAKE_RF_DEFAULT);
    delay(100);
}