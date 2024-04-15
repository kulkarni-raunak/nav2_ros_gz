#!/bin/bash

# Immediately catch all errors
set -eo pipefail


# ros2 Sourcing and model paths
echo 'source /opt/ros/humble/setup.bash' >> ~/.bashrc
echo 'export TURTLEBOT3_MODEL=waffle' >> ~/.bashrc
echo 'export GZ_VERSION=garden' >> ~/.bashrc
echo 'source /nav2_ros_gz/install/setup.bash && pwd' >> ~/.bashrc

echo "finished: .devcontainer/post-create-command.sh"
