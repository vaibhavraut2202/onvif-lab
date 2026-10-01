#include "soapDeviceBindingProxy.h"
#include "DeviceBinding.nsmap"
#include <iostream>

int main()
{
    DeviceBindingProxy proxy;

    const char* endpoint =
        "http://192.168.137.186:8080";

    proxy.soap->userid = NULL;
    proxy.soap->passwd = NULL;

    _tds__GetCapabilities request;
    _tds__GetCapabilitiesResponse response;

    if (proxy.GetCapabilities(
            endpoint,
            NULL,
            &request,
            &response) == SOAP_OK)
    {
        if (response.Capabilities)
        {
            if (response.Capabilities->Device)
            {
                std::cout << "Device XAddr: "
                          << response.Capabilities->Device->XAddr
                          << std::endl;
            }
        }
    }
    else
    {
        proxy.soap_stream_fault(std::cerr);
    }

    return 0;
}