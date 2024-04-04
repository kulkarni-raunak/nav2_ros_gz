# Build on top of npslearninglab/watery_robots:vrx_current. It has ros2 humble, gazebo garden installed. 
FROM npslearninglab/watery_robots:vrx_current

# Switch USER from developer to root
# https://hub.docker.com/layers/npslearninglab/watery_robots/vrx_current/images/sha256-c8bb6645b728f18e8f8dd9f423eddc258eb2b1efedc3a0d4ec36b57e52e4e4f9?context=explore
USER root

RUN apt-get update \
    && apt-get install -y \
    gz-garden \
    ros-${ROS_DISTRO}-ros-gzgarden

## install dependencies
# libgz-plugin2-dev for gz_ros2_control
# libsdl-image1.2-dev and libsdl-image-dev for nav2_util
# ros-${ROS_DISTRO}-test-msgs-dbgsym for nav2_util 
# ros-${ROS_DISTRO}-robot-localization-dbgsym for nav2_behavior_tree
RUN apt-get update && apt-get install -y \
    ros-${ROS_DISTRO}-joint-state-publisher-gui \
    # ros-${ROS_DISTRO}-navigation2 \
    # ros-${ROS_DISTRO}-nav2-bringup \ 
    ros-${ROS_DISTRO}-turtlebot3 \
    ros-${ROS_DISTRO}-controller-manager-dbgsym \
    ros-${ROS_DISTRO}-controller-manager \
    libgz-plugin2-dev \
    ros-${ROS_DISTRO}-test-msgs-dbgsym \
    ros-${ROS_DISTRO}-robot-localization-dbgsym
    # libsdl-image1.2-dev \
    # libsdl2-image-dev
    
# # install python packages
# RUN pip3 install \
#     transforms3d

# Add vscode user with same UID and GID as your host system
# (copied from https://code.visualstudio.com/remote/advancedcontainers/add-nonroot-user#_creating-a-nonroot-user)
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME
# Switch from root to user
USER $USERNAME

# Add user to video group to allow access to webcam
RUN sudo usermod --append --groups video $USERNAME

# Update all packages
RUN sudo apt update & sudo apt upgrade -y

## install dependencies
# for teleop keyboard shell
RUN sudo apt install -y xterm   

# gdb & gdbserver -> for debugging ros2 cpp nodes
RUN sudo apt install -y \
    gdb \
    gdbserver

## install python packages

# Rosdep update
RUN rosdep update

# Source the ROS setup file
RUN echo "source /opt/ros/${ROS_DISTRO}/setup.bash" >> ~/.bashrc
