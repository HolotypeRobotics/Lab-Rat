#include "rclcpp/rclcpp.hpp"
#include "custom_msgs/ActionMatrix.hpp"
#include "custom_msgs/FocusMatrix.hpp"
#include "configurator.h"
#include "hardware_interface.h"
#include "ClientNode.h"


    ClientNode::ClientNode() : Node("client_node")
    {

        // Subscribe to the action and focus matrices
        action_subscriber_ = this->create_subscription<your_custom_msgs::ActionMatrix>(
            "action_matrix_topic", 10,
            std::bind(&ClientNode::actionCallback, this, std::placeholders::_1));

        focus_subscriber_ = this->create_subscription<your_custom_msgs::FocusMatrix>(
            "attention_matrix_topic", 10,
            std::bind(&ClientNode::focusCallback, this, std::placeholders::_1));
        
    }

    void ClientNode::initialize(const Config& config) {
        Configurator configurator;
        configurator.configure(*this, config);
    }

    ClientNode::~ClientNode()
    {
    }

    ClientNode::configure

