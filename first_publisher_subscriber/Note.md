Run nodes:
```sh
roscore
rosrun first_publisher_subscriber machao_node
rosrun first_publisher_subscriber yao_node
rosrun first_publisher_subscriber zhaoyun_node
```

or
```sh
roslaunch first_publisher_subscriber run_nodes_oneline.launch
```

Then check the topic:
```
rostopic list
rostopic hz kaihei_room
rostopic echo kaihei_room
```