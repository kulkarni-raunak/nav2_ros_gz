#!/bin/bash

# Immediately catch all errors
# set -eo pipefail

# Uncomment for debugging
# set -x
# env

# Install dependencies
cd /nav2_ros_gz && rosdep install -r --from-paths src/gz_ros2_control --ignore-src --rosdistro $ROS_DISTRO -y

source .bashrc

echo "finished: .devcontainer/update-content-command.sh"