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
# xterm for teleop keyboard shell
#  gdb & gdbserver -> for debugging ros2 cpp nodes
RUN apt-get update && apt-get install -y \
    ros-${ROS_DISTRO}-joint-state-publisher-gui \
    ros-${ROS_DISTRO}-turtlebot3 \
    ros-${ROS_DISTRO}-controller-manager-dbgsym \
    ros-${ROS_DISTRO}-controller-manager \
    ros-${ROS_DISTRO}-behaviortree-cpp \
    ros-${ROS_DISTRO}-test-msgs-dbgsym \
    ros-${ROS_DISTRO}-robot-localization-dbgsym \
    libgz-plugin2-dev \
    gdb \
    gdbserver \
    xterm


# install Groot
RUN cd /home \
    && wget https://s3.us-west-1.amazonaws.com/download.behaviortree.dev/groot2_linux_installer/Groot2-v1.5.2-linux-installer.run \
    && chmod +x Groot2-v1.5.2-linux-installer.run \
    && /home/Groot2-v1.5.2-linux-installer.run in -c --al --root /home/Groot \
    && echo "alias groot=/home/Groot/bin/groot2" >> /etc/bash.bashrc


RUN apt-get install -y \
    libzmq3-dev \
    libboost-dev

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

## install python packages

# Rosdep update
RUN rosdep update

# Source the ROS setup file
RUN echo "source /opt/ros/${ROS_DISTRO}/setup.bash" >> ~/.bashrc
