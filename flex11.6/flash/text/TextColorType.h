#if !defined(FLEX11_6_FLASH_TEXT_TEXTCOLORTYPE_AS)
#define FLEX11_6_FLASH_TEXT_TEXTCOLORTYPE_AS
#if defined(__cplusplus)


/**
 * The TextColorType class provides color values for the flash.text.TextRenderer class.
 * @langversion 3.0
 * @playerversion   Flash 9
 */


namespace flash
{
    namespace text
    {
        class TextColorType : public Object
        {
            /**
             * Used in the colorType parameter in the setAdvancedAntiAliasingTable() method.
             * Use the syntax TextColorType.DARK_COLOR.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string DARK_COLOR;

            /**
             * Used in the colorType parameter in the setAdvancedAntiAliasingTable() method.
             * Use the syntax TextColorType.LIGHT_COLOR.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string LIGHT_COLOR;

        public:
            TextColorType();
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_TEXTCOLORTYPE_AS
#endif // __cplusplus

