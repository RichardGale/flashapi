#if !defined(FLEX11_6_FLASH_NET_URLLOADER_AS)
#define FLEX11_6_FLASH_NET_URLLOADER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace net
    {
        class URLStream;
    }
}
namespace flash
{
    namespace net
    {
        class URLRequest;
    }
}
namespace flash
{
    namespace events
    {
        class Event;
    }
}
namespace flash
{
    namespace events
    {
        class ProgressEvent;
    }
}

/**
 * Dispatched if a call to the load() method attempts to access data over HTTP,
 * and Adobe AIR is able to detect and return the status code for the request.
 * @eventType   flash.events.HTTPStatusEvent.HTTP_RESPONSE_STATUS
 */
//[Event(name="httpResponseStatus",type="flash.events.HTTPStatusEvent")]

/**
 * Dispatched if a call to URLLoader.load()
 * attempts to access data over HTTP.
 * @eventType   flash.events.HTTPStatusEvent.HTTP_STATUS
 */
//[Event(name="httpStatus",type="flash.events.HTTPStatusEvent")]

/**
 * Dispatched if a call to URLLoader.load()
 * attempts to load data from a server outside the security sandbox.
 * @eventType   flash.events.SecurityErrorEvent.SECURITY_ERROR
 */
//[Event(name="securityError",type="flash.events.SecurityErrorEvent")]

/**
 * Dispatched if a call to URLLoader.load()
 * results in a fatal error that terminates the download.
 * @eventType   flash.events.IOErrorEvent.IO_ERROR
 */
//[Event(name="ioError",type="flash.events.IOErrorEvent")]

/**
 * Dispatched when data is received as the download operation progresses.
 * @eventType   flash.events.ProgressEvent.PROGRESS
 */
//[Event(name="progress",type="flash.events.ProgressEvent")]

/**
 * Dispatched after all the received data is decoded and
 * placed in the data property of the URLLoader object.
 * @eventType   flash.events.Event.COMPLETE
 */
//[Event(name="complete",type="flash.events.Event")]

/**
 * Dispatched when the download operation commences following
 * a call to the URLLoader.load() method.
 * @eventType   flash.events.Event.OPEN
 */
//[Event(name="open",type="flash.events.Event")]

using namespace flash::events;
using namespace flash::net;

namespace flash
{
    namespace net
    {
        /**
         * The URLLoader class downloads data from a URL
         * as text, binary data, or URL-encoded variables. It is useful for downloading
         * text files, XML, or other information to be used in a
         * dynamic, data-driven application.
         *
         *   <p class="- topic/p ">A URLLoader object downloads all of the data from a URL before
         * making it available to code in the applications. It sends out
         * notifications about the progress of the download, which you can monitor
         * through the <codeph class="+ topic/ph pr-d/codeph ">bytesLoaded</codeph> and <codeph class="+ topic/ph pr-d/codeph ">bytesTotal</codeph> properties,
         * as well as through dispatched events.</p><p class="- topic/p ">When loading very large video files, such as FLV's, out-of-memory errors may occur.
         * </p><p class="- topic/p ">When you use this class <ph class="- topic/ph ">in Flash Player and</ph> in
         * AIR application content in security sandboxes other than then application security sandbox,
         * consider the following security model:</p><ul class="- topic/ul "><li class="- topic/li ">A SWF file in the local-with-filesystem sandbox may not load data from,
         * or provide data to, a resource that is in the network sandbox. </li><li class="- topic/li "> By default, the calling SWF file and the URL you load must be in exactly the same domain.
         * For example, a SWF file at www.adobe.com can load data only from sources that are also at www.adobe.com.
         * To load data from a different domain, place a URL policy file on the server hosting the data.</li></ul><p class="- topic/p ">For more information related to security, see the Flash Player Developer Center Topic:
         * <xref href="http://www.adobe.com/go/devnet_security_en" scope="external" class="- topic/xref ">Security</xref>.</p>
         *
         *   EXAMPLE:
         *
         *   The following example loads and displays the
         * data found in a local text file. It also traces event handling information.
         *
         *   <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> To run this example, put a file named urlLoaderExample.txt
         * in the same directory as your SWF file. That file should only contain the following line of text:
         * <codeph class="+ topic/ph pr-d/codeph ">answer=42&amp;question=unknown</codeph></p><p class="- topic/p ">The example code does the following:</p><ol class="- topic/ol "><li class="- topic/li ">The constructor function creates a URLLoader instance named <codeph class="+ topic/ph pr-d/codeph ">loader</codeph> and a URLRequest
         * instance named <codeph class="+ topic/ph pr-d/codeph ">request</codeph>, which contains the location and name of the file to be loaded.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">loader</codeph> object is passed to the <codeph class="+ topic/ph pr-d/codeph ">configureListeners()</codeph> method,
         * which adds listeners for each of the supported URLLoader events.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">request</codeph> object is then passed to <codeph class="+ topic/ph pr-d/codeph ">loader.load()</codeph>, which loads the text file.</li><li class="- topic/li ">When the URLLoader has finished loading the text file the <codeph class="+ topic/ph pr-d/codeph ">Event.COMPLETE event</codeph> fires,
         * triggering the <codeph class="+ topic/ph pr-d/codeph ">completeHandler()</codeph> method. The <codeph class="+ topic/ph pr-d/codeph ">completeHandler()</codeph> method creates a
         * URLVariables object from the text loaded from the file. The URLVariables object converts URL-encoded
         * name/value pairs into ActionScript properties to make it easier to manipulate the loaded data.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         *
         *   package {
         * import flash.display.Sprite;
         * import flash.events.*;
         * import flash.net.*;
         *
         *   public class URLLoaderExample extends Sprite {
         * public function URLLoaderExample() {
         * var loader:URLLoader = new URLLoader();
         * configureListeners(loader);
         *
         *   var request:URLRequest = new URLRequest("urlLoaderExample.txt");
         * try {
         * loader.load(request);
         * } catch (error:Error) {
         * trace("Unable to load requested document.");
         * }
         * }
         *
         *   private function configureListeners(dispatcher:IEventDispatcher):void {
         * dispatcher.addEventListener(Event.COMPLETE, completeHandler);
         * dispatcher.addEventListener(Event.OPEN, openHandler);
         * dispatcher.addEventListener(ProgressEvent.PROGRESS, progressHandler);
         * dispatcher.addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);
         * dispatcher.addEventListener(HTTPStatusEvent.HTTP_STATUS, httpStatusHandler);
         * dispatcher.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
         * }
         *
         *   private function completeHandler(event:Event):void {
         * var loader:URLLoader = URLLoader(event.target);
         * trace("completeHandler: " + loader.data);
         *
         *   var vars:URLVariables = new URLVariables(loader.data);
         * trace("The answer is " + vars.answer);
         * }
         *
         *   private function openHandler(event:Event):void {
         * trace("openHandler: " + event);
         * }
         *
         *   private function progressHandler(event:ProgressEvent):void {
         * trace("progressHandler loaded:" + event.bytesLoaded + " total: " + event.bytesTotal);
         * }
         *
         *   private function securityErrorHandler(event:SecurityErrorEvent):void {
         * trace("securityErrorHandler: " + event);
         * }
         *
         *   private function httpStatusHandler(event:HTTPStatusEvent):void {
         * trace("httpStatusHandler: " + event);
         * }
         *
         *   private function ioErrorHandler(event:IOErrorEvent):void {
         * trace("ioErrorHandler: " + event);
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        class URLLoader : public flash::events::EventDispatcher
        {
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
        public:
            void *data;

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
        public:
            std::string dataFormat;

            /**
             * Indicates the number of bytes that have been loaded thus far
             * during the load operation.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int bytesLoaded;

            /**
             * Indicates the total number of bytes in the downloaded data.
             * This property contains 0 while the load operation is in progress
             * and is populated when the operation is complete.
             * Also, a missing Content-Length header will result in bytesTotal being indeterminate.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int bytesTotal;

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
        public:
            void     addEventListener(std::string type, Function *listener, bool useCapture=false, int priority=0, bool useWeakReference=false);

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
        public:
            void     load(URLRequest *request);

            /**
             * Closes the load operation in progress.  Any load
             * operation in progress is immediately terminated.
             * If no URL is currently being streamed, an invalid stream error is thrown.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     close();

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
        public:
            URLLoader(URLRequest *request=NULL);
        };
    }
}

#endif // FLEX11_6_FLASH_NET_URLLOADER_AS
#endif // __cplusplus

