/*
 * Firmware arduino pour contrôler les robots T-quad avec ROS
 * @auteur : Mamadou Sarifou Diallo
 * @email : diallo.msdpro@gmail.com
 * @version : 1.0.0
 */

//============ Insertions des bibliothèques ===========================================
#include "Motor.h"
#include <NewPing.h>
#include <PID_v1.h>
#include <ros.h>
#include <std_msgs/Int64MultiArray.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>
//#include <digitalWriteFast.h>
//#include <EnableInterrupt.h>

//============ Définitions et déclarations des moteurs et des codeurs =================
//Moteur avant gauche
Motor moteurGaucheAvant(32,31,46);
#define codeurAvantGauchePinA 18
#define codeurAvantGauchePinB 23
volatile int8_t ticksCodeurAvantGauche = 0;

//Moteur arrière gauche
Motor moteurGaucheArriere(7,34,6);
#define codeurArriereGauchePinA 3
#define codeurArriereGauchePinB 9
volatile int8_t ticksCodeurArriereGauche = 0;


//Moteur avant droit
Motor moteurDroitAvant(33,30,44);
#define codeurAvantDroitPinA 19
#define codeurAvantDroitPinB 49
volatile int8_t ticksCodeurAvantDroit = 0;

//Moteur arrière droit
Motor moteurDroitArriere(36,4,5);
#define codeurArriereDroitPinA 2
#define codeurArriereDroitPinB 8
volatile int8_t ticksCodeurArriereDroit = 0;

//============ Définitions et déclarations des variables pour le PID ==================
//double Kp = 0.05 ; // gain proportionnel du PID
//double Ki = 2.5 ; // gain intégral du PID
//double Kd = 0.1 ;// gain dérivé du PID
//
////Moteur avant gauche
//double InputAVG, OutputAVG, SetPointAVG ;
//PID moteurAvantGauchePID(&InputAVG, &OutputAVG, &SetPointAVG, Kp, Ki, Kd, DIRECT);
//
////Moteur arrière gauche
//double InputARG, OutputARG, SetPointARG ;
//PID moteurArriereGauchePID(&InputARG, &OutputARG, &SetPointARG, Kp, Ki, Kd, DIRECT);
//
////Moteur avant droit
//double InputAVD, OutputAVD, SetPointAVD ;
//PID moteurAvantDroitPID(&InputAVD, &OutputAVD, &SetPointAVD, Kp, Ki, Kd, DIRECT);
//
////Moteur arrière droit
//double InputARD, OutputARD, SetPointARD ;
//PID moteurArriereDroitPID(&InputARD, &OutputARD, &SetPointARD, Kp, Ki, Kd, DIRECT);

//============ Définitions et déclarations du capteurs ultrasons ======================
// Déclarations du capteurs ultrason
NewPing sonar(11,10,200);
// message ros pour la valeur renvoyé par le capteur ultrason
sensor_msgs::Range range_msg;
//
char frameid[] = "/ultrasound";

//============ Définitions des callback pour les souscriptions ========================
// Callback pour le contrôle des moteurs
void motors_callback(const std_msgs::Int64MultiArray &velocity) {
    moteurGaucheAvant.run(velocity.data[0]);
    moteurGaucheArriere.run(velocity.data[1]);
    moteurDroitAvant.run(velocity.data[2]);
    moteurDroitArriere.run(velocity.data[3]);
}

ros::NodeHandle nh;
ros::Subscriber<std_msgs::Int64MultiArray> sub_motors("tquad/motors", motors_callback);
ros::Publisher pub_range( "tquad/ultrasound", &range_msg);

void setup() {
  // Initialisation de la communication série
  Serial.begin(9600);
  
  // Initialisations des moteurs
  moteurDroitAvant.init();
  moteurDroitArriere.init();
  moteurGaucheAvant.init();
  moteurGaucheArriere.init();
//
//  // Initialisation des encodeurs
//  initPID();
//
  // Initialisation du handler ros
  nh.initNode();
  
  // Initilisation du publisher de l'ultrason
  nh.advertise(pub_range);
  
  // Initialisation du subscriber des moteursython html
  nh.subscribe(sub_motors);
   
  range_msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
  range_msg.header.frame_id =  frameid;
  range_msg.field_of_view = 0.1;  // fake
  range_msg.min_range = 0.0;
  range_msg.max_range = 6.47;
  

}

void loop() {
//  Serial.println("A");
//  Serial.println(ticksCodeurArriereDroit);
//  SetPointARD = 100 ;
//  InputARD = ticksCodeurArriereDroit ;
//  moteurArriereDroitPID.Compute();
//  Serial.println(OutputARD);
  range();
  nh.spinOnce();
  delay(1000);
}

void range() {
  range_msg.range = sonar.ping_cm();
  range_msg.header.stamp = nh.now();
  pub_range.publish(&range_msg);
}

//void initPID() {
//  pinMode(codeurAvantDroitPinA, INPUT_PULLUP);
//  pinMode(codeurAvantDroitPinB, INPUT_PULLUP);
//  enableInterrupt(codeurAvantDroitPinA, GestionInterruptionCodeurAvantDroitPinA, CHANGE);
//  moteurAvantDroitPID.SetMode(AUTOMATIC);
//  moteurAvantDroitPID.SetOutputLimits(-255, 255);
//  
//  pinMode(codeurArriereDroitPinA, INPUT_PULLUP);
//  pinMode(codeurArriereDroitPinB, INPUT_PULLUP);
//  enableInterrupt(codeurArriereDroitPinA, GestionInterruptionCodeurArriereDroitPinA, CHANGE);
//  moteurArriereGauchePID.SetMode(AUTOMATIC);
//  moteurArriereGauchePID.SetOutputLimits(-255, 255);
//  
//  pinMode(codeurAvantGauchePinA, INPUT_PULLUP);
//  pinMode(codeurAvantGauchePinB, INPUT_PULLUP);
//  enableInterrupt(codeurAvantGauchePinA, GestionInterruptionCodeurAvantGauchePinA, CHANGE);
//  moteurAvantGauchePID.SetMode(AUTOMATIC);
//  moteurAvantGauchePID.SetOutputLimits(-255, 255);
//  
//  pinMode(codeurArriereGauchePinA, INPUT_PULLUP);
//  pinMode(codeurArriereGauchePinB, INPUT_PULLUP);
//  enableInterrupt(codeurArriereGauchePinA, GestionInterruptionCodeurArriereGauchePinA, CHANGE);
//  moteurArriereGauchePID.SetMode(AUTOMATIC);
//  moteurArriereGauchePID.SetOutputLimits(-255, 255);
//}
//
//void GestionInterruptionCodeurArriereDroitPinA() {
//    if (digitalReadFast2(codeurArriereDroitPinA) == digitalReadFast2(codeurArriereDroitPinB)) {
//        ticksCodeurArriereDroit++;
//    }
//    else {
//        ticksCodeurArriereDroit--;
//    }
//
//}
//
//
//void GestionInterruptionCodeurArriereGauchePinA() {
//    if (digitalReadFast2(codeurArriereGauchePinA) == digitalReadFast2(codeurArriereGauchePinB)) {
//        ticksCodeurArriereGauche++;
//    }
//    else {
//        ticksCodeurArriereGauche--;
//    }
//}
//
//
//void GestionInterruptionCodeurAvantDroitPinA() {
//    if (digitalReadFast2(codeurAvantDroitPinA) == digitalReadFast2(codeurAvantDroitPinB)) {
//        ticksCodeurAvantDroit++;
//    }
//    else {
//        ticksCodeurAvantDroit--;
//    }
//}
//
//
//void GestionInterruptionCodeurAvantGauchePinA() {
//    if (digitalReadFast2(codeurAvantGauchePinA) == digitalReadFast2(codeurAvantGauchePinB)) {
//        ticksCodeurAvantGauche++;
//    }
//    else {
//        ticksCodeurAvantGauche--;
//    }
//}
