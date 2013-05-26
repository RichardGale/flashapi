#if !defined(FLEX11_6_FLASH_ERRORS_MEMORYERROR_AS)
#define FLEX11_6_FLASH_ERRORS_MEMORYERROR_AS
#if defined(__cplusplus)


/**
 * The MemoryError exception is thrown when a memory allocation request fails.
 *
 *   <p class="- topic/p ">On a desktop machine, memory allocation failures are rare unless an allocation
 * request is extremely large. For example, a 32-bit Windows program can access only 2GB of
 * address space, so a request for 10 billion bytes is impossible.</p><p class="- topic/p ">By default, Flash Player does not impose a limit on how much memory an
 * ActionScript program can allocate.</p>
 *
 *   EXAMPLE:
 *
 *   The following example shows one method of generating a MemoryError.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.errors.MemoryError;
 * import flash.utils.setInterval;
 *
 *   public class MemoryErrorExample extends Sprite {
 * private var crashingStr:String;
 * private var intervalId:Number;
 *
 *   public function MemoryErrorExample() {
 * crashingStr = "abcdefghijklmnopqrstuvwxyz";
 * intervalId = setInterval(exhaustMemory, 50);
 * }
 *
 *   public function exhaustMemory():void {
 * try {
 * crashingStr += crashingStr;
 * }
 * catch(e:MemoryError) {
 * trace(e);
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



namespace flash
{
    namespace errors
    {
        class MemoryError : public Error
        {
        public:
            MemoryError(std::string message="", int id=0);
        };
    }
}

#endif // FLEX11_6_FLASH_ERRORS_MEMORYERROR_AS
#endif // __cplusplus

