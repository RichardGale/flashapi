#if !defined(FLEX11_6_FLASH_AUTOMATION_STAGECAPTURE_AS)
#define FLEX11_6_FLASH_AUTOMATION_STAGECAPTURE_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace geom
    {
        class Rectangle;
    }
}
namespace flash
{
    namespace display
    {
        class BitmapData;
    }
}

using namespace flash::display;
using namespace flash::events;
using namespace flash::geom;

namespace flash
{
    namespace automation
    {
        class StageCapture : public flash::events::EventDispatcher
        {
        public:
            static const std::string CURRENT;
        public:
            static const std::string NEXT;
        public:
            static const std::string MULTIPLE;
        public:
            static const std::string RASTER;
        public:
            static const std::string STAGE;
        public:
            static const std::string SCREEN;

        public:
            void         fileNameBase(std::string value);
        public:
            std::string  fileNameBase();

        public:
            void         clipRect(Rectangle *value);
        public:
            Rectangle   *clipRect();

        public:
            void         captureSource(std::string value);
        public:
            std::string  captureSource();

        public:
            void     capture(std::string type);

        public:
            void     cancel();

        public:
            BitmapData *captureBitmapData();

        public:
            StageCapture();
        };
    }
}

#endif // FLEX11_6_FLASH_AUTOMATION_STAGECAPTURE_AS
#endif // __cplusplus

