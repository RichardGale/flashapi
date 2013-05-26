#if !defined(FLEX11_6_FLASH_NET_DRM_DRMMANAGERSESSION_AS)
#define FLEX11_6_FLASH_NET_DRM_DRMMANAGERSESSION_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMContentData;
        }
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
    namespace utils
    {
        class Timer;
    }
}
namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMVoucher;
        }
    }
}

using namespace flash::events;
using namespace flash::net::drm;
using namespace flash::utils;

namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMManagerSession : public flash::events::EventDispatcher
            {
                static const unsigned int STATUS_READY;
                static const unsigned int STATUS_NOTREADY;
                static const unsigned int STATUS_FAILED;
                static const unsigned int STATUS_UNKNOWN;
            public:
                bool m_isInSession;

            public:
                DRMContentData *metadata();
            public:
                void         metadata(DRMContentData *inData);

            public:
                DRMManagerSession();

            public:
                void     onSessionError();

            public:
                void     onSessionComplete();

            public:
                void     setTimerUp();

            public:
                unsigned int     checkStatus();

            public:
                unsigned int     getLastError();

            public:
                unsigned int     getLastSubErrorID();

            public:
                void        *issueDRMStatusEvent(DRMContentData *inMetadata, DRMVoucher *voucher);

            public:
                void     issueDRMErrorEvent(DRMContentData *metadata, int errorID, int subErrorID, std::string eventType="");

            public:
                void     errorCodeToThrow(unsigned int errorCode);
            };
        }
    }
}

#endif // FLEX11_6_FLASH_NET_DRM_DRMMANAGERSESSION_AS
#endif // __cplusplus

