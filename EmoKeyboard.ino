#include <BleKeyboard.h>

BleKeyboard bleKeyboard("EMO Keyboard");
int curSwitchState = HIGH;
int prevSwitchState = HIGH;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  pinMode(19, INPUT_PULLUP);
  curSwitchState = digitalRead(19);
  prevSwitchState = curSwitchState;
}

void loop() {
  if(bleKeyboard.isConnected()) {
    curSwitchState = digitalRead(19);
    if(prevSwitchState == HIGH && curSwitchState == LOW){
      // git push
      bleKeyboard.print("git push");
      delay(100);
      bleKeyboard.write(KEY_RETURN);

      // ENG - JPN language change
//      bleKeyboard.press(KEY_LEFT_CTRL);
//      bleKeyboard.print(" ");
//      delay(100);
//      bleKeyboard.releaseAll();
    }
    prevSwitchState = curSwitchState;
  }

  delay(300);
}
