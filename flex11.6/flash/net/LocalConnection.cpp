

#include "LocalConnection.h"
#include "flash/events/EventDispatcher.h"

    /**
     * Dispatched when a LocalConnection object reports its status.
     * @eventType   flash.events.StatusEvent.STATUS
     */

using namespace flash::events;

namespace flash {
namespace net {


        /**
         * The isSupported property is set to true if the
         * LocalConnection class is supported on the current platform, otherwise it is
         * set to false.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool LocalConnection::isSupported()          ;

        /**
         * A string representing the domain of the location of the current file.
         * 
         *   In content running in the application security sandbox in Adobe AIR (content
         * installed with the AIR application), the runtime uses the string app# followed by the application
         * ID for the AIR application (defined in the application descriptor file) in place of the superdomain.
         * For example a connectionName for an application with the application ID com.example.air.MyAppconnectionName resolves to "app#com.example.air.MyApp:connectionName".In SWF files published for Flash Player 9 or later, the returned string is the exact domain of
         * the file, including subdomains. For example, if the file is located at www.adobe.com, this command
         * returns "www.adobe.com". If the current file is a local file residing on the client computer running in Flash Player,
         * this command returns "localhost".The most common ways to use this property are to include the domain name of the sending
         * LocalConnection object as a parameter to the method you plan to invoke in the receiving
         * LocalConnection object, or to use it with LocalConnection.allowDomain() to accept commands
         * from a specified domain. If you are enabling communication only between LocalConnection objects
         * that are located in the same domain, you probably don't need to use this property.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string LocalConnection::domain()         ;

        /**
         * Indicates the object on which callback methods are invoked. The default object
         * is this, the local connection being created. You can set the
         * client property to another object, and callback methods are
         * invoked on that other object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  TypeError The client property must be set to a non-null object.
         */
        Object* LocalConnection::client()         ;
        void LocalConnection::client(Object* client)       ;

        bool LocalConnection::isPerUser()          ;
        void LocalConnection::isPerUser(bool newValue)       ;

        /**
         * Closes (disconnects) a LocalConnection object. Issue this command when you no longer want the object
         * to accept commands     for example, when you want to issue a connect()
         * command using the same connectionName parameter in another SWF file.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  ArgumentError The LocalConnection instance is not connected, so it cannot be closed.
         */
        void LocalConnection::close()       ;

        /**
         * Prepares a LocalConnection object to receive commands that are sent from a send() command
         * (from the sending LocalConnection object). The object used with the connect() method is
         * called the receiving LocalConnection object. The receiving and sending objects
         * must be running on the same client computer.
         * 
         *   To avoid a race condition, define the methods attached to the
         * receiving LocalConnection object before
         * calling this method, as shown in the LocalConnection class example. By default, the connectionName argument is resolved into a value of
         * "superdomain:connectionName",
         * where superdomain is the superdomain of the file that contains the
         * connect() command. For example, if the file that contains the
         * receiving LocalConnection object is located at www.someDomain.com, connectionName
         * resolves to "someDomain.com:connectionName". (If a file running in Flash Player
         * is located on the client computer, the value assigned to superdomain is
         * "localhost".)In content running in the application security sandbox in Adobe AIR (content
         * installed with the AIR application), the runtime uses the string app# followed by the application
         * ID for the AIR application (defined in the application descriptor file) in place of the superdomain.
         * For example a connectionName for an application with the application ID com.example.air.MyAppconnectionName resolves to "app#com.example.air.MyApp:connectionName".Also by default, Flash Player lets the receiving LocalConnection object accept commands only from
         * sending LocalConnection objects whose connection name also resolves into a value of
         * "superdomain:connectionName". In this way, Flash Player makes
         * it simple for files that are located in the same domain to communicate with each other.If you are implementing communication only between files in the same domain, specify a string
         * for connectionName that does not begin with an underscore (_) and that does not specify
         * a domain name (for example, "myDomain:connectionName"). Use the same string in the
         * connect(connectionName) method.If you are implementing communication between files in different domains, specifying a string
         * for connectionName that begins with an underscore (_) makes the file with the
         * receiving LocalConnection object more portable between domains. Here are the two possible cases:If the string for connectionNamedoes not begin with an underscore (_),
         * a prefix is added with the superdomain and a colon (for example,
         * "myDomain:connectionName"). Although this ensures that your connection does not conflict
         * with connections of the same name from other domains, any sending LocalConnection objects must
         * specify this superdomain (for example, "myDomain:connectionName").
         * If the file with the receiving LocalConnection object is moved to another domain, the player changes
         * the prefix to reflect the new superdomain (for example, "anotherDomain:connectionName").
         * All sending LocalConnection objects would have to be manually edited to point to the new superdomain.If the string for connectionNamebegins with an underscore (for example,
         * "_connectionName"), a prefix is not added to the string. This means that
         * the receiving and sending LocalConnection objects use identical strings for
         * connectionName. If the receiving object uses allowDomain()
         * to specify that connections from any domain will be accepted, the file with the receiving LocalConnection
         * object can be moved to another domain without altering any sending LocalConnection objects.For more information, see the discussion in the class overview and the discussion
         * of connectionName in send(), and also
         * the allowDomain() and domain entries.Note: Colons are used as special characters to separate the superdomain from the
         * connectionName string. A string for connectionName that contains a colon is
         * not valid.When you use this method , consider the Flash Player
         * security model. By default, a LocalConnection object
         * is associated with the sandbox of the  file that created it, and cross-domain calls to LocalConnection
         * objects are not allowed unless you call the LocalConnection.allowDomain() method in the
         * receiving file. You can prevent a file from using this method by setting the
         * allowNetworking parameter of the the object and embed
         * tags in the HTML page that contains the SWF content. However, in Adobe AIR,
         * content in the application security sandbox (content installed with the AIR application)
         * are not restricted by these security limitations.For more information related to security, see the Flash Player Developer Center Topic:
         * Security.
         * @param   connectionName  A string that corresponds to the connection name specified in the
         *   send() command that wants to communicate with the receiving LocalConnection object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  TypeError The value passed to the connectionName parameter must be non-null.
         * @throws  ArgumentError This error can occur for three reasons: 1) The string value passed to the connectionName parameter
         *   was null. Pass a non-null value. 2) The value passed to the connectionName parameter
         *   contained a colon (:). Colons are used as special characters to separate the superdomain
         *   from the connectionName string in the send() method, not the
         *   connect()method. 3) The LocalConnection instance is already connected.
         */
        void LocalConnection::connect(std::string connectionName)       ;

        /**
         * Creates a LocalConnection object. You can use LocalConnection objects to enable
         * communication between different files that are running on the same client computer.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @oldexample  The following example shows how receiving and sending files create LocalConnnection objects.
         *   The two files can use the same name or different names for their respective LocalConnection objects.
         *   In this example they use different names.
         *   
         *     <listing>
         *   // Code in the receiving file
         *   this.createTextField("result_txt", 1, 10, 10, 100, 22);
         *   result_txt.border = true;
         *   var receiving_lc:LocalConnection = new LocalConnection();
         *   receiving_lc.methodToExecute = function(param1:Number, param2:Number) {
         *   result_txt.text = param1+param2;
         *   };
         *   receiving_lc.connect("lc_name");
         *   </listing><p class="- topic/p ">The following file sends the request to the first file.</p><listing>
         *   // Code in the sending file
         *   var sending_lc:LocalConnection = new LocalConnection();
         *   sending_lc.send("lc_name", "methodToExecute", 5, 7);
         *   </listing>
         */
        LocalConnection::LocalConnection();

        /**
         * Invokes the method named methodName on a connection that was opened with the
         * connect(connectionName) method (in the receiving LocalConnection
         * object). The object used with the send() method is called the sending LocalConnection object.
         * The SWF files that contain the sending and receiving objects must be running on the same client computer.
         * 
         *   There is a 40 kilobyte limit to the amount of data you can pass as parameters to this command.
         * If send() throws an ArgumentError but your syntax is correct, try dividing the
         * send() requests into multiple commands, each with less than 40K of data.As discussed in the connect() entry, the current superdomain in added to
         * connectionName by default. If you are implementing communication between different domains,
         * you need to define connectionName in both the sending and receiving LocalConnection
         * objects in such a way that the current superdomain is not added to connectionName.
         * You can do this in one of the following two ways:Use an underscore (_) at the beginning of connectionName in both the sending and
         * receiving LocalConnection objects. In the file that contains the receiving object, use
         * LocalConnection.allowDomain() to specify that connections from any domain will be accepted.
         * This implementation lets you store your sending and receiving files in any domain.Include the superdomain in connectionName in the sending LocalConnection
         * object     for example, myDomain.com:myConnectionName. In the receiving object, use
         * LocalConnection.allowDomain() to specify that connections from the specified superdomain
         * will be accepted (in this case, myDomain.com) or that connections from any domain will be accepted.Note: You cannot specify a superdomain in connectionName in the receiving
         * LocalConnection object     you can do this in only the sending LocalConnection object.When you use this method , consider the Flash Player
         * security model. By default, a LocalConnection object
         * is associated with the sandbox of the file that created it, and cross-domain calls to LocalConnection
         * objects are not allowed unless you call the LocalConnection.allowDomain() method in the
         * receiving file.  For SWF content running in the browser, ou can prevent a file from using this method by setting the
         * allowNetworking parameter of the the object and embed
         * tags in the HTML page that contains the SWF content. However, in Adobe AIR, content in the
         * application security sandbox (content installed with the AIR application) are not
         * restricted by these security limitations.For more information related to security, see the Flash Player Developer Center Topic:
         * Security.
         * @param   connectionName  Corresponds to the connection name specified in the connect() command
         *   that wants to communicate with the sending LocalConnection object.
         * @param   methodName  The name of the method to be invoked in the receiving LocalConnection object. The
         *   following method names cause the command to fail: send, connect,
         *   close, allowDomain, allowInsecureDomain,
         *   client, and domain.
         * @param   arguments   Additional optional parameters to be passed to the specified method.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  TypeError The value of either connectionName or methodName
         *   is null. Pass non-null values for these parameters.
         * @throws  ArgumentError This error can occur for one of the following reasons:
         *   1) The value of either connectionName or methodName
         *   is an empty string. Pass valid strings for these parameters.
         *   2) The method specified in methodName is restricted.
         *   3) The serialized message that is being sent is too large (larger than 40K).
         */
        void LocalConnection::send(std::string connectionName, std::string methodName, ...)       ;

        /**
         * Specifies one or more domains that can send LocalConnection calls to this LocalConnection instance.
         * 
         *   You cannot use this method to let files hosted using a secure protocol (HTTPS) allow access from
         * files hosted in nonsecure protocols; you must use the allowInsecureDomain() method instead.You may want to use this method so that a child file from a different domain can make LocalConnection
         * calls to the parent file, without knowing the final domain from which the child file will come.
         * This can happen, for example, when you use load-balancing redirects or third-party servers. In this situation,
         * you can use the url property of the LoaderInfo object used with the load, to get the domain to use with
         * the allowDomain() method. For example, if you use a Loader object to load a child file, once the file
         * is loaded, you can check the contentLoaderInfo.url property of the Loader object, and parse the domain
         * out of the full URL string. If you do this, make sure that you wait until the file is loaded, because the
         * contentLoaderInfo.url property will not have its final, correct value until the file is completely loaded. The opposite situation can also occur: you might create a child file that wants to accept LocalConnection
         * calls from its parent but doesn't know the domain of its parent. In this situation, implement this method by
         * checking whether the domain argument matches the domain of the loaderInfo.url property in the
         * loaded file. Again, you must parse the domain out of the full URL from loaderInfo.url.
         * In this situation, you don't have to wait for the parent file to load; the parent will already be loaded
         * by the time the child loads.When using this method, consider the Flash Player security model. By default, a LocalConnection object
         * is associated with the sandbox of the file that created it, and cross-domain calls to LocalConnection
         * objects are not allowed unless you call the LocalConnection.allowDomain() method in the
         * receiving file. However, in Adobe AIR, content in the application security sandbox
         * (content installed with the AIR application) are not restricted by these security limitations.For more information related to security, see the Flash Player Developer Center Topic:
         * Security.Note: The allowDomain() method has changed
         * from the form it had in ActionScript 1.0 and 2.0.  In those earlier versions,
         * allowDomain was a callback method that you
         * implemented.  In ActionScript 3.0, allowDomain() is a built-in
         * method of LocalConnection that you call.  With this change, allowDomain()
         * works in much the same way as flash.system.Security.allowDomain().
         * @param   domains One or more strings that name the domains from which
         *   you want to allow LocalConnection calls. This parameter has two special cases:
         *   
         *     You can specify a wildcard character "~~" to allow calls from all domains.You can specify the string "localhost" to allow calls to this file from files that
         *   are installed locally. Flash Player 8 introduced security restrictions
         *   on local files. By default, a SWF file running in Flash Player
         *   that is allowed to access the Internet cannot also have access to the local file system.
         *   In Flash Player, if you specify "localhost", any local SWF file can access this
         *   SWF file.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    Change the first example in the listing.
         * @throws  ArgumentError All parameters specified must be non-null strings.
         */
        void LocalConnection::allowDomain(...)       ;

        /**
         * Specifies one or more domains that can send LocalConnection calls to this LocalConnection object.
         * 
         *   The allowInsecureDomain() method works just like the allowDomain() method,
         * except that the allowInsecureDomain() method additionally permits SWF files
         * from non-HTTPS origins to send LocalConnection calls to files from HTTPS origins.  This difference
         * is meaningful only if you call the allowInsecureDomain() method from a
         * file that was loaded using HTTPS.  You must call the allowInsecureDomain() method even
         * if you are crossing a non-HTTPS/HTTPS boundary within the same domain; by default, LocalConnection calls
         * are never permitted from non-HTTPS files to HTTPS files, even within the same domain.Calling allowInsecureDomain() is not recommended,
         * because it can compromise the security offered by HTTPS.  When you
         * load a file over HTTPS, you can be reasonably sure that the file
         * will not be tampered with during delivery over the network.  If you
         * then permit a non-HTTPS file to make LocalConnection calls to the
         * HTTPS file, you are accepting calls from a file that may in fact have
         * been tampered with during delivery.  This generally requires extra
         * vigilance because you cannot trust the authenticity of LocalConnection
         * calls arriving at your HTTPS file.By default, files hosted using the HTTPS protocol can be accessed only by other files hosted
         * using the HTTPS protocol. This implementation maintains the integrity provided by the HTTPS protocol.Using this method to override the default behavior is not recommended, because it compromises HTTPS security.
         * However, you might need to do so, for example, if you need to permit access to HTTPS SWF files published for
         * Flash Player 9 or later from HTTP files SWF published for Flash Player 6 or earlier.For more information related to security, see the Flash Player Developer Center Topic:
         * Security.
         * @param   domains One or more strings that name the domains from which
         *   you want to allow LocalConnection calls. There are two special cases
         *   for this parameter:
         *   You can specify the wildcard character "~~" to allow calls from all domains.
         *   Specifying "~~" does not include local hosts.You can specify the string "localhost" to allow calls to this SWF file from SWF files that
         *   are installed locally. Flash Player 8 introduced security restrictions on local SWF files. A SWF file
         *   that is allowed to access the Internet cannot also have access to the local file system. If you
         *   specify "localhost", any local SWF file can access this SWF file. Remember that you must also
         *   designate the calling SWF file as a local-with-networking SWF file at authoring time.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    Seems like a security note is in order here.
         * @throws  ArgumentError All parameters specified must be non-null strings.
         */
        void LocalConnection::allowInsecureDomain(...)       ;
}
}

