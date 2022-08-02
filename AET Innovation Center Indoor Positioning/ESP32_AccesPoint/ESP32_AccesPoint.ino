#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>


#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b" // https://www.uuidgenerator.net/   BURADAN RANDOM UUID LER ALINMALI
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

// * * ESP_PWR_LVL_N14
// * * ESP_PWR_LVL_N11
// * * ESP_PWR_LVL_N8
// * * ESP_PWR_LVL_N5
// * * ESP_PWR_LVL_N2
// * * ESP_PWR_LVL_P1
// * * ESP_PWR_LVL_P4
// * * ESP_PWR_LVL_P7

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  BLEDevice::init("AP1");// BLE ADI////////
  BLEDevice::setPower(ESP_PWR_LVL_N14);
  BLEServer *pServer = BLEDevice::createServer(); //BU CİHAZI SUNUCU OLARAK AYARLADIK
  BLEService *pService = pServer->createService(SERVICE_UUID); //BLE SERVER İÇİN BİR HİZMET BAŞLATILDI
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setValue("SAMEEEED"); //SANIRIM KARŞI CİHAZA GÖNDERİLECEK VERİ
  pService->start(); // BLEYİ BAŞLAT VE YAYIN YAP
  // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void loop() {
  
  //delay(2000);
}
