#include <GyverButton.h>
GButton quar (11, HIGH_PULL, NORM_OPEN);

void setup() {
  Serial.begin(9600);
  quar.setTimeout(1000);

}

void loop() {
  quar.tick();
  if (quar.isSingle()) {
    Serial.println("Good");
  }
  if (quar.isDouble()) {
    Serial.println("Very good");
  }
  if (quar.isTriple()) {
    Serial.println("Best!");
  }
  if (quar.isHolded()) {
    Serial.println("Hold");
  }
  if (quar.hasClicks()) {
    Serial.println(quar.getClicks());
  }

}
