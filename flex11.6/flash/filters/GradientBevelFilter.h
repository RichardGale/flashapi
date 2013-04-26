#if !defined(FLEX11_6_FLASH_FILTERS_GRADIENTBEVELFILTER_AS)
#define FLEX11_6_FLASH_FILTERS_GRADIENTBEVELFILTER_AS
#if defined(__cplusplus)


#include "flash/filters/BitmapFilter.h"

/**
 * The GradientBevelFilter class lets you apply a gradient bevel effect to
 * display objects. A gradient bevel is a beveled edge, enhanced with gradient color,
 * on the outside, inside, or top of an object. Beveled edges make objects look
 * three-dimensional.
 * You can apply the filter to any display object (that is, objects that inherit from the DisplayObject class),
 * such as MovieClip, SimpleButton, TextField, and Video objects, as well as to BitmapData objects.
 *
 *   <p class="- topic/p ">The use of filters depends on the object to which you apply the filter:</p><ul class="- topic/ul "><li class="- topic/li ">To apply filters to display objects, use the
 * <codeph class="+ topic/ph pr-d/codeph ">filters</codeph> property. Setting the <codeph class="+ topic/ph pr-d/codeph ">filters</codeph>
 * property of an object does not modify the object, and you can remove the filter by clearing the
 * <codeph class="+ topic/ph pr-d/codeph ">filters</codeph> property. </li><li class="- topic/li ">To apply filters to BitmapData objects, use the <codeph class="+ topic/ph pr-d/codeph ">BitmapData.applyFilter()</codeph> method.
 * Calling <codeph class="+ topic/ph pr-d/codeph ">applyFilter()</codeph> on a BitmapData object takes the source BitmapData object
 * and the filter object and generates a filtered image as a result.</li></ul><p class="- topic/p ">If you apply a filter to a display object, the <codeph class="+ topic/ph pr-d/codeph ">cacheAsBitmap</codeph> property of the
 * display object is set to <codeph class="+ topic/ph pr-d/codeph ">true</codeph>. If you clear all filters, the original value of
 * <codeph class="+ topic/ph pr-d/codeph ">cacheAsBitmap</codeph> is restored.</p><p class="- topic/p ">This filter supports Stage scaling. However, it does not support general scaling, rotation,
 * and skewing; if the object itself is scaled (if <codeph class="+ topic/ph pr-d/codeph ">scaleX</codeph> and <codeph class="+ topic/ph pr-d/codeph ">scaleY</codeph> are set
 * to a value other than 1.0), the
 * filter effect is not scaled. It is scaled only when the user zooms in on the Stage.</p><p class="- topic/p ">A filter is not applied if the resulting image exceeds the maximum dimensions.
 * In  AIR 1.5 and Flash Player 10, the maximum is 8,191 pixels in width or height,
 * and the total number of pixels cannot exceed 16,777,215 pixels. (So, if an image is 8,191 pixels
 * wide, it can only be 2,048 pixels high.) In Flash Player 9 and earlier and AIR 1.1 and earlier,
 * the limitation is 2,880 pixels in height and 2,880 pixels in width.
 * For example, if you zoom in on a large movie clip with a filter applied, the filter is
 * turned off if the resulting image exceeds the maximum dimensions.</p>
 *
 *   EXAMPLE:
 *
 *   The following example draws a square and applies a gradient bevel filter to it.
 * The general workflow of this example is as follows:
 * <ol class="- topic/ol "><li class="- topic/li ">Import the required classes.</li><li class="- topic/li ">Declare global variables to define the square and the filter.</li><li class="- topic/li ">Create the constructor functions, which does the following:
 * <ul class="- topic/ul "><li class="- topic/li ">Calls the <codeph class="+ topic/ph pr-d/codeph ">draw()</codeph> method, which uses methods of the Graphics class
 * accessed through the <codeph class="+ topic/ph pr-d/codeph ">graphics</codeph> property of Sprite to draw a gray square.</li><li class="- topic/li ">Creates a BitmapFilter object named <codeph class="+ topic/ph pr-d/codeph ">filter</codeph> and assigns it
 * the return value of a call to <codeph class="+ topic/ph pr-d/codeph ">getBitmapFilter()</codeph>, which creates the filter.</li><li class="- topic/li ">Creates a new array named <codeph class="+ topic/ph pr-d/codeph ">myFilters</codeph> and adds <codeph class="+ topic/ph pr-d/codeph ">filter</codeph> to it.</li><li class="- topic/li ">Assigns <codeph class="+ topic/ph pr-d/codeph ">myFilters</codeph> to the <codeph class="+ topic/ph pr-d/codeph ">filters</codeph> property of the
 * GradientBevelFilterExample object. This applies all filters found in <codeph class="+ topic/ph pr-d/codeph ">myFilters</codeph>, which in this case
 * is only <codeph class="+ topic/ph pr-d/codeph ">filter</codeph>.</li></ul></li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.filters.BitmapFilter;
 * import flash.filters.BitmapFilterQuality;
 * import flash.filters.BitmapFilterType;
 * import flash.filters.GradientBevelFilter;
 *
 *   public class GradientBevelFilterExample extends Sprite {
 * private var bgColor:uint     = 0xCCCCCC;
 * private var size:uint        = 80;
 * private var offset:uint      = 50;
 * private var distance:Number  = 5;
 * private var angleInDegrees:Number = 225; // opposite 45 degrees
 * private var colors:Array     = [0xFFFFFF, 0xCCCCCC, 0x000000];
 * private var alphas:Array     = [1, 0, 1];
 * private var ratios:Array     = [0, 128, 255];
 * private var blurX:Number     = 8;
 * private var blurY:Number     = 8;
 * private var strength:Number  = 2;
 * private var quality:Number   = BitmapFilterQuality.HIGH
 * private var type:String      = BitmapFilterType.INNER;
 * private var knockout:Boolean = true;
 *
 *   public function GradientBevelFilterExample() {
 * draw();
 * var filter:BitmapFilter = getBitmapFilter();
 * var myFilters:Array = new Array();
 * myFilters.push(filter);
 * filters = myFilters;
 * }
 *
 *   private function getBitmapFilter():BitmapFilter {
 * return new GradientBevelFilter(distance,
 * angleInDegrees,
 * colors,
 * alphas,
 * ratios,
 * blurX,
 * blurY,
 * strength,
 * quality,
 * type,
 * knockout);
 * }
 *
 *   private function draw():void {
 * graphics.beginFill(bgColor);
 * graphics.drawRect(offset, offset, size, size);
 * graphics.endFill();
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 */
using namespace flash::filters;

namespace flash
{
    namespace filters
    {
        class GradientBevelFilter: public BitmapFilter
        {
            /**
             * The offset distance. Valid values are 0 to 8. The default value is 4.0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example demonstrates how to set the <code>distance</code> property on an existing object.
             *   <listing version="2.0">
             *   import flash.filters.GradientBevelFilter;
             *
             *     var mc:MovieClip = setUpFilter("distanceExample");
             *   mc.onRelease = function() {
             *   var arr:Array = this.filters;
             *   arr[0].distance = 1;
             *   this.filters = arr;
             *   }
             *
             *     function setUpFilter(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 150;
             *   var h:Number = 150;
             *   art.beginFill(0xCCCCCC);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *
             *     var colors:Array = [0xFFFFFF, 0xCCCCCC, 0x000000];
             *   var alphas:Array = [1, 0, 1];
             *   var ratios:Array = [0, 128, 255];
             *   var filter:GradientBevelFilter = new GradientBevelFilter(5, 225, colors, alphas, ratios, 5, 5, 5, 3, "inner", false);
             *
             *     art.filters = new Array(filter);
             *   return art;
             *   }
             *   </listing>
             */
        public:
            float        distance();
        public:
            void         distance(float value);

            /**
             * The angle, in degrees. Valid values are 0 to 360. The default is 45.
             *
             *   The angle value represents the angle of the theoretical light source falling on the object.
             * The value determines the angle at which the gradient colors are applied to the object:
             * where the highlight and the shadow appear, or where the first color in the array appears.
             * The colors are then applied in the order in which they appear in the array.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example demonstrates how to set the <code>angle</code> property on an existing object.
             *   <listing version="2.0">
             *   import flash.filters.GradientBevelFilter;
             *
             *     var mc:MovieClip = setUpFilter("angleExample");
             *   mc.onRelease = function() {
             *   var arr:Array = this.filters;
             *   arr[0].angle = 45;
             *   this.filters = arr;
             *   }
             *
             *     function setUpFilter(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 150;
             *   var h:Number = 150;
             *   art.beginFill(0xCCCCCC);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *
             *     var colors:Array = [0xFFFFFF, 0xCCCCCC, 0x000000];
             *   var alphas:Array = [1, 0, 1];
             *   var ratios:Array = [0, 128, 255];
             *   var filter:GradientBevelFilter = new GradientBevelFilter(5, 225, colors, alphas, ratios, 5, 5, 5, 3, "inner", false);
             *
             *     art.filters = new Array(filter);
             *   return art;
             *   }
             *   </listing>
             */
        public:
            float        angle();
        public:
            void         angle(float value);

            /**
             * An array of RGB hexadecimal color values to use in the gradient.
             * For example, red is 0xFF0000, blue is 0x0000FF, and so on.
             *
             *   The colors property cannot be changed by directly modifying its values.
             * Instead, you must get a reference to colors, make the change to the
             * reference, and then set colors to the reference.The colors, alphas, and ratios properties are related.
             * The first element in the colors array
             * corresponds to the first element in the alphas array
             * and in the ratios array, and so on.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example demonstrates how to set the <code>colors</code> property on an existing entity.
             *   <listing version="2.0">
             *   import flash.filters.GradientBevelFilter;
             *
             *     var mc:MovieClip = setUpFilter("colorsExample");
             *   mc.onPress = function() {
             *   var arr:Array = this.filters;
             *   var colors:Array = [0x000000, 0xCCCCCC, 0xFFFFFF];
             *   arr[0].colors = colors;
             *   this.filters = arr;
             *   }
             *   mc.onRelease = function() {
             *   var arr:Array = this.filters;
             *   var colors:Array = [0xFFFFFF, 0xCCCCCC, 0x000000];
             *   arr[0].colors = colors;
             *   this.filters = arr;
             *   }
             *
             *     function setUpFilter(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 150;
             *   var h:Number = 150;
             *   art.beginFill(0xCCCCCC);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *
             *     var colors:Array = [0xFFFFFF, 0xCCCCCC, 0x000000];
             *   var alphas:Array = [1, 0, 1];
             *   var ratios:Array = [0, 128, 255];
             *   var filter:GradientBevelFilter = new GradientBevelFilter(5, 225, colors, alphas, ratios, 5, 5, 5, 2, "inner", false);
             *
             *     art.filters = new Array(filter);
             *   return art;
             *   }
             *   </listing>
             * @throws  TypeError The Array is null when being set
             */
        public:
            std::vector<void *> colors();
        public:
            void         colors(std::vector<void *> value);

            /**
             * An array of alpha transparency values for the corresponding colors in the
             * colors array. Valid values for each element
             * in the array are 0 to 1. For example, .25 sets a transparency value of 25%.
             *
             *   The alphas property cannot be changed by directly modifying its values.
             * Instead, you must get a reference to alphas, make the change to the
             * reference, and then set alphas to the reference.The colors, alphas, and ratios properties are related.
             * The first element in the colors array
             * corresponds to the first element in the alphas array
             * and in the ratios array, and so on.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example demonstrates how to set the <code>alphas</code> property on an existing entity.
             *   <listing version="2.0">
             *   import flash.filters.GradientBevelFilter;
             *
             *     var mc:MovieClip = setUpFilter("alphasExample");
             *   mc.onPress = function() {
             *   var arr:Array = this.filters;
             *   var alphas:Array = [.2, 0, .2];
             *   arr[0].alphas = alphas;
             *   this.filters = arr;
             *   }
             *   mc.onRelease = function() {
             *   var arr:Array = this.filters;
             *   var alphas:Array = [1, 0, 1];
             *   arr[0].alphas = alphas;
             *   this.filters = arr;
             *   }
             *
             *     function setUpFilter(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 150;
             *   var h:Number = 150;
             *   art.beginFill(0xCCCCCC);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *
             *     var colors:Array = [0xFFFFFF, 0xCCCCCC, 0x000000];
             *   var alphas:Array = [1, 0, 1];
             *   var ratios:Array = [0, 128, 255];
             *   var filter:GradientBevelFilter = new GradientBevelFilter(5, 225, colors, alphas, ratios, 5, 5, 5, 2, "inner", false);
             *
             *     art.filters = new Array(filter);
             *   return art;
             *   }
             *   </listing>
             * @throws  TypeError The Array is null when being set
             */
        public:
            std::vector<void *> alphas();
        public:
            void         alphas(std::vector<void *> value);

            /**
             * An array of color distribution ratios for the corresponding colors in the
             * colors array. Valid values for each element
             * in the array are 0 to 255.
             *
             *   The ratios property cannot be changed by directly modifying its values.
             * Instead, you must get a reference to ratios, make the change to the
             * reference, and then set ratios to the reference. The colors, alphas, and ratios properties are related.
             * The first element in the colors array
             * corresponds to the first element in the alphas array
             * and in the ratios array, and so on. To understand how the colors in a gradient bevel are distributed, think first of the colors
             * that you want in your gradient bevel. Consider that a simple bevel has a highlight color and shadow
             * color; a gradient bevel has a highlight gradient and a shadow gradient. Assume that the highlight
             * appears on the top-left corner, and the shadow appears on the bottom-right corner. Assume that one
             * possible usage of the filter has four colors in the highlight and four in the shadow. In addition
             * to the highlight and shadow, the filter uses a base fill color that appears where the edges of the
             * highlight and shadow meet. Therefore the total number of colors is nine, and the corresponding number
             * of elements in the ratios array is nine. If you think of a gradient as composed of stripes of various colors, blending into each other,
             * each ratio value sets the position of the color on the radius of the gradient, where 0 represents
             * the outermost point of the gradient and 255 represents the innermost point of the gradient.
             * For a typical usage,
             * the middle value is 128, and that is the base fill value. To get the bevel effect shown in the
             * image below, assign the
             * ratio values as follows, using the example of nine colors: The first four colors range from 0-127, increasing in value so that each value is greater than
             * or equal to the previous one. This is the highlight bevel edge. The fifth color (the middle color) is the base fill, set to 128. The pixel value of 128
             * sets the base fill, which appears either outside the shape (and around the bevel edges) if the type
             * is set to outer; or inside the shape, effectively covering the object's own fill, if the type
             * is set to inner. The last four colors range from 129-255, increasing in value so that each value
             * is greater than or equal to the previous one. This is the shadow bevel edge. If you want an equal distribution of colors for each edge, use an odd number of colors,
             * where the middle color is the base fill. Distribute the values between 0-127 and 129-255
             * equally among your colors, then adjust the value to change the width of each stripe of color
             * in the gradient. For a gradient bevel with nine colors, a possible array is
             * [16, 32, 64, 96, 128, 160, 192, 224, 235]. The following image depicts the gradient bevel
             * as described:Keep in mind that the spread of the colors in the gradient varies based on the values
             * of the blurX, blurY, strength, and quality
             * properties, as well as the ratios values.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example demonstrates how to set the <code>ratios</code> property on an existing entity.
             *   <listing version="2.0">
             *   import flash.filters.GradientBevelFilter;
             *
             *     var mc:MovieClip = setUpFilter("ratiosExample");
             *   mc.onPress = function() {
             *   var arr:Array = this.filters;
             *   var ratios:Array = [127, 128, 129];
             *   arr[0].ratios = ratios;
             *   this.filters = arr;
             *   }
             *   mc.onRelease = function() {
             *   var arr:Array = this.filters;
             *   var ratios:Array = [0, 128, 255];
             *   arr[0].ratios = ratios;
             *   this.filters = arr;
             *   }
             *
             *     function setUpFilter(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 150;
             *   var h:Number = 150;
             *   art.beginFill(0xCCCCCC);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *
             *     var colors:Array = [0xFFFFFF, 0xCCCCCC, 0x000000];
             *   var alphas:Array = [1, 0, 1];
             *   var ratios:Array = [0, 128, 255];
             *   var filter:GradientBevelFilter = new GradientBevelFilter(5, 225, colors, alphas, ratios, 5, 5, 5, 2, "inner", false);
             *
             *     art.filters = new Array(filter);
             *   return art;
             *   }
             *   </listing>
             * @throws  TypeError The Array is null when being set
             */
        public:
            std::vector<void *> ratios();
        public:
            void         ratios(std::vector<void *> value);

            /**
             * The amount of horizontal blur. Valid values are 0 to 255. A blur of 1 or
             * less means that the original image is copied as is. The default value
             * is 4. Values that are a power of 2 (such as 2, 4, 8, 16 and 32) are optimized
             * to render more quickly than other values.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example demonstrates how to set the <code>blurX</code> property on an existing object.
             *   <listing version="2.0">
             *   import flash.filters.GradientBevelFilter;
             *
             *     var mc:MovieClip = setUpFilter("blurXExample");
             *   mc.onRelease = function() {
             *   var arr:Array = this.filters;
             *   arr[0].blurX = 16;
             *   this.filters = arr;
             *   }
             *
             *     function setUpFilter(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 150;
             *   var h:Number = 150;
             *   art.beginFill(0xCCCCCC);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *
             *     var colors:Array = [0xFFFFFF, 0xCCCCCC, 0x000000];
             *   var alphas:Array = [1, 0, 1];
             *   var ratios:Array = [0, 128, 255];
             *   var filter:GradientBevelFilter = new GradientBevelFilter(5, 225, colors, alphas, ratios, 5, 5, 5, 3, "inner", false);
             *
             *     art.filters = new Array(filter);
             *   return art;
             *   }
             *   </listing>
             */
        public:
            float        blurX();
        public:
            void         blurX(float value);

            /**
             * The amount of vertical blur. Valid values are 0 to 255. A blur of 1 or less
             * means that the original image is copied as is. The default value is
             * 4. Values that are a power of 2 (such as 2, 4, 8, 16 and 32) are optimized
             * to render more quickly than other values.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example demonstrates how to set the <code>blurY</code> property on an existing object.
             *   <listing version="2.0">
             *   import flash.filters.GradientBevelFilter;
             *
             *     var mc:MovieClip = setUpFilter("blurYExample");
             *   mc.onRelease = function() {
             *   var arr:Array = this.filters;
             *   arr[0].blurY = 16;
             *   this.filters = arr;
             *   }
             *
             *     function setUpFilter(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 150;
             *   var h:Number = 150;
             *   art.beginFill(0xCCCCCC);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *
             *     var colors:Array = [0xFFFFFF, 0xCCCCCC, 0x000000];
             *   var alphas:Array = [1, 0, 1];
             *   var ratios:Array = [0, 128, 255];
             *   var filter:GradientBevelFilter = new GradientBevelFilter(5, 225, colors, alphas, ratios, 5, 5, 5, 3, "inner", false);
             *
             *     art.filters = new Array(filter);
             *   return art;
             *   }
             *   </listing>
             */
        public:
            float        blurY();
        public:
            void         blurY(float value);

            /**
             * Specifies whether the object has a knockout effect. A knockout effect
             * makes the object's fill transparent and reveals the background color of the document.
             * The value true specifies a knockout effect;
             * the default is false (no knockout effect).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example demonstrates how to set the <code>knockout</code> property on an existing object.
             *   <listing version="2.0">
             *   import flash.filters.GradientBevelFilter;
             *
             *     var mc:MovieClip = setUpFilter("knockoutExample");
             *   mc.onRelease = function() {
             *   var arr:Array = this.filters;
             *   arr[0].knockout = true;
             *   this.filters = arr;
             *   }
             *
             *     function setUpFilter(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 150;
             *   var h:Number = 150;
             *   art.beginFill(0xCCCCCC);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *
             *     var colors:Array = [0xFFFFFF, 0xCCCCCC, 0x000000];
             *   var alphas:Array = [1, 0, 1];
             *   var ratios:Array = [0, 128, 255];
             *   var filter:GradientBevelFilter = new GradientBevelFilter(5, 225, colors, alphas, ratios, 5, 5, 5, 3, "inner", false);
             *
             *     art.filters = new Array(filter);
             *   return art;
             *   }
             *   </listing>
             */
        public:
            bool         knockout();
        public:
            void         knockout(bool value);

            /**
             * The number of times to apply the filter. The default value is BitmapFilterQuality.LOW,
             * which is equivalent to applying the filter once. The value BitmapFilterQuality.MEDIUM
             * applies the filter twice; the value BitmapFilterQuality.HIGH applies it three times.
             * Filters with lower values are rendered more quickly.
             *
             *   For most applications, a quality value of low, medium, or high is sufficient.
             * Although you can use additional numeric values up to 15 to achieve different effects,
             * higher values are rendered more slowly. Instead of increasing the value of quality,
             * you can often get a similar effect, and with faster rendering, by simply increasing the values
             * of the blurX and blurY properties.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example demonstrates how to set the <code>quality</code> property on an existing
             *   object.
             *   <listing version="2.0">
             *   import flash.filters.GradientBevelFilter;
             *
             *     var mc:MovieClip = setUpFilter("qualityExample");
             *   mc.onRelease = function() {
             *   var arr:Array = this.filters;
             *   arr[0].quality = 1; // low quality
             *   this.filters = arr;
             *   }
             *
             *     function setUpFilter(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 150;
             *   var h:Number = 150;
             *   art.beginFill(0xCCCCCC);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *
             *     var colors:Array = [0xFFFFFF, 0xCCCCCC, 0x000000];
             *   var alphas:Array = [1, 0, 1];
             *   var ratios:Array = [0, 128, 255];
             *   var filter:GradientBevelFilter = new GradientBevelFilter(5, 225, colors, alphas, ratios, 5, 5, 5, 3, "inner", false);
             *
             *     art.filters = new Array(filter);
             *   return art;
             *   }
             *   </listing>
             */
        public:
            int          quality();
        public:
            void         quality(int value);

            /**
             * The strength of the imprint or spread. The higher the value, the more color is imprinted
             * and the stronger the contrast between the bevel and the background.
             * Valid values are 0 to 255.
             * A value of 0 means that the filter is not applied. The default value is 1.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example demonstrates how to set the <code>strength</code> property on an existing object.
             *   <listing version="2.0">
             *   import flash.filters.GradientBevelFilter;
             *
             *     var mc:MovieClip = setUpFilter("strengthExample");
             *   mc.onRelease = function() {
             *   var arr:Array = this.filters;
             *   arr[0].strength = 1;
             *   this.filters = arr;
             *   }
             *
             *     function setUpFilter(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 150;
             *   var h:Number = 150;
             *   art.beginFill(0xCCCCCC);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *
             *     var colors:Array = [0xFFFFFF, 0xCCCCCC, 0x000000];
             *   var alphas:Array = [1, 0, 1];
             *   var ratios:Array = [0, 128, 255];
             *   var filter:GradientBevelFilter = new GradientBevelFilter(5, 225, colors, alphas, ratios, 5, 5, 5, 3, "inner", false);
             *
             *     art.filters = new Array(filter);
             *   return art;
             *   }
             *   </listing>
             */
        public:
            float        strength();
        public:
            void         strength(float value);

            /**
             * The placement of the bevel effect. Possible values are BitmapFilterType constants:
             * BitmapFilterType.OUTER     Bevel on the outer edge of the objectBitmapFilterType.INNER     Bevel on the inner edge of the objectBitmapFilterType.FULL     Bevel on top of the object
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example demonstrates how to set the <code>type</code> property on an existing object.
             *   <listing version="2.0">
             *   import flash.filters.GradientBevelFilter;
             *
             *     var mc:MovieClip = setUpFilter("typeExample");
             *   mc.onRelease = function() {
             *   var arr:Array = this.filters;
             *   arr[0].type = "outer";
             *   this.filters = arr;
             *   }
             *
             *     function setUpFilter(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 150;
             *   var h:Number = 150;
             *   art.beginFill(0xCCCCCC);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *
             *     var colors:Array = [0xFFFFFF, 0xCCCCCC, 0x000000];
             *   var alphas:Array = [1, 0, 1];
             *   var ratios:Array = [0, 128, 255];
             *   var filter:GradientBevelFilter = new GradientBevelFilter(5, 225, colors, alphas, ratios, 5, 5, 5, 3, "inner", false);
             *
             *     art.filters = new Array(filter);
             *   return art;
             *   }
             *   </listing>
             */
        public:
            std::string  type();
        public:
            void         type(std::string value);

            /**
             * Initializes the filter with the specified parameters.
             * @param   distance    The offset distance. Valid values are 0 to 8.
             * @param   angle   The angle, in degrees. Valid values are 0 to 360.
             * @param   colors  An array of RGB hexadecimal color values to use in the gradient.
             *   For example, red is 0xFF0000, blue is 0x0000FF, and so on.
             * @param   alphas  An array of alpha transparency values for the corresponding colors in
             *   the colors array. Valid values for each element in the array are 0 to 1.
             *   For example, .25 sets a transparency value of 25%.
             * @param   ratios  An array of color distribution ratios; valid values are
             *   0 to 255.
             * @param   blurX   The amount of horizontal blur. Valid values are 0 to 255. A blur of 1 or
             *   less means that the original image is copied as is. The default value
             *   is 4. Values that are a power of 2 (such as 2, 4, 8, 16 and 32) are optimized
             *   to render more quickly than other values.
             * @param   blurY   The amount of vertical blur. Valid values are 0 to 255. A blur of 1 or less
             *   means that the original image is copied as is. Values that are a power of 2
             *   (such as 2, 4, 8, 16 and 32) are optimized
             *   to render more quickly than other values.
             * @param   strength    The strength of the imprint or spread. The higher the value, the more color
             *   is imprinted and the stronger the contrast between the bevel and the background.
             *   Valid values are 0 to 255. A value of 0 means that the filter is not applied.
             * @param   quality The quality of the filter. Use BitmapFilterQuality constants:
             *   BitmapFilterQuality.LOWBitmapFilterQuality.MEDIUMBitmapFilterQuality.HIGHFor more information, see the description of the quality property.
             * @param   type    The placement of the bevel effect. Possible values are BitmapFilterType constants:
             *   BitmapFilterType.OUTER     Bevel on the outer edge of the objectBitmapFilterType.INNER     Bevel on the inner edge of the objectBitmapFilterType.FULL     Bevel on top of the object
             * @param   knockout    Specifies whether a knockout effect is applied. The value true
             *   makes the object's fill transparent and reveals the background color of the document.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @category    Constructor
             */
        public:
            GradientBevelFilter(float distance, float angle, std::vector<void *> colors, std::vector<void *> alphas, std::vector<void *> ratios, float blurX, float blurY, float strength, int quality, std::string type, bool knockout);

            /**
             * Returns a copy of this filter object.
             * @return  A new GradientBevelFilter instance with all the
             *   same properties as the original GradientBevelFilter instance.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example creates two rectangle shapes. The first,
             *   <code>sourceClip</code> has a bevel effect. The second,
             *   <code>resultClip</code> has no effect until it is clicked.
             *   <listing version="2.0">
             *   import flash.filters.GradientBevelFilter;
             *
             *     var sourceClip:MovieClip = setUpFlatRectangle(150, 150, 0xCCCCCC, "cloneSourceClip");
             *   var resultClip:MovieClip = setUpFlatRectangle(150, 150, 0xCCCCCC, "cloneResultClip");
             *
             *     resultClip.source = sourceClip;
             *
             *     var sourceFilter:GradientBevelFilter = getNewFilter();
             *   sourceClip.filters = new Array(sourceFilter);
             *
             *     resultClip._x = 180;
             *   resultClip.onRelease = function() {
             *   this.filters = new Array(this.source.filters[0].clone());
             *   }
             *
             *     function setUpFlatRectangle(w:Number, h:Number, bgColor:Number, name:String):MovieClip {
             *   var mc:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   mc.beginFill(bgColor);
             *   mc.lineTo(w, 0);
             *   mc.lineTo(w, h);
             *   mc.lineTo(0, h);
             *   mc.lineTo(0, 0);
             *   return mc;
             *   }
             *
             *     function getNewFilter():GradientBevelFilter {
             *   var colors:Array = [0xFFFFFF, 0xCCCCCC, 0x000000];
             *   var alphas:Array = [1, 0, 1];
             *   var ratios:Array = [0, 128, 255];
             *   return new GradientBevelFilter(5, 225, colors, alphas, ratios, 5, 5, 5, 2, "inner", false);
             *   }
             *
             *     </listing>
             */
        public:
            flash::filters::BitmapFilter *clone();
        };
    }
}

#endif // FLEX11_6_FLASH_FILTERS_GRADIENTBEVELFILTER_AS
#endif // __cplusplus

