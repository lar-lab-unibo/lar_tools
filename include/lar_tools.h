/*
 * File:   lar_tools.h
 * Author: daniele
 *
 * Created on 4 novembre 2015, 12.16
 */

#ifndef LAR_TOOLS_H
#define LAR_TOOLS_H

#include <fstream>

//ROS
#include <ros/ros.h>
#include "geometry_msgs/Pose.h"
#include <kdl/frames_io.hpp>
#include <tf/tf.h>

//EIGEN
#include <eigen3/Eigen/Core>



namespace lar_tools {

std::string package_name_prefix = "lar";

void init_ros_node(int argc, char** argv, std::string name) {
        std::stringstream ss;
        ss << package_name_prefix << "_" << name;
        ros::init(argc, argv, ss.str().c_str());
        ROS_INFO("Node %s Started!", ss.str().c_str());
}

/**
 * Builds Rotation matrix in 4x4 Form
 * @param axis x,y,z
 * @param angle angle in radians
 * @param out OUTPUT
 */
void rotation_matrix_4x4(char axis, float angle, Eigen::Matrix4f& out) {
        if (axis == 'x') {
                out <<
                1, 0, 0, 0,
                0, cos(angle), -sin(angle), 0,
                0, sin(angle), cos(angle), 0,
                0, 0, 0, 1;
        } else if (axis == 'y') {
                out <<
                cos(angle), 0, sin(angle), 0,
                0, 1, 0, 0,
                -sin(angle), 0, cos(angle), 0,
                0, 0, 0, 1;
        } else if (axis == 'z') {
                out <<
                cos(angle), -sin(angle), 0, 0,
                sin(angle), cos(angle), 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1;
        } else {
                out << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
        }
}

/**
 * Creates KDL Frame
 * @param x
 * @param y
 * @param z
 * @param roll
 * @param pitch
 * @param yaw
 * @param out_frame OUTPUT
 */
void create_kdl_frame(float x, float y, float z, float roll, float pitch, float yaw, KDL::Frame& out_frame) {

        out_frame.M = KDL::Rotation::RPY(
                roll,
                pitch,
                yaw
                );

        out_frame.p[0] = x;
        out_frame.p[1] = y;
        out_frame.p[2] = z;
}

/**
 * KDL Frame to Eigen Matrix 4x4
 * @param frame KDL Frame
 * @param mat Eigen Matrix 4x4
 */
void kdl_to_eigen_4x4(KDL::Frame& frame, Eigen::Matrix4f& mat) {
        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        mat(i, j) = frame.M(i, j);
                }
        }

        mat(0, 3) = frame.p[0];
        mat(1, 3) = frame.p[1];
        mat(2, 3) = frame.p[2];
        mat(3, 3) = 1;
}

/**
 * KDL Frame to Eigen Matrix 4x4
 * @param frame KDL Frame
 * @param mat Eigen Matrix 4x4
 */
void kdl_to_eigen_4x4_d(KDL::Frame& frame, Eigen::Matrix4d& mat) {
        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        mat(i, j) = frame.M(i, j);
                }
        }

        mat(0, 3) = frame.p[0];
        mat(1, 3) = frame.p[1];
        mat(2, 3) = frame.p[2];
        mat(3, 3) = 1;
}

/**
 * Creates Eigen4x4 Matrix
 * @param x
 * @param y
 * @param z
 * @param roll
 * @param pitch
 * @param yaw
 * @param mat
 */
void create_eigen_4x4(float x, float y, float z, float roll, float pitch, float yaw, Eigen::Matrix4f& mat) {
        KDL::Frame frame;
        create_kdl_frame(x, y, z, roll, pitch, yaw, frame);
        kdl_to_eigen_4x4(frame, mat);
}

/**
 * Creates Eigen4x4 Matrix
 * @param x
 * @param y
 * @param z
 * @param roll
 * @param pitch
 * @param yaw
 * @param mat
 */
void create_eigen_4x4_d(float x, float y, float z, float roll, float pitch, float yaw, Eigen::Matrix4d& mat) {
        KDL::Frame frame;
        create_kdl_frame(x, y, z, roll, pitch, yaw, frame);
        kdl_to_eigen_4x4_d(frame, mat);
}


/**
 * Inverts 4x4 Transformation matrix
 * @param in
 * @return
 */
Eigen::Matrix4f invert_transform_4x4(Eigen::Matrix4f & t) {
        Eigen::Matrix3f R = t.block<3, 3>(0, 0);
        Eigen::Vector3f translation = t.block<3, 1>(0, 3);
        Eigen::MatrixXf last_block = t.block<1, 4>(3, 0);

        Eigen::Matrix3f RT = R.transpose();
        Eigen::MatrixXf Temp(3, 4);
        translation = -RT*translation;
        Temp << RT, translation;
        Eigen::Matrix4f t2;
        t2 << Temp, last_block;

        return t2;
}

/**
 * Load 4x4 Transformation Matrix from file
 */
Eigen::Matrix4f load_transform_4x4(const std::string& filename){
        Eigen::Matrix4f mat;
        std::ifstream f (filename.c_str());
        float v;
        mat(3,0) = 0; mat(3,1) = 0; mat(3,2) = 0; mat(3,3) = 1;
        for (int y = 0; y < 3; y++)
        {
                for (int x = 0; x < 4; x++)
                {
                        f >> v;
                        mat(y,x) = static_cast<double> (v);
                }
        }
        f.close ();
        return mat;
}

/**
 * Load 4x4 Transformation Matrix from file
 */
Eigen::Matrix4d load_transform_4x4_d(const std::string& filename){
        Eigen::Matrix4d mat;
        std::ifstream f (filename.c_str());
        float v;
        mat(3,0) = 0; mat(3,1) = 0; mat(3,2) = 0; mat(3,3) = 1;
        for (int y = 0; y < 3; y++)
        {
                for (int x = 0; x < 4; x++)
                {
                        f >> v;
                        mat(y,x) = static_cast<double> (v);
                }
        }
        f.close ();
        return mat;
}

/**
 * Builds TF from geometry_msgs::Pose TODO: reverse
 */
void geometrypose_to_tf(geometry_msgs::Pose& pose,  tf::Transform& t, bool reverse = false){
        if(!reverse) {
                t.setOrigin( tf::Vector3(
                                     pose.position.x,
                                     pose.position.y,
                                     pose.position.z
                                     ));

                tf::Quaternion q(
                        pose.orientation.x,
                        pose.orientation.y,
                        pose.orientation.z,
                        pose.orientation.w
                        );

                t.setRotation(q);
        }else{
          pose.position.x = t.getOrigin()[0];
          pose.position.y = t.getOrigin()[1];
          pose.position.z = t.getOrigin()[2];
          pose.orientation.x = t.getRotation().x();
          pose.orientation.y = t.getRotation().y();
          pose.orientation.z = t.getRotation().z();
          pose.orientation.w = t.getRotation().w();
        }
}

}

#endif  /* LAR_TOOLS_H */
