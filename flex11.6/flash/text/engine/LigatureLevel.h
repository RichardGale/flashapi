#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_LIGATURELEVEL_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_LIGATURELEVEL_AS
#if defined(__cplusplus)


/**
 * The LigatureLevel class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">ligatureLevel</codeph> property
 * of the ElementFormat class. A ligature occurs where two or more letter-forms are joined as a single glyph. Ligatures
 * usually replace consecutive characters sharing common components, such as the letter pairs 'fi', 'fl', or 'ae'.
 * They are used with both Latin and Non-Latin character sets.
 * <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> When working with Arabic or Syriac fonts, <codeph class="+ topic/ph pr-d/codeph ">ligatureLevel</codeph> must be set to MINIMUM or above.</p>
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
            class LigatureLevel : public Object
            {
                /**
                 * Used to specify no ligatures.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string NONE;

                /**
                 * Used to specify minimum ligatures.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string MINIMUM;

                /**
                 * Used to specify common ligatures.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string COMMON;

                /**
                 * Used to specify uncommon ligatures.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string UNCOMMON;

                /**
                 * Used to specify exotic ligatures.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string EXOTIC;

            public:
                LigatureLevel();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_LIGATURELEVEL_AS
#endif // __cplusplus

