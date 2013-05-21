

#include "Point.h"
#include "flash/geom/Point.h"

    /**
     * The Point object represents a location in a two-dimensional coordinate system, where <i class="+ topic/ph hi-d/i ">x</i>
     * represents the horizontal axis and <i class="+ topic/ph hi-d/i ">y</i> represents the vertical axis.
     * 
     *   <p class="- topic/p ">The following code creates a point at (0,0):</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">var myPoint:Point = new Point();</codeblock><p class="- topic/p ">Methods and properties of the following classes use Point objects:</p><ul class="- topic/ul "><li class="- topic/li ">BitmapData</li><li class="- topic/li ">DisplayObject</li><li class="- topic/li ">DisplayObjectContainer</li><li class="- topic/li ">DisplacementMapFilter</li><li class="- topic/li ">NativeWindow</li><li class="- topic/li ">Matrix</li><li class="- topic/li ">Rectangle</li></ul><p class="- topic/p ">You can use the <codeph class="+ topic/ph pr-d/codeph ">new Point()</codeph> constructor to create a 
     * Point object.</p>
     * 
     *   EXAMPLE:
     * 
     *   The following example uses the PointExample class to create a number of new Point
     * objects at various <i class="+ topic/ph hi-d/i ">x,y</i> coordinates and then uses the <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph> method to output the  
     * results of various class methods.
     * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * import flash.display.Sprite;
     * import flash.geom.Point;
     * 
     *   public class PointExample extends Sprite {
     * 
     *   public function PointExample() {
     * var point1:Point = new Point();
     * trace(point1);  // (x=0, y=0)
     * 
     *   var point2:Point = new Point(6, 8);
     * trace(point2); // (x=6, y=8)
     * 
     *   trace(Point.interpolate(point1, point2, 0.5)); // (x=3, y=4)
     * 
     *   trace(Point.distance(point1, point2)); // 10
     * 
     *   trace(point1.add(point2)); // (x=6, y=8)
     * 
     *   var point3:Point = point2.clone();
     * trace(point2.equals(point3)); // true
     * 
     *   point3.normalize(2.5);
     * trace(point3); // (x=1.5, y=2)
     * 
     *   trace(point2.subtract(point3)); // (x=4.5, y=6)
     * 
     *   trace(point1.offset(2, 3)); //
     * 
     *   var angle:Number = Math.PI * 2 * (30 / 360); // 30 degrees
     * trace(Point.polar(4, angle)) // (x=3.464101615137755, y=1.9999999999999998)   
     * }
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */

using namespace flash::geom;

namespace flash {
namespace geom {


        /**
         * The horizontal coordinate of the point. The default value is 0.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @maelexample The following example sets the <i class="+ topic/ph hi-d/i ">x</i> (horizontal) coordinate of <code>myPoint</code> and gets <code>myX</code> from <code>myPoint.x</code>.
         *   
         *     <listing version="2.0">  
         *   import flash.geom.Point;
         *   var myPoint:Point = new Point();
         *   trace(myPoint.x); // 0
         *   myPoint.x = 5;
         *   trace(myPoint.x); // 5
         *   var myX:Number = myPoint.x;
         *   trace(myX); // 5
         *   </listing>
         */
                   

        /**
         * The vertical coordinate of the point. The default value is 0.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @maelexample The following example sets the <i class="+ topic/ph hi-d/i ">y</i> (vertical) coordinate of <code>myPoint</code> and gets <code>myY</code> from <code>myPoint.y</code>.
         *   
         *     <listing version="2.0">  
         *   import flash.geom.Point;
         *   var myPoint:Point = new Point();
         *   trace(myPoint.y); // 0
         *   myPoint.y = 5;
         *   trace(myPoint.y); // 5
         *   var myY:Number = myPoint.y;
         *   trace(myY); // 5
         *   </listing>
         */
                   

        /**
         * The length of the line segment from (0,0) to this point.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @maelexample The following example creates a new Point, <code>myPoint</code>, and determines the length of a line from (0, 0) to that Point.
         *   
         *     <listing version="2.0">
         *   import flash.geom.Point;
         *   var myPoint:Point = new Point(3,4);
         *   trace(myPoint.length); // 5
         *   </listing>
         */
        float Point::length()         ;

        /**
         * Determines a point between two specified points. The parameter f 
         * determines where the new interpolated point is located relative to the two end points 
         * specified by parameters pt1 and pt2. The closer the value of the parameter
         * f is to 1.0, the closer the interpolated point is to the
         * first point (parameter pt1). The closer the value of the parameter f is
         * to 0, the closer the interpolated point is to the second point (parameter pt2).
         * @param   pt1 The first point.
         * @param   pt2 The second point.
         * @param   f   The level of interpolation between the two points. Indicates where the new point will be, along the line 
         *   between pt1 and pt2. If f=1, pt1 is returned; if 
         *   f=0, pt2 is returned.
         * @return  The new, interpolated point.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @maelexample The following example locates the interpolated point (<code>interpolatedPoint</code>) half way (50%) between <code>point_1</code> and <code>point_2</code>.
         *   
         *     <listing version="2.0">
         *   import flash.geom.Point;
         *   var point_1:Point = new Point(-100, -100);
         *   var point_2:Point = new Point(50, 50);
         *   var interpolatedPoint:Point = Point.interpolate(point_1, point_2, .5);
         *   trace(interpolatedPoint.toString()); // (x=-25, y=-25)
         *   </listing>
         */
        flash::geom::Point* Point::interpolate(Point* pt1, Point* pt2, float f)                   ;

        /**
         * Returns the distance between pt1 and pt2.
         * @param   pt1 The first point.
         * @param   pt2 The second point.
         * @return  The distance between the first and second points.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        float Point::distance(Point* pt1, Point* pt2)         ;

        /**
         * Creates a new point. If you pass no parameters to this method, a point is created at (0,0).
         * @param   x   The horizontal coordinate.
         * @param   y   The vertical coordinate.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @maelexample The first example creates <code>point_1</code> with the default constructor.
         *   <listing version="2.0">
         *   import flash.geom.Point;
         *   var point_1:Point = new Point();
         *   trace(point_1.x); // 0
         *   trace(point_1.y); // 0
         *   </listing>
         *   The second example creates <code>point_2</code> with the coordinates x = 1 and y = 2.
         *   <listing version="2.0">
         *   import flash.geom.Point;
         *   var point_2:Point = new Point(1, 2);
         *   trace(point_2.x); // 1
         *   trace(point_2.y); // 2
         *   </listing>
         */
        Point::Point(float x, float y);

        /**
         * Converts a pair of polar coordinates to a Cartesian point coordinate.
         * @param   len The length coordinate of the polar pair.
         * @param   angle   The angle, in radians, of the polar pair.
         * @return  The Cartesian point.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @maelexample The following example creates a Point object <code>cartesianPoint</code> from the value of <code>angleInRadians</code>
         *   and a line length of 5.  The <code>angleInRadians</code> value equal to Math.atan(3/4)
         *   is used because of the characteristics of right triangles with sides that 
         *   have ratios of 3:4:5.
         *   
         *     <listing version="2.0">
         *   import flash.geom.Point;
         *   var len:Number = 5;
         *   var angleInRadians:Number = Math.atan(3/4);
         *   var cartesianPoint:Point = Point.polar(len, angleInRadians);
         *   trace(cartesianPoint.toString()); // (x=4, y=3)
         *   </listing>
         *   
         *     When computers work with transcendental numbers such as pi, some round-off
         *   error occurs because floating-point arithmetic has only finite precision.
         *   When you use <code>Math.PI</code>, consider using the <code>Math.round()</code> function, as shown 
         *   in the following example.
         *   
         *     <listing version="2.0">
         *   import flash.geom.Point;
         *   var len:Number = 10;
         *   var angleInRadians:Number = Math.PI;
         *   var cartesianPoint:Point = Point.polar(len, angleInRadians);
         *   trace(cartesianPoint.toString()); // should be (x=-10, y=0), but is (x=-10, y=1.22460635382238e-15)
         *   trace(Math.round(cartesianPoint.y)); // 0
         *   </listing>
         */
        flash::geom::Point* Point::polar(float len, float angle)                   ;

        /**
         * Creates a copy of this Point object.
         * @return  The new Point object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @maelexample The following example creates a <code>clonedPoint</code> from the values found in 
         *   <code>myPoint</code>.  The <code>clonedPoint</code> contains all the
         *   the values from <code>myPoint</code> but is not the same object.
         *   
         *     <listing version="2.0">
         *   import flash.geom.Point;
         *   var myPoint:Point = new Point(1, 2);
         *   var clonedPoint:Point = myPoint.clone();
         *   trace(clonedPoint.x); // 1
         *   trace(clonedPoint.y); // 2
         *   trace(myPoint.equals(clonedPoint)); // true
         *   trace(myPoint === clonedPoint); // false
         *   </listing>
         */
        flash::geom::Point* Point::clone()                   ;

        /**
         * Offsets the Point object by the specified amount. The value of dx is added
         * to the original value of x to create the new x value. The value
         * of dy is added to the original value of y to create the new y value.
         * @param   dx  The amount by which to offset the horizontal coordinate, x.
         * @param   dy  The amount by which to offset the vertical coordinate, y.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void Point::offset(float dx, float dy)       ;

        /**
         * Determines whether two points are equal. Two points are equal if they have the same x and
         * y values.
         * @param   toCompare   The point to be compared.
         * @return  A value of true if the object is equal to this Point object; false if it is not equal.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        bool Point::equals(Point* toCompare)          ;

        /**
         * Subtracts the coordinates of another point from the coordinates of this point to create a new 
         * point.
         * @param   v   The point to be subtracted.
         * @return  The new point.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @maelexample The following example creates <code>point_3</code> by subtracting <code>point_2</code> from <code>point_1</code>.
         *   
         *     <listing version="2.0">
         *   import flash.geom.Point;
         *   var point_1:Point = new Point(4, 8);
         *   var point_2:Point = new Point(1, 2);
         *   var resultPoint:Point = point_1.subtract(point_2);
         *   trace(resultPoint.toString()); // (x=3, y=6)
         *   </listing>
         */
        flash::geom::Point* Point::subtract(Point* v)                   ;

        /**
         * Adds the coordinates of another point to the coordinates of this point to create a new point.
         * @param   v   The point to be added.
         * @return  The new point.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @maelexample The following example creates a Point object <code>resultPoint</code> by adding <code>point_2</code> to 
         *   <code>point_1</code>.
         *   
         *     <listing version="2.0">
         *   import flash.geom.Point;
         *   var point_1:Point = new Point(4, 8);
         *   var point_2:Point = new Point(1, 2);
         *   var resultPoint:Point = point_1.add(point_2);
         *   trace(resultPoint.toString()); // (x=5, y=10)
         *   </listing>
         */
        flash::geom::Point* Point::add(Point* v)                   ;

        /**
         * Scales the line segment between (0,0) and the current point to a set length.
         * @param   thickness   The scaling value. For example, if the current point is (0,5), 
         *   and you normalize it to 1, the point returned is at (0,1).
         * @return  The normalized point.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @maelexample The following example extends the length of the <code>normalizedPoint</code> object from 5 to 10.
         *   
         *     <listing version="2.0">
         *   import flash.geom.Point;
         *   var normalizedPoint:Point = new Point(3, 4);
         *   trace(normalizedPoint.length); // 5
         *   trace(normalizedPoint.toString()); // (x=3, y=4)
         *   normalizedPoint.normalize(10);
         *   trace(normalizedPoint.length); // 10
         *   trace(normalizedPoint.toString()); // (x=6, y=8)
         *   </listing>
         */
        void Point::normalize(float thickness)       ;

        /**
         * Returns a string that contains the values of the x and y coordinates.
         * 
         *   The string has the form "(x=x, y=y)", so calling the toString()
         * method for a point at 23,17 would return "(x=23, y=17)".
         * @return  The string representation of the coordinates.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string Point::toString()         ;

        void Point::copyFrom(Point* sourcePoint)       ;

        void Point::setTo(float xa, float ya)       ;
}
}

