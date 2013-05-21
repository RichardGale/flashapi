

    /**
     * The JointStyle class is an enumeration of constant values that specify the joint style to use in drawing lines.
     * These constants are provided for use as values in the <codeph class="+ topic/ph pr-d/codeph ">joints</codeph> parameter of the
     * <codeph class="+ topic/ph pr-d/codeph ">flash.display.Graphics.lineStyle()</codeph> method. The method supports three types of joints: 
     * miter, round, and bevel, as the following example shows:
     * 
     *   <p class="- topic/p "><adobeimage alt="MITER, ROUND, and BEVEL" href="../../images/linejoin.jpg" placement="inline" class="+ topic/image adobe-d/adobeimage " /></p>
     * 
     *   EXAMPLE:
     * 
     *   The following example uses the JointStyleExample class to show the result
     * of three different joint styles applied to three sets of joined lines. This task is accomplished by performing
     * the following steps:
     * <ol class="- topic/ol "><li class="- topic/li ">The properties of each line are set as follows:
     * <ul class="- topic/ul "><li class="- topic/li ">The line length is set to 80 pixels.</li><li class="- topic/li ">The border color is set to orange.</li><li class="- topic/li ">The border size is set to 30 pixels.</li><li class="- topic/li ">The highlight color is set to gray.</li><li class="- topic/li ">The highlight size is set to zero pixels.</li><li class="- topic/li ">The alpha is set to 1, making it solid.</li><li class="- topic/li ">The pixel hinting is set to false (strokes not hinted to full pixels).</li><li class="- topic/li ">The line scale mode is set to normal, which scales the thickness.</li><li class="- topic/li ">The border caps and miter limit are declared but not set, so the default values are used.</li></ul></li><li class="- topic/li ">The class constructor creates three sets of two connected line segments. The segments start at x = 0, y = 0
     * by calling the <codeph class="+ topic/ph pr-d/codeph ">doDrawCorner()</codeph> method three times using the three joint styles (miter,
     * round, and bevel).  Each of the three calls to <codeph class="+ topic/ph pr-d/codeph ">doDrawCorner()</codeph> uses the joint style and
     * properties previously listed to draw two connected line segments and associated line highlights. This is done by
     * first creating a new Shape object <codeph class="+ topic/ph pr-d/codeph ">child</codeph> and then using methods of the Graphics
     * class to set the line style and draw the lines and highlights.  Each instance of <codeph class="+ topic/ph pr-d/codeph ">child</codeph>
     * is added to the display list and promptly drawn on the stage.</li><li class="- topic/li ">The connected line segments are then redrawn by using the <codeph class="+ topic/ph pr-d/codeph ">refreshLayout()</codeph> method 
     * at y = 80 pixels and starting at x = 80 pixels, with a 25-pixel separation between the line segments.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * import flash.display.DisplayObject;
     * import flash.display.Graphics;
     * import flash.display.JointStyle;
     * import flash.display.LineScaleMode;
     * import flash.display.Shape;
     * import flash.display.Sprite;
     * 
     *   public class JointStyleExample extends Sprite {
     * private var size:uint                  = 80;
     * private var borderColor:uint           = 0xFFCC00;
     * private var borderSize:uint            = 30;
     * private var highlightColor:uint        = 0x666666;
     * private var highlightSize:uint         = 0;
     * private var gutter:uint                = 25;
     * private var borderAlpha:uint           = 1;
     * private var borderPixelHinting:Boolean = false;
     * private var borderScaleMode:String     = LineScaleMode.NORMAL;
     * private var borderCaps:String;
     * private var borderMiterLimit:uint;
     * 
     *   public function JointStyleExample() {
     * doDrawCorner(JointStyle.MITER);
     * doDrawCorner(JointStyle.ROUND);
     * doDrawCorner(JointStyle.BEVEL);
     * refreshLayout();
     * }
     * 
     *   private function doDrawCorner(jointStyle:String):void {
     * var halfSize:uint = Math.round(size / 2);
     * var child:Shape = new Shape();
     * child.graphics.lineStyle(borderSize,
     * borderColor,
     * borderAlpha,
     * borderPixelHinting,
     * borderScaleMode,
     * borderCaps,
     * jointStyle,
     * borderMiterLimit);
     * child.graphics.lineTo(0, 0);
     * child.graphics.lineTo(size, 0);
     * child.graphics.lineTo(halfSize, size);
     * child.graphics.endFill();
     * 
     *   child.graphics.moveTo(0, 0);
     * child.graphics.lineStyle(highlightSize, highlightColor);
     * child.graphics.lineTo(0, 0);
     * child.graphics.lineTo(size, 0);
     * child.graphics.lineTo(halfSize, size);
     * 
     *   addChild(child);
     * }
     * 
     *   private function refreshLayout():void {
     * var ln:uint = numChildren;
     * var child:DisplayObject;
     * var lastChild:DisplayObject = getChildAt(0);
     * lastChild.x = size;
     * lastChild.y = size;
     * for (var i:uint = 1; i &lt; ln; i++) {
     * child = getChildAt(i);
     * child.x = gutter + lastChild.x + lastChild.width;
     * child.y = size;
     * lastChild = child;
     * }
     * }
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     */


namespace flash {
namespace display {


        /**
         * Specifies round joints in the joints parameter of the
         * flash.display.Graphics.lineStyle() method.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string JointStyle::ROUND="round";

        /**
         * Specifies beveled joints in the joints parameter of the
         * flash.display.Graphics.lineStyle() method.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string JointStyle::BEVEL="bevel";

        /**
         * Specifies mitered joints in the joints parameter of the
         * flash.display.Graphics.lineStyle() method.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string JointStyle::MITER="miter";

        JointStyle::JointStyle();
}
}

