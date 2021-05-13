#include <ArduinoJson.h>

String jsonGenerator(const char *data);

StaticJsonDocument<256> doc;
void setup() {
  Serial.begin(115200);
}

void loop() {
    const char *value = "1234567";
    String res = jsonGenerator(value);
    const char *response = jsonDeserialize(res);
    Serial.print("Generated Result = ");
    Serial.println(res);
    
    delay(30000);
}

String jsonGenerator(const char *data){
    doc["sensor"] = "rfid";
    doc["id_number"] = data;
    doc["time"] = 123112121;
    String result;
    serializeJson(doc, result);
    return result;
}

const char* jsonDeserialize(String payload){
    Serial.println("Starting JSON Serialization...");
    StaticJsonDocument<256> doc;
    DeserializationError error =  deserializeJson(doc,payload);
    const char *result;
    if(error) {
      Serial.print("deserializeJson() failed with code ");
      Serial.println(error.c_str());
      result = error.c_str();
    } else {
      Serial.println("JSON OK");
      result = (const char*)doc["result"];
    }
//    const char *response = 
    Serial.println(result);
    return result;
}
