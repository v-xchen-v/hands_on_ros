/*
roslaunch wpr_simulation wpb_simple.launch
rosrun lidar_msgs lidar_msgs
*/

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

void lidar_callback(sensor_msgs::LaserScan msg)
{
    float distanceToForward = msg.ranges[180];
    ROS_INFO_STREAM("distance to forward:" << std::to_string(distanceToForward) << "\n");
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "lidar_msg");

    ros::NodeHandle nh;

    ros::Subscriber subscriber = nh.subscribe<sensor_msgs::LaserScan>("/scan", 3, lidar_callback);

    ros::Rate rate = ros::Rate(10);

    while(ros::ok())
    {
        ros::spinOnce();
        rate.sleep();
    }
    /* code */
    return 0;
}
