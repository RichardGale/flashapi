#if !defined(FLEX11_6_FLASH_AUTOMATION_STAGECAPTUREEVENT_AS)
#define FLEX11_6_FLASH_AUTOMATION_STAGECAPTUREEVENT_AS
#if defined(__cplusplus)


#include "flash/events/Event.h"

using namespace flash::events;

namespace flash
{
    namespace automation
    {
        class StageCaptureEvent: public Event
        {
        public:
            static const std::string CAPTURE;

        public:
            std::string  url();

        public:
            unsigned int checksum();

        public:
            Event   *clone();

        public:
            StageCaptureEvent(std::string type, bool bubbles, bool cancelable, std::string url, unsigned int checksum);

        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_AUTOMATION_STAGECAPTUREEVENT_AS
#endif // __cplusplus

