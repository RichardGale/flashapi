#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_FONTWEIGHT_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_FONTWEIGHT_AS
#if defined(__cplusplus)


/**
 * The FontWeight class is an enumeration of constant values used with <codeph class="+ topic/ph pr-d/codeph ">FontDescription.fontWeight</codeph>.
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
            class FontWeight: public Object
            {
                /**
                 * Used to indicate normal font weight.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string NORMAL;

                /**
                 * Used to indicate bold font weight.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string BOLD;

            public:
                FontWeight();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_FONTWEIGHT_AS
#endif // __cplusplus

