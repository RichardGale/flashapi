#if !defined(FLEX11_6_FLASH_SYSTEM_WORKERSTATE_AS)
#define FLEX11_6_FLASH_SYSTEM_WORKERSTATE_AS
#if defined(__cplusplus)



#include "flex11.6.h"



namespace flash
{
    namespace system
    {
        class WorkerState : public Object
        {
        public:
            static const std::string NEW;
        public:
            static const std::string RUNNING;
        public:
            static const std::string TERMINATED;

        public:
            WorkerState();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_WORKERSTATE_AS
#endif // __cplusplus

