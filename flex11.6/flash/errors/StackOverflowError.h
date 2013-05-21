#if !defined(FLEX11_6_FLASH_ERRORS_STACKOVERFLOWERROR_AS)
#define FLEX11_6_FLASH_ERRORS_STACKOVERFLOWERROR_AS
#if defined(__cplusplus)


/**
 * ActionScript throws a StackOverflowError exception when the stack available to the script
 * is exhausted. ActionScript uses a stack to store information about each method call made in
 * a script, such as the local variables that the method uses. The amount of stack space
 * available varies from system to system.
 *
 *   <p class="- topic/p ">A StackOverflowError exception might indicate that infinite recursion has occurred, in
 * which case a termination case needs to be added to the function. It also might indicate
 * that the recursive algorithm has a proper terminating condition but has exhausted the stack
 * anyway. In this case, try to express the algorithm iteratively instead.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the sample StackOverflowErrorExample class to show
 * the error generated in the event of a stack overflow.  This is accomplished using the following
 * steps:
 * <ol class="- topic/ol "><li class="- topic/li ">The constructor calls the method <codeph class="+ topic/ph pr-d/codeph ">lockMachine()</codeph> within an error handling code
 * segment that catches StackOverflowError objects.  </li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">lockMachine()</codeph> method calls itself until the stack overflows.</li><li class="- topic/li ">After the StackOverflowError is thrown, the constructor catches it and then outputs an
 * error message through the <codeph class="+ topic/ph pr-d/codeph ">trace</codeph> statement. </li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.errors.StackOverflowError;
 *
 *   public class StackOverflowErrorExample extends Sprite {
 * public function StackOverflowErrorExample() {
 * try {
 * lockMachine();
 * }
 * catch(e:StackOverflowError) {
 * trace(e);    // StackOverflowError: Error #1023: Stack overflow.
 * }
 * }
 *
 *   private function lockMachine():void {
 * lockMachine();
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace errors
    {
        class StackOverflowError : public Error
        {
        public:
            StackOverflowError(std::string message="", int id=0);
        };
    }
}

#endif // FLEX11_6_FLASH_ERRORS_STACKOVERFLOWERROR_AS
#endif // __cplusplus

