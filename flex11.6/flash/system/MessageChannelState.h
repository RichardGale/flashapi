#if !defined(FLEX11_6_FLASH_SYSTEM_MESSAGECHANNELSTATE_AS)
#define FLEX11_6_FLASH_SYSTEM_MESSAGECHANNELSTATE_AS
#if defined(__cplusplus)



#include "flex11.6.h"



namespace flash
{
    namespace system
    {
        class MessageChannelState : public Object
        {
        public:
            static const std::string OPEN;
        public:
            static const std::string CLOSING;
        public:
            static const std::string CLOSED;

        public:
            MessageChannelState();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_MESSAGECHANNELSTATE_AS
#endif // __cplusplus

