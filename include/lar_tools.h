/* 
 * File:   lar_tools.h
 * Author: daniele
 *
 * Created on 4 novembre 2015, 12.16
 */

#ifndef LAR_TOOLS_H
#define	LAR_TOOLS_H

#include <ros/ros.h>

namespace lar_tools{
    
    std::string package_name_prefix = "lar_tools";
    
    void init_ros_node(int argc, char** argv,std::string name){
        std::stringstream ss;
        ss << package_name_prefix<<"_"<<name;
        ros::init(argc, argv, ss.str().c_str());
        ROS_INFO("Node %s Started!",ss.str().c_str());
    }
}

#endif	/* LAR_TOOLS_H */

