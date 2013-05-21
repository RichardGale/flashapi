

#include "ShaderFilter.h"
#include "flash/display/Shader.h"
#include "flash/geom/Rectangle.h"

    /**
     * The ShaderFilter class applies a filter by executing a shader on the object 
     * being filtered. The filtered object is used as an input to the shader, and the 
     * shader output becomes the filter result.
     * 
     *   <p class="- topic/p ">To create a new filter, use the constructor <codeph class="+ topic/ph pr-d/codeph ">new ShaderFilter()</codeph>. The 
     * use of filters depends on the object to which you apply the filter:</p><ul class="- topic/ul "><li class="- topic/li ">To apply filters to movie clips, text fields, buttons, and video, use the 
     * <codeph class="+ topic/ph pr-d/codeph ">filters</codeph> property (inherited from DisplayObject). Setting the 
     * <codeph class="+ topic/ph pr-d/codeph ">filters</codeph> property of an object does not modify the object, and you 
     * can remove the filter by clearing the <codeph class="+ topic/ph pr-d/codeph ">filters</codeph> property.</li><li class="- topic/li ">To apply filters to BitmapData objects, use the <codeph class="+ topic/ph pr-d/codeph ">BitmapData.applyFilter()</codeph>
     * method. Calling <codeph class="+ topic/ph pr-d/codeph ">applyFilter()</codeph> on a BitmapData object takes the source
     * BitmapData object and the filter object and generates a filtered image as a 
     * result.</li></ul><p class="- topic/p ">If you apply a filter to a display object, the value of the <codeph class="+ topic/ph pr-d/codeph ">cacheAsBitmap</codeph> 
     * property of the object is set to true. If you remove all filters, the original value of 
     * <codeph class="+ topic/ph pr-d/codeph ">cacheAsBitmap</codeph> is restored.</p><p class="- topic/p ">This filter supports stage scaling. However, it does not support general scaling, 
     * rotation, and skewing. If the object itself is scaled (if the <codeph class="+ topic/ph pr-d/codeph ">scaleX</codeph> and 
     * <codeph class="+ topic/ph pr-d/codeph ">scaleY</codeph> properties are not set to 100%), the filter is not scaled. It is 
     * scaled only when the user zooms in on the stage.</p><p class="- topic/p ">A filter is not applied if the resulting image exceeds the maximum dimensions.
     * In  AIR 1.5 and Flash Player 10, the maximum is 8,191 pixels in width or height, 
     * and the total number of pixels cannot exceed 16,777,215 pixels. (So, if an image is 8,191 pixels 
     * wide, it can only be 2,048 pixels high.) In Flash Player 9 and earlier and AIR 1.1 and earlier, 
     * the limitation is 2,880 pixels in height and 2,880 pixels in width.
     * If, for example, you zoom in on a large movie clip with a filter applied, the filter is 
     * turned off if the resulting image exceeds the maximum dimensions.</p><p class="- topic/p ">To specify the Shader instance to use with the filter, pass the Shader instance 
     * as an argument to the <codeph class="+ topic/ph pr-d/codeph ">ShaderFilter()</codeph> 
     * constructor, or set it as the value of the <codeph class="+ topic/ph pr-d/codeph ">shader</codeph> property.</p><p class="- topic/p ">To allow the shader output to extend beyond the bounds of the filtered object, 
     * use the <codeph class="+ topic/ph pr-d/codeph ">leftExtension</codeph>, <codeph class="+ topic/ph pr-d/codeph ">rightExtension</codeph>, <codeph class="+ topic/ph pr-d/codeph ">topExtension</codeph>,
     * and <codeph class="+ topic/ph pr-d/codeph ">bottomExtension</codeph> properties.</p>
     * 
     *   EXAMPLE:
     * 
     *   The following example loads a shader and uses it as the <codeph class="+ topic/ph pr-d/codeph ">shader</codeph> property 
     * of a ShaderFilter. The code draws a circle in a Sprite instance and adds it to the stage. When 
     * the shader loads, the shader filter is applied to that Sprite.
     * 
     *   <p class="- topic/p ">Note that this example assumes there's a shader bytecode file named "gradient.pbj" in the same 
     * directory as the output directory for the application.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * 
     *   //
     * // Source code for the shader:
     * //
     * &lt;languageVersion : 1.0;&gt;
     * 
     *   kernel RedGradientFilter
     * &lt;
     * namespace: "Adobe::Example";
     * vendor: "Adobe examples";
     * version: 1;
     * description: "Applies a gradient across the red channel of the input image.";
     * &gt;
     * {
     * input image4 src;
     * output pixel4 dst;
     * 
     *   parameter float width
     * &lt;
     * description: "The width of the image to which the shader is applied.";
     * minValue: 0.0;
     * &gt;;
     * 
     *   void evaluatePixel()
     * {
     * pixel4 temp = sampleNearest(src, outCoord());
     * temp.r = 1.0 - (outCoord().x * (1.0 / width));
     * dst = temp;
     * }
     * }
     * 
     *   //
     * // ActionScript source code:
     * //
     * package {
     * import flash.display.Shader;
     * import flash.display.Sprite;
     * import flash.events.Event;
     * import flash.filters.ShaderFilter;
     * import flash.net.URLLoader;
     * import flash.net.URLLoaderDataFormat;
     * import flash.net.URLRequest;
     * 
     *   public class ShaderFilterExample extends Sprite {
     * 
     *   private var loader:URLLoader;
     * private var s:Sprite;
     * 
     *   public function ShaderFilterExample() {
     * loader = new URLLoader();
     * loader.dataFormat = URLLoaderDataFormat.BINARY;
     * loader.addEventListener(Event.COMPLETE, loadCompleteHandler);
     * loader.load(new URLRequest("gradient.pbj"));
     * 
     *   s = new Sprite();
     * s.graphics.beginFill(0x009900);
     * s.graphics.drawCircle(100, 100, 100);
     * addChild(s);
     * }
     * 
     *   private function loadCompleteHandler(event:Event):void {
     * var shader:Shader = new Shader(loader.data);
     * shader.data.width.value = [s.width];
     * 
     *   var gradientFilter:ShaderFilter = new ShaderFilter(shader);
     * s.filters = [gradientFilter];
     * }
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     */

using namespace flash::display;
using namespace flash::geom;

namespace flash {
namespace filters {


        /**
         * The shader to use for this filter.
         * 
         *   The Shader assigned to the shader property must specify at least one 
         * image4 input. The input does not need to be specified in code using the 
         * associated ShaderInput object's input property. Instead, the object to which the 
         * filter is applied is automatically 
         * used as the first input (the input with index 0). A shader used as a filter 
         * can specify more than one input, in which case any additional input must be specified 
         * by setting its ShaderInput instance's input property.When you assign a Shader instance to this property the shader is copied internally and the 
         * filter operation uses that internal copy, not a reference to the original shader. Any changes 
         * made to the shader, such as changing a parameter value, input, or bytecode, are not applied 
         * to the copied shader that's used for the filter. To make it so that shader changes are taken 
         * into account in the filter output, 
         * you must reassign the Shader instance to the shader property. As with all filters,
         * you must also reassign the ShaderFilter instance to the display object's filters 
         * property in order to apply filter changes.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        flash::display::Shader* ShaderFilter::shader()                       ;
        void ShaderFilter::shader(Shader* shader)       ;

        /**
         * The growth in pixels on the left side of the target object.
         * 
         *   The growth is the area beyond the bounds of the target object 
         * that is passed to the shader during execution. At execution time 
         * Flash Player or AIR computes the normal bounds of a movie clip and extends 
         * the bounds based on the leftExtension, rightExtension,
         * topExtension, and bottomExtension values.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        int ShaderFilter::leftExtension()      ;
        void ShaderFilter::leftExtension(int v)       ;

        /**
         * The growth in pixels on the top side of the target object.
         * 
         *   The growth is the area beyond the bounds of the target object 
         * that is passed to the shader during execution. At execution time 
         * Flash Player or AIR computes the normal bounds of a movie clip and extends 
         * the bounds based on the leftExtension, rightExtension,
         * topExtension, and bottomExtension values.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        int ShaderFilter::topExtension()      ;
        void ShaderFilter::topExtension(int v)       ;

        /**
         * The growth in pixels on the right side of the target object.
         * 
         *   The growth is the area beyond the bounds of the target object 
         * that is passed to the shader during execution. At execution time 
         * Flash Player or AIR computes the normal bounds of a movie clip and extends 
         * the bounds based on the leftExtension, rightExtension,
         * topExtension, and bottomExtension values.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        int ShaderFilter::rightExtension()      ;
        void ShaderFilter::rightExtension(int v)       ;

        /**
         * The growth in pixels on the bottom side of the target object.
         * 
         *   The growth is the area beyond the bounds of the target object 
         * that is passed to the shader during execution. At execution time 
         * Flash Player or AIR computes the normal bounds of a movie clip and extends 
         * the bounds based on the leftExtension, rightExtension,
         * topExtension, and bottomExtension values.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        int ShaderFilter::bottomExtension()      ;
        void ShaderFilter::bottomExtension(int v)       ;

        /**
         * Creates a new shader filter.
         * @param   shader  The Shader to use for this filter. For details and limitations that 
         *   the shader must conform to, see the description for the shader 
         *   property.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        ShaderFilter::ShaderFilter(Shader* shader);
}
}

