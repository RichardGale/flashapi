#if !defined(FLEX11_6_FLASH_EVENTS_DRMDEVICEGROUPERROREVENT_AS)
#define FLEX11_6_FLASH_EVENTS_DRMDEVICEGROUPERROREVENT_AS
#if defined(__cplusplus)


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
namespace flash
{
    namespace events
    {
        class Event;
    }
}

using namespace flash::net::drm;
using namespace flash::events;

namespace flash
{
    namespace events
    {
        class DRMDeviceGroupErrorEvent: public ErrorEvent
        {
        public:
            static const std::string ADD_TO_DEVICE_GROUP_ERROR;
        public:
            static const std::string REMOVE_FROM_DEVICE_GROUP_ERROR;

        public:
            int          subErrorID();
        public:
            void         subErrorID(int value);

        public:
            void         deviceGroup(DRMDeviceGroup *value);
        public:
            DRMDeviceGroup *deviceGroup();

        public:
            bool         systemUpdateNeeded();

        public:
            bool         drmUpdateNeeded();

        public:
            DRMDeviceGroupErrorEvent(std::string type, bool bubbles, bool cancelable, std::string errorDetail, int errorCode, int subErrorID, DRMDeviceGroup *deviceGroup, bool systemUpdateNeeded, bool drmUpdateNeeded);

        public:
            std::string toString();

        public:
            Event   *clone();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_DRMDEVICEGROUPERROREVENT_AS
#endif // __cplusplus

