#include "Motor.h"
#include <NewPing.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int64MultiArray.h>

Motor moteurGaucheAvant(32,31,46);
Motor moteurGaucheArriere(7,34,6);

Motor moteurDroiteAvant(33,30,44);
Motor moteurDroiteArriere(36,4,5);

NewPing sonar(11,10,200);

void callback(const std_msgs::Int64MultiArray &vel) {
    moteurGaucheAvant.run(vel.data[0]);
    moteurGaucheArriere.run(vel.data[1]);
    moteurDroiteAvant.run(vel.data[2]);
    moteurDroiteArriere.run(vel.data[3]);
} 
ros::NodeHandle nh;
ros::Subscriber<std_msgs::Int64MultiArray> sub("tquad/motors", callback);
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
     delay(25);
}
