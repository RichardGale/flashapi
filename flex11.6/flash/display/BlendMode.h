#if !defined(FLEX11_6_FLASH_DISPLAY_BLENDMODE_AS)
#define FLEX11_6_FLASH_DISPLAY_BLENDMODE_AS
#if defined(__cplusplus)


/**
 * A class that provides constant values for visual blend mode effects. These constants are used in the following:
 *
 *   <ul class="- topic/ul "><li class="- topic/li "> The <codeph class="+ topic/ph pr-d/codeph ">blendMode</codeph> property of the flash.display.DisplayObject class.</li><li class="- topic/li "> The <codeph class="+ topic/ph pr-d/codeph ">blendMode</codeph> parameter of the <codeph class="+ topic/ph pr-d/codeph ">draw()</codeph> method of the
 * flash.display.BitmapData class</li></ul>
 * @langversion 3.0
 * @playerversion   Flash 9
 */

#include "flex11.6.h"



namespace flash
{
    namespace display
    {
        class BlendMode : public Object
        {
            /**
             * The display object appears in front of the background. Pixel values of the display object
             * override the pixel values of the background. Where the display object is transparent, the
             * background is visible.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string NORMAL;

            /**
             * Forces the creation of a transparency group for the display object. This means that the display
             * object is precomposed in a temporary buffer before it is processed further. The precomposition is done
             * automatically if the display object is precached by means of bitmap caching or if the display object is
             * a display object container that has at least one child object with a blendMode
             * setting other than "normal".
             *
             *   Not supported under GPU rendering.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string LAYER;

            /**
             * Multiplies the values of the display object constituent colors by the constituent colors of
             * the background color, and normalizes by dividing by 0xFF,
             * resulting in darker colors. This setting is commonly used for shadows and depth effects.
             *
             *   For example, if a constituent color (such as red) of one pixel in the display object and the
             * corresponding color of the pixel in the background both have the value 0x88, the multiplied
             * result is 0x4840. Dividing by 0xFF yields a value of 0x48 for that constituent color,
             * which is a darker shade than the color of the display object or the color of the background.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string MULTIPLY;

            /**
             * Multiplies the complement (inverse) of the display object color by the complement of the background
             * color, resulting in a bleaching effect. This setting is commonly used for highlights or to remove black
             * areas of the display object.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string SCREEN;

            /**
             * Selects the lighter of the constituent colors of the display object and the colors of the background (the
             * colors with the larger values). This setting is commonly used for superimposing type.
             *
             *   For example, if the display object has a pixel with an RGB value of 0xFFCC33, and the background
             * pixel has an RGB value of 0xDDF800, the resulting RGB value for the displayed pixel is
             * 0xFFF833 (because 0xFF > 0xDD, 0xCC < 0xF8, and 0x33 > 0x00 = 33).Not supported under GPU rendering.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string LIGHTEN;

            /**
             * Selects the darker of the constituent colors of the display object and the colors of the background (the
             * colors with the smaller values). This setting is commonly used for superimposing type.
             *
             *   For example, if the display object has a pixel with an RGB value of 0xFFCC33, and the background
             * pixel has an RGB value of 0xDDF800, the resulting RGB value for the displayed pixel is
             * 0xDDCC00 (because 0xFF > 0xDD, 0xCC < 0xF8, and 0x33 > 0x00 = 33).Not supported under GPU rendering.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string DARKEN;

            /**
             * Adds the values of the constituent colors of the display object to the colors of its background, applying a
             * ceiling of 0xFF. This setting is commonly used for animating a lightening dissolve between
             * two objects.
             *
             *   For example, if the display object has a pixel with an RGB value of 0xAAA633, and the background
             * pixel has an RGB value of 0xDD2200, the resulting RGB value for the displayed pixel is
             * 0xFFC833 (because 0xAA + 0xDD > 0xFF, 0xA6 + 0x22 = 0xC8, and 0x33 + 0x00 = 0x33).
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string ADD;

            /**
             * Subtracts the values of the constituent colors in the display object from the values of the background
             * color, applying a floor of 0. This setting is commonly used for animating a darkening dissolve between
             * two objects.
             *
             *   For example, if the display object has a pixel with an RGB value of 0xAA2233, and the background
             * pixel has an RGB value of 0xDDA600, the resulting RGB value for the displayed pixel is
             * 0x338400 (because 0xDD - 0xAA = 0x33, 0xA6 - 0x22 = 0x84, and 0x00 - 0x33 < 0x00).
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string SUBTRACT;

            /**
             * Compares the constituent colors of the display object with the colors of its background, and subtracts
             * the darker of the values of the two constituent colors from the lighter value. This setting is commonly
             * used for more vibrant colors.
             *
             *   For example, if the display object has a pixel with an RGB value of 0xFFCC33, and the background
             * pixel has an RGB value of 0xDDF800, the resulting RGB value for the displayed pixel is
             * 0x222C33 (because 0xFF - 0xDD = 0x22, 0xF8 - 0xCC = 0x2C, and 0x33 - 0x00 = 0x33).
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string DIFFERENCE;

            /**
             * Inverts the background.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string INVERT;

            /**
             * Adjusts the color of each pixel based on the darkness of the background.
             * If the background is lighter than 50% gray, the display object and background colors are
             * screened, which results in a lighter color. If the background is darker than 50% gray,
             * the colors are multiplied, which results in a darker color.
             * This setting is commonly used for shading effects.
             *
             *   Not supported under GPU rendering.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string OVERLAY;

            /**
             * Adjusts the color of each pixel based on the darkness of the display object.
             * If the display object is lighter than 50% gray, the display object and background colors are
             * screened, which results in a lighter color. If the display object is darker than 50% gray,
             * the colors are multiplied, which results in a darker color.
             * This setting is commonly used for shading effects.
             *
             *   Not supported under GPU rendering.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string HARDLIGHT;

            /**
             * Applies the alpha value of each pixel of the display object to the background.
             * This requires the blendMode property of the parent display object be set to
             * flash.display.BlendMode.LAYER.
             *
             *   Not supported under GPU rendering.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string ALPHA;

            /**
             * Erases the background based on the alpha value of the display object. This process requires
             * that the blendMode property of the parent display object be set to
             * flash.display.BlendMode.LAYER.
             *
             *   Not supported under GPU rendering.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string ERASE;

            /**
             * Uses a shader to define the blend between objects.
             *
             *   Setting the blendShader property to a Shader instance
             * automatically sets the display object's blendMode property to
             * BlendMode.SHADER. If the blendMode property is set to
             * BlendMode.SHADER without first setting the blendShader property,
             * the blendMode property is set to BlendMode.NORMAL instead.
             * If the blendShader property is set (which sets the
             * blendMode property to BlendMode.SHADER), then later the value of the
             * blendMode property is changed, the blend mode can be reset to use the blend
             * shader simply by setting the blendMode property to BlendMode.SHADER.
             * The blendShader property does not need to be set again except to change the
             * shader that's used to define the blend mode.Not supported under GPU rendering.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string SHADER;

        public:
            BlendMode();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_BLENDMODE_AS
#endif // __cplusplus

