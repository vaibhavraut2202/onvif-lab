#include "soapEventBindingProxy.h"
#include "EventBinding.nsmap"

#include <iostream>
#include <string>

int main()
{
    EventBindingProxy client;

    client.soap_endpoint = "http://192.168.137.186:8082";

    _tev__GetEventProperties request;
    _tev__GetEventPropertiesResponse response;

    int result = client.GetEventProperties(
        &request,
        response
    );

    if (result != SOAP_OK)
    {
        client.soap_stream_fault(std::cerr);
        return 1;
    }

    std::cout << "GetEventProperties successful!\n\n";

    std::cout << "Topic Namespace Locations:\n";

    for (const auto& location : response.TopicNamespaceLocation)
    {
        std::cout << "  " << location << "\n";
    }

    std::cout << "\nFixed Topic Set: "
              << (response.wsnt__FixedTopicSet ? "true" : "false")
              << "\n";

    std::cout << "\nTopic Expression Dialects:\n";

    for (const auto& dialect : response.wsnt__TopicExpressionDialect)
    {
        std::cout << "  " << dialect << "\n";
    }

    std::cout << "\nMessage Content Filter Dialects:\n";

    for (const auto& dialect : response.MessageContentFilterDialect)
    {
        std::cout << "  " << dialect << "\n";
    }

    return 0;
}