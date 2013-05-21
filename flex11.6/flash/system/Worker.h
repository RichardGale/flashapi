#if !defined(FLEX11_6_FLASH_SYSTEM_WORKER_AS)
#define FLEX11_6_FLASH_SYSTEM_WORKER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"

namespace flash
{
    namespace system
    {
        class MessageChannel;
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
using namespace flash::system;
using namespace flash::utils;

namespace flash
{
    namespace system
    {
        class Worker : public flash::events::EventDispatcher
        {
        public:
            static bool         isSupported();

        public:
            static Worker      *current();

        public:
            bool         isPrimordial();

        public:
            std::string  state();

        public:
            MessageChannel *createMessageChannel(Worker *receiver);

        public:
            void     start();

        public:
            void     setSharedProperty(std::string key, void *value);

        public:
            void    *getSharedProperty(std::string key);

        public:
            void     addEventListener(std::string type, Function *listener, bool useCapture   =false, int priority=0, bool useWeakReference   =false);

        public:
            void     removeEventListener(std::string type, Function *listener, bool useCapture   =false);

        public:
            bool     terminate();

        public:
            Worker();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_WORKER_AS
#endif // __cplusplus

