#include <vector>
#include <string>

class Devices
{
    
public:
    Devices();
    ~Devices();

    typedef struct BoardStruct {
        int id; 
        int type;
    } Board;

    typedef struct ActuatorStruct {
        std::string name;
        // value range. could be any type, defined be python style list in json file

    } Actuator;

    typedef struct SensorStruct {
        std::string name;
        // value range. could be any type, defined be python style list in json file

    } Sensor;
    

private:
    std::vector<Board> boards;
    std::vector<Actuator> actuators;
    std::vector<Sensor> sensors;

};