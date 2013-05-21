

    /**
     * The IllegalOperationError exception is thrown when a method is not implemented or the 
     * implementation doesn't cover the current usage.
     * 
     *   <p class="- topic/p ">Examples of illegal operation error exceptions include:</p><ul class="- topic/ul "><li class="- topic/li ">A base class, such as DisplayObjectContainer, provides more functionality than a Stage 
     * can support (such as masks)</li><li class="- topic/li ">Certain accessibility methods are called when the player is compiled without accessibility 
     * support</li><li class="- topic/li ">The mms.cfg setting prohibits a FileReference action</li><li class="- topic/li ">ActionScript tries to run a <codeph class="+ topic/ph pr-d/codeph ">FileReference.browse()</codeph> call when a browse dialog box is already open</li><li class="- topic/li ">ActionScript tries to use an unsupported protocol for a FileReference object (such as FTP)</li><li product="flash" class="- topic/li ">Authoring-only features are invoked from a run-time player</li><li product="flash" class="- topic/li ">An attempt is made to set the name of a Timeline-placed object</li></ul>
     * 
     *   EXAMPLE:
     * 
     *   The following example shows the use of an <codeph class="+ topic/ph pr-d/codeph ">IllegalOperationError</codeph> handler.
     * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * import flash.display.DisplayObject;
     * import flash.display.Sprite;
     * import flash.errors.IllegalOperationError;
     * 
     *   public class IllegalOperationErrorExample extends Sprite {
     * public function IllegalOperationErrorExample() {
     * var child:Sprite = new Sprite();
     * try {
     * addChild(child);
     * }
     * catch(e:IllegalOperationError) {
     * trace(e);
     * }
     * }
     * 
     *   public override function addChild(child:DisplayObject):DisplayObject {
     * throw new IllegalOperationError("addChild cannot be performed on the IllegalOperationErrorExample class");
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


        IllegalOperationError::IllegalOperationError(std::string message, int id);
}
}

