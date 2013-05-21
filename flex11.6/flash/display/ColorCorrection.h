#if !defined(FLEX11_6_FLASH_DISPLAY_COLORCORRECTION_AS)
#define FLEX11_6_FLASH_DISPLAY_COLORCORRECTION_AS
#if defined(__cplusplus)


/**
 * The ColorCorrection class provides values for the <codeph class="+ topic/ph pr-d/codeph ">flash.display.Stage.colorCorrection</codeph> property.
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */


namespace flash
{
    namespace display
    {
        class ColorCorrection : public Object
        {
            /**
             * Uses the host's default color correction. For the web player the host is usually a browser, and Flash Player
             * tries to use the same color correction as the web page hosting the SWF file.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string DEFAULT;

            /**
             * Turns on color correction regardless of the player host environment, if available.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string ON;

            /**
             * Turns off color correction regardless of the player host environment.
             * This setting provides faster performance.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string OFF;

        public:
            ColorCorrection();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_COLORCORRECTION_AS
#endif // __cplusplus

