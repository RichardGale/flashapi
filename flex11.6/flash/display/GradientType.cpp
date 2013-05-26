

    /**
     * The GradientType class provides values for the <codeph class="+ topic/ph pr-d/codeph ">type</codeph> parameter in the 
     * <codeph class="+ topic/ph pr-d/codeph ">beginGradientFill()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">lineGradientStyle()</codeph> methods of the flash.display.Graphics class.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */


namespace flash {
namespace display {


        /**
         * Value used to specify a linear gradient fill.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string GradientType::LINEAR   = "linear";

        /**
         * Value used to specify a radial gradient fill.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string GradientType::RADIAL   = "radial";

        GradientType::GradientType();
}
}

