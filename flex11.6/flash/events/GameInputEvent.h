#if !defined(FLEX11_6_FLASH_EVENTS_GAMEINPUTEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_GAMEINPUTEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace ui
    {
        class GameInputDevice;
    }
}

using namespace flash::ui;

namespace flash
{
    namespace events
    {
        class GameInputEvent : public Event
        {
        public:
            static const std::string DEVICE_ADDED;
        public:
            static const std::string DEVICE_REMOVED;

        public:
            GameInputDevice *device();

        public:
            GameInputEvent(std::string type, bool bubbles=false, bool cancelable=false, GameInputDevice *device=NULL);
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_GAMEINPUTEVENT_AS
#endif // __cplusplus

