#include "soapSubscriptionManagerBindingService.h"
#include "SubscriptionManagerBinding.nsmap"

#include <iostream>
#include <ctime>
#include <string>

class MySubscriptionService : public SubscriptionManagerBindingService
{
private:

    bool subscriptionActive = true;

public:

    int Renew(
        _wsnt__Renew *request,
        _wsnt__RenewResponse &response
    ) override
    {
        std::cout << "Renew received!" << std::endl;

        if (!subscriptionActive)
        {
            std::cout << "Subscription is inactive."
                      << std::endl;

            return SOAP_FAULT;
        }

        if (request->TerminationTime)
        {
            std::cout << "Requested TerminationTime: "
                      << *request->TerminationTime
                      << std::endl;
        }
        else
        {
            std::cout << "No TerminationTime supplied"
                      << std::endl;
        }

        /*
         * Demo behavior:
         * renew the subscription for another 1 hour.
         */

        response.CurrentTime =
            new time_t(std::time(nullptr));

        response.TerminationTime =
            std::time(nullptr) + 3600;

        std::cout << "New TerminationTime: "
                  << response.TerminationTime
                  << std::endl;

        return SOAP_OK;
    }


    int Unsubscribe(
        _wsnt__Unsubscribe *request,
        _wsnt__UnsubscribeResponse &response
    ) override
    {
        (void)request;
        (void)response;

        std::cout << "Unsubscribe received!"
                  << std::endl;

        if (!subscriptionActive)
        {
            std::cout << "Subscription already inactive."
                      << std::endl;

            return SOAP_OK;
        }

        /*
         * Mark the subscription as inactive.
         */

        subscriptionActive = false;

        std::cout << "Subscription deactivated."
                  << std::endl;

        return SOAP_OK;
    }
};


int main()
{
    MySubscriptionService service;

    std::cout << "ONVIF Subscription Manager starting..."
              << std::endl;

    std::cout << "Listening on port 8084"
              << std::endl;

    if (service.run(8084) != SOAP_OK)
    {
        service.soap_stream_fault(std::cerr);
        return 1;
    }

    return 0;
}
