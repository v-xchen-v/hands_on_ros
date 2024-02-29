#!/usr/bin/env python3

"""
chmod +x first_node.py
rosrun first_node first_node
"""

import rospy

if __name__ == "__main__":
    rospy.init_node('first_node')
    print('Hello World!')