#include "Motor.h"
#include <NewPing.h>

Motor moteurGaucheAvant(32,31,46);
Motor moteurGaucheArriere(7,34,6);

Motor moteurDroiteAvant(33,30,44);
Motor moteurDroiteArriere(36,4,5);

NewPing sonar(11,10,200);
void setup() {
  Serial.begin(115200);
  moteurDroiteAvant.init();
  moteurDroiteArriere.init();
  moteurGaucheAvant.init();
  moteurGaucheArriere.init();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(sonar.ping_cm() > 10)  {
  Serial.println(sonar.ping_cm());
  moteurGaucheAvant.run(100);
  moteurGaucheArriere.run(100);
  moteurDroiteAvant.run(100);
  moteurDroiteArriere.run(100);
  delay(50);
  }else {
  moteurGaucheAvant.stop();
  moteurGaucheArriere.stop();
  moteurDroiteAvant.stop();
  moteurDroiteArriere.stop();
  }

}
