#if !defined(FLEX11_6_FLASH_DISPLAY_SHADERINPUT_AS)
#define FLEX11_6_FLASH_DISPLAY_SHADERINPUT_AS
#if defined(__cplusplus)


/**
 * A ShaderInput instance represents a single input image for
 * a shader kernel. A kernel can be defined to accept zero, one, or more
 * source images that are used in the kernel execution. A ShaderInput
 * instance provides a mechanism for specifying the input image
 * that is used when the shader executes. To specify a value for the input,
 * create a BitmapData, ByteArray, or Vector.&lt;Number&gt; instance containing the image data
 * and assign it to the <codeph class="+ topic/ph pr-d/codeph ">input</codeph> property.
 *
 *   <p class="- topic/p ">The ShaderInput instance representing a Shader instance's input image
 * is accessed as a property of the Shader instance's
 * <codeph class="+ topic/ph pr-d/codeph ">data</codeph> property. The ShaderInput property has the same name
 * as the input's name in the shader code.
 * For example, if a shader defines an input named <codeph class="+ topic/ph pr-d/codeph ">src</codeph>,
 * the ShaderInput instance representing the <codeph class="+ topic/ph pr-d/codeph ">src</codeph> input
 * is available as the <codeph class="+ topic/ph pr-d/codeph ">src</codeph> property, as this example shows:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">myShader.data.src.image = new BitmapData(50, 50, true, 0xFF990000);</codeblock><p class="- topic/p ">For some uses of a Shader instance, you do not
 * need to specify an input image, because it is automatically specified by the
 * operation. You only need to specify an input when a Shader is used for the following:</p><ul class="- topic/ul "><li class="- topic/li ">Shader fill</li><li class="- topic/li ">ShaderFilter, only for the second or additional inputs
 * if the shader is defined to use more than one input. (The object to which the
 * filter is applied is automatically used as the first input.)</li><li class="- topic/li ">Shader blend mode, only for the third or additional inputs if the shader is
 * defined to use more than two inputs. (The objects being blended
 * are automatically used as the first and second inputs.)</li><li class="- topic/li ">ShaderJob background execution</li></ul><p class="- topic/p ">If the shader is being executed using a ShaderJob instance to process a
 * ByteArray containing a linear array of data, set the ShaderInput instance's
 * <codeph class="+ topic/ph pr-d/codeph ">height</codeph> to 1 and <codeph class="+ topic/ph pr-d/codeph ">width</codeph> to the number of 32-bit floating
 * point values in the ByteArray. In that case, the input in the shader must be defined with
 * the <codeph class="+ topic/ph pr-d/codeph ">image1</codeph> data type.</p><p class="- topic/p ">Generally, developer code does not create a ShaderInput instance
 * directly. A ShaderInput instance is created for each of a shader's inputs
 * when the Shader instance is created.</p>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */

namespace flash
{
    namespace display
    {
        class ShaderInput: public Object
        {
            /**
             * The input data that is used when the shader executes. This property can be
             * a BitmapData instance, a ByteArray instance, or a Vector.<Number> instance.
             *
             *   If a ByteArray value is assigned to the input property, the following
             * conditions must be met:The height and width properties must be set.The byte array's contents must only consist of 32-bit floating-point values.
             * These values can be written using the ByteArray.writeFloat() method.The total length in bytes of the ByteArray must be exactly width times
             * height times channels times 4.The byte array's endian property must be Endian.LITTLE_ENDIAN.If a Vector.<Number> instance is assigned to the input property, the
             * length of the Vector must be equal to width times height times
             * channels.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            Object      *input();
        public:
            void         input(Object *input);

            /**
             * The width of the shader input. This property is only used when the input data
             * is a ByteArray or Vector.<Number> instance. When the input is a BitmapData
             * instance the width is automatically determined.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            int          width();
        public:
            void         width(int value);

            /**
             * The height of the shader input. This property is only used when the input data
             * is a ByteArray or Vector.<Number> instance. When the input is a BitmapData
             * instance the height is automatically determined.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            int          height();
        public:
            void         height(int value);

            /**
             * The number of channels that a shader input expects. This property must be
             * accounted for when the input data is a ByteArray or
             * Vector.<Number> instance.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            int          channels();

            /**
             * The zero-based index of the input in the shader, indicating the order
             * of the input definitions in the shader.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            int          index();

            /**
             * Creates a ShaderInput instance. Developer code does
             * not call the ShaderInput constructor
             * directly. A ShaderInput instance is created for each of a shader's inputs
             * when the Shader instance is created.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            ShaderInput();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_SHADERINPUT_AS
#endif // __cplusplus

