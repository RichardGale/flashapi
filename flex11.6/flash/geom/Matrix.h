#if !defined(FLEX11_6_FLASH_GEOM_MATRIX_AS)
#define FLEX11_6_FLASH_GEOM_MATRIX_AS
#if defined(__cplusplus)


#include "flex11.6.h"

namespace flash
{
    namespace geom
    {
        class Point;
    }
}
namespace flash
{
    namespace geom
    {
        class Vector3D;
    }
}

/**
 * The Matrix class represents a transformation matrix that determines how to map points from one
 * coordinate space to another.  You can perform various graphical
 * transformations on a display object by setting the properties of a Matrix object,
 * applying that Matrix object to the <codeph class="+ topic/ph pr-d/codeph ">matrix</codeph> property of a Transform object,
 * and then applying that Transform object as the <codeph class="+ topic/ph pr-d/codeph ">transform</codeph> property of the display object.
 * These transformation functions include translation
 * (<i class="+ topic/ph hi-d/i ">x</i> and <i class="+ topic/ph hi-d/i ">y</i> repositioning), rotation, scaling, and skewing.
 *
 *   <p class="- topic/p ">Together these types of transformations are known as <i class="+ topic/ph hi-d/i ">affine transformations</i>.
 * Affine transformations preserve the straightness of lines while transforming, so that
 * parallel lines stay parallel.</p><p class="- topic/p ">To apply a transformation matrix to a display object, you create a Transform
 * object, set its <codeph class="+ topic/ph pr-d/codeph ">matrix</codeph> property to the transformation matrix, and then set the <codeph class="+ topic/ph pr-d/codeph ">transform</codeph>
 * property of the display object to the Transform object.
 * Matrix objects are also used as parameters of some methods, such as the following:</p><ul class="- topic/ul "><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">draw()</codeph> method of a BitmapData object</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">beginBitmapFill()</codeph> method, <codeph class="+ topic/ph pr-d/codeph ">beginGradientFill()</codeph> method,
 * or <codeph class="+ topic/ph pr-d/codeph ">lineGradientStyle()</codeph> method of a Graphics object</li></ul><p class="- topic/p ">A transformation matrix object is a 3 x 3 matrix with the following contents:</p><p class="- topic/p "><adobeimage alt="Matrix class properties in matrix notation" href="../../images/matrix_props1.jpg" placement="inline" class="+ topic/image adobe-d/adobeimage " /></p><p class="- topic/p ">In traditional transformation matrixes, the <codeph class="+ topic/ph pr-d/codeph ">u</codeph>, <codeph class="+ topic/ph pr-d/codeph ">v</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">w</codeph>
 * properties provide extra capabilities.
 * The Matrix class can only operate in two-dimensional space, so it always
 * assumes that the property values <codeph class="+ topic/ph pr-d/codeph ">u</codeph> and <codeph class="+ topic/ph pr-d/codeph ">v</codeph> are 0.0, and that the property value
 * <codeph class="+ topic/ph pr-d/codeph ">w</codeph> is 1.0. The effective values of the matrix are as follows:</p><p class="- topic/p "><adobeimage alt="Matrix class properties in matrix notation showing    assumed values for u, v, and w" href="../../images/matrix_props2.jpg" placement="inline" class="+ topic/image adobe-d/adobeimage " /></p><p class="- topic/p ">You can get and set the values of all six of the other properties in a Matrix
 * object: <codeph class="+ topic/ph pr-d/codeph ">a</codeph>, <codeph class="+ topic/ph pr-d/codeph ">b</codeph>, <codeph class="+ topic/ph pr-d/codeph ">c</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">d</codeph>, <codeph class="+ topic/ph pr-d/codeph ">tx</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">ty</codeph>.</p><p class="- topic/p ">The Matrix class supports the four major types of transformations:
 * translation, scaling, rotation, and skewing. You can set three of these transformations by using
 * specialized methods, as described in the following table: </p><adobetable class="innertable"><tgroup cols="5" class="- topic/tgroup "><thead class="- topic/thead "><row class="- topic/row "><entry class="- topic/entry ">Transformation</entry><entry class="- topic/entry ">Method</entry><entry class="- topic/entry ">Matrix values</entry><entry class="- topic/entry ">Display result</entry><entry class="- topic/entry ">Description</entry></row></thead><tbody class="- topic/tbody "><row valign="top" class="- topic/row "><entry class="- topic/entry ">Translation (displacement)</entry><entry outputclass="nowrap" class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">translate(tx, ty)</codeph></entry><entry class="- topic/entry "><adobeimage alt="Matrix notation of translate method parameters" height="104" href="../../images/matrix_translate.jpg" width="150" placement="inline" class="+ topic/image adobe-d/adobeimage " /></entry><entry class="- topic/entry "><adobeimage alt="Illustration of translate method effects" height="91" href="../../images/matrix_translate_image.jpg" width="111" placement="inline" class="+ topic/image adobe-d/adobeimage " /></entry><entry class="- topic/entry ">Moves the image <codeph class="+ topic/ph pr-d/codeph ">tx</codeph> pixels to the right and <codeph class="+ topic/ph pr-d/codeph ">ty</codeph> pixels
 * down.</entry></row><row valign="top" class="- topic/row "><entry class="- topic/entry ">Scaling</entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">scale(sx, sy)</codeph></entry><entry class="- topic/entry "><adobeimage alt="Matrix notation of scale method parameters" height="105" href="../../images/matrix_scale.jpg" width="140" placement="inline" class="+ topic/image adobe-d/adobeimage " /></entry><entry class="- topic/entry "><adobeimage alt="Illustration of scale method effects" height="84" href="../../images/matrix_scale_image.jpg" width="111" placement="inline" class="+ topic/image adobe-d/adobeimage " /></entry><entry class="- topic/entry ">Resizes the image, multiplying the location of each pixel by <codeph class="+ topic/ph pr-d/codeph ">sx</codeph> on the
 * <i class="+ topic/ph hi-d/i ">x</i> axis and <codeph class="+ topic/ph pr-d/codeph ">sy</codeph> on the <i class="+ topic/ph hi-d/i ">y</i> axis.</entry></row><row valign="top" class="- topic/row "><entry class="- topic/entry ">Rotation</entry><entry class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">rotate(q)</codeph></entry><entry class="- topic/entry "><adobeimage alt="Matrix notation of rotate method properties" height="105" href="../../images/matrix_rotate.jpg" width="219" placement="inline" class="+ topic/image adobe-d/adobeimage " /></entry><entry class="- topic/entry "><adobeimage alt="Illustration of rotate method effects" height="91" href="../../images/matrix_rotate_image.jpg" width="111" placement="inline" class="+ topic/image adobe-d/adobeimage " /></entry><entry class="- topic/entry ">Rotates the image by an angle <codeph class="+ topic/ph pr-d/codeph ">q</codeph>, which is measured in radians.</entry></row><row valign="top" class="- topic/row "><entry class="- topic/entry ">Skewing or shearing </entry><entry class="- topic/entry ">None; must set the properties <codeph class="+ topic/ph pr-d/codeph ">b</codeph> and <codeph class="+ topic/ph pr-d/codeph ">c</codeph></entry><entry class="- topic/entry "><adobeimage alt="Matrix notation of skew function properties" href="../../images/matrix_skew.jpg" placement="inline" class="+ topic/image adobe-d/adobeimage " /></entry><entry class="- topic/entry "><adobeimage alt="Illustration of skew function effects" height="77" href="../../images/matrix_skew_image.jpg" width="111" placement="inline" class="+ topic/image adobe-d/adobeimage " /></entry><entry class="- topic/entry ">Progressively slides the image in a direction parallel to the <i class="+ topic/ph hi-d/i ">x</i> or <i class="+ topic/ph hi-d/i ">y</i>  axis. The <codeph class="+ topic/ph pr-d/codeph ">b</codeph>
 * property of the Matrix object represents the tangent of the skew angle along the <i class="+ topic/ph hi-d/i ">y</i> axis;
 * the <codeph class="+ topic/ph pr-d/codeph ">c</codeph> property of the Matrix object represents the tangent of the skew angle along the
 * <i class="+ topic/ph hi-d/i ">x</i> axis.</entry></row></tbody></tgroup></adobetable><p class="- topic/p ">Each transformation function alters the current matrix properties so that
 * you can effectively combine multiple transformations. To do this, you call more than one
 * transformation function before applying the matrix to its display object target (by using the
 * <codeph class="+ topic/ph pr-d/codeph ">transform</codeph> property of that display object).</p><p class="- topic/p ">Use the <codeph class="+ topic/ph pr-d/codeph ">new Matrix()</codeph> constructor to create a
 * Matrix object before you can call the methods of the Matrix object.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">MatrixExample</codeph> class to show
 * how a large gradient-filled square can be created.  This is accomplished with the following
 * steps:
 * <ol class="- topic/ol "><li class="- topic/li ">The application creates a new Matrix object <codeph class="+ topic/ph pr-d/codeph ">myMatrix</codeph>, and it uses the
 * <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph> method to output
 * the default property values for the <codeph class="+ topic/ph pr-d/codeph ">myMatrix</codeph> object.</li><li class="- topic/li ">The application calls the <codeph class="+ topic/ph pr-d/codeph ">createGradientBox()</codeph> with the <codeph class="+ topic/ph pr-d/codeph ">width</codeph>
 * and <codeph class="+ topic/ph pr-d/codeph ">height</codeph> parameters set to 200 pixels, no rotation, and the distance to translate along
 * the <i class="+ topic/ph hi-d/i ">x</i> and <i class="+ topic/ph hi-d/i ">y</i> axes set to 50 pixels.</li><li class="- topic/li ">The application prints the <codeph class="+ topic/ph pr-d/codeph ">myMatrix</codeph> object again to show the change after calling
 * <codeph class="+ topic/ph pr-d/codeph ">createGradientBox()</codeph>.</li><li class="- topic/li ">The application sets up three variables to control how the gradient box is filled:
 * <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">colors</codeph>: Sets the gradient colors to range between solid red and solid blue.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">alphas</codeph>: Sets the opacity to solid.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">ratios</codeph>: Sets the distribution of the colors to be equal for both red and blue.</li></ul></li><li class="- topic/li ">The application calls the graphics method <codeph class="+ topic/ph pr-d/codeph ">beginGradientFill()</codeph>, which operates on the <codeph class="+ topic/ph pr-d/codeph ">myMatrix</codeph>
 * object, and it calls the <codeph class="+ topic/ph pr-d/codeph ">lineTo()</codeph> method, resulting in the gradient-filled box.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.geom.Matrix;
 * import flash.display.Sprite;
 * import flash.display.GradientType;
 *
 *   public class MatrixExample extends Sprite {
 *
 *   public function MatrixExample() {
 * var myMatrix:Matrix = new Matrix();
 * trace(myMatrix.toString());    // (a=1, b=0, c=0, d=1, tx=0, ty=0)
 *
 *   myMatrix.createGradientBox(200, 200, 0, 50, 50);
 * trace(myMatrix.toString());    // (a=0.1220703125, b=0, c=0, d=0.1220703125, tx=150, ty=150)
 *
 *   var colors:Array = [0xFF0000, 0x0000FF];
 * var alphas:Array = [1, 1];
 * var ratios:Array = [0, 0xFF];
 * graphics.beginGradientFill(GradientType.LINEAR, colors, alphas, ratios, myMatrix);
 * graphics.lineTo(0, 300);
 * graphics.lineTo(300, 300);
 * graphics.lineTo(300, 0);
 * graphics.lineTo(0, 0);
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
        class Matrix : public Object
        {
            /**
             * The value that affects the positioning of pixels
             * along the x axis when scaling or rotating an image.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float a;

            /**
             * The value that affects the positioning of pixels
             * along the y axis when rotating or skewing an image.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float b;

            /**
             * The value that affects the positioning of pixels
             * along the x axis when rotating or skewing an image.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float c;

            /**
             * The value that affects the positioning of pixels
             * along the y axis when scaling or rotating an image.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float d;

            /**
             * The distance by which to translate each point along the x axis.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float tx;

            /**
             * The distance by which to translate each point along the y axis.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float ty;

            /**
             * Creates a new Matrix object with the specified parameters. In matrix notation, the properties
             * are organized like this:
             *
             *   If you do not provide any parameters to the new Matrix() constructor, it creates an
             * identity matrix with the following values:a = 1b = 0c = 0d = 1tx = 0ty = 0In matrix notation, the identity matrix looks like this:
             * @param   a   The value that affects the positioning of pixels
             *   along the x axis when scaling or rotating an image.
             * @param   b   The value that affects the positioning of pixels
             *   along the y axis when rotating or skewing an image.
             * @param   c   The value that affects the positioning of pixels
             *   along the x axis when rotating or skewing an image.
             * @param   d   The value that affects the positioning of pixels
             *   along the y axis when scaling or rotating an image..
             * @param   tx  The distance by which to translate each point along the x axis.
             * @param   ty  The distance by which to translate each point along the y axis.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            Matrix(float a =1, float b =0, float c =0, float d =1, float tx =0, float ty =0);

            /**
             * Returns a new Matrix object that is a clone of this
             * matrix, with an exact copy of the contained object.
             * @return  A Matrix object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates <code>clonedMatrix</code> from <code>myMatrix</code>.
             *   Notice that the Matrix class does not have an equals method, so the following example
             *   uses a custom written function to test the equality of two Matricies.
             *
             *     <listing version="2.0">
             *   import flash.geom.Matrix;
             *
             *     var myMatrix:Matrix = new Matrix(2, 0, 0, 2, 0, 0);
             *   var clonedMatrix:Matrix = new Matrix();
             *
             *     trace(myMatrix);                        // (a=2, b=0, c=0, d=2, tx=0, ty=0)
             *   trace(clonedMatrix);                    // (a=1, b=0, c=0, d=1, tx=0, ty=0)
             *   trace(equals(myMatrix, clonedMatrix));  // false
             *
             *     clonedMatrix = myMatrix.clone();
             *
             *     trace(myMatrix);                        // (a=2, b=0, c=0, d=2, tx=0, ty=0)
             *   trace(clonedMatrix);                    // (a=2, b=0, c=0, d=2, tx=0, ty=0)
             *   trace(equals(myMatrix, clonedMatrix));  // true
             *
             *     function equals(m1:Matrix, m2:Matrix):Boolean {
             *   return m1.toString() == m2.toString();
             *   }
             *   </listing>
             */
        public:
            flash::geom::Matrix *clone();

            /**
             * Concatenates a matrix with the current matrix, effectively combining the
             * geometric effects of the two. In mathematical terms, concatenating two matrixes
             * is the same as combining them using matrix multiplication.
             *
             *   For example, if matrix m1 scales an object by a factor of four, and
             * matrix m2 rotates an object by 1.5707963267949 radians
             * (Math.PI/2), then m1.concat(m2) transforms m1
             * into a matrix that scales an object by a factor of four and rotates the object by
             * Math.PI/2 radians. This method replaces the source matrix with the concatenated matrix. If you
             * want to concatenate two matrixes without altering either of the two source matrixes,
             * first copy the source matrix by using the clone() method, as shown in the Class Examples section.
             * @param   m   The matrix to be concatenated to the source matrix.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates three Matricies that define transformations for
             *   three rectangle MovieClips.  The first two Matricies <code>rotate45Matrix</code>
             *   and <code>doubleScaleMatrix</code> are applied to the two rectangles
             *   <code>rectangleMc_1</code> and <code>rectangleMc_2</code>.  Then, the third
             *   Matrix is created using the <code>concat()</code> method on <code>rotate45Matrix</code> and
             *   <code>doubleScaleMatrix</code> to create <code>scaleAndRotateMatrix</code>.
             *   This Matrix is then applied to <code>rectangleMc_3</code> to scale and rotate it.
             *
             *     <listing version="2.0">
             *   import flash.geom.Matrix;
             *   import flash.geom.Transform;
             *
             *     var rectangleMc_0:MovieClip = createRectangle(20, 80, 0x000000);
             *   var rectangleMc_1:MovieClip = createRectangle(20, 80, 0xFF0000);
             *   var rectangleMc_2:MovieClip = createRectangle(20, 80, 0x00FF00);
             *   var rectangleMc_3:MovieClip = createRectangle(20, 80, 0x0000FF);
             *
             *     var rectangleTrans_1:Transform = new Transform(rectangleMc_1);
             *   var rectangleTrans_2:Transform = new Transform(rectangleMc_2);
             *   var rectangleTrans_3:Transform = new Transform(rectangleMc_3);
             *
             *     var rotate45Matrix:Matrix = new Matrix();
             *   rotate45Matrix.rotate(Math.PI/4);
             *   rectangleTrans_1.matrix = rotate45Matrix;
             *   rectangleMc_1._x = 100;
             *   trace(rotate45Matrix.toString());    // (a=0.707106781186548, b=0.707106781186547, c=-0.707106781186547, d=0.707106781186548, tx=0, ty=0)
             *
             *     var doubleScaleMatrix:Matrix = new Matrix();
             *   doubleScaleMatrix.scale(2, 2);
             *   rectangleTrans_2.matrix = doubleScaleMatrix;
             *   rectangleMc_2._x = 200;
             *   trace(doubleScaleMatrix.toString());  // (a=2, b=0, c=0, d=2, tx=0, ty=0)
             *
             *     var scaleAndRotateMatrix:Matrix = doubleScaleMatrix.clone();
             *   scaleAndRotateMatrix.concat(rotate45Matrix);
             *   rectangleTrans_3.matrix = scaleAndRotateMatrix;
             *   rectangleMc_3._x = 300;
             *   trace(scaleAndRotateMatrix.toString());   // (a=1.4142135623731, b=1.41421356237309, c=-1.41421356237309, d=1.4142135623731, tx=0, ty=0)
             *
             *     function createRectangle(width:Number, height:Number, color:Number):MovieClip {
             *   var depth:Number = this.getNextHighestDepth();
             *   var mc:MovieClip = this.createEmptyMovieClip("mc_" + depth, depth);
             *   mc.beginFill(color);
             *   mc.lineTo(0, height);
             *   mc.lineTo(width, height);
             *   mc.lineTo(width, 0);
             *   mc.lineTo(0, 0);
             *   return mc;
             *   }
             *
             *     </listing>
             */
        public:
            void     concat(Matrix *m);

            /**
             * Performs the opposite transformation
             * of the original matrix. You can apply an inverted matrix to an object to undo the transformation
             * performed when applying the original matrix.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     invert();

            /**
             * Sets each matrix property to a value that causes a null transformation. An object transformed
             * by applying an identity matrix will be identical to the original.
             *
             *   After calling the identity() method, the resulting matrix has the following properties:
             * a=1, b=0, c=0, d=1, tx=0, ty=0.In matrix notation, the identity matrix looks like this:
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @category    Method
             */
        public:
            void     identity();

            /**
             * Includes parameters for scaling,
             * rotation, and translation. When applied to a matrix it sets the matrix's values
             * based on those parameters.
             *
             *   Using the createBox() method lets you obtain the same matrix as you would if
             * you applied the identity(), rotate(), scale(), and translate() methods
             * in succession. For example, mat1.createBox(2,2,Math.PI/4, 100, 100) has the
             * same effect as the following:
             * <codeblock>
             *
             *   import flash.geom.Matrix;
             *
             *   var mat1:Matrix = new Matrix();
             * mat1.identity();
             * mat1.rotate(Math.PI/4);
             * mat1.scale(2,2);
             * mat1.translate(10,20);
             *
             *   </codeblock>
             * @param   scaleX  The factor by which to scale horizontally.
             * @param   scaleY  The factor by which scale vertically.
             * @param   rotation    The amount to rotate, in radians.
             * @param   tx  The number of pixels to translate (move) to the right along the x axis.
             * @param   ty  The number of pixels to translate (move) down along the y axis.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     createBox(float scaleX, float scaleY, float rotation =0, float tx =0, float ty =0);

            /**
             * Creates the specific style of matrix expected by the beginGradientFill() and
             * lineGradientStyle() methods of the Graphics class. Width and height are scaled to
             * a scaleX/scaleY pair and the tx/ty
             * values are offset by half the width and height.
             *
             *   For example, consider a gradient with the following characteristics:GradientType.LINEARTwo colors, green and blue, with the ratios array set to [0, 255]SpreadMethod.PADInterpolationMethod.LINEAR_RGBThe following illustrations show gradients in which the matrix was defined using the
             * createGradientBox() method with different parameter settings:createGradientBox() settingsResulting gradientwidth = 25;
             * height = 25;
             * rotation = 0;
             * tx = 0;
             * ty = 0;width = 25;
             * height = 25;
             * rotation = 0;
             * tx = 25;
             * ty = 0;width = 50;
             * height = 50;
             * rotation = 0;
             * tx = 0;
             * ty = 0;width = 50;
             * height = 50;
             * rotation = Math.PI / 4; // 45 degrees
             * tx = 0;
             * ty = 0;
             * @param   width   The width of the gradient box.
             * @param   height  The height of the gradient box.
             * @param   rotation    The amount to rotate, in radians.
             * @param   tx  The distance, in pixels, to translate to the right along the x axis.
             *   This value is offset by half of the width parameter.
             * @param   ty  The distance, in pixels, to translate down along the y axis.
             *
             *     This value is offset by half of the height parameter.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @category    Method
             */
        public:
            void     createGradientBox(float width, float height, float rotation =0, float tx =0, float ty =0);

            /**
             * Applies a rotation transformation to the Matrix object.
             *
             *   The rotate() method alters the a, b, c,
             * and d properties of the Matrix object.
             * In matrix notation, this is the same as concatenating the current matrix with the following:
             * @param   angle   The rotation angle in radians.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example the <code>rotate()</code> method rotates <code>rectangleMc</code>
             *   30 degrees clockwise.  Notice that applying <code>myMatrix</code> to <code>rectangleMc</code>
             *   resets its <i class="+ topic/ph hi-d/i ">_x</i> value leaving us to reset it to 100 manually.
             *
             *     <listing version="2.0">
             *   import flash.geom.Matrix;
             *   import flash.geom.Transform;
             *
             *     var myMatrix:Matrix = new Matrix();
             *   trace(myMatrix.toString());           // (a=1, b=0, c=0, d=1, tx=0, ty=0)
             *
             *     var degrees:Number = 30;
             *   var radians:Number = (degrees/180) ~~ Math.PI;
             *   myMatrix.rotate(radians);
             *   trace(myMatrix.toString());           // (a=0.866025403784439, b=0.5, c=-0.5, d=0.866025403784439, tx=0, ty=0)
             *
             *     var rectangleMc:MovieClip = createRectangle(20, 80, 0xFF0000);
             *   trace(rectangleMc._x);                // 0
             *   rectangleMc._x = 100;
             *   trace(rectangleMc._x);                // 100
             *
             *     var rectangleTrans:Transform = new Transform(rectangleMc);
             *   rectangleTrans.matrix = myMatrix;
             *   trace(rectangleMc._x);                // 0
             *   rectangleMc._x = 100;
             *   trace(rectangleMc._x);                // 100
             *
             *     function createRectangle(width:Number, height:Number, color:Number):MovieClip {
             *   var depth:Number = this.getNextHighestDepth();
             *   var mc:MovieClip = this.createEmptyMovieClip("mc_" + depth, depth);
             *   mc.beginFill(color);
             *   mc.lineTo(0, height);
             *   mc.lineTo(width, height);
             *   mc.lineTo(width, 0);
             *   mc.lineTo(0, 0);
             *   return mc;
             *   }
             *   </listing>
             *   The above example uses the <code>_x</code> property of the MovieClip object
             *   to position <code>rectangleMc</code>.  Generally, when dealing with Matrix
             *   positioning, mixing positioning techniques is considered bad style.  The
             *   example above written in good style would concatenate a translation Matrix to
             *   <code>myMatrix</code> to change the horizontal location of <code>rectangleMc</code>.
             *   The following example demonstrates this.
             *   <listing version="2.0">
             *   import flash.geom.Matrix;
             *   import flash.geom.Transform;
             *
             *     var myMatrix:Matrix = new Matrix();
             *   trace(myMatrix.toString());   // (a=1, b=0, c=0, d=1, tx=0, ty=0)
             *
             *     var degrees:Number = 30;
             *   var radians:Number = (degrees/180) ~~ Math.PI;
             *   myMatrix.rotate(radians);
             *   trace(myMatrix.toString());   // (a=0.866025403784439, b=0.5, c=-0.5, d=0.866025403784439, tx=0, ty=0)
             *
             *     var translateMatrix:Matrix = new Matrix();
             *   translateMatrix.translate(100, 0);
             *   myMatrix.concat(translateMatrix);
             *   trace(myMatrix.toString());   // (a=0.866025403784439, b=0.5, c=-0.5, d=0.866025403784439, tx=100, ty=0)
             *
             *     var rectangleMc:MovieClip = createRectangle(20, 80, 0xFF0000);
             *   trace(rectangleMc._x);        // 0
             *   rectangleMc._x = 100;
             *   trace(rectangleMc._x);        // 100
             *
             *     var rectangleTrans:Transform = new Transform(rectangleMc);
             *   rectangleTrans.matrix = myMatrix;
             *   trace(rectangleMc._x);        // 100
             *
             *     function createRectangle(width:Number, height:Number, color:Number):MovieClip {
             *   var depth:Number = this.getNextHighestDepth();
             *   var mc:MovieClip = this.createEmptyMovieClip("mc_" + depth, depth);
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
            void     rotate(float angle);

            /**
             * Translates the matrix along the x and y axes, as specified by the dx
             * and dy parameters.
             * @param   dx  The amount of movement along the x axis to the right, in pixels.
             * @param   dy  The amount of movement down along the y axis, in pixels.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example uses the <code>translate()</code> method to position
             *   <code>rectangleMc</code> x:100 and y:50. Notice that <code>translate()</code> affects
             *   the translate values <code>tx</code> and <code>ty</code> but not <code>a</code>, <code>b</code>,
             *   <code>c</code>, or <code>d</code>.
             *
             *     <listing version="2.0">
             *   import flash.geom.Matrix;
             *
             *     var myMatrix:Matrix = new Matrix(2, 0, 0, 2, 100, 100);
             *   trace(myMatrix.toString());   // (a=2, b=0, c=0, d=2, tx=100, ty=100)
             *
             *     myMatrix.translate(100, 50);
             *   trace(myMatrix.toString());   // (a=2, b=0, c=0, d=2, tx=200, ty=150)
             *   </listing>
             */
        public:
            void     translate(float dx, float dy);

            /**
             * Applies a scaling transformation to the matrix. The x axis is multiplied
             * by sx, and the y axis it is multiplied by sy.
             *
             *   The scale() method alters the a and d properties of
             * the Matrix object.
             * In matrix notation, this is the same as concatenating the current matrix with the following matrix:
             * @param   sx  A multiplier used to scale the object along the x axis.
             * @param   sy  A multiplier used to scale the object along the y axis.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example uses the <code>scale()</code> method to
             *   scale <code>myMatrix</code> by a factor of 3 horizontally and a factor of 4
             *   vertically.
             *
             *     <listing version="2.0">
             *   import flash.geom.Matrix;
             *
             *     var myMatrix:Matrix = new Matrix(2, 0, 0, 2, 100, 100);
             *   trace(myMatrix.toString());   // (a=2, b=0, c=0, d=2, tx=100, ty=100)
             *
             *     myMatrix.scale(3, 4);
             *   trace(myMatrix.toString());   // (a=6, b=0, c=0, d=8, tx=300, ty=400)
             *   </listing>
             */
        public:
            void     scale(float sx, float sy);

            /**
             * Given a point in the pretransform coordinate space, returns the coordinates of
             * that point after the transformation occurs. Unlike the standard transformation applied using
             * the transformPoint() method, the deltaTransformPoint() method's
             * transformation does not consider the translation parameters tx and ty.
             * @param   point   The point for which you want to get the result of the matrix transformation.
             * @return  The point resulting from applying the matrix transformation.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example uses the <code>deltaTransformPoint()</code> method
             *   to create <code>deltaTransformedPoint</code> from <code>myPoint</code>.  Notice that
             *   the <code>translate()</code> method has no affect on the position of <code>deltaTransformedPoint</code>.
             *   In the example, however, <code>scale()</code> does affect the position.  It
             *   increases the original <code>x</code> value by a factor of three from 50 to 150.
             *
             *     <listing version="2.0">
             *   import flash.geom.Matrix;
             *   import flash.geom.Point;
             *
             *     var myMatrix:Matrix = new Matrix();
             *   trace(myMatrix);  // (a=1, b=0, c=0, d=1, tx=0, ty=0)
             *
             *     myMatrix.translate(100, 0);
             *   trace(myMatrix);  // (a=1, b=0, c=0, d=1, tx=100, ty=0)
             *
             *     myMatrix.scale(3, 3);
             *   trace(myMatrix);  // (a=3, b=0, c=0, d=3, tx=300, ty=0)
             *
             *     var myPoint:Point = new Point(50,0);
             *   trace(myPoint);   // (50, 0)
             *
             *     var deltaTransformedPoint:Point = myMatrix.deltaTransformPoint(myPoint);
             *   trace(deltaTransformedPoint); // (150, 0)
             *
             *     var pointMc_0:MovieClip = createRectangle(10, 10, 0xFF0000);
             *   pointMc_0._x = myPoint.x;
             *
             *     var pointMc_1:MovieClip = createRectangle(10, 10, 0x00FF00);
             *   pointMc_1._x = deltaTransformedPoint.x;
             *
             *     function createRectangle(width:Number, height:Number, color:Number):MovieClip {
             *   var depth:Number = this.getNextHighestDepth();
             *   var mc:MovieClip = this.createEmptyMovieClip("mc_" + depth, depth);
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
            flash::geom::Point *deltaTransformPoint(Point *point);

            /**
             * Returns the result of applying the geometric transformation represented by the Matrix object to the
             * specified point.
             * @param   point   The point for which you want to get the result of the Matrix transformation.
             * @return  The point resulting from applying the Matrix transformation.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example uses the <code>transformPoint()</code> method
             *   to create <code>transformedPoint</code> from <code>myPoint</code>.  Notice that
             *   the <code>translate()</code> method does have an affect on the position of <code>transformedPoint</code>.
             *   In the example, <code>scale()</code> increases the original <code>x</code>
             *   value by a factor of three from 50 to 150, and <code>translate()</code> increases
             *   <code>x</code> by 300 for a total value of 450.
             *
             *     <listing version="2.0">
             *   import flash.geom.Matrix;
             *   import flash.geom.Point;
             *
             *     var myMatrix:Matrix = new Matrix();
             *   trace(myMatrix);  // (a=1, b=0, c=0, d=1, tx=0, ty=0)
             *
             *     myMatrix.translate(100, 0);
             *   trace(myMatrix);  // (a=1, b=0, c=0, d=1, tx=100, ty=0)
             *
             *     myMatrix.scale(3, 3);
             *   trace(myMatrix);  // (a=3, b=0, c=0, d=3, tx=300, ty=0)
             *
             *     var myPoint:Point = new Point(50,0);
             *   trace(myPoint);                   // (50, 0)
             *
             *     var transformedPoint:Point = myMatrix.transformPoint(myPoint);
             *   trace(transformedPoint);  // (450, 0)
             *
             *     var pointMc_0:MovieClip = createRectangle(10, 10, 0xFF0000);
             *   pointMc_0._x = myPoint.x;
             *
             *     var pointMc_1:MovieClip = createRectangle(10, 10, 0x00FF00);
             *   pointMc_1._x = transformedPoint.x;
             *
             *     function createRectangle(width:Number, height:Number, color:Number):MovieClip {
             *   var depth:Number = this.getNextHighestDepth();
             *   var mc:MovieClip = this.createEmptyMovieClip("mc_" + depth, depth);
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
            flash::geom::Point *transformPoint(Point *point);

            /**
             * Returns a text value listing the properties of the Matrix object.
             * @return  A string containing the values of the properties of the Matrix object: a, b, c,
             *   d, tx, and ty.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @maelexample The following example creates <code>myMatrix</code> and converts its values
             *   to a String in the format of (a=A, b=B, c=C, d=D, tx=TX, ty=TY).
             *
             *     <listing version="2.0">
             *   import flash.geom.Matrix;
             *
             *     var myMatrix:Matrix = new Matrix();
             *   trace("myMatrix: " + myMatrix.toString()); // (a=1, b=0, c=0, d=1, tx=0, ty=0)
             *   </listing>
             */
        public:
            std::string toString();

        public:
            void     copyFrom(Matrix *sourceMatrix);

        public:
            void     setTo(float aa, float ba, float ca, float da, float txa, float tya);

        public:
            void     copyRowTo(unsigned int row, Vector3D *vector3D);

        public:
            void     copyColumnTo(unsigned int column, Vector3D *vector3D);

        public:
            void     copyRowFrom(unsigned int row, Vector3D *vector3D);

        public:
            void     copyColumnFrom(unsigned int column, Vector3D *vector3D);
        };
    }
}

#endif // FLEX11_6_FLASH_GEOM_MATRIX_AS
#endif // __cplusplus

