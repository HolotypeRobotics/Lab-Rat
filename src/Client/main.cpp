#include "ClientNode.h"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    Configurator configurator;
    configurator.configure(hw_interface, config);
    hw_interface.init(config);
    rclcpp::spin(std::make_shared<ClientNode>());
    rclcpp::shutdown();
    return 0;
}