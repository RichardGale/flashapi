

#include "package.as.h"
#include "flash/net/URLRequest.h"

    /**
     * Preserves the class (type) of an object when the object is encoded in Action Message Format (AMF).
     * When you encode an object into AMF, this function saves the alias for its class, so that you can 
     * recover the class when decoding the object.
     * If the encoding context did not register an alias for an object's class, the object
     * is encoded as an anonymous object. Similarly, if the decoding context does not have the same
     * alias registered, an anonymous object is created for the decoded data.
     * 
     *   LocalConnection, ByteArray, SharedObject, NetConnection and NetStream are all examples
     * of classes that encode objects in AMF.The encoding and decoding contexts do not need to use the same class for an alias;
     * they can intentionally change classes, provided that the destination class contains all of the members
     * that the source class serializes.
     * @param   aliasName   The alias to use.
     * @param   classObject The class associated with the given alias.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     * @throws  TypeError If either parameter is null.
     */
    void ::registerClassAlias(std::string aliasName, Class* classObject)       ;
    /**
     * Looks up a class that previously had an alias registered through a call to the registerClassAlias()
     * method.
     * This method does not interact with the flash.utils.getDefinitionByName() 
     * method.
     * @param   aliasName   The alias to find.
     * @return  The class associated with the given alias. If not found, an exception will be thrown.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     * @internal    includeExample examples\GetClassByAliasExample.as -noswf
     * @throws  ReferenceError The alias was not registered.
     */
    Class* ::getClassByAlias(std::string aliasName)        ;
    /**
     * Opens or replaces a window in the application that contains the Flash Player container
     * (usually a browser). In Adobe AIR, the function opens a URL in the default system web browserImportant Security Note  Developers often pass URL values to the navigateToURL() function that were obtained from external sources 
     * such as FlashVars.  Attackers may try to manipulate these external sources to perform attacks such as cross-site scripting. 
     * Therefore, developers should validate all URLs before passing them to this function. Good data validation for URLs can mean different things depending on the usage of the URL within the overall application.  
     * The most common data validation techniques include validating that the URL is of the appropriate scheme.  
     * For instance, unintentionally allowing javascript: URLs may result in cross-site scripting.  
     * Validating that the URL is a within your domain can ensure that the SWF file can't be used as an open-redirector 
     * by people who conduct phishing attacks.  For additional security, you may also choose to validate the path of the URL 
     * and to validate that the URL conforms to the RFC guidelinesFor example, the following code shows a simple example of performing data validation by denying any URL 
     * that does not begin with http:// or https:// and validating that the URL is within your domain name.  
     * This example may not be appropriate for all web applications and you should consider whether additional checks 
     * against the URL are necessary. 
     * <codeblock>
     * 
     *   // Regular expression pattern match for URLs that start with http:// and https:// plus your domain name.
     * function checkProtocol (flashVarURL:String):Boolean {
     * // Get the domain name for the SWF if it is not known at compile time.
     * // If the domain is known at compile time, then the following two lines can be replaced with a hard coded string.
     * var my_lc:LocalConnection = new LocalConnection();
     * var domainName:String = my_lc.domain;
     * // Build the RegEx to test the URL.
     * // This RegEx assumes that there is at least one "/" after the
     * // domain. http://www.mysite.com will not match.
     * var pattern:RegExp = new RegExp("^http[s]?\:\\/\\/([^\\/]+)\\/");
     * var result:Object = pattern.exec(flashVarURL);
     * if (result == null || result[1] != domainName || flashVarURL.length >= 4096) {
     * return (false);
     * }
     * return (true);
     * }
     * 
     *   </codeblock>
     * For local content running in a browser, calls to the 
     * navigateToURL() method that specify a "javascript:" pseudo-protocol 
     * (via a URLRequest object passed as the first parameter) are only permitted if the SWF 
     * file and the containing web page (if there is one) are in the local-trusted security sandbox.
     * Some browsers do not support using the javascript protocol with the navigateToURL()
     * method. Instead, consider using the call() method of the ExternalInterface
     * API to invoke JavaScript methods within the enclosing HTML page.In Flash Player, and in non-application sandboxes in Adobe AIR, 
     * you cannot connect to commonly reserved ports. 
     * For a complete list of blocked ports, see "Restricting Networking APIs" in the 
     * ActionScript 3.0 Developer's Guide.In Flash Player 10 and later running in a browser, using this method programmatically to
     * open a pop-up window may not be successful.  Various browsers (and browser configurations) may block pop-up windows 
     * at any time; it is not possible to guarantee any pop-up window will appear.  
     * However, for the best chance of success, use this method to open a pop-up window only in code that executes 
     * as a direct result of a user action (for example, in an event handler for a mouse click or key-press event.) In Flash Player 10 and later, if you use a multipart Content-Type (for example "multipart/form-data") 
     * that contains an upload (indicated by a "filename" parameter in a "content-disposition" header within the POST body),
     * the POST operation is subject to the security rules applied to uploads:The POST operation must be performed in response to a user-initiated action, such as a mouse click or key press.If the POST operation is cross-domain (the POST target is not on the same server as the SWF file 
     * that is sending the POST request),
     * the target server must provide a URL policy file that permits cross-domain access.Also, for any multipart Content-Type, the syntax must be valid (according to the RFC2046 standards).
     * If the syntax appears to be invalid, the POST operation is subject to the security rules applied to uploads.In AIR, on mobile platforms, the sms: and tel: URI schemes are supported. On Android, vipaccess:, connectpro:, and market: URI schemes are supported.
     * The URL syntax is subject to the platform conventions. For example, on Android, the URI scheme must be lower case.
     * When you navigate to a URL using one of these schemes, the runtime opens the URL in the default application for 
     * handling the scheme. Thus, navigating to tel:+5555555555 opens the phone dialer with the specified
     * number already entered. A separate application or utility, such as a phone dialer must be available to process the URL.The following code shows how you can invoke the VIP Access and Connect Pro applications on Android:
     * <codeblock>
     * 
     *   //Invoke the VIP Access Application.
     * navigateToURL(new URLRequest("vipaccess://com.verisign.mvip.main?action=securitycode"));
     * 
     *   //Invoke the Connect Pro Application.
     * navigateToURL(new URLRequest("connectpro://"));
     * 
     *   </codeblock>
     * @param   request A URLRequest object that specifies the URL to navigate to.
     *   
     *     For content running in Adobe AIR, when 
     *   using the navigateToURL() function, the runtime treats a URLRequest that uses the POST
     *   method (one that has its method property set to URLRequestMethod.POST)
     *   as using the GET method.
     * @param   window  The browser window or HTML frame in which to display
     *   the document indicated by the request parameter.
     *   You can enter the name of a specific window or use one of the following values:
     *   "_self" specifies the current frame in the current window."_blank" specifies a new window."_parent" specifies the parent of the current frame."_top" specifies the top-level frame in the current window.If you do not specify a value for this parameter, a new empty window is created.
     *   In the stand-alone player, you can either specify a new ("_blank") window
     *   or a named window. The other values don't apply.Note: When code in a SWF file that is running in the 
     *   local-with-filesystem sandbox calls the navigateToURL() 
     *   function and specifies a custom window name for the window 
     *   parameter, the window name is transfered into a random name. The name is in 
     *   the form "_flashXXXXXXXX", where each X represents a random 
     *   hexadecimal digit. Within the same session (until you close the containing 
     *   browser window), if you call the function again and specify the same name for 
     *   the window parameter, the same random string is used.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     * @internal    throws IOError The "digest" and "importToSandbox" properties of URLRequest
     *   are not supported by URLLoader.navigate.
     * @throws  IOError The digest property of the request object is not 
     *   null. You should only set the digest property of a URLRequest object
     *   for use calling the URLLoader.load() method when loading a SWZ file (an Adobe 
     *   platform component).
     * @throws  SecurityError In Flash Player (and in non-application sandbox content in Adobe AIR), 
     *   this error is thrown in the following situations:
     *   Local untrusted SWF files may not communicate with
     *   the Internet. You can avoid this situation by reclassifying this SWF file
     *   as local-with-networking or trusted.A navigate operation attempted to evaluate a scripting
     *   pseudo-URL, but the containing document (usually an HTML document in a
     *   browser) is from a sandbox to which you do not have access.  You can avoid this situation 
     *   by specifying allowScriptAccess="always" in the containing
     *   document.You cannot navigate the special windows 
     *   "_self", "_top", or "_parent"
     *   if your SWF file is contained by an HTML page
     *   that has set the allowScriptAccess to 
     *   "none", or to "sameDomain" 
     *   when the domains of the HTML file and the SWF file do not match.You cannot navigate a window with a nondefault name
     *   from within a SWF file that is in the local-with-filesystem sandbox.You cannot connect to commonly reserved ports. 
     *   For a complete list of blocked ports, see "Restricting Networking APIs" in the 
     *   ActionScript 3.0 Developer's Guide.
     * @throws  Error If the method is not called in response to a user action, such as a mouse
     *   event or keypress event. This requirement only applies to content in Flash Player and 
     *   to non-application sandbox content in Adobe AIR.
     */
    void ::navigateToURL(URLRequest* request, std::string window)       ;
    /**
     * Sends a URL request to a server, but ignores any response.
     * To examine the server response, use the URLLoader.load() method instead.You cannot connect to commonly reserved ports. 
     * For a complete list of blocked ports, see "Restricting Networking APIs" in the 
     * ActionScript 3.0 Developer's Guide.You can prevent a SWF file from using this method by setting the 
     * allowNetworking parameter of the the object and embed 
     * tags in the HTML page that contains the SWF content. In Flash Player 10 and later, if you use a multipart Content-Type (for example "multipart/form-data") 
     * that contains an upload (indicated by a "filename" parameter in a "content-disposition" header within the POST body),
     * the POST operation is subject to the security rules applied to uploads:The POST operation must be performed in response to a user-initiated action, such as a mouse click or key press.If the POST operation is cross-domain (the POST target is not on the same server as the SWF file 
     * that is sending the POST request),
     * the target server must provide a URL policy file that permits cross-domain access.Also, for any multipart Content-Type, the syntax must be valid (according to the RFC2046 standards).
     * If the syntax appears to be invalid, the POST operation is subject to the security rules applied to uploads.For more information related to security, see the Flash Player Developer Center Topic: 
     * Security.
     * @param   request A URLRequest object specifying the URL to send data to.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     * @internal    throws IOError The "digest" and "importToSandbox" properties of URLRequest
     *   are not supported by URLLoader.send.
     * @throws  SecurityError Local untrusted SWF files cannot communicate with
     *   the Internet. You can avoid this situation by reclassifying this SWF file
     *   as local-with-networking or trusted.
     * @throws  SecurityError You cannot connect to commonly reserved ports. 
     *   For a complete list of blocked ports, see "Restricting Networking APIs" in the 
     *   ActionScript 3.0 Developer's Guide.
     */
    void ::sendToURL(URLRequest* request)       ;
