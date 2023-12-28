#include "Device.h"
#include <rclcpp/rclcpp.hpp>
#include <hardware_interface/hardware_interface.hpp>
#include <hardware_interface/types/hardware_interface_return_values.hpp>
#include <hardware_interface/types/hardware_interface_status_values.hpp>
#include <hardware_interface/types/hardware_interface_type_values.hpp>
#include <hardware_interface/types/hardware_interface_state.hpp>
#include <hardware_interface/types/hardware_interface_command.hpp>

#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Device : public hardware_interface::HardwareInterface {
public:
  Device(const std::string& config_file_path) {
    loadConfig(config_file_path);
    // Initialize hardware interface based on config
    // ...
  }

  hardware_interface::return_type configure(
      const hardware_interface::HardwareInfo& info) override {
    // Configuration logic based on the hardware_info
    // ...
    return hardware_interface::return_type::OK;
  }

  void read() override {
    // Read data from Zephyr driver
    // ...
  }

  void write() override {
    // Write commands to Zephyr driver
    // ...
  }

private:
  void loadConfig(const std::string& config_file_path) {
    std::ifstream config_file(config_file_path);
    json config;
    config_file >> config;

    if (config.contains("hardware_interface")) {
      auto hw_config = config["hardware_interface"];
      if (hw_config.contains("type") && hw_config["type"] == "zephyr_driver") {
        // Extract parameters and initialize Zephyr driver
        // ...
      }
    }
  }
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("zephyr_interface_node");
  auto hw_interface = std::make_shared<ZephyrHardwareInterface>("path_to_config.json");

  // Register hardware interface with the node
  rclcpp::register_interface_node(node, hw_interface);

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
