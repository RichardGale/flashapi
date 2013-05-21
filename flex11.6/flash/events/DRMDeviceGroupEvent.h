#if !defined(FLEX11_6_FLASH_EVENTS_DRMDEVICEGROUPEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_DRMDEVICEGROUPEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMDeviceGroup;
        }
    }
}
#include "flash/events/Event.h"

using namespace flash::events;
using namespace flash::net::drm;

namespace flash
{
    namespace events
    {
        class DRMDeviceGroupEvent : public flash::events::Event
        {
        public:
            static const std::string ADD_TO_DEVICE_GROUP_COMPLETE;
        public:
            static const std::string REMOVE_FROM_DEVICE_GROUP_COMPLETE;

        public:
            void         deviceGroup(DRMDeviceGroup *value);
        public:
            DRMDeviceGroup *deviceGroup();

        public:
            DRMDeviceGroupEvent(std::string type, bool bubbles   =false, bool cancelable   =false, DRMDeviceGroup *deviceGroup=NULL);

        public:
            Event   *clone();

        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_DRMDEVICEGROUPEVENT_AS
#endif // __cplusplus

