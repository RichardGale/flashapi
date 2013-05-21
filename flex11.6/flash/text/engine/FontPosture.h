#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_FONTPOSTURE_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_FONTPOSTURE_AS
#if defined(__cplusplus)


/**
 * The FontPosture class is an enumeration of constant values used with <codeph class="+ topic/ph pr-d/codeph ">FontDescription.fontPosture</codeph> to
 * set text to italic or normal.
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace text
    {
        namespace engine
        {
            class FontPosture : public Object
            {
                /**
                 * Used to indicate normal font posture.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string NORMAL;

                /**
                 * Used to indicate italic font posture.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string ITALIC;

            public:
                FontPosture();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_FONTPOSTURE_AS
#endif // __cplusplus

