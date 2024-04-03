# To run simulation 

## Clone this repo
```
git clone --recurse-submodules -j8 git@github.com:kulkarni-raunak/nav2_ros_gz.git
```

## Inside ws_nav2/src/

```
rosdep install -r --from-paths . --ignore-src --rosdistro $ROS_DISTRO -y
```

## Build

```
colcon build --symlink-install
```

## Launch
```
ros2 launch turtlebot3_gz gz_sim.launch.py 
```
