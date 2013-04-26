#if !defined(FLEX11_6_FLASH_DISPLAY_FRAMELABEL_AS)
#define FLEX11_6_FLASH_DISPLAY_FRAMELABEL_AS
#if defined(__cplusplus)


#include "flash/events/EventDispatcher.h"

/**
 * The FrameLabel object contains properties that specify a frame number and the
 * corresponding label name.
 * The Scene class includes a <codeph class="+ topic/ph pr-d/codeph ">labels</codeph> property, which is an array
 * of FrameLabel objects for the scene.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
using namespace flash::events;

namespace flash
{
    namespace display
    {
        class FrameLabel: public EventDispatcher
        {
            /**
             * The name of the label.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  name();

            /**
             * The frame number containing the label.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int          frame();

        public:
            FrameLabel(std::string name, int frame);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_FRAMELABEL_AS
#endif // __cplusplus

