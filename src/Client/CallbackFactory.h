template <typename T>
class CallbackFactory 
{
public:
    static void createCallback(const std::string& topic_name, const ConfigItem& item);

private:
    static std::function<void(const std::shared_ptr<typename T::MessageT>&)> getCallbackFunction(ClientNode& client_node, const ConfigItem& item);
    static std::function<void(const std::shared_ptr<typename T::MessageT>&)> createSensorCallback(ClientNode& client_node, const ConfigItem& item);
    static std::function<void(const std::shared_ptr<typename T::MessageT>&)> createActionCallback(ClientNode& client_node, const ConfigItem& item)


};