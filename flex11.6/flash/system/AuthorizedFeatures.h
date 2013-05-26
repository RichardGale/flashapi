#if !defined(FLEX11_6_FLASH_SYSTEM_AUTHORIZEDFEATURES_AS)
#define FLEX11_6_FLASH_SYSTEM_AUTHORIZEDFEATURES_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace system
    {
        class ApplicationInstaller;
    }
}
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}
namespace flash
{
    namespace net
    {
        class URLStream;
    }
}

using namespace flash::net;
using namespace flash::system;
using namespace flash::utils;

namespace flash
{
    namespace system
    {
        class AuthorizedFeatures : public Object
        {
        public:
            AuthorizedFeatures();

        public:
            ApplicationInstaller *createApplicationInstaller(XML *strings, ByteArray *icon);

        public:
            bool  enableDiskCache(URLStream *stream);

            bool  isFeatureEnabled(std::string feature, std::string data="");

            bool  isNegativeToken();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_AUTHORIZEDFEATURES_AS
#endif // __cplusplus

