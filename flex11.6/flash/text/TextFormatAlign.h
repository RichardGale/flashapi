#if !defined(FLEX11_6_FLASH_TEXT_TEXTFORMATALIGN_AS)
#define FLEX11_6_FLASH_TEXT_TEXTFORMATALIGN_AS
#if defined(__cplusplus)


/**
 * The TextFormatAlign class provides values for text alignment in the TextFormat class.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace text
    {
        class TextFormatAlign : public Object
        {
            /**
             * Constant; aligns text to the left within the text field.
             * Use the syntax TextFormatAlign.LEFT.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string LEFT;

            /**
             * Constant; centers the text in the text field.
             * Use the syntax TextFormatAlign.CENTER.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string CENTER;

            /**
             * Constant; aligns text to the right within the text field.
             * Use the syntax TextFormatAlign.RIGHT.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string RIGHT;

            /**
             * Constant; justifies text within the text field.
             * Use the syntax TextFormatAlign.JUSTIFY.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string JUSTIFY;
        public:
            static const std::string START;
        public:
            static const std::string END;

        public:
            TextFormatAlign();
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_TEXTFORMATALIGN_AS
#endif // __cplusplus

