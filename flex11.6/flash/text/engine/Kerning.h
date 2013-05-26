#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_KERNING_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_KERNING_AS
#if defined(__cplusplus)


/**
 * The Kerning class is an enumeration of constant values used with <codeph class="+ topic/ph pr-d/codeph ">ElementFormat.kerning</codeph>.
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
            class Kerning : public Object
            {
                /**
                 * Used to indicate kerning is enabled.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string ON;

                /**
                 * Used to indicate kerning is disabled.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string OFF;

                /**
                 * Used to indicate that kerning is enabled except where inappropriate in Asian typography. Kerning is
                 * applied between two characters if neither is Kanji, Hiragana, or Katakana.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string AUTO;

            public:
                Kerning();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_KERNING_AS
#endif // __cplusplus

