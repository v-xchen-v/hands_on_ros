## C++
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

## Python
Run nodes:
```sh
roscore
rosrun first_publisher_subscriber machao_node.py
rosrun first_publisher_subscriber yao_node.py
rosrun first_publisher_subscriber zhaoyun_node.py
```

or
```sh
roslaunch first_publisher_subscriber run_nodes_oneline_py.launch
```

Then check the topic:
```
rostopic list
rostopic hz kaihei_room
rostopic echo kaihei_room
```

## rqt_graph
图形化显示当前系统活跃的节点以及节点间的话题通讯关系。
```
rqt_graph
```
![alt text](rqt_graph.png)