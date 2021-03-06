#include<ArduinoJson.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

void setup(){
  Serial.begin(9600);
  deserializejson();
  jsonGenerator(); // serialization()
}

void deserializejson(){
  Serial.println("Starting JSON");
  StaticJsonDocument<256> doc;
  char json[] = "{\"sensor\":\"rfid\", \"id_number\":\"123456qwert\", \"time\": 1233234234}";
  DeserializationError error =  deserializeJson(doc,json);
  if(error) {
    Serial.print("deserializeJson() failed with code ");
    Serial.println(error.c_str());
  } else {
    Serial.println("JSON OK");
  }

  const char* sensor = doc["sensor"];
  const char* id_number = doc["id_number"];
  long time = doc["time"];

  Serial.println(sensor);
  Serial.println(id_number);
  Serial.println(time);
}

void jsonGenerator(){
  Serial.println("Starting JSON");
  StaticJsonDocument<256> doc;
  char json[] = "{\"sensor\":\"rfid\", \"id_number\":\"123456qwert\", \"time\": 1233234234}";
  doc["sensor"] = "rfid";
  doc["id_number"] = "123456qwert";
  doc["time"] = 123112121;

  JsonArray data = doc.createNestedArray("data");
  data.add(4.86);
  data.add(2.02);

  serializeJson(doc, Serial);

  Serial.println();

  serializeJsonPretty(doc, Serial);
}

void loop(){
  
}
