#include "soapDeviceBindingProxy.h"
#include "DeviceBinding.nsmap"
#include <iostream>

int main() {
    DeviceBindingProxy proxy;

    // Use your Pi’s IP here
    const char* endpoint = "http://192.168.137.186:8080";

    // No userid/password needed
    proxy.soap->userid = NULL;
    proxy.soap->passwd = NULL;

    _tds__GetDeviceInformation request;
    _tds__GetDeviceInformationResponse response;

    if (proxy.GetDeviceInformation(endpoint, NULL, &request, &response) == SOAP_OK) {
        std::cout << "Manufacturer: " << response.Manufacturer << std::endl;
        std::cout << "Model: " << response.Model << std::endl;
        std::cout << "Firmware: " << response.FirmwareVersion << std::endl;
        std::cout << "Serial: " << response.SerialNumber << std::endl;
        std::cout << "Hardware: " << response.HardwareId << std::endl;
    } else {
        proxy.soap_stream_fault(std::cerr);
    }

    return 0;
}
