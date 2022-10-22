/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
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
//    Serial.print(curSwitchState);
//    Serial.print(" ");
//    Serial.print(prevSwitchState);
    if(prevSwitchState == HIGH && curSwitchState == LOW){
//      Serial.println("Sending 'Hello world'...");
      bleKeyboard.print("git push");
  
      delay(100);
  
//      Serial.println("Sending Enter key...");
      bleKeyboard.write(KEY_RETURN);
  
     //
     // Below is an example of pressing multiple keyboard modifiers 
     // which by default is commented out.
      /*
      Serial.println("Sending Ctrl+Alt+Delete...");
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press(KEY_DELETE);
      delay(100);
      bleKeyboard.releaseAll();
      */
    }
    prevSwitchState = curSwitchState;
  }

  delay(300);
}
