#if !defined(FLEX11_6_FLASH_DISPLAY_GRADIENTTYPE_AS)
#define FLEX11_6_FLASH_DISPLAY_GRADIENTTYPE_AS
#if defined(__cplusplus)


/**
 * The GradientType class provides values for the <codeph class="+ topic/ph pr-d/codeph ">type</codeph> parameter in the
 * <codeph class="+ topic/ph pr-d/codeph ">beginGradientFill()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">lineGradientStyle()</codeph> methods of the flash.display.Graphics class.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace display
    {
        class GradientType : public Object
        {
            /**
             * Value used to specify a linear gradient fill.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string LINEAR;

            /**
             * Value used to specify a radial gradient fill.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string RADIAL;

        public:
            GradientType();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_GRADIENTTYPE_AS
#endif // __cplusplus

