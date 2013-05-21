#if !defined(FLEX11_6_FLASH_DISPLAY_SHAPE_AS)
#define FLEX11_6_FLASH_DISPLAY_SHAPE_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace display
    {
        class Graphics;
    }
}

/**
 * This class is used to create lightweight shapes using the ActionScript drawing application program interface (API).
 * The Shape class includes a <codeph class="+ topic/ph pr-d/codeph ">graphics</codeph> property, which lets you access methods from the Graphics class.
 *
 *   <p class="- topic/p ">The Sprite class also includes a <codeph class="+ topic/ph pr-d/codeph ">graphics</codeph>property, and it includes other features not available to the
 * Shape class. For example, a Sprite object is a display object container, whereas a Shape object is not (and cannot contain
 * child display objects). For this reason, Shape objects consume less memory than Sprite objects that contain the
 * same graphics. However, a Sprite object supports user input events, while a Shape object does not.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">ShapeExample</codeph> class to draw a circle,
 * a rounded rectangle, and a square.  This task is accomplished by performing the following steps:
 *
 *   <ol class="- topic/ol "><li class="- topic/li ">Declare a <codeph class="+ topic/ph pr-d/codeph ">size</codeph> property for later use in determining the size of each shape.</li><li class="- topic/li ">Declare properties that set the background color to orange, the border color to
 * dark gray, the border size to 0 pixels, the corner radius to 9 pixels, and set the space
 * between the stage edge and the other objects to be 5 pixels.</li><li class="- topic/li ">Use the properties declared in the preceding steps along with the built-in methods of the
 * Graphics class to draw the circle, rounded rectangle, and square at coordinates x = 0, y = 0.</li><li class="- topic/li ">Redraw each of the shapes along the top of the stage, starting at x = 5, y = 5, with
 * a 5-pixel spacing between shapes by using the <codeph class="+ topic/ph pr-d/codeph ">refreshLayout()</codeph> method.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.DisplayObject;
 * import flash.display.Graphics;
 * import flash.display.JointStyle;
 * import flash.display.LineScaleMode;
 * import flash.display.Shape;
 * import flash.display.Sprite;
 *
 *   public class ShapeExample extends Sprite {
 * private var size:uint           = 80;
 * private var bgColor:uint       = 0xFFCC00;
 * private var borderColor:uint  = 0x666666;
 * private var borderSize:uint   = 0;
 * private var cornerRadius:uint = 9;
 * private var gutter:uint       = 5;
 *
 *   public function ShapeExample() {
 * doDrawCircle();
 * doDrawRoundRect();
 * doDrawRect();
 * refreshLayout();
 * }
 *
 *   private function refreshLayout():void {
 * var ln:uint = numChildren;
 * var child:DisplayObject;
 * var lastChild:DisplayObject = getChildAt(0);
 * lastChild.x = gutter;
 * lastChild.y = gutter;
 * for (var i:uint = 1; i &lt; ln; i++) {
 * child = getChildAt(i);
 * child.x = gutter + lastChild.x + lastChild.width;
 * child.y = gutter;
 * lastChild = child;
 * }
 * }
 *
 *   private function doDrawCircle():void {
 * var child:Shape = new Shape();
 * var halfSize:uint = Math.round(size/2);
 * child.graphics.beginFill(bgColor);
 * child.graphics.lineStyle(borderSize, borderColor);
 * child.graphics.drawCircle(halfSize, halfSize, halfSize);
 * child.graphics.endFill();
 * addChild(child);
 * }
 *
 *   private function doDrawRoundRect():void {
 * var child:Shape = new Shape();
 * child.graphics.beginFill(bgColor);
 * child.graphics.lineStyle(borderSize, borderColor);
 * child.graphics.drawRoundRect(0, 0, size, size, cornerRadius);
 * child.graphics.endFill();
 * addChild(child);
 * }
 *
 *   private function doDrawRect():void {
 * var child:Shape = new Shape();
 * child.graphics.beginFill(bgColor);
 * child.graphics.lineStyle(borderSize, borderColor);
 * child.graphics.drawRect(0, 0, size, size);
 * child.graphics.endFill();
 * addChild(child);
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

using namespace flash::display;

namespace flash
{
    namespace display
    {
        class Shape : public DisplayObject
        {
            /**
             * Specifies the Graphics object belonging to this Shape object, where vector
             * drawing commands can occur.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::display::Graphics *graphics();

            /**
             * Creates a new Shape object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            Shape();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_SHAPE_AS
#endif // __cplusplus

