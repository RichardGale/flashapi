#if !defined(FLEX11_6_FLASH_DISPLAY_GRAPHICSENDFILL_AS)
#define FLEX11_6_FLASH_DISPLAY_GRAPHICSENDFILL_AS
#if defined(__cplusplus)


#include "IGraphicsFill.h"
#include "IGraphicsData.h"

/**
 * Indicates the end of a graphics fill. Use a GraphicsEndFill object with the <codeph class="+ topic/ph pr-d/codeph ">Graphics.drawGraphicsData()</codeph> method.
 *
 *   <p class="- topic/p ">
 * Drawing a GraphicsEndFill object is the equivalent of calling the <codeph class="+ topic/ph pr-d/codeph ">Graphics.endFill()</codeph> method.
 * </p>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */
using namespace ;
using namespace ;

namespace flash
{
    namespace display
    {
        class GraphicsEndFill: public Object, public IGraphicsFill,, public IGraphicsData
        {
            /**
             * Creates an object to use with the Graphics.drawGraphicsData() method to end
             * the fill, explicitly.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            GraphicsEndFill();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_GRAPHICSENDFILL_AS
#endif // __cplusplus

