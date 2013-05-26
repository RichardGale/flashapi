

    /**
     * The StageDisplayState class provides values for the <codeph class="+ topic/ph pr-d/codeph ">Stage.displayState</codeph> property.
     * @langversion 3.0
     * @playerversion   Flash 9.0.28.0
     * @playerversion   Lite 4
     */


namespace flash {
namespace display {


        /**
         * Specifies that the Stage is in full-screen mode. Keyboard interactivity is disabled in this mode.
         * @langversion 3.0
         * @playerversion   Flash 9.0.28.0
         * @playerversion   Lite 4
         */
        const std::string StageDisplayState::FULL_SCREEN   = "fullScreen";

        /**
         * Specifies that the Stage is in full-screen mode with keyboard interactivity enabled. 
         * Only AIR applications support this capability.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        const std::string StageDisplayState::FULL_SCREEN_INTERACTIVE   = "fullScreenInteractive";

        /**
         * Specifies that the Stage is in normal mode.
         * @langversion 3.0
         * @playerversion   Flash 9.0.28.0
         * @playerversion   Lite 4
         */
        const std::string StageDisplayState::NORMAL   = "normal";

        StageDisplayState::StageDisplayState();
}
}

