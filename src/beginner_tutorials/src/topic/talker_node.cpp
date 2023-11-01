#include "ros/ros.h"
#include "std_msgs/String.h"
int main(int argc, char **argv)
{
    // 初始化ros，定义节点名称
    ros::init(argc,argv,"talker_node");
    ros::NodeHandle n;
    // 节点创建"chatter"话题发布信息，信息类型为String,话题最多缓存10条
    // 可根据信息处理速度设置缓存大小
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 10);
    // 每1hz执行循环
    ros::Rate loop_rate(1);
    
    
int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world ROS noetic, this is a beginner tutorials " << count;
    msg.data = ss.str();
    // ROS_INFO可用来取代printf/cout
    // ROS_INFO("%s", msg.data.c_str());
    // 向话题发送信息
    chatter_pub.publish(msg);

    ros::spinOnce();
    // 每1hz停在这里
    loop_rate.sleep();
    ++count;
  }

}
