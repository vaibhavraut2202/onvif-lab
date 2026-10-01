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

    _tds__GetSystemDateAndTime request;
    _tds__GetSystemDateAndTimeResponse response;

    if (proxy.GetSystemDateAndTime(
            endpoint,
            NULL,
            &request,
            &response) == SOAP_OK)
    {
        if (response.SystemDateAndTime)
        {
            std::cout << "DateTime Type: "
                      << response.SystemDateAndTime->DateTimeType
                      << std::endl;

            std::cout << "Daylight Savings: "
                      << response.SystemDateAndTime->DaylightSavings
                      << std::endl;

            if (response.SystemDateAndTime->TimeZone)
            {
                std::cout << "Time Zone: "
                          << response.SystemDateAndTime->TimeZone->TZ
                          << std::endl;
            }

            if (response.SystemDateAndTime->UTCDateTime)
            {
                auto* utc =
                    response.SystemDateAndTime->UTCDateTime;

                std::cout << "UTC: "
                          << utc->Date->Year << "-"
                          << utc->Date->Month << "-"
                          << utc->Date->Day << " "
                          << utc->Time->Hour << ":"
                          << utc->Time->Minute << ":"
                          << utc->Time->Second
                          << std::endl;
            }

            if (response.SystemDateAndTime->LocalDateTime)
            {
                auto* local =
                    response.SystemDateAndTime->LocalDateTime;

                std::cout << "Local: "
                          << local->Date->Year << "-"
                          << local->Date->Month << "-"
                          << local->Date->Day << " "
                          << local->Time->Hour << ":"
                          << local->Time->Minute << ":"
                          << local->Time->Second
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