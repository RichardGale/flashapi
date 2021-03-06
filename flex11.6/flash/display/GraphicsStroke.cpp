

#include "GraphicsStroke.h"
#include "IGraphicsStroke.h"
#include "IGraphicsData.h"
#include "flash/display/IGraphicsFill.h"

    /**
     * Defines a line style or stroke.
     * 
     *   <p class="- topic/p ">
     * Use a GraphicsStroke object with the <codeph class="+ topic/ph pr-d/codeph ">Graphics.drawGraphicsData()</codeph> method.
     * Drawing a GraphicsStroke object is the equivalent of calling one of the methods of the Graphics
     * class that sets the line style, such as the <codeph class="+ topic/ph pr-d/codeph ">Graphics.lineStyle()</codeph> method, the 
     * <codeph class="+ topic/ph pr-d/codeph ">Graphics.lineBitmapStyle()</codeph> method, or the <codeph class="+ topic/ph pr-d/codeph ">Graphics.lineGradientStyle()</codeph> 
     * method.
     * </p>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     */

using namespace flash::display;

namespace flash {
namespace display {


        /**
         * Indicates the thickness of the line in 
         * points; valid values are 0-255. If a number is not specified, or if the 
         * parameter is undefined, a line is not drawn. If a value of less than 0 is passed, 
         * the default is 0. The value 0 indicates hairline thickness; the maximum thickness 
         * is 255. If a value greater than 255 is passed, the default is 255.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
                   

        /**
         * Specifies whether to hint strokes 
         * to full pixels. This affects both the position of anchors of a curve and the line stroke size 
         * itself. With pixelHinting set to true, Flash Player hints line widths  
         * to full pixel widths. With pixelHinting set to false, disjoints can 
         * appear for curves and straight lines. For example, the following illustrations show how 
         * Flash Player renders two rounded rectangles that are identical, except that the 
         * pixelHinting parameter used in the lineStyle() method is set 
         * differently (the images are scaled by 200%, to emphasize the difference):
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
                   

        /**
         * Indicates the limit at which a miter is cut off. 
         * Valid values range from 1 to 255 (and values outside that range are rounded to 1 or 255). 
         * This value is only used if the jointStyle 
         * is set to "miter". The 
         * miterLimit value represents the length that a miter can extend beyond the point
         * at which the lines meet to form a joint. The value expresses a factor of the line
         * thickness. For example, with a miterLimit factor of 2.5 and a 
         * thickness of 10 pixels, the miter is cut off at 25 pixels.
         * 
         *   For example, consider the following angled lines, each drawn with a thickness 
         * of 20, but with miterLimit set to 1, 2, and 4. Superimposed are black reference
         * lines showing the meeting points of the joints:Notice that a given miterLimit value has a specific maximum angle 
         * for which the miter is cut off. The following table lists some examples:miterLimit value:Angles smaller than this are cut off:1.41490 degrees260 degrees430 degrees815 degrees
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
                   

        /**
         * Specifies the instance containing data for filling a stroke. An IGraphicsFill
         * instance can represent a series of fill commands.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
                   

        /**
         * Specifies the type of caps at the end 
         * of lines. Valid values are: CapsStyle.NONE, CapsStyle.ROUND, and CapsStyle.SQUARE. 
         * If a value is not indicated, Flash uses round caps. 
         * For example, the following illustrations show the different capsStyle 
         * settings. For each setting, the illustration shows a blue line with a thickness of 30 (for 
         * which the capsStyle applies), and a superimposed black line with a thickness of 1 
         * (for which no capsStyle applies):
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::string GraphicsStroke::caps()         ;
        void GraphicsStroke::caps(std::string value)       ;

        /**
         * Specifies the type of joint appearance
         * used at angles. Valid 
         * values are: JointStyle.BEVEL, JointStyle.MITER, and JointStyle.ROUND.
         * If a value is not indicated, Flash uses round joints.
         * 
         *   For example, the following illustrations show the different joints 
         * settings. For each setting, the illustration shows an angled blue line with a thickness of 
         * 30 (for which the jointStyle applies), and a superimposed angled black line with a 
         * thickness of 1 (for which no jointStyle applies):
         * Note: For joints set to JointStyle.MITER, 
         * you can use the miterLimit parameter to limit the length of the miter.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::string GraphicsStroke::joints()         ;
        void GraphicsStroke::joints(std::string value)       ;

        /**
         * Specifies the stroke thickness scaling. Valid values are:
         * 
         *   LineScaleMode.NORMAL   Always scale the line thickness when the object is scaled 
         * (the default).
         * LineScaleMode.NONE   Never scale the line thickness.
         * LineScaleMode.VERTICAL   Do not scale the line thickness if the object is scaled vertically 
         * only. For example, consider the following circles, drawn with a one-pixel line, and each with the 
         * scaleMode parameter set to LineScaleMode.VERTICAL. The circle on the left 
         * is scaled vertically only, and the circle on the right is scaled both vertically and horizontally:
         * 
         *   LineScaleMode.HORIZONTAL   Do not scale the line thickness if the object is scaled horizontally 
         * only. For example, consider the following circles, drawn with a one-pixel line, and each with the 
         * scaleMode parameter set to LineScaleMode.HORIZONTAL. The circle on the left 
         * is scaled horizontally only, and the circle on the right is scaled both vertically and horizontally:
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::string GraphicsStroke::scaleMode()         ;
        void GraphicsStroke::scaleMode(std::string value)       ;

        /**
         * Creates a new GraphicsStroke object.
         * @param   thickness   An integer that indicates the thickness of the line in 
         *   points; valid values are 0-255. If a number is not specified, or if the 
         *   parameter is undefined, a line is not drawn. If a value of less than 0 is passed, 
         *   the default is 0. The value 0 indicates hairline thickness; the maximum thickness 
         *   is 255. If a value greater than 255 is passed, the default is 255.
         * @param   pixelHinting    A Boolean value that specifies whether to hint strokes 
         *   to full pixels. This affects both the position of anchors of a curve and the line stroke size 
         *   itself. With pixelHinting set to true, Flash Player hints line widths  
         *   to full pixel widths. With pixelHinting set to false, disjoints can 
         *   appear for curves and straight lines. For example, the following illustrations show how 
         *   Flash Player renders two rounded rectangles that are identical, except that the 
         *   pixelHinting parameter used in the lineStyle() method is set 
         *   differently (the images are scaled by 200%, to emphasize the difference):
         *   
         *     If a value is not supplied, the line does not use pixel hinting.
         * @param   scaleMode   A value from the LineScaleMode class that 
         *   specifies which scale mode to use:
         *   
         *     LineScaleMode.NORMAL   Always scale the line thickness when the object is scaled 
         *   (the default).
         *   LineScaleMode.NONE   Never scale the line thickness.
         *   LineScaleMode.VERTICAL   Do not scale the line thickness if the object is scaled vertically 
         *   only. For example, consider the following circles, drawn with a one-pixel line, and each with the 
         *   scaleMode parameter set to LineScaleMode.VERTICAL. The circle on the left 
         *   is scaled vertically only, and the circle on the right is scaled both vertically and horizontally:
         *   
         *     LineScaleMode.HORIZONTAL   Do not scale the line thickness if the object is scaled horizontally 
         *   only. For example, consider the following circles, drawn with a one-pixel line, and each with the 
         *   scaleMode parameter set to LineScaleMode.HORIZONTAL. The circle on the left 
         *   is scaled horizontally only, and the circle on the right is scaled both vertically and horizontally:
         * @param   caps    A value from the CapsStyle class that specifies the type of caps at the end 
         *   of lines. Valid values are: CapsStyle.NONE, CapsStyle.ROUND, and CapsStyle.SQUARE. 
         *   If a value is not indicated, Flash uses round caps. 
         *   For example, the following illustrations show the different capsStyle 
         *   settings. For each setting, the illustration shows a blue line with a thickness of 30 (for 
         *   which the capsStyle applies), and a superimposed black line with a thickness of 1 
         *   (for which no capsStyle applies):
         * @param   joints  A value from the JointStyle class that specifies the type of joint appearance
         *   used at angles. Valid 
         *   values are: JointStyle.BEVEL, JointStyle.MITER, and JointStyle.ROUND.
         *   If a value is not indicated, Flash uses round joints.
         *   
         *     For example, the following illustrations show the different joints 
         *   settings. For each setting, the illustration shows an angled blue line with a thickness of 
         *   30 (for which the jointStyle applies), and a superimposed angled black line with a 
         *   thickness of 1 (for which no jointStyle applies):
         *   Note: For joints set to JointStyle.MITER, 
         *   you can use the miterLimit parameter to limit the length of the miter.
         * @param   miterLimit  A number that indicates the limit at which a miter is cut off. 
         *   Valid values range from 1 to 255 (and values outside that range are rounded to 1 or 255). 
         *   This value is only used if the jointStyle 
         *   is set to "miter". The 
         *   miterLimit value represents the length that a miter can extend beyond the point
         *   at which the lines meet to form a joint. The value expresses a factor of the line
         *   thickness. For example, with a miterLimit factor of 2.5 and a 
         *   thickness of 10 pixels, the miter is cut off at 25 pixels.
         *   
         *     For example, consider the following angled lines, each drawn with a thickness 
         *   of 20, but with miterLimit set to 1, 2, and 4. Superimposed are black reference
         *   lines showing the meeting points of the joints:Notice that a given miterLimit value has a specific maximum angle 
         *   for which the miter is cut off. The following table lists some examples:miterLimit value:Angles smaller than this are cut off:1.41490 degrees260 degrees430 degrees815 degrees
         * @param   fill    An IGraphicsFill instance containing data for filling a stroke. An IGraphicsFill
         *   instance can represent a series of fill commands.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        GraphicsStroke::GraphicsStroke(float thickness, bool pixelHinting, std::string scaleMode, std::string caps, std::string joints, float miterLimit, IGraphicsFill* fill);
}
}

