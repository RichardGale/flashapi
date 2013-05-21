

#include "GraphicsSolidFill.h"
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


namespace flash {
namespace display {


        /**
         * The color of the fill. Valid values are in the hexadecimal format 0xRRGGBB. The default value is 0xFF0000 (or the uint 0).
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
                   

        /**
         * Indicates the alpha transparency value of the fill. Valid values are 0 (fully transparent) to 1 (fully opaque). 
         * The default value is 1. Display objects with alpha set to 0 are active, even though they are invisible.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
                   

        /**
         * Creates a new GraphicsSolidFill object.
         * @param   color   The color value. Valid values are in the hexadecimal format 0xRRGGBB.
         * @param   alpha   The alpha transparency value. Valid values are 0 (fully transparent) to 1 (fully opaque).
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        GraphicsSolidFill::GraphicsSolidFill(unsigned int color, float alpha);
}
}

