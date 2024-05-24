/*
One servo follows the movement of another
manual servo movement
Disable torque of servo 2
ReadPos of servo 2
set target position AKA SMS_STS_GOAL_POSITION_L of servo 3 to pos of servo 2
Not ideal when crossing between 4095 and 0 positions as the servo then spins all the way back
NB! due to gear ratio, very hard to turn, must attach lever to servo wheel to be able to turn it when torque off

HC Gilje may 2024
*/

#include <SCServo.h>

SMS_STS st;

// the uart used to control servos.
// GPIO 18 - S_RXD, GPIO 19 - S_TXD, as default.
#define S_RXD 18
#define S_TXD 19


void setup() {
  Serial.begin(115200);
  Serial1.begin(1000000, SERIAL_8N1, S_RXD, S_TXD);
  st.pSerial = &Serial1;
  delay(1000);
  st.EnableTorque(2, 0);
  Serial.print("torque status servo 2:");
  Serial.println(st.readByte(2,SMS_STS_TORQUE_ENABLE));
  Serial.print("torque status servo 3:");
  Serial.println(st.readByte(3,SMS_STS_TORQUE_ENABLE));

}

void loop() {
  int pos = st.ReadPos(2);
  st.writeWord(3, SMS_STS_GOAL_POSITION_L, pos);
  // Serial.print(st.ReadPos(2));
  // Serial.print(" ");
  // Serial.println(st.ReadPos(3));
  delay(50);
}
