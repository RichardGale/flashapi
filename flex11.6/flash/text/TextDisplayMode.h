#if !defined(FLEX11_6_FLASH_TEXT_TEXTDISPLAYMODE_AS)
#define FLEX11_6_FLASH_TEXT_TEXTDISPLAYMODE_AS
#if defined(__cplusplus)


/**
 * The TextDisplayMode class contains values that control the subpixel anti-aliasing of the advanced anti-aliasing system.
 * @langversion 3.0
 * @playerversion   Flash 9
 */

#include "flex11.6.h"



namespace flash
{
    namespace text
    {
        class TextDisplayMode : public Object
        {
            /**
             * Forces Flash Player to use LCD subpixel anti-aliasing. Depending on the font and
             * the hardware, this setting can result in much higher resolution text or text coloring.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string LCD;

            /**
             * Forces Flash Player to display grayscale anti-aliasing. While this setting
             * avoids text coloring, some users may think it appears blurry.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string CRT;

            /**
             * Allows Flash Player to choose LCD or CRT mode.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string DEFAULT;

        public:
            TextDisplayMode();
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_TEXTDISPLAYMODE_AS
#endif // __cplusplus

