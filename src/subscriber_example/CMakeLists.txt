cmake_minimum_required(VERSION 3.16)
project(subscriber_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ament_cmake REQUIRED)
find_package(behaviortree_ros2 REQUIRED)
find_package(std_msgs REQUIRED)
find_package(action_tutorials_interfaces REQUIRED)
find_package(behaviortree_cpp REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)


set(THIS_PACKAGE_DEPS 
    behaviortree_ros2
    std_msgs
    behaviortree_cpp
    rclcpp
    rclcpp_action
    action_tutorials_interfaces)

######################################################
# Build subscriber_test
add_executable(subscriber_test src/main.cpp)
ament_target_dependencies(subscriber_test ${THIS_PACKAGE_DEPS}) 

######################################################

######################################################
# Build fibonacci_test
add_executable(fibonacci_test src/fibonacci_main.cpp)
ament_target_dependencies(fibonacci_test ${THIS_PACKAGE_DEPS}) 

######################################################
# INSTALL

install(TARGETS
  subscriber_test
  fibonacci_test
  DESTINATION lib/${PROJECT_NAME}
  )

ament_export_dependencies(behaviortree_ros2)

ament_package()
