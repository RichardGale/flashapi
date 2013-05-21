

#include "FrameLabel.h"
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

namespace flash {
namespace display {


        /**
         * The name of the label.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string FrameLabel::name()         ;

        /**
         * The frame number containing the label.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        int FrameLabel::frame()      ;

        FrameLabel::FrameLabel(std::string name, int frame);
}
}

