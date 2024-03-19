借助阿杰老师开源的含有雷达场景的[wpr_simualtion](https://github.com/6-robot/wpr_simulation)进行实验，接受传感器数据并打印到控制台

```
cd src
git clone https://github.com/6-robot/wpr_simulation.git
cd wpr_simulation/scripts
./install_for_noetic.sh
```

开启仿真环境，仿真环境中包含一个含有雷达的base
```
roslaunch wpr_simulation wpb_simple.launch
```
运行雷达消息打印的订阅节点
## C++ Version
```
rosrun lidar_msgs lidar_msgs
```
### or Python Version
```
rosrun lidar_msgs lidar_msgs.py
```
打印消息如下:
```
[ INFO] [1710827223.142889968, 567.276000000]: distance to forward:2.605849

[ INFO] [1710827223.242264044, 567.376000000]: distance to forward:2.605698

[ INFO] [1710827223.342275609, 567.477000000]: distance to forward:2.585717
```
