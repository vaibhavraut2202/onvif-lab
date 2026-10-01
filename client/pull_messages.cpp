#include "soapPullPointSubscriptionBindingProxy.h"
#include "PullPointSubscriptionBinding.nsmap"

#include <iostream>

int main()
{
    PullPointSubscriptionBindingProxy client;

    client.soap_endpoint =
        "http://192.168.137.186:8083";

    _tev__PullMessages request;
    _tev__PullMessagesResponse response;

    // Ask the PullPoint for up to 5 messages
    request.Timeout = 10;
    request.MessageLimit = 5;

    int result = client.PullMessages(
        &request,
        response
    );

    if (result != SOAP_OK)
    {
        client.soap_stream_fault(std::cerr);
        return 1;
    }

    std::cout << "PullMessages successful!\n\n";

    std::cout << "Current Time: "
              << response.CurrentTime
              << "\n";

    std::cout << "Termination Time: "
              << response.TerminationTime
              << "\n";

    std::cout << "\nNotification count: "
              << response.wsnt__NotificationMessage.size()
              << "\n";

    for (const auto* notification :
         response.wsnt__NotificationMessage)
    {
        std::cout << "\n--- Notification ---\n";

        if (notification->Topic)
        {
            std::cout << "Topic: "
                      << notification->Topic->__any
                      << "\n";

            std::cout << "Topic Dialect: "
                      << notification->Topic->Dialect
                      << "\n";
        }

        std::cout << "Message XML:\n";

        if (notification->Message.__any)
        {
            std::cout << notification->Message.__any
                      << "\n";
        }
    }

    return 0;
}