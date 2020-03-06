#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <SocketIoClient.h>
#include <WiFiClientSecureBearSSL.h>


#ifndef STASSID
#define STASSID "Trend Edu 2"
#define STAPSK  "*700700*"
#endif

#define PIN0 D0
#define PIN1 D5


const char* ssid = STASSID;
const char* password = STAPSK;

// Fingerprint for demo URL, expires on June 2 , 2021 , needs to be updated well before this date
// 0x08, 0x3b, 0x71, 0x72, 0x02, 0x43, 0x6e, 0xca, 0xed, 0x42, 0x86, 0x93, 0xba, 0x7e, 0xdf, 0x81, 0xc4, 0xbc, 0x62, 0x30
const uint8_t fingerprint[20] = {0x08, 0x3b, 0x71, 0x72, 0x02, 0x43, 0x6e, 0xca, 0xed, 0x42, 0x86, 0x93, 0xba, 0x7e, 0xdf, 0x81, 0xc4, 0xbc, 0x62, 0x30};

ESP8266WiFiMulti WiFiMulti;
SocketIoClient webSocket;

String getData();

void event(const char * payload, size_t length) {
//  USE_SERIAL.printf("got message: %s\n", payload);
}

const size_t capacity = JSON_ARRAY_SIZE(2) + 2*JSON_OBJECT_SIZE(8) + JSON_OBJECT_SIZE(21) + 650;
DynamicJsonBuffer jsonBuffer(capacity);

void setup() {

  Serial.begin(115200);

  //*set pins as output*/
  pinMode(PIN0, OUTPUT);
  pinMode(PIN1, OUTPUT);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

//*Connect To AP */
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);
  
  while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
  }

    webSocket.on("event", event);
    webSocket.begin("my.socket-io.server");
//const char* json = "{\"_id\":\"5e4f0489f69d13271ccb0646\",\"owner_id\":\"5e4edc20656468067898ab8a\",\"name\":\"Anwar\",\"email\":\"mohamed@gmail.com\",\"version\":1,\"tag\":\"AC\",\"is_sensor\":true,\"is_rgp\":true,\"temp_sensor\":25,\"isActive\":true,\"rgp_value\":255255255,\"rgp_name\":\"\",\"rgp_intensity\":50,\"number_of_pins\":2,\"pins\":[{\"_id\":\"5e5adba4f7c3960004b6b648\",\"pin_id\":\"1\",\"tag\":\"AC\",\"value\":\"off\",\"name\":\"pin1\",\"is_pwm\":false,\"intensity\":50,\"picture\":null},{\"_id\":\"5e5adba4f7c3960004b6b647\",\"pin_id\":\"2\",\"tag\":\"AC\",\"value\":\"on\",\"name\":\"pin2\",\"is_pwm\":false,\"intensity\":50,\"picture\":null}],\"__v\":0,\"index\":null,\"latitude\":null,\"longitude\":null,\"picture\":\"https://drive.google.com/uc?id=1P4Yck9Jqrm5hc-jbQ9LRXrKIQjZyvC79\",\"registered\":null}";
//
//const char* _id = root["_id"]; // "5e4f0489f69d13271ccb0646"
//const char* owner_id = root["owner_id"]; // "5e4edc20656468067898ab8a"
//const char* name = root["name"]; // "Anwar"
//const char* email = root["email"]; // "mohamed@gmail.com"
//int version = root["version"]; // 1
//const char* tag = root["tag"]; // "AC"
//bool is_sensor = root["is_sensor"]; // true
//bool is_rgp = root["is_rgp"]; // true
//int temp_sensor = root["temp_sensor"]; // 25
//bool isActive = root["isActive"]; // true
//long rgp_value = root["rgp_value"]; // 255255255
//const char* rgp_name = root["rgp_name"]; // ""
//int rgp_intensity = root["rgp_intensity"]; // 50
//int number_of_pins = root["number_of_pins"]; // 2
//
//JsonObject& pins_0 = root["pins"][0];
//const char* pins_0__id = pins_0["_id"]; // "5e5adba4f7c3960004b6b648"
//const char* pins_0_pin_id = pins_0["pin_id"]; // "1"
//const char* pins_0_tag = pins_0["tag"]; // "AC"
//const char* pins_0_value = pins_0["value"]; // "off"
//const char* pins_0_name = pins_0["name"]; // "pin1"
//bool pins_0_is_pwm = pins_0["is_pwm"]; // false
//int pins_0_intensity = pins_0["intensity"]; // 50
//
//JsonObject& pins_1 = root["pins"][1];
//const char* pins_1__id = pins_1["_id"]; // "5e5adba4f7c3960004b6b647"
//const char* pins_1_pin_id = pins_1["pin_id"]; // "2"
//const char* pins_1_tag = pins_1["tag"]; // "AC"
//const char* pins_1_value = pins_1["value"]; // "on"
//const char* pins_1_name = pins_1["name"]; // "pin2"
//bool pins_1_is_pwm = pins_1["is_pwm"]; // false
//int pins_1_intensity = pins_1["intensity"]; // 50
//
//int _v = root["__v"]; // 0
//const char* picture = root["picture"]; // "https://drive.google.com/uc?id=1P4Yck9Jqrm5hc-jbQ9LRXrKIQjZyvC79"
//
//
// 
 
}

void loop() {

//  
//  // wait for WiFi connection
//  if ((WiFiMulti.run() == WL_CONNECTED)) {
//   String jsonData = getData();
////   Serial.println(jsonData);
//   JsonObject& root = jsonBuffer.parseObject(jsonData);
//    const char* _id = root["_id"]; // "device _id"
//    const char* owner_id = root["owner_id"]; // "owner_id"
//    const char* name = root["name"]; // "Anwar"
//    const char* email = root["email"]; // "mohamed@gmail.com"
////    int version = root["version"]; // 1
////    const char* tag = root["tag"]; // "AC"
////    bool is_sensor = root["is_sensor"]; // true
////    bool is_rgp = root["is_rgp"]; // true
////    int temp_sensor = root["temp_sensor"]; // 25
////    bool isActive = root["isActive"]; // true
////    long rgp_value = root["rgp_value"]; // 255255255
////    const char* rgp_name = root["rgp_name"]; // ""
////    int rgp_intensity = root["rgp_intensity"]; // 50
////    int number_of_pins = root["number_of_pins"]; // 2
//
//    JsonObject& pins_0 = root["pins"][0];
//    JsonObject& pins_1 = root["pins"][1];
//    String pins_0_value = pins_0["value"]; // "off"
//    String pins_1_value = pins_1["value"]; // "on"
//    Serial.print("pins_0_value : ");
//    Serial.println(pins_0_value);
//    Serial.print("pins_1_value : ");
//    Serial.println(pins_1_value);
//    if(pins_0_value == "on" ){
//    digitalWrite(PIN0, HIGH);
//    Serial.print("sssssssss0");
//    }else{
//      Serial.print("hhhhhhhhhhhh0");
//      digitalWrite(PIN0, LOW);
//    }
//   if(pins_1_value=="on"){
//    digitalWrite(PIN1, HIGH);
//    Serial.print("sssssssss1");
//    }else{
//      Serial.print("hhhhhhhhhhhh1");
//      digitalWrite(PIN1, LOW);
//    }
//  }
//
//  Serial.println("Wait 500ms before next round...");
//  delay(500);
  
}




String getData(){ 
   std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
    client->setFingerprint(fingerprint);
    HTTPClient https;
    Serial.print("[HTTPS] begin...\n");
    if (https.begin(*client, "https://mylastapi.herokuapp.com/devices/5e4f0489f69d13271ccb0646")) {  // HTTPS
      Serial.print("[HTTPS] GET...\n");
      // start connection and send HTTP header
      int httpCode = https.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          return payload;
//          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }
      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
  }
