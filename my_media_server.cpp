#include "soapMediaBindingService.h"
#include "MediaBinding.nsmap"

class MyMediaService : public MediaBindingService
{
public:
    int GetProfile(
        _trt__GetProfile *request,
        _trt__GetProfileResponse &response
    ) override;

    int GetProfiles(
        _trt__GetProfiles *request,
        _trt__GetProfilesResponse &response
    ) override;

    int GetStreamUri(
        _trt__GetStreamUri *request,
        _trt__GetStreamUriResponse &response
    ) override;

    int GetVideoEncoderConfiguration(
        _trt__GetVideoEncoderConfiguration *request,
        _trt__GetVideoEncoderConfigurationResponse &response
    ) override;

    int GetVideoSourceConfiguration(
        _trt__GetVideoSourceConfiguration *request,
        _trt__GetVideoSourceConfigurationResponse &response
    ) override;

    int GetVideoEncoderConfigurationOptions(
        _trt__GetVideoEncoderConfigurationOptions *request,
        _trt__GetVideoEncoderConfigurationOptionsResponse &response
    ) override;
};


int MyMediaService::GetProfile(
    _trt__GetProfile *request,
    _trt__GetProfileResponse &response)
{
    // --------------------------------------------------
    // Create Profile object
    // --------------------------------------------------

    tt__Profile *profile =
        soap_instantiate_tt__Profile(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!profile)
        return SOAP_EOM;

    profile->soap_default(this->soap);


    // --------------------------------------------------
    // Basic profile information
    // --------------------------------------------------

    profile->Name = "MainStream";
    profile->token = "Profile_1";


    // --------------------------------------------------
    // Video Source Configuration
    // --------------------------------------------------

    profile->VideoSourceConfiguration =
        soap_instantiate_tt__VideoSourceConfiguration(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!profile->VideoSourceConfiguration)
        return SOAP_EOM;

    profile->VideoSourceConfiguration->soap_default(this->soap);

    profile->VideoSourceConfiguration->Name =
        "MainVideoSource";

    profile->VideoSourceConfiguration->UseCount = 1;

    profile->VideoSourceConfiguration->token =
        "SourceConfig_1";

    profile->VideoSourceConfiguration->SourceToken =
        "VideoSource_1";


    // --------------------------------------------------
    // Video Source Bounds
    // --------------------------------------------------

    profile->VideoSourceConfiguration->Bounds =
        soap_instantiate_tt__IntRectangle(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!profile->VideoSourceConfiguration->Bounds)
        return SOAP_EOM;

    profile->VideoSourceConfiguration->Bounds->soap_default(
        this->soap);

    profile->VideoSourceConfiguration->Bounds->x = 0;
    profile->VideoSourceConfiguration->Bounds->y = 0;
    profile->VideoSourceConfiguration->Bounds->width = 1280;
    profile->VideoSourceConfiguration->Bounds->height = 720;


    // --------------------------------------------------
    // Video Encoder Configuration
    // --------------------------------------------------

    profile->VideoEncoderConfiguration =
        soap_instantiate_tt__VideoEncoderConfiguration(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!profile->VideoEncoderConfiguration)
        return SOAP_EOM;

    profile->VideoEncoderConfiguration->soap_default(
        this->soap);

    profile->VideoEncoderConfiguration->Name =
        "MainEncoder";

    profile->VideoEncoderConfiguration->UseCount = 1;

    profile->VideoEncoderConfiguration->token =
        "Encoder_1";

    profile->VideoEncoderConfiguration->Encoding =
        tt__VideoEncoding__H264;


    // --------------------------------------------------
    // Video Encoder Resolution
    // --------------------------------------------------

    profile->VideoEncoderConfiguration->Resolution =
        soap_instantiate_tt__VideoResolution(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!profile->VideoEncoderConfiguration->Resolution)
        return SOAP_EOM;

    profile->VideoEncoderConfiguration->Resolution->soap_default(
        this->soap);

    profile->VideoEncoderConfiguration->Resolution->Width = 1280;
    profile->VideoEncoderConfiguration->Resolution->Height = 720;


    // --------------------------------------------------
    // Video Encoder Quality
    // --------------------------------------------------

    profile->VideoEncoderConfiguration->Quality = 5.0;


    // --------------------------------------------------
    // Session timeout
    // --------------------------------------------------

    profile->VideoEncoderConfiguration->SessionTimeout =
        "PT60S";


    // --------------------------------------------------
    // Return Profile
    // --------------------------------------------------

    response.Profile = profile;

    return SOAP_OK;
}


int MyMediaService::GetProfiles(
    _trt__GetProfiles *request,
    _trt__GetProfilesResponse &response)
{
    tt__Profile *profile =
        soap_instantiate_tt__Profile(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!profile)
        return SOAP_EOM;

    profile->soap_default(this->soap);

    profile->Name = "MainStream";
    profile->token = "Profile_1";

    response.Profiles.push_back(profile);

    return SOAP_OK;
}


int MyMediaService::GetStreamUri(
    _trt__GetStreamUri *request,
    _trt__GetStreamUriResponse &response)
{
    tt__MediaUri *mediaUri =
        soap_instantiate_tt__MediaUri(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!mediaUri)
        return SOAP_EOM;

    mediaUri->soap_default(this->soap);

    mediaUri->Uri =
        "rtsp://192.168.137.186:8554/cam";

    mediaUri->InvalidAfterConnect = false;
    mediaUri->InvalidAfterReboot = false;
    mediaUri->Timeout = "PT0S";

    response.MediaUri = mediaUri;

    return SOAP_OK;
}


int MyMediaService::GetVideoEncoderConfiguration(
    _trt__GetVideoEncoderConfiguration *request,
    _trt__GetVideoEncoderConfigurationResponse &response)
{
    tt__VideoEncoderConfiguration *configuration =
        soap_instantiate_tt__VideoEncoderConfiguration(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!configuration)
        return SOAP_EOM;

    configuration->soap_default(this->soap);

    configuration->Name = "MainEncoder";
    configuration->UseCount = 1;
    configuration->token = "Encoder_1";

    configuration->Encoding =
        tt__VideoEncoding__H264;

    configuration->Resolution =
        soap_instantiate_tt__VideoResolution(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!configuration->Resolution)
        return SOAP_EOM;

    configuration->Resolution->soap_default(this->soap);

    configuration->Resolution->Width = 1280;
    configuration->Resolution->Height = 720;

    configuration->Quality = 5.0;

    configuration->SessionTimeout = "PT60S";

    response.Configuration = configuration;

    return SOAP_OK;
}


int MyMediaService::GetVideoSourceConfiguration(
    _trt__GetVideoSourceConfiguration *request,
    _trt__GetVideoSourceConfigurationResponse &response)
{
    tt__VideoSourceConfiguration *configuration =
        soap_instantiate_tt__VideoSourceConfiguration(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!configuration)
        return SOAP_EOM;

    configuration->soap_default(this->soap);

    configuration->Name = "MainVideoSource";
    configuration->UseCount = 1;
    configuration->token = "SourceConfig_1";

    configuration->SourceToken = "VideoSource_1";

    configuration->Bounds =
        soap_instantiate_tt__IntRectangle(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!configuration->Bounds)
        return SOAP_EOM;

    configuration->Bounds->soap_default(this->soap);

    configuration->Bounds->x = 0;
    configuration->Bounds->y = 0;
    configuration->Bounds->width = 1280;
    configuration->Bounds->height = 720;

    response.Configuration = configuration;

    return SOAP_OK;
}


int MyMediaService::GetVideoEncoderConfigurationOptions(
    _trt__GetVideoEncoderConfigurationOptions *request,
    _trt__GetVideoEncoderConfigurationOptionsResponse &response)
{
    tt__VideoEncoderConfigurationOptions *options =
        soap_instantiate_tt__VideoEncoderConfigurationOptions(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!options)
        return SOAP_EOM;

    options->soap_default(this->soap);


    // --------------------------------------------------
    // Quality range
    // --------------------------------------------------

    options->QualityRange =
        soap_instantiate_tt__IntRange(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!options->QualityRange)
        return SOAP_EOM;

    options->QualityRange->soap_default(this->soap);

    options->QualityRange->Min = 1;
    options->QualityRange->Max = 10;


    // --------------------------------------------------
    // H.264 options
    // --------------------------------------------------

    options->H264 =
        soap_instantiate_tt__H264Options(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!options->H264)
        return SOAP_EOM;

    options->H264->soap_default(this->soap);


    // --------------------------------------------------
    // Supported resolution
    // --------------------------------------------------

    tt__VideoResolution *resolution =
        soap_instantiate_tt__VideoResolution(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!resolution)
        return SOAP_EOM;

    resolution->soap_default(this->soap);

    resolution->Width = 1280;
    resolution->Height = 720;

    options->H264->ResolutionsAvailable.push_back(
        resolution);


    // --------------------------------------------------
    // GOP / GOV length
    // --------------------------------------------------

    options->H264->GovLengthRange =
        soap_instantiate_tt__IntRange(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!options->H264->GovLengthRange)
        return SOAP_EOM;

    options->H264->GovLengthRange->soap_default(this->soap);

    options->H264->GovLengthRange->Min = 1;
    options->H264->GovLengthRange->Max = 60;


    // --------------------------------------------------
    // Frame rate
    // --------------------------------------------------

    options->H264->FrameRateRange =
        soap_instantiate_tt__IntRange(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!options->H264->FrameRateRange)
        return SOAP_EOM;

    options->H264->FrameRateRange->soap_default(this->soap);

    options->H264->FrameRateRange->Min = 1;
    options->H264->FrameRateRange->Max = 30;


    // --------------------------------------------------
    // Encoding interval
    // --------------------------------------------------

    options->H264->EncodingIntervalRange =
        soap_instantiate_tt__IntRange(
            this->soap,
            -1,
            NULL,
            NULL,
            NULL);

    if (!options->H264->EncodingIntervalRange)
        return SOAP_EOM;

    options->H264->EncodingIntervalRange->soap_default(
        this->soap);

    options->H264->EncodingIntervalRange->Min = 1;
    options->H264->EncodingIntervalRange->Max = 1;


    // --------------------------------------------------
    // H.264 profiles
    // --------------------------------------------------

    options->H264->H264ProfilesSupported.push_back(
        tt__H264Profile__Baseline);

    options->H264->H264ProfilesSupported.push_back(
        tt__H264Profile__Main);

    options->H264->H264ProfilesSupported.push_back(
        tt__H264Profile__High);


    // --------------------------------------------------
    // Return response
    // --------------------------------------------------

    response.Options = options;

    return SOAP_OK;
}


int main()
{
    MyMediaService service;

    return service.run(8081);
}
