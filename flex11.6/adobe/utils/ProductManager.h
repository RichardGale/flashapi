#if !defined(FLEX11_6_ADOBE_UTILS_PRODUCTMANAGER_AS)
#define FLEX11_6_ADOBE_UTILS_PRODUCTMANAGER_AS
#if defined(__cplusplus)


#include "flash/events/EventDispatcher.h"

using namespace flash::events;

namespace adobe
{
    namespace utils
    {
        class ProductManager: public EventDispatcher
        {
        public:
            bool         running();

        public:
            bool         installed();

        public:
            std::string  installedVersion();

        public:
            ProductManager(std::string name, bool shared);

        public:
            bool     launch(std::string parameters);

        public:
            bool     download(std::string caption, std::string fileName, std::vector<void *> pathElements);

        public:
            bool     doSelfUpgrade(std::string os);
        };
    }
}

#endif // FLEX11_6_ADOBE_UTILS_PRODUCTMANAGER_AS
#endif // __cplusplus

