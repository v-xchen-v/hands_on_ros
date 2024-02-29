#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    rospy.init_node("machao_node")
    
    publisher = rospy.Publisher("kaihei_room", String, queue_size=3)
    
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        msg = String()
        msg.data = "Play a game?"
        publisher.publish(msg)
        
        rate.sleep()