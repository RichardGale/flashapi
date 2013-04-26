#if !defined(FLEX11_6_FLASH_UI_GAMEINPUT_AS)
#define FLEX11_6_FLASH_UI_GAMEINPUT_AS
#if defined(__cplusplus)


#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace ui
    {
        class GameInputDevice;
    }
}

using namespace flash::events;
using namespace flash::ui;

namespace flash
{
    namespace ui
    {
        class GameInput: public EventDispatcher
        {
        public:
            static int          numDevices();

        public:
            static bool         isSupported();

        public:
            GameInput();

        public:
            static GameInputDevice *getDeviceAt(int index);
        };
    }
}

#endif // FLEX11_6_FLASH_UI_GAMEINPUT_AS
#endif // __cplusplus

