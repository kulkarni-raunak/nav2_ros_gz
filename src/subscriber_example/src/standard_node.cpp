#include <iostream>
#include <chrono>
#include "behaviortree_cpp/behavior_tree.h"

using namespace std::chrono_literals;

class Standard_ConditionNode : public BT::ConditionNode
{
 public:
  Standard_ConditionNode(const std::string& name) :
      BT::ConditionNode(name, {})
  {}

  BT::NodeStatus tick() override
  {
    std::this_thread::sleep_for(1s);
    return BT::NodeStatus::SUCCESS;
  }
};