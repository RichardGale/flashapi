

    /**
     * The StageScaleMode class provides values for the <codeph class="+ topic/ph pr-d/codeph ">Stage.scaleMode</codeph> property.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */


namespace flash {
namespace display {


        /**
         * Specifies that the entire application be visible in the specified area without distortion while 
         * maintaining the original aspect ratio of the application. Borders can appear on two sides of the application.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string StageScaleMode::SHOW_ALL="showAll";

        /**
         * Specifies that the entire application be visible in the specified area without trying to preserve 
         * the original aspect ratio. Distortion can occur.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string StageScaleMode::EXACT_FIT="exactFit";

        /**
         * Specifies that the entire application fill the specified area, without distortion but possibly with 
         * some cropping, while maintaining the original aspect ratio of the application.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string StageScaleMode::NO_BORDER="noBorder";

        /**
         * Specifies that the size of the application be fixed, so that it remains unchanged even as the size 
         * of the player window changes. Cropping might occur if the player window is smaller than the content.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string StageScaleMode::NO_SCALE="noScale";

        StageScaleMode::StageScaleMode();
}
}

