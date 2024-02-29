#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist

if __name__ == '__main__':
    rospy.init_node("vel_ctrl_node")
    
    publisher = rospy.Publisher("turtle1/cmd_vel", Twist, queue_size=3)
    
    rate = rospy.Rate(10)
    
    while not rospy.is_shutdown():
        vel_msg = Twist()
        vel_msg.linear.x = 0.5
        vel_msg.angular.z = 0.1
        publisher.publish(vel_msg)
        
        rate.sleep()