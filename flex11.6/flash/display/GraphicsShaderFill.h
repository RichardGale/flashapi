#if !defined(FLEX11_6_FLASH_DISPLAY_GRAPHICSSHADERFILL_AS)
#define FLEX11_6_FLASH_DISPLAY_GRAPHICSSHADERFILL_AS
#if defined(__cplusplus)


#include "IGraphicsFill.h"
#include "IGraphicsData.h"
namespace flash
{
    namespace display
    {
        class Shader;
    }
}
namespace flash
{
    namespace geom
    {
        class Matrix;
    }
}

/**
 * Defines a shader fill.
 *
 *   <p class="- topic/p ">
 * Use a GraphicsShaderFill object with the <codeph class="+ topic/ph pr-d/codeph ">Graphics.drawGraphicsData()</codeph> method.
 * Drawing a GraphicsShaderFill object is the equivalent of calling the <codeph class="+ topic/ph pr-d/codeph ">Graphics.beginShaderFill()</codeph> method.
 * </p>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */
using namespace ;
using namespace ;
using namespace flash::display;
using namespace flash::geom;

namespace flash
{
    namespace display
    {
        class GraphicsShaderFill: public Object, public IGraphicsFill,, public IGraphicsData
        {
            /**
             * The shader to use for the fill. This Shader instance is not required to
             * specify an image input. However, if an image input is specified in the shader, the input
             * must be provided manually by setting the input property of the corresponding ShaderInput
             * property of the Shader.data property.
             *
             *   When you pass a Shader instance as an argument the shader is copied internally and the
             * drawing fill operation uses that internal copy, not a reference to the original shader. Any changes
             * made to the shader, such as changing a parameter value, input, or bytecode, are not applied
             * to the copied shader that's used for the fill.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            flash::display::Shader *shader;

            /**
             * A matrix object (of the flash.geom.Matrix class), which you can use to
             * define transformations on the shader. For example, you can use the following matrix
             * to rotate a shader by 45 degrees (pi/4 radians):
             *
             *   <codeblock>
             *
             *   matrix = new flash.geom.Matrix();
             * matrix.rotate(Math.PI / 4);
             *
             *   </codeblock>
             * The coordinates received in the shader are based on the matrix that is specified
             * for the matrix parameter. For a default (null) matrix, the
             * coordinates in the shader are local pixel coordinates which can be used to sample an
             * input.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            flash::geom::Matrix *matrix;

            /**
             * Creates a new GraphicsShaderFill object.
             * @param   shader  The shader to use for the fill. This Shader instance is not required to
             *   specify an image input. However, if an image input is specified in the shader, the input
             *   must be provided manually by setting the input property of the corresponding ShaderInput
             *   property of the Shader.data property.
             * @param   matrix  A matrix object (of the flash.geom.Matrix class), which you can use to
             *   define transformations on the shader.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            GraphicsShaderFill(Shader *shader, Matrix *matrix);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_GRAPHICSSHADERFILL_AS
#endif // __cplusplus

