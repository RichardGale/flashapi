#if !defined(FLEX11_6_FLASH_NET_DRM_DRMMODULECYCLEPROVIDER_AS)
#define FLEX11_6_FLASH_NET_DRM_DRMMODULECYCLEPROVIDER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace events
    {
        class TimerEvent;
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
using namespace flash::utils;

namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMModuleCycleProvider : public Object
            {
            public:
                DRMModuleCycleProvider();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_NET_DRM_DRMMODULECYCLEPROVIDER_AS
#endif // __cplusplus

