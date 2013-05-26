#if !defined(FLEX11_6_FLASH_UI_GAMEINPUTDEVICE_AS)
#define FLEX11_6_FLASH_UI_GAMEINPUTDEVICE_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace ui
    {
        class GameInputControl;
    }
}
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

using namespace flash::events;
using namespace flash::ui;
using namespace flash::utils;

namespace flash
{
    namespace ui
    {
        class GameInputDevice : public flash::events::EventDispatcher
        {
        public:
            static const int MAX_BUFFER_SIZE;

        public:
            int          numControls();

        public:
            int          sampleInterval();
        public:
            void         sampleInterval(int val);

        public:
            bool      enabled();
        public:
            void         enabled(bool val);

        public:
            std::string       id();

        public:
            std::string       name();

        public:
            GameInputDevice();

        public:
            GameInputControl *getControlAt(int i);

        public:
            void     startCachingSamples(int numSamples, std::vector<int> controls);

        public:
            void     stopCachingSamples();

        public:
            int      getCachedSamples(ByteArray *data, bool append=false);
        };
    }
}

#endif // FLEX11_6_FLASH_UI_GAMEINPUTDEVICE_AS
#endif // __cplusplus

