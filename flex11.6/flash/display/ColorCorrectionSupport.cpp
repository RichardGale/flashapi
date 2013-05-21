

    /**
     * The ColorCorrectionSupport class provides values for the <codeph class="+ topic/ph pr-d/codeph ">flash.display.Stage.colorCorrectionSupport</codeph> property.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     */


namespace flash {
namespace display {


        /**
         * Color correction is not supported by the host environment.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ColorCorrectionSupport::UNSUPPORTED="unsupported";

        /**
         * Color correction is supported, and on by default.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ColorCorrectionSupport::DEFAULT_ON="defaultOn";

        /**
         * Color correction is supported, but off by default.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string ColorCorrectionSupport::DEFAULT_OFF="defaultOff";

        ColorCorrectionSupport::ColorCorrectionSupport();
}
}

