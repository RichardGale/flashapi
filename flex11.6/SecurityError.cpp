

    /**
     * The <codeph class="+ topic/ph pr-d/codeph ">SecurityError</codeph> exception is thrown when some type of security violation 
     * takes place.
     * <p class="- topic/p ">
     * Examples of security errors:</p><ul class="- topic/ul "><li class="- topic/li ">An unauthorized property access or method call is made across a security sandbox 
     * boundary.</li><li class="- topic/li ">An attempt was made to access a URL not permitted by the security sandbox.</li><li class="- topic/li ">A socket connection was attempted to an unauthorized port number, e.g. a port above 
     * 65535.</li><li class="- topic/li ">An attempt was made to access the user's camera or microphone, and the request to 
     * access the device was denied by the user.</li></ul>
     * 
     *   EXAMPLE:
     * 
     *   The following example shows how a <codeph class="+ topic/ph pr-d/codeph ">SecurityError</codeph> error can 
     * be generated and handled within a <codeph class="+ topic/ph pr-d/codeph ">try...catch</codeph> statement by attempting 
     * to connect to a port number that is one larger than the maximum allowed.
     * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package {
     * import flash.display.Sprite;
     * import flash.net.Socket;
     * 
     *   public class SecurityErrorExample extends Sprite {
     * 
     *   public function SecurityErrorExample() {
     * try {
     * var host:String = "www.[yourDomain].com";
     * var socket:Socket = new Socket();
     * socket.connect(host, 65536);
     * }
     * catch(e:SecurityError) {
     * trace(e);
     * }
     * }
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     * @playerversion   Lite 4
     */




        const int SecurityError::length  ;

        /**
         * Creates a new SecurityError object.
         * @playerversion   Lite 4
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         */
        SecurityError::SecurityError(void* message, void* id);

