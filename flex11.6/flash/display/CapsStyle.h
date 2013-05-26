#if !defined(FLEX11_6_FLASH_DISPLAY_CAPSSTYLE_AS)
#define FLEX11_6_FLASH_DISPLAY_CAPSSTYLE_AS
#if defined(__cplusplus)


/**
 * The CapsStyle class is an enumeration of constant values that specify the caps style to use in drawing lines.
 * The constants are provided for use as values in the <codeph class="+ topic/ph pr-d/codeph ">caps</codeph> parameter of the
 * <codeph class="+ topic/ph pr-d/codeph ">flash.display.Graphics.lineStyle()</codeph> method. You can specify the following three types of caps:
 *
 *   <p class="- topic/p "><adobeimage alt="The three types of caps: NONE, ROUND, and SQUARE." href="../../images/linecap.jpg" placement="inline" class="+ topic/image adobe-d/adobeimage " /></p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">CapsStyleExample</codeph> class to draw three
 * parallel lines, each with a different line cap style.
 * <ol class="- topic/ol "><li class="- topic/li ">The properties of each line are set as follows:
 * <ul class="- topic/ul "><li class="- topic/li ">The line length is set to 80 pixels.</li><li class="- topic/li ">The border color is set to orange.</li><li class="- topic/li ">The border size is set to 30 pixels. </li><li class="- topic/li ">The highlight color is set to gray. </li><li class="- topic/li ">The highlight size is set to 0 pixels.</li><li class="- topic/li ">The alpha is set to 1, making it solid.</li><li class="- topic/li ">The pixel hinting is set to false (strokes not hinted to full pixels).</li><li class="- topic/li ">The line scale mode is set to normal, which scales the thickness. </li><li class="- topic/li ">The joint style of the border caps are set to <codeph class="+ topic/ph pr-d/codeph ">MITER</codeph>.</li><li class="- topic/li ">The miter limit is set to 1, indicating that the miter is cut off close to the line.</li></ul></li><li class="- topic/li ">The class constructor creates three vertical lines, starting at <i class="+ topic/ph hi-d/i ">x = 0, y = 0</i> by calling
 * the <codeph class="+ topic/ph pr-d/codeph ">drawLine()</codeph> method three times using the three different line cap styles (none,
 * round, and square).  Each of the three calls to the <codeph class="+ topic/ph pr-d/codeph ">drawLine()</codeph> method uses the cap style and
 * properties listed previously to draw a vertical line and associated line highlight. The calls
 * first create a new <codeph class="+ topic/ph pr-d/codeph ">child</codeph> Shape object and then use methods of the Graphics
 * class to set the line style and draw the lines and highlights. Each instance of <codeph class="+ topic/ph pr-d/codeph ">child</codeph>
 * is added to the display list and drawn on the stage.</li><li class="- topic/li ">The connected line segments are redrawn by using the <codeph class="+ topic/ph pr-d/codeph ">refreshLayout()</codeph> method at <i class="+ topic/ph hi-d/i ">y = 80</i>
 * pixels and starting at <i class="+ topic/ph hi-d/i ">x = 80</i> pixels, with a 25-pixel separation between the line segments.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.CapsStyle;
 * import flash.display.DisplayObject;
 * import flash.display.Graphics;
 * import flash.display.JointStyle;
 * import flash.display.LineScaleMode;
 * import flash.display.Shape;
 * import flash.display.Sprite;
 *
 *   public class CapsStyleExample extends Sprite {
 * private var lineLength:uint            = 80;
 * private var borderColor:uint           = 0xFFCC00;
 * private var borderSize:uint            = 30;
 * private var highlightColor:uint        = 0x666666;
 * private var highlightSize:uint         = 0;
 * private var gutter:uint                = 25;
 * private var borderAlpha:uint           = 1;
 * private var borderPixelHinting:Boolean = false;
 * private var borderScaleMode:String     = LineScaleMode.NORMAL;
 * private var borderJointStyle:String    = JointStyle.MITER;
 * private var borderMiterLimit:uint      = 1;
 *
 *   public function CapsStyleExample() {
 * drawLine(CapsStyle.NONE);
 * drawLine(CapsStyle.ROUND);
 * drawLine(CapsStyle.SQUARE);
 * refreshLayout();
 * }
 *
 *   private function drawLine(capsStyle:String):void {
 * var child:Shape = new Shape();
 * child.graphics.lineStyle(borderSize,
 * borderColor,
 * borderAlpha,
 * borderPixelHinting,
 * borderScaleMode,
 * capsStyle,
 * borderJointStyle,
 * borderMiterLimit);
 * child.graphics.lineTo(0, 0);
 * child.graphics.lineTo(0, lineLength);
 * child.graphics.endFill();
 *
 *   child.graphics.moveTo(0, 0);
 * child.graphics.lineStyle(highlightSize, highlightColor);
 * child.graphics.lineTo(0, 0);
 * child.graphics.lineTo(0, lineLength);
 *
 *   addChild(child);
 * }
 *
 *   private function refreshLayout():void {
 * var ln:uint = numChildren;
 * var child:DisplayObject;
 * var lastChild:DisplayObject = getChildAt(0);
 * lastChild.x = lineLength;
 * lastChild.y = lineLength;
 * for (var i:uint = 1; i &lt; ln; i++) {
 * child = getChildAt(i);
 * child.x = gutter + lastChild.x + lastChild.width;
 * child.y = lineLength;
 * lastChild = child;
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 */

#include "flex11.6.h"



namespace flash
{
    namespace display
    {
        class CapsStyle : public Object
        {
            /**
             * Used to specify round caps in the caps parameter of the
             * flash.display.Graphics.lineStyle() method.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string ROUND;

            /**
             * Used to specify no caps in the caps parameter of the
             * flash.display.Graphics.lineStyle() method.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string NONE;

            /**
             * Used to specify square caps in the caps parameter of the
             * flash.display.Graphics.lineStyle() method.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string SQUARE;

        public:
            CapsStyle();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_CAPSSTYLE_AS
#endif // __cplusplus

