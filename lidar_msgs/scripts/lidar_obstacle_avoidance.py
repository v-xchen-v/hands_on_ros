#!/usr/bin/env python3

"""
chmod +x scripts/lidar_msgs.py
roslaunch wpr_simulation wpb_simple.launch
rosrun lidar_msgs lidar_obstacle_avoidance.py
"""
import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

nCount = 0

def lidar_callback(msg: LaserScan):
    global nCount
    
    distanceToForward = msg.ranges[180]
    rospy.loginfo(f'DistanceToForward: {distanceToForward}')

    cmd_vel = Twist()
    if distanceToForward < 1.5 or (nCount> 0 and nCount<50):
        cmd_vel.angular.z = 0.5
        
        nCount+=1
        if nCount==50:
            nCount = 0
    else:
        cmd_vel.linear.x = 0.1
    
    global vel_pub
    vel_pub.publish(cmd_vel)
    

if __name__ == "__main__":
    rospy.init_node("lidar_msgs")
    rospy.Subscriber("/scan", LaserScan, queue_size=3, callback=lidar_callback)
    
    vel_pub = rospy.Publisher("/cmd_vel", Twist, queue_size=3)
    rospy.spin()