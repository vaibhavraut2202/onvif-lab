#include "soapEventBindingProxy.h"
#include "EventBinding.nsmap"

#include <iostream>

int main()
{
    EventBindingProxy client;

    client.soap_endpoint = "http://192.168.137.186:8082";

    _tev__CreatePullPointSubscription request;
    _tev__CreatePullPointSubscriptionResponse response;

    int result = client.CreatePullPointSubscription(
        &request,
        response
    );

    if (result != SOAP_OK)
    {
        client.soap_stream_fault(std::cerr);
        return 1;
    }

    std::cout << "CreatePullPointSubscription successful!\n\n";

    std::cout << "Subscription Reference:\n";
    std::cout << "  Address: "
              << response.SubscriptionReference.Address
              << "\n";

    std::cout << "\nCurrent Time: "
              << response.wsnt__CurrentTime
              << "\n";

    std::cout << "Termination Time: "
              << response.wsnt__TerminationTime
              << "\n";

    return 0;
}