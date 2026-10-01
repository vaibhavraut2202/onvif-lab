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

    _tds__GetServices request;
    _tds__GetServicesResponse response;

    request.IncludeCapability = false;

    if (proxy.GetServices(
            endpoint,
            NULL,
            &request,
            &response) == SOAP_OK)
    {
        std::cout << "GetServices successful!" << std::endl;

        for (auto service : response.Service)
        {
            std::cout << "\nService:" << std::endl;
            std::cout << "  Namespace: "
                      << service->Namespace << std::endl;

            std::cout << "  XAddr: "
                      << service->XAddr << std::endl;

            if (service->Version)
            {
                std::cout << "  Version: "
                          << service->Version->Major
                          << "."
                          << service->Version->Minor
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