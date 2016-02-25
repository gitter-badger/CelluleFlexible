#ifndef SWITCH_STATE
#define SWITCH_STATE
#include <ros/ros.h>
#include "simulation/Msg_SwitchControl.h"

class switchState
{
private:
	ros::Publisher switchStatePublisher;
	simulation::Msg_SwitchControl stateSwitches;
public:

	switchState ();
	void unlockSwitch(int numSwitch);
	void lockSwitch(int numSwitch);
	void turnRight(int numSwitch);
	void turnLeft(int numSwitch);
	void publish();
	void init(ros::NodeHandle n);
};

#endif
