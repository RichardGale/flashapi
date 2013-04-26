#if !defined(FLEX11_6_FLASH_EVENTS_THROTTLEEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_THROTTLEEVENT_AS
#if defined(__cplusplus)


#include "flash/events/Event.h"

using namespace flash::events;

namespace flash
{
    namespace events
    {
        class ThrottleEvent: public Event
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
            ThrottleEvent(std::string type, bool bubbles, bool cancelable, std::string state, float targetFrameRate);

        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_THROTTLEEVENT_AS
#endif // __cplusplus

