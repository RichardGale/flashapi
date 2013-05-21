

    /**
     * The TextLineCreationResult class is an enumeration of constant values used with <codeph class="+ topic/ph pr-d/codeph ">TextBlock.textLineCreationResult</codeph>.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {
namespace engine {


        /**
         * Indicates the line was successfully broken.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextLineCreationResult::SUCCESS="success";

        /**
         * Indicates the line was created with an emergency break because no break opportunity
         * was available in the specified width.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextLineCreationResult::EMERGENCY="emergency";

        /**
         * Indicates no line was created because all text in the block had already been broken.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextLineCreationResult::COMPLETE="complete";

        /**
         * Indicates no line was created because no text could fit in the specified width
         * and fitSomething was not specified in the call to createTextLine().
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextLineCreationResult::INSUFFICIENT_WIDTH="insufficientWidth";

        TextLineCreationResult::TextLineCreationResult();
}
}
}

