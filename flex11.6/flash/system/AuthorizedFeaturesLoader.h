#if !defined(FLEX11_6_FLASH_SYSTEM_AUTHORIZEDFEATURESLOADER_AS)
#define FLEX11_6_FLASH_SYSTEM_AUTHORIZEDFEATURESLOADER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace system
    {
        class AuthorizedFeatures;
    }
}

using namespace flash::events;
using namespace flash::system;

namespace flash
{
    namespace system
    {
        class AuthorizedFeaturesLoader : public flash::events::EventDispatcher
        {
        public:
            AuthorizedFeatures *authorizedFeatures();

        public:
            AuthorizedFeaturesLoader();

        public:
            void     loadAuthorizedFeatures();

            void     makeGlobal();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_AUTHORIZEDFEATURESLOADER_AS
#endif // __cplusplus

