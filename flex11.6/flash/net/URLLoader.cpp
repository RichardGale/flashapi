

#include "URLLoader.h"
#include "flash/events/EventDispatcher.h"
#include "flash/net/URLStream.h"
#include "flash/net/URLRequest.h"
#include "flash/events/Event.h"
#include "flash/events/ProgressEvent.h"

    /**
     * Dispatched if a call to the load() method attempts to access data over HTTP,
     * and Adobe AIR is able to detect and return the status code for the request.
     * @eventType   flash.events.HTTPStatusEvent.HTTP_RESPONSE_STATUS
     */

using namespace flash::events;
using namespace flash::net;

namespace flash {
namespace net {


        /**
         * The data received from the load operation. This property
         * is populated only when the load operation is complete.
         * The format of the data depends on the setting of the
         * dataFormat property:
         * 
         *   If the dataFormat property is URLLoaderDataFormat.TEXT,
         * the received data is a string containing the text of the loaded file.If the dataFormat property is URLLoaderDataFormat.BINARY,
         * the received data is a ByteArray object containing the raw binary data.If the dataFormat property is URLLoaderDataFormat.VARIABLES,
         * the received data is a URLVariables object containing the URL-encoded variables.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
                   

        /**
         * Controls whether the downloaded data is received as
         * text (URLLoaderDataFormat.TEXT), raw binary data
         * (URLLoaderDataFormat.BINARY), or URL-encoded variables
         * (URLLoaderDataFormat.VARIABLES).
         * 
         *   If the value of the dataFormat property is URLLoaderDataFormat.TEXT,
         * the received data is a string containing the text of the loaded file.If the value of the dataFormat property is URLLoaderDataFormat.BINARY,
         * the received data is a ByteArray object containing the raw binary data.If the value of the dataFormat property is URLLoaderDataFormat.VARIABLES,
         * the received data is a URLVariables object containing the URL-encoded variables.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
                   

        /**
         * Indicates the number of bytes that have been loaded thus far
         * during the load operation.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
                   

        /**
         * Indicates the total number of bytes in the downloaded data.
         * This property contains 0 while the load operation is in progress
         * and is populated when the operation is complete.
         * Also, a missing Content-Length header will result in bytesTotal being indeterminate.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
                   

        /**
         * Registers an event listener object with an EventDispatcher object so that the listener 
         * receives notification of an event. You can register event listeners on all nodes in the 
         * display list for a specific type of event, phase, and priority.After you successfully register an event listener, you cannot change its priority
         * through additional calls to addEventListener(). To change a listener's
         * priority, you must first call removeListener(). Then you can register the
         * listener again with the new priority level. Keep in mind that after the listener is registered, subsequent calls to
         * addEventListener() with a different type or
         * useCapture value result in the creation of a separate listener registration. 
         * For example, if you first register a listener with useCapture set to 
         * true, it listens only during the capture phase. If you call 
         * addEventListener() again using the same listener object, but with
         * useCapture set to false, you have two separate listeners: one
         * that listens during the capture phase and another that listens during the target and
         * bubbling phases.You cannot register an event listener for only the target phase or the bubbling 
         * phase. Those phases are coupled during registration because bubbling 
         * applies only to the ancestors of the target node.If you no longer need an event listener, remove it by calling 
         * removeEventListener(), or memory problems could result. Event listeners are not automatically
         * removed from memory because the garbage
         * collector does not remove the listener as long as the dispatching object exists (unless the useWeakReference
         * parameter is set to true).Copying an EventDispatcher instance does not copy the event listeners attached to it. 
         * (If your newly created node needs an event listener, you must attach the listener after
         * creating the node.) However, if you move an EventDispatcher instance, the event listeners 
         * attached to it move along with it.If the event listener is being registered on a node while an event is being processed
         * on this node, the event listener is not triggered during the current phase but can be 
         * triggered during a later phase in the event flow, such as the bubbling phase.If an event listener is removed from a node while an event is being processed on the node,
         * it is still triggered by the current actions. After it is removed, the event listener is
         * never invoked again (unless registered again for future processing).
         * @param   type    The type of event.
         * @param   listener    The listener function that processes the event. This function must accept
         *   an Event object as its only parameter and must return nothing, as this example shows:
         *   <codeblock>
         *   function(evt:Event):void
         *   </codeblock>
         *   The function can have any name.
         * @param   useCapture  Determines whether the listener works in the capture phase or the 
         *   target and bubbling phases. If useCapture is set to true, 
         *   the listener processes the event only during the capture phase and not in the 
         *   target or bubbling phase. If useCapture is false, the
         *   listener processes the event only during the target or bubbling phase. To listen for
         *   the event in all three phases, call addEventListener twice, once with 
         *   useCapture set to true, then again with
         *   useCapture set to false.
         * @param   priority    The priority level of the event listener. The priority is designated by
         *   a signed 32-bit integer. The higher the number, the higher the priority. All listeners
         *   with priority n are processed before listeners of priority n-1. If two
         *   or more listeners share the same priority, they are processed in the order in which they
         *   were added. The default priority is 0.
         * @param   useWeakReference    Determines whether the reference to the listener is strong or
         *   weak. A strong reference (the default) prevents your listener from being garbage-collected.
         *   A weak reference does not. Class-level member functions are not subject to garbage 
         *   collection, so you can set useWeakReference to true for 
         *   class-level member functions without subjecting them to garbage collection. If you set
         *   useWeakReference to true for a listener that is a nested inner 
         *   function, the function will be garbage-collected and no longer persistent. If you create 
         *   references to the inner function (save it in another variable) then it is not 
         *   garbage-collected and stays persistent.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void URLLoader::addEventListener(std::string type, Function* listener, bool useCapture, int priority, bool useWeakReference)       ;

        /**
         * Sends and loads data from the specified URL. The data can be received as
         * text, raw binary data, or URL-encoded variables, depending on the
         * value you set for the dataFormat property. Note that
         * the default value of the dataFormat property is text.
         * If you want to send data to the specified URL, you can set the data
         * property in the URLRequest object.
         * 
         *   Note: If a file being loaded contains non-ASCII characters (as found
         * in many non-English languages), it is recommended that you save the
         * file with UTF-8 or UTF-16 encoding as opposed to a non-Unicode format
         * like ASCII. A SWF file in the local-with-filesystem sandbox may not load data from,
         * or provide data to, a resource that is in the network sandbox. By default, the calling SWF file and the URL you load must be in exactly the same domain.
         * For example, a SWF file at www.adobe.com can load data only from sources that are also at www.adobe.com.
         * To load data from a different domain, place a URL policy file on the server hosting the data.You cannot connect to commonly reserved ports.
         * For a complete list of blocked ports, see "Restricting Networking APIs" in the
         * ActionScript 3.0 Developer's Guide. In Flash Player 10 and later, if you use a multipart Content-Type (for example "multipart/form-data")
         * that contains an upload (indicated by a "filename" parameter in a "content-disposition" header within the POST body),
         * the POST operation is subject to the security rules applied to uploads:The POST operation must be performed in response to a user-initiated action, such as a mouse click or key press.If the POST operation is cross-domain (the POST target is not on the same server as the SWF file
         * that is sending the POST request),
         * the target server must provide a URL policy file that permits cross-domain access.Also, for any multipart Content-Type, the syntax must be valid (according to the RFC2046 standards).
         * If the syntax appears to be invalid, the POST operation is subject to the security rules applied to uploads.For more information related to security, see the Flash Player Developer Center Topic:
         * Security.
         * @param   request A URLRequest object specifying the URL to download.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  ArgumentError URLRequest.requestHeader objects may not
         *   contain certain prohibited HTTP request headers. For more information,
         *   see the URLRequestHeader class description.
         * @throws  MemoryError This error can occur for the following reasons:
         *   1) Flash Player or AIR cannot
         *   convert the URLRequest.data
         *   parameter from UTF8 to MBCS. This error is applicable if the URLRequest object
         *   passed to load() is set to perform a GET operation and
         *   if System.useCodePage is set to true.
         *   2) Flash Player or AIR cannot
         *   allocate memory for the POST data. This error is
         *   
         *     applicable if the URLRequest object passed to load is set
         *   to perform a POST operation.
         * @throws  SecurityError Local untrusted files may not communicate with
         *   the Internet. This may be worked around by reclassifying this file
         *   as local-with-networking or trusted.
         * @throws  SecurityError You are trying to connect to a commonly reserved port.
         *   For a complete list of blocked ports, see "Restricting Networking APIs" in the
         *   ActionScript 3.0 Developer's Guide.
         * @throws  TypeError The value of the request parameter
         *   or the URLRequest.url property of the URLRequest object passed are
         *   null.
         */
        void URLLoader::load(URLRequest* request)       ;

        /**
         * Closes the load operation in progress.  Any load
         * operation in progress is immediately terminated.
         * If no URL is currently being streamed, an invalid stream error is thrown.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void URLLoader::close()       ;

        /**
         * Creates a URLLoader object.
         * @param   request A URLRequest object specifying
         *   the URL to download.  If this parameter is omitted,
         *   no load operation begins.  If
         *   specified, the load operation begins
         *   immediately (see the load entry for more information).
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        URLLoader::URLLoader(URLRequest* request);
}
}

