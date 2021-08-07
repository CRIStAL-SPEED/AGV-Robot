#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from std_msgs.msg import Float32MultiArray
from geometry_msgs.msg import Twist
import numpy as np

class TquadDriver():
    """
        Noeud ros pour piloter les moteur de l'agv
    """
    def __init__(self):
        self.radius = 0.03
        self.lenght = 0.1
        self.width = 0.075
        self.sub_cmd = rospy.Subscriber('tquad/cmd_vel', Twist, self.cb_cmd_vel)
        self.pub_motors = rospy.Publisher('tquad/serial_subscriber', Float32MultiArray, queue_size=1)

    def cb_cmd_vel(self, cmd):
        """
        to do something
        """
        vel_motors = self.twist2pwm(cmd.linear.x, cmd.linear.y, cmd.angular.z)
        pwm_motors = Float32MultiArray(data=vel_motors)
        #pub_motors.publish(pub_motors)

    def twist2pwm(self, vx, vy, wz):
        H = np.array([[-self.lenght - self.width, 1, -1], 
                      [ self.lenght + self.width, 1, 1], 
                      [ self.lenght + self.width, 1, -1], 
                      [ self.lenght - self.width, 1, 1]]) / self.radius
        twist = np.array([wz,vx,vy])
        twist.shape = (3,1)
        u = np.dot(H, twist)
        u = np.around(u)
        return u.flatten().tolist()

    def map2pw(self, value, min, max):
        return value**(max-min) + min

def main():
    rospy.init_node('tquad_driver', anonymous=True)
    tquad = TquadDriver()
    rospy.spin()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass