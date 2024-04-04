# To run simulation 

## Clone this repo
```
git clone --recurse-submodules -j8 git@github.com:kulkarni-raunak/nav2_ros_gz.git
```

## Inside nav2_ros_gz/

```
rosdep install -r --from-paths . --ignore-src --rosdistro $ROS_DISTRO -y
```

## Build

```
colcon build --symlink-install --packages-skip nav2_system_tests
```

## Launch
```
ros2 launch turtlebot3_gz gz_sim.launch.py 
```
