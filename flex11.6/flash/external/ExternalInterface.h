#if !defined(FLEX11_6_FLASH_EXTERNAL_EXTERNALINTERFACE_AS)
#define FLEX11_6_FLASH_EXTERNAL_EXTERNALINTERFACE_AS
#if defined(__cplusplus)


/**
 * The ExternalInterface class is an application programming interface
 * that enables straightforward communication between ActionScript and the SWF
 * container    for example, an HTML page with JavaScript or a desktop application
 * that uses Flash Player to display a SWF file.
 *
 *   <p class="- topic/p ">Using the ExternalInterface class, you can call an ActionScript function in
 * the Flash runtime, using JavaScript in the HTML page. The ActionScript function can return a value,
 * and JavaScript receives it immediately as the return value of the call.</p><p class="- topic/p ">This functionality replaces the
 * <codeph class="+ topic/ph pr-d/codeph ">fscommand()</codeph> method.</p><p class="- topic/p ">Use the ExternalInterface class in the following combinations of browser and
 * operating system:</p><adobetable class="innertable"><tgroup cols="3" class="- topic/tgroup "><thead class="- topic/thead "><row class="- topic/row "><entry class="- topic/entry ">Browser</entry><entry class="- topic/entry ">Operating System</entry><entry class="- topic/entry ">Operating System</entry></row></thead><tbody class="- topic/tbody "><row class="- topic/row "><entry class="- topic/entry ">Internet Explorer 5.0 and later</entry><entry class="- topic/entry ">  Windows  </entry><entry class="- topic/entry ">  </entry></row><row class="- topic/row "><entry class="- topic/entry ">Netscape 8.0 and later</entry><entry class="- topic/entry ">  Windows  </entry><entry class="- topic/entry ">  MacOS  </entry></row><row class="- topic/row "><entry class="- topic/entry ">Mozilla 1.7.5 and later</entry><entry class="- topic/entry ">  Windows  </entry><entry class="- topic/entry ">  MacOS  </entry></row><row class="- topic/row "><entry class="- topic/entry ">Firefox 1.0 and later</entry><entry class="- topic/entry ">  Windows  </entry><entry class="- topic/entry ">  MacOS  </entry></row><row class="- topic/row "><entry class="- topic/entry ">Safari 1.3 and later</entry><entry class="- topic/entry ">  </entry><entry class="- topic/entry ">  MacOS  </entry></row></tbody></tgroup></adobetable><p class="- topic/p ">Flash Player for Linux version 9.0.31.0 and later supports the ExternalInterface class in the following browsers:</p><adobetable class="innertable"><tgroup cols="1" class="- topic/tgroup "><thead class="- topic/thead "><row class="- topic/row "><entry class="- topic/entry ">Browser</entry></row></thead><tbody class="- topic/tbody "><row class="- topic/row "><entry class="- topic/entry ">Mozilla 1.7.x and later</entry></row><row class="- topic/row "><entry class="- topic/entry ">Firefox 1.5.0.7 and later</entry></row><row class="- topic/row "><entry class="- topic/entry ">SeaMonkey 1.0.5 and later </entry></row></tbody></tgroup></adobetable><p class="- topic/p ">The ExternalInterface class requires the user's web browser to support either
 * ActiveX<sup class="+ topic/ph hi-d/sup ">  </sup> or the NPRuntime API that is exposed by some browsers for plug-in scripting.
 * Even if a browser and operating system combination are not listed above, they should support
 * the ExternalInterface class if they support the NPRuntime API.
 * See <xref href="http://www.mozilla.org/projects/plugins/npruntime.html" scope="external" class="- topic/xref ">http://www.mozilla.org/projects/plugins/npruntime.html</xref>.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> When embedding SWF files within an HTML page, make sure that the <codeph class="+ topic/ph pr-d/codeph ">id</codeph> attribute is set and the
 * <codeph class="+ topic/ph pr-d/codeph ">id</codeph> and <codeph class="+ topic/ph pr-d/codeph ">name</codeph> attributes of the <codeph class="+ topic/ph pr-d/codeph ">object</codeph> and <codeph class="+ topic/ph pr-d/codeph ">embed</codeph>
 * tags do not include the following characters:</p><pre xml:space="preserve" class="- topic/pre ">
 * . - + ~~ / \
 * </pre><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note for Flash Player applications:</b> Flash Player version 9.0.115.0 and later allows the <codeph class="+ topic/ph pr-d/codeph ">.</codeph> (period) character
 * within the <codeph class="+ topic/ph pr-d/codeph ">id</codeph> and <codeph class="+ topic/ph pr-d/codeph ">name</codeph> attributes.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note for Flash Player applications:</b> In Flash Player 10 and later running in a browser, using this class programmatically to
 * open a pop-up window may not be successful.  Various browsers (and browser configurations) may block pop-up windows
 * at any time; it is not possible to guarantee any pop-up window will appear.
 * However, for the best chance of success, use this class to open a pop-up window only in code that executes
 * as a direct result of a user action (for example, in an event handler for a mouse click or key-press event.)</p><p class="- topic/p ">From ActionScript, you can do the following on the HTML page:
 * <ul class="- topic/ul "><li class="- topic/li ">Call any JavaScript function.</li><li class="- topic/li ">Pass any number of arguments, with any names.</li><li class="- topic/li ">Pass various data types (Boolean, Number, String, and so on).</li><li class="- topic/li ">Receive a return value from the JavaScript function.</li></ul></p><p class="- topic/p ">From JavaScript on the HTML page, you can:
 * <ul class="- topic/ul "><li class="- topic/li ">Call an ActionScript function.</li><li class="- topic/li ">Pass arguments using standard function call notation.</li><li class="- topic/li ">Return a value to the JavaScript function.</li></ul></p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note for Flash Player applications:</b> Flash Player does not currently support SWF files embedded within HTML forms.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note for AIR applications:</b> In Adobe AIR, the ExternalInterface class can be used to communicate between JavaScript
 * in an HTML page loaded in the HTMLLoader control and ActionScript in SWF content embedded in that HTML page.</p>
 *
 *   EXAMPLE:
 *
 *   The following example demonstrates sending data between Flash Player and an HTML container.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.events.*;
 * import flash.external.ExternalInterface;
 * import flash.text.TextField;
 * import flash.utils.Timer;
 * import flash.text.TextFieldType;
 * import flash.text.TextFieldAutoSize;
 *
 *   public class ExternalInterfaceExample extends Sprite {
 * private var input:TextField;
 * private var output:TextField;
 * private var sendBtn:Sprite;
 *
 *   public function ExternalInterfaceExample() {
 * input = new TextField();
 * input.type = TextFieldType.INPUT;
 * input.background = true;
 * input.border = true;
 * input.width = 350;
 * input.height = 18;
 * addChild(input);
 *
 *   sendBtn = new Sprite();
 * sendBtn.mouseEnabled = true;
 * sendBtn.x = input.width + 10;
 * sendBtn.graphics.beginFill(0xCCCCCC);
 * sendBtn.graphics.drawRoundRect(0, 0, 80, 18, 10, 10);
 * sendBtn.graphics.endFill();
 * sendBtn.addEventListener(MouseEvent.CLICK, clickHandler);
 * addChild(sendBtn);
 *
 *   output = new TextField();
 * output.y = 25;
 * output.width = 450;
 * output.height = 325;
 * output.multiline = true;
 * output.wordWrap = true;
 * output.border = true;
 * output.text = "Initializing...\n";
 * addChild(output);
 *
 *   if (ExternalInterface.available) {
 * try {
 * output.appendText("Adding callback...\n");
 * ExternalInterface.addCallback("sendToActionScript", receivedFromJavaScript);
 * if (checkJavaScriptReady()) {
 * output.appendText("JavaScript is ready.\n");
 * } else {
 * output.appendText("JavaScript is not ready, creating timer.\n");
 * var readyTimer:Timer = new Timer(100, 0);
 * readyTimer.addEventListener(TimerEvent.TIMER, timerHandler);
 * readyTimer.start();
 * }
 * } catch (error:SecurityError) {
 * output.appendText("A SecurityError occurred: " + error.message + "\n");
 * } catch (error:Error) {
 * output.appendText("An Error occurred: " + error.message + "\n");
 * }
 * } else {
 * output.appendText("External interface is not available for this container.");
 * }
 * }
 * private function receivedFromJavaScript(value:String):void {
 * output.appendText("JavaScript says: " + value + "\n");
 * }
 * private function checkJavaScriptReady():Boolean {
 * var isReady:Boolean = ExternalInterface.call("isReady");
 * return isReady;
 * }
 * private function timerHandler(event:TimerEvent):void {
 * output.appendText("Checking JavaScript status...\n");
 * var isReady:Boolean = checkJavaScriptReady();
 * if (isReady) {
 * output.appendText("JavaScript is ready.\n");
 * Timer(event.target).stop();
 * }
 * }
 * private function clickHandler(event:MouseEvent):void {
 * if (ExternalInterface.available) {
 * ExternalInterface.call("sendToJavaScript", input.text);
 * }
 * }
 * }
 * }
 *
 *   </codeblock> In order to test the previous ActionScript code, embed the generated SWF file using the following HTML template:
 * <codeblock rev="2.0" xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * &lt;!-- saved from url=(0014)about:internet --&gt;
 * &lt;html lang="en"&gt;
 * &lt;head&gt;
 * &lt;meta http-equiv="Content-Type" content="text/html; charset=utf-8" /&gt;
 * &lt;title&gt;ExternalInterfaceExample&lt;/title&gt;
 * &lt;script language="JavaScript"&gt;
 * var jsReady = false;
 * function isReady() {
 * return jsReady;
 * }
 * function pageInit() {
 * jsReady = true;
 * document.forms["form1"].output.value += "\n" + "JavaScript is ready.\n";
 * }
 * function thisMovie(movieName) {
 * if (navigator.appName.indexOf("Microsoft") != -1) {
 * return window[movieName];
 * } else {
 * return document[movieName];
 * }
 * }
 * function sendToActionScript(value) {
 * thisMovie("ExternalInterfaceExample").sendToActionScript(value);
 * }
 * function sendToJavaScript(value) {
 * document.forms["form1"].output.value += "ActionScript says: " + value + "\n";
 * }
 * &lt;/script&gt;
 * &lt;/head&gt;
 * &lt;body onload="pageInit();"&gt;
 *
 *   &lt;object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000"
 * id="ExternalInterfaceExample" width="500" height="375"
 * codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab"&gt;
 * &lt;param name="movie" value="ExternalInterfaceExample.swf" /&gt;
 * &lt;param name="quality" value="high" /&gt;
 * &lt;param name="bgcolor" value="#869ca7" /&gt;
 * &lt;param name="allowScriptAccess" value="sameDomain" /&gt;
 * &lt;embed src="ExternalInterfaceExample.swf" quality="high" bgcolor="#869ca7"
 * width="500" height="375" name="ExternalInterfaceExample" align="middle"
 * play="true" loop="false" quality="high" allowScriptAccess="sameDomain"
 * type="application/x-shockwave-flash"
 * pluginspage="http://www.macromedia.com/go/getflashplayer"&gt;
 * &lt;/embed&gt;
 * &lt;/object&gt;
 *
 *   &lt;form name="form1" onsubmit="return false;"&gt;
 * &lt;input type="text" name="input" value="" /&gt;
 * &lt;input type="button" value="Send" onclick="sendToActionScript(this.form.input.value);" /&gt;&lt;br /&gt;
 * &lt;textarea cols="60" rows="20" name="output" readonly="true"&gt;Initializing...&lt;/textarea&gt;
 * &lt;/form&gt;
 *
 *   &lt;/body&gt;
 * &lt;/html&gt;
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 * @internal    Verify table is still correct and paragraph below the table still applies.
 */


namespace flash
{
    namespace external
    {
        class ExternalInterface : public Object
        {
            /**
             * Indicates whether the external interface should attempt to pass ActionScript exceptions to the
             * current browser and JavaScript exceptions to the player. You must explicitly set this property
             * to true to catch JavaScript exceptions in ActionScript and to catch ActionScript exceptions
             * in JavaScript.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             * @playerversion   Lite 4
             */
        public:
            static bool marshallExceptions;

            /**
             * Indicates whether this player is in a container that offers an external interface.
             * If the external interface is available, this property is true; otherwise,
             * it is false.
             *
             *   Note: When using the External API with HTML, always check that the HTML
             * has finished loading before you attempt to call any JavaScript methods.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static bool         available();

            /**
             * Returns the id attribute of the object tag in Internet Explorer,
             * or the name attribute of the embed tag in Netscape.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static std::string  objectID();

        public:
            ExternalInterface();

            /**
             * Registers an ActionScript method as callable from the container.
             * After a successful invocation of addCallBack(), the registered function in
             * the player can be called by JavaScript or ActiveX code in the container.
             *
             *   Note: For local content running in a browser, calls to the
             * ExternalInterface.addCallback() method work only if the SWF file and the
             * containing web page are in the local-trusted security sandbox. For more information,
             * see the Flash Player Developer Center Topic: Security.
             * @param   functionName    The name by which the container can invoke
             *   the function.
             * @param   closure The function closure to invoke. This could be a
             *   free-standing function, or it could be a method closure
             *   referencing a method of an object instance. By passing
             *   a method closure, you can direct the callback
             *   at a method of a particular object instance.
             *   Note: Repeating addCallback() on an existing callback function
             *   with a null closure value removes the callback.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error The container does not support incoming calls.
             *   Incoming calls are supported only in Internet Explorer for Windows and browsers
             *   that use the NPRuntime API such as Mozilla 1.7.5 and later or Firefox 1.0 and later.
             * @throws  SecurityError A callback with the specified name has already been
             *   added by ActionScript in a sandbox to which you do not have access; you
             *   cannot overwrite that callback. To work around this problem, rewrite the
             *   ActionScript that originally called the addCallback() method so that it also
             *   calls the Security.allowDomain() method.
             * @throws  SecurityError The containing environment belongs to a security sandbox
             *   to which the calling code does not have access. To fix this problem, follow these steps:
             *
             *     In the object tag for the SWF file in the containing HTML page,
             *   set the following parameter:
             *
             *     <param name="allowScriptAccess" value="always" />In the SWF file, add the following ActionScript:
             *
             *     flash.system.Security.allowDomain(sourceDomain)
             */
        public:
            static void     addCallback(std::string functionName, Function *closure);

            /**
             * Calls a function exposed by the SWF container, passing zero or
             * more arguments.  If the function is not available, the call returns
             * null; otherwise it returns the value provided by the function.
             * Recursion is not permitted on Opera or Netscape browsers; on these browsers a recursive call
             * produces a null response. (Recursion is supported on Internet Explorer and Firefox browsers.)
             *
             *   If the container is an HTML page, this method invokes a JavaScript function
             * in a script element.If the container is another ActiveX container, this method dispatches the
             * FlashCall ActiveX event with the specified name, and the container processes the event.If the container is hosting the Netscape plug-in, you can either write custom support
             * for the new NPRuntime interface or embed an HTML control and embed the player within
             * the HTML control. If you embed an HTML control, you can communicate with the
             * player through a JavaScript interface to the native container application.Note: For local content running in a browser, calls to the
             * ExternalInterface.call() method are permitted only if the SWF file and the
             * containing web page (if there is one) are in the local-trusted security sandbox. Also, you can
             * prevent a SWF file from using this method by setting the  allowNetworking
             * parameter of the object and embed tags in the HTML
             * page that contains the SWF content. For more information, see the Flash Player Developer Center Topic:
             * Security.Note for Flash Player applications: In Flash Player 10 and Flash Player 9 Update 5, some web browsers restrict this method
             * if a pop-up blocker is enabled. In this scenario, you can only call this method successfully
             * in response to a user event (for example, in an event handler for a mouse click or keypress event).
             * @param   functionName    The alphanumeric name of the function to call in the container. Using a non-alphanumeric function name
             *   causes a runtime error (error 2155). You can use a try..catch block to handle the error.
             * @param   arguments   The arguments to pass to the function in the
             *   container. You can specify zero or more parameters, separating them with commas.
             *   They can be of any ActionScript data type.
             *   When the call is to a JavaScript function, the ActionScript
             *   types are automatically converted into JavaScript types; when the call is to some other
             *   ActiveX container, the parameters are encoded in the request message.
             * @return  The response received from the container. If the call failed    for example, if there is no such
             *   function in the container, the interface is not available, a recursion occurred (with a Netscape
             *   or Opera browser), or there is a security issue    null is returned and an error is thrown.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    Should probably provide a link for the 4th paragraph above for info on Netscape.
             * @throws  Error The container does not support outgoing calls.
             *   Outgoing calls are supported only in Internet Explorer for Windows and browsers
             *   that use the NPRuntime API such as Mozilla 1.7.5 and later or Firefox 1.0 and later.
             * @throws  SecurityError The containing environment belongs to a security sandbox
             *   to which the calling code does not have access. To fix this problem, follow these steps:
             *
             *     In the object tag for the SWF file in the containing HTML page,
             *   set the following parameter:
             *
             *     <param name="allowScriptAccess" value="always" />In the SWF file, add the following ActionScript:
             *
             *     flash.system.Security.allowDomain(sourceDomain)
             */
        public:
            static void    *call(std::string functionName, ...);
        };
    }
}

#endif // FLEX11_6_FLASH_EXTERNAL_EXTERNALINTERFACE_AS
#endif // __cplusplus

