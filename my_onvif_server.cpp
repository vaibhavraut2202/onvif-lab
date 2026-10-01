#include "soapDeviceBindingService.h"
#include "DeviceBinding.nsmap"
#include <ctime>

class MyDeviceService : public DeviceBindingService
{
public:
    int GetDeviceInformation(
        _tds__GetDeviceInformation *request,
        _tds__GetDeviceInformationResponse &response
    ) override;

    int GetSystemDateAndTime(
        _tds__GetSystemDateAndTime *request,
        _tds__GetSystemDateAndTimeResponse &response
    ) override;

    int GetCapabilities(
        _tds__GetCapabilities *request,
        _tds__GetCapabilitiesResponse &response
    ) override;

    int GetServices(
        _tds__GetServices *request,
        _tds__GetServicesResponse &response
    ) override;
};


int MyDeviceService::GetDeviceInformation(
    _tds__GetDeviceInformation *request,
    _tds__GetDeviceInformationResponse &response)
{
    response.Manufacturer = "Vaibhav ONVIF Lab";
    response.Model = "RaspberryPi-ONVIF";
    response.FirmwareVersion = "1.0";
    response.SerialNumber = "PI4-001";
    response.HardwareId = "RPI4";

    return SOAP_OK;
}


int MyDeviceService::GetSystemDateAndTime(
    _tds__GetSystemDateAndTime *request,
    _tds__GetSystemDateAndTimeResponse &response)
{
    time_t now = time(nullptr);

    struct tm localTime = *localtime(&now);
    struct tm utcTime = *gmtime(&now);


    /*
     * Create main SystemDateTime object.
     */
    response.SystemDateAndTime =
        soap_instantiate_tt__SystemDateTime(
            this->soap, -1, NULL, NULL, NULL);

    if (!response.SystemDateAndTime)
        return SOAP_EOM;

    response.SystemDateAndTime->soap_default(this->soap);

    response.SystemDateAndTime->DateTimeType =
        tt__SetDateTimeType__Manual;

    response.SystemDateAndTime->DaylightSavings = false;


    /*
     * Time zone.
     */
    response.SystemDateAndTime->TimeZone =
        soap_instantiate_tt__TimeZone(
            this->soap, -1, NULL, NULL, NULL);

    if (!response.SystemDateAndTime->TimeZone)
        return SOAP_EOM;

    response.SystemDateAndTime->TimeZone->soap_default(this->soap);

    response.SystemDateAndTime->TimeZone->TZ = "GMT+05:30";


    /*
     * =========================
     * UTC DATE AND TIME
     * =========================
     */

    response.SystemDateAndTime->UTCDateTime =
        soap_instantiate_tt__DateTime(
            this->soap, -1, NULL, NULL, NULL);

    if (!response.SystemDateAndTime->UTCDateTime)
        return SOAP_EOM;

    response.SystemDateAndTime->UTCDateTime->soap_default(this->soap);


    response.SystemDateAndTime->UTCDateTime->Date =
        soap_instantiate_tt__Date(
            this->soap, -1, NULL, NULL, NULL);

    if (!response.SystemDateAndTime->UTCDateTime->Date)
        return SOAP_EOM;

    response.SystemDateAndTime->UTCDateTime->Date->soap_default(this->soap);


    response.SystemDateAndTime->UTCDateTime->Time =
        soap_instantiate_tt__Time(
            this->soap, -1, NULL, NULL, NULL);

    if (!response.SystemDateAndTime->UTCDateTime->Time)
        return SOAP_EOM;

    response.SystemDateAndTime->UTCDateTime->Time->soap_default(this->soap);


    response.SystemDateAndTime->UTCDateTime->Date->Year =
        utcTime.tm_year + 1900;

    response.SystemDateAndTime->UTCDateTime->Date->Month =
        utcTime.tm_mon + 1;

    response.SystemDateAndTime->UTCDateTime->Date->Day =
        utcTime.tm_mday;


    response.SystemDateAndTime->UTCDateTime->Time->Hour =
        utcTime.tm_hour;

    response.SystemDateAndTime->UTCDateTime->Time->Minute =
        utcTime.tm_min;

    response.SystemDateAndTime->UTCDateTime->Time->Second =
        utcTime.tm_sec;


    /*
     * =========================
     * LOCAL DATE AND TIME
     * =========================
     */

    response.SystemDateAndTime->LocalDateTime =
        soap_instantiate_tt__DateTime(
            this->soap, -1, NULL, NULL, NULL);

    if (!response.SystemDateAndTime->LocalDateTime)
        return SOAP_EOM;

    response.SystemDateAndTime->LocalDateTime->soap_default(this->soap);


    response.SystemDateAndTime->LocalDateTime->Date =
        soap_instantiate_tt__Date(
            this->soap, -1, NULL, NULL, NULL);

    if (!response.SystemDateAndTime->LocalDateTime->Date)
        return SOAP_EOM;

    response.SystemDateAndTime->LocalDateTime->Date->soap_default(this->soap);


    response.SystemDateAndTime->LocalDateTime->Time =
        soap_instantiate_tt__Time(
            this->soap, -1, NULL, NULL, NULL);

    if (!response.SystemDateAndTime->LocalDateTime->Time)
        return SOAP_EOM;

    response.SystemDateAndTime->LocalDateTime->Time->soap_default(this->soap);


    response.SystemDateAndTime->LocalDateTime->Date->Year =
        localTime.tm_year + 1900;

    response.SystemDateAndTime->LocalDateTime->Date->Month =
        localTime.tm_mon + 1;

    response.SystemDateAndTime->LocalDateTime->Date->Day =
        localTime.tm_mday;


    response.SystemDateAndTime->LocalDateTime->Time->Hour =
        localTime.tm_hour;

    response.SystemDateAndTime->LocalDateTime->Time->Minute =
        localTime.tm_min;

    response.SystemDateAndTime->LocalDateTime->Time->Second =
        localTime.tm_sec;


    return SOAP_OK;
}


int MyDeviceService::GetCapabilities(
    _tds__GetCapabilities *request,
    _tds__GetCapabilitiesResponse &response)
{
    /*
     * Create main Capabilities object.
     */
    response.Capabilities =
        soap_instantiate_tt__Capabilities(
            this->soap, -1, NULL, NULL, NULL);

    if (!response.Capabilities)
        return SOAP_EOM;

    response.Capabilities->soap_default(this->soap);


    /*
     * Create Device capabilities.
     */
    response.Capabilities->Device =
        soap_instantiate_tt__DeviceCapabilities(
            this->soap, -1, NULL, NULL, NULL);

    if (!response.Capabilities->Device)
        return SOAP_EOM;

    response.Capabilities->Device->soap_default(this->soap);


    /*
     * ONVIF Device service endpoint.
     */
    response.Capabilities->Device->XAddr =
        "http://192.168.137.186:8080";


    return SOAP_OK;
}


int MyDeviceService::GetServices(
    _tds__GetServices *request,
    _tds__GetServicesResponse &response)
{
    /*
     * Create one ONVIF Device service entry.
     */
    tds__Service *deviceService =
        soap_instantiate_tds__Service(
            this->soap, -1, NULL, NULL, NULL);

    if (!deviceService)
        return SOAP_EOM;

    deviceService->soap_default(this->soap);


    /*
     * Service namespace.
     */
    deviceService->Namespace =
        "http://www.onvif.org/ver10/device/wsdl";


    /*
     * Device service endpoint.
     */
    deviceService->XAddr =
        "http://192.168.137.186:8080";


    /*
     * ONVIF version.
     */
    deviceService->Version =
        soap_instantiate_tt__OnvifVersion(
            this->soap, -1, NULL, NULL, NULL);

    if (!deviceService->Version)
        return SOAP_EOM;

    deviceService->Version->soap_default(this->soap);

    deviceService->Version->Major = 2;
    deviceService->Version->Minor = 0;


    /*
     * Add service to response vector.
     */
    response.Service.push_back(deviceService);


    return SOAP_OK;
}


int main()
{
    MyDeviceService service;

    return service.run(8080);
}
