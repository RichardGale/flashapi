#if !defined(FLEX11_6_FLASH_AUTOMATION_STAGECAPTUREEVENT_AS)
#define FLEX11_6_FLASH_AUTOMATION_STAGECAPTUREEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/Event.h"

using namespace flash::events;

namespace flash
{
    namespace automation
    {
        class StageCaptureEvent : public flash::events::Event
        {
        public:
            static const std::string CAPTURE;

        public:
            std::string       url();

        public:
            unsigned int         checksum();

        public:
            Event    *clone();

        public:
            StageCaptureEvent(std::string type, bool bubbles=false, bool cancelable=false, std::string url="", unsigned int checksum=0);

        public:
            std::string   toString();
        };
    }
}

#endif // FLEX11_6_FLASH_AUTOMATION_STAGECAPTUREEVENT_AS
#endif // __cplusplus

