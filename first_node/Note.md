# Commands you need to create your first ROS node

/toc

- 1. Create workspace
- 2. Create a new package
- 3. Write a Hello World source code
- 4. Compile and Run

## Prepare workspace and create new package with `catkin_create_pkg`

```
cd ~
mkdir --parents hands_on_ros_ws/src
cd hands_on_ros_ws/src
catkin_create_pkg first_node roscpp rospy std_msgs
```
print info:
```
Created file first_node/package.xml
Created file first_node/CMakeLists.txt
Created folder first_node/include/first_node
Created folder first_node/src
Successfully created files in /root/hands_on_ros_ws/src/first_node. Please adjust the values in package.xml.
```
If not familiar with creating workspace, refer to: https://industrial-training-master.readthedocs.io/en/melodic/_source/session1/Create-Catkin-Workspace.html

## Compile and run
```
cd ~/hands_on_ros/src
catkin_make

# when compile done

rosrun first_node first_node
```
### Package not found error

If meet package not found error, you may forgot to source `~/hands_on_ros/devel/setup.sh` to make workspace visible to ROS.
```
[rospack] Error: package 'first_node' not found
```

```
source ~/hands_on_ros/devel/setup.sh
rosrun first_node first_node
```

printing
```
Hello World!
```
