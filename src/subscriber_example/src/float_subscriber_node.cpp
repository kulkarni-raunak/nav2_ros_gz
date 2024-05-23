#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include <std_msgs/msg/float32.hpp>

using namespace BT;

class ReceiveFloat: public RosTopicSubNode<std_msgs::msg::Float32>
{
public:
  ReceiveFloat(const std::string& name,
                const NodeConfig& conf,
                const RosNodeParams& params)
    : RosTopicSubNode<std_msgs::msg::Float32>(name, conf, params)
  {}

  static BT::PortsList providedPorts()
  {
    return {};
  }

  NodeStatus onTick(const std::shared_ptr<std_msgs::msg::Float32>& last_msg) override
  {
    if(last_msg) // empty if no new message received, since the last tick
    {
      std::cout << "Got a message" << std::endl;
      RCLCPP_INFO(logger(), "[%s] new message: %f", name().c_str(), last_msg->data);
    }
    return NodeStatus::SUCCESS;
  }
};
