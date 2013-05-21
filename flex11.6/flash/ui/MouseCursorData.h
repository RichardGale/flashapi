#if !defined(FLEX11_6_FLASH_UI_MOUSECURSORDATA_AS)
#define FLEX11_6_FLASH_UI_MOUSECURSORDATA_AS
#if defined(__cplusplus)


#include "flex11.6.h"
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
        class Point;
    }
}

/**
 * The MouseCursorData class lets you define the appearance of a "native" mouse cursor.
 *
 *   <p class="- topic/p ">To display the cursor, use the <codeph class="+ topic/ph pr-d/codeph ">Mouse.registerCursor()</codeph> function. To return
 * control of the cursor image to the operating system, call <codeph class="+ topic/ph pr-d/codeph ">Mouse.unregisterCursor()</codeph>.
 * Call <codeph class="+ topic/ph pr-d/codeph ">Mouse.supportsNativeCursor</codeph> to test whether native cursors are supported on the
 * current computer.</p><p class="- topic/p ">The maximum cursor size is 32x32 pixels.Transparency is supported on most operating systems.</p><p class="- topic/p ">A native mouse cursor is implemented directly through the operating system cursor mechanism
 * and is a more efficient means for displaying a custom cursor image than using a display object.
 * You can animate the cursor by supplying more than one image in the <codeph class="+ topic/ph pr-d/codeph ">data</codeph> property
 * and setting the frame rate. </p><p class="- topic/p ">The cursor is only displayed within the bounds of the stage. Outside the stage, control of the
 * cursor image returns to the operating system</p>
 *
 *   EXAMPLE:
 *
 *   The following example creates and displays a spinning arrow for the mouse cursor.
 *
 *   <p class="- topic/p ">The example uses the drawing commands available through the Graphics class to create
 * eight, rotated images of an arrow. These images are pushed into a vector and assigned to the <codeph class="+ topic/ph pr-d/codeph ">data</codeph>
 * property of the MouseCursorData object. (Note that you can also use prerendered bitmap images for your cursors.)</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package  {
 *
 *   import flash.display.Sprite;
 * import flash.display.Shape;
 * import flash.display.BitmapData;
 * import flash.display.GraphicsPath;
 * import flash.ui.MouseCursorData;
 * import flash.ui.Mouse;
 * import flash.geom.Matrix;
 *
 *   public class MouseCursorDataExample extends Sprite {
 * //Graphics path data for an arrow
 * private var cursorPoints:Vector.&lt;Number&gt; = new &lt;Number&gt;[0,8, 16,8, 16,0, 24,12, 16,24, 16,16, 0,16, 0,8];
 * private var cursorDrawCommands:Vector.&lt;int&gt; = new &lt;int&gt;[1,2,2,2,2,2,2,2];
 *
 *   public function MouseCursorDataExample() {
 * var mouseCursorData:MouseCursorData = new MouseCursorData();
 * mouseCursorData.data = makeCursorImages();
 * mouseCursorData.frameRate = 1;
 *
 *   Mouse.registerCursor( "spinningArrow", mouseCursorData );
 * Mouse.cursor = "spinningArrow";
 * }
 *
 *   //Returns a Vector containing 8 cursor images
 * private function makeCursorImages():Vector.&lt;BitmapData&gt;
 * {
 * var cursorData:Vector.&lt;BitmapData&gt; = new Vector.&lt;BitmapData&gt;();
 *
 *   var cursorShape:Shape = new Shape();
 * cursorShape.graphics.beginFill( 0xff5555, .75 );
 * cursorShape.graphics.lineStyle( 1 );
 * cursorShape.graphics.drawPath( cursorDrawCommands, cursorPoints );
 * cursorShape.graphics.endFill();
 * var transformer:Matrix = new Matrix();
 *
 *   //Rotate and draw the arrow shape to a BitmapData object for each of 8 frames
 * for( var i:int = 0; i &lt; 8; i++ )
 * {
 * var cursorFrame:BitmapData = new BitmapData( 32, 32, true, 0 );
 * cursorFrame.draw( cursorShape, transformer );
 * cursorData.push( cursorFrame );
 *
 *   transformer.translate(-15,-15);
 * transformer.rotate( 0.785398163 );
 * transformer.translate(15,15);
 * }
 * return cursorData;
 * }
 * }
 *
 *   }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10.2
 * @playerversion   AIR 2.6
 */

using namespace flash::display;
using namespace flash::geom;

namespace flash
{
    namespace ui
    {
        class MouseCursorData : public Object
        {
            /**
             * A Vector of BitmapData objects containing the cursor image or images.
             *
             *   Supply more than one image and set the framerate property to
             * animate the cursor.The maximum cursor size is 32x32 pixels.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR 2.6
             */
        public:
            std::vector<flash::display::BitmapData *> data();
        public:
            void         data(std::vector<BitmapData *> data);

            /**
             * The hot spot of the cursor in pixels.
             *
             *   The hotspot is the point on the cursor under which mouse clicks are registered.
             * By default, the hot spot is the upper-left corner (0,0).
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR 2.6
             */
        public:
            flash::geom::Point *hotSpot();
        public:
            void         hotSpot(Point *data);

            /**
             * The frame rate for animating the cursor.
             *
             *   Suppy more than one image in the data property and set the
             * frame rate to a value greater than 0 to animate the cursor. The cursor frame rate
             * may differ from the current SWF frame rate.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR 2.6
             */
        public:
            float        frameRate();
        public:
            void         frameRate(float data);

            /**
             * Creates a MouseCursorData object.
             *
             *   To display the cursor, call the Mouse.registerCursor() function.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR 2.6
             */
        public:
            MouseCursorData();
        };
    }
}

#endif // FLEX11_6_FLASH_UI_MOUSECURSORDATA_AS
#endif // __cplusplus

