#if !defined(FLEX11_6_FLASH_CONCURRENT_CONDITION_AS)
#define FLEX11_6_FLASH_CONCURRENT_CONDITION_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace concurrent
    {
        class Mutex;
    }
}

using namespace flash::concurrent;

namespace flash
{
    namespace concurrent
    {
        class Condition : public Object
        {
        public:
            static bool         isSupported();

        public:
            Mutex       *mutex();

        public:
            Condition(Mutex *mutex);

        public:
            bool     wait(float timeout =-1);

        public:
            void     notify();

        public:
            void     notifyAll();
        };
    }
}

#endif // FLEX11_6_FLASH_CONCURRENT_CONDITION_AS
#endif // __cplusplus

