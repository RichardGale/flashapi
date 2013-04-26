#if !defined(FLEX11_6_FLASH_SYSTEM_WORKERDOMAIN_AS)
#define FLEX11_6_FLASH_SYSTEM_WORKERDOMAIN_AS
#if defined(__cplusplus)



namespace flash
{
    namespace system
    {
        class Worker;
    }
}
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

using namespace flash::system;
using namespace flash::utils;

namespace flash
{
    namespace system
    {
        class WorkerDomain: public Object
        {
        public:
            static bool         isSupported();

        public:
            static WorkerDomain *current();

        public:
            Worker  *createWorker(ByteArray *swf, bool giveAppPrivileges);

        public:
            std::vector<Worker *> *listWorkers();

        public:
            WorkerDomain();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_WORKERDOMAIN_AS
#endif // __cplusplus

