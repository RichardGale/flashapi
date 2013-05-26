#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_TYPOGRAPHICCASE_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_TYPOGRAPHICCASE_AS
#if defined(__cplusplus)


/**
 * The TypographicCase class is an enumeration of constant values for setting the <codeph class="+ topic/ph pr-d/codeph ">typographicCase</codeph> property
 * of the ElementFormat class.
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



namespace flash
{
    namespace text
    {
        namespace engine
        {
            class TypographicCase : public Object
            {
                /**
                 * Specifies default typographic case. The results are font-dependent; characters use the settings specified by the font designer
                 * without any features applied.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string DEFAULT;

                /**
                 * Specifies that uppercase characters use title glyphs on output.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string TITLE;

                /**
                 * Specifies that spacing is adjusted for uppercase characters on output.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string CAPS;

                /**
                 * Specifies that uppercase characters use small-caps glyphs on output.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string SMALL_CAPS;

                /**
                 * Specifies that all characters use uppercase glyphs on output.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string UPPERCASE;

                /**
                 * Specifies that all characters use lowercase glyphs on output.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string LOWERCASE;

                /**
                 * Specifies that all lowercase characters use small-caps glyphs on output.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string CAPS_AND_SMALL_CAPS;

            public:
                TypographicCase();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_TYPOGRAPHICCASE_AS
#endif // __cplusplus

