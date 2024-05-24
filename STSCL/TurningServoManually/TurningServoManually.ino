/*
manual servo movement
Disable torque
ReadPos
NB! due to gear ratio, very hard to turn, must attach lever to servo wheel to be able to turn it when torque off

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
  //st.EnableTorque(1, 0);
  st.EnableTorque(2, 0);
}

void loop()
{
//Serial.println(st.EnableTorque(1, 0));
Serial.println(st.ReadPos(2));
    delay(500);
}
