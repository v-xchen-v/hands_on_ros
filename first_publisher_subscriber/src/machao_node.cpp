/*
roscore
rosrun first_publisher_subscriber machao_node
rostopic list
rostopic hz kaihei_room
rostopic echo kaihei_room
*/

#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char *argv[])
{
    // init with node with name
    ros::init(argc, argv, "machao_ndoe");

    // create a node handler who is a role of house keeper serving as the conduit for almost all forms of communication between nodes
    ros::NodeHandle nodeHandle;

    // create a publisher cares topic "kaihei_room"
    ros::Publisher publisher = nodeHandle.advertise<std_msgs::String>("kaihei_room", 3);

    // send message by 10 hz to topic
    ros::Rate rate = ros::Rate(10);
    while(ros::ok())
    {
        std_msgs::String msg;
        msg.data = "Play a game?";
        publisher.publish(msg);

        rate.sleep();
    }

    return 0;
}
