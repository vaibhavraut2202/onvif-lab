#include "soapSubscriptionManagerBindingProxy.h"
#include "SubscriptionManagerBinding.nsmap"

#include <iostream>

int main()
{
    SubscriptionManagerBindingProxy client;

    client.soap_endpoint =
        "http://192.168.137.152:8084";

    _wsnt__Unsubscribe request;
    _wsnt__UnsubscribeResponse response;

    int result = client.Unsubscribe(
        &request,
        response
    );

    if (result != SOAP_OK)
    {
        client.soap_stream_fault(std::cerr);
        return 1;
    }

    std::cout << "Unsubscribe successful!" << std::endl;

    return 0;
}