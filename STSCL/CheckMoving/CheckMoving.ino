/*
ReadMove check if servo is moving

HC Gilje may 2024
*/

#include <SCServo.h>

SMS_STS st;

// the uart used to control servos.
// GPIO 18 - S_RXD, GPIO 19 - S_TXD, as default.
#define S_RXD 18
#define S_TXD 19


void setup()
{
  Serial.begin(115200);
  Serial1.begin(1000000, SERIAL_8N1, S_RXD, S_TXD);
  st.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  st.WritePosEx(1, 1000, 3400, 25);
  while (st.ReadMove(1)==1) {
    Serial.println(st.ReadMove(1));
    delay(50);
  }

  Serial.println(st.ReadMove(1));
  delay(1000);

  st.WritePosEx(1, 3000, 1400, 25);
  while (st.ReadMove(1)==1) {
    Serial.println(st.ReadMove(1));
    delay(50);
  }

  Serial.println(st.ReadMove(1));
  delay(1000);

}
