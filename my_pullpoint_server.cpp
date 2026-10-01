#include "soapPullPointSubscriptionBindingService.h"
#include "PullPointSubscriptionBinding.nsmap"

#include <iostream>
#include <ctime>

class MyPullPointService : public PullPointSubscriptionBindingService
{
public:

    int PullMessages(
        _tev__PullMessages *request,
        _tev__PullMessagesResponse &response
    ) override
    {
        std::cout << "PullMessages received!" << std::endl;

        std::cout << "Timeout: "
                  << request->Timeout
                  << std::endl;

        std::cout << "MessageLimit: "
                  << request->MessageLimit
                  << std::endl;

        response.CurrentTime = std::time(nullptr);

        response.TerminationTime =
            std::time(nullptr) + 3600;

        if (request->MessageLimit > 0)
        {
            wsnt__NotificationMessageHolderType *notification =
                soap_new_wsnt__NotificationMessageHolderType(this->soap);

            notification->Topic =
                soap_new_wsnt__TopicExpressionType(this->soap);

            notification->Topic->Dialect =
                (char*)"http://docs.oasis-open.org/wsn/t-1/TopicExpression/Simple";

            notification->Topic->__any =
                (char*)"tns1:MotionDetector/Motion";

            notification->Message.__any =
                (char*)"<tt:Message xmlns:tt=\"http://www.onvif.org/ver10/schema\">"
                       "<tt:Data>"
                       "<tt:SimpleItem Name=\"IsMotion\" Value=\"true\"/>"
                       "</tt:Data>"
                       "</tt:Message>";

            response.wsnt__NotificationMessage.push_back(
                notification
            );
        }

        return SOAP_OK;
    }
};

int main()
{
    MyPullPointService service;

    std::cout << "ONVIF PullPoint server starting..." << std::endl;
    std::cout << "Listening on port 8083" << std::endl;

    if (service.run(8083) != SOAP_OK)
    {
        service.soap_stream_fault(std::cerr);
        return 1;
    }

    return 0;
}
