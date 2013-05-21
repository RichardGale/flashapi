#if !defined(FLEX11_6_FLASH_UI_GAMEINPUTCONTROL_AS)
#define FLEX11_6_FLASH_UI_GAMEINPUTCONTROL_AS
#if defined(__cplusplus)


#include "flex11.6.h"
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
        class GameInputControl : public flash::events::EventDispatcher
        {
        public:
            int          numValues();

        public:
            int          index();

        public:
            bool         relative();

        public:
            std::string  type();

        public:
            std::string  hand();

        public:
            std::string  finger();

        public:
            GameInputDevice *device();

        public:
            GameInputControl();

        public:
            float    getValueAt(int index=0);
        };
    }
}

#endif // FLEX11_6_FLASH_UI_GAMEINPUTCONTROL_AS
#endif // __cplusplus

