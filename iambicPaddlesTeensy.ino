/*
 * iambic morse paddle interpreter for teensy
 * 
 * this program takes signals from iambic morse paddles 
 * and translates them into left and right mouse clicks 
 * for practicing keying cw on iambic paddles
 * 
 * pin 0: left paddle
 * pin 1: right paddle
 */

const int paddles = 1; // might change somewhere along the line
int paddleStates[paddles + 1];

void setup() {
  
  // set pin mode
  for (int i = 0; i <= paddles; i++) {
    paddleStates[i] = HIGH;
    pinMode(i, INPUT);
  }

}

void loop() {

  for (int i = 0; i <= paddles; i++) {
    if (paddleStates[i] == LOW) {
      if (i == 0) {
        Mouse.set_buttons(1, 0, 0);
      } else {
        Mouse.set_buttons(0, 0, 1);
      }
    } else {
      if (i == 0) {
        Mouse.set_buttons(0, 0, 0);
      } else {
        Mouse.set_buttons(0, 0, 0);
      }
    }
  }
  
}
