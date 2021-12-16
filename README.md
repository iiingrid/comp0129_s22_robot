# Package Preparation:
```bash
> mkdir src
> git submodule add https://github.com/COMP0129-S22/panda_moveit_config.git src/panda_moveit_config
> git submodule add https://github.com/COMP0129-S22/panda_description.git src/panda_description
> git submodule add https://github.com/RPL-CS-UCL/realsense_gazebo_plugin.git src/realsense_gazebo_plugin 
> git submodule add https://github.com/RPL-CS-UCL/rpl_panda_with_rs.git src/rpl_panda_with_rs
```

# Pre-Requisites
```bash
> sudo apt install ros-melodic-franka-ros ros-melodic-libfranka
```

# Installation
```bash
> git clone --recurse-submodules https://github.com/COMP0129-S22/comp0129_s22_robot.git
> git submodule update --init --recursive
> cd comp0129_s22_robot & catkin build
```

# Run Panda robot Gazebo and rviz
```bash
> roslaunch panda_description description.launch
```
