#include <cw3/cw3.h>

#include <ros/ros.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <boost/graph/graph_concepts.hpp>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <visualization_msgs/Marker.h>

///////////////////////////////////////////////////////////////////////////////
// Initialise the filter boolean to be false
bool isFilterOn     = false;
bool isFastFilterOn = false;

int
main (int argc, char** argv)
{
  ros::init (argc, argv, "test_cw1");
  
  ros::NodeHandle nh ("~");
  
  // MoveIt! requirement for non-blocking group.move ()
  ros::AsyncSpinner spinner (1);
  spinner.start();
  
  // Create a cw1 object and update the parameters
  CW3 cw3_obj (nh);
  cw3_obj.updateParams (nh);
    
  /** Lab 1 */
  cw3_obj.Lab1CreateFrames ();
  
  //Decleare a joint state publisher
  ros::Publisher joint_pub = nh.advertise<sensor_msgs::JointState>("/move_group/fake_controller_joint_states", 0);

  // Publisher to publish boolean value of isFilterOn
  ros::Publisher filter_env_pub     = nh.advertise<std_msgs::Bool>("/is_filter_env", 0, false);
  ros::Publisher fastfilter_env_pub = nh.advertise<std_msgs::Bool>("/is_fastfilter_env", 0, false);

  // Publishers for bumper sensor informations
  ros::Publisher bumper1_pub       = nh.advertise<std_msgs::Bool>("/bumper1", 0, false);
  ros::Publisher bumper2_pub       = nh.advertise<std_msgs::Bool>("/bumper2", 1, true);
  ros::Publisher bumper3_pub       = nh.advertise<std_msgs::Bool>("/bumper3", 0, false);
  ros::Publisher cylinder_pose_pub = nh.advertise<geometry_msgs::PoseStamped>("/cylinder_pose", 1, true);

  // MoveIt! operates on sets of joints called "planning groups" and stores
  // them in an object called the `JointModelGroup`. Throughout MoveIt! the
  // terms "planning group" and "joint model group" are used interchangably.
  //
  // The :move_group_interface:`MoveGroup` class can be easily
  // setup using just the name of the planning group you would like to control
  // and plan for.
  ros::WallDuration(1.0).sleep ();
  static const std::string PLANNING_GROUP = "panda_arm";
  moveit::planning_interface::MoveGroupInterface move_group (PLANNING_GROUP);
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
  move_group.setPlanningTime (45.0);
  
  // Create collision objects: two tables, and a cylindric object
  cw3_obj.cw1Q3AddColObj (planning_scene_interface);
  
  ros::Rate r (10);
  while (ros::ok ())
  {
    cw3_obj.Lab1PublishFrames ();

    // Publish bumper sensor information 
    cw3_obj.publishBumpers(bumper1_pub, bumper2_pub, bumper3_pub);
    if (cw3_obj.kbhit()) // check if a key is pressed without blocking the while
    {
      int ch = getchar();

      // press f to trigger filterEnvironment
      if (ch == 'f') 
      {
        ROS_INFO("filterEnvironment Activated");
        // Toggle the filter activation boolean 
        isFilterOn = !isFilterOn;
        // Publish boolean message
        std_msgs::Bool msg;
        msg.data = isFilterOn;
        filter_env_pub.publish(msg);
      }

      // press p to trigger fastFilterEnvironment
      if (ch == 'p') 
      {
        ROS_INFO("fastFilterEnvironment Activated");
        // Toggle the filter activation boolean 
        isFastFilterOn = !isFastFilterOn;
        // Publish boolean message
        std_msgs::Bool msg;
        msg.data = isFastFilterOn;
        fastfilter_env_pub.publish(msg);
      }
      
      /*// press 1 to move object from ground to table1 centre in pick-and-place without constraint
      if (ch == '1')
      {
        std::string fromTable = "";
        std::string toTable   = "";
        // Check table 1 if there is an object via bumper
        if (cw3_obj.bumper1HasObject)
        {
          if (cw3_obj.objPosX == 0.0 && cw3_obj.objPosY == 0.5)
          {
            // Cylinder already on table one, do nothing.
            ROS_INFO("Cylinder already on table 1");
          }
          else 
          {
            // Stick object on table one, move it to any empty table.
            fromTable = "table1";
            if (!cw3_obj.bumper2HasObject)
            {
              toTable = "table2";
            }
            else if (!cw3_obj.bumper3HasObject)
            {
              toTable = "table3";
            }

            // Move stick
            bool isCylinder = false;
            cw3_obj.pick(move_group, fromTable, isCylinder);
            cw3_obj.place(move_group, toTable, isCylinder);

            // Update sensor value
            if (toTable.compare("table2") == 0)
            {
              cw3_obj.bumper2HasObject = true;
            }
            else if (toTable.compare("table3") == 0)
            {
              cw3_obj.bumper3HasObject = true;
            }
            cw3_obj.bumper1HasObject = false;
          }
        }
        
        if (!cw3_obj.bumper1HasObject)
        {*/
          // Find the location of the stack
          if (cw3_obj.objPosX == -0.5 && cw3_obj.objPosY == 0.0)
          {
            fromTable = "table2";
          }
          else if (cw3_obj.objPosX == 0.0 && cw3_obj.objPosY == -0.5)
          {
            fromTable = "table3";
          }
          else
          {
            fromTable = "";
          }
          toTable = "table1";

          // Move cylinder
          bool isCylinder = true;
          cw3_obj.pick(move_group, fromTable, isCylinder);
          cw3_obj.place(move_group, toTable, isCylinder);
          cw3_obj.updateCylinderPose(cylinder_pose_pub, toTable);
          cw3_obj.bumper1HasObject = true;

          // Update bumper
          if (fromTable.compare("table2") == 0)
          {
            cw3_obj.bumper2HasObject = false;
          }
          else if (fromTable.compare("table3") == 0)
          {
            cw3_obj.bumper3HasObject = false;
          }
        }
      }
      else if (ch == '2')
      {
        std::string fromTable = "";
        std::string toTable   = "";
        // Check table 2 if there is an object via bumper
        if (cw3_obj.bumper2HasObject)
        {
          if (cw3_obj.objPosX == -0.5 && cw3_obj.objPosY == 0.0)
          {
            // Cylinder already on table one, do nothing.
            ROS_INFO("Cylinder already on table 2");
          }
          else 
          {
            // Stick object on table two, move it to any empty table.
            fromTable = "table2";
            if (!cw3_obj.bumper1HasObject)
            {
              toTable = "table1";
            }
            else if (!cw3_obj.bumper3HasObject)
            {
              toTable = "table3";
            }

            // Move stick
            bool isCylinder = false;
            cw3_obj.pick(move_group, fromTable, isCylinder);
            cw3_obj.place(move_group, toTable, isCylinder);

            // Update sensor value
            if (toTable.compare("table1") == 0)
            {
              cw3_obj.bumper1HasObject = true;
            }
            else if (toTable.compare("table3") == 0)
            {
              cw3_obj.bumper3HasObject = true;
            }
            cw3_obj.bumper2HasObject = false;
          }
        }
        
        if (!cw3_obj.bumper2HasObject)
        {
          // Now find the location of the cylinder
          if (cw3_obj.objPosX == 0.0 && cw3_obj.objPosY == 0.5)
          {
            fromTable = "table1";
          }
          else if (cw3_obj.objPosX == 0.0 && cw3_obj.objPosY == -0.5)
          {
            fromTable = "table3";
          }
          else
          {
            fromTable = "";
          }
          toTable = "table2";

          // Move cylinder
          bool isCylinder = true;
          cw3_obj.pick(move_group, fromTable, isCylinder);
          cw3_obj.place(move_group, toTable, isCylinder);
          cw3_obj.updateCylinderPose(cylinder_pose_pub, toTable);
          cw3_obj.bumper2HasObject = true;

          // Update sensor value
          if (fromTable.compare("table1") == 0)
          {
            cw3_obj.bumper1HasObject = false;
          }
          else if (fromTable.compare("table3") == 0)
          {
            cw3_obj.bumper3HasObject = false;
          }
        }
      }
      else if (ch == '3')
      {
        std::string fromTable = "";
        std::string toTable   = "";
        // Check table 3 if there is an object via bumper
        if (cw3_obj.bumper3HasObject)
        {
          if (cw3_obj.objPosX == 0.0 && cw3_obj.objPosY == -0.5)
          {
            // Cylinder already on table one, do nothing.
            ROS_INFO("Cylinder already on table 3");
          }
          else 
          {
            // Stick object on table three, move it to any empty table.
            fromTable = "table3";
            if (!cw3_obj.bumper1HasObject)
            {
              toTable = "table1";
            }
            else if (!cw3_obj.bumper2HasObject)
            {
              toTable = "table2";
            }

            // Move stick
            bool isCylinder = false;
            cw3_obj.pick(move_group, fromTable, isCylinder);
            cw3_obj.place(move_group, toTable, isCylinder);

            // Update sensor value
            if (toTable.compare("table1") == 0)
            {
              cw3_obj.bumper1HasObject = true;
            }
            else if (toTable.compare("table2") == 0)
            {
              cw3_obj.bumper2HasObject = true;
            }
            cw3_obj.bumper3HasObject = false;
          }
        }
        
        if (!cw3_obj.bumper3HasObject)
        {
          // Now find the location of the cylinder
          if (cw3_obj.objPosX == 0.0 && cw3_obj.objPosY == 0.5)
          {
            fromTable = "table1";
          }
          else if (cw3_obj.objPosX == -0.5 && cw3_obj.objPosY == 0.0)
          {
            fromTable = "table2";
          }
          else
          {
            fromTable = "";
          }
          toTable = "table3";

          // Move cylinder
          bool isCylinder = true;
          cw3_obj.pick(move_group, fromTable, isCylinder);
          cw3_obj.place(move_group, toTable, isCylinder);
          cw3_obj.updateCylinderPose(cylinder_pose_pub, toTable);
          cw3_obj.bumper3HasObject = true;

          // Update sensor value
          if (fromTable.compare("table1") == 0)
          {
            cw3_obj.bumper1HasObject = false;
          }
          else if (fromTable.compare("table2") == 0)
          {
            cw3_obj.bumper2HasObject = false;
          }
        }
      }
    }
    ros::spinOnce();
    r.sleep();
  }
  return (0);
}
