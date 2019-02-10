#include <ros/ros.h>
#include <vehicle.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "swarm_node");
	ros::NodeHandle nh("~");
	ros::Rate rate(10);

	std::unique_ptr<SwarmVehicle> camila(new SwarmVehicle(nh, "camila", 6));

	ROS_INFO("swarm_node start");

	mavros_msgs::State state;
	while (ros::ok())
	{
		camila->run();

		ros::spinOnce();
		rate.sleep();
	}

	camila.release();
	return 0;
}