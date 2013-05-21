#if !defined(FLEX11_6_FLASH_DISPLAY_GRAPHICSSOLIDFILL_AS)
#define FLEX11_6_FLASH_DISPLAY_GRAPHICSSOLIDFILL_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "IGraphicsFill.h"
#include "IGraphicsData.h"

/**
 * Defines a solid fill.
 *
 *   <p class="- topic/p ">
 * Use a GraphicsSolidFill object with the <codeph class="+ topic/ph pr-d/codeph ">Graphics.drawGraphicsData()</codeph> method.
 * Drawing a GraphicsSolidFill object is the equivalent of calling the <codeph class="+ topic/ph pr-d/codeph ">Graphics.beginFill()</codeph> method.
 * </p>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */


namespace flash
{
    namespace display
    {
        class GraphicsSolidFill : public Object, public private::IGraphicsFill, public private::IGraphicsData
        {
            /**
             * The color of the fill. Valid values are in the hexadecimal format 0xRRGGBB. The default value is 0xFF0000 (or the uint 0).
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            unsigned int color;

            /**
             * Indicates the alpha transparency value of the fill. Valid values are 0 (fully transparent) to 1 (fully opaque).
             * The default value is 1. Display objects with alpha set to 0 are active, even though they are invisible.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            float alpha;

            /**
             * Creates a new GraphicsSolidFill object.
             * @param   color   The color value. Valid values are in the hexadecimal format 0xRRGGBB.
             * @param   alpha   The alpha transparency value. Valid values are 0 (fully transparent) to 1 (fully opaque).
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            GraphicsSolidFill(unsigned int color=0, float alpha =1);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_GRAPHICSSOLIDFILL_AS
#endif // __cplusplus

