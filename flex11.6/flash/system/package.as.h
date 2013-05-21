#if !defined(FLEX11_6_FLASH_SYSTEM_PACKAGE_AS_AS)
#define FLEX11_6_FLASH_SYSTEM_PACKAGE_AS_AS
#if defined(__cplusplus)


/**
 * Lets the SWF file communicate with either Flash Player or the program hosting Flash Player,
 * such as a web browser. You can also use the fscommand() function to pass messages to
 * Director or to Visual Basic, Visual C++, and other programs that can host ActiveX controls.
 *
 *   The fscommand() function lets a SWF file communicate with a script in a web page.
 * However, script access is controlled by the web page's allowScriptAccess setting.
 * (You set this attribute in the HTML code that embeds the SWF file   for
 * example, in the PARAM tag for Internet Explorer or the EMBED tag for Netscape.)  When allowScriptAccess is set to "sameDomain" (the default),
 * scripting is allowed only from SWF files that are in the same domain as the web page.  When allowScriptAccess is set to "always",
 * the SWF file can communicate with the HTML page in which it is embedded
 * even when the SWF file is from a different domain than the HTML page. When allowScriptAccess is set to "never",
 * the SWF file cannot communicate with any HTML page. Note that using this value is deprecated and not recommended,
 * and shouldn't be necessary if you don't serve untrusted SWF files from your own domain.
 * If you do need to serve untrusted SWF files, Adobe recommends that you create a distinct subdomain
 * and place all untrusted content there. You can prevent a SWF file from using this method by setting the
 * allowNetworking parameter of the the object and embed
 * tags in the HTML page that contains the SWF content. The fscommand() function is not allowed if the calling SWF file is in
 * the local-with-file-system or local-with-network sandbox and the containing HTML page is in
 * an untrusted sandbox.For more information related to security, see the Flash Player Developer Center Topic:
 * Security.Usage 1: To use fscommand() to send a message to Flash Player, you must use predefined commands and parameters. The
 * following table shows the values that you can specify for the fscommand() function's command and
 * args parameters. These values control SWF files that are playing in Flash Player, including projectors. (A
 * projector is a SWF file saved in a format that can run as a stand-alone application   that is, without Flash Player.)CommandParameter (args)PurposequitNoneCloses the projector.fullscreentrue or falseSpecifying true sets Flash Player to full-screen mode. Specifying
 * false returns the player to normal menu view.allowscaletrue or falseSpecifying false sets the player so that the SWF file is always drawn
 * at its original size and never scaled. Specifying true forces the SWF file to scale to 100% of the
 * player.showmenutrue or falseSpecifying true enables the full set of context menu items. Specifying
 * false hides all of the context menu items except About Flash Player and Settings.execPath to application Executes an application from within the projector.trapallkeystrue or falseSpecifying true sends all key events, including accelerator keys, to
 * the onClipEvent(keyDown/keyUp) handler in Flash Player. Not all of the commands listed in the table are available in all applications:
 * None of the commands are available in web players.All of the commands are available in stand-alone projector applications.AIR applications should use the flash.desktop.NativeApplication class for similar functions, such as
 * NativeApplication.nativeApplication.exit() instead of fscommand("quit").Only allowscale and exec are available in test-movie players.The exec command can contain only the characters A-Z, a-z, 0-9, period (.), and underscore (_). The exec
 * command runs in the subdirectory fscommand only. In other words, if you use the exec command to call an application, the
 * application must reside in a subdirectory named fscommand. The exec command works only from within a Flash projector
 * file.Usage 2: To use fscommand() to send a message to a scripting language such as JavaScript in a web browser, you can
 * pass any two parameters in the command and args parameters. These parameters can be strings or
 * expressions, and they are used in a JavaScript function that handles, or catches, the fscommand() function. In a web browser, fscommand() calls the JavaScript function moviename_DoFScommand, which resides in the
 * web page that contains the SWF file. For moviename, supply the name of the Flash object that you used for the
 * NAME attribute of the EMBED tag or the ID property of the OBJECT tag. If you assign the SWF file
 * the name "myMovie", the JavaScript function myMovie_DoFScommand is called. In the web page that contains the SWF file, set the allowScriptAccess attribute to allow or deny the SWF file's
 * ability to access the web page, as described above. (You set this attribute in the HTML code that embeds the SWF file   for example, in the
 * PARAM tag for Internet Explorer or the EMBED tag for Netscape.) In Flash Player 10 and later running in a browser, using this method programmatically to
 * open a pop-up window may not be successful.  Various browsers (and browser configurations) may block pop-up windows
 * at any time; it is not possible to guarantee any pop-up window will appear.
 * However, for the best chance of success, use this method to open a pop-up window only in code that executes
 * as a direct result of a user action (for example, in an event handler for a mouse click or key-press event.)Usage 3: The fscommand() function can send messages to Director (Macromedia Director from Adobe).
 * These messages are interpreted by Lingo (the Director scripting language) as strings, events, or executable Lingo
 * code. If a message is a string or an event, you must write the Lingo code to receive the message from the
 * fscommand() function and carry out an action in Director. For more information, see the Director Support
 * Center at www.adobe.com/support/director/.Usage 4: In VisualBasic, Visual C++, and other programs that can host ActiveX controls, fscommand() sends a VB event
 * with two strings that can be handled in the environment's programming language. For more information, use the keywords "Flash method"
 * to search the Flash Support Center at www.adobe.com/support/flash/.Note: The ExternalInterface class provides better functionality
 * for communication between JavaScript and ActionScript (Usage 2) and between ActionScript and VisualBasic, Visual C++, or other
 * programs that can host ActiveX controls (Usage 4). You should continue to use fscommand() for sending messages to Flash
 * Player (Usage 1) and Director (Usage 3).
 * @param   command A string passed to the host application for any use, or a command passed to Flash Player.
 * @param   args    A string passed to the host application for any use, or a value passed to Flash Player.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @oldexample  <p class="- topic/p ">In the following example, the <code>fscommand()</code> function sets Flash Player to
 *   scale the SWF file to the full monitor screen size when the <code>fullscreen_btn</code> button or
 *   <code>unfullscreen_btn</code> is released:</p><pre xml:space="preserve" class="- topic/pre ">this.fullscreen_btn.onRelease = function() {
 *   fscommand("fullscreen", true);
 *   };
 *   this.unfullscreen_btn.onRelease = function() {
 *   fscommand("fullscreen", false);
 *   };
 *   </pre><p class="- topic/p ">The following example uses the <code>fscommand()</code> function applied to a button in Flash to
 *   open a JavaScript message box in an HTML page. The message itself is sent to JavaScript as the
 *   <code>fscommand</code> parameter. </p><p class="- topic/p ">You must add a function to the HTML page that contains the SWF file. This function,
 *   <code><i class="+ topic/ph hi-d/i ">myDocument</i></code><code>_DoFSCommand</code>, sits in the HTML page and waits for an
 *   <code>fscommand()</code> function in Flash. When an <code>fscommand</code> is triggered in Flash
 *   (for example, when a user presses the button), the <code>command</code> and <code>args</code> strings
 *   are passed to the <code><i class="+ topic/ph hi-d/i ">myDocument</i></code><code>_DoFSCommand </code>function. You can use the
 *   passed strings in your JavaScript or VBScript code in any way you like. In this example, the function
 *   contains a conditional <code>if</code> statement that checks to see if the command string is
 *   "<code>messagebox</code>". If it is, a JavaScript alert box (or "message box") opens
 *   and displays the contents of the <code>args</code> string.</p><pre xml:space="preserve" class="- topic/pre ">function myDocument_DoFSCommand(command, args) {
 *   if (command == "messagebox") {
 *   alert(args);
 *   }
 *
 *     </pre><p class="- topic/p ">In the Flash document, add the <code>fscommand()</code> function to a button:</p><pre xml:space="preserve" class="- topic/pre ">fscommand("messagebox", "This is a message box called from within Flash.")
 *   </pre><p class="- topic/p ">You can also use expressions for the <code>fscommand()</code> function and parameters, as in the
 *   following example:</p><pre xml:space="preserve" class="- topic/pre ">fscommand("messagebox", "Hello, " + name + ", welcome to our website!")
 *   </pre><p class="- topic/p ">To test the SWF file, select File &gt; Publish Preview &gt; HTML.</p><p class="- topic/p "><strong>Note: </strong>If you publish your SWF file using the Flash with FSCommand template in the
 *   HTML
 *   tab of the Publish Settings dialog box, the <code>myDocument_DoFSCommand</code> function is inserted
 *   automatically. The SWF file's <code>NAME</code> and <code>ID</code> attributes will be the filename.
 *   For example, for the file myDocument.fla, the attributes would be set to <code>myDocument</code>.</p>
 * @throws  Error If the function is not called in response to a user action, such as a mouse
 *   event or keypress event.
 */
public:
void     fscommand(std::string command, std::string args="");
#endif // FLEX11_6_FLASH_SYSTEM_PACKAGE_AS_AS
#endif // __cplusplus

