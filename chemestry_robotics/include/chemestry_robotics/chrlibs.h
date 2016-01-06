#include <ros/ros.h>
#include <iostream>
#include <string>
#include <geometry_msgs/Twist.h> // For geometry_msgs : : Twist
#include <stdlib.h>
#include <vector>

#define CMD_VEL "cmd_vel"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592
#define VEL_LINEAR (double) 0.5
#define VEL_ANGULAR (double) PI / 6

using namespace std;
