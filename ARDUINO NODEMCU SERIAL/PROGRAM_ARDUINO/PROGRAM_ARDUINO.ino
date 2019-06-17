/* ======================================================================
                   PROGRAM ARDUINO -> NODEMCU SERIAL
   ======================================================================
   >> ERWIN NUR CAHYONO | Email : erwinproject.id@gmail.com
   FITUR PROGRAM :
   [+] SEND DATA TO ARDUNO
   [+] GET DATA FROM ARDUINO
   ======================================================================
*/
#include <SoftwareSerial.h>
#define rx1           9   // KOMUNIKASI KE NODEMCU
#define tx1           10
#define rx2           11  // KOMUNIKASI DARI NODEMCU KE ARDUINO
#define tx2           12
#define br            57600

SoftwareSerial ToNode (rx1, tx1);
SoftwareSerial FromNode (rx2, tx2);

String GetData, SendData, DatatoNodemcu;

void setup() {
  Serial.begin(br);
  ToNode.begin(br);
  FromNode.begin(br);
}

void loop() {
  KomFromNode();
  if (GetData.length() > 0) {
    Serial.print("Data Dari Nodemcu : ");
    Serial.println(GetData);
  }
  DatatoNodemcu = "Data Arduino";
  GetData = "";
  sendNode();
}

// GET DATA DARI NODEMCU
void KomFromNode() {
  while (FromNode.available()) {
    delay(10);
    char j = FromNode.read();
    GetData += j;
  }
}

void sendNode() {
  SendData = DatatoNodemcu;
  if (SendData.length() > 0) {
    ToNode.print(SendData);
    Serial.print("Data yang Arduino kirim : ");
    Serial.println(SendData);
  }
  delay(1000);
}
