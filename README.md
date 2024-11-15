# To run simulation 

## Clone this repo
```bash
git clone --recurse-submodules -j8 git@github.com:kulkarni-raunak/nav2_ros_gz.git
```
## Add .bash_history inside nav2_ros_gz/
`touch .bash_history`

## Install dependencies (already done in the dev container)
### Inside nav2_ros_gz/ 

```bash
rosdep install -r --from-paths . --ignore-src --rosdistro $ROS_DISTRO -y
```

## Build

```bash
colcon build --symlink-install --packages-skip nav2_system_tests
```
## Source or open another terminal tab (as already sourced in the dev container bashrc)
```bash
source /nav2_ros_gz/install/setup.bash
```

## Launch
```bash
ros2 launch nav2_bringup tb3_gz_simulation_launch.py headless:=False
```

## Launch [To work with wamv]
### (Note1: waveglider is still pending)
### (Note2: Map and Mask path will needed to be modified depending from which devcontainer/folder you'll call them)
For World = Sydney regatta
```bash
ros2 launch nav2_bringup wamv_nav2_gz_simulation_launch.py params_file:=/nav2_ros_gz/src/navigation2/nav2_bringup/params_imarex/nav2_params.yaml use_sim_time:=true map:=/nav2_ros_gz/src/navigation2/nav2_bringup/maps/sydney_regatta.yaml mask:=/nav2_ros_gz/src/navigation2/nav2_bringup/maps/keepout_mask.yaml
```
For World = Port of Bremen
```bash
ros2 launch nav2_bringup wamv_nav2_gz_simulation_launch.py params_file:=/nav2_ros_gz/src/navigation2/nav2_bringup/params_imarex/nav2_params.yaml use_sim_time:=true map:=/scenario-simulation/src/submodules/katamaran_nav2_bt/maps/Port_bremen/Port_Bremen_Polygon.yaml mask:=/scenario-simulation/src/submodules/katamaran_nav2_bt/maps/Port_bremen/avoid_area_01.yaml 
```


## Refrences

Follow [migration of gazebos_ros_pkgs to ros_gz guide](https://gazebosim.org/docs/garden/migrating_gazebo_classic_ros2_packages) to tweak the packges dependent on gazebo_ros in nav2/navigation2 . `Note: May not support Gazebo garden.`
