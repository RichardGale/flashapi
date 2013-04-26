#if !defined(FLEX11_6_FLASH_SYSTEM_APPLICATIONINSTALLER_AS)
#define FLEX11_6_FLASH_SYSTEM_APPLICATIONINSTALLER_AS
#if defined(__cplusplus)


#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

using namespace flash::events;
using namespace flash::utils;

namespace flash
{
    namespace system
    {
        class ApplicationInstaller: public EventDispatcher
        {
        public:
            bool         isInstalled();

        public:
            ApplicationInstaller();

        public:
            static std::string stringsDigest(XML *strings);

        public:
            static std::string iconDigest(ByteArray *icon);

        public:
            void     install(std::string mode);
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_APPLICATIONINSTALLER_AS
#endif // __cplusplus

