

    /**
     * The ScriptTimeoutError exception is thrown when the script timeout interval is reached. 
     * The script timeout interval is 15 seconds. <ph outputclass="flexonly" class="- topic/ph ">There are two XML attributes 
     * that you can add to the <codeph class="+ topic/ph pr-d/codeph ">mx:Application</codeph> tag: <codeph class="+ topic/ph pr-d/codeph ">scriptTimeLimit</codeph> 
     * (the number of seconds until script timeout) and <codeph class="+ topic/ph pr-d/codeph ">scriptRecursionLimit</codeph> 
     * (the depth of recursive calls permitted). </ph><p class="- topic/p ">Two ScriptTimeoutError exceptions are thrown. The first exception you can catch and exit
     * cleanly. If there is no exception handler, the uncaught exception terminates execution. The 
     * second exception is thrown but cannot be caught by user code; it goes to the uncaught 
     * exception handler. It is uncatchable to prevent the player from hanging 
     * indefinitely.</p>
     * 
     *   EXAMPLE:
     * 
     *   The following example uses the sample ScriptTimeoutErrorExample class to show 
     * the error generated in the event of script timeout.  This is accomplished with the following 
     * steps:
     * <ol class="- topic/ol "><li class="- topic/li ">A <codeph class="+ topic/ph pr-d/codeph ">keepLooking</codeph> Boolean property is declared.</li><li class="- topic/li ">The constructor calls the <codeph class="+ topic/ph pr-d/codeph ">lockMachine()</codeph> method within an error handling code
     * segment that catches ScriptTimeoutError objects.  </li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">lockMachine()</codeph> method contains an endless <codeph class="+ topic/ph pr-d/codeph ">while</codeph> loop.</li><li class="- topic/li ">After awhile, the ScriptTimeoutError is thrown. The constructor catches it, 
     * outputs an error message through the <codeph class="+ topic/ph pr-d/codeph ">trace</codeph> statement and resets the <codeph class="+ topic/ph pr-d/codeph ">keepLooking</codeph>
     * Boolean to <codeph class="+ topic/ph pr-d/codeph ">false</codeph>, which terminates the <codeph class="+ topic/ph pr-d/codeph ">while</codeph> loop in <codeph class="+ topic/ph pr-d/codeph ">lockMachine()</codeph>. </li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * import flash.display.Sprite;
     * import flash.errors.ScriptTimeoutError;
     * 
     *   public class ScriptTimeoutErrorExample extends Sprite {        
     * private var keepLooping:Boolean = true;
     * 
     *   public function ScriptTimeoutErrorExample() {
     * try {
     * lockMachine();
     * } 
     * catch(e:ScriptTimeoutError) {
     * trace(e);    // ScriptTimeoutError: Error #1502: A script has executed for longer than 15 seconds
     * keepLooping = false;
     * }
     * }
     * 
     *   private function lockMachine():void {
     * while(keepLooping){        
     * }
     * }
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */


namespace flash {
namespace errors {


        ScriptTimeoutError::ScriptTimeoutError(std::string message, int id);
}
}

