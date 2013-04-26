#if !defined(FLEX11_6_FLASH_NET_DRM_DRMAUTHENTICATIONCONTEXT_AS)
#define FLEX11_6_FLASH_NET_DRM_DRMAUTHENTICATIONCONTEXT_AS
#if defined(__cplusplus)


namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

using namespace flash::utils;

namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMAuthenticationContext: public DRMManagerSession
            {
            public:
                ByteArray   *authenticationToken();

            public:
                void     authenticate(std::string url, std::string domain, std::string username, std::string password);

            public:
                DRMAuthenticationContext();

            public:
                void     onSessionComplete();

            public:
                void     onSessionError();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_NET_DRM_DRMAUTHENTICATIONCONTEXT_AS
#endif // __cplusplus

