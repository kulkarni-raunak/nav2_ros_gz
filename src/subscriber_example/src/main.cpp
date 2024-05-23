#include "float_subscriber_node.cpp"
#include "standard_node.cpp"


// Simple tree, used to execute once each action.
  static const char* xml_text = R"(
  <root BTCPP_format="4">
    <BehaviorTree>
      <Sequence>
        <ReceiveFloat name="A"/>
        <Standard_ConditionNode name="B"/>
        <ReceiveFloat name="C"/>
      </Sequence>
    </BehaviorTree>
  </root>
 )";

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto nh = std::make_shared<rclcpp::Node>("subscriber_test");

  BehaviorTreeFactory factory;

  RosNodeParams params;
  params.nh = nh;
  params.default_port_value = "btcpp_string";
  factory.registerNodeType<ReceiveFloat>("ReceiveFloat", params);
  factory.registerNodeType<Standard_ConditionNode>("Standard_ConditionNode");

  // auto tree = factory.createTreeFromText(xml_text);

  auto tree = factory.createTreeFromFile("src/subscriber_example/src/subscriber_test_tree.xml");

  while(rclcpp::ok())
  {
    tree.tickWhileRunning();
  }

  return 0;
}
