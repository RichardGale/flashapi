#if !defined(FLEX11_6_FLASH_DISPLAY_GRAPHICS_AS)
#define FLEX11_6_FLASH_DISPLAY_GRAPHICS_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace geom
    {
        class Matrix;
    }
}
namespace flash
{
    namespace display
    {
        class BitmapData;
    }
}
namespace flash
{
    namespace display
    {
        class Shader;
    }
}

namespace flash
{
    namespace display
    {
        class IGraphicsPath;
    }
}
namespace flash
{
    namespace display
    {
        class IGraphicsFill;
    }
}
namespace flash
{
    namespace display
    {
        class IGraphicsStroke;
    }
}
namespace flash
{
    namespace display
    {
        class IGraphicsData;
    }
}

/**
 * The Graphics class contains a set of methods that you can use to create a vector shape.
 * Display objects that support drawing include Sprite and Shape objects.
 * Each of these classes includes a <codeph class="+ topic/ph pr-d/codeph ">graphics</codeph> property that is a Graphics object.
 * The following are among those helper functions provided for ease of use:
 * <codeph class="+ topic/ph pr-d/codeph ">drawRect()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">drawRoundRect()</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">drawCircle()</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">drawEllipse()</codeph>.
 *
 *   <p class="- topic/p ">You cannot create a Graphics object directly from ActionScript code.
 * If you call <codeph class="+ topic/ph pr-d/codeph ">new Graphics()</codeph>, an exception is thrown.</p><p class="- topic/p ">The Graphics class is final; it cannot be subclassed.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the GraphicsExample class to draw a circle,
 * a rounded rectangle, and a square.  This task is accomplished by using the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">Declare a <codeph class="+ topic/ph pr-d/codeph ">size</codeph> property for later use in determining the size of each shape.</li><li class="- topic/li ">Declare properties that set the background color to orange, the border color to
 * dark gray, the border size to 0 pixels, the corner radius to 9 pixels, and set the space
 * between the stage edge and the other objects to be 5 pixels.</li><li class="- topic/li ">Use the properties declared in the preceding steps along with the built in methods of the
 * Graphics class to draw the circle, rounded rectangle, and square at coordinates x = 0, y = 0.</li><li class="- topic/li ">Redraw each of the shapes along the top of the stage, starting at x = 5, y = 5, with
 * a 5-pixel spacing between shapes.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.DisplayObject;
 * import flash.display.Graphics;
 * import flash.display.Shape;
 * import flash.display.Sprite;
 *
 *   public class GraphicsExample extends Sprite {
 * private var size:uint         = 80;
 * private var bgColor:uint      = 0xFFCC00;
 * private var borderColor:uint  = 0x666666;
 * private var borderSize:uint   = 0;
 * private var cornerRadius:uint = 9;
 * private var gutter:uint       = 5;
 *
 *   public function GraphicsExample() {
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
 * var halfSize:uint = Math.round(size / 2);
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
using namespace flash::geom;

namespace flash
{
    namespace display
    {
        class Graphics : public Object
        {
            /**
             * Clears the graphics that were drawn to this Graphics object, and resets fill and
             * line style settings.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     clear();

            /**
             * Specifies a simple one-color fill that subsequent calls to other
             * Graphics methods (such as lineTo() or drawCircle()) use when drawing.
             * The fill remains in effect until you call the beginFill(),
             * beginBitmapFill(), beginGradientFill(), or beginShaderFill() method.
             * Calling the clear() method clears the fill.
             *
             *   The application renders the fill whenever three or more points are drawn, or when
             * the endFill() method is called.
             * @param   color   The color of the fill (0xRRGGBB).
             * @param   alpha   The alpha value of the fill (0.0 to 1.0).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     beginFill(unsigned int color, float alpha =1);

            /**
             * Specifies a gradient fill used by subsequent calls to other
             * Graphics methods (such as lineTo() or drawCircle()) for the object.
             * The fill remains in effect until you call the beginFill(),
             * beginBitmapFill(), beginGradientFill(), or beginShaderFill() method.
             * Calling the clear() method clears the fill.
             *
             *   The application renders the fill whenever three or more points are drawn, or when
             * the endFill() method is called.
             * @param   type    A value from the GradientType class that
             *   specifies which gradient type to use: GradientType.LINEAR or
             *   GradientType.RADIAL.
             * @param   colors  An array of RGB hexadecimal color values used in the gradient; for example,
             *   red is 0xFF0000, blue is 0x0000FF, and so on. You can specify up to 15 colors.
             *   For each color, specify a corresponding value in the alphas and ratios parameters.
             * @param   alphas  An array of alpha values for the corresponding colors in the colors array;
             *   valid values are 0 to 1. If the value is less than 0, the default is 0. If the value is
             *   greater than 1, the default is 1.
             * @param   ratios  An array of color distribution ratios; valid values are 0-255. This value
             *   defines the percentage of the width where the color is sampled at 100%. The value 0 represents
             *   the left position in the gradient box, and 255 represents the right position in the
             *   gradient box.
             *
             *     Note: This value represents positions in the gradient box, not the
             *   coordinate space of the final gradient, which can be wider or thinner than the gradient box.
             *   Specify a value for each value in the colors parameter. For example, for a linear gradient that includes two colors, blue and green, the
             *   following example illustrates the placement of the colors in the gradient based on different values
             *   in the ratios array:ratiosGradient[0, 127][0, 255][127, 255]The values in the array must increase sequentially; for example,
             *   [0, 63, 127, 190, 255].
             * @param   matrix  A transformation matrix as defined by the
             *   flash.geom.Matrix class. The flash.geom.Matrix class includes a
             *   createGradientBox() method, which lets you conveniently set up
             *   the matrix for use with the beginGradientFill() method.
             * @param   spreadMethod    A value from the SpreadMethod class that
             *   specifies which spread method to use, either: SpreadMethod.PAD,
             *   SpreadMethod.REFLECT, or SpreadMethod.REPEAT.
             *
             *     For example, consider a simple linear gradient between two colors:
             *   <codeblock>
             *
             *     import flash.geom.*
             *   import flash.display.*
             *   var fillType:String = GradientType.LINEAR;
             *   var colors:Array = [0xFF0000, 0x0000FF];
             *   var alphas:Array = [1, 1];
             *   var ratios:Array = [0x00, 0xFF];
             *   var matr:Matrix = new Matrix();
             *   matr.createGradientBox(20, 20, 0, 0, 0);
             *   var spreadMethod:String = SpreadMethod.PAD;
             *   this.graphics.beginGradientFill(fillType, colors, alphas, ratios, matr, spreadMethod);
             *   this.graphics.drawRect(0,0,100,100);
             *
             *     </codeblock>
             *   This example uses SpreadMethod.PAD for the spread method, and
             *   the gradient fill looks like the following:If you use SpreadMethod.REFLECT for the spread method, the gradient fill
             *   looks like the following:If you use SpreadMethod.REPEAT for the spread method, the gradient fill
             *   looks like the following:
             * @param   interpolationMethod A value from the InterpolationMethod class that
             *   specifies which value to use: InterpolationMethod.LINEAR_RGB or
             *   InterpolationMethod.RGBFor example, consider a simple linear gradient between two colors (with the spreadMethod
             *   parameter set to SpreadMethod.REFLECT). The different interpolation methods affect
             *   the appearance as follows: InterpolationMethod.LINEAR_RGBInterpolationMethod.RGB
             * @param   focalPointRatio A number that controls the
             *   location of the focal point of the gradient. 0 means that the focal point is in the center. 1
             *   means that the focal point is at one border of the gradient circle. -1 means that the focal point
             *   is at the other border of the gradient circle. A value less than -1 or greater than
             *   1 is rounded to -1 or 1. For example, the following example
             *   shows a focalPointRatio set to 0.75:
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  ArgumentError If the type parameter is not valid.
             */
        public:
            void     beginGradientFill(std::string type, std::vector<void *> colors, std::vector<void *> alphas, std::vector<void *> ratios, Matrix *matrix=NULL, std::string spreadMethod="pad", std::string interpolationMethod="rgb", float focalPointRatio =0);

            /**
             * Fills a drawing area with a bitmap image. The bitmap can be repeated or tiled to fill
             * the area. The fill remains in effect until you call the beginFill(),
             * beginBitmapFill(), beginGradientFill(), or beginShaderFill() method.
             * Calling the clear() method clears the fill.
             *
             *   The application renders the fill whenever three or more points are drawn, or when
             * the endFill() method is called.
             * @param   bitmap  A transparent or opaque bitmap image that contains the bits to be displayed.
             * @param   matrix  A matrix object (of the flash.geom.Matrix class), which you can use to
             *   define transformations on the bitmap. For example, you can use the following matrix
             *   to rotate a bitmap by 45 degrees (pi/4 radians):
             *
             *     <codeblock>
             *
             *     matrix = new flash.geom.Matrix();
             *   matrix.rotate(Math.PI / 4);
             *
             *     </codeblock>
             * @param   repeat  If true, the bitmap image repeats in a tiled pattern. If
             *   false, the bitmap image does not repeat, and the edges of the bitmap are
             *   used for any fill area that extends beyond the bitmap.
             *
             *     For example, consider the following bitmap (a 20 x 20-pixel checkerboard pattern):When repeat is set to true (as in the following example), the bitmap fill
             *   repeats the bitmap:When repeat is set to false, the bitmap fill uses the edge
             *   pixels for the fill area outside the bitmap:
             * @param   smooth  If false, upscaled bitmap images are rendered by using a
             *   nearest-neighbor algorithm and look pixelated. If true, upscaled
             *   bitmap images are rendered by using a bilinear algorithm. Rendering by using the nearest
             *   neighbor algorithm is faster.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     beginBitmapFill(BitmapData *bitmap, Matrix *matrix=NULL, bool repeat   =true, bool smooth   =false);

            /**
             * Specifies a shader fill used by subsequent calls to other Graphics methods
             * (such as lineTo() or drawCircle()) for the object.
             * The fill remains in effect until you call the beginFill(),
             * beginBitmapFill(), beginGradientFill(), or beginShaderFill() method.
             * Calling the clear() method clears the fill.
             *
             *   The application renders the fill whenever three or more points are drawn, or when
             * the endFill() method is called.Shader fills are not supported under GPU rendering; filled areas will be colored cyan.
             * @param   shader  The shader to use for the fill. This Shader instance is not required to
             *   specify an image input. However, if an image input is specified in the shader, the input
             *   must be provided manually. To specify the input, set the input property
             *   of the corresponding ShaderInput
             *   property of the Shader.data property.
             *
             *     When you pass a Shader instance as an argument the shader is copied internally. The
             *   drawing fill operation uses that internal copy, not a reference to the original shader. Any changes
             *   made to the shader, such as changing a parameter value, input, or bytecode, are not applied
             *   to the copied shader that's used for the fill.
             * @param   matrix  A matrix object (of the flash.geom.Matrix class), which you can use to
             *   define transformations on the shader. For example, you can use the following matrix
             *   to rotate a shader by 45 degrees (pi/4 radians):
             *
             *     <codeblock>
             *
             *     matrix = new flash.geom.Matrix();
             *   matrix.rotate(Math.PI / 4);
             *
             *     </codeblock>
             *   The coordinates received in the shader are based on the matrix that is specified
             *   for the matrix parameter. For a default (null) matrix, the
             *   coordinates in the shader are local pixel coordinates which can be used to sample an
             *   input.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @throws  ArgumentError When the shader output type is not compatible with this operation
             *   (the shader must specify a pixel3 or pixel4
             *   output).
             * @throws  ArgumentError When the shader specifies an image input that isn't provided.
             * @throws  ArgumentError When a ByteArray or Vector.<Number> instance is used as
             *   an input and the width
             *   and height properties aren't specified for the
             *   ShaderInput, or the specified values don't match the amount of
             *   data in the input object. See the ShaderInput.input
             *   property for more information.
             */
        public:
            void     beginShaderFill(Shader *shader, Matrix *matrix=NULL);

        public:
            Graphics();

            /**
             * Specifies a gradient to use for the stroke when drawing lines.
             *
             *   The gradient line style is used for subsequent calls to Graphics
             * methods such as the lineTo() methods or the drawCircle() method.
             * The line style remains in effect until you call the lineStyle() or
             * lineBitmapStyle() methods, or the lineGradientStyle() method
             * again with different parameters. You can call the lineGradientStyle() method in the middle of drawing a path
             * to specify different styles for different line segments within a path. Call the lineStyle() method before you call the
             * lineGradientStyle() method to enable a stroke, or else the value of the line style
             * is undefined.Calls to the clear() method set the line style back to undefined.
             * @param   type    A value from the GradientType class that
             *   specifies which gradient type to use, either GradientType.LINEAR or GradientType.RADIAL.
             * @param   colors  An array of RGB hex color values to be used in the gradient (for example,
             *   red is 0xFF0000, blue is 0x0000FF, and so on).
             * @param   alphas  An array of alpha values for the corresponding colors in the colors array;
             *   valid values are 0 to 1. If the value is less than 0, the default is 0. If the value is
             *   greater than 1, the default is 1.
             * @param   ratios  An array of color distribution ratios; valid values are from 0 to 255. This value
             *   defines the percentage of the width where the color is sampled at 100%. The value 0 represents
             *   the left position in the gradient box, and 255 represents the right position in the
             *   gradient box. This value represents positions in the gradient box, not the
             *   coordinate space of the final gradient, which can be wider or thinner than the gradient box.
             *   Specify a value for each value in the colors parameter.
             *
             *     For example, for a linear gradient that includes two colors, blue and green, the
             *   following figure illustrates the placement of the colors in the gradient based on different values
             *   in the ratios array:ratiosGradient[0, 127][0, 255][127, 255]The values in the array must increase, sequentially; for example,
             *   [0, 63, 127, 190, 255].
             * @param   matrix  A transformation matrix as defined by the
             *   flash.geom.Matrix class. The flash.geom.Matrix class includes a
             *   createGradientBox() method, which lets you conveniently set up
             *   the matrix for use with the lineGradientStyle() method.
             * @param   spreadMethod    A value from the SpreadMethod class that
             *   specifies which spread method to use:
             *
             *     SpreadMethod.PADSpreadMethod.REFLECTSpreadMethod.REPEAT
             * @param   interpolationMethod A value from the InterpolationMethod class that
             *   specifies which value to use. For example, consider a simple linear gradient between two colors (with the spreadMethod
             *   parameter set to SpreadMethod.REFLECT). The different interpolation methods affect
             *   the appearance as follows:
             *
             *     InterpolationMethod.LINEAR_RGBInterpolationMethod.RGB
             * @param   focalPointRatio A number that controls the location of the focal
             *   point of the gradient. The value 0 means the focal point is in the center. The value 1 means the focal
             *   point is at one border of the gradient circle. The value -1 means that the focal point is
             *   at the other border of the gradient circle. Values less than -1 or greater than 1 are
             *   rounded to -1 or 1. The following image shows a gradient with a
             *   focalPointRatio of -0.75:
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            void     lineGradientStyle(std::string type, std::vector<void *> colors, std::vector<void *> alphas, std::vector<void *> ratios, Matrix *matrix=NULL, std::string spreadMethod="pad", std::string interpolationMethod="rgb", float focalPointRatio =0);

            /**
             * Specifies a line style used for subsequent calls to
             * Graphics methods such as the lineTo() method or the drawCircle() method.
             * The line style remains in effect until you call the lineGradientStyle()
             * method, the lineBitmapStyle() method, or the lineStyle() method with different parameters.
             *
             *   You can call the lineStyle() method in the middle of drawing a path to specify different
             * styles for different line segments within the path.Note: Calls to the clear() method set the line style back to
             * undefined.Note: Flash Lite 4 supports only the first three parameters (thickness, color, and alpha).
             * @param   thickness   An integer that indicates the thickness of the line in
             *   points; valid values are 0-255. If a number is not specified, or if the
             *   parameter is undefined, a line is not drawn. If a value of less than 0 is passed,
             *   the default is 0. The value 0 indicates hairline thickness; the maximum thickness
             *   is 255. If a value greater than 255 is passed, the default is 255.
             * @param   color   A hexadecimal color value of the line; for example, red is 0xFF0000, blue is
             *   0x0000FF, and so on. If a value is not indicated, the default is 0x000000 (black). Optional.
             * @param   alpha   A number that indicates the alpha value of the color of the line;
             *   valid values are 0 to 1. If a value is not indicated, the default is 1 (solid). If
             *   the value is less than 0, the default is 0. If the value is greater than 1, the default is 1.
             * @param   pixelHinting    (Not supported in Flash Lite 4) A Boolean value that specifies whether to hint strokes
             *   to full pixels. This affects both the position of anchors of a curve and the line stroke size
             *   itself. With pixelHinting set to true, line widths are adjusted
             *   to full pixel widths. With pixelHinting set to false, disjoints can
             *   appear for curves and straight lines. For example, the following illustrations show how
             *   Flash Player or Adobe AIR renders two rounded rectangles that are identical, except that the
             *   pixelHinting parameter used in the lineStyle() method is set
             *   differently (the images are scaled by 200%, to emphasize the difference):
             *
             *     If a value is not supplied, the line does not use pixel hinting.
             * @param   scaleMode   (Not supported in Flash Lite 4) A value from the LineScaleMode class that
             *   specifies which scale mode to use:
             *
             *     LineScaleMode.NORMAL   Always scale the line thickness when the object is scaled
             *   (the default).
             *   LineScaleMode.NONE   Never scale the line thickness.
             *   LineScaleMode.VERTICAL   Do not scale the line thickness if the object is scaled vertically
             *   only. For example, consider the following circles, drawn with a one-pixel line, and each with the
             *   scaleMode parameter set to LineScaleMode.VERTICAL. The circle on the left
             *   is scaled vertically only, and the circle on the right is scaled both vertically and horizontally:
             *
             *     LineScaleMode.HORIZONTAL   Do not scale the line thickness if the object is scaled horizontally
             *   only. For example, consider the following circles, drawn with a one-pixel line, and each with the
             *   scaleMode parameter set to LineScaleMode.HORIZONTAL. The circle on the left
             *   is scaled horizontally only, and the circle on the right is scaled both vertically and horizontally:
             * @param   caps    (Not supported in Flash Lite 4) A value from the CapsStyle class that specifies the type of caps at the end
             *   of lines. Valid values are: CapsStyle.NONE, CapsStyle.ROUND, and CapsStyle.SQUARE.
             *   If a value is not indicated, Flash uses round caps.
             *   For example, the following illustrations show the different capsStyle
             *   settings. For each setting, the illustration shows a blue line with a thickness of 30 (for
             *   which the capsStyle applies), and a superimposed black line with a thickness of 1
             *   (for which no capsStyle applies):
             * @param   joints  (Not supported in Flash Lite 4) A value from the JointStyle class that specifies the type of joint appearance
             *   used at angles. Valid
             *   values are: JointStyle.BEVEL, JointStyle.MITER, and JointStyle.ROUND.
             *   If a value is not indicated, Flash uses round joints.
             *
             *     For example, the following illustrations show the different joints
             *   settings. For each setting, the illustration shows an angled blue line with a thickness of
             *   30 (for which the jointStyle applies), and a superimposed angled black line with a
             *   thickness of 1 (for which no jointStyle applies):
             *   Note: For joints set to JointStyle.MITER,
             *   you can use the miterLimit parameter to limit the length of the miter.
             * @param   miterLimit  (Not supported in Flash Lite 4) A number that indicates the limit at which a miter is cut off.
             *   Valid values range from 1 to 255 (and values outside that range are rounded to 1 or 255).
             *   This value is only used if the jointStyle
             *   is set to "miter". The
             *   miterLimit value represents the length that a miter can extend beyond the point
             *   at which the lines meet to form a joint. The value expresses a factor of the line
             *   thickness. For example, with a miterLimit factor of 2.5 and a
             *   thickness of 10 pixels, the miter is cut off at 25 pixels.
             *
             *     For example, consider the following angled lines, each drawn with a thickness
             *   of 20, but with miterLimit set to 1, 2, and 4. Superimposed are black reference
             *   lines showing the meeting points of the joints:Notice that a given miterLimit value has a specific maximum angle
             *   for which the miter is cut off. The following table lists some examples:miterLimit value:Angles smaller than this are cut off:1.41490 degrees260 degrees430 degrees815 degrees
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following code draws a triangle with a 5-pixel, solid magenta line with
             *   no fill, with pixel hinting, no stroke scaling, no caps, and miter joints with
             *   <code>miterLimit</code> set to 1:
             *
             *     <listing>
             *   this.createEmptyMovieClip("triangle_mc", this.getNextHighestDepth());
             *   triangle_mc.lineStyle(5, 0xff00ff, 100, true, "none", "round", "miter", 1);
             *   triangle_mc.moveTo(200, 200);
             *   triangle_mc.lineTo(300, 300);
             *   triangle_mc.lineTo(100, 300);
             *   triangle_mc.lineTo(200, 200);
             *   </listing>
             */
        public:
            void     lineStyle(float thickness =NULL, unsigned int color=0, float alpha =1, bool pixelHinting   =false, std::string scaleMode="normal", std::string caps="", std::string joints="", float miterLimit =3);

            /**
             * Draws a rectangle. Set the line style, fill, or both before
             * you call the drawRect() method, by calling the linestyle(),
             * lineGradientStyle(), beginFill(), beginGradientFill(),
             * or beginBitmapFill() method.
             * @param   x   A number indicating the horizontal position relative to the
             *   registration point of the parent display object (in pixels).
             * @param   y   A number indicating the vertical position relative to the
             *   registration point of the parent display object (in pixels).
             * @param   width   The width of the rectangle (in pixels).
             * @param   height  The height of the rectangle (in pixels).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  ArgumentError If the width or height parameters
             *   are not a number (Number.NaN).
             */
        public:
            void     drawRect(float x, float y, float width, float height);

            /**
             * Draws a rounded rectangle. Set the line style, fill, or both before
             * you call the drawRoundRect() method, by calling the linestyle(),
             * lineGradientStyle(), beginFill(), beginGradientFill(), or
             * beginBitmapFill() method.
             * @param   x   A number indicating the horizontal position relative to the
             *   registration point of the parent display object (in pixels).
             * @param   y   A number indicating the vertical position relative to the
             *   registration point of the parent display object (in pixels).
             * @param   width   The width of the round rectangle (in pixels).
             * @param   height  The height of the round rectangle (in pixels).
             * @param   ellipseWidth    The width of the ellipse used to draw the rounded corners (in pixels).
             * @param   ellipseHeight   The height of the ellipse used to draw the rounded corners (in pixels).
             *   Optional; if no value is specified, the default value matches that provided for the
             *   ellipseWidth parameter.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  ArgumentError If the width, height, ellipseWidth
             *   or ellipseHeight parameters are not a number (Number.NaN).
             */
        public:
            void     drawRoundRect(float x, float y, float width, float height, float ellipseWidth, float ellipseHeight =NULL);

        public:
            void     drawRoundRectComplex(float x, float y, float width, float height, float topLeftRadius, float topRightRadius, float bottomLeftRadius, float bottomRightRadius);

            /**
             * Draws a circle. Set the line style, fill, or both before
             * you call the drawCircle() method, by calling the linestyle(),
             * lineGradientStyle(), beginFill(), beginGradientFill(),
             * or beginBitmapFill() method.
             * @param   x   The x location of the center of the circle relative to the
             *   registration point of the parent display object (in pixels).
             * @param   y   The y location of the center of the circle relative to the
             *   registration point of the parent display object (in pixels).
             * @param   radius  The radius of the circle (in pixels).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     drawCircle(float x, float y, float radius);

            /**
             * Draws an ellipse. Set the line style, fill, or both before
             * you call the drawEllipse() method, by calling the linestyle(),
             * lineGradientStyle(), beginFill(), beginGradientFill(),
             * or beginBitmapFill() method.
             * @param   x   The x location of the top-left of the bounding-box of the ellipse relative to the
             *   registration point of the parent display object (in pixels).
             * @param   y   The y location of the top left of the bounding-box of the ellipse relative to the
             *   registration point of the parent display object (in pixels).
             * @param   width   The width of the ellipse (in pixels).
             * @param   height  The height of the ellipse (in pixels).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     drawEllipse(float x, float y, float width, float height);

            /**
             * Moves the current drawing position to (x, y). If any of the parameters
             * are missing, this method fails and the current drawing position is not changed.
             * @param   x   A number that indicates the horizontal position relative to the
             *   registration point of the parent display object (in pixels).
             * @param   y   A number that indicates the vertical position relative to the
             *   registration point of the parent display object (in pixels).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example draws a triangle with a 5-pixel, solid magenta line and a
             *   partially transparent blue fill:
             *
             *     <listing>
             *   this.createEmptyMovieClip("triangle_mc", 1);
             *   triangle_mc.beginFill(0x0000FF, 30);
             *   triangle_mc.lineStyle(5, 0xFF00FF, 100);
             *   triangle_mc.moveTo(200, 200);
             *   triangle_mc.lineTo(300, 300);
             *   triangle_mc.lineTo(100, 300);
             *   triangle_mc.lineTo(200, 200);
             *   triangle_mc.endFill();
             *   </listing>
             */
        public:
            void     moveTo(float x, float y);

            /**
             * Draws a line using the current line style from the current drawing position to (x, y);
             * the current drawing position is then set to (x, y).
             * If the display object in which you are drawing contains content that was created with
             * the Flash drawing tools, calls to the lineTo() method are drawn underneath the content. If
             * you call lineTo() before any calls to the moveTo() method, the
             * default position for the current drawing is (0, 0). If any of the parameters are missing, this
             * method fails and the current drawing position is not changed.
             * @param   x   A number that indicates the horizontal position relative to the
             *   registration point of the parent display object (in pixels).
             * @param   y   A number that indicates the vertical position relative to the
             *   registration point of the parent display object (in pixels).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example draws a triangle with a 5-pixel, solid magenta line and a
             *   partially transparent blue fill.
             *
             *     <listing>
             *   this.createEmptyMovieClip("triangle_mc", 1);
             *   triangle_mc.beginFill(0x0000FF, 30);
             *   triangle_mc.lineStyle(5, 0xFF00FF, 100);
             *   triangle_mc.moveTo(200, 200);
             *   triangle_mc.lineTo(300, 300);
             *   triangle_mc.lineTo(100, 300);
             *   triangle_mc.lineTo(200, 200);
             *   triangle_mc.endFill();
             *   </listing>
             */
        public:
            void     lineTo(float x, float y);

            /**
             * Draws a curve using the current line style from the current drawing position
             * to (anchorX, anchorY) and using the control point that (controlX,
             * controlY) specifies. The current drawing position is then set to
             * (anchorX, anchorY). If the movie clip in which you are
             * drawing contains content created with the Flash drawing tools, calls to the
             * curveTo() method are drawn underneath this content. If you call the
             * curveTo() method before any calls to the moveTo() method,
             * the default of the current drawing position is (0, 0). If any of the parameters are
             * missing, this method fails and the current drawing position is not changed.
             *
             *   The curve drawn is a quadratic Bezier curve. Quadratic Bezier curves
             * consist of two anchor points and one control point. The curve interpolates the two anchor
             * points and curves toward the control point.
             * @param   controlX    A number that specifies the horizontal position of the control
             *   point relative to the registration point of the parent display object.
             * @param   controlY    A number that specifies the vertical position of the control
             *   point relative to the registration point of the parent display object.
             * @param   anchorX A number that specifies the horizontal position of the next anchor
             *   point relative to the registration point of the parent display object.
             * @param   anchorY A number that specifies the vertical position of the next anchor
             *   point relative to the registration point of the parent display object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     curveTo(float controlX, float controlY, float anchorX, float anchorY);

        public:
            void     cubicCurveTo(float controlX1, float controlY1, float controlX2, float controlY2, float anchorX, float anchorY);

            /**
             * Applies a fill to the lines and curves that were added since the last call to the
             * beginFill(), beginGradientFill(), or
             * beginBitmapFill() method. Flash uses the fill that was specified in the previous
             * call to the beginFill(), beginGradientFill(), or beginBitmapFill()
             * method. If the current drawing position does not equal the previous position specified in a
             * moveTo() method and a fill is defined, the path is closed with a line and then
             * filled.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates a square with red fill on the Stage:
             *
             *     <listing>
             *   this.createEmptyMovieClip("square_mc", this.getNextHighestDepth());
             *   square_mc.beginFill(0xFF0000);
             *   square_mc.moveTo(10, 10);
             *   square_mc.lineTo(100, 10);
             *   square_mc.lineTo(100, 100);
             *   square_mc.lineTo(10, 100);
             *   square_mc.lineTo(10, 10);
             *   square_mc.endFill();
             *   </listing>
             */
        public:
            void     endFill();

            /**
             * Copies all of drawing commands from the source Graphics object into the
             * calling Graphics object.
             * @param   sourceGraphics  The Graphics object from which to copy the drawing commands.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            void     copyFrom(Graphics *sourceGraphics);

            /**
             * Specifies a bitmap to use for the line stroke when drawing lines.
             *
             *   The bitmap line style is used for subsequent calls to Graphics
             * methods such as the lineTo() method or the drawCircle() method.
             * The line style remains in effect until you call the lineStyle() or
             * lineGradientStyle() methods, or the lineBitmapStyle() method
             * again with different parameters. You can call the lineBitmapStyle() method in the middle of drawing a path
             * to specify different styles for different line segments within a path. Call the lineStyle() method before you call the
             * lineBitmapStyle() method to enable a stroke, or else the value of the line style
             * is undefined.Calls to the clear() method set the line style back to undefined.
             * @param   bitmap  The bitmap to use for the line stroke.
             * @param   matrix  An optional transformation matrix as defined by the flash.geom.Matrix class.
             *   The matrix can be used to scale or otherwise manipulate the bitmap before
             *   applying it to the line style.
             * @param   repeat  Whether to repeat the bitmap in a tiled fashion.
             * @param   smooth  Whether smoothing should be applied to the bitmap.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            void     lineBitmapStyle(BitmapData *bitmap, Matrix *matrix=NULL, bool repeat   =true, bool smooth   =false);

            /**
             * Specifies a shader to use for the line stroke when drawing lines.
             *
             *   The shader line style is used for subsequent calls to Graphics
             * methods such as the lineTo() method or the drawCircle() method.
             * The line style remains in effect until you call the lineStyle() or
             * lineGradientStyle() methods, or the lineBitmapStyle() method
             * again with different parameters. You can call the lineShaderStyle() method in the middle of drawing a path
             * to specify different styles for different line segments within a path. Call the lineStyle() method before you call the
             * lineShaderStyle() method to enable a stroke, or else the value of the line style
             * is undefined.Calls to the clear() method set the line style back to undefined.
             * @param   shader  The shader to use for the line stroke.
             * @param   matrix  An optional transformation matrix as defined by the flash.geom.Matrix class.
             *   The matrix can be used to scale or otherwise manipulate the bitmap before
             *   applying it to the line style.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            void     lineShaderStyle(Shader *shader, Matrix *matrix=NULL);

            /**
             * Submits a series of commands for drawing. The drawPath() method uses vector arrays to consolidate
             * individual moveTo(), lineTo(), and curveTo() drawing commands
             * into a single call. The drawPath() method parameters combine drawing commands with x- and y-coordinate
             * value pairs and a drawing direction. The drawing commands are values from the GraphicsPathCommand class. The
             * x- and y-coordinate value pairs are Numbers in an array where each pair defines a coordinate location. The drawing
             * direction is a value from the GraphicsPathWinding class.
             *
             *   Generally, drawings render faster with drawPath() than with
             * a series of individual lineTo() and curveTo() methods.
             *
             *   The drawPath() method uses a uses a floating computation so rotation and scaling
             * of shapes is more accurate and gives better results. However, curves submitted using the
             * drawPath() method can have small sub-pixel alignment errors when used in conjunction
             * with the lineTo() and curveTo() methods.
             *
             *   The drawPath() method also uses slightly different rules for filling and drawing lines.
             * They are:
             * When a fill is applied to rendering a path:
             * A sub-path of less than 3 points is not rendered. (But note that the stroke rendering will
             * still occur, consistent with the rules for strokes below.)A sub-path that isn't closed (the end point is not equal to the begin point) is implicitly
             * closed.When a stroke is applied to rendering a path:
             * The sub-paths can be composed of any number of points.The sub-path is never implicitly closed.
             * @param   commands    A Vector of integers representing commands defined by the GraphicsPathCommand class. The
             *   GraphicsPathCommand class maps commands to numeric identifiers for this vector array.
             * @param   data    A Vector of Numbers where each pair of numbers is treated as a coordinate location (an x, y pair).
             *   The x- and y-coordinate value pairs are not Point objects; the data vector is
             *   a series of numbers where each group of two numbers represents a coordinate location.
             * @param   winding Specifies the winding rule using a value defined in the GraphicsPathWinding class.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            void     drawPath(std::vector<int> commands, std::vector<float> data, std::string winding="evenOdd");

            /**
             * Renders a set of triangles, typically to distort bitmaps and give them a three-dimensional appearance. The
             * drawTriangles() method maps either the current fill, or a bitmap fill, to the
             * triangle faces using a set of (u,v) coordinates.
             *
             *   Any type of fill can be used, but if the fill has a transform matrix that
             * transform matrix is ignored.
             *
             *   A uvtData parameter improves texture mapping when a bitmap fill is used.
             * @param   vertices    A Vector of Numbers where each pair of numbers is treated as a coordinate location (an x, y pair). The
             *   vertices parameter is required.
             * @param   indices A Vector of integers or indexes, where every three indexes define a triangle. If the indexes parameter
             *   is null then every three vertices (six x,y pairs in the vertices Vector) defines a triangle.
             *   Otherwise each index refers to a vertex, which is a pair of numbers in the vertices Vector.
             *   For example indexes[1] refers to (vertices[2], vertices[3]).
             *   The indexes parameter is optional, but indexes generally reduce the amount of data submitted
             *   and the amount of data computed.
             * @param   uvtData A Vector of normalized coordinates used to apply texture mapping.
             *   Each coordinate refers to a point on the bitmap used for the fill.
             *   You must have one UV or one UVT coordinate per vertex.
             *   In UV coordinates, (0,0) is the upper left of the bitmap, and (1,1) is the lower right of the bitmap.
             *   If the length of this vector is twice the length of the vertices vector then normalized
             *   coordinates are used without perspective correction. If the length of this vector is three times the length of the vertices vector then the
             *   third coordinate is interpreted as 't' (the distance from the eye to the texture in eye space).
             *   This helps the rendering engine correctly apply perspective when mapping textures in three dimensions.If the uvtData parameter is null, then normal fill rules (and any fill type) apply.
             * @param   culling Specifies whether to render triangles that face in a specified direction. This parameter prevents
             *   the rendering of triangles that cannot be seen in the current view.
             *   This parameter can be set to any value defined by the TriangleCulling class.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            void     drawTriangles(std::vector<float> vertices, std::vector<int> indices=std::vector<int>(), std::vector<float> uvtData=std::vector<float>(), std::string culling="none");

            /**
             * Submits a series of IGraphicsData instances for drawing. This method accepts a Vector containing objects
             * including paths, fills, and strokes
             * that implement the IGraphicsData interface. A
             * Vector of IGraphicsData instances can refer to a part of a shape, or a complex fully defined
             * set of data for rendering a complete shape.
             *
             *   Graphics paths can contain other graphics paths. If the graphicsData Vector
             * includes a path, that path and all its sub-paths are rendered during this operation.
             * @param   graphicsData    A Vector containing graphics objects, each of which much implement the IGraphicsData interface.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            void     drawGraphicsData(std::vector<flash::display::IGraphicsData *> graphicsData);

        public:
            std::vector<IGraphicsData *> readGraphicsData(bool recurse   =true);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_GRAPHICS_AS
#endif // __cplusplus

