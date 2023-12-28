#import "CallbackFactory.h"
    
    static void createCallback(ClientNode& client_node, const std::string& topic_name, const ConfigItem& item) {
        std::function<void(const std::shared_ptr<typename T::MessageT>&)> callback =
            getCallbackFunction(client_node, item);
        client_node.createSubscription<typename T::MessageT>(topic_name, callback);
    }

    static std::function<void(const std::shared_ptr<typename T::MessageT>&)> getCallbackFunction(ClientNode& client_node, const ConfigItem& item) {
        // Map item type to specific callback creation logic
        if (item.type == "sensor") {
            return createSensorCallback(client_node, item);
        } else if (item.type == "actuator") {
            return createActionCallback(client_node, item);
        } else {
            // Handle unknown item types
            return {};  // Return an empty function
        }
    }

    // Implement specific callback creation logic for sensors and actuators
    static std::function<void(const std::shared_ptr<typename T::MessageT>&)> createSensorCallback(ClientNode& client_node, const ConfigItem& item) {
            return [&client_node, item](const std::shared_ptr<typename T::MessageT>& msg) {
            // Process sensor data using HardwareInterface
            client_node.hw_interface.processSensorData(item.name, msg);
        }
    }

    static std::function<void(const std::shared_ptr<typename T::MessageT>&)> createActionCallback(ClientNode& client_node, const ConfigItem& item) {
        return [&client_node, item](const std::shared_ptr<typename T::MessageT>& msg) {
            // Execute action using HardwareInterface
            client_node.hw_interface.executeAction(item.name, msg);
        };
    }