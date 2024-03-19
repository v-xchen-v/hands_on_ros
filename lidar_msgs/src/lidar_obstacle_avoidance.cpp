/*
roslaunch wpr_simulation wpb_simple.launch
rosrun lidar_msgs lidar_obstacle_avoidance
*/

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

ros::Publisher vel_pub;
int nCount = 0;

void lidar_callback(sensor_msgs::LaserScan msg)
{
    float distanceToForward = msg.ranges[180];
    ROS_INFO_STREAM("distance to forward:" << std::to_string(distanceToForward) << "\n");

    geometry_msgs::Twist cmd_vel;
    if(distanceToForward < 1.5 || (nCount > 0 && nCount < 50))
    {
        cmd_vel.angular.z = 0.3;
        nCount+=1;
        if(nCount == 50)
        {
            nCount = 0;
        }
    }
    else
    {
        cmd_vel.linear.x = 0.1;
    }
    vel_pub.publish(cmd_vel);
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "lidar_msg");

    ros::NodeHandle nh;

    ros::Subscriber subscriber = nh.subscribe<sensor_msgs::LaserScan>("/scan", 3, lidar_callback);
    vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 3);

    ros::Rate rate = ros::Rate(10);

    while(ros::ok())
    {
        ros::spinOnce();
        rate.sleep();
    }
    /* code */
    return 0;
}
