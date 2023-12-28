
#include "Configurator.h"
#include <rapidjson/Document>
#include "Devices.h"

class Configurator {
public:

    Configurator();
    Configurator(const std::string &filePath);
    ~Configurator() {};
    bool setFromFile(const std::string &filePath);
    // function to set up ros2 hardware interface
    // bool SetConfig(Document config);
private:
    rapidjson::Document parsed_config;  // Assuming RapidJSON library
};
