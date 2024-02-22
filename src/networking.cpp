#include "networking.h"

Networking::Networking() : deviceStatus("devices"), client(INFLUXDB_URL, INFLUXDB_ORG, INFLUXDB_BUCKET,
                        INFLUXDB_TOKEN, InfluxDbCloud2CACert)
{
  
}

void Networking::setupWifi() {
  WiFi.mode(WIFI_STA);
  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to wifi...");
  while (wifiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // This line sets the options for the Influx client. It means that it will
  // send data in batches of size 1 and it will send the data immediately
  client.setWriteOptions(WriteOptions().batchSize(1).flushInterval(0));

  deviceStatus.addTag("device", DEVICE);
  deviceStatus.addTag("location", DEVICE_LOCATION);
  deviceStatus.addTag("SSID", WiFi.SSID());

  // Sync time for proper connection and data points
  timeSync(TZ_INFO, "pool.ntp.org", "time.nis.gov");

  checkConnection();
}

void Networking::checkConnection() {
  if (client.validateConnection()) {
    Serial.println("Connected to InfluxDB: ");
    Serial.println(client.getServerUrl());
  } else {
    Serial.println("InfluxDB connection failed: ");
    Serial.println(client.getLastErrorMessage());
  }
}

void Networking::addData(String fieldName, float fieldData) {
  if (!clearedFields) {
    deviceStatus.clearFields();
    clearedFields = true;
  }
  deviceStatus.addField(fieldName, fieldData);
}

void Networking::updateData() {
  // Check Wi-Fi connection and reconnect if needed
  if (wifiMulti.run() != WL_CONNECTED) {
    Serial.println("Wifi connection lost");
  }

  // Write point
  if (!client.writePoint(deviceStatus)) {
    Serial.println("InfluxDB write failed: ");
    Serial.println(client.getLastErrorMessage());
  }
}