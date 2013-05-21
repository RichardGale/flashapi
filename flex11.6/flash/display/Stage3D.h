#if !defined(FLEX11_6_FLASH_DISPLAY_STAGE3D_AS)
#define FLEX11_6_FLASH_DISPLAY_STAGE3D_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace display3D
    {
        class Context3D;
    }
}

using namespace flash::display3D;
using namespace flash::events;

namespace flash
{
    namespace display
    {
        class Stage3D : public flash::events::EventDispatcher
        {
        public:
            Context3D   *context3D();

        public:
            float        x();
        public:
            void         x(float value);

        public:
            float        y();
        public:
            void         y(float value);

        public:
            bool         visible();
        public:
            void         visible(bool value);

        public:
            void     requestContext3D(std::string context3DRenderMode="auto", std::string profile="baseline");

        public:
            Stage3D();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_STAGE3D_AS
#endif // __cplusplus

