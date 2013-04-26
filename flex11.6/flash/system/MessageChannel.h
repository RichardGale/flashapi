#if !defined(FLEX11_6_FLASH_SYSTEM_MESSAGECHANNEL_AS)
#define FLEX11_6_FLASH_SYSTEM_MESSAGECHANNEL_AS
#if defined(__cplusplus)


#include "flash/events/EventDispatcher.h"

using namespace flash::events;

namespace flash
{
    namespace system
    {
        class MessageChannel: public EventDispatcher
        {
        public:
            bool         messageAvailable();

        public:
            std::string  state();

        public:
            MessageChannel();

        public:
            void     send(void *arg, int queueLimit);

        public:
            void    *receive(bool blockUntilReceived);

        public:
            void     addEventListener(std::string type, Function *listener, bool useCapture, int priority, bool useWeakReference);

        public:
            void     removeEventListener(std::string type, Function *listener, bool useCapture);

        public:
            void     close();

        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_MESSAGECHANNEL_AS
#endif // __cplusplus

