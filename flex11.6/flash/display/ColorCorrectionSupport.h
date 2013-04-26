#if !defined(FLEX11_6_FLASH_DISPLAY_COLORCORRECTIONSUPPORT_AS)
#define FLEX11_6_FLASH_DISPLAY_COLORCORRECTIONSUPPORT_AS
#if defined(__cplusplus)


/**
 * The ColorCorrectionSupport class provides values for the <codeph class="+ topic/ph pr-d/codeph ">flash.display.Stage.colorCorrectionSupport</codeph> property.
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */

namespace flash
{
    namespace display
    {
        class ColorCorrectionSupport: public Object
        {
            /**
             * Color correction is not supported by the host environment.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string UNSUPPORTED;

            /**
             * Color correction is supported, and on by default.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string DEFAULT_ON;

            /**
             * Color correction is supported, but off by default.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string DEFAULT_OFF;

        public:
            ColorCorrectionSupport();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_COLORCORRECTIONSUPPORT_AS
#endif // __cplusplus

