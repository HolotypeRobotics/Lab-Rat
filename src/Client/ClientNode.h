#include "rclcpp/rclcpp.hpp"

class ClientNode : public rclcpp::Node
{
    public:
        ClientNode() : Node("client_node");
        ~ClientNode();
        bool initialize(std::string path);
        bool configure(std::string path);
        
    private:
        HardwareInterface hw_interface;
        rclcpp::Subscription<your_custom_msgs::ActionMatrix>::SharedPtr action_subscriber_;
        rclcpp::Subscription<your_custom_msgs::AttentionMatrix>::SharedPtr attention_subscriber_;
};
