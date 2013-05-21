#if !defined(FLEX11_6_FLASH_EVENTS_NETFILTEREVENT_AS)
#define FLEX11_6_FLASH_EVENTS_NETFILTEREVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}
#include "flash/events/Event.h"

using namespace flash::events;
using namespace flash::utils;

namespace flash
{
    namespace events
    {
        class NetFilterEvent : public flash::events::Event
        {
        public:
            ByteArray *header;
        public:
            ByteArray *data;

        public:
            Event   *clone();

        public:
            NetFilterEvent(std::string type, bool bubbles   =false, bool cancelable   =false, ByteArray *header=NULL, ByteArray *data=NULL);

        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_NETFILTEREVENT_AS
#endif // __cplusplus

