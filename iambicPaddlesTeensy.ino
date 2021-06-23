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
int paddleStates[paddles+1];

void setup() {

  Serial.begin(9600);

  printf("iambic keyer ready");
  
  // set pin mode
  for (int i = 0; i <= paddles; i++) {
    paddleStates[i] = HIGH;
    pinMode(i, INPUT);
    printf("registered pin: " + 1);
  }

}

void loop() {

  for (int i = 0; i <= paddles; i++) {
    if (paddleStates[i] == LOW) {
      if (i == 0) {
        Mouse.press(MOUSE_LEFT);
        printf("dit pressed");
      } else {
        Mouse.press(MOUSE_RIGHT);
        printf("dah pressed");
      }
    } else {
      if (i == 0) {
        Mouse.release(MOUSE_LEFT);
        printf("dit released");
      } else {
        Mouse.release(MOUSE_RIGHT);
        printf("dah released");
      }
    }
  }
  
}
