#!/usr/bin/env python3

"""
chmod +x scripts/lidar_msgs.py
roslaunch wpr_simulation wpb_simple.launch
rosrun lidar_msgs lidar_msgs.py
"""
import rospy
from sensor_msgs.msg import LaserScan

def lidar_callback(msg: LaserScan):
    rospy.loginfo(f'DistanceToForward: {msg.ranges[180]}')

if __name__ == "__main__":
    rospy.init_node("lidar_msgs")
    rospy.Subscriber("/scan", LaserScan, queue_size=3, callback=lidar_callback)
    
    rospy.spin()