#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_TEXTLINEVALIDITY_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_TEXTLINEVALIDITY_AS
#if defined(__cplusplus)


/**
 * The TextLineValidity class is an enumeration of constant values for setting the <codeph class="+ topic/ph pr-d/codeph ">validity</codeph> property
 * of the TextLine class.
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
            class TextLineValidity: public Object
            {
                /**
                 * Specifies that the text line is valid.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string VALID;

                /**
                 * Specifies that the text line is possibly invalid.  The Flash runtime uses this validity during rebreaking of a previously broken text
                 * block whose content has not changed.  You cannot set this value.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string POSSIBLY_INVALID;

                /**
                 * Specifies that the line is invalid.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string INVALID;

                /**
                 * Specifies that the line is static, and that the connection between the line and the text block has been severed.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string STATIC;

            public:
                TextLineValidity();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_TEXTLINEVALIDITY_AS
#endif // __cplusplus

