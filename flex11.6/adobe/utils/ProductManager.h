#if !defined(FLEX11_6_ADOBE_UTILS_PRODUCTMANAGER_AS)
#define FLEX11_6_ADOBE_UTILS_PRODUCTMANAGER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"

using namespace flash::events;

namespace adobe
{
    namespace utils
    {
        class ProductManager : public flash::events::EventDispatcher
        {
        public:
            bool      running();

        public:
            bool      installed();

        public:
            std::string       installedVersion();

        public:
            ProductManager(std::string name="", bool shared=false);

        public:
            bool  launch(std::string parameters="");

        public:
            bool  download(std::string caption="", std::string fileName="", std::vector<void *> pathElements=std::vector<void *>());

        public:
            bool  doSelfUpgrade(std::string os);
        };
    }
}

#endif // FLEX11_6_ADOBE_UTILS_PRODUCTMANAGER_AS
#endif // __cplusplus

