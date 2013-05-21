#if !defined(FLEX11_6_FLASH_SYSTEM_MESSAGECHANNEL_AS)
#define FLEX11_6_FLASH_SYSTEM_MESSAGECHANNEL_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"

using namespace flash::events;

namespace flash
{
    namespace system
    {
        class MessageChannel : public flash::events::EventDispatcher
        {
        public:
            bool         messageAvailable();

        public:
            std::string  state();

        public:
            MessageChannel();

        public:
            void     send(void *arg, int queueLimit=-1);

        public:
            void    *receive(bool blockUntilReceived   =false);

        public:
            void     addEventListener(std::string type, Function *listener, bool useCapture   =false, int priority=0, bool useWeakReference   =false);

        public:
            void     removeEventListener(std::string type, Function *listener, bool useCapture   =false);

        public:
            void     close();

        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_MESSAGECHANNEL_AS
#endif // __cplusplus

