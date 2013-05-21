#if !defined(FLEX11_6_FLASH_GEOM_COLORTRANSFORM_AS)
#define FLEX11_6_FLASH_GEOM_COLORTRANSFORM_AS
#if defined(__cplusplus)


#include "flex11.6.h"


/**
 * The ColorTransform class lets you adjust the color values in a display object.
 * The color adjustment or <i class="+ topic/ph hi-d/i ">color transformation</i> can be applied to all four channels:
 * red, green, blue, and alpha transparency.
 *
 *   <p class="- topic/p ">When a ColorTransform object is applied to a display object, a new value for each color
 * channel is calculated like this:</p><ul class="- topic/ul "><li class="- topic/li ">New red value = (old red value * <codeph class="+ topic/ph pr-d/codeph ">redMultiplier</codeph>) + <codeph class="+ topic/ph pr-d/codeph ">redOffset</codeph></li><li class="- topic/li ">New green value = (old green value * <codeph class="+ topic/ph pr-d/codeph ">greenMultiplier</codeph>) +
 * <codeph class="+ topic/ph pr-d/codeph ">greenOffset</codeph></li><li class="- topic/li ">New blue value = (old blue value * <codeph class="+ topic/ph pr-d/codeph ">blueMultiplier</codeph>) + <codeph class="+ topic/ph pr-d/codeph ">blueOffset</codeph></li><li class="- topic/li ">New alpha value = (old alpha value * <codeph class="+ topic/ph pr-d/codeph ">alphaMultiplier</codeph>) +
 * <codeph class="+ topic/ph pr-d/codeph ">alphaOffset</codeph></li></ul><p class="- topic/p ">If any of the color channel values is greater than 255 after the calculation, it is set to 255.
 * If it is less than 0, it is set to 0.</p><p class="- topic/p ">You can use ColorTransform objects in the following ways:</p><ul class="- topic/ul "><li class="- topic/li ">In the <codeph class="+ topic/ph pr-d/codeph ">colorTransform</codeph> parameter of the <codeph class="+ topic/ph pr-d/codeph ">colorTransform()</codeph> method
 * of the BitmapData class</li><li class="- topic/li ">As the <codeph class="+ topic/ph pr-d/codeph ">colorTransform</codeph> property of a Transform object (which can be
 * used as the <codeph class="+ topic/ph pr-d/codeph ">transform</codeph> property of a display object)</li></ul><p class="- topic/p ">You must use the <codeph class="+ topic/ph pr-d/codeph ">new ColorTransform()</codeph> constructor to create a
 * ColorTransform object before you can call the methods of the
 * ColorTransform object.</p><p class="- topic/p ">Color transformations do not apply to the background color of a movie clip (such as a loaded SWF
 * object). They apply only to graphics and symbols that are attached to the movie clip.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the TransformExample class to create a simple sprite
 * in the shape of a square filled with a gradient pattern. Each time the user clicks the square, the
 * application transforms the colors of the square sprite, adding to the red color channel and
 * lightening the blue color channel. This is accomplished with the following steps:
 *
 *   <ol class="- topic/ol "><li class="- topic/li ">The constructor creates a new sprite object <codeph class="+ topic/ph pr-d/codeph ">target</codeph>.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">CustomButton()</codeph> constructor calls the <codeph class="+ topic/ph pr-d/codeph ">draw()</codeph> method, which draws a gradient
 * square in the sprite.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">CustomButton()</codeph> constructor adds a click event listener for the sprite, which is handled by the
 * <codeph class="+ topic/ph pr-d/codeph ">clickHandler()</codeph> method.  </li><li class="- topic/li ">In the <codeph class="+ topic/ph pr-d/codeph ">clickHandler()</codeph> method, two properties are set to the
 * <codeph class="+ topic/ph pr-d/codeph ">redOffset</codeph> and <codeph class="+ topic/ph pr-d/codeph ">blueOffset</codeph> properties of the current
 * color transformation. Each is adjusted by 25. Then the <codeph class="+ topic/ph pr-d/codeph ">transform.colorTransform</codeph>
 * property of the square sprite is modified to use the new offset values.
 * Each time the user clicks the square, the call to the <codeph class="+ topic/ph pr-d/codeph ">clickHandler()</codeph> method modifies
 * the color of the square, by augmenting its red color value and diminishing its blue color value.  </li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.display.GradientType;
 * import flash.geom.ColorTransform;
 * import flash.events.MouseEvent;
 *
 *   public class ColorTransformExample extends Sprite {
 * public function ColorTransformExample() {
 * var target:Sprite = new Sprite();
 * draw(target);
 * addChild(target);
 * target.useHandCursor = true;
 * target.buttonMode = true;
 * target.addEventListener(MouseEvent.CLICK, clickHandler)
 * }
 * public function draw(sprite:Sprite):void {
 * var red:uint = 0xFF0000;
 * var green:uint = 0x00FF00;
 * var blue:uint = 0x0000FF;
 * var size:Number = 100;
 * sprite.graphics.beginGradientFill(GradientType.LINEAR, [red, blue, green], [1, 0.5, 1], [0, 200, 255]);
 * sprite.graphics.drawRect(0, 0, 100, 100);
 * }
 * public function clickHandler(event:MouseEvent):void {
 * var rOffset:Number = transform.colorTransform.redOffset + 25;
 * var bOffset:Number = transform.colorTransform.redOffset - 25;
 * this.transform.colorTransform = new ColorTransform(1, 1, 1, 1, rOffset, 0, bOffset, 0);
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace geom
    {
        class ColorTransform : public Object
        {
            /**
             * A decimal value that is multiplied with the red channel value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates the ColorTransform object <code>colorTrans</code>
             *   and adjusts its <code>redMultiplier</code> from 1 to .5.
             *   <listing version="2.0">
             *   import flash.geom.ColorTransform;
             *
             *     var colorTrans:ColorTransform = new ColorTransform();
             *   trace(colorTrans.redMultiplier);       // 1
             *
             *     colorTrans.redMultiplier = .5;
             *   trace(colorTrans.redMultiplier);       // .5
             *
             *     var rect:MovieClip = createRectangle(20, 80, 0xFF0000);
             *   var trans:Transform = new Transform(rect);
             *   trans.colorTransform = colorTrans;
             *
             *     function createRectangle(width:Number, height:Number, color:Number, scope:MovieClip):MovieClip {
             *   scope = (scope == undefined) ? this : scope;
             *   var depth:Number = scope.getNextHighestDepth();
             *   var mc:MovieClip = scope.createEmptyMovieClip("mc_" + depth, depth);
             *   mc.beginFill(color);
             *   mc.lineTo(0, height);
             *   mc.lineTo(width, height);
             *   mc.lineTo(width, 0);
             *   mc.lineTo(0, 0);
             *   return mc;
             *   }
             *   </listing>
             */
        public:
            float redMultiplier;

            /**
             * A decimal value that is multiplied with the green channel value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates the ColorTransform object <code>colorTrans</code>
             *   and adjusts its <code>greenMultiplier</code> from 1 to .5.
             *   <listing version="2.0">
             *   import flash.geom.ColorTransform;
             *
             *     var colorTrans:ColorTransform = new ColorTransform();
             *   trace(colorTrans.greenMultiplier);     // 1
             *
             *     colorTrans.greenMultiplier = .5;
             *   trace(colorTrans.greenMultiplier);     // .5
             *
             *     var rect:MovieClip = createRectangle(20, 80, 0x00FF00);
             *   var trans:Transform = new Transform(rect);
             *   trans.colorTransform = colorTrans;
             *
             *     function createRectangle(width:Number, height:Number, color:Number, scope:MovieClip):MovieClip {
             *   scope = (scope == undefined) ? this : scope;
             *   var depth:Number = scope.getNextHighestDepth();
             *   var mc:MovieClip = scope.createEmptyMovieClip("mc_" + depth, depth);
             *   mc.beginFill(color);
             *   mc.lineTo(0, height);
             *   mc.lineTo(width, height);
             *   mc.lineTo(width, 0);
             *   mc.lineTo(0, 0);
             *   return mc;
             *   }
             *   </listing>
             */
        public:
            float greenMultiplier;

            /**
             * A decimal value that is multiplied with the blue channel value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates the ColorTransform object <code>colorTrans</code>
             *   and adjusts its <code>blueMultiplier</code> from 1 to .5.
             *   <listing version="2.0">
             *   import flash.geom.ColorTransform;
             *
             *     var colorTrans:ColorTransform = new ColorTransform();
             *   trace(colorTrans.blueMultiplier);      // 1
             *
             *     colorTrans.blueMultiplier = .5;
             *   trace(colorTrans.blueMultiplier);      // .5
             *
             *     var rect:MovieClip = createRectangle(20, 80, 0x0000FF);
             *   var trans:Transform = new Transform(rect);
             *   trans.colorTransform = colorTrans;
             *
             *     function createRectangle(width:Number, height:Number, color:Number, scope:MovieClip):MovieClip {
             *   scope = (scope == undefined) ? this : scope;
             *   var depth:Number = scope.getNextHighestDepth();
             *   var mc:MovieClip = scope.createEmptyMovieClip("mc_" + depth, depth);
             *   mc.beginFill(color);
             *   mc.lineTo(0, height);
             *   mc.lineTo(width, height);
             *   mc.lineTo(width, 0);
             *   mc.lineTo(0, 0);
             *   return mc;
             *   }
             *   </listing>
             */
        public:
            float blueMultiplier;

            /**
             * A decimal value that is multiplied with the alpha transparency channel value.
             *
             *   If you set the alpha transparency value of a display object directly by using the
             * alpha property of the DisplayObject instance, it affects the value of the
             * alphaMultiplier property of that display object's transform.colorTransform
             * property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates the ColorTransform object <code>colorTrans</code>
             *   and adjusts its <code>alphaMultiplier</code> from 1 to .5.
             *   <listing version="2.0">
             *   import flash.geom.ColorTransform;
             *   import flash.geom.Transform;
             *
             *     var colorTrans:ColorTransform = new ColorTransform();
             *   trace(colorTrans.alphaMultiplier);     // 1
             *
             *     colorTrans.alphaMultiplier = .5;
             *   trace(colorTrans.alphaMultiplier);     // .5
             *
             *     var rect:MovieClip = createRectangle(20, 80, 0x000000);
             *   var trans:Transform = new Transform(rect);
             *   trans.colorTransform = colorTrans;
             *
             *     function createRectangle(width:Number, height:Number, color:Number, scope:MovieClip):MovieClip {
             *   scope = (scope == undefined) ? this : scope;
             *   var depth:Number = scope.getNextHighestDepth();
             *   var mc:MovieClip = scope.createEmptyMovieClip("mc_" + depth, depth);
             *   mc.beginFill(color);
             *   mc.lineTo(0, height);
             *   mc.lineTo(width, height);
             *   mc.lineTo(width, 0);
             *   mc.lineTo(0, 0);
             *   return mc;
             *   }
             *   </listing>
             */
        public:
            float alphaMultiplier;

            /**
             * A number from -255 to 255 that is added to the red channel value after it has been
             * multiplied by the redMultiplier value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates the ColorTransform object <code>colorTrans</code>
             *   and adjusts its <code>redOffset</code> from 0 to 255.
             *   <listing version="2.0">
             *   import flash.geom.ColorTransform;
             *
             *     var colorTrans:ColorTransform = new ColorTransform();
             *   trace(colorTrans.redOffset);           // 0
             *
             *     colorTrans.redOffset = 255;
             *   trace(colorTrans.redOffset);           // 255
             *
             *     var rect:MovieClip = createRectangle(20, 80, 0x000000);
             *   var trans:Transform = new Transform(rect);
             *   trans.colorTransform = colorTrans;
             *
             *     function createRectangle(width:Number, height:Number, color:Number, scope:MovieClip):MovieClip {
             *   scope = (scope == undefined) ? this : scope;
             *   var depth:Number = scope.getNextHighestDepth();
             *   var mc:MovieClip = scope.createEmptyMovieClip("mc_" + depth, depth);
             *   mc.beginFill(color);
             *   mc.lineTo(0, height);
             *   mc.lineTo(width, height);
             *   mc.lineTo(width, 0);
             *   mc.lineTo(0, 0);
             *   return mc;
             *   }
             *   </listing>
             */
        public:
            float redOffset;

            /**
             * A number from -255 to 255 that is added to the green channel value after it has
             * been multiplied by the greenMultiplier value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates the ColorTransform object <code>colorTrans</code>
             *   and adjusts its <code>greenOffset</code> from 0 to 255.
             *   <listing version="2.0">
             *   import flash.geom.ColorTransform;
             *
             *     var colorTrans:ColorTransform = new ColorTransform();
             *   trace(colorTrans.greenOffset);         // 0
             *
             *     colorTrans.redOffset = 255;
             *   trace(colorTrans.greenOffset);         // 255
             *
             *     var rect:MovieClip = createRectangle(20, 80, 0x000000);
             *   var trans:Transform = new Transform(rect);
             *   trans.colorTransform = colorTrans;
             *
             *     function createRectangle(width:Number, height:Number, color:Number, scope:MovieClip):MovieClip {
             *   scope = (scope == undefined) ? this : scope;
             *   var depth:Number = scope.getNextHighestDepth();
             *   var mc:MovieClip = scope.createEmptyMovieClip("mc_" + depth, depth);
             *   mc.beginFill(color);
             *   mc.lineTo(0, height);
             *   mc.lineTo(width, height);
             *   mc.lineTo(width, 0);
             *   mc.lineTo(0, 0);
             *   return mc;
             *   }
             *   </listing>
             */
        public:
            float greenOffset;

            /**
             * A number from -255 to 255 that is added to the blue channel value after it has
             * been multiplied by the blueMultiplier value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates the ColorTransform object <code>colorTrans</code>
             *   and adjusts its <code>blueOffset</code> from 0 to 255.
             *   <listing version="2.0">
             *   import flash.geom.ColorTransform;
             *
             *     var colorTrans:ColorTransform = new ColorTransform();
             *   trace(colorTrans.blueOffset);          // 0
             *
             *     colorTrans.blueOffset = 255;
             *   trace(colorTrans.blueOffset);          // 255
             *
             *     var rect:MovieClip = createRectangle(20, 80, 0x000000);
             *   var trans:Transform = new Transform(rect);
             *   trans.colorTransform = colorTrans;
             *
             *     function createRectangle(width:Number, height:Number, color:Number, scope:MovieClip):MovieClip {
             *   scope = (scope == undefined) ? this : scope;
             *   var depth:Number = scope.getNextHighestDepth();
             *   var mc:MovieClip = scope.createEmptyMovieClip("mc_" + depth, depth);
             *   mc.beginFill(color);
             *   mc.lineTo(0, height);
             *   mc.lineTo(width, height);
             *   mc.lineTo(width, 0);
             *   mc.lineTo(0, 0);
             *   return mc;
             *   }
             *   </listing>
             */
        public:
            float blueOffset;

            /**
             * A number from -255 to 255 that is added to the alpha transparency channel value after it has
             * been multiplied by the alphaMultiplier value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates the ColorTransform object <code>colorTrans</code>
             *   and adjusts its <code>alphaOffset</code> from 0 to -128.
             *   <listing version="2.0">
             *   import flash.geom.ColorTransform;
             *
             *     var colorTrans:ColorTransform = new ColorTransform();
             *   trace(colorTrans.alphaOffset);         // 0
             *
             *     colorTrans.alphaOffset = -128;
             *   trace(colorTrans.alphaOffset);         // -128
             *
             *     var rect:MovieClip = createRectangle(20, 80, 0x000000);
             *   var trans:Transform = new Transform(rect);
             *   trans.colorTransform = colorTrans;
             *
             *     function createRectangle(width:Number, height:Number, color:Number, scope:MovieClip):MovieClip {
             *   scope = (scope == undefined) ? this : scope;
             *   var depth:Number = scope.getNextHighestDepth();
             *   var mc:MovieClip = scope.createEmptyMovieClip("mc_" + depth, depth);
             *   mc.beginFill(color);
             *   mc.lineTo(0, height);
             *   mc.lineTo(width, height);
             *   mc.lineTo(width, 0);
             *   mc.lineTo(0, 0);
             *   return mc;
             *   }
             *   </listing>
             */
        public:
            float alphaOffset;

            /**
             * The RGB color value for a ColorTransform object.
             *
             *   When you set this property, it changes the three color offset values (redOffset,
             * greenOffset, and blueOffset)
             * accordingly, and it sets the three color multiplier values (redMultiplier,
             * greenMultiplier, and blueMultiplier) to 0.
             * The alpha transparency multiplier and offset values do not change.When you pass a value for this property, use the format 0xRRGGBB.
             * RR, GG, and BB each consist
             * of two hexadecimal digits that specify the offset of each color component. The 0x
             * tells the ActionScript compiler that the number is a hexadecimal value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @oldexample  This example sets the RGB color value for the movie clip <code>my_mc</code>.<span class="flashonly"> To see this code work, place a movie clip on the Stage with the instance name <code>my_mc</code>. Then place the following code on Frame 1 in the main Timeline and select Control &gt; Test Movie:</span><pre xml:space="preserve" class="- topic/pre "><code>var my_color:Color = new Color(my_mc);</code><code>my_color.setRGB(0xFF0000); // my_mc turns red</code></pre>
             */
        public:
            unsigned int color();
        public:
            void         color(unsigned int newColor);

            /**
             * Creates a ColorTransform object for a display object with the specified
             * color channel values and alpha values.
             * @param   redMultiplier   The value for the red multiplier, in the range from 0 to 1.
             * @param   greenMultiplier The value for the green multiplier, in the range from 0 to 1.
             * @param   blueMultiplier  The value for the blue multiplier, in the range from 0 to 1.
             * @param   alphaMultiplier The value for the alpha transparency multiplier, in the range from 0 to 1.
             * @param   redOffset   The offset value for the red color channel, in the range from -255 to 255.
             * @param   greenOffset The offset value for the green color channel, in the range from -255 to 255.
             * @param   blueOffset  The offset for the blue color channel value, in the range from -255 to 255.
             * @param   alphaOffset The offset for alpha transparency channel value, in the range from -255 to 255.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            ColorTransform(float redMultiplier =1, float greenMultiplier =1, float blueMultiplier =1, float alphaMultiplier =1, float redOffset =0, float greenOffset =0, float blueOffset =0, float alphaOffset =0);

            /**
             * Concatenates the ColorTranform object specified by the second parameter
             * with the current ColorTransform object and sets the
             * current object as the result, which is an additive combination of the two color transformations.
             * When you apply the concatenated ColorTransform object, the effect is the same as applying the
             * second color transformation after the original color transformation.
             * @param   second  The ColorTransform object to be combined with the current ColorTransform object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example concatenates the ColorTransform object <code>colorTrans_2</code>
             *   to <code>colorTrans_1</code> resulting in a full red offset combined with a .5 alpha multiplier.
             *   <listing version="2.0">
             *   import flash.geom.ColorTransform;
             *
             *     var colorTrans_1:ColorTransform = new ColorTransform(1, 1, 1, 1, 255, 0, 0, 0);
             *   trace(colorTrans_1);       // (redMultiplier=1, greenMultiplier=1, blueMultiplier=1, alphaMultiplier=1, redOffset=255, greenOffset=0, blueOffset=0, alphaOffset=0)
             *
             *     var colorTrans_2:ColorTransform = new ColorTransform(1, 1, 1, .5, 0, 0, 0, 0);
             *   trace(colorTrans_2);       // (redMultiplier=1, greenMultiplier=1, blueMultiplier=1, alphaMultiplier=0.5, redOffset=0, greenOffset=0, blueOffset=0, alphaOffset=0)
             *
             *     colorTrans_1.concat(colorTrans_2);
             *   trace(colorTrans_1);       // (redMultiplier=1, greenMultiplier=1, blueMultiplier=1, alphaMultiplier=0.5, redOffset=255, greenOffset=0, blueOffset=0, alphaOffset=0)
             *
             *     var rect:MovieClip = createRectangle(20, 80, 0x000000);
             *   var trans:Transform = new Transform(rect);
             *   trans.colorTransform = colorTrans_1;
             *
             *     function createRectangle(width:Number, height:Number, color:Number, scope:MovieClip):MovieClip {
             *   scope = (scope == undefined) ? this : scope;
             *   var depth:Number = scope.getNextHighestDepth();
             *   var mc:MovieClip = scope.createEmptyMovieClip("mc_" + depth, depth);
             *   mc.beginFill(color);
             *   mc.lineTo(0, height);
             *   mc.lineTo(width, height);
             *   mc.lineTo(width, 0);
             *   mc.lineTo(0, 0);
             *   return mc;
             *   }
             *   </listing>
             */
        public:
            void     concat(ColorTransform *second);

            /**
             * Formats and returns a string that describes all of the properties of the
             * ColorTransform object.
             * @return  A string that lists all of the properties of the ColorTransform object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates the ColorTransform object <code>colorTrans</code>
             *   and calls its <code>toSting()</code> method.  This method results in a string with the format
             *   (redMultiplier=RM, greenMultiplier=GM, blueMultiplier=BM, alphaMultiplier=AM, redOffset=RO, greenOffset=GO, blueOffset=BO, alphaOffset=AO).
             *   <listing version="2.0">
             *   import flash.geom.ColorTransform;
             *
             *     var colorTrans:ColorTransform = new ColorTransform(1, 2, 3, 4, -255, -128, 128, 255);
             *   trace(colorTrans.toString());      // (redMultiplier=1, greenMultiplier=2, blueMultiplier=3, alphaMultiplier=4, redOffset=-255, greenOffset=-128, blueOffset=128, alphaOffset=255)
             *   </listing>
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_GEOM_COLORTRANSFORM_AS
#endif // __cplusplus

