

    /**
     * The EventPhase class provides values for the <codeph class="+ topic/ph pr-d/codeph ">eventPhase</codeph> property of the Event class.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     * @internal    includeExample examples\EventPhaseExample.as -noswf
     */


namespace flash {
namespace events {


        /**
         * The capturing phase, which is the first phase of the event flow.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const unsigned int EventPhase::CAPTURING_PHASE   = 1;

        /**
         * The target phase, which is the second phase of the event flow.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const unsigned int EventPhase::AT_TARGET   = 2;

        /**
         * The bubbling phase, which is the third phase of the event flow.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const unsigned int EventPhase::BUBBLING_PHASE   = 3;

        EventPhase::EventPhase();
}
}

