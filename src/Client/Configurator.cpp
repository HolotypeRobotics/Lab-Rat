#include "CallbackFactory.h"
#include "rapidjson/document.h"
#include <string>
#include <vector>
#include <iostream>

using namespace rapidjson;

void CallbackFactory::registerType(string name, shared_ptr<CallbackCreatorBase> creator) {
    if (callbacks_.find(name) != callbacks_.end()) {
        cerr << "Duplicate callback type: " << name << endl;
        abort();
    }
        callbacks_[name] = creator;
    }
void Configurator::configure(ClientNode& client_node, std::string path) {
    configureBoard(client_node, config);
    configureSensors(client_node, config);
    configureActuators(client_node, config);
}

template <typename T>
void configureCallbacks(ClientNode& client_node, const std::vector<T>& config_items, const std::string& prefix) {
    for (const auto& item : config_items) {
        std::string topic_name = prefix + item.name;
        CallbackFactory<T>::createCallback(client_node, topic_name, item);
    }
}

void Configurator::configureSensors(ClientNode& client_node, const Config& config) {
    //
    configureCallbacks<SensorConfigItem>(config.sensors, "sensor_");
}

void Configurator::configureActuators(ClientNode& client_node, const Config& config) {
    configureCallbacks<ActuatorConfigItem>(config.actuators, "action_");
}

void Configurator::configureBoard(ClientNode& client_node, const Config& config) {
    // Publish board info to the ROS system
    // if (!config.board.info_topic.empty()) {
    //     InfoPublisher publisher(&client_node, config.board.info_topic);
    //     BoardInfo info;
    //     info.set_model(config.board.model);
    //     info.set_revision(config.board.revision);
    //     info.set_cpu(config.board.cpu);
    //     info.set_ram(config.board.ram);
    //     info.set_mac(config.board.mac);
    //     }
    return;
    }
