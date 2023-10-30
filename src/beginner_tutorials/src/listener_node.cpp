#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
// 这是一个回调函数，当有新消息到达chatter话题时它就会被调用。
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("subscriber:I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener_node");
  ros::NodeHandle n;
  // 订阅主题
  ros::Subscriber sub = n.subscribe("chatter", 10, chatterCallback);
  ros::spin();

  return 0;
}