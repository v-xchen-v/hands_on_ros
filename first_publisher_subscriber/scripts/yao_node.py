#!/usr/bin/env python3
import rospy
from std_msgs.msg import String


def yao_callback(msg):
    global publisher
    if msg.data == "Play a game?":
        response_msg = String(data="+++++++++")
        publisher.publish(response_msg)
        
if __name__ == "__main__":
    rospy.init_node("yao_node")
    
    subscriber = rospy.Subscriber("kaihei_room", String, yao_callback)
    publisher = rospy.Publisher("kaihei_room", String, queue_size=3)
    
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        rospy.spin()
        
        rate.sleep()