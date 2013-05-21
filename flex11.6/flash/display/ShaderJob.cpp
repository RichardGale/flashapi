

#include "ShaderJob.h"
#include "flash/events/EventDispatcher.h"
#include "flash/display/Shader.h"

    /**
     * Dispatched when a ShaderJob that executes asynchronously finishes processing 
     * the data using the shader.
     * @eventType   flash.events.ShaderEvent.COMPLETE
     */

using namespace flash::display;
using namespace flash::events;

namespace flash {
namespace display {


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
        flash::display::Shader* ShaderJob::shader()                       ;
        void ShaderJob::shader(Shader* s)       ;

        /**
         * The object into which the result of the shader operation is written. 
         * This object must be a BitmapData, ByteArray, or Vector.<Number> instance.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        Object* ShaderJob::target()         ;
        void ShaderJob::target(Object* s)       ;

        /**
         * The width of the result data in the target if it is 
         * a ByteArray or Vector.<Number> instance. The size of the 
         * ByteArray or Vector.<Number> instance is enlarged 
         * if necessary and existing data is overwritten.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        int ShaderJob::width()      ;
        void ShaderJob::width(int v)       ;

        /**
         * The height of the result data in the target if it is 
         * a ByteArray or Vector.<Number> instance. The size of the 
         * ByteArray or Vector.<Number> instance is enlarged 
         * if necessary and existing data is overwritten.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        int ShaderJob::height()      ;
        void ShaderJob::height(int v)       ;

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
        float ShaderJob::progress()         ;

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
        ShaderJob::ShaderJob(Shader* shader, Object* target, int width, int height);

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
        void ShaderJob::start(bool waitForCompletion)       ;

        /**
         * Cancels the currently running shader operation. Any result data that is already 
         * computed is discarded. The complete event is not dispatched.
         * 
         *   Calling cancel() multiple times has no additional effect.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        void ShaderJob::cancel()       ;
}
}

