#if !defined(FLEX11_6_FLASH_DISPLAY_GRAPHICSBITMAPFILL_AS)
#define FLEX11_6_FLASH_DISPLAY_GRAPHICSBITMAPFILL_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "IGraphicsFill.h"
#include "IGraphicsData.h"
namespace flash
{
    namespace display
    {
        class BitmapData;
    }
}
namespace flash
{
    namespace geom
    {
        class Matrix;
    }
}

/**
 * Defines a bitmap fill. The bitmap can be smoothed, repeated or tiled to fill
 * the area; or manipulated using a transformation matrix.
 * <p class="- topic/p ">
 * Use a GraphicsBitmapFill object with the <codeph class="+ topic/ph pr-d/codeph ">Graphics.drawGraphicsData()</codeph> method.
 * Drawing a GraphicsBitmapFill object is the equivalent of calling the <codeph class="+ topic/ph pr-d/codeph ">Graphics.beginBitmapFill()</codeph> method.
 * </p>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */

using namespace flash::display;
using namespace flash::geom;

namespace flash
{
    namespace display
    {
        class GraphicsBitmapFill : public Object, public private::IGraphicsFill, public private::IGraphicsData
        {
            /**
             * A transparent or opaque bitmap image.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            flash::display::BitmapData *bitmapData;

            /**
             * A matrix object (of the flash.geom.Matrix class) that
             * defines transformations on the bitmap. For example, the following matrix
             * rotates a bitmap by 45 degrees (pi/4 radians):
             *
             *   <codeblock>
             *
             *   matrix = new flash.geom.Matrix();
             * matrix.rotate(Math.PI / 4);
             *
             *   </codeblock>
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            flash::geom::Matrix *matrix;

            /**
             * Specifies whether to repeat the bitmap image in a tiled pattern.
             *
             *   If true, the bitmap image repeats in a tiled pattern. If
             * false, the bitmap image does not repeat, and the outermost pixels along
             * the edges of the bitmap are used for any fill area that extends beyond the bounds of the bitmap.For example, consider the following bitmap (a 20 x 20-pixel checkerboard pattern):When repeat is set to true (as in the following example), the bitmap fill
             * repeats the bitmap:When repeat is set to false, the bitmap fill uses the edge
             * pixels for the fill area outside the bitmap:
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            bool repeat;

            /**
             * Specifies whether to apply a smoothing algorithm to the bitmap image.
             *
             *   If false, upscaled bitmap images are rendered by using a
             * nearest-neighbor algorithm and look pixelated. If true, upscaled
             * bitmap images are rendered by using a bilinear algorithm. Rendering by using the nearest
             * neighbor algorithm is usually faster.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            bool smooth;

            /**
             * Creates a new GraphicsBitmapFill object.
             * @param   bitmapData  A transparent or opaque bitmap image that contains the bits to display.
             * @param   matrix  A matrix object (of the flash.geom.Matrix class), which you use to
             *   define transformations on the bitmap.
             * @param   repeat  If true, the bitmap image repeats in a tiled pattern. If
             *   false, the bitmap image does not repeat, and the edges of the bitmap are
             *   used for any fill area that extends beyond the bitmap.
             * @param   smooth  If false, upscaled bitmap images are rendered using a
             *   nearest-neighbor algorithm and appear pixelated. If true, upscaled
             *   bitmap images are rendered using a bilinear algorithm. Rendering that uses the nearest-neighbor
             *   algorithm is usually faster.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            GraphicsBitmapFill(BitmapData *bitmapData=NULL, Matrix *matrix=NULL, bool repeat=true, bool smooth=false);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_GRAPHICSBITMAPFILL_AS
#endif // __cplusplus

