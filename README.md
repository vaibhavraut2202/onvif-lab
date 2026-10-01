\# ONVIF Lab



A hands-on ONVIF and gSOAP learning project using a Raspberry Pi as the ONVIF device/server and Windows C++ as the client.



\## Project



\- Raspberry Pi 4 ONVIF server

\- Windows C++ ONVIF clients

\- gSOAP-generated SOAP/WSDL code

\- ONVIF Device services

\- ONVIF Media services

\- ONVIF Events

\- PullPoint event notifications

\- RTSP test streaming with MediaMTX



\## APIs Implemented



\### Device

\- GetDeviceInformation

\- GetSystemDateAndTime

\- GetCapabilities

\- GetServices



\### Media

\- GetProfiles

\- GetProfile

\- GetStreamUri

\- GetVideoEncoderConfiguration

\- GetVideoSourceConfiguration

\- GetVideoEncoderConfigurationOptions



\### Events

\- GetEventProperties

\- CreatePullPointSubscription

\- PullMessages



\## Architecture



Windows C++ ONVIF Client  

↓ SOAP/XML  

Raspberry Pi ONVIF Server  

↓  

Media / RTSP



\## Tools



\- C++

\- gSOAP

\- ONVIF specifications

\- Raspberry Pi

\- Windows + MinGW

\- MediaMTX

\- FFmpeg

\- Git / GitHub

