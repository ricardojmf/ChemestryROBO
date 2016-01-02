#include <ros/ros.h> //Must include this for all ROS cpp projects
#include <sensor_msgs/LaserScan.h>
#include <std_msgs/Float32.h> //Including the Float32 class from std_msgs
#include <std_msgs/Bool.h> // boolean message time
#include "sensor_msgs/Range.h"
#include <geometry_msgs/Twist.h> // For geometry_msgs : : Twist
#include <stdlib.h> // For rand () and RAND_MAX
#include <math.h>

using namespace std;

#define ATOM1 "robot0"
#define ATOM2 "robot1"
#define FRONT_SONAR "sonar_0"
#define UPPER_SONAR "sonar_1"
#define CMD_VEL "cmd_vel"

ros::Publisher pub1;
ros::Publisher pub2;

double sonar1;
double sonar2;
int sonar = 1;
int x = 0;

string topicCreation(string robotName, string type);
void sonarCallback_sonar_2(const sensor_msgs::Range::ConstPtr& m);
void sonarCallback_sonar_0(const sensor_msgs::Range::ConstPtr& m);

int main(int argc, char **argv)
{
		ros::init(argc, argv, "test");

		string topic1 = topicCreation(ATOM1, FRONT_SONAR);
		cout << "TOPIC1: " << topic1 << endl;
		string topic2 = topicCreation(ATOM1, UPPER_SONAR);
		cout << "TOPIC2: " << topic2 << endl;
		string topic3 = topicCreation(ATOM1, CMD_VEL);
		cout << "TOPIC3: " << topic3 << endl;

		string topic4 = topicCreation(ATOM2, FRONT_SONAR);
		cout << "TOPIC4: " << topic4 << endl;
		string topic5 = topicCreation(ATOM2, UPPER_SONAR);
		cout << "TOPIC5: " << topic5 << endl;
		string topic6 = topicCreation(ATOM2, CMD_VEL);
		cout << "TOPIC6: " << topic5 << endl;

    ros::NodeHandle nh;

		pub1 = nh.advertise <geometry_msgs::Twist > (topic3.c_str(), 1000) ;
		pub2 = nh.advertise <geometry_msgs::Twist > (topic6.c_str(), 1000) ;

    srand(time(0));

    ros::spin();

    return 0;
}

string topicCreation(string robotName, string type)
{
	return robotName + "/" + type;
}

void sonarCallback_sonar_2(const sensor_msgs::Range::ConstPtr& m)
{
	sonar2 = m->range;
}

void sonarCallback_sonar_0(const sensor_msgs::Range::ConstPtr& m)
{

	geometry_msgs:: Twist msg;

	sonar1 = m->range;

	ROS_INFO_STREAM("\nsonar1: " << sonar1);
	ROS_INFO_STREAM("\nsonar2: " << sonar2);

  ros:: Rate rate(2);


  	if(sonar == 1)
    {
      if(sonar1 < 0.8)
      {
        msg.linear.x = 0;
        msg.angular.z = M_PI;
        sonar = 2;
      }
      else
      {
        msg.linear.x = 1;
      }
    }

  	else if(sonar == 2)
  	{
  		if(sonar2 <= 2)
      {
         x = 0;
      }


  		if(!(sonar2 < 2) && !(sonar1 < 1) && x == 0)
  		{
       	msg.linear.x = 0;
      	msg.angular.z = -M_PI;
        x = 1;
  		}
      else if(!(sonar2 < 2) && !(sonar1 < 1)&& x == 1)
      {
        msg.linear.x = 1;
      }
  		else if(!(sonar1 < 1) && sonar2 < 2)
  		{
  			msg.linear.x = 1;
  		}
  		else if(sonar1 < 1)
  		{
  			msg.linear.x = 0;
      	msg.angular.z = M_PI;
  		}
    }

	pub1.publish(msg);
	pub2.publish(msg);
  rate.sleep();
}
