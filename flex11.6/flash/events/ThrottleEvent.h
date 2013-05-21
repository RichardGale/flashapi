#if !defined(FLEX11_6_FLASH_EVENTS_THROTTLEEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_THROTTLEEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/Event.h"

using namespace flash::events;

namespace flash
{
    namespace events
    {
        class ThrottleEvent : public flash::events::Event
        {
        public:
            static const std::string THROTTLE;

        public:
            float        targetFrameRate();

        public:
            std::string  state();

        public:
            Event   *clone();

        public:
            ThrottleEvent(std::string type, bool bubbles   =false, bool cancelable   =false, std::string state="", float targetFrameRate =0);

        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_THROTTLEEVENT_AS
#endif // __cplusplus

