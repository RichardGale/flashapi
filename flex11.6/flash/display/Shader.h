#if !defined(FLEX11_6_FLASH_DISPLAY_SHADER_AS)
#define FLEX11_6_FLASH_DISPLAY_SHADER_AS
#if defined(__cplusplus)


namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}
namespace flash
{
    namespace display
    {
        class ShaderData;
    }
}

/**
 * A Shader instance represents a Pixel Bender shader kernel in ActionScript. To use
 * a shader in your application, you create a Shader instance for it. You
 * then use that Shader instance in the appropriate way according to the effect
 * you want to create. For example, to use the shader as a filter, you
 * assign the Shader instance to the <codeph class="+ topic/ph pr-d/codeph ">shader</codeph> property of a
 * ShaderFilter object.
 *
 *   <p class="- topic/p ">A shader defines a function that executes on all the pixels in an image,
 * one pixel at a time. The result of each call to the function is the output
 * color at that pixel coordinate in the image. A shader can specify one or more
 * input images, which are images whose content can be used in determining the
 * output of the function. A shader can also specify one or more parameters,
 * which are input values that can be used in calculating the function output. In
 * a single shader execution, the input and parameter values are constant. The only
 * thing that varies is the coordinate of the pixel whose color is the function result.
 * Shader function calls for multiple output
 * pixel coordinates execute in parallel to improve shader execution performance.</p><p class="- topic/p ">The shader bytecode can be loaded at run time using a URLLoader instance.
 * The following example demonstrates loading a shader bytecode file at run time
 * and linking it to a Shader instance.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * var loader:URLLoader = new URLLoader();
 * loader.dataFormat = URLLoaderDataFormat.BINARY;
 * loader.addEventListener(Event.COMPLETE, onLoadComplete);
 * loader.load(new URLRequest("myShader.pbj"));
 *
 *   var shader:Shader;
 *
 *   function onLoadComplete(event:Event):void {
 * // Create a new shader and set the loaded data as its bytecode
 * shader = new Shader();
 * shader.byteCode = loader.data;
 *
 *   // You can also pass the bytecode to the Shader() constructor like this:
 * // shader = new Shader(loader.data);
 *
 *   // do something with the shader
 * }
 * </codeblock><p class="- topic/p ">You can also embed the shader into the SWF at compile time using the
 * <codeph class="+ topic/ph pr-d/codeph ">[Embed]</codeph> metadata tag. The <codeph class="+ topic/ph pr-d/codeph ">[Embed]</codeph> metadata tag
 * is only available if you use the Flex SDK to compile the SWF. The
 * <codeph class="+ topic/ph pr-d/codeph ">[Embed]</codeph> tag's <codeph class="+ topic/ph pr-d/codeph ">source</codeph> parameter points to
 * the shader file, and its <codeph class="+ topic/ph pr-d/codeph ">mimeType</codeph> parameter is
 * <codeph class="+ topic/ph pr-d/codeph ">"application/octet-stream"</codeph>, as in this example:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * [Embed(source="myShader.pbj", mimeType="application/octet-stream)]
 * var MyShaderClass:Class;
 *
 *   // ...
 *
 *   // create a new shader and set the embedded shader as its bytecode
 * var shaderShader = new Shader();
 * shader.byteCode = new MyShaderClass();
 *
 *   // You can also pass the bytecode to the Shader() constructor like this:
 * // var shader:Shader = new Shader(new MyShaderClass());
 *
 *   // do something with the shader
 * </codeblock><p class="- topic/p ">In either case, you link the raw shader (the <codeph class="+ topic/ph pr-d/codeph ">URLLoader.data</codeph> property
 * or an instance of the <codeph class="+ topic/ph pr-d/codeph ">[Embed]</codeph> data class) to the Shader instance. As
 * the previous examples demonstrate, you can do this in two ways. You can
 * pass the shader bytecode as an argument
 * to the <codeph class="+ topic/ph pr-d/codeph ">Shader()</codeph> constructor. Alternatively, you can set it as the Shader
 * instance's <codeph class="+ topic/ph pr-d/codeph ">byteCode</codeph> property.</p><p class="- topic/p ">Once a Shader instance is created, it can be used in one of several
 * ways:</p><ul class="- topic/ul "><li class="- topic/li ">A shader fill: The output of the shader is used as a fill for
 * content drawn with the drawing API. Pass the Shader instance as
 * an argument to the <codeph class="+ topic/ph pr-d/codeph ">Graphics.beginShaderFill()</codeph> method.</li><li class="- topic/li ">A shader filter: The output of the shader is used as a graphic filter
 * applied to a display object. Assign the Shader instance to the
 * <codeph class="+ topic/ph pr-d/codeph ">shader</codeph> property of a ShaderFilter instance.</li><li class="- topic/li ">A blend mode: The output of the shader is rendered as the blending
 * between two overlapping display objects. Assign the Shader instance
 * to the <codeph class="+ topic/ph pr-d/codeph ">blendShader</codeph> property of the upper of the
 * two display objects.</li><li class="- topic/li ">Background shader processing: The shader executes in the background,
 * avoiding the possibility of freezing the display, and dispatches an
 * event when processing is complete. Assign the Shader instance to
 * the <codeph class="+ topic/ph pr-d/codeph ">shader</codeph> property of a ShaderJob instance.</li></ul><p class="- topic/p ">Shader fills, filters, and blends are not supported under GPU rendering.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Mobile Browser Support:</b> This feature is not supported in mobile browsers.</p><p class="- topic/p "><i class="+ topic/ph hi-d/i ">AIR profile support:</i> This feature is supported
 * on all desktop operating systems, but it is not supported on all mobile devices. It is not supported on AIR
 * for TV devices. See
 * <xref href="http://help.adobe.com/en_US/air/build/WS144092a96ffef7cc16ddeea2126bb46b82f-8000.html" class="- topic/xref ">
 * AIR Profile Support</xref> for more information regarding API support across multiple profiles.</p>
 *
 *   EXAMPLE:
 *
 *   The following example loads a shader bytecode file at run time and creates
 * a Shader instance linked to it.
 *
 *   <p class="- topic/p ">Note that this example assumes there's a shader bytecode file named "donothing.pbj" in the same
 * directory as the output directory for the application. The Pixel Bender source code for the DoNothing shader
 * is available in the <xref href="ShaderData.html#includeExamplesSummary" class="- topic/xref ">ShaderData class example</xref>.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Shader;
 * import flash.display.Sprite;
 * import flash.events.Event;
 * import flash.net.URLLoader;
 * import flash.net.URLLoaderDataFormat;
 * import flash.net.URLRequest;
 *
 *   public class LoadedShaderExample extends Sprite {
 *
 *   private var loader:URLLoader;
 *
 *   public function LoadedShaderExample() {
 * loader = new URLLoader();
 * loader.dataFormat = URLLoaderDataFormat.BINARY;
 * loader.addEventListener(Event.COMPLETE, loadCompleteHandler);
 * loader.load(new URLRequest("donothing.pbj"));
 * }
 *
 *   private function loadCompleteHandler(event:Event):void {
 * var shader:Shader = new Shader();
 * shader.byteCode = loader.data;
 *
 *   // do something with the Shader instance
 * }
 * }
 * }
 * </codeblock>
 *
 *   EXAMPLE:
 *
 *   The following example embeds a shader bytecode file by compiling it
 * into the SWF, and creates a Shader instance linked to it.
 *
 *   <p class="- topic/p ">Note that this example assumes there's a shader bytecode file named "donothing.pbj" in the same
 * directory as the source code for the application, and that the Flex SDK is used to compile the SWF.
 * The Pixel Bender source code for the DoNothing shader
 * is available in the <xref href="ShaderData.html#includeExamplesSummary" class="- topic/xref ">ShaderData class example</xref>.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Shader;
 * import flash.display.Sprite;
 *
 *   public class EmbeddedShaderExample extends Sprite {
 *
 *   [Embed(source="donothing.pbj", mimeType="application/octet-stream")]
 * private static var DoNothingShader:Class;
 *
 *   public function EmbeddedShaderExample() {
 * var shader:Shader = new Shader();
 * shader.byteCode = new DoNothingShader();
 *
 *   // do something with the Shader instance
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */
using namespace flash::utils;
using namespace flash::display;

namespace flash
{
    namespace display
    {
        class Shader: public Object
        {
            /**
             * The raw shader bytecode for this Shader instance.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            void         byteCode(ByteArray *code);

            /**
             * Provides access to parameters, input images, and metadata for the Shader instance.
             * ShaderParameter objects representing parameters for the shader, ShaderInput objects
             * representing the input images for the shader, and other values representing the
             * shader's metadata are dynamically added as properties of the data
             * property object when the Shader instance is created. Those properties can be
             * used to introspect the shader and to set parameter and input values.
             *
             *   For information about accessing and manipulating the dynamic properties of
             * the data object, see the ShaderData class description.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            flash::display::ShaderData *data();
        public:
            void         data(ShaderData *p);

            /**
             * The precision of math operations performed by the shader.
             *
             *   The set of possible values for the precisionHint property is defined
             * by the constants in the ShaderPrecision class.The default value is ShaderPrecision.FULL. Setting the precision
             * to ShaderPrecision.FAST can speed up math operations at the expense
             * of precision.Full precision mode (ShaderPrecision.FULL) computes all math
             * operations to the full width of the IEEE 32-bit floating standard and provides
             * consistent behavior on all platforms. In this mode, some math operations such
             * as trigonometric and exponential functions can be slow.Fast precision mode (ShaderPrecision.FAST) is designed for
             * maximum performance but does not work consistently on different platforms
             * and individual CPU configurations. In many cases, this level of precision
             * is sufficient to create graphic effects without visible artifacts.The precision mode selection affects the following shader operations.
             * These operations are faster on an Intel processor
             * with the SSE instruction set:sin(x)cos(x)tan(x)asin(x)acos(x)atan(x)atan(x, y)exp(x)exp2(x)log(x)log2(x)pow(x, y)reciprocal(x)sqrt(x)
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            std::string  precisionHint();
        public:
            void         precisionHint(std::string p);

        public:
            Shader(ByteArray *code);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_SHADER_AS
#endif // __cplusplus

