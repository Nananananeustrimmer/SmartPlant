#ifndef NETWORKING_H
#define NETWORKING_H

#include <InfluxDbClient.h>
#include <InfluxDbCloud.h>
#include <WiFiMulti.h>
#include <math.h>
#include "Arduino.h"

class Networking {
public:
  Networking();
  void setupWifi();
  void addData(String fieldName, float fieldData);
  void updateData();

private:
  void checkConnection();
  const char *DEVICE = "ESP_CAMIEL";
  const char *DEVICE_LOCATION = "HAN_NIJMEGEN";
  const char *WIFI_SSID = "MiA3";
  const char *WIFI_PASSWORD = "test1234";
  const char *INFLUXDB_URL = "https://influx.mvrautomatisering.nl";
  const char *INFLUXDB_TOKEN =
      "nOmg1VbkptIRrwGz1wk1AgkpdC7DwSouf3nax_"
      "KaDwSQ1HXHRGgp9N31JwUcl4ZTNnFnxLD0kCxdFCWZ1sm8Pg==";
  const char *INFLUXDB_ORG = "han";
  const char *INFLUXDB_BUCKET = "Camiel_Bucket";
  const char *TZ_INFO = "CET-1CEST,M3.5.0,M10.5.0/3";

  bool clearedFields = false;
  
  WiFiMulti wifiMulti;
  InfluxDBClient client;
  Point deviceStatus;
};

#endif // NETWORKING_H