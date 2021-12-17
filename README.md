Author: Dimitrios Kanoulas (d.kanoulas@ucl.ac.uk), Luke Beddow, Denis Hadjivelichkov

Description: This package implements some sample code for COMP0129-S22

## Pre-Requisites
```bash
> sudo apt install ros-melodic-franka-ros ros-melodic-libfranka
```

## Installation
```bash
> git clone --recurse-submodules https://github.com/COMP0129-S22/comp0129_s22_robot.git
> cd comp0129_s22_robot
> git submodule update --init --recursive
> catkin build
```

## Run Panda robot Gazebo and rviz
```bash
> source devel/setup.bash
> roslaunch panda_description description.launch
```

## Package Preparation (not to be ran by students):
```bash
> mkdir src
> git submodule add https://github.com/COMP0129-S22/panda_moveit_config.git src/panda_moveit_config
> git submodule add https://github.com/COMP0129-S22/panda_description.git src/panda_description
> git submodule add https://github.com/RPL-CS-UCL/realsense_gazebo_plugin.git src/realsense_gazebo_plugin 
> git submodule add https://github.com/RPL-CS-UCL/rpl_panda_with_rs.git src/rpl_panda_with_rs
``

LICENSE: MIT.  See LICENSE.txt

DISCLAIMER:

THIS INFORMATION AND/OR SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS INFORMATION AND/OR
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Copyright (C) 2019-2022 Dimitrios Kanoulas except where specified
