#if !defined(FLEX11_6_FLASH_NET_DRM_DRMURLDOWNLOADCONTEXT_AS)
#define FLEX11_6_FLASH_NET_DRM_DRMURLDOWNLOADCONTEXT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}
namespace flash
{
    namespace net
    {
        class URLRequest;
    }
}
namespace flash
{
    namespace events
    {
        class TimerEvent;
    }
}
namespace flash
{
    namespace events
    {
        class Event;
    }
}
namespace flash
{
    namespace net
    {
        class URLLoader;
    }
}
namespace flash
{
    namespace utils
    {
        class Timer;
    }
}

using namespace flash::events;
using namespace flash::net;
using namespace flash::utils;

namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMURLDownloadContext : public flash::events::EventDispatcher
            {
            public:
                DRMURLDownloadContext();

            public:
                void     httpPostAndReceiveASync(std::string url, std::string headerName, std::string headerValue, ByteArray *data);

            public:
                void     httpGetASync(std::string url);
            };
        }
    }
}

#endif // FLEX11_6_FLASH_NET_DRM_DRMURLDOWNLOADCONTEXT_AS
#endif // __cplusplus

