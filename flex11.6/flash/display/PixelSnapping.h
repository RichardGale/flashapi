#if !defined(FLEX11_6_FLASH_DISPLAY_PIXELSNAPPING_AS)
#define FLEX11_6_FLASH_DISPLAY_PIXELSNAPPING_AS
#if defined(__cplusplus)


/**
 * The PixelSnapping class is an enumeration of constant values for setting the pixel snapping options
 * by using the <codeph class="+ topic/ph pr-d/codeph ">pixelSnapping</codeph> property of a Bitmap object.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



namespace flash
{
    namespace display
    {
        class PixelSnapping : public Object
        {
            /**
             * A constant value used in the pixelSnapping property of a Bitmap object
             * to specify that no pixel snapping occurs.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string NEVER;

            /**
             * A constant value used in the pixelSnapping property of a Bitmap object
             * to specify that the bitmap image is always snapped to the nearest
             * pixel, independent of any transformation.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string ALWAYS;

            /**
             * A constant value used in the pixelSnapping property of a Bitmap object
             * to specify that the bitmap image is snapped to the nearest pixel if it is drawn with no rotation
             * or skew and it is drawn at a scale factor of 99.9% to 100.1%. If these conditions are satisfied,
             * the image is drawn at 100% scale, snapped to the nearest pixel. Internally, this setting allows the image
             * to be drawn as fast as possible by using the vector renderer.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string AUTO;

        public:
            PixelSnapping();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_PIXELSNAPPING_AS
#endif // __cplusplus

