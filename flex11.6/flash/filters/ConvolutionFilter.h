#if !defined(FLEX11_6_FLASH_FILTERS_CONVOLUTIONFILTER_AS)
#define FLEX11_6_FLASH_FILTERS_CONVOLUTIONFILTER_AS
#if defined(__cplusplus)


#include "flash/filters/BitmapFilter.h"

/**
 * The ConvolutionFilter class applies a matrix convolution filter effect. A convolution combines pixels
 * in the input image with neighboring pixels to produce an image. A wide variety of image
 * effects can be achieved through convolutions, including blurring, edge detection, sharpening,
 * embossing, and beveling. You can apply the filter to any display object (that is, objects that
 * inherit from the DisplayObject class),
 * such as MovieClip, SimpleButton, TextField, and Video objects, as well as to BitmapData objects.
 *
 *   <p class="- topic/p ">To create a convolution filter, use the syntax <codeph class="+ topic/ph pr-d/codeph ">new ConvolutionFilter()</codeph>.
 * The use of filters depends on the object to which you apply the filter:</p><ul class="- topic/ul "><li class="- topic/li ">To apply filters to movie clips, text fields, buttons, and video, use the
 * <codeph class="+ topic/ph pr-d/codeph ">filters</codeph> property (inherited from DisplayObject). Setting the <codeph class="+ topic/ph pr-d/codeph ">filters</codeph>
 * property of an object does not modify the object, and you can remove the filter by clearing the
 * <codeph class="+ topic/ph pr-d/codeph ">filters</codeph> property. </li><li class="- topic/li ">To apply filters to BitmapData objects, use the <codeph class="+ topic/ph pr-d/codeph ">BitmapData.applyFilter()</codeph> method.
 * Calling <codeph class="+ topic/ph pr-d/codeph ">applyFilter()</codeph> on a BitmapData object takes the source BitmapData object
 * and the filter object and generates a filtered image as a result.</li></ul><p class="- topic/p ">If you apply a filter to a display object, the value of the <codeph class="+ topic/ph pr-d/codeph ">cacheAsBitmap</codeph> property of the
 * object is set to <codeph class="+ topic/ph pr-d/codeph ">true</codeph>. If you clear all filters, the original value of
 * <codeph class="+ topic/ph pr-d/codeph ">cacheAsBitmap</codeph> is restored.</p><p class="- topic/p ">A filter is not applied if the resulting image exceeds the maximum dimensions.
 * In  AIR 1.5 and Flash Player 10, the maximum is 8,191 pixels in width or height,
 * and the total number of pixels cannot exceed 16,777,215 pixels. (So, if an image is 8,191 pixels
 * wide, it can only be 2,048 pixels high.) In Flash Player 9 and earlier and AIR 1.1 and earlier,
 * the limitation is 2,880 pixels in height and 2,880 pixels in width.
 * For example, if you zoom in on a large movie clip with a filter applied, the filter is
 * turned off if the resulting image exceeds maximum dimensions.</p>
 *
 *   EXAMPLE:
 *
 *   The following example applies different convolution filters to
 * an image file. The filter constructor calls
 * <codeph class="+ topic/ph pr-d/codeph ">buildChild()</codeph> four times to load and display four instances of the image.
 * Each call to <codeph class="+ topic/ph pr-d/codeph ">buildChild()</codeph> takes as an argument a function that applies
 * no filter to the first instance and a different convolution filter to each
 * subsequent instance.
 * <p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">buildChild()</codeph> function creates a new Loader object named
 * <codeph class="+ topic/ph pr-d/codeph ">loader</codeph>. For each call to <codeph class="+ topic/ph pr-d/codeph ">buildChild()</codeph>,
 * attach an event listener to the Loader object to listen for <codeph class="+ topic/ph pr-d/codeph ">complete</codeph> events,
 * which are handled by the function passed to <codeph class="+ topic/ph pr-d/codeph ">buildChild()</codeph>.</p><p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">applyBrightness()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">applySharpness()</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">applyOutline()</codeph>
 * functions use different values for the <codeph class="+ topic/ph pr-d/codeph ">matrix</codeph> array to achieve different
 * ConvolutionFilter effects.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note</b>: For best results, use an image approximately 80 pixels in width.
 * The name and location of the image file should match the value you pass to the
 * <codeph class="+ topic/ph pr-d/codeph ">url</codeph> property. For example, the value passed to <codeph class="+ topic/ph pr-d/codeph ">url</codeph> in the example
 * points to an image file named "Image.jpg" that is in the same directory as your SWF file.
 * </p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.DisplayObject;
 * import flash.display.Loader;
 * import flash.display.Sprite;
 * import flash.events.*;
 * import flash.filters.BitmapFilter;
 * import flash.filters.ConvolutionFilter;
 * import flash.net.URLRequest;
 * import flash.text.TextField;
 * import flash.text.TextFieldAutoSize;
 *
 *   public class ConvolutionFilterExample extends Sprite {
 * private var size:uint = 140;
 * private var url:String = "Image.jpg";
 *
 *   public function ConvolutionFilterExample() {
 * buildChild(applyNothing);
 * buildChild(applyBrightness);
 * buildChild(applySharpness);
 * buildChild(applyOutline);
 * }
 *
 *   private function buildChild(loadHandler:Function):void {
 * var loader:Loader = new Loader();
 * loader.x = numChildren * size;
 * loader.y = size;
 * loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
 * if(loadHandler != null) {
 * loader.contentLoaderInfo.addEventListener(Event.COMPLETE, loadHandler);
 * }
 *
 *   var request:URLRequest = new URLRequest(url);
 * loader.load(request);
 * addChild(loader);
 * }
 *
 *   private function applyNothing(event:Event):void {
 * var child:DisplayObject = DisplayObject(event.target.loader);
 * applyLabel(child, "no filter");
 * }
 *
 *   private function applyBrightness(event:Event):void {
 * var child:DisplayObject = DisplayObject(event.target.loader);
 * var matrix:Array = [5, 5, 5,
 * 5, 0, 5,
 * 5, 5, 5];
 * applyFilter(child, matrix);
 * applyLabel(child, "brightness");
 * }
 *
 *   private function applySharpness(event:Event):void {
 * var child:DisplayObject = DisplayObject(event.target.loader);
 * var matrix:Array = [0, -1, 0,
 * -1, 20, -1,
 * 0, -1, 0];
 * applyFilter(child, matrix);
 * applyLabel(child, "sharpness");
 * }
 *
 *   private function applyOutline(event:Event):void {
 * var child:DisplayObject = DisplayObject(event.target.loader);
 * var matrix:Array = [-30, 30, 0,
 * -30, 30, 0,
 * -30, 30, 0];
 * applyFilter(child, matrix);
 * applyLabel(child, "outline");
 * }
 *
 *   private function applyFilter(child:DisplayObject, matrix:Array):void {
 * var matrixX:Number = 3;
 * var matrixY:Number = 3;
 * var divisor:Number = 9;
 * var filter:BitmapFilter = new ConvolutionFilter(matrixX, matrixY, matrix, divisor);
 * var filters:Array = new Array();
 * filters.push(filter);
 * child.filters = filters;
 * }
 *
 *   private function applyLabel(child:DisplayObject, label:String):void {
 * var tf:TextField = new TextField();
 * tf.x = child.x;
 * tf.y = child.height;
 * tf.autoSize = TextFieldAutoSize.LEFT;
 * tf.text = label;
 * addChild(tf);
 * }
 *
 *   private function ioErrorHandler(event:IOErrorEvent):void {
 * trace("Unable to load image: " + url);
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @internal    Do we allow anything other than 3x3 matrix convolution? Are default x y values correct?
 */
using namespace flash::filters;

namespace flash
{
    namespace filters
    {
        class ConvolutionFilter: public BitmapFilter
        {
            /**
             * An array of values used for matrix transformation. The number of items
             * in the array must equal matrixX ~~ matrixY.
             * A matrix convolution is based on an n x m matrix, which describes how a given pixel value in the
             * input image is combined with its neighboring pixel values to produce a resulting pixel value. Each
             * result pixel is determined by applying the matrix to the corresponding source pixel and its
             * neighboring pixels. For a 3 x 3 matrix convolution, the following formula is used for each independent color channel:
             *
             *   dst (x, y) = ((src (x-1, y-1) ~~ a0 + src(x, y-1) ~~ a1....
             * src(x, y+1) ~~ a7 + src (x+1,y+1) ~~ a8) / divisor) + bias
             * Certain filter specifications perform faster when run by a processor
             * that offers SSE (Streaming SIMD Extensions). The following are criteria
             * for faster convolution operations:The filter must be a 3x3 filter.All the filter terms must be integers between -127 and +127.The sum of all the filter terms must not have an absolute value greater than 127.If any filter term is negative, the divisor must be between 2.00001 and 256.If all filter terms are positive, the divisor must be between 1.1 and 256.The bias must be an integer.Note: If you create a ConvolutionFilter instance using the
             * constructor without parameters, the order you assign values to matrix properties affects
             * the behavior of the filter. In the following case, the matrix array is assigned while the
             * matrixX and matrixY properties are still set to 0
             * (the default value):
             * <codeblock>
             *
             *   public var myfilter:ConvolutionFilter = new ConvolutionFilter();
             * myfilter.matrix = [0, 0, 0, 0, 1, 0, 0, 0, 0];
             * myfilter.matrixX = 3;
             * myfilter.matrixY = 3;
             *
             *   </codeblock>
             * In the following case, the matrix array is assigned while the matrixX
             * and matrixY properties are set to 3:
             * <codeblock>
             *
             *   public var myfilter:ConvolutionFilter = new ConvolutionFilter();
             * myfilter.matrixX = 3;
             * myfilter.matrixY = 3;
             * myfilter.matrix = [0, 0, 0, 0, 1, 0, 0, 0, 0];
             *
             *   </codeblock>
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example changes the <code>matrix</code> property of <code>filter</code>
             *   from one that blurs a bitmap to one that sharpens it.
             *   <listing version="2.0">
             *   import flash.filters.ConvolutionFilter;
             *   import flash.display.BitmapData;
             *
             *     var filter:ConvolutionFilter = new ConvolutionFilter(3, 3, [1, 1, 1, 1, 1, 1, 1, 1, 1], 9);
             *
             *     var myBitmapData:BitmapData = new BitmapData(100, 80, false, 0x00FF0000);
             *
             *     var mc:MovieClip = this.createEmptyMovieClip("mc", this.getNextHighestDepth());
             *   mc.attachBitmap(myBitmapData, this.getNextHighestDepth());
             *   myBitmapData.noise(128);
             *
             *     mc.onPress = function() {
             *   var newMatrix:Array = [0, -1, 0, -1, 8, -1, 0, -1, 0];
             *   filter.matrix = newMatrix;
             *   myBitmapData.applyFilter(myBitmapData, myBitmapData.rectangle, new Point(0, 0), filter);
             *   }
             *   </listing>
             * @throws  TypeError The Array is null when being set
             */
        public:
            std::vector<void *> matrix();
        public:
            void         matrix(std::vector<void *> value);

            /**
             * The x dimension of the matrix (the number of columns in the matrix). The default
             * value is 0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example displays the <code>matrixX</code>
             *   property of <code>filter</code>.
             *   <listing version="2.0">
             *   import flash.filters.ConvolutionFilter;
             *
             *     var filter:ConvolutionFilter = new ConvolutionFilter(2, 3, [1, 0, 0, 1, 0, 0], 6);
             *   trace(filter.matrixX); // 2
             *   </listing>
             */
        public:
            float        matrixX();
        public:
            void         matrixX(float value);

            /**
             * The y dimension of the matrix (the number of rows in the matrix). The default value
             * is 0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example displays the <code>matrixY</code>
             *   property of <code>filter</code>.
             *   <listing version="2.0">
             *   import flash.filters.ConvolutionFilter;
             *
             *     var filter:ConvolutionFilter = new ConvolutionFilter(2, 3, [1, 0, 0, 1, 0, 0], 6);
             *   trace(filter.matrixY); // 3
             *   </listing>
             */
        public:
            float        matrixY();
        public:
            void         matrixY(float value);

            /**
             * The divisor used during matrix transformation. The default value is 1.
             * A divisor that is the sum of all the matrix values smooths out the overall color intensity of the
             * result. A value of 0 is ignored and the default is used instead.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example changes the <code>divisor</code> property of <code>filter</code>
             *   to 6.
             *   <listing version="2.0">
             *   import flash.filters.ConvolutionFilter;
             *   import flash.display.BitmapData;
             *
             *     var filter:ConvolutionFilter = new ConvolutionFilter(3, 3, [1, 1, 1, 1, 1, 1, 1, 1, 1], 9);
             *
             *     var myBitmapData:BitmapData = new BitmapData(100, 80, false, 0x00FF0000);
             *
             *     var mc:MovieClip = this.createEmptyMovieClip("mc", this.getNextHighestDepth());
             *   mc.attachBitmap(myBitmapData, this.getNextHighestDepth());
             *   myBitmapData.noise(128);
             *
             *     mc.onPress = function() {
             *   var newDivisor:Number = 6;
             *   filter.divisor = newDivisor;
             *   myBitmapData.applyFilter(myBitmapData, myBitmapData.rectangle, new Point(0, 0), filter);
             *   }
             *   </listing>
             */
        public:
            float        divisor();
        public:
            void         divisor(float value);

            /**
             * The amount of bias to add to the result of the matrix transformation.
             * The bias increases the color value of each channel, so that dark colors
             * appear brighter. The default value is 0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example changes the <code>bias</code> property of <code>filter</code>
             *   from its default value of 0 to 50.
             *   <listing version="2.0">
             *   import flash.filters.ConvolutionFilter;
             *   import flash.display.BitmapData;
             *
             *     var bias:Number = 50;
             *   var filter:ConvolutionFilter = new ConvolutionFilter(3, 3, [1, 1, 1, 1, 1, 1, 1, 1, 1], 9, bias);
             *
             *     var myBitmapData:BitmapData = new BitmapData(100, 80, false, 0x00FF0000);
             *
             *     var mc:MovieClip = this.createEmptyMovieClip("mc", this.getNextHighestDepth());
             *   mc.attachBitmap(myBitmapData, this.getNextHighestDepth());
             *   myBitmapData.noise(128);
             *
             *     mc.onPress = function() {
             *   myBitmapData.applyFilter(myBitmapData, myBitmapData.rectangle, new Point(0, 0), filter);
             *   }
             *   </listing>
             */
        public:
            float        bias();
        public:
            void         bias(float value);

            /**
             * Indicates if the alpha channel is preserved without the filter effect
             * or if the convolution filter is applied
             * to the alpha channel as well as the color channels.
             * A value of false indicates that the
             * convolution applies to all channels, including the
             * alpha channel. A value of true indicates that the convolution applies only to the
             * color channels. The default value is true.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example changes the <code>preserveAlpha</code> property of <code>filter</code>
             *   from its default value of <code>true</code> to <code>false</code>.
             *   <listing version="2.0">
             *   import flash.filters.ConvolutionFilter;
             *   import flash.display.BitmapData;
             *
             *     var preserveAlpha:Boolean = false;
             *   var filter:ConvolutionFilter = new ConvolutionFilter(3, 3, [1, 1, 1, 1, 1, 1, 1, 1, 1], 9, 0, preserveAlpha);
             *
             *     var myBitmapData:BitmapData = new BitmapData(100, 80, true, 0xCCFF0000);
             *
             *     var mc:MovieClip = this.createEmptyMovieClip("mc", this.getNextHighestDepth());
             *   mc.attachBitmap(myBitmapData, this.getNextHighestDepth());
             *   myBitmapData.noise(128, 0, 255, 1 | 2 | 4 | 8, false);
             *
             *     mc.onPress = function() {
             *   myBitmapData.applyFilter(myBitmapData, myBitmapData.rectangle, new Point(0, 0), filter);
             *   }
             *   </listing>
             */
        public:
            bool         preserveAlpha();
        public:
            void         preserveAlpha(bool value);

            /**
             * Indicates whether the image should be clamped. For pixels off the source image, a value of
             * true indicates that the input
             * image is extended along each of its borders as necessary by duplicating the color values at each
             * respective edge of the input image. A value of false indicates that another color should
             * be used, as specified in the color and alpha properties.
             * The default is true.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool         clamp();
        public:
            void         clamp(bool value);

            /**
             * The hexadecimal color to substitute for pixels that are off the source image.
             * It is an RGB value with no alpha component. The default is 0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example changes the <code>color</code> property of <code>filter</code>
             *   from its default value of <code>0</code> to <code>0xFF0000</code>.
             *   <listing version="2.0">
             *   import flash.filters.ConvolutionFilter;
             *   import flash.display.BitmapData;
             *   import flash.geom.Rectangle;
             *   import flash.geom.Point;
             *
             *     var color:Number = 0x0000FF;
             *   var filter:ConvolutionFilter = new ConvolutionFilter(3, 3, [1, 1, 1, 1, 1, 1, 1, 1, 1], 9, 0, true, false, color, 1);
             *
             *     var myBitmapData:BitmapData = new BitmapData(100, 80, true, 0xCCFF0000);
             *
             *     var mc:MovieClip = this.createEmptyMovieClip("mc", this.getNextHighestDepth());
             *   mc.attachBitmap(myBitmapData, this.getNextHighestDepth());
             *   myBitmapData.noise(128, 0, 255, 1 | 2 | 4 | 8, false);
             *
             *     var height:Number = 100;
             *   var width:Number = 80;
             *   mc.onPress = function() {
             *   height -= 2;
             *   width -= 2;
             *   myBitmapData.applyFilter(myBitmapData, new Rectangle(0, 0, height, width), new Point(2, 2), filter);
             *   }
             *   </listing>
             */
        public:
            unsigned int color();
        public:
            void         color(unsigned int value);

            /**
             * The alpha transparency value of the substitute color. Valid values are 0 to 1.0. The default is 0. For example,
             * .25 sets a transparency value of 25%.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example changes the <code>alpha</code> property of <code>filter</code>
             *   from its default value of <code>1</code> to <code>.35</code>.
             *   <listing version="2.0">
             *   import flash.filters.ConvolutionFilter;
             *   import flash.display.BitmapData;
             *   import flash.geom.Rectangle;
             *   import flash.geom.Point;
             *
             *     var alpha:Number = .35;
             *   var filter:ConvolutionFilter = new ConvolutionFilter(3, 3, [1, 1, 1, 1, 1, 1, 1, 1, 1], 9, 0, true, false, 0x0000FF, alpha);
             *
             *     var myBitmapData:BitmapData = new BitmapData(100, 80, true, 0xCCFF0000);
             *
             *     var mc:MovieClip = this.createEmptyMovieClip("mc", this.getNextHighestDepth());
             *   mc.attachBitmap(myBitmapData, this.getNextHighestDepth());
             *   myBitmapData.noise(128, 0, 255, 1 | 2 | 4 | 8, false);
             *
             *     mc.onPress = function() {
             *   myBitmapData.applyFilter(myBitmapData, new Rectangle(0, 0, 98, 78), new Point(2, 2), filter);
             *   }
             *   </listing>
             */
        public:
            float        alpha();
        public:
            void         alpha(float value);

            /**
             * Initializes a ConvolutionFilter instance with the specified parameters.
             * @param   matrixX The x dimension of the matrix (the number of columns in the matrix). The
             *   default value is 0.
             * @param   matrixY The y dimension of the matrix (the number of rows in the matrix). The
             *   default value is 0.
             * @param   matrix  The array of values used for matrix transformation. The number of
             *   items in the array must equal matrixX ~~ matrixY.
             * @param   divisor The divisor used during matrix transformation. The default value is 1.
             *   A divisor that is the sum of all the matrix values evens out the overall color intensity of the
             *   result. A value of 0 is ignored and the default is used instead.
             * @param   bias    The bias to add to the result of the matrix transformation. The default value is 0.
             * @param   preserveAlpha   A value of false indicates that the alpha value is not
             *   preserved and that the convolution applies to all
             *   channels, including the alpha channel. A value of true indicates that
             *   the convolution applies only to the color channels. The default value is true.
             * @param   clamp   For pixels that are off the source image, a value of true indicates that the
             *   input  image is extended along each of its borders as necessary by duplicating the color values
             *   at the given edge of the input image.   A value of false indicates that another
             *   color should be used, as specified in the color and alpha properties.
             *   The default is true.
             * @param   color   The hexadecimal color to substitute for pixels that are off the source image.
             * @param   alpha   The alpha of the substitute color.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example creates a ConvolutionFilter
             *   object with the four required parameters <code>matrixX</code>, <code>matrixY</code>,
             *   <code>matrix</code>, and <code>divisor</code>.
             *   <listing version="2.0">
             *   import flash.filters.ConvolutionFilter;
             *   import flash.display.BitmapData;
             *
             *     var matrixX:Number = 3;
             *   var matrixY:Number = 3;
             *   var matrix:Array = [1, 1, 1, 1, 1, 1, 1, 1, 1];
             *   var divisor:Number = 9;
             *
             *     var filter:ConvolutionFilter = new ConvolutionFilter(matrixX, matrixY, matrix, divisor);
             *
             *     var myBitmapData:BitmapData = new BitmapData(100, 80, false, 0x00FF0000);
             *
             *     var mc:MovieClip = this.createEmptyMovieClip("mc", this.getNextHighestDepth());
             *   mc.attachBitmap(myBitmapData, this.getNextHighestDepth());
             *   myBitmapData.noise(128);
             *
             *     mc.onPress = function() {
             *   myBitmapData.applyFilter(myBitmapData, myBitmapData.rectangle, new Point(0, 0), filter);
             *   }
             *   </listing>
             */
        public:
            ConvolutionFilter(float matrixX, float matrixY, std::vector<void *> matrix, float divisor, float bias, bool preserveAlpha, bool clamp, unsigned int color, float alpha);

            /**
             * Returns a copy of this filter object.
             * @return  BitmapFilter A new ConvolutionFilter instance with all the same properties as the original
             *   ConvolutionMatrixFilter instance.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example creates three <code>ConvolutionFilter</code> objects and compares them.  <code>filter_1</code>
             *   is created using the <code>ConvolutionFilter</code> construtor.  <code>filter_2</code> is created by setting it equal to
             *   <code>filter_1</code>.  And, <code>clonedFilter</code> is created by cloning <code>filter_1</code>.  Notice
             *   that while <code>filter_2</code> evaluates as being equal to <code>filter_1</code>, <code>clonedFilter</code>,
             *   even though it contains the same values as <code>filter_1</code>, does not.
             *   <listing version="2.0">
             *   import flash.filters.ConvolutionFilter;
             *
             *     var filter_1:ConvolutionFilter = new ConvolutionFilter(3, 3, [1, 1, 1, 1, 1, 1, 1, 1, 1], 9);
             *   var filter_2:ConvolutionFilter = filter_1;
             *   var clonedFilter:ConvolutionFilter = filter_1.clone();
             *
             *     trace(filter_1 == filter_2);     // true
             *   trace(filter_1 == clonedFilter);   // false
             *
             *     for(var i in filter_1) {
             *   trace("&gt;&gt; " + i + ": " + filter_1[i]);
             *   // &gt;&gt; clone: [type Function]
             *   // &gt;&gt; alpha: 0
             *   // &gt;&gt; color: 0
             *   // &gt;&gt; clamp: true
             *   // &gt;&gt; preserveAlpha: true
             *   // &gt;&gt; bias: 0
             *   // &gt;&gt; divisor: 9
             *   // &gt;&gt; matrix: 0,1,0,1,4,1,0,1,0
             *   // &gt;&gt; matrixY: 3
             *   // &gt;&gt; matrixX: 3
             *   }
             *
             *     for(var i in clonedFilter) {
             *   trace("&gt;&gt; " + i + ": " + clonedFilter[i]);
             *   // &gt;&gt; clone: [type Function]
             *   // &gt;&gt; alpha: 0
             *   // &gt;&gt; color: 0
             *   // &gt;&gt; clamp: true
             *   // &gt;&gt; preserveAlpha: true
             *   // &gt;&gt; bias: 0
             *   // &gt;&gt; divisor: 9
             *   // &gt;&gt; matrix: 0,1,0,1,4,1,0,1,0
             *   // &gt;&gt; matrixY: 3
             *   // &gt;&gt; matrixX: 3
             *   }
             *   </listing><p class="- topic/p ">To further demonstrate the relationships between <code>filter_1</code>, <code>filter_2</code>, and <code>clonedFilter</code>
             *   the example below modifies the <code>bias</code> property of <code>filter_1</code>.  Modifying <code>bias</code> demonstrates
             *   that the <code>clone()</code> method creates a new instance based on values of the <code>filter_1</code> instead of pointing to
             *   them in reference.</p><listing version="2.0">
             *   import flash.filters.ConvolutionFilter;
             *
             *     var filter_1:ConvolutionFilter = new ConvolutionFilter(3, 3, [1, 1, 1, 1, 1, 1, 1, 1, 1], 9);
             *   var filter_2:ConvolutionFilter = filter_1;
             *   var clonedFilter:ConvolutionFilter = filter_1.clone();
             *   trace(filter_1.bias);          // 0
             *   trace(filter_2.bias);          // 0
             *   trace(clonedFilter.bias);      // 0
             *
             *     filter_1.bias = 20;
             *
             *     trace(filter_1.bias);            // 20
             *   trace(filter_2.bias);          // 20
             *   trace(clonedFilter.bias);      // 0
             *   </listing>
             */
        public:
            flash::filters::BitmapFilter *clone();
        };
    }
}

#endif // FLEX11_6_FLASH_FILTERS_CONVOLUTIONFILTER_AS
#endif // __cplusplus

