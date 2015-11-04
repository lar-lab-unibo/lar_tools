#include <ros/ros.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lar_tools.h"


/** MAIN NODE **/
int
main(int argc, char** argv) {
        
        std::stringstream ss;
        std::string node_name;
        
        std::cout << "Testing node started...\n";
        // Initialize ROS
        ros::init(argc, argv, "lar_tools_testing_node");
        ros::NodeHandle nh;

        while (nh.ok() ) {
                
                ros::spinOnce();
        }
}
