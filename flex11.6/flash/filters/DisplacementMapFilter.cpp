

#include "DisplacementMapFilter.h"
#include "flash/display/BitmapData.h"
#include "flash/geom/Point.h"
#include "flash/filters/BitmapFilter.h"

    /**
     * The DisplacementMapFilter class uses the pixel values from the specified BitmapData object 
     * (called the <i class="+ topic/ph hi-d/i ">displacement map image</i>) to perform a displacement of an object.
     * You can use this filter to apply a warped 
     * or mottled effect to any object that inherits from the DisplayObject class, 
     * such as MovieClip, SimpleButton, TextField, and Video objects, as well as to BitmapData objects.
     * 
     *   <p class="- topic/p ">The use of filters depends on the object to which you apply the filter:</p><ul class="- topic/ul "><li class="- topic/li ">To apply filters to a display object, use the
     * <codeph class="+ topic/ph pr-d/codeph ">filters</codeph> property of the display object. Setting the <codeph class="+ topic/ph pr-d/codeph ">filters</codeph> 
     * property of an object does not modify the object, and you can remove the filter by clearing the
     * <codeph class="+ topic/ph pr-d/codeph ">filters</codeph> property. </li><li class="- topic/li ">To apply filters to BitmapData objects, use the <codeph class="+ topic/ph pr-d/codeph ">BitmapData.applyFilter()</codeph> method.
     * Calling <codeph class="+ topic/ph pr-d/codeph ">applyFilter()</codeph> on a BitmapData object takes the source BitmapData object 
     * and the filter object and generates a filtered image.</li></ul><p class="- topic/p ">If you apply a filter to a display object, the value of the <codeph class="+ topic/ph pr-d/codeph ">cacheAsBitmap</codeph> property of the 
     * display object is set to <codeph class="+ topic/ph pr-d/codeph ">true</codeph>. If you clear all filters, the original value of 
     * <codeph class="+ topic/ph pr-d/codeph ">cacheAsBitmap</codeph> is restored.</p><p class="- topic/p ">The filter uses the following formula:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * dstPixel[x, y] = srcPixel[x + ((componentX(x, y) - 128) ~~ scaleX) / 256, y + ((componentY(x, y) - 128) ~~scaleY) / 256)
     * </codeblock><p class="- topic/p ">where <codeph class="+ topic/ph pr-d/codeph ">componentX(x, y)</codeph> gets the <codeph class="+ topic/ph pr-d/codeph ">componentX</codeph> property color value 
     * from the <codeph class="+ topic/ph pr-d/codeph ">mapBitmap</codeph> property at <codeph class="+ topic/ph pr-d/codeph ">(x - mapPoint.x ,y - mapPoint.y)</codeph>.</p><p class="- topic/p ">The map image used by the filter is scaled to match the Stage scaling.
     * It is not scaled when the object itself is scaled.</p><p class="- topic/p ">This filter supports Stage scaling. However, general scaling, rotation, and 
     * skewing are not supported. If the object itself is scaled (if the <codeph class="+ topic/ph pr-d/codeph ">scaleX</codeph>
     * and <codeph class="+ topic/ph pr-d/codeph ">scaleY</codeph> properties are set to a value other than 1.0),
     * the filter effect is not scaled. It is scaled only when the user zooms in on the Stage.</p>
     * 
     *   EXAMPLE:
     * 
     *   The following example draws a square with a radial gradient fill, creates a text field, 
     * creates a BitmapData object, and applies a displacement map filter to the 
     * DisplacementMapFilterExample object. The general workflow for this example is as follows:
     * <ol class="- topic/ol "><li class="- topic/li ">The class defines variables for the background color, for the text field label,
     * and for the size and offset that will be used in various functions.</li><li class="- topic/li ">The constructor function calls the <codeph class="+ topic/ph pr-d/codeph ">draw()</codeph> method, 
     * which uses the methods of the Graphics class to draw a square with a radial gradient fill.
     * Note that <codeph class="+ topic/ph pr-d/codeph ">graphics</codeph> is a property of the DisplacementMapFilterExample object,
     * which extends Sprite.</li><li class="- topic/li ">The constructor function calls the <codeph class="+ topic/ph pr-d/codeph ">createLabel()</codeph> method, which creates a text field
     * displaying the value of <codeph class="+ topic/ph pr-d/codeph ">labelText</codeph> and adds it to the display list.</li><li class="- topic/li ">The constructor function calls the <codeph class="+ topic/ph pr-d/codeph ">createFilter()</codeph> method, which does the following:
     * <ul class="- topic/ul "><li class="- topic/li ">Creates a variable named <codeph class="+ topic/ph pr-d/codeph ">filter</codeph> for the filter object.</li><li class="- topic/li ">Calls the <codeph class="+ topic/ph pr-d/codeph ">getDisplacementMapFilter()</codeph> method and assigns its return value
     * to the <codeph class="+ topic/ph pr-d/codeph ">filter</codeph> variable.</li><li class="- topic/li ">Passes <codeph class="+ topic/ph pr-d/codeph ">filter</codeph> to the <codeph class="+ topic/ph pr-d/codeph ">filters</codeph> property of the 
     * DisplacementFilterExample object (the main class).</li></ul></li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">getBitmapFilter()</codeph> method creates a BitmapData object
     * named <codeph class="+ topic/ph pr-d/codeph ">mapBitmap</codeph> and assigns it the results of
     * the <codeph class="+ topic/ph pr-d/codeph ">createBitmapData()</codeph> method. The <codeph class="+ topic/ph pr-d/codeph ">mapBitmap</codeph> object, 
     * along with other variables, defines a new displacement map filter.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">createBitmapData()</codeph> method creates a new BitmapData object that is based on
     * the current contents of the DisplacementMapFilterExample object. It creates a new bitmap 
     * based on <codeph class="+ topic/ph pr-d/codeph ">bitmapData</codeph> and adds the bitmap to the Stage.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * import flash.display.Bitmap;
     * import flash.display.BitmapData;
     * import flash.display.BitmapDataChannel;
     * import flash.display.GradientType;
     * import flash.display.SpreadMethod;
     * import flash.display.Sprite;
     * import flash.filters.BitmapFilter;
     * import flash.filters.DisplacementMapFilter;
     * import flash.filters.DisplacementMapFilterMode;
     * import flash.geom.Matrix;
     * import flash.geom.Point;
     * import flash.text.TextField;
     * 
     *   public class DisplacementMapFilterExample extends Sprite {
     * private var bgColor:uint     = 0xFFCC00;
     * private var size:uint        = 200;
     * private var offset:uint      = 90;
     * private var labelText:String = "Watch the text bend with the displacement map";
     * 
     *   public function DisplacementMapFilterExample() {
     * draw();
     * createLabel();
     * createFilter();
     * }
     * 
     *   private function createFilter():void {
     * var filter:BitmapFilter = getBitmapFilter();
     * filters = new Array(filter);
     * }
     * 
     *   private function getBitmapFilter():BitmapFilter {
     * var mapBitmap:BitmapData = createBitmapData();
     * var mapPoint:Point       = new Point(0, 0);
     * var channels:uint        = BitmapDataChannel.RED;
     * var componentX:uint      = channels;
     * var componentY:uint      = channels;
     * var scaleX:Number        = 0.5;
     * var scaleY:Number        = -30;
     * var mode:String          = DisplacementMapFilterMode.CLAMP;
     * var color:uint           = 0;
     * var alpha:Number         = 0;
     * return new DisplacementMapFilter(mapBitmap,
     * mapPoint,
     * componentX,
     * componentY,
     * scaleX,
     * scaleY,
     * mode,
     * color,
     * alpha);
     * }
     * 
     *   private function draw():void {
     * var matrix:Matrix = new Matrix();
     * matrix.createGradientBox(size, size);
     * graphics.beginGradientFill(GradientType.RADIAL,
     * [0xFF0000, 0x0000FF],
     * [100, 100],
     * [55, 200],
     * matrix,
     * SpreadMethod.PAD);
     * graphics.drawRect(0, 0, size, size);
     * }
     * 
     *   private function createBitmapData():BitmapData {
     * var bitmapData:BitmapData = new BitmapData(size, size, true, bgColor);
     * bitmapData.draw(this, new Matrix());
     * var bitmap:Bitmap = new Bitmap(bitmapData);
     * bitmap.x = size;
     * addChild(bitmap);
     * return bitmapData;
     * }
     * 
     *   private function createLabel():void {
     * var tf:TextField = new TextField();
     * tf.text = labelText;
     * tf.y = offset;
     * tf.width = size;
     * addChild(tf);
     * }
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     */

using namespace flash::display;
using namespace flash::filters;
using namespace flash::geom;

namespace flash {
namespace filters {


        /**
         * A BitmapData object containing the displacement map data.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @maelexample The following example changes the <code>mapBitmap</code> property on the existing MovieClip 
         *   <code>filteredMc</code> when a user clicks on it.
         *   <listing version="2.0">
         *   import flash.filters.DisplacementMapFilter;
         *   import flash.display.BitmapData;
         *   import flash.geom.Point;
         *   import flash.geom.Matrix;
         *   import flash.geom.ColorTransform;
         *   
         *     var filteredMc:MovieClip = createDisplacementMapRectangle();
         *   var scope:Object = this;
         *   
         *     filteredMc.onPress = function() {
         *   var filter:DisplacementMapFilter = this.filters[0];
         *   filter.mapBitmap = scope.createGradientBitmap(300, 80, 0xFF000000, "linear");
         *   this.filters = new Array(filter);
         *   }
         *   
         *     function createDisplacementMapRectangle():MovieClip {
         *   var mapBitmap:BitmapData = createGradientBitmap(300, 80, 0xFF000000, "radial");
         *   var filter:DisplacementMapFilter = new DisplacementMapFilter(mapBitmap, new Point(-30, -30), 1, 1, 10, 10, "wrap", 0x000000, 0x000000);
         *   
         *     var txtBlock:MovieClip = createTextBlock();
         *   txtBlock._x = 30;
         *   txtBlock._y = 30;
         *   
         *     txtBlock.filters = new Array(filter);
         *   
         *     return txtBlock;
         *   }
         *   
         *     function createGradientBitmap(w:Number, h:Number, bgColor:Number, type:String, hide:Boolean):BitmapData {
         *   var mc:MovieClip = this.createEmptyMovieClip("mc", 1);
         *   var matrix:Matrix = new Matrix();
         *   matrix.createGradientBox(w, h, 0, 0, 0);
         *   
         *     mc.beginGradientFill(type, [0xFF0000, 0x0000FF], [100, 100], [0x55, 0x99], matrix, "pad");       
         *   mc.lineTo(w, 0);
         *   mc.lineTo(w, h);
         *   mc.lineTo(0, h);
         *   mc.lineTo(0, 0);
         *   mc.endFill();
         *   (hide == true) ? mc._alpha = 0 : mc._alpha = 100;
         *   
         *     var bmp:BitmapData = new BitmapData(w, h, true, bgColor);
         *   bmp.draw(mc, new Matrix(), new ColorTransform(), "normal", bmp.rectangle, true);
         *   mc.attachBitmap(bmp, this.getNextHighestDepth());
         *   
         *     return bmp;
         *   }
         *   
         *     function createTextBlock():MovieClip {
         *   var txtBlock:MovieClip = this.createEmptyMovieClip("txtBlock", this.getNextHighestDepth());
         *   txtBlock.createTextField("txt", this.getNextHighestDepth(), 0, 0, 300, 80);
         *   txtBlock.txt.text = "watch the text bend with the displacement map";
         *   return txtBlock;
         *   }
         *   </listing>
         * @throws  TypeError The BitmapData is null when being set
         */
        flash::display::BitmapData* DisplacementMapFilter::mapBitmap()                           ;
        void DisplacementMapFilter::mapBitmap(BitmapData* value)       ;

        /**
         * A value that contains the offset of the upper-left corner of 
         * the target display object from the upper-left corner of the map image.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @maelexample The following example changes the <code>mapPoint</code> property on the existing MovieClip 
         *   <code>filteredMc</code> when a user clicks on it.
         *   <listing version="2.0">
         *   import flash.filters.DisplacementMapFilter;
         *   import flash.display.BitmapData;
         *   import flash.geom.Point;
         *   import flash.geom.Matrix;
         *   import flash.geom.ColorTransform;
         *   
         *     var filteredMc:MovieClip = createDisplacementMapRectangle();
         *   
         *     filteredMc.onPress = function() {
         *   var filter:DisplacementMapFilter = this.filters[0];
         *   filter.mapPoint = new Point(-30, -40);
         *   this.filters = new Array(filter);
         *   this._x = 30;
         *   this._y = 40;
         *   }
         *   
         *     function createDisplacementMapRectangle():MovieClip {
         *   var mapBitmap:BitmapData = createGradientBitmap(300, 80, 0xFF000000, "radial");
         *   var filter:DisplacementMapFilter = new DisplacementMapFilter(mapBitmap, new Point(-30, -30), 1, 1, 10, 10, "wrap", 0x000000, 0x000000);
         *   
         *     var txtBlock:MovieClip = createTextBlock();
         *   txtBlock._x = 30;
         *   txtBlock._y = 30;
         *   
         *     txtBlock.filters = new Array(filter);
         *   
         *     return txtBlock;
         *   }
         *   
         *     function createGradientBitmap(w:Number, h:Number, bgColor:Number, type:String, hide:Boolean):BitmapData {
         *   var mc:MovieClip = this.createEmptyMovieClip("mc", 1);
         *   var matrix:Matrix = new Matrix();
         *   matrix.createGradientBox(w, h, 0, 0, 0);
         *   
         *     mc.beginGradientFill(type, [0xFF0000, 0x0000FF], [100, 100], [0x55, 0x99], matrix, "pad");       
         *   mc.lineTo(w, 0);
         *   mc.lineTo(w, h);
         *   mc.lineTo(0, h);
         *   mc.lineTo(0, 0);
         *   mc.endFill();
         *   (hide == true) ? mc._alpha = 0 : mc._alpha = 100;
         *   
         *     var bmp:BitmapData = new BitmapData(w, h, true, bgColor);
         *   bmp.draw(mc, new Matrix(), new ColorTransform(), "normal", bmp.rectangle, true);
         *   mc.attachBitmap(bmp, this.getNextHighestDepth());
         *   
         *     return bmp;
         *   }
         *   
         *     function createTextBlock():MovieClip {
         *   var txtBlock:MovieClip = this.createEmptyMovieClip("txtBlock", this.getNextHighestDepth());
         *   txtBlock.createTextField("txt", this.getNextHighestDepth(), 0, 0, 300, 80);
         *   txtBlock.txt.text = "watch the text bend with the displacement map";
         *   return txtBlock;
         *   }
         *   </listing>
         * @throws  TypeError The Point is null when being set
         */
        flash::geom::Point* DisplacementMapFilter::mapPoint()                   ;
        void DisplacementMapFilter::mapPoint(Point* value)       ;

        /**
         * Describes which color channel to use in the map image to displace the x result. 
         * Possible values are BitmapDataChannel constants:
         * BitmapDataChannel.ALPHABitmapDataChannel.BLUEBitmapDataChannel.GREENBitmapDataChannel.RED
         * @langversion 3.0
         * @playerversion   Flash 9
         * @oldexample  The following example changes the <code>componentX</code> property on the existing MovieClip 
         *   <code>filteredMc</code> when a user clicks on it.  It changes the value from 1 to 4 which changes the 
         *   color channel from red to blue.
         *   <listing version="2.0">
         *   import flash.filters.DisplacementMapFilter;
         *   import flash.display.BitmapData;
         *   import flash.geom.Point;
         *   import flash.geom.Matrix;
         *   import flash.geom.ColorTransform;
         *   
         *     var filteredMc:MovieClip = createDisplacementMapRectangle();
         *   
         *     filteredMc.onPress = function() {
         *   var filter:DisplacementMapFilter = this.filters[0];
         *   filter.componentX = 4;
         *   this.filters = new Array(filter);
         *   }
         *   
         *     function createDisplacementMapRectangle():MovieClip {
         *   var mapBitmap:BitmapData = createGradientBitmap(300, 80, 0xFF000000, "radial");
         *   var filter:DisplacementMapFilter = new DisplacementMapFilter(mapBitmap, new Point(-30, -30), 1, 1, 10, 10, "wrap", 0x000000, 0x000000);
         *   
         *     var txtBlock:MovieClip = createTextBlock();
         *   txtBlock._x = 30;
         *   txtBlock._y = 30;
         *   
         *     txtBlock.filters = new Array(filter);
         *   
         *     return txtBlock;
         *   }
         *   
         *     function createGradientBitmap(w:Number, h:Number, bgColor:Number, type:String, hide:Boolean):BitmapData {
         *   var mc:MovieClip = this.createEmptyMovieClip("mc", 1);
         *   var matrix:Matrix = new Matrix();
         *   matrix.createGradientBox(w, h, 0, 0, 0);
         *   
         *     mc.beginGradientFill(type, [0xFF0000, 0x0000FF], [100, 100], [0x55, 0x99], matrix, "pad");       
         *   mc.lineTo(w, 0);
         *   mc.lineTo(w, h);
         *   mc.lineTo(0, h);
         *   mc.lineTo(0, 0);
         *   mc.endFill();
         *   (hide == true) ? mc._alpha = 0 : mc._alpha = 100;
         *   
         *     var bmp:BitmapData = new BitmapData(w, h, true, bgColor);
         *   bmp.draw(mc, new Matrix(), new ColorTransform(), "normal", bmp.rectangle, true);
         *   mc.attachBitmap(bmp, this.getNextHighestDepth());
         *   
         *     return bmp;
         *   }
         *   
         *     function createTextBlock():MovieClip {
         *   var txtBlock:MovieClip = this.createEmptyMovieClip("txtBlock", this.getNextHighestDepth());
         *   txtBlock.createTextField("txt", this.getNextHighestDepth(), 0, 0, 300, 80);
         *   txtBlock.txt.text = "watch the text bend with the displacement map";
         *   return txtBlock;
         *   }
         *   </listing>
         */
        unsigned int DisplacementMapFilter::componentX()       ;
        void DisplacementMapFilter::componentX(unsigned int value)       ;

        /**
         * Describes which color channel to use in the map image to displace the y result. 
         * Possible values are BitmapDataChannel constants:
         * BitmapDataChannel.ALPHABitmapDataChannel.BLUEBitmapDataChannel.GREENBitmapDataChannel.RED
         * @langversion 3.0
         * @playerversion   Flash 9
         * @oldexample  The following example changes the <code>componentY</code> property on the existing MovieClip 
         *   <code>filteredMc</code> when a user clicks it.  The value changes from 1 to 4, which changes the 
         *   color channel from red to blue.
         *   <listing version="2.0">
         *   import flash.filters.DisplacementMapFilter;
         *   import flash.display.BitmapData;
         *   import flash.geom.Point;
         *   import flash.geom.Matrix;
         *   import flash.geom.ColorTransform;
         *   
         *     var filteredMc:MovieClip = createDisplacementMapRectangle();
         *   
         *     filteredMc.onPress = function() {
         *   var filter:DisplacementMapFilter = this.filters[0];
         *   filter.componentY = 4;
         *   this.filters = new Array(filter);
         *   }
         *   
         *     function createDisplacementMapRectangle():MovieClip {
         *   var mapBitmap:BitmapData = createGradientBitmap(300, 80, 0xFF000000, "radial");
         *   var filter:DisplacementMapFilter = new DisplacementMapFilter(mapBitmap, new Point(-30, -30), 1, 1, 10, 10, "wrap", 0x000000, 0x000000);
         *   
         *     var txtBlock:MovieClip = createTextBlock();
         *   txtBlock._x = 30;
         *   txtBlock._y = 30;
         *   
         *     txtBlock.filters = new Array(filter);
         *   
         *     return txtBlock;
         *   }
         *   
         *     function createGradientBitmap(w:Number, h:Number, bgColor:Number, type:String, hide:Boolean):BitmapData {
         *   var mc:MovieClip = this.createEmptyMovieClip("mc", 1);
         *   var matrix:Matrix = new Matrix();
         *   matrix.createGradientBox(w, h, 0, 0, 0);
         *   
         *     mc.beginGradientFill(type, [0xFF0000, 0x0000FF], [100, 100], [0x55, 0x99], matrix, "pad");       
         *   mc.lineTo(w, 0);
         *   mc.lineTo(w, h);
         *   mc.lineTo(0, h);
         *   mc.lineTo(0, 0);
         *   mc.endFill();
         *   (hide == true) ? mc._alpha = 0 : mc._alpha = 100;
         *   
         *     var bmp:BitmapData = new BitmapData(w, h, true, bgColor);
         *   bmp.draw(mc, new Matrix(), new ColorTransform(), "normal", bmp.rectangle, true);
         *   mc.attachBitmap(bmp, this.getNextHighestDepth());
         *   
         *     return bmp;
         *   }
         *   
         *     function createTextBlock():MovieClip {
         *   var txtBlock:MovieClip = this.createEmptyMovieClip("txtBlock", this.getNextHighestDepth());
         *   txtBlock.createTextField("txt", this.getNextHighestDepth(), 0, 0, 300, 80);
         *   txtBlock.txt.text = "watch the text bend with the displacement map";
         *   return txtBlock;
         *   }
         *   </listing>
         */
        unsigned int DisplacementMapFilter::componentY()       ;
        void DisplacementMapFilter::componentY(unsigned int value)       ;

        /**
         * The multiplier to use to scale the x displacement result from the map calculation.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @maelexample The following example changes the <code>scaleX</code> property on the existing MovieClip 
         *   <code>filteredMc</code> when a user clicks on it.
         *   <listing version="2.0">
         *   import flash.filters.DisplacementMapFilter;
         *   import flash.display.BitmapData;
         *   import flash.geom.Point;
         *   import flash.geom.Matrix;
         *   import flash.geom.ColorTransform;
         *   
         *     var filteredMc:MovieClip = createDisplacementMapRectangle();
         *   
         *     filteredMc.onPress = function() {
         *   var filter:DisplacementMapFilter = this.filters[0];
         *   filter.scaleX = 5;
         *   this.filters = new Array(filter);
         *   }
         *   
         *     function createDisplacementMapRectangle():MovieClip {
         *   var mapBitmap:BitmapData = createGradientBitmap(300, 80, 0xFF000000, "radial");
         *   var filter:DisplacementMapFilter = new DisplacementMapFilter(mapBitmap, new Point(-30, -30), 1, 1, 10, 10, "wrap", 0x000000, 0x000000);
         *   
         *     var txtBlock:MovieClip = createTextBlock();
         *   txtBlock._x = 30;
         *   txtBlock._y = 30;
         *   
         *     txtBlock.filters = new Array(filter);
         *   
         *     return txtBlock;
         *   }
         *   
         *     function createGradientBitmap(w:Number, h:Number, bgColor:Number, type:String, hide:Boolean):BitmapData {
         *   var mc:MovieClip = this.createEmptyMovieClip("mc", 1);
         *   var matrix:Matrix = new Matrix();
         *   matrix.createGradientBox(w, h, 0, 0, 0);
         *   
         *     mc.beginGradientFill(type, [0xFF0000, 0x0000FF], [100, 100], [0x55, 0x99], matrix, "pad");       
         *   mc.lineTo(w, 0);
         *   mc.lineTo(w, h);
         *   mc.lineTo(0, h);
         *   mc.lineTo(0, 0);
         *   mc.endFill();
         *   (hide == true) ? mc._alpha = 0 : mc._alpha = 100;
         *   
         *     var bmp:BitmapData = new BitmapData(w, h, true, bgColor);
         *   bmp.draw(mc, new Matrix(), new ColorTransform(), "normal", bmp.rectangle, true);
         *   mc.attachBitmap(bmp, this.getNextHighestDepth());
         *   
         *     return bmp;
         *   }
         *   
         *     function createTextBlock():MovieClip {
         *   var txtBlock:MovieClip = this.createEmptyMovieClip("txtBlock", this.getNextHighestDepth());
         *   txtBlock.createTextField("txt", this.getNextHighestDepth(), 0, 0, 300, 80);
         *   txtBlock.txt.text = "watch the text bend with the displacement map";
         *   return txtBlock;
         *   }
         *   </listing>
         */
        float DisplacementMapFilter::scaleX()         ;
        void DisplacementMapFilter::scaleX(float value)       ;

        /**
         * The multiplier to use to scale the y displacement result from the map calculation.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @maelexample The following example changes the <code>scaleY</code> property on the existing MovieClip 
         *   <code>filteredMc</code> when a user clicks on it.
         *   <listing version="2.0">
         *   import flash.filters.DisplacementMapFilter;
         *   import flash.display.BitmapData;
         *   import flash.geom.Point;
         *   import flash.geom.Matrix;
         *   import flash.geom.ColorTransform;
         *   
         *     var filteredMc:MovieClip = createDisplacementMapRectangle();
         *   
         *     filteredMc.onPress = function() {
         *   var filter:DisplacementMapFilter = this.filters[0];
         *   filter.scaleY = 5;
         *   this.filters = new Array(filter);
         *   }
         *   
         *     function createDisplacementMapRectangle():MovieClip {
         *   var mapBitmap:BitmapData = createGradientBitmap(300, 80, 0xFF000000, "radial");
         *   var filter:DisplacementMapFilter = new DisplacementMapFilter(mapBitmap, new Point(-30, -30), 1, 1, 10, 10, "wrap", 0x000000, 0x000000);
         *   
         *     var txtBlock:MovieClip = createTextBlock();
         *   txtBlock._x = 30;
         *   txtBlock._y = 30;
         *   
         *     txtBlock.filters = new Array(filter);
         *   
         *     return txtBlock;
         *   }
         *   
         *     function createGradientBitmap(w:Number, h:Number, bgColor:Number, type:String, hide:Boolean):BitmapData {
         *   var mc:MovieClip = this.createEmptyMovieClip("mc", 1);
         *   var matrix:Matrix = new Matrix();
         *   matrix.createGradientBox(w, h, 0, 0, 0);
         *   
         *     mc.beginGradientFill(type, [0xFF0000, 0x0000FF], [100, 100], [0x55, 0x99], matrix, "pad");       
         *   mc.lineTo(w, 0);
         *   mc.lineTo(w, h);
         *   mc.lineTo(0, h);
         *   mc.lineTo(0, 0);
         *   mc.endFill();
         *   (hide == true) ? mc._alpha = 0 : mc._alpha = 100;
         *   
         *     var bmp:BitmapData = new BitmapData(w, h, true, bgColor);
         *   bmp.draw(mc, new Matrix(), new ColorTransform(), "normal", bmp.rectangle, true);
         *   mc.attachBitmap(bmp, this.getNextHighestDepth());
         *   
         *     return bmp;
         *   }
         *   
         *     function createTextBlock():MovieClip {
         *   var txtBlock:MovieClip = this.createEmptyMovieClip("txtBlock", this.getNextHighestDepth());
         *   txtBlock.createTextField("txt", this.getNextHighestDepth(), 0, 0, 300, 80);
         *   txtBlock.txt.text = "watch the text bend with the displacement map";
         *   return txtBlock;
         *   }
         *   </listing>
         */
        float DisplacementMapFilter::scaleY()         ;
        void DisplacementMapFilter::scaleY(float value)       ;

        /**
         * The mode for the filter. Possible values are DisplacementMapFilterMode
         * constants:
         * DisplacementMapFilterMode.WRAP     Wraps the displacement value to the other side of the source image.DisplacementMapFilterMode.CLAMP     Clamps the displacement value to the edge of the source image.DisplacementMapFilterMode.IGNORE     If the displacement value is out of range, ignores the displacement and uses the source pixel.DisplacementMapFilterMode.COLOR     If the displacement value is outside the image, substitutes the values in the color and alpha properties.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @oldexample  The following example modifies <code>scaleY</code> inorder to create a displacement
         *   value that is out of range and then changes the <code>mode</code> property on the existing MovieClip 
         *   <code>filteredMc</code> to <code>ignore</code> when a user clicks on it.
         *   <listing version="2.0">
         *   import flash.filters.DisplacementMapFilter;
         *   import flash.display.BitmapData;
         *   import flash.geom.Point;
         *   import flash.geom.Matrix;
         *   import flash.geom.ColorTransform;
         *   
         *     var filteredMc:MovieClip = createDisplacementMapRectangle();
         *   
         *     filteredMc.onPress = function() {
         *   var filter:DisplacementMapFilter = this.filters[0];
         *   filter.scaleY = 25;
         *   filter.mode = "ignore";
         *   this.filters = new Array(filter);
         *   }
         *   
         *     function createDisplacementMapRectangle():MovieClip {
         *   var mapBitmap:BitmapData = createGradientBitmap(300, 80, 0xFF000000, "radial");
         *   var filter:DisplacementMapFilter = new DisplacementMapFilter(mapBitmap, new Point(-30, -30), 1, 1, 10, 10, "wrap", 0x000000, 0x000000);
         *   
         *     var txtBlock:MovieClip = createTextBlock();
         *   txtBlock._x = 30;
         *   txtBlock._y = 30;
         *   
         *     txtBlock.filters = new Array(filter);
         *   
         *     return txtBlock;
         *   }
         *   
         *     function createGradientBitmap(w:Number, h:Number, bgColor:Number, type:String, hide:Boolean):BitmapData {
         *   var mc:MovieClip = this.createEmptyMovieClip("mc", 1);
         *   var matrix:Matrix = new Matrix();
         *   matrix.createGradientBox(w, h, 0, 0, 0);
         *   
         *     mc.beginGradientFill(type, [0xFF0000, 0x0000FF], [100, 100], [0x55, 0x99], matrix, "pad");       
         *   mc.lineTo(w, 0);
         *   mc.lineTo(w, h);
         *   mc.lineTo(0, h);
         *   mc.lineTo(0, 0);
         *   mc.endFill();
         *   (hide == true) ? mc._alpha = 0 : mc._alpha = 100;
         *   
         *     var bmp:BitmapData = new BitmapData(w, h, true, bgColor);
         *   bmp.draw(mc, new Matrix(), new ColorTransform(), "normal", bmp.rectangle, true);
         *   mc.attachBitmap(bmp, this.getNextHighestDepth());
         *   
         *     return bmp;
         *   }
         *   
         *     function createTextBlock():MovieClip {
         *   var txtBlock:MovieClip = this.createEmptyMovieClip("txtBlock", this.getNextHighestDepth());
         *   txtBlock.createTextField("txt", this.getNextHighestDepth(), 0, 0, 300, 80);
         *   txtBlock.txt.text = "watch the text bend with the displacement map";
         *   return txtBlock;
         *   }
         *   </listing>
         * @throws  TypeError The String is null when being set
         * @throws  ArgumentError The mode string is not one of the valid types
         */
        std::string DisplacementMapFilter::mode()         ;
        void DisplacementMapFilter::mode(std::string value)       ;

        /**
         * Specifies what color to use for out-of-bounds displacements.  The valid range of 
         * displacements is 0.0 to 1.0. Values are in hexadecimal format. The default value
         * for color is 0. Use this property if the mode property 
         * is set to DisplacementMapFilterMode.COLOR.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @maelexample The following example modifies the out of range 
         *   <code>color</code> property on the existing MovieClip 
         *   <code>filteredMc</code> to <code>0x00FF00</code> when a user clicks on it.
         *   <listing version="2.0">
         *   import flash.filters.DisplacementMapFilter;
         *   import flash.display.BitmapData;
         *   import flash.geom.Point;
         *   import flash.geom.Matrix;
         *   import flash.geom.ColorTransform;
         *   
         *     var filteredMc:MovieClip = createDisplacementMapRectangle();
         *   
         *     filteredMc.onPress = function() {
         *   var filter:DisplacementMapFilter = this.filters[0];
         *   filter.scaleY = 25;
         *   filter.mode = "color";
         *   filter.alpha = .25;
         *   filter.color = 0x00FF00;
         *   this.filters = new Array(filter);
         *   }
         *   
         *     function createDisplacementMapRectangle():MovieClip {
         *   var mapBitmap:BitmapData = createGradientBitmap(300, 80, 0xFF000000, "radial");
         *   var filter:DisplacementMapFilter = new DisplacementMapFilter(mapBitmap, new Point(-30, -30), 1, 1, 10, 10, "wrap", 0x000000, 0x000000);
         *   
         *     var txtBlock:MovieClip = createTextBlock();
         *   txtBlock._x = 30;
         *   txtBlock._y = 30;
         *   
         *     txtBlock.filters = new Array(filter);
         *   
         *     return txtBlock;
         *   }
         *   
         *     function createGradientBitmap(w:Number, h:Number, bgColor:Number, type:String, hide:Boolean):BitmapData {
         *   var mc:MovieClip = this.createEmptyMovieClip("mc", 1);
         *   var matrix:Matrix = new Matrix();
         *   matrix.createGradientBox(w, h, 0, 0, 0);
         *   
         *     mc.beginGradientFill(type, [0xFF0000, 0x0000FF], [100, 100], [0x55, 0x99], matrix, "pad");       
         *   mc.lineTo(w, 0);
         *   mc.lineTo(w, h);
         *   mc.lineTo(0, h);
         *   mc.lineTo(0, 0);
         *   mc.endFill();
         *   (hide == true) ? mc._alpha = 0 : mc._alpha = 100;
         *   
         *     var bmp:BitmapData = new BitmapData(w, h, true, bgColor);
         *   bmp.draw(mc, new Matrix(), new ColorTransform(), "normal", bmp.rectangle, true);
         *   mc.attachBitmap(bmp, this.getNextHighestDepth());
         *   
         *     return bmp;
         *   }
         *   
         *     function createTextBlock():MovieClip {
         *   var txtBlock:MovieClip = this.createEmptyMovieClip("txtBlock", this.getNextHighestDepth());
         *   txtBlock.createTextField("txt", this.getNextHighestDepth(), 0, 0, 300, 80);
         *   txtBlock.txt.text = "watch the text bend with the displacement map";
         *   return txtBlock;
         *   }
         *   </listing>
         */
        unsigned int DisplacementMapFilter::color()       ;
        void DisplacementMapFilter::color(unsigned int value)       ;

        /**
         * Specifies the alpha transparency value to use for out-of-bounds displacements.
         * It is specified as a normalized value from 0.0 to 1.0. For example,
         * .25 sets a transparency value of 25%. The default value is 0.
         * Use this property if the mode property is set to DisplacementMapFilterMode.COLOR.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @maelexample The following example modifies the out of range 
         *   <code>alpha</code> property on the existing MovieClip 
         *   <code>filteredMc</code> to <code>0x00FF00</code> when a user clicks on it.
         *   <listing version="2.0">
         *   import flash.filters.DisplacementMapFilter;
         *   import flash.display.BitmapData;
         *   import flash.geom.Point;
         *   import flash.geom.Matrix;
         *   import flash.geom.ColorTransform;
         *   
         *     var filteredMc:MovieClip = createDisplacementMapRectangle();
         *   
         *     filteredMc.onPress = function() {
         *   var filter:DisplacementMapFilter = this.filters[0];
         *   filter.scaleY = 25;
         *   filter.mode = "color";
         *   filter.alpha = .25;
         *   this.filters = new Array(filter);
         *   }
         *   
         *     function createDisplacementMapRectangle():MovieClip {
         *   var mapBitmap:BitmapData = createGradientBitmap(300, 80, 0xFF000000, "radial");
         *   var filter:DisplacementMapFilter = new DisplacementMapFilter(mapBitmap, new Point(-30, -30), 1, 1, 10, 10, "wrap", 0x000000, 0x000000);
         *   
         *     var txtBlock:MovieClip = createTextBlock();
         *   txtBlock._x = 30;
         *   txtBlock._y = 30;
         *   
         *     txtBlock.filters = new Array(filter);
         *   
         *     return txtBlock;
         *   }
         *   
         *     function createGradientBitmap(w:Number, h:Number, bgColor:Number, type:String, hide:Boolean):BitmapData {
         *   var mc:MovieClip = this.createEmptyMovieClip("mc", 1);
         *   var matrix:Matrix = new Matrix();
         *   matrix.createGradientBox(w, h, 0, 0, 0);
         *   
         *     mc.beginGradientFill(type, [0xFF0000, 0x0000FF], [100, 100], [0x55, 0x99], matrix, "pad");       
         *   mc.lineTo(w, 0);
         *   mc.lineTo(w, h);
         *   mc.lineTo(0, h);
         *   mc.lineTo(0, 0);
         *   mc.endFill();
         *   (hide == true) ? mc._alpha = 0 : mc._alpha = 100;
         *   
         *     var bmp:BitmapData = new BitmapData(w, h, true, bgColor);
         *   bmp.draw(mc, new Matrix(), new ColorTransform(), "normal", bmp.rectangle, true);
         *   mc.attachBitmap(bmp, this.getNextHighestDepth());
         *   
         *     return bmp;
         *   }
         *   
         *     function createTextBlock():MovieClip {
         *   var txtBlock:MovieClip = this.createEmptyMovieClip("txtBlock", this.getNextHighestDepth());
         *   txtBlock.createTextField("txt", this.getNextHighestDepth(), 0, 0, 300, 80);
         *   txtBlock.txt.text = "watch the text bend with the displacement map";
         *   return txtBlock;
         *   }
         *   </listing>
         */
        float DisplacementMapFilter::alpha()         ;
        void DisplacementMapFilter::alpha(float value)       ;

        /**
         * Initializes a DisplacementMapFilter instance with the specified parameters.
         * @param   mapBitmap   A BitmapData object containing the displacement map data.
         * @param   mapPoint    A value that contains the offset of the upper-left corner of the
         *   target display object from the upper-left corner of the map image.
         * @param   componentX  Describes which color channel to use in the map image to displace the x result. 
         *   Possible values are the BitmapDataChannel constants.
         * @param   componentY  Describes which color channel to use in the map image to displace the y result. 
         *   Possible values are the BitmapDataChannel constants.
         * @param   scaleX  The multiplier to use to scale the x displacement result from the map calculation.
         * @param   scaleY  The multiplier to use to scale the y displacement result from the map calculation.
         * @param   mode    The mode of the filter. Possible values are the DisplacementMapFilterMode
         *   constants.
         * @param   color   Specifies the color to use for out-of-bounds displacements. The valid range of 
         *   displacements is 0.0 to 1.0. Use this parameter if mode is set to DisplacementMapFilterMode.COLOR.
         * @param   alpha   Specifies what alpha value to use for out-of-bounds displacements.
         *   It is specified as a normalized value from 0.0 to 1.0. For example,
         *   .25 sets a transparency value of 25%. 
         *   Use this parameter if mode is set to DisplacementMapFilterMode.COLOR.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @category    Constructor
         */
        DisplacementMapFilter::DisplacementMapFilter(BitmapData* mapBitmap, Point* mapPoint, unsigned int componentX, unsigned int componentY, float scaleX, float scaleY, std::string mode, unsigned int color, float alpha);

        /**
         * Returns a copy of this filter object.
         * @return  A new DisplacementMapFilter instance with all the same properties as the
         *   original one.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @maelexample The following example creates three <code>DisplacementMapFilter</code> objects and compares them.  <code>filter_1</code>
         *   is created using the <code>DisplacementMapFilter</code> construtor.  <code>filter_2</code> is created by setting it equal to 
         *   <code>filter_1</code>.  And, <code>clonedFilter</code> is created by cloning <code>filter_1</code>.  Notice
         *   that while <code>filter_2</code> evaluates as being equal to <code>filter_1</code>, <code>clonedFilter</code>,
         *   even though it contains the same values as <code>filter_1</code>, does not.
         *   <listing version="2.0">
         *   import flash.filters.DisplacementMapFilter;
         *   import flash.display.BitmapData;
         *   import flash.geom.Point;
         *   import flash.geom.Matrix;
         *   import flash.geom.ColorTransform;
         *   
         *     var mapBitmap:BitmapData = createGradientBitmap(300, 80, 0xFF000000, "radial", true);
         *   
         *     var filter_1:DisplacementMapFilter = new DisplacementMapFilter(mapBitmap, new Point(-30, -30), 1, 1, 10, 10, "wrap", 0x000000, 0x000000);
         *   var filter_2:DisplacementMapFilter = filter_1;
         *   var clonedFilter:DisplacementMapFilter = filter_1.clone();
         *   
         *     trace(filter_1 == filter_2);     // true
         *   trace(filter_1 == clonedFilter);   // false
         *   
         *     for(var i in filter_1) {
         *   trace("&gt;&gt; " + i + ": " + filter_1[i]);
         *   // &gt;&gt; clone: [type Function]
         *   // &gt;&gt; alpha: 0
         *   // &gt;&gt; color: 0
         *   // &gt;&gt; mode: wrap
         *   // &gt;&gt; scaleY: 10
         *   // &gt;&gt; scaleX: 10
         *   // &gt;&gt; componentY: 1
         *   // &gt;&gt; componentX: 1
         *   // &gt;&gt; mapPoint: (-30, -30)
         *   // &gt;&gt; mapBitmap: [object Object]
         *   }
         *   
         *     for(var i in clonedFilter) {
         *   trace("&gt;&gt; " + i + ": " + clonedFilter[i]);
         *   // &gt;&gt; clone: [type Function]
         *   // &gt;&gt; alpha: 0
         *   // &gt;&gt; color: 0
         *   // &gt;&gt; mode: wrap
         *   // &gt;&gt; scaleY: 10
         *   // &gt;&gt; scaleX: 10
         *   // &gt;&gt; componentY: 1
         *   // &gt;&gt; componentX: 1
         *   // &gt;&gt; mapPoint: (-30, -30)
         *   // &gt;&gt; mapBitmap: [object Object]
         *   }
         *   
         *     function createGradientBitmap(w:Number, h:Number, bgColor:Number, type:String, hide:Boolean):BitmapData {
         *   var mc:MovieClip = this.createEmptyMovieClip("mc", 1);
         *   var matrix:Matrix = new Matrix();
         *   matrix.createGradientBox(w, h, 0, 0, 0);
         *   
         *     mc.beginGradientFill(type, [0xFF0000, 0x0000FF], [100, 100], [0x55, 0x99], matrix, "pad");       
         *   mc.lineTo(w, 0);
         *   mc.lineTo(w, h);
         *   mc.lineTo(0, h);
         *   mc.lineTo(0, 0);
         *   mc.endFill();
         *   (hide == true) ? mc._alpha = 0 : mc._alpha = 100;
         *   
         *     var bmp:BitmapData = new BitmapData(w, h, true, bgColor);
         *   bmp.draw(mc, new Matrix(), new ColorTransform(), "normal", bmp.rectangle, true);
         *   mc.attachBitmap(bmp, this.getNextHighestDepth());
         *   
         *     return bmp;
         *   }
         *   </listing>
         *   To further demonstrate the relationships between <code>filter_1</code>, <code>filter_2</code>, and <code>clonedFilter</code>
         *   the example below modifies the <code>mode</code> property of <code>filter_1</code>.  Modifying <code>mode</code> demonstrates
         *   that the <code>clone()</code> method creates a new instance based on values of the <code>filter_1</code> instead of pointing to 
         *   them in reference.
         *   <listing version="2.0">
         *   import flash.filters.DisplacementMapFilter;
         *   import flash.display.BitmapData;
         *   import flash.geom.Point;
         *   import flash.geom.Matrix;
         *   import flash.geom.ColorTransform;
         *   
         *     var mapBitmap:BitmapData = createGradientBitmap(300, 80, 0xFF000000, "radial", true);
         *   
         *     var filter_1:DisplacementMapFilter = new DisplacementMapFilter(mapBitmap, new Point(-30, -30), 1, 1, 10, 10, "wrap", 0x000000, 0x000000);
         *   var filter_2:DisplacementMapFilter = filter_1;
         *   var clonedFilter:DisplacementMapFilter = filter_1.clone();
         *   
         *     trace(filter_1.mode);            // wrap
         *   trace(filter_2.mode);          // wrap
         *   trace(clonedFilter.mode);      // wrap
         *   
         *     filter_1.mode = "ignore";
         *   
         *     trace(filter_1.mode);            // ignore
         *   trace(filter_2.mode);          // ignore
         *   trace(clonedFilter.mode);      // wrap
         *   
         *     function createGradientBitmap(w:Number, h:Number, bgColor:Number, type:String, hide:Boolean):BitmapData {
         *   var mc:MovieClip = this.createEmptyMovieClip("mc", 1);
         *   var matrix:Matrix = new Matrix();
         *   matrix.createGradientBox(w, h, 0, 0, 0);
         *   
         *     mc.beginGradientFill(type, [0xFF0000, 0x0000FF], [100, 100], [0x55, 0x99], matrix, "pad");       
         *   mc.lineTo(w, 0);
         *   mc.lineTo(w, h);
         *   mc.lineTo(0, h);
         *   mc.lineTo(0, 0);
         *   mc.endFill();
         *   (hide == true) ? mc._alpha = 0 : mc._alpha = 100;
         *   
         *     var bmp:BitmapData = new BitmapData(w, h, true, bgColor);
         *   bmp.draw(mc, new Matrix(), new ColorTransform(), "normal", bmp.rectangle, true);
         *   mc.attachBitmap(bmp, this.getNextHighestDepth());
         *   
         *     return bmp;
         *   }
         *   </listing>
         */
        flash::filters::BitmapFilter* DisplacementMapFilter::clone()                             ;
}
}

