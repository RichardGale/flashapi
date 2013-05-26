#if !defined(FLEX11_6_FLASH_FILTERS_DISPLACEMENTMAPFILTERMODE_AS)
#define FLEX11_6_FLASH_FILTERS_DISPLACEMENTMAPFILTERMODE_AS
#if defined(__cplusplus)


/**
 * The DisplacementMapFilterMode class provides values for the <codeph class="+ topic/ph pr-d/codeph ">mode</codeph> property
 * of the DisplacementMapFilter class.
 * @langversion 3.0
 * @playerversion   Flash 9
 */

#include "flex11.6.h"



namespace flash
{
    namespace filters
    {
        class DisplacementMapFilterMode : public Object
        {
            /**
             * Wraps the displacement value to the other side of the source image.
             * Use with the DisplacementMapFilter.mode property.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string WRAP;

            /**
             * Clamps the displacement value to the edge of the source image.
             *
             *   Use with the DisplacementMapFilter.mode property.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string CLAMP;

            /**
             * If the displacement value is out of range, ignores the displacement and uses the source pixel.
             *
             *   Use with the DisplacementMapFilter.mode property.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string IGNORE;

            /**
             * If the displacement value is outside the image, substitutes the values in
             * the color and alpha properties.
             *
             *   Use with the DisplacementMapFilter.mode property.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string COLOR;

        public:
            DisplacementMapFilterMode();
        };
    }
}

#endif // FLEX11_6_FLASH_FILTERS_DISPLACEMENTMAPFILTERMODE_AS
#endif // __cplusplus

