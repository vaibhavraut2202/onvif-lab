#include "soapMediaBindingProxy.h"
#include "MediaBinding.nsmap"

#include <iostream>

int main()
{
    MediaBindingProxy proxy;

    const char* endpoint =
        "http://192.168.137.186:8081";

    proxy.soap->userid = NULL;
    proxy.soap->passwd = NULL;

    _trt__GetProfile request;
    _trt__GetProfileResponse response;

    request.ProfileToken = "Profile_1";

    if (proxy.GetProfile(
            endpoint,
            NULL,
            &request,
            response) == SOAP_OK)
    {
        std::cout
            << "GetProfile successful!"
            << std::endl;

        if (response.Profile)
        {
            auto profile = response.Profile;

            std::cout << "\nProfile:" << std::endl;
            std::cout << "  Name: "
                      << profile->Name
                      << std::endl;

            std::cout << "  Token: "
                      << profile->token
                      << std::endl;


            // ------------------------------------------
            // Video Source Configuration
            // ------------------------------------------

            if (profile->VideoSourceConfiguration)
            {
                auto source =
                    profile->VideoSourceConfiguration;

                std::cout
                    << "\nVideo Source Configuration:"
                    << std::endl;

                std::cout << "  Name: "
                          << source->Name
                          << std::endl;

                std::cout << "  Token: "
                          << source->token
                          << std::endl;

                std::cout << "  SourceToken: "
                          << source->SourceToken
                          << std::endl;

                if (source->Bounds)
                {
                    std::cout << "  Resolution: "
                              << source->Bounds->width
                              << " x "
                              << source->Bounds->height
                              << std::endl;
                }
            }


            // ------------------------------------------
            // Video Encoder Configuration
            // ------------------------------------------

            if (profile->VideoEncoderConfiguration)
            {
                auto encoder =
                    profile->VideoEncoderConfiguration;

                std::cout
                    << "\nVideo Encoder Configuration:"
                    << std::endl;

                std::cout << "  Name: "
                          << encoder->Name
                          << std::endl;

                std::cout << "  Token: "
                          << encoder->token
                          << std::endl;

                std::cout << "  UseCount: "
                          << encoder->UseCount
                          << std::endl;

                std::cout << "  Encoding: ";

                if (encoder->Encoding ==
                    tt__VideoEncoding__H264)
                {
                    std::cout << "H264";
                }
                else if (encoder->Encoding ==
                         tt__VideoEncoding__JPEG)
                {
                    std::cout << "JPEG";
                }
                else if (encoder->Encoding ==
                         tt__VideoEncoding__MPEG4)
                {
                    std::cout << "MPEG4";
                }
                else
                {
                    std::cout << "Unknown";
                }

                std::cout << std::endl;

                if (encoder->Resolution)
                {
                    std::cout << "  Resolution: "
                              << encoder->Resolution->Width
                              << " x "
                              << encoder->Resolution->Height
                              << std::endl;
                }

                std::cout << "  Quality: "
                          << encoder->Quality
                          << std::endl;

                std::cout << "  SessionTimeout: "
                          << encoder->SessionTimeout
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