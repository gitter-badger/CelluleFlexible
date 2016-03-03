#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

#include "vrepController.h"
#include "UI.h"
#include "inOutController.h"

#include <ros/ros.h>



int main(int argc, char **argv)
{
			//Initialisation du noeud ROS
			ros::init(argc, argv, "simulation");
			ros::NodeHandle nh;

			// VREP CONTROLLER 
			vrepController VREPController;
			VREPController.init(nh);

			// USER INTERFACE
			UI userInterface;
			userInterface.init(nh);

			// IN & OUT CONTROLLER
			inOutController IOController(&userInterface);
			IOController.init(nh);

			for(int i=1;i<=argc-1;i++) VREPController.loadModel(argv[i][0]); 

			// Demarrage de la simulation pour avoir la premiere image
			VREPController.play();
			// Pause pour laisser à l'utilisateur le soin de Commencer la simulation
			VREPController.pause();

			while (ros::ok())
			{
				ros::spinOnce();
			}				
				
			userInterface.close();
			VREPController.close();
			return 0;
}
