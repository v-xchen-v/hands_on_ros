- geometry_msgs/Twist: a message type used to express the velocity of a robot in free space broken into its linear and angular parts.
- turtlesim： is a lightweight and educational tool packaged with ROS (Robot Operating System) that provides a simple simulator for teaching ROS concepts.

## C++
```sh
roscore
rosrun turtlesim turtlesim_node
rosrun simple_vel_ctrl vel_ctrl_node
```

or

```sh
roslaunch simple_vel_ctrl turtle_move.launch
```
## Python
```sh
roscore
rosrun turtlesim turtlesim_node
rosrun simple_vel_ctrl vel_ctrl_node.py
```

or

```sh
roslaunch simple_vel_ctrl turtle_move_py.launch
```

## Check
```
rostopic list
rostopic info /turtle1/cmd_vel
```

## Issue
比较坑的是，有时候turtle没动，别慌，重启一下turtlesim就好了。