

#include "GraphicsGradientFill.h"
#include "IGraphicsFill.h"
#include "IGraphicsData.h"
#include "flash/geom/Matrix.h"

    /**
     * Defines a gradient fill.
     * 
     *   <p class="- topic/p ">
     * Use a GraphicsGradientFill object with the <codeph class="+ topic/ph pr-d/codeph ">Graphics.drawGraphicsData()</codeph> method.
     * Drawing a GraphicsGradientFill object is the equivalent of calling the <codeph class="+ topic/ph pr-d/codeph ">Graphics.beginGradientFill()</codeph> method.
     * </p>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     */

using namespace flash::geom;

namespace flash {
namespace display {


        /**
         * An array of RGB hexadecimal color values to use in the gradient. For example,
         * red is 0xFF0000, blue is 0x0000FF, and so on. You can specify up to 15 colors. 
         * For each color, specify a corresponding value in the alphas and ratios properties.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
                   

        /**
         * An array of alpha values for the corresponding colors in the colors array. 
         * Valid values are between 0 and 1. If the value is less than 0, 0 is used. If the value is 
         * greater than 1, 1 is used.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
                   

        /**
         * An array of color distribution ratios. Valid values are between 0 and 255. This value 
         * defines the percentage of the width where the color is sampled at 100%. The value 0 represents 
         * the left position in the gradient box, and the value 255 represents the right position in the 
         * gradient box.
         * 
         *   Note: This value represents positions in the gradient box, not the 
         * coordinate space of the final gradient which can be wider or thinner than the gradient box. 
         * Specify a value for corresponding to each value in the colors property. For example, for a linear gradient that includes two colors (blue and green) the 
         * following example illustrates the placement of the colors in the gradient based on different values
         * in the ratios array:ratiosGradient[0, 127][0, 255][127, 255]The values in the array must increase sequentially; for example, 
         * [0, 63, 127, 190, 255].
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
                   

        /**
         * A transformation matrix as defined by the 
         * Matrix class. The flash.geom.Matrix class includes a 
         * createGradientBox() method to set up 
         * the matrix for use with the beginGradientFill() method.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
                   

        /**
         * A number that controls the 
         * location of the focal point of the gradient. A value of 0 sets the focal point in the center. A value of 1 
         * means that the focal point is at one border of the gradient circle.A value of -1 sets the focal point 
         * at the other border of the gradient circle. A value of less than -1 or greater than
         * 1 is rounded to -1 or 1, respectively. For example, the following 
         * shows a focalPointRatio set to 0.75:
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
                   

        /**
         * A value from the GradientType class that 
         * specifies which gradient type to use. Values are GradientType.LINEAR or 
         * GradientType.RADIAL.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::string GraphicsGradientFill::type()         ;
        void GraphicsGradientFill::type(std::string value)       ;

        /**
         * A value from the SpreadMethod class that 
         * specifies which spread method to use. Valid values are: SpreadMethod.PAD,
         * SpreadMethod.REFLECT, or SpreadMethod.REPEAT.
         * 
         *   For example, the following shows a simple linear gradient between two colors:
         * <codeblock>
         * 
         *   import flash.geom.*
         * import flash.display.*
         * var fillType:String = GradientType.LINEAR;
         * var colors:Array = [0xFF0000, 0x0000FF];
         * var alphas:Array = [1, 1];
         * var ratios:Array = [0x00, 0xFF];
         * var matr:Matrix = new Matrix();
         * matr.createGradientBox(20, 20, 0, 0, 0);
         * var spreadMethod:String = SpreadMethod.PAD;
         * this.graphics.beginGradientFill(fillType, colors, alphas, ratios, matr, spreadMethod);       
         * this.graphics.drawRect(0,0,100,100);
         * 
         *   </codeblock>
         * This example uses SpreadMethod.PAD for the spread method, and 
         * the gradient fill looks like the following:If you use SpreadMethod.REFLECT for the spread method, the gradient fill  
         * looks like the following:If you use SpreadMethod.REPEAT for the spread method, the gradient fill  
         * looks like the following:
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::string GraphicsGradientFill::spreadMethod()         ;
        void GraphicsGradientFill::spreadMethod(std::string value)       ;

        /**
         * A value from the InterpolationMethod class that 
         * specifies which value to use. Valid values are: InterpolationMethod.LINEAR_RGB or 
         * InterpolationMethod.RGBFor example, the following shows a simple linear gradient between two colors (with the spreadMethod 
         * parameter set to SpreadMethod.REFLECT). The different interpolation methods change 
         * the appearance as follows: InterpolationMethod.LINEAR_RGBInterpolationMethod.RGB
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::string GraphicsGradientFill::interpolationMethod()         ;
        void GraphicsGradientFill::interpolationMethod(std::string value)       ;

        /**
         * Creates a new GraphicsGradientFill object.
         * @param   type    A value from the GradientType class that 
         *   specifies which gradient type to use: GradientType.LINEAR or 
         *   GradientType.RADIAL.
         * @param   colors  An array of RGB hexadecimal color values used in the gradient; for example,
         *   red is 0xFF0000, blue is 0x0000FF, and so on. You can specify up to 15 colors. 
         *   For each color, specify a corresponding value in the alphas and ratios parameters.
         * @param   alphas  An array of alpha values for the corresponding colors in the colors array; 
         *   valid values are 0 to 1. If the value is less than 0, 0 is used. If the value is 
         *   greater than 1, 1 is used.
         * @param   ratios  An array of color distribution ratios; valid values are 0-255. This value 
         *   defines the percentage of the width where the color is sampled at 100%. The value 0 represents 
         *   the left position in the gradient box, and 255 represents the right position in the 
         *   gradient box.
         * @param   matrix  A transformation matrix as defined by the 
         *   flash.geom.Matrix class. The flash.geom.Matrix class includes a 
         *   createGradientBox() method, which lets you conveniently set up 
         *   the matrix for use with the beginGradientFill() method.
         * @param   spreadMethod    A value from the SpreadMethod class that 
         *   specifies which spread method to use, either: SpreadMethod.PAD,
         *   SpreadMethod.REFLECT, or SpreadMethod.REPEAT.
         * @param   interpolationMethod A value from the InterpolationMethod class that 
         *   specifies which value to use: InterpolationMethod.LINEAR_RGB or 
         *   InterpolationMethod.RGB
         * @param   focalPointRatio A number that controls the 
         *   location of the focal point of the gradient. A value of 0 sets the focal point in the center. A value of 1 
         *   sets the focal point at one border of the gradient circle. A value of -1 sets the focal point 
         *   at the other border of the gradient circle. A value less than -1 or greater than
         *   1 is rounded to -1 or 1, respectively.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        GraphicsGradientFill::GraphicsGradientFill(std::string type, std::vector<void*> colors, std::vector<void*> alphas, std::vector<void*> ratios, void* matrix, void* spreadMethod, std::string interpolationMethod, float focalPointRatio);
}
}

