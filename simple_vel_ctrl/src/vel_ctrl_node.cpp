#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "vel_ctrl_node");

    ros::NodeHandle nodeHandle;

    ros::Publisher publisher = nodeHandle.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 3);

    ros::Rate rate = ros::Rate(10);

    while(ros::ok())
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 0.5;
        vel_msg.angular.z = 0.1;
        publisher.publish(vel_msg);

        rate.sleep();

    }
    return 0;
}
