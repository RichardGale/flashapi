

    /**
     * The TextDisplayMode class contains values that control the subpixel anti-aliasing of the advanced anti-aliasing system.
     * @langversion 3.0
     * @playerversion   Flash 9
     */


namespace flash {
namespace text {


        /**
         * Forces Flash Player to use LCD subpixel anti-aliasing. Depending on the font and
         * the hardware, this setting can result in much higher resolution text or text coloring.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string TextDisplayMode::LCD   = "lcd";

        /**
         * Forces Flash Player to display grayscale anti-aliasing. While this setting 
         * avoids text coloring, some users may think it appears blurry.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string TextDisplayMode::CRT   = "crt";

        /**
         * Allows Flash Player to choose LCD or CRT mode.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string TextDisplayMode::DEFAULT   = "default";

        TextDisplayMode::TextDisplayMode();
}
}

