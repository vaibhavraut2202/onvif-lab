#include "soapEventBindingService.h"
#include "EventBinding.nsmap"

#include <iostream>
#include <ctime>

class MyEventsService : public EventBindingService
{
public:

    int GetEventProperties(
        _tev__GetEventProperties *request,
        _tev__GetEventPropertiesResponse &response) override
    {
        (void)request;

        response.TopicNamespaceLocation.push_back(
            "http://www.onvif.org/ver10/topics/topicns.xml"
        );

        response.wsnt__FixedTopicSet = true;

        response.wstop__TopicSet = nullptr;

        response.wsnt__TopicExpressionDialect.push_back(
            "http://docs.oasis-open.org/wsn/t-1/TopicExpression/Simple"
        );

        response.MessageContentFilterDialect.push_back(
            "http://www.onvif.org/ver10/tev/messageContentFilter/ItemFilter"
        );

        return SOAP_OK;
    }


    int CreatePullPointSubscription(
        _tev__CreatePullPointSubscription *request,
        _tev__CreatePullPointSubscriptionResponse &response) override
    {
        (void)request;

        /*
         * For now we create a simple, fixed subscription reference.
         * Later this will represent an actual subscription object.
         */

        response.SubscriptionReference.Address =
            "http://192.168.137.186:8082/onvif/events/pullpoint";

        response.wsnt__CurrentTime = std::time(nullptr);

        response.wsnt__TerminationTime =
            std::time(nullptr) + 3600;

        return SOAP_OK;
    }
};


int main()
{
    MyEventsService service;

    std::cout << "ONVIF Events server starting..." << std::endl;
    std::cout << "Listening on port 8082" << std::endl;

    if (service.run(8082) != SOAP_OK)
    {
        service.soap_stream_fault(std::cerr);
        return 1;
    }

    return 0;
}
