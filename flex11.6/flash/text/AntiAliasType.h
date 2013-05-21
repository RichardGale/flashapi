#if !defined(FLEX11_6_FLASH_TEXT_ANTIALIASTYPE_AS)
#define FLEX11_6_FLASH_TEXT_ANTIALIASTYPE_AS
#if defined(__cplusplus)


/**
 * The AntiAliasType class provides values for anti-aliasing in the flash.text.TextField class.
 * @langversion 3.0
 * @playerversion   Flash 9
 */


namespace flash
{
    namespace text
    {
        class AntiAliasType : public Object
        {
            /**
             * Sets anti-aliasing to the anti-aliasing that is used in Flash Player 7 and earlier.
             * This setting is recommended for applications that do not have a lot of text.
             * This constant is used for the antiAliasType property in the TextField
             * class.
             * Use the syntax AntiAliasType.NORMAL.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string NORMAL;

            /**
             * Sets anti-aliasing to advanced anti-aliasing. Advanced anti-aliasing
             * allows font faces to be rendered at very high quality at small sizes. It is best used
             * with applications that have a lot of small text. Advanced anti-aliasing is not recommended
             * for very large fonts (larger than 48 points).
             * This constant is used for the antiAliasType property in the TextField
             * class.
             * Use the syntax AntiAliasType.ADVANCED.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string ADVANCED;

        public:
            AntiAliasType();
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_ANTIALIASTYPE_AS
#endif // __cplusplus

