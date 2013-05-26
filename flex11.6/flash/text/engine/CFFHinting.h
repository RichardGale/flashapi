#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_CFFHINTING_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_CFFHINTING_AS
#if defined(__cplusplus)


/**
 * The CFFHinting class defines values for cff hinting in the FontDescription class.
 *
 *   <p class="- topic/p ">Hinting adjusts the display of an outline font so it lines up with the pixel grid.
 * At small screen sizes, hinting produces a clear, legible text for human readers.
 * </p>
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
            class CFFHinting : public Object
            {
                /**
                 * No hinting is applied. Horizontal stems in the glyphs are not forced to the pixel grid.
                 * This constant is used in setting the cffHinting property of the
                 * FontDescription class. Recommended setting for animation or for large font sizes.
                 * Use the syntax CFFHinting.NONE.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string NONE;

                /**
                 * Fits strong horizontal stems to the pixel grid for improved readability.
                 * This constant is used in setting the cffHinting property of the
                 * FontDescription class. Use the syntax CFFHinting.HORIZONTAL_STEM.
                 *
                 *   Note: Not recommended for animation.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const std::string HORIZONTAL_STEM;

            public:
                CFFHinting();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_CFFHINTING_AS
#endif // __cplusplus

