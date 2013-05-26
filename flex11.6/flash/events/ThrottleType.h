#if !defined(FLEX11_6_FLASH_EVENTS_THROTTLETYPE_AS)
#define FLEX11_6_FLASH_EVENTS_THROTTLETYPE_AS
#if defined(__cplusplus)



#include "flex11.6.h"



namespace flash
{
    namespace events
    {
        class ThrottleType : public Object
        {
        public:
            static const std::string THROTTLE;
        public:
            static const std::string PAUSE;
        public:
            static const std::string RESUME;

        public:
            ThrottleType();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_THROTTLETYPE_AS
#endif // __cplusplus

