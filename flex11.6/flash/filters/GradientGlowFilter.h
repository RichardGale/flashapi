#if !defined(FLEX11_6_FLASH_FILTERS_GRADIENTGLOWFILTER_AS)
#define FLEX11_6_FLASH_FILTERS_GRADIENTGLOWFILTER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/filters/BitmapFilter.h"

/**
 * The GradientGlowFilter class lets you apply a gradient glow effect to display objects.
 * A gradient glow is a realistic-looking glow with a color gradient that
 * you can control. You can apply a gradient glow around
 * the inner or outer edge of an object or on top of an object.
 * You can apply the filter to any display object (objects that inherit from the DisplayObject class),
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
 *   The following example draws a square and applies a gradient glow filter to it.
 * The general workflow of the example is as follows:
 * <ol class="- topic/ol "><li class="- topic/li ">Import the required classes.</li><li class="- topic/li ">Declare global variables used to define the square and filter.</li><li class="- topic/li ">Create the constructor function, which does the following:
 * <ul class="- topic/ul "><li class="- topic/li ">Calls the <codeph class="+ topic/ph pr-d/codeph ">draw()</codeph> method, which uses methods of the Graphics class
 * accessed through the <codeph class="+ topic/ph pr-d/codeph ">graphics</codeph> property of Sprite to draw a square.</li><li class="- topic/li ">Creates a BitmapFilter object named <codeph class="+ topic/ph pr-d/codeph ">filter</codeph> and assigns it
 * the return value of a call to <codeph class="+ topic/ph pr-d/codeph ">getBitmapFilter()</codeph>, which creates the filter.</li><li class="- topic/li ">Creates a new array named <codeph class="+ topic/ph pr-d/codeph ">myFilters</codeph> and adds <codeph class="+ topic/ph pr-d/codeph ">filter</codeph> to it.</li><li class="- topic/li ">Assigns <codeph class="+ topic/ph pr-d/codeph ">myFilters</codeph> to the <codeph class="+ topic/ph pr-d/codeph ">filters</codeph> property of the
 * GradientGlowFilterExample object. This applies all filters found in <codeph class="+ topic/ph pr-d/codeph ">myFilters</codeph>,
 * which in this case is only <codeph class="+ topic/ph pr-d/codeph ">filter</codeph>.</li></ul></li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.filters.BitmapFilter;
 * import flash.filters.BitmapFilterQuality;
 * import flash.filters.BitmapFilterType;
 * import flash.filters.GradientGlowFilter;
 * import flash.display.Sprite;
 *
 *   public class GradientGlowFilterExample extends Sprite {
 * private var bgColor:uint = 0xCCCCCC;
 * private var size:uint    = 80;
 * private var offset:uint  = 50;
 *
 *   private var distance:Number  = 0;
 * private var angleInDegrees:Number = 45;
 * private var colors:Array     = [0xFFFFFF, 0xFF0000, 0xFFFF00, 0x00CCFF];
 * private var alphas:Array     = [0, 1, 1, 1];
 * private var ratios:Array     = [0, 63, 126, 255];
 * private var blurX:Number     = 50;
 * private var blurY:Number     = 50;
 * private var strength:Number  = 2.5;
 * private var quality:Number   = BitmapFilterQuality.HIGH;
 * private var type:String      = BitmapFilterType.OUTER;
 * private var knockout:Boolean = false;
 *
 *   public function GradientGlowFilterExample() {
 * draw();
 * var filter:BitmapFilter = getBitmapFilter();
 * var myFilters:Array = new Array();
 * myFilters.push(filter);
 * filters = myFilters;
 * }
 *
 *   private function getBitmapFilter():BitmapFilter {
 * return new GradientGlowFilter(distance,
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
        class GradientGlowFilter : public flash::filters::BitmapFilter
        {
            /**
             * The angle, in degrees. Valid values are 0 to 360. The default is 45.
             *
             *   The angle value represents the angle of the theoretical light source falling on the object and
             * determines the placement of the effect relative to the object. If distance is set to 0, the effect
             * is not offset from the object, and therefore the angle property has no effect.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example changes the <code>angle</code> property on an existing movie clip
             *   when a user clicks it.
             *   <listing version="2.0">
             *   import flash.filters.GradientGlowFilter;
             *   var mc:MovieClip = createGradientGlowRectangle("GlowAngle");
             *   mc.onRelease = function() {
             *   var filter:GradientGlowFilter = this.filters[0];
             *   filter.distance = 50;
             *   filter.angle = 90;
             *   this.filters = new Array(filter);
             *   }
             *
             *     function createGradientGlowRectangle(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 100;
             *   var h:Number = 100;
             *   art.beginFill(0x003366);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *   art._x = 20;
             *   art._y = 20;
             *
             *     var colors:Array = [0xFFFFFF, 0xFF0000, 0xFFFF00, 0x00CCFF];
             *   var alphas:Array = [0, 1, 1, 1];
             *   var ratios:Array = [0, 63, 126, 255];
             *   var filter:GradientGlowFilter = new GradientGlowFilter(0, 45, colors, alphas, ratios, 55, 55, 2.5, 2, "outer", false);
             *   var filterArray:Array = new Array();
             *   filterArray.push(filter);
             *   art.filters = filterArray;
             *   return art;
             *   }
             *   </listing>
             */
        public:
            float       angle();
        public:
            void         angle(float value);

            /**
             * An array of alpha transparency values for the corresponding colors in
             * the colors array. Valid values for each element in the array are 0 to 1.
             * For example, .25 sets the alpha transparency value to 25%.
             *
             *   The alphas property cannot be changed by directly modifying its values.
             * Instead, you must get a reference to alphas, make the change to the
             * reference, and then set alphas to the reference.The colors, alphas, and ratios properties are related.
             * The first element in the colors array
             * corresponds to the first element in the alphas array
             * and in the ratios array, and so on.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example changes the <code>alphas</code> property on an existing movie clip
             *   when a user clicks it.
             *   <listing version="2.0">
             *   import flash.filters.GradientGlowFilter;
             *   var mc:MovieClip = createGradientGlowRectangle("GlowAlphas");
             *   mc.onRelease = function() {
             *   var filter:GradientGlowFilter = this.filters[0];
             *   var alphas:Array = filter.alphas;
             *   alphas.pop();
             *   alphas.pop();
             *   alphas.push(.3);
             *   alphas.push(1);
             *   filter.alphas = alphas;
             *   this.filters = new Array(filter);
             *   }
             *
             *     function createGradientGlowRectangle(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 100;
             *   var h:Number = 100;
             *   art.beginFill(0x003366);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *   art._x = 20;
             *   art._y = 20;
             *
             *     var colors:Array = [0xFFFFFF, 0xFF0000, 0xFFFF00, 0x00CCFF];
             *   var alphas:Array = [0, 1, 1, 1];
             *   var ratios:Array = [0, 63, 126, 255];
             *   var filter:GradientGlowFilter = new GradientGlowFilter(0, 45, colors, alphas, ratios, 55, 55, 2.5, 2, "outer", false);
             *   var filterArray:Array = new Array();
             *   filterArray.push(filter);
             *   art.filters = filterArray;
             *   return art;
             *   }
             *   </listing>
             * @throws  TypeError The Array is null when being set
             */
        public:
            std::vector<void *>        alphas();
        public:
            void         alphas(std::vector<void *> value);

            /**
             * The amount of horizontal blur. Valid values are 0 to 255. A blur of 1 or
             * less means that the original image is copied as is. The default value
             * is 4. Values that are a power of 2 (such as 2, 4, 8, 16, and 32) are optimized
             * to render more quickly than other values.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            float       blurX();
        public:
            void         blurX(float value);

            /**
             * The amount of vertical blur. Valid values are 0 to 255. A blur of 1 or less
             * means that the original image is copied as is. The default value is
             * 4. Values that are a power of 2 (such as 2, 4, 8, 16, and 32) are optimized
             * to render more quickly than other values.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            float       blurY();
        public:
            void         blurY(float value);

            /**
             * An array of colors that defines a gradient.
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
             * @maelexample The following example changes the <code>colors</code> property on an existing movie clip
             *   when a user clicks it.
             *   <listing version="2.0">
             *   import flash.filters.GradientGlowFilter;
             *   var mc:MovieClip = createGradientGlowRectangle("GlowColors");
             *   mc.onRelease = function() {
             *   var filter:GradientGlowFilter = this.filters[0];
             *   var colors:Array = filter.colors;
             *   colors.pop();
             *   colors.push(0xFF00FF);
             *   filter.colors = colors;
             *   this.filters = new Array(filter);
             *   }
             *
             *     function createGradientGlowRectangle(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 100;
             *   var h:Number = 100;
             *   art.beginFill(0x003366);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *   art._x = 20;
             *   art._y = 20;
             *
             *     var colors:Array = [0xFFFFFF, 0xFF0000, 0xFFFF00, 0x00CCFF];
             *   var alphas:Array = [0, 1, 1, 1];
             *   var ratios:Array = [0, 63, 126, 255];
             *   var filter:GradientGlowFilter = new GradientGlowFilter(0, 45, colors, alphas, ratios, 55, 55, 2.5, 2, "outer", false);
             *   var filterArray:Array = new Array();
             *   filterArray.push(filter);
             *   art.filters = filterArray;
             *   return art;
             *   }
             *   </listing>
             * @throws  TypeError The Array is null when being set
             */
        public:
            std::vector<void *>        colors();
        public:
            void         colors(std::vector<void *> value);

            /**
             * The offset distance of the glow. The default value is 4.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example changes the <code>distance</code> property on an existing movie clip
             *   when a user clicks it.
             *   <listing version="2.0">
             *   import flash.filters.GradientGlowFilter;
             *   var mc:MovieClip = createGradientGlowRectangle("GlowDistance");
             *   mc.onRelease = function() {
             *   var filter:GradientGlowFilter = this.filters[0];
             *   filter.distance = 20;
             *   this.filters = new Array(filter);
             *   }
             *
             *     function createGradientGlowRectangle(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 100;
             *   var h:Number = 100;
             *   art.beginFill(0x003366);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *   art._x = 20;
             *   art._y = 20;
             *
             *     var colors:Array = [0xFFFFFF, 0xFF0000, 0xFFFF00, 0x00CCFF];
             *   var alphas:Array = [0, 1, 1, 1];
             *   var ratios:Array = [0, 63, 126, 255];
             *   var filter:GradientGlowFilter = new GradientGlowFilter(0, 45, colors, alphas, ratios, 55, 55, 2.5, 2, "outer", false);
             *   var filterArray:Array = new Array();
             *   filterArray.push(filter);
             *   art.filters = filterArray;
             *   return art;
             *   }
             *   </listing>
             */
        public:
            float       distance();
        public:
            void         distance(float value);

            /**
             * Specifies whether the object has a knockout effect. A knockout effect
             * makes the object's fill transparent and reveals the background color of the document.
             * The value true specifies a knockout effect;
             * the default value is false (no knockout effect).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example changes the <code>knockout</code> property on an existing movie clip
             *   when a user clicks it.
             *   <listing version="2.0">
             *   import flash.filters.GradientGlowFilter;
             *   var mc:MovieClip = createGradientGlowRectangle("GlowKnockout");
             *   mc.onRelease = function() {
             *   var filter:GradientGlowFilter = this.filters[0];
             *   filter.knockout = true;
             *   this.filters = new Array(filter);
             *   }
             *
             *     function createGradientGlowRectangle(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 100;
             *   var h:Number = 100;
             *   art.beginFill(0x003366);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *   art._x = 20;
             *   art._y = 20;
             *
             *     var colors:Array = [0xFFFFFF, 0xFF0000, 0xFFFF00, 0x00CCFF];
             *   var alphas:Array = [0, 1, 1, 1];
             *   var ratios:Array = [0, 63, 126, 255];
             *   var filter:GradientGlowFilter = new GradientGlowFilter(0, 45, colors, alphas, ratios, 55, 55, 2.5, 2, "outer", false);
             *   var filterArray:Array = new Array();
             *   filterArray.push(filter);
             *   art.filters = filterArray;
             *   return art;
             *   }
             *
             *     </listing>
             */
        public:
            bool      knockout();
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
             * @maelexample The following example changes the <code>quality</code> property on an existing movie clip
             *   when a user clicks it.
             *   <listing version="2.0">
             *   import flash.filters.GradientGlowFilter;
             *   var mc:MovieClip = createGradientGlowRectangle("GlowQuality");
             *   mc.onRelease = function() {
             *   var filter:GradientGlowFilter = this.filters[0];
             *   filter.quality = 3;
             *   this.filters = new Array(filter);
             *   }
             *
             *     function createGradientGlowRectangle(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 100;
             *   var h:Number = 100;
             *   art.beginFill(0x003366);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *   art._x = 20;
             *   art._y = 20;
             *
             *     var colors:Array = [0xFFFFFF, 0xFF0000, 0xFFFF00, 0x00CCFF];
             *   var alphas:Array = [0, 1, 1, 1];
             *   var ratios:Array = [0, 63, 126, 255];
             *   var filter:GradientGlowFilter = new GradientGlowFilter(0, 45, colors, alphas, ratios, 55, 55, 2.5, 2, "outer", false);
             *   var filterArray:Array = new Array();
             *   filterArray.push(filter);
             *   art.filters = filterArray;
             *   return art;
             *   }
             *   </listing>
             */
        public:
            int          quality();
        public:
            void         quality(int value);

            /**
             * An array of color distribution ratios for the corresponding colors in the
             * colors array. Valid values are
             * 0 to 255.
             *
             *   The ratios property cannot be changed by directly modifying its values.
             * Instead, you must get a reference to ratios, make the change to the
             * reference, and then set ratios to the reference.The colors, alphas, and ratios properties are related.
             * The first element in the colors array
             * corresponds to the first element in the alphas array
             * and in the ratios array, and so on.Think of the gradient glow filter as a glow that emanates from
             * the center of the object (if the distance value is set to 0),
             * with gradients that are stripes of color blending into each other. The first color
             * in the colors array is the outermost color of the glow.
             * The last color is the innermost color of the glow.Each value in the ratios array sets
             * the position of the color on the radius of the gradient, where 0 represents
             * the outermost point of the gradient and 255 represents the innermost point of
             * the gradient. The ratio values can range from 0 to 255 pixels,
             * in increasing value; for example [0, 64, 128, 200, 255]. Values from 0 to 128
             * appear on the outer edges of the glow. Values from 129 to 255 appear in the inner
             * area of the glow. Depending on the ratio values of the colors and the type
             * value of the filter, the filter colors might be obscured by the object to which
             * the filter is applied.In the following code and image, a filter is applied to a black circle movie
             * clip, with the type set to "full". For instructional purposes, the first color
             * in the colors array, pink, has an alpha value of 1,
             * so it shows against the white document background. (In practice, you probably would
             * not want the first color showing in this way.) The last color in the
             * array, yellow, obscures the black circle to which the filter is applied:
             * var colors:Array = [0xFFCCFF, 0x0000FF, 0x9900FF, 0xFF0000, 0xFFFF00];
             * var alphas:Array = [1, 1, 1, 1, 1];
             * var ratios:Array = [0, 32, 64, 128, 225];
             * var myGGF:GradientGlowFilter = new GradientGlowFilter(0, 0, colors, alphas, ratios, 50, 50, 1, 2, "full", false);
             * To achieve a seamless effect with your document background when you set the type
             * value to "outer" or "full", set the first color in the
             * array to the same color as the document background, or set the
             * alpha value of the first color to 0; either technique makes the filter blend in with the background.If you make two small changes in the code, the effect of the glow can be very
             * different, even with the same ratios and colors arrays. Set
             * the alpha value of the first
             * color in the array to 0, to make the filter blend in with the document's
             * white background; and set the type property to
             * "outer" or "inner".
             * Observe the results, as shown in the following images.Keep in mind that the spread of the colors in the gradient varies based on the values
             * of the blurX, blurY, strength, and quality
             * properties, as well as the ratios values.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example changes the <code>ratios</code> property on an existing movie clip
             *   when a user clicks it.
             *   <listing version="2.0">
             *   import flash.filters.GradientGlowFilter;
             *   var mc:MovieClip = createGradientGlowRectangle("GlowRatios");
             *   mc.onRelease = function() {
             *   var filter:GradientGlowFilter = this.filters[0];
             *   var ratios:Array = filter.ratios;
             *   ratios.shift();
             *   ratios.unshift(40);
             *   filter.ratios = ratios;
             *   this.filters = new Array(filter);
             *   }
             *
             *     function createGradientGlowRectangle(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 100;
             *   var h:Number = 100;
             *   art.beginFill(0x003366);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *   art._x = 20;
             *   art._y = 20;
             *
             *     var colors:Array = [0xFFFFFF, 0xFF0000, 0xFFFF00, 0x00CCFF];
             *   var alphas:Array = [0, 1, 1, 1];
             *   var ratios:Array = [0, 63, 126, 255];
             *   var filter:GradientGlowFilter = new GradientGlowFilter(0, 45, colors, alphas, ratios, 55, 55, 2.5, 2, "outer", false);
             *   var filterArray:Array = new Array();
             *   filterArray.push(filter);
             *   art.filters = filterArray;
             *   return art;
             *   }
             *   </listing>
             * @throws  TypeError The Array is null when being set
             */
        public:
            std::vector<void *>        ratios();
        public:
            void         ratios(std::vector<void *> value);

            /**
             * The strength of the imprint or spread. The higher the value, the more color is imprinted
             * and the stronger the contrast between the glow and the background. Valid values are 0 to 255.
             * A value of 0 means that the filter is not applied. The default value is 1.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example changes the <code>strength</code> property on an existing movie clip
             *   when a user clicks it.
             *   <listing version="2.0">
             *   import flash.filters.GradientGlowFilter;
             *   var mc:MovieClip = createGradientGlowRectangle("GlowStrength");
             *   mc.onRelease = function() {
             *   var filter:GradientGlowFilter = this.filters[0];
             *   filter.strength = 1;
             *   this.filters = new Array(filter);
             *   }
             *
             *     function createGradientGlowRectangle(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 100;
             *   var h:Number = 100;
             *   art.beginFill(0x003366);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *   art._x = 20;
             *   art._y = 20;
             *
             *     var colors:Array = [0xFFFFFF, 0xFF0000, 0xFFFF00, 0x00CCFF];
             *   var alphas:Array = [0, 1, 1, 1];
             *   var ratios:Array = [0, 63, 126, 255];
             *   var filter:GradientGlowFilter = new GradientGlowFilter(0, 45, colors, alphas, ratios, 55, 55, 2.5, 2, "outer", false);
             *   var filterArray:Array = new Array();
             *   filterArray.push(filter);
             *   art.filters = filterArray;
             *   return art;
             *   }
             *   </listing>
             */
        public:
            float       strength();
        public:
            void         strength(float value);

            /**
             * The placement of the filter effect. Possible values are flash.filters.BitmapFilterType constants:
             * BitmapFilterType.OUTER     Glow on the outer edge of the objectBitmapFilterType.INNER     Glow on the inner edge of the object; the default.BitmapFilterType.FULL     Glow on top of the object
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example changes the <code>type</code> property on an existing movie clip
             *   when a user clicks it.
             *   <listing version="2.0">
             *   import flash.filters.GradientGlowFilter;
             *   var mc:MovieClip = createGradientGlowRectangle("GlowType");
             *   mc.onRelease = function() {
             *   var filter:GradientGlowFilter = this.filters[0];
             *   filter.type = "inner";
             *   filter.strength = 1;
             *   this.filters = new Array(filter);
             *   }
             *
             *     function createGradientGlowRectangle(name:String):MovieClip {
             *   var art:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   var w:Number = 100;
             *   var h:Number = 100;
             *   art.beginFill(0x003366);
             *   art.lineTo(w, 0);
             *   art.lineTo(w, h);
             *   art.lineTo(0, h);
             *   art.lineTo(0, 0);
             *   art._x = 20;
             *   art._y = 20;
             *
             *     var colors:Array = [0xFFFFFF, 0xFF0000, 0xFFFF00, 0x00CCFF];
             *   var alphas:Array = [0, 1, 1, 1];
             *   var ratios:Array = [0, 63, 126, 255];
             *   var filter:GradientGlowFilter = new GradientGlowFilter(0, 45, colors, alphas, ratios, 55, 55, 2.5, 2, "outer", false);
             *   var filterArray:Array = new Array();
             *   filterArray.push(filter);
             *   art.filters = filterArray;
             *   return art;
             *   }
             *   </listing>
             * @throws  TypeError The string is null when being set
             */
        public:
            std::string       type();
        public:
            void         type(std::string value);

            /**
             * Initializes the filter with the specified parameters.
             * @param   distance    The offset distance of the glow.
             * @param   angle   The angle, in degrees. Valid values are 0 to 360.
             * @param   colors  An array of colors that defines a gradient.
             *   For example, red is 0xFF0000, blue is 0x0000FF, and so on.
             * @param   alphas  An array of alpha transparency values for the corresponding colors in
             *   the colors array. Valid values for each element in the array are 0 to 1.
             *   For example, a value of .25 sets the alpha transparency value to 25%.
             * @param   ratios  An array of color distribution ratios. Valid values are
             *   0 to 255. This value defines the percentage of the width where the color
             *   is sampled at 100 percent.
             * @param   blurX   The amount of horizontal blur. Valid values are 0 to 255. A blur of 1 or
             *   less means that the original image is copied as is. Values that are a power of 2 (such as 2, 4, 8, 16 and 32) are optimized
             *   to render more quickly than other values.
             * @param   blurY   The amount of vertical blur. Valid values are 0 to 255. A blur of 1 or less
             *   means that the original image is copied as is. Values that are a power of 2 (such as 2, 4, 8, 16 and 32) are optimized
             *   to render more quickly than other values.
             * @param   strength    The strength of the imprint or spread. The higher the value, the more color is
             *   imprinted and the stronger the contrast between the glow and the background.
             *   Valid values are 0 to 255. The larger the value, the stronger the imprint. A value of 0
             *   means the filter is not applied.
             * @param   quality The number of times to apply the filter. Use the BitmapFilterQuality constants:
             *   BitmapFilterQuality.LOWBitmapFilterQuality.MEDIUMBitmapFilterQuality.HIGHFor more information, see the description of the quality property.
             * @param   type    The placement of the filter effect. Possible values are the
             *   flash.filters.BitmapFilterType constants:
             *   BitmapFilterType.OUTER     Glow on the outer edge of the objectBitmapFilterType.INNER     Glow on the inner edge of the object; the default.BitmapFilterType.FULL     Glow on top of the object
             * @param   knockout    Specifies whether the object has a knockout effect. A knockout effect
             *   makes the object's fill transparent and reveals the background color of the document.
             *   The value true specifies a knockout effect;
             *   the default is false (no knockout effect).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example creates a gradient glow filter, assigns
             *   its values, and applies it to a flat rectangle image.
             *
             *     <listing version="2.0">
             *   import flash.filters.GradientGlowFilter;
             *   var art:MovieClip = createRectangle(100, 100, 0x003366, "gradientGlowFilterExample");
             *   var distance:Number = 0;
             *   var angleInDegrees:Number = 45;
             *   var colors:Array = [0xFFFFFF, 0xFF0000, 0xFFFF00, 0x00CCFF];
             *   var alphas:Array = [0, 1, 1, 1];
             *   var ratios:Array = [0, 63, 126, 255];
             *   var blurX:Number = 50;
             *   var blurY:Number = 50;
             *   var strength:Number = 2.5;
             *   var quality:Number = 3;
             *   var type:String = "outer";
             *   var knockout:Boolean = false;
             *
             *     var filter:GradientGlowFilter = new GradientGlowFilter(distance,
             *   angleInDegrees,
             *   colors,
             *   alphas,
             *   ratios,
             *   blurX,
             *   blurY,
             *   strength,
             *   quality,
             *   type,
             *   knockout);
             *   var filterArray:Array = new Array();
             *   filterArray.push(filter);
             *   art.filters = filterArray;
             *
             *     function createRectangle(w:Number, h:Number, bgColor:Number, name:String):MovieClip {
             *   var mc:MovieClip = this.createEmptyMovieClip(name, this.getNextHighestDepth());
             *   mc.beginFill(bgColor);
             *   mc.lineTo(w, 0);
             *   mc.lineTo(w, h);
             *   mc.lineTo(0, h);
             *   mc.lineTo(0, 0);
             *   mc._x = 20;
             *   mc._y = 20;
             *   return mc;
             *   }
             *   </listing>
             */
        public:
            GradientGlowFilter(float distance=4, float angle=45, std::vector<void *> colors=std::vector<void *>(), std::vector<void *> alphas=std::vector<void *>(), std::vector<void *> ratios=std::vector<void *>(), float blurX=4, float blurY=4, float strength=1, int quality=1, std::string type="inner", bool knockout=false);

            /**
             * Returns a copy of this filter object.
             * @return  A new GradientGlowFilter instance with all the
             *   same properties as the original GradientGlowFilter instance.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example creates three GradientGlowFilter objects and compares them; <code>filter_1</code>
             *   is created by using the GradientGlowFilter construtor; <code>filter_2</code> is created by setting it equal to
             *   <code>filter_1</code>; and, <code>clonedFilter</code> is created by cloning <code>filter_1</code>.  Notice
             *   that although <code>filter_2</code> evaluates as being equal to <code>filter_1</code>, <code>clonedFilter</code>,
             *   even though it contains the same values as <code>filter_1</code>, does not.
             *   <listing version="2.0">
             *   import flash.filters.GradientGlowFilter;
             *
             *     var colors:Array = [0xFFFFFF, 0xFF0000, 0xFFFF00, 0x00CCFF];
             *   var alphas:Array = [0, 1, 1, 1];
             *   var ratios:Array = [0, 63, 126, 255];
             *   var filter_1:GradientGlowFilter = new GradientGlowFilter(0, 45, colors, alphas, ratios, 55, 55, 2.5, 2, "outer", false);
             *   var filter_2:GradientGlowFilter = filter_1;
             *   var clonedFilter:GradientGlowFilter = filter_1.clone();
             *
             *     trace(filter_1 == filter_2);     // true
             *   trace(filter_1 == clonedFilter);   // false
             *
             *     for(var i in filter_1) {
             *   trace("&gt;&gt; " + i + ": " + filter_1[i]);
             *   // &gt;&gt; clone: [type Function]
             *   // &gt;&gt; type: outer
             *   // &gt;&gt; knockout: false
             *   // &gt;&gt; strength: 2.5
             *   // &gt;&gt; quality: 2
             *   // &gt;&gt; blurY: 55
             *   // &gt;&gt; blurX: 55
             *   // &gt;&gt; ratios: 0,63,126,255
             *   // &gt;&gt; alphas: 0,1,1,1
             *   // &gt;&gt; colors: 16777215,16711680,16776960,52479
             *   // &gt;&gt; angle: 45
             *   // &gt;&gt; distance: 0
             *   }
             *
             *     for(var i in clonedFilter) {
             *   trace("&gt;&gt; " + i + ": " + clonedFilter[i]);
             *   // &gt;&gt; clone: [type Function]
             *   // &gt;&gt; type: outer
             *   // &gt;&gt; knockout: false
             *   // &gt;&gt; strength: 2.5
             *   // &gt;&gt; quality: 2
             *   // &gt;&gt; blurY: 55
             *   // &gt;&gt; blurX: 55
             *   // &gt;&gt; ratios: 0,63,126,255
             *   // &gt;&gt; alphas: 0,1,1,1
             *   // &gt;&gt; colors: 16777215,16711680,16776960,52479
             *   // &gt;&gt; angle: 45
             *   // &gt;&gt; distance: 0
             *   }
             *   </listing>
             *   To further demonstrate the relationships between <code>filter_1</code>, <code>filter_2</code>, and <code>clonedFilter</code>,
             *   the following example below modifies the <code>knockout</code> property of <code>filter_1</code>. Modifying <code>knockout</code> demonstrates
             *   that the <code>clone()</code> method creates a new instance based on the values of <code>filter_1</code> instead of pointing to
             *   them in reference.
             *   <listing version="2.0">
             *   import flash.filters.GradientGlowFilter;
             *
             *     var colors:Array = [0xFFFFFF, 0xFF0000, 0xFFFF00, 0x00CCFF];
             *   var alphas:Array = [0, 1, 1, 1];
             *   var ratios:Array = [0, 63, 126, 255];
             *   var filter_1:GradientGlowFilter = new GradientGlowFilter(0, 45, colors, alphas, ratios, 55, 55, 2.5, 2, "outer", false);
             *   var filter_2:GradientGlowFilter = filter_1;
             *   var clonedFilter:GradientGlowFilter = filter_1.clone();
             *
             *     trace(filter_1.knockout);            // false
             *   trace(filter_2.knockout);          // false
             *   trace(clonedFilter.knockout);      // false
             *
             *     filter_1.knockout = true;
             *
             *     trace(filter_1.knockout);            // true
             *   trace(filter_2.knockout);          // true
             *   trace(clonedFilter.knockout);      // false
             *   </listing>
             */
        public:
            flash::filters::BitmapFilter *clone();
        };
    }
}

#endif // FLEX11_6_FLASH_FILTERS_GRADIENTGLOWFILTER_AS
#endif // __cplusplus

