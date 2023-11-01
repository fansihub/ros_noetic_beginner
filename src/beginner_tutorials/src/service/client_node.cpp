// 复制自src/ros_tutorials/roscpp_tutorials/add_two_ints_client
#include "ros/ros.h"
#include "roscpp_tutorials/TwoInts.h"
#include <cstdlib>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<roscpp_tutorials::TwoInts>("add_two_ints");
  roscpp_tutorials::TwoInts srv;
  srv.request.a = atoi(argv[1]);
  srv.request.b = atoi(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}

