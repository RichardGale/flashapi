#if !defined(FLEX11_6_FLASH_GEOM_TRANSFORM_AS)
#define FLEX11_6_FLASH_GEOM_TRANSFORM_AS
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
    namespace geom
    {
        class ColorTransform;
    }
}
namespace flash
{
    namespace geom
    {
        class Rectangle;
    }
}
namespace flash
{
    namespace display
    {
        class DisplayObject;
    }
}
namespace flash
{
    namespace geom
    {
        class Matrix3D;
    }
}
namespace flash
{
    namespace geom
    {
        class PerspectiveProjection;
    }
}

/**
 * The Transform class provides access to color adjustment properties and two- or three-dimensional
 * transformation objects that can be applied to a display object. During the transformation,
 * the color or the orientation and position of a display object is adjusted (offset) from
 * the current values or coordinates to new values or coordinates.
 * The Transform class also collects data about color and two-dimensional matrix transformations
 * that are applied to a display object and all of its parent objects. You can access
 * these combined transformations through the <codeph class="+ topic/ph pr-d/codeph ">concatenatedColorTransform</codeph>
 * and <codeph class="+ topic/ph pr-d/codeph ">concatenatedMatrix</codeph> properties.
 *
 *   <p class="- topic/p ">To apply color transformations: create a ColorTransform object,
 * set the color adjustments using the object's methods and properties, and then assign the
 * <codeph class="+ topic/ph pr-d/codeph ">colorTransformation</codeph> property of the <codeph class="+ topic/ph pr-d/codeph ">transform</codeph> property of the
 * display object to the new ColorTransformation object.</p><p class="- topic/p ">To apply two-dimensional transformations: create a Matrix object,
 * set the matrix's two-dimensional transformation, and then assign the <codeph class="+ topic/ph pr-d/codeph ">transform.matrix</codeph>
 * property of the display object to the new Matrix object.</p><p class="- topic/p ">To apply three-dimensional transformations: start with a three-dimensional display object.
 * A three-dimensional display object has a <codeph class="+ topic/ph pr-d/codeph ">z</codeph> property value other than zero.
 * You do not need to create the Matrix3D object. For all three-dimensional objects, a Matrix3D object
 * is created automatically when you assign a <codeph class="+ topic/ph pr-d/codeph ">z</codeph> value to a display object. You can
 * access the display object's Matrix3D object through the display object's <codeph class="+ topic/ph pr-d/codeph ">transform</codeph> property.
 * Using the methods of the Matrix3D class, you can add to or modify the existing transformation settings. Also, you can
 * create a custom Matrix3D object, set the custom Matrix3D object's transformation elements,
 * and then assign the new Matrix3D object to the display object using the <codeph class="+ topic/ph pr-d/codeph ">transform.matrix</codeph>
 * property.</p><p class="- topic/p ">To modify a perspective projection of the stage or root object:
 * use the <codeph class="+ topic/ph pr-d/codeph ">transform.matrix</codeph> property of the root display object to gain access to the
 * PerspectiveProjection object. Or, apply different perspective projection
 * properties to a display object by setting the perspective projection properties of the display
 * object's parent. The child display object inherits the new properties. Specifically, create a
 * PerspectiveProjection object and set its properties, then assign the PerspectiveProjection
 * object to the <codeph class="+ topic/ph pr-d/codeph ">perspectiveProjection</codeph> property of the parent display object's
 * <codeph class="+ topic/ph pr-d/codeph ">transform</codeph> property. The specified projection transformation then applies
 * to all the display object's three-dimensional children.</p><p class="- topic/p ">Since both PerspectiveProjection and Matrix3D objects perform perspective transformations,
 * do not assign both to a display object at the same time. Use the PerspectiveProjection object
 * for focal length and projection center changes. For more control over the perspective transformation,
 * create a perspective projection Matrix3D object.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the TransformExample class to skew the bottom side
 * of a square sprite filled with a gradient pattern. Each time the user clicks the square, the
 * application transforms the sprite by skewing it with the following steps:
 *
 *   <ol class="- topic/ol "><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">TransformExample()</codeph> constructor creates a new sprite object <codeph class="+ topic/ph pr-d/codeph ">target</codeph>.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">TransformExample()</codeph> constructor calls the <codeph class="+ topic/ph pr-d/codeph ">draw()</codeph> method,
 * which draws a gradient square in the sprite.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">TransformExample()</codeph> constructor adds a click event listener for the sprite,
 * which is handled by the <codeph class="+ topic/ph pr-d/codeph ">clickHandler()</codeph> method. </li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">clickHandler()</codeph> method creates a new Matrix object, <codeph class="+ topic/ph pr-d/codeph ">skewMatrix</codeph>,
 * which is set to apply a skew effect. Another matrix, <codeph class="+ topic/ph pr-d/codeph ">tempMatrix</codeph>, is assigned to the
 * current transformation matrix of the sprite, and then is combined with <codeph class="+ topic/ph pr-d/codeph ">skewMatrix</codeph>
 * using the <codeph class="+ topic/ph pr-d/codeph ">concat()</codeph> method. This matrix is assigned to the
 * <codeph class="+ topic/ph pr-d/codeph ">transform.matrix</codeph> property of the square sprite. Each time the user clicks the square,
 * the call to the <codeph class="+ topic/ph pr-d/codeph ">clickHandler()</codeph> modifies the shape of the square by skewing it.  </li><li class="- topic/li ">Additionally, the <codeph class="+ topic/ph pr-d/codeph ">clickHandler()</codeph> method creates a new ColorTransform object. The
 * <codeph class="+ topic/ph pr-d/codeph ">redOffset</codeph> property of the new ColorTransform is set to the current value of redOffset and
 * increased by 25. Likewise, the <codeph class="+ topic/ph pr-d/codeph ">blueOffset</codeph> property is reduced by 25. With each click,
 * the colors of the sprite change. </li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.display.GradientType;
 * import flash.geom.Matrix;
 * import flash.geom.ColorTransform;
 * import flash.events.MouseEvent;
 *
 *   public class TransformExample extends Sprite {
 * public function TransformExample() {
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
 * var skewMatrix:Matrix = new Matrix();
 * skewMatrix.c = 0.25;
 * var tempMatrix:Matrix = this.transform.matrix;
 * tempMatrix.concat(skewMatrix);
 * this.transform.matrix = tempMatrix;
 *
 *   var rOffset:Number = this.transform.colorTransform.redOffset + 25;
 * var bOffset:Number = this.transform.colorTransform.blueOffset - 25;
 * this.transform.colorTransform = new ColorTransform(1, 1, 1, 1, rOffset, 0, bOffset, 0);
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
    namespace geom
    {
        class Transform : public Object
        {
            /**
             * A Matrix object containing values that alter the scaling, rotation,
             * and translation of the display object.
             *
             *   If the matrix property is set to a value (not null), the
             * matrix3D property is null. And if the matrix3D property
             * is set to a value (not null), the matrix property is null.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example applies the Matrix object <code>scaleMatrix</code> to the Transform
             *   object <code>trans</code>.  This Matrix scales the MovieClip <code>rect</code> by a factor of two.
             *   <listing version="2.0">
             *   import flash.geom.Transform;
             *   import flash.geom.Matrix;
             *
             *     var rect:MovieClip = createRectangle(20, 80, 0xFF0000);
             *
             *     var trans:Transform = new Transform(rect);
             *   trace(trans.matrix);         // (a=1, b=0, c=0, d=1, tx=0, ty=0)
             *
             *     var scaleMatrix:Matrix = new Matrix();
             *   scaleMatrix.scale(2, 2);
             *
             *     trans.matrix = scaleMatrix;
             *   trace(trans.matrix);         // (a=2, b=0, c=0, d=2, tx=0, ty=0)
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
             * @throws  TypeError The matrix is null when being set
             */
        public:
            flash::geom::Matrix *matrix();
        public:
            void         matrix(Matrix *value);

            /**
             * A ColorTransform object containing values that universally adjust the colors in
             * the display object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example applies the ColorTransform object <code>blueColorTransform</code> to
             *   the Transform object <code>trans</code>.  This ColorTransform converts the color of the MovieClip
             *   <code>rect</code> from red to blue.
             *   <listing version="2.0">
             *   import flash.geom.Transform;
             *   import flash.geom.ColorTransform;
             *
             *     var rect:MovieClip = createRectangle(20, 80, 0xFF0000);
             *
             *     var trans:Transform = new Transform(rect);
             *   trace(trans.colorTransform);
             *   // (redMultiplier=1, greenMultiplier=1, blueMultiplier=1, alphaMultiplier=1, redOffset=0, greenOffset=0, blueOffset=0, alphaOffset=0)
             *
             *     var blueColorTransform:ColorTransform = new ColorTransform(0, 1, 1, 1, 0, 0, 255, 0);
             *
             *     parentTrans.colorTransform = blueColorTransform;
             *   trace(trans.colorTransform);
             *   // (redMultiplier=0, greenMultiplier=1, blueMultiplier=1, alphaMultiplier=1, redOffset=0, greenOffset=0, blueOffset=255, alphaOffset=0)
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
             * @throws  TypeError The colorTransform is null when being set
             */
        public:
            flash::geom::ColorTransform *colorTransform();
        public:
            void         colorTransform(ColorTransform *value);

            /**
             * A Matrix object representing the combined transformation matrixes of the
             * display object and all of its parent objects, back to the root level.
             * If different transformation matrixes have been applied at different levels,
             * all of those matrixes are concatenated into one matrix
             * for this property. Also, for resizeable SWF content running in the browser,
             * this property factors in the difference between stage coordinates and window
             * coordinates due to window resizing. Thus, the property converts local coordinates
             * to window coordinates, which may not be the same coordinate space as that of
             * the Stage.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example applies two Transform objects to a parent movie clip and to a child movie clip.
             *   A <code>scaleMatrix</code> is then applied to the Transform object <code>parentTrans</code> which
             *   scales both parent and child MovieClips.  Notice how <code>child.concatenatedMatrix</code> is the
             *   combination of <code>parentTrans</code> and <code>childTrans</code>.
             *
             *     <listing version="2.0">
             *   import flash.geom.Transform;
             *   import flash.geom.Matrix;
             *
             *     var parentRect:MovieClip = createRectangle(20, 80, 0xFF0000);
             *   var childRect:MovieClip = createRectangle(10, 40, 0x00FF00, parentRect);
             *
             *     var parentTrans:Transform = new Transform(parentRect);
             *   var childTrans:Transform = new Transform(childRect);
             *
             *     var scaleMatrix:Matrix = new Matrix();
             *   scaleMatrix.scale(2, 2);
             *
             *     parentTrans.matrix = scaleMatrix;
             *
             *     trace(childTrans.concatenatedMatrix);     // (a=2, b=0, c=0, d=2, tx=0, ty=0)
             *   trace(childTrans.matrix);                 // (a=1, b=0, c=0, d=1, tx=0, ty=0)
             *   trace(parentTrans.concatenatedMatrix);    // (a=2, b=0, c=0, d=2, tx=0, ty=0)
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
            flash::geom::Matrix *concatenatedMatrix();

            /**
             * A ColorTransform object representing the combined color transformations applied to the display object
             * and all of its parent objects, back to the root level.
             * If different color transformations have been applied at different levels, all of those transformations are
             * concatenated into one ColorTransform object
             * for this property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example applies two Transform objects to both a parent and child MovieClip.
             *   A <code>blueColorTransform</code> is then applied to the Transform object <code>parentTrans</code> which
             *   adjusts the color of both parent and child MovieClips towards blue.  Notice how <code>child.concatenatedColorTransform</code> is the
             *   combination of <code>parentTrans</code> and <code>childTrans</code>.
             *   <listing version="2.0">
             *   import flash.geom.Transform;
             *   import flash.geom.ColorTransform;
             *
             *     var parentRect:MovieClip = createRectangle(20, 80, 0xFF0000);
             *   var childRect:MovieClip = createRectangle(10, 40, 0x00FF00, parentRect);
             *
             *     var parentTrans:Transform = new Transform(parentRect);
             *   var childTrans:Transform = new Transform(childRect);
             *
             *     var blueColorTransform:ColorTransform = new ColorTransform(0, 1, 1, 1, 0, 0, 255, 0);
             *
             *     parentTrans.colorTransform = blueColorTransform;
             *
             *     trace(childTrans.concatenatedColorTransform);
             *   // (redMultiplier=0, greenMultiplier=1, blueMultiplier=1, alphaMultiplier=1, redOffset=0, greenOffset=0, blueOffset=255, alphaOffset=0)
             *   trace(childTrans.colorTransform);
             *   // (redMultiplier=1, greenMultiplier=1, blueMultiplier=1, alphaMultiplier=1, redOffset=0, greenOffset=0, blueOffset=0, alphaOffset=0)
             *   trace(parentTrans.concatenatedColorTransform);
             *   // (redMultiplier=0, greenMultiplier=1, blueMultiplier=1, alphaMultiplier=1, redOffset=0, greenOffset=0, blueOffset=255, alphaOffset=0)
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
            flash::geom::ColorTransform *concatenatedColorTransform();

            /**
             * A Rectangle object that defines the bounding rectangle of the display object on the stage.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates a Transform object <code>trans</code> and traces out
             *   its <code>pixelBounds</code>.  Notice that pixel bounds returns a bounding box with values
             *   equal to MovieClip's <code>getBounds()</code> and <code>getRect()</code> methods.
             *   <listing version="2.0">
             *   import flash.geom.Transform;
             *
             *     var rect:MovieClip = createRectangle(20, 80, 0xFF0000);
             *   var trans:Transform = new Transform(rect);
             *   trace(trans.pixelBounds);         // (x=0, y=0, w=20, h=80)
             *
             *     var boundsObj:Object = rect.getBounds();
             *   trace(boundsObj.xMin);            // 0
             *   trace(boundsObj.yMin);            // 0
             *   trace(boundsObj.xMax);            // 20
             *   trace(boundsObj.yMax);            // 80
             *
             *     var rectObj:Object = rect.getRect();
             *   trace(rectObj.xMin);              // 0
             *   trace(rectObj.yMin);              // 0
             *   trace(rectObj.xMax);              // 20
             *   trace(rectObj.yMax);              // 80
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
            flash::geom::Rectangle *pixelBounds();

            /**
             * Provides access to the Matrix3D object of a three-dimensional display object.
             * The Matrix3D object represents a transformation matrix that determines the
             * display object's position and orientation. A Matrix3D object can also
             * perform perspective projection.
             *
             *   If the matrix property is set to a value (not null), the
             * matrix3D property is null. And if the matrix3D property
             * is set to a value (not null), the matrix property is null.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            flash::geom::Matrix3D *matrix3D();
        public:
            void         matrix3D(Matrix3D *m);

            /**
             * Provides access to the PerspectiveProjection object of a three-dimensional display
             * object. The PerspectiveProjection object can be used to modify the perspective
             * transformation of the stage or to assign a perspective transformation to all the
             * three-dimensional children of a display object.
             *
             *   Based on the field of view and aspect ratio (dimensions) of the stage, a
             * default PerspectiveProjection object is assigned to the root object.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            flash::geom::PerspectiveProjection *perspectiveProjection();
        public:
            void         perspectiveProjection(PerspectiveProjection *pm);

            /**
             * Returns a Matrix3D object, which can transform the space of a specified
             * display object in relation to the current display object's space. You can use the
             * getRelativeMatrix3D() method to move one three-dimensional display
             * object relative to another three-dimensional display object.
             * @param   relativeTo  The display object relative to which the transformation occurs.
             *   To get a Matrix3D object relative to the stage, set the parameter to the root
             *   or stage object. To get the world-relative matrix of the display object,
             *   set the parameter to a display object that has a perspective transformation applied to it.
             * @return  A Matrix3D object that can be used to transform the space from the relativeTo
             *   display object to the current display object space.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            flash::geom::Matrix3D *getRelativeMatrix3D(DisplayObject *relativeTo);

        public:
            Transform(DisplayObject *displayObject);
        };
    }
}

#endif // FLEX11_6_FLASH_GEOM_TRANSFORM_AS
#endif // __cplusplus

