#if !defined(FLEX11_6_FLASH_EVENTS_NETFILTEREVENT_AS)
#define FLEX11_6_FLASH_EVENTS_NETFILTEREVENT_AS
#if defined(__cplusplus)


namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}
#include "flash/events/Event.h"

using namespace flash::utils;
using namespace flash::events;

namespace flash
{
    namespace events
    {
        class NetFilterEvent: public Event
        {
        public:
            ByteArray *header;
        public:
            ByteArray *data;

        public:
            Event   *clone();

        public:
            NetFilterEvent(std::string type, bool bubbles, bool cancelable, ByteArray *header, ByteArray *data);

        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_NETFILTEREVENT_AS
#endif // __cplusplus

