#if !defined(FLEX11_6_FLASH_UTILS_SETINTERVALTIMER_AS)
#define FLEX11_6_FLASH_UTILS_SETINTERVALTIMER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace events
    {
        class Event;
    }
}

using namespace flash::events;

namespace flash
{
    namespace utils
    {
        class SetIntervalTimer : public Timer
        {
            unsigned int id;

            static void     clearInterval(unsigned int id_to_clear);

        public:
            SetIntervalTimer(Function *closure, float delay, bool repeats, std::vector<void *> rest);
        };
    }
}

#endif // FLEX11_6_FLASH_UTILS_SETINTERVALTIMER_AS
#endif // __cplusplus

