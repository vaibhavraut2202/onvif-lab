#include "soapSubscriptionManagerBindingProxy.h"
#include "SubscriptionManagerBinding.nsmap"

#include <iostream>

int main()
{
    SubscriptionManagerBindingProxy client;

    client.soap_endpoint =
        "http://192.168.137.152:8084";

    _wsnt__Renew request;
    _wsnt__RenewResponse response;

    // Request a 2-hour subscription duration
    request.TerminationTime =
        new std::string("PT2H");

    int result = client.Renew(
        &request,
        response
    );

    if (result != SOAP_OK)
    {
        client.soap_stream_fault(std::cerr);
        return 1;
    }

    std::cout << "Renew successful!\n\n";

    if (response.CurrentTime)
    {
        std::cout << "Current Time: "
                  << *response.CurrentTime
                  << "\n";
    }

    std::cout << "New Termination Time: "
              << response.TerminationTime
              << "\n";

    return 0;
}