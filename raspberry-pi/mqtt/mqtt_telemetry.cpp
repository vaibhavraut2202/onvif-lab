#include <mqtt/async_client.h>
#include <iostream>
#include <chrono>
#include <thread>

class command_callback : public virtual mqtt::callback
{
public:
    void message_arrived(mqtt::const_message_ptr msg) override
    {
        std::cout << "Command received: "
                  << msg->to_string()
                  << std::endl;
    }
};

int main()
{
    const std::string SERVER_ADDRESS = "tcp://localhost:1883";
    const std::string CLIENT_ID = "pi_telemetry";
    const std::string TELEMETRY_TOPIC = "device/pi4/telemetry";
    const std::string STATUS_TOPIC = "device/pi4/status";
    const std::string COMMAND_TOPIC = "device/pi4/command/led";

    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);

    mqtt::connect_options connOpts;
    connOpts.set_user_name("piuser");
    connOpts.set_password("12345678");

    mqtt::message willMessage(
        STATUS_TOPIC,
        "OFFLINE",
        1,
        true
    );

    connOpts.set_will(willMessage);

    command_callback callback;
    client.set_callback(callback);

    std::cout << "Connecting to MQTT broker..." << std::endl;

    client.connect(connOpts)->wait();

    std::cout << "Connected!" << std::endl;

    auto onlineMessage =
        mqtt::make_message(STATUS_TOPIC, "ONLINE");

    onlineMessage->set_qos(1);
    onlineMessage->set_retained(true);

    client.publish(onlineMessage)->wait();

    client.subscribe(COMMAND_TOPIC, 1)->wait();

    std::cout << "Subscribed to: "
              << COMMAND_TOPIC
              << std::endl;

    int temperature = 25;
    int humidity = 60;
    int uptime = 0;

    while (true)
    {
        std::string payload =
            "temperature=" + std::to_string(temperature) +
            ",humidity=" + std::to_string(humidity) +
            ",uptime=" + std::to_string(uptime);

        auto message =
            mqtt::make_message(TELEMETRY_TOPIC, payload);

        message->set_qos(1);

        client.publish(message)->wait();

        std::cout << "Published: "
                  << payload
                  << std::endl;

        temperature++;
        humidity--;
        uptime += 5;

        std::this_thread::sleep_for(
            std::chrono::seconds(5)
        );
    }

    return 0;
}
