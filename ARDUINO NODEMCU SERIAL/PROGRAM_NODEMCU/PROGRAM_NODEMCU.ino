/* ======================================================================
                   PROGRAM NODEMCU ARDUINO SERIAL
   ======================================================================
   >> ERWIN NUR CAHYONO | Email : erwinproject.id@gmail.com
   FITUR PROGRAM :
   [+] SEND DATA TO ARDUNO
   [+] GET DATA FROM ARDUINO
   ======================================================================
*/

#include <SoftwareSerial.h>

#define br        57600  // my baudrate
#define rx1       D5
#define tx1       D6
#define rx2       D3
#define tx2       D4

SoftwareSerial fromUno (rx1, tx1);
SoftwareSerial sendUno (rx2, tx2);

String GetData, SendData, DatatoArdino;

void setup() {
  Serial.begin(br);
  fromUno.begin(br);
  sendUno.begin(br);

}

void loop() {
  KomFromUno();
  if (GetData.length() > 0) {
    Serial.print("Data From Arduino : ");
    Serial.println(GetData);
    delay(500);
  }
  GetData = "";

  DatatoArdino = "Data NODEMCU";

  sendToUno();
}

// SEND DATA TO ARDUINO UNO
void sendToUno() {
  SendData = DatatoArdino;
  if (SendData.length() > 0) {
    sendUno.print(SendData);

    Serial.println();
    Serial.print("Send Data : ");
    Serial.println(SendData);
  }
  delay(500);
}

// KOMUNIKASI RX TX DARI ARDUINO
void KomFromUno() {
  while (fromUno.available()) {
    delay(10);
    char v = fromUno.read();
    GetData += v;
  }
}
