#include "Motor.h"
#include <NewPing.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>

Motor moteurGaucheAvant(32,31,46);
Motor moteurGaucheArriere(7,34,6);

Motor moteurDroiteAvant(33,30,44);
Motor moteurDroiteArriere(36,4,5);

NewPing sonar(11,10,200);

void callback(const geometry_msgs::Twist &vel) {
  if (vel.linear.x > 0) {
    moteurGaucheAvant.run(100);
    moteurGaucheArriere.run(100);
    moteurDroiteAvant.run(100);
    moteurDroiteArriere.run(100);
  }
  if (vel.linear.x == 0 && vel.linear.y == 0) {
    moteurGaucheAvant.stop();
    moteurGaucheArriere.stop();
    moteurDroiteAvant.stop();
    moteurDroiteArriere.stop();
  }
} 
ros::NodeHandle nh;
ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", callback);
void setup() {
  Serial.begin(115200);
  moteurDroiteAvant.init();
  moteurDroiteArriere.init();
  moteurGaucheAvant.init();
  moteurGaucheArriere.init();

  nh.initNode();
  nh.subscribe(sub);

}

void loop() {
     nh.spinOnce();
     delay(1);
}
