#if !defined(FLEX11_6_FLASH_DISPLAY_INTERPOLATIONMETHOD_AS)
#define FLEX11_6_FLASH_DISPLAY_INTERPOLATIONMETHOD_AS
#if defined(__cplusplus)


/**
 * The InterpolationMethod class provides values for the <codeph class="+ topic/ph pr-d/codeph ">interpolationMethod</codeph>
 * parameter in the <codeph class="+ topic/ph pr-d/codeph ">Graphics.beginGradientFill()</codeph> and
 * <codeph class="+ topic/ph pr-d/codeph ">Graphics.lineGradientStyle()</codeph> methods. This parameter determines
 * the RGB space to use when rendering the gradient.
 * @langversion 3.0
 * @playerversion   Flash 9
 */

#include "flex11.6.h"



namespace flash
{
    namespace display
    {
        class InterpolationMethod : public Object
        {
            /**
             * Specifies that the RGB interpolation method should be used. This means that the gradient is rendered with
             * exponential sRGB (standard RGB) space.
             * The sRGB space is a W3C-endorsed standard that defines a non-linear conversion between
             * red, green, and blue component values and the actual intensity of the visible component color.
             *
             *   For example, consider a simple linear gradient between two colors (with the spreadMethod
             * parameter set to SpreadMethod.REFLECT). The different interpolation methods affect
             * the appearance as follows: InterpolationMethod.LINEAR_RGBInterpolationMethod.RGB
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string RGB;

            /**
             * Specifies that the linear RGB interpolation method should be used. This means that
             * an RGB color space based on a linear RGB color model is used.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string LINEAR_RGB;

        public:
            InterpolationMethod();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_INTERPOLATIONMETHOD_AS
#endif // __cplusplus

