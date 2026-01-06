#include <Arduino.h>
#include "json_serializer.h"

void setup()
{
  Serial.begin(115200);
  delay(1000);

  /* ---- Sample Data (as required by PDF) ---- */

  DataPoint dp = {
    "1970-01-01 00:00",
    "1970-01-01 00:00",
    107.752,
    "OK"
  };

  DeviceReading dr = {
    "water",
    "waterstarm",
    "stromleser_50898527",
    "m3",
    &dp,
    1
  };

  Values values = {
    1,
    &dr
  };

  GatewayPacket pkt = {
    "gateway_1234",
    "1970-01-01",
    "stromleser",
    15,
    1,
    values
  };

  char json[512];

  int res = serialize_to_json(&pkt, json, sizeof(json));

  if (res >= 0) {
    Serial.println("Generated JSON:");
    Serial.println(json);
  } else {
    Serial.println("JSON serialization failed");
  }
}

void loop()
{
  // nothing needed
}
