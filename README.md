# To run simulation 

## Clone this repo
```
git clone --recurse-submodules -j8 git@github.com:kulkarni-raunak/nav2_ros_gz.git
```
## Add .bash_history inside nav2_ros_gz/
`touch .bash_history`

## ~~Install dependencies~~ (already done in the dev container)
### ~~Inside nav2_ros_gz/~~ 

<del>
  
```
rosdep install -r --from-paths . --ignore-src --rosdistro $ROS_DISTRO -y
```

</del>

## Build
~~Build Everything!!~~ Takes about 30~40 mins!!

<del>
  
```
colcon build --symlink-install --packages-skip nav2_system_tests
```
</del>


Now you can only build the package that you made changes to and **save time**. i.e.,
```bash
colcon build --symlink-install --packages-select nav2_bringup
source /nav2_ros_gz/install/setup.bash
```
> or just open another terminal tab (this WS is already sourced in the dev container's ~/.bashrc)

## Launch
```
ros2 launch nav2_bringup tb3_gz_simulation_launch.py headless:=False
```

## Refrences

Follow [migration of gazebos_ros_pkgs to ros_gz guide](https://gazebosim.org/docs/garden/migrating_gazebo_classic_ros2_packages) to tweak the packges dependent on gazebo_ros in nav2/navigation2 . `Note: May not support Gazebo garden.`
