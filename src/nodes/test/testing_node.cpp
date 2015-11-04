#include <ros/ros.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <boost/thread.hpp>
#include <boost/date_time.hpp>

#include "lar_tools.h"
#include "lar_tool_utils/UDPNode.h"

using namespace lar_tools;

struct message {
    int command;
    float payload[16];
};


void senderFunc()
{
   UDPNode node("127.0.0.1",9999);  
   float p = 0.00f;
   while(node.isReady()){
       message m;
       m.command = 124;
       m.payload[0] = p;
       p+=0.04f;
       bool s = node.send(&m,sizeof(m));
   }
}

/** MAIN NODE **/
int
main(int argc, char** argv) {

    // Initialize ROS
    lar_tools::init_ros_node(argc, argv, "tesing_node");

    ros::NodeHandle nh;
    UDPNode node(9999);

    if (!node.isReady()) {
        ROS_ERROR("Error node failed initialization");
    } else {
        ROS_INFO("UDP Node Ready!");
    }
    message m;
    boost::thread workerThread(senderFunc);
    while (nh.ok() && node.isReady()) {
        ROS_INFO("Waiting for data");
        node.receive(&m, sizeof (m));
        ROS_INFO("Received command %d with data %f",m.command,m.payload[0]);
        ros::spinOnce();
    }
    workerThread.join();
}
