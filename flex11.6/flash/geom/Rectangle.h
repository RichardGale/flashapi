#if !defined(FLEX11_6_FLASH_GEOM_RECTANGLE_AS)
#define FLEX11_6_FLASH_GEOM_RECTANGLE_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace geom
    {
        class Point;
    }
}


/**
 * A Rectangle object is an area defined by its position, as
 * indicated by its top-left corner point (<i class="+ topic/ph hi-d/i ">x</i>, <i class="+ topic/ph hi-d/i ">y</i>) and by its width
 * and its height.
 *
 *   <p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">x</codeph>, <codeph class="+ topic/ph pr-d/codeph ">y</codeph>, <codeph class="+ topic/ph pr-d/codeph ">width</codeph>, and
 * <codeph class="+ topic/ph pr-d/codeph ">height</codeph> properties of the Rectangle class are
 * independent of each other; changing the value of one property has
 * no effect on the others. However, the <codeph class="+ topic/ph pr-d/codeph ">right</codeph> and <codeph class="+ topic/ph pr-d/codeph ">bottom</codeph>
 * properties are integrally related to those four properties. For example, if you change
 * the value of the <codeph class="+ topic/ph pr-d/codeph ">right</codeph> property, the value of the <codeph class="+ topic/ph pr-d/codeph ">width</codeph> property
 * changes; if you change the <codeph class="+ topic/ph pr-d/codeph ">bottom</codeph> property, the value of the <codeph class="+ topic/ph pr-d/codeph ">height</codeph>
 * property changes. </p><p class="- topic/p ">The following methods and properties use Rectangle objects:</p><ul class="- topic/ul "><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">applyFilter()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">colorTransform()</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">copyChannel()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">copyPixels()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">draw()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">fillRect()</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">generateFilterRect()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">getColorBoundsRect()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">getPixels()</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">merge()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">paletteMap()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">pixelDisolve()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">setPixels()</codeph>, and
 * <codeph class="+ topic/ph pr-d/codeph ">threshold()</codeph> methods, and the <codeph class="+ topic/ph pr-d/codeph ">rect</codeph> property of the BitmapData class</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">getBounds()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">getRect()</codeph> methods, and the <codeph class="+ topic/ph pr-d/codeph ">scrollRect</codeph>
 * and <codeph class="+ topic/ph pr-d/codeph ">scale9Grid</codeph> properties of the DisplayObject class</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">getCharBoundaries()</codeph> method of the TextField class</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">pixelBounds</codeph> property of the Transform class</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">bounds</codeph> parameter for the <codeph class="+ topic/ph pr-d/codeph ">startDrag()</codeph> method of the Sprite class</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">printArea</codeph> parameter of the <codeph class="+ topic/ph pr-d/codeph ">addPage()</codeph> method of the PrintJob class</li></ul><p class="- topic/p ">You can use the <codeph class="+ topic/ph pr-d/codeph ">new Rectangle()</codeph> constructor to create a
 * Rectangle object.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> The Rectangle class does not define a rectangular Shape display object. To draw
 * a rectangular Shape object onscreen, use the <codeph class="+ topic/ph pr-d/codeph ">drawRect()</codeph> method of the Graphics
 * class.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the RectangleExample class to create three new Rectangle
 * objects at various <i class="+ topic/ph hi-d/i ">x</i>,<i class="+ topic/ph hi-d/i ">y</i> coordinates and with various heights and widths and then uses the
 * <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph> method to confirm that the Rectangle instances were successfully created.  Then a Boolean
 * variable <codeph class="+ topic/ph pr-d/codeph ">isContained</codeph> is assigned to the result of the call to
 * the <codeph class="+ topic/ph pr-d/codeph ">containsRect()</codeph> method,
 * which determines that the second rectangle does not fully enclose the third rectangle.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.geom.Rectangle;
 *
 *   public class RectangleExample extends Sprite {
 *
 *   public function RectangleExample() {
 * var firstRect:Rectangle = new Rectangle();
 * trace(firstRect);  // (x=0, y=0, w=0, h=0)
 * var secondRect:Rectangle = new Rectangle(1, 3, 11, 13);
 * trace(secondRect); // (x=1, y=3, w=11, h=13)
 * var thirdRect:Rectangle = new Rectangle(5, 8, 17, 19);
 * trace(thirdRect);  // (x=5, y=8, w=17, h=19)
 * var isContained:Boolean = secondRect.containsRect(thirdRect);
 * trace(isContained); // false
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

using namespace flash::geom;

namespace flash
{
    namespace geom
    {
        class Rectangle : public Object
        {
            /**
             * The x coordinate of the top-left corner of the rectangle. Changing
             * the value of the x property of a Rectangle object has no effect on the
             * y,
             * width, and height properties.
             *
             *   The value of the x property is equal to the value of the
             * left property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates an empty Rectangle and sets its <i class="+ topic/ph hi-d/i ">x</i> property
             *   to 10. Notice that <code>rect.left</code> is also changed.
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle();
             *   trace(rect.x); // 0
             *   trace(rect.left); // 0
             *   rect.x = 10;
             *   trace(rect.x); // 10
             *   trace(rect.left); // 10
             *   </listing>
             */
        public:
            float x;

            /**
             * The y coordinate of the top-left corner of the rectangle. Changing
             * the value of the y property of a Rectangle object has no effect on the
             * x, width, and height properties.
             *
             *   The value of the y property is equal to the value of
             * the top property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates an empty Rectangle and sets its <i class="+ topic/ph hi-d/i ">y</i> property
             *   to 10. Notice that <code>rect.top</code> is also changed.
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle();
             *   trace(rect.y); // 0
             *   trace(rect.top); // 0
             *   rect.y = 10;
             *   trace(rect.y); // 10
             *   trace(rect.top); // 10
             *   </listing>
             */
        public:
            float y;

            /**
             * The width of the rectangle, in pixels. Changing the width value of a Rectangle object
             * has no effect on the x, y, and height
             * properties.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates a Rectangle object and change its <code>width</code> property
             *   from 10 to 20. Notice that <code>rect.right</code> also
             *   changes.
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle(5, 5, 10, 10);
             *   trace(rect.width); // 10
             *   trace(rect.right); // 15
             *   rect.width = 20;
             *   trace(rect.width); // 20
             *   trace(rect.right); // 25
             *   </listing>
             */
        public:
            float width;

            /**
             * The height of the rectangle, in pixels. Changing the height value of a Rectangle
             * object has no effect on the x, y, and
             * width properties.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Create a Rectangle and change its <i class="+ topic/ph hi-d/i ">width</i> property
             *   from 10 to 20. Notice that <code>rect.right</code> is also
             *   changed.
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle(5, 5, 10, 10);
             *   trace(rect.width); // 10
             *   trace(rect.right); // 15
             *   rect.width = 20;
             *   trace(rect.width); // 20
             *   trace(rect.right); // 25
             *   </listing>
             */
        public:
            float height;

            /**
             * The x coordinate of the top-left corner of the rectangle. Changing
             * the left property of a Rectangle object has no effect on the y
             * and height properties. However it does affect the width
             * property, whereas changing the x value does not affect the
             * width property.
             *
             *   The value of the left property is equal to the value of the
             * x property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Change the <i class="+ topic/ph hi-d/i ">left</i> property and notice that
             *   <code>rect.x</code> is also changed.
             *   <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle();
             *   trace(rect.left); // 0
             *   trace(rect.x); // 0
             *   rect.left = 10;
             *   trace(rect.left); // 10
             *   trace(rect.x); // 10
             *   </listing>
             */
        public:
            float       left();
        public:
            void         left(float value);

            /**
             * The sum of the x and
             * width properties.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Create a Rectangle and change its <i class="+ topic/ph hi-d/i ">right</i> property
             *   from 15 to 30. Notice that <code>rect.width</code> is also
             *   changed.
             *   <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle(5, 5, 10, 10);
             *   trace(rect.width); // 10
             *   trace(rect.right); // 15
             *   rect.right = 30;
             *   trace(rect.width); // 25
             *   trace(rect.right); // 30
             *   </listing>
             */
        public:
            float       right();
        public:
            void         right(float value);

            /**
             * The y coordinate of the top-left corner of the rectangle. Changing
             * the top property of a Rectangle object has no effect on the x
             * and width properties. However it does affect the height
             * property, whereas changing the y value does not affect the
             * height property.
             *
             *   The value of the top property is equal to the value of the y property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Change the <i class="+ topic/ph hi-d/i ">top</i> property and notice that
             *   <code>rect.y</code> is also changed.
             *   <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle();
             *   trace(rect.top); // 0
             *   trace(rect.y); // 0
             *   rect.top = 10;
             *   trace(rect.top); // 10
             *   trace(rect.y); // 10
             *   </listing>
             */
        public:
            float       top();
        public:
            void         top(float value);

            /**
             * The sum of the y and
             * height properties.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Create a Rectangle and change its <i class="+ topic/ph hi-d/i ">bottom</i> property
             *   from 15 to 30. Notice that <code>rect.height</code> is also
             *   changed.
             *   <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle(5, 5, 10, 10);
             *   trace(rect.height); // 10
             *   trace(rect.bottom); // 15
             *   rect.bottom = 30;
             *   trace(rect.height); // 25
             *   trace(rect.bottom); // 30
             *   </listing>
             */
        public:
            float       bottom();
        public:
            void         bottom(float value);

            /**
             * The location of the Rectangle object's top-left corner, determined by the x and
             * y coordinates of the point.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Get the Rectangle <code>topLeft</code> property as a Point object.
             *   <listing version="2.0">
             *   var rect:Rectangle = new Rectangle(5, 15);
             *   var myTopLeft:Point = rect.topLeft;
             *   trace(myTopLeft.x); // 5;
             *   trace(myTopLeft.y); // 15;
             *   </listing>
             */
        public:
            flash::geom::Point *topLeft();
        public:
            void         topLeft(Point *value);

            /**
             * The location of the Rectangle object's bottom-right corner, determined by the values of the right and
             * bottom properties.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Get the Rectangle <code>bottomRight</code> property as a Point object.
             *   <listing version="2.0">
             *   var rect:Rectangle = new Rectangle(1, 2, 4, 8);
             *   trace(rect.bottom); // 5
             *   trace(rect.right); // 10
             *   var myBottomRight:Point = rect.bottomRight;
             *   trace(myBottomRight.x); // 5
             *   trace(myBottomRight.y); // 10
             *   </listing>
             */
        public:
            flash::geom::Point *bottomRight();
        public:
            void         bottomRight(Point *value);

            /**
             * The size of the Rectangle object, expressed as a Point object with the values
             * of the width and height properties.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates a new Rectangle, retrieves it's <code>size</code>,
             *   changes the <code>size</code> and sets the new values on the Rectangle instance.
             *   It is critical to remember that the <code>Point</code> object used by <code>size</code>
             *   uses x and y values to represent the <code>width</code> and <code>height</code> properties
             *   of the Rectangle.
             *   <listing version="2.0">
             *   import flash.geom.Rectangle;
             *   import flash.geom.Point;
             *   var rect:Rectangle = new Rectangle(1, 2, 4, 8);
             *
             *     var size:Point = rect.size;
             *   trace(size.x); // 4;
             *   trace(size.y); // 8;
             *
             *     size.x = 16;
             *   size.y = 32;
             *   rect.size = size;
             *   trace(rect.x); // 1
             *   trace(rect.y); // 2
             *   trace(rect.width); // 16
             *   trace(rect.height); // 32
             *   </listing>
             */
        public:
            flash::geom::Point *size();
        public:
            void         size(Point *value);

            /**
             * Creates a new Rectangle object with the top-left corner specified by the x
             * and y parameters and with the specified width and height
             * parameters. If you call this function without parameters,
             * a rectangle with x, y, width, and height
             * properties set to 0 is created.
             * @param   x   The x coordinate of the top-left corner of the rectangle.
             * @param   y   The y coordinate of the top-left corner of the rectangle.
             * @param   width   The width of the rectangle, in pixels.
             * @param   height  The height of the rectangle, in pixels.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Create a new Rectangle with with specific parameters.
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle(5, 10, 50, 100);
             *   trace(rect.toString()); // (x=5, y=10, w=50, h=100)
             *   </listing>
             */
        public:
            Rectangle(float x=0, float y=0, float width=0, float height=0);

            /**
             * Returns a new Rectangle object with the same values for the x, y,
             * width, and height properties as the original Rectangle object.
             * @return  A new Rectangle object with the same values for the x, y,
             *   width, and height properties as the original Rectangle object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example demonstrates the <code>clone</code> member.
             *   <listing version="2.0">
             *   import flash.geom.Rectangle;
             *   var rect:Rectangle = new Rectangle(1, 2, 4, 8);
             *   var shadow:Rectangle = rect.clone();
             *   shadow.offset(5, 5);
             *   trace(rect); // (x=1, y=2, w=4, h=8)
             *   trace(shadow); // (x=6, y=7, w=4, h=8)
             *   </listing>
             */
        public:
            flash::geom::Rectangle *clone();

            /**
             * Determines whether or not this Rectangle object is empty.
             * @return  A value of true if the Rectangle object's width or height is less than
             *   or equal to 0; otherwise false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Create a non-empty Rectangle and make it become empty.
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle(1, 2, 4, 8);
             *   trace(rect.isEmpty()); // false
             *   rect.width = 0;
             *   trace(rect.isEmpty()); // true
             *   rect.width = 4;
             *   trace(rect.isEmpty()); // false
             *   rect.height = 0;
             *   trace(rect.isEmpty()); // true
             *   </listing>
             */
        public:
            bool  isEmpty();

            /**
             * Sets all of the Rectangle object's properties to 0. A Rectangle object is empty if its width or
             * height is less than or equal to 0.
             *
             *   This method sets the values of the x, y,
             * width, and height properties to 0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Create a non-empty Rectangle and make it empty.
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle(5, 10, 50, 100);
             *   trace(rect.isEmpty()); // false
             *   rect.setEmpty();
             *   trace(rect.isEmpty()); // true
             *   </listing>
             */
        public:
            void     setEmpty();

            /**
             * Increases the size of the Rectangle object by the specified amounts, in pixels. The center point of the
             * Rectangle object stays the same, and its size increases to the left and right by the
             * dx value, and to the top and the bottom by the dy value.
             * @param   dx  The value to be added to the left and the right of the Rectangle object. The following
             *   equation is used to calculate the new width and position of the rectangle:
             *
             *     <codeblock>
             *
             *     x -= dx;
             *   width += 2 ~~ dx;
             *
             *     </codeblock>
             * @param   dy  The value to be added to the top and the bottom of the Rectangle. The
             *   following equation is used to calculate the new height and position of the rectangle:
             *
             *     <codeblock>
             *
             *     y -= dy;
             *   height += 2 ~~ dy;
             *
             *     </codeblock>
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Create a Rectangle and increase its <code>width</code> by 16 ~~ 2 (32) and it's <code>height</code> by 32 ~~ 2 (64)
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle(1, 2, 4, 8);
             *   trace(rect.toString()); // (x=1, y=2, w=4, h=8)
             *   rect.inflate(16, 32);
             *   trace(rect.toString()); // (x=-15, y=-30, w=36, h=72)
             *   </listing>
             */
        public:
            void     inflate(float dx, float dy);

            /**
             * Increases the size of the Rectangle object.
             * This method is similar to the Rectangle.inflate() method
             * except it takes a Point object as a parameter.
             *
             *   The following two code examples give the same result:
             * <codeblock>
             *
             *   var rect1:Rectangle = new Rectangle(0,0,2,5);
             * rect1.inflate(2,2)
             *
             *   </codeblock>
             *
             *   <codeblock>
             *
             *   var rect1:Rectangle = new Rectangle(0,0,2,5);
             * var pt1:Point = new Point(2,2);
             * rect1.inflatePoint(pt1)
             *
             *   </codeblock>
             * @param   point   The x property of this Point object is used to increase the
             *   horizontal dimension of the Rectangle object. The y property
             *   is used to increase the vertical dimension of the Rectangle object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Create a Rectangle and inflate it by the <i class="+ topic/ph hi-d/i ">x</i><i class="+ topic/ph hi-d/i ">horizontal</i> and <i class="+ topic/ph hi-d/i ">y</i><i class="+ topic/ph hi-d/i ">vertical</i> amounts found in Point
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle(0, 0, 2, 5);
             *   var myPoint:Point = new Point(2, 2);
             *   rect.inflatePoint(myPoint);
             *   trace(rect.toString()); // (x=-2, y=-2, w=6, h=9)
             *   </listing>
             */
        public:
            void     inflatePoint(Point *point);

            /**
             * Adjusts the location of the Rectangle object, as determined by its top-left corner,
             * by the specified amounts.
             * @param   dx  Moves the x value of the Rectangle object by this amount.
             * @param   dy  Moves the y value of the Rectangle object by this amount.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Create a Rectangle and offset it's <i class="+ topic/ph hi-d/i ">x</i> and <i class="+ topic/ph hi-d/i ">y</i> values by 5 and 10 respectively
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle(1, 2, 4, 8);
             *   rect.offset(16, 32);
             *   trace(rect.toString()); // (x=17, y=34, w=4, h=8)
             *   </listing>
             */
        public:
            void     offset(float dx, float dy);

            /**
             * Adjusts the location of the Rectangle object using a Point object as a parameter.
             * This method is similar to the Rectangle.offset() method, except that it takes a Point
             * object as a parameter.
             * @param   point   A Point object to use to offset this Rectangle object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Offset a Rectangle by using the values found in a Point
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle(1, 2, 4, 8);
             *   var myPoint:Point = new Point(16, 32);
             *   rect.offsetPoint(myPoint);
             *   trace(rect.toString()); // (x=17, y=34, w=4, h=8)
             *   </listing>
             */
        public:
            void     offsetPoint(Point *point);

            /**
             * Determines whether the specified point is contained within the rectangular region defined
             * by this Rectangle object.
             * @param   x   The x coordinate (horizontal position) of the point.
             * @param   y   The y coordinate (vertical position) of the point.
             * @return  A value of true if the Rectangle object contains the specified point;
             *   otherwise false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Do the coordinates fall inside of the Rectangle?
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle(10, 10, 50, 50);
             *   var doesContain_1:Boolean = rect.contains(59, 59);
             *   trace(doesContain_1); // true
             *   var doesContain_2:Boolean = rect.contains(10, 10);
             *   trace(doesContain_2); // true
             *   var doesContain_3:Boolean = rect.contains(60, 60);
             *   trace(doesContain_3); // false
             *   </listing>
             */
        public:
            bool  contains(float x, float y);

            /**
             * Determines whether the specified point is contained within the rectangular region defined
             * by this Rectangle object. This method is similar to the Rectangle.contains() method,
             * except that it takes a Point object as a parameter.
             * @param   point   The point, as represented by its x and y coordinates.
             * @return  A value of true if the Rectangle object contains the specified point;
             *   otherwise false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Do the specified Points fall inside of the Rectangle?
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect:Rectangle = new Rectangle(10, 10, 50, 50);
             *   var containsPoint_1:Boolean = rect.containsPoint(new Point(10, 10));
             *   trace(containsPoint_1); // true
             *   var containsPoint_2:Boolean = rect.containsPoint(new Point(59, 59));
             *   trace(containsPoint_2); // true
             *   var containsPoint_3:Boolean = rect.containsPoint(new Point(60, 60));
             *   trace(containsPoint_3); // false
             *   </listing>
             */
        public:
            bool  containsPoint(Point *point);

            /**
             * Determines whether the Rectangle object specified by the rect parameter is contained
             * within this Rectangle object. A Rectangle object is said to contain another if the second
             * Rectangle object falls entirely within the boundaries of the first.
             * @param   rect    The Rectangle object being checked.
             * @return  A value of true if the Rectangle object that you specify is
             *   contained by this Rectangle object; otherwise false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample A Rectangle is said to contain another if that second
             *   Rectangle falls entirely within the boundaries of the first.
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rectA:Rectangle = new Rectangle(10, 10, 50, 50);
             *   var rectB:Rectangle = new Rectangle(10, 10, 50, 50);
             *   var rectC:Rectangle = new Rectangle(10, 10, 51, 51);
             *   var rectD:Rectangle = new Rectangle(15, 15, 45, 45);
             *   var rectAContainsB:Boolean = rectA.containsRect(rectB); // true
             *   var rectAContainsC:Boolean = rectA.containsRect(rectC); // false
             *   var rectAContainsD:Boolean = rectA.containsRect(rectD); // true
             *   </listing>
             */
        public:
            bool  containsRect(Rectangle *rect);

            /**
             * If the Rectangle object specified in the toIntersect parameter intersects with this Rectangle
             * object, returns the area of intersection as a Rectangle object.
             * If the rectangles do not intersect, this method returns an empty Rectangle object with its properties
             * set to 0.
             * @param   toIntersect The Rectangle object to compare against to see if it intersects with
             *   this Rectangle object.
             * @return  A Rectangle object that equals the area of intersection. If the rectangles do not
             *   intersect, this method returns an empty Rectangle object; that is, a rectangle with its x,
             *   y, width, and height properties set to 0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample What area overlaps <code>rect_1</code> between <code>rect_2</code>?
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect_1:Rectangle = new Rectangle(0, 0, 50, 50);
             *   var rect_2:Rectangle = new Rectangle(25, 25, 100, 100);
             *   var intersectingArea:Rectangle = rect_1.intersection(rect_2);
             *   trace(intersectingArea.toString()); // (x=25, y=25, w=25, h=25)
             *   </listing>
             */
        public:
            flash::geom::Rectangle *intersection(Rectangle *toIntersect);

            /**
             * Determines whether the object specified in the toIntersect parameter intersects
             * with this Rectangle object. This method checks the x, y,
             * width, and height properties of the specified Rectangle object to see
             * if it intersects with this Rectangle object.
             * @param   toIntersect The Rectangle object to compare against this Rectangle object.
             * @return  A value of true if the specified object intersects with this Rectangle object;
             *   otherwise false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Does <code>rect_1</code> intersect with <code>rect_2</code>?
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rectA:Rectangle = new Rectangle(10, 10, 50, 50);
             *   var rectB:Rectangle = new Rectangle(59, 59, 50, 50);
             *   var rectC:Rectangle = new Rectangle(60, 60, 50, 50);
             *   var rectAIntersectsB:Boolean = rectA.intersects(rectB);
             *   var rectAIntersectsC:Boolean = rectA.intersects(rectC);
             *   trace(rectAIntersectsB); // true
             *   trace(rectAIntersectsC); // false
             *
             *     var firstPixel:Rectangle = new Rectangle(0, 0, 1, 1);
             *   var adjacentPixel:Rectangle = new Rectangle(1, 1, 1, 1);
             *   var pixelsIntersect:Boolean = firstPixel.intersects(adjacentPixel);
             *   trace(pixelsIntersect); // false
             *   </listing>
             */
        public:
            bool  intersects(Rectangle *toIntersect);

            /**
             * Adds two rectangles together to create a new Rectangle object, by
             * filling in the horizontal and vertical space between the two rectangles.
             *
             *   Note: The union() method ignores rectangles with 0
             * as the height or width value, such as: var rect2:Rectangle = new Rectangle(300,300,50,0);
             * @param   toUnion A Rectangle object to add to this Rectangle object.
             * @return  A new Rectangle object that is the union of the two rectangles.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Create a new Rectangle out of the Union of two others.
             *   <p class="- topic/p ">For example, consider a rectangle with properties <code>x=20</code>, <code>y=50</code>, <code>width=60</code>, and
             *   <code>height=30</code> (20, 50, 60, 30) and a second rectangle with properties (150, 130, 50, 30).
             *   The union of these two rectangles would be a larger rectangle encompassing the two rectangles
             *   with the properties (20, 50, 180, 110).</p><listing version="2.0">
             *   import flash.geom.~~;
             *   var rect_1:Rectangle = new Rectangle(20, 50, 60, 30);
             *   var rect_2:Rectangle = new Rectangle(150, 130, 50, 30);
             *   var combined:Rectangle = rect_1.union(rect_2);
             *   trace(combined.toString()); // (x=20, y=50, w=180, h=110)
             *   </listing>
             */
        public:
            flash::geom::Rectangle *UNION(Rectangle *toUnion);

            /**
             * Determines whether the object specified in the toCompare parameter is
             * equal to this Rectangle object. This method compares the x, y,
             * width, and height properties of an object against the same properties
             * of this Rectangle object.
             * @param   toCompare   The rectangle to compare to this Rectangle object.
             * @return  A value of true if the object has exactly the same values for the
             *   x, y, width, and height properties
             *   as this Rectangle object; otherwise false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Even though the method signature only expects an abstract Object
             *   only other Rectangle instances will ever be treated as equal.
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect_1:Rectangle = new Rectangle(0, 0, 50, 100);
             *   var nonRect:Object = new Object();
             *   nonRect.x = 0;
             *   nonRect.y = 0;
             *   nonRect.width = 50;
             *   nonRect.height = 100;
             *   trace(rect_1.equals(nonRect));
             *   </listing>
             */
        public:
            bool  equals(Rectangle *toCompare);

            /**
             * Builds and returns a string that lists the horizontal and vertical positions
             * and the width and height of the Rectangle object.
             * @return  A string listing the value of each of the following properties of the Rectangle object:
             *   x, y, width, and height.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample Concatenate a String representation of <code>rect_1</code> with some helpful
             *   debugging text.
             *
             *     <listing version="2.0">
             *   import flash.geom.~~;
             *   var rect_1:Rectangle = new Rectangle(0, 0, 50, 100);
             *   trace("Rectangle 1 : " + rect_1.toString()); // Rectangle 1 : (x=0, y=0, w=50, h=100)
             *   </listing>
             */
        public:
            std::string   toString();

        public:
            void     copyFrom(Rectangle *sourceRect);

        public:
            void     setTo(float xa, float ya, float widtha, float heighta);
        };
    }
}

#endif // FLEX11_6_FLASH_GEOM_RECTANGLE_AS
#endif // __cplusplus

