/*
roscore
rosrun first_publisher_subscriber yao_node
rostopic list
rostopic hz kaihei_room
rostopic echo kaihei_room
*/

#include <ros/ros.h>
#include <std_msgs/String.h>
ros::Publisher publisher;

void yao_callback(std_msgs::String msg)
{
    if(msg.data == "Play a game?")
    {
        std_msgs::String response_msg;
        response_msg.data = "+++++++++";
        publisher.publish(response_msg);
    }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "yao_node");

    ros::NodeHandle nodeHandle;

    ros::Subscriber subscriber = nodeHandle.subscribe<std_msgs::String>("kaihei_room", 3, yao_callback);
    publisher = nodeHandle.advertise<std_msgs::String>("kaihei_room", 3);

    
    while(ros::ok)
    {
        ros::spinOnce();
    }
    return 0;
}
