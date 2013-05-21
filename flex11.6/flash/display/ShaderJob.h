#if !defined(FLEX11_6_FLASH_DISPLAY_SHADERJOB_AS)
#define FLEX11_6_FLASH_DISPLAY_SHADERJOB_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace display
    {
        class Shader;
    }
}

/**
 * Dispatched when a ShaderJob that executes asynchronously finishes processing
 * the data using the shader.
 * @eventType   flash.events.ShaderEvent.COMPLETE
 */
//[Event(name="complete",type="flash.events.ShaderEvent")]

using namespace flash::display;
using namespace flash::events;

namespace flash
{
    namespace display
    {
        /**
         * A ShaderJob instance is used to execute a shader operation in stand-alone mode.
         * The shader operation executes and returns its result data. It is up to the
         * developer to determine how to use the result.
         *
         *   <p class="- topic/p ">There are two primary reasons for using a shader in stand-alone mode:</p><ul class="- topic/ul "><li class="- topic/li ">Processing non-image data: Using a ShaderJob instance you have control
         * over input values and over how the shader result is used. The shader can
         * return the result as binary data or number data instead of image data.</li><li class="- topic/li ">Background processing: Some shaders are complex and require a notable
         * amount of time to execute. Executing a complex shader in the main
         * execution of an application could slow down other parts of the application
         * such as user interaction or updating the screen. Using a ShaderJob instance,
         * you can execute the shader in the background.
         * When the shader is executed in this way, the shader operation runs separate
         * from the main execution of the application.</li></ul><p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">shader</codeph> property (or constructor parameter) specifies the
         * Shader instance representing the shader that is used for the operation. You
         * provide any parameter or input that the shader expects using the
         * associated ShaderParameter or ShaderInput instance.</p><p class="- topic/p ">Before execution a ShaderJob operation, you provide an object into which the
         * result is written, by setting it as the value of the <codeph class="+ topic/ph pr-d/codeph ">target</codeph> property.
         * When the shader operation completes the result is written into the <codeph class="+ topic/ph pr-d/codeph ">target</codeph> object.</p><p class="- topic/p ">To begin a background shader operation,
         * call the <codeph class="+ topic/ph pr-d/codeph ">start()</codeph> method. When the operation finishes the result is
         * written into the <codeph class="+ topic/ph pr-d/codeph ">target</codeph> object. At that point the ShaderJob
         * instance dispatches a <codeph class="+ topic/ph pr-d/codeph ">complete</codeph>
         * event, notifying listeners that the result is available.</p><p class="- topic/p ">To execute a shader synchronously (that is, not running in the background), call
         * the <codeph class="+ topic/ph pr-d/codeph ">start()</codeph> method and pass <codeph class="+ topic/ph pr-d/codeph ">true</codeph> as an argument. The shader
         * runs in the main execution thread and your code pauses until the operation completes. When
         * it finishes the result is written into the <codeph class="+ topic/ph pr-d/codeph ">target</codeph> object. At that point
         * the application continues running at the next line of code.</p>
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        class ShaderJob : public flash::events::EventDispatcher
        {
            /**
             * The shader that's used for the operation. Any input or parameter that the
             * shader expects must be provided using the ShaderInput or ShaderParameter
             * property of the Shader instance's data property. An input must
             * be provided using its corresponding ShaderInput even if it is the same as
             * the target object.
             *
             *   To process a ByteArray containing a linear array of data (as opposed to
             * image data) set the corresponding ShaderInput instance's height
             * to 1 and width to the number of 32-bit floating-point values in
             * the ByteArray. In that case, the input in the shader must be defined with
             * the image1 data type.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            flash::display::Shader *shader();
        public:
            void         shader(Shader *s);

            /**
             * The object into which the result of the shader operation is written.
             * This object must be a BitmapData, ByteArray, or Vector.<Number> instance.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            Object      *target();
        public:
            void         target(Object *s);

            /**
             * The width of the result data in the target if it is
             * a ByteArray or Vector.<Number> instance. The size of the
             * ByteArray or Vector.<Number> instance is enlarged
             * if necessary and existing data is overwritten.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            int          width();
        public:
            void         width(int v);

            /**
             * The height of the result data in the target if it is
             * a ByteArray or Vector.<Number> instance. The size of the
             * ByteArray or Vector.<Number> instance is enlarged
             * if necessary and existing data is overwritten.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            int          height();
        public:
            void         height(int v);

            /**
             * The progress of a running shader. This property is a value from 0 through 1.
             * Zero is the initial value (0% complete). One indicates that the shader
             * has completed its operation.
             *
             *   If the cancel() method is called this property becomes
             * undefined, and its value cannot be used reliably until the
             * shader operation starts again.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            float        progress();

            /**
             *
             * @param   shader  The shader to use for the operation.
             * @param   target  The object into which the result of the shader operation
             *   is written. This argument must be a BitmapData, ByteArray, or
             *   Vector.<Number> instance.
             * @param   width   The width of the result data in the target if it is
             *   a ByteArray or Vector.<Number> instance. The size of the
             *   ByteArray or Vector.<Number> instance is enlarged
             *   if necessary and existing data is overwritten.
             * @param   height  The height of the result data in the target if it is
             *   a ByteArray or Vector.<Number> instance. The size of the
             *   ByteArray or Vector.<Number> instance is enlarged
             *   if necessary and existing data is overwritten.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            ShaderJob(Shader *shader=NULL, Object *target=NULL, int width=0, int height=0);

            /**
             * Starts a shader operation in synchronous or asynchronous mode, according to the
             * value of the waitForCompletion parameter.
             *
             *   In asynchronous mode (when waitForCompletion
             * is false), which is the default, the
             * ShaderJob execution runs in the background. The shader operation does not affect the
             * responsiveness of the display or other operations. In asynchronous mode the start()
             * call returns immediately and the program continues with the next line of code. When the asynchronous
             * shader operation finishes, the result is available and the complete
             * event is dispatched.Only one background ShaderJob operation
             * executes at a time. Shader operations are held in a queue until they execute.
             * If you call the start() method while a shader
             * operation is executing, the additional operation is added to the end of the queue.
             * Later, when its turn comes, it executes.To execute a shader operation in synchronous mode, call start() with a
             * true value for the waitForCompletion parameter (the only parameter).
             * Your code pauses at the point where start() is called until the shader operation
             * completes. At that point the result is available and execution continues with the next line
             * of code.When you call the start() method the Shader instance in the shader
             * property is copied internally. The
             * shader operation uses that internal copy, not a reference to the original shader. Any changes
             * made to the shader, such as changing a parameter value, input, or bytecode, are not applied
             * to the copied shader that's used for the shader processing. To incorporate shader changes
             * into the shader processing, call the cancel() method
             * (if necessary) and call the start() method again to restart the shader processing.While a shader operation is executing, the target object's value
             * is not changed. When the operation finishes (and the complete
             * event is dispatched in asynchronous mode) the entire result is written to the
             * target object at one time. If the target object is a
             * BitmapData instance and its dispose() method is called
             * before the operation finishes, the complete event is still
             * dispatched in asynchronous mode. However, the result data is not
             * written to the BitmapData object because it is in a disposed state.
             * @param   waitForCompletion   Specifies whether to execute the shader in the background
             *   (false, the default) or in the main program
             *   execution (true).
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @throws  ArgumentError When the target property is null or is not
             *   a BitmapData, ByteArray, or Vector.<Number> instance.
             * @throws  ArgumentError When the shader specifies an image input that isn't provided.
             * @throws  ArgumentError When a ByteArray or Vector.<Number> instance is used as
             *   an input and the width
             *   and height properties aren't specified for the
             *   ShaderInput, or the specified values don't match the amount of
             *   data in the input object. See the ShaderInput.input
             *   property for more information.
             */
        public:
            void     start(bool waitForCompletion   =false);

            /**
             * Cancels the currently running shader operation. Any result data that is already
             * computed is discarded. The complete event is not dispatched.
             *
             *   Calling cancel() multiple times has no additional effect.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            void     cancel();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_SHADERJOB_AS
#endif // __cplusplus

