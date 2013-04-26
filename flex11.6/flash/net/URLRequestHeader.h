#if !defined(FLEX11_6_FLASH_NET_URLREQUESTHEADER_AS)
#define FLEX11_6_FLASH_NET_URLREQUESTHEADER_AS
#if defined(__cplusplus)


/**
 * A URLRequestHeader object encapsulates a single HTTP request header
 * and consists of a name/value pair.
 *
 *   URLRequestHeader objects are used in the <codeph class="+ topic/ph pr-d/codeph ">requestHeaders</codeph> property of the URLRequest class.
 *
 *   <p class="- topic/p ">In Adobe<sup class="+ topic/ph hi-d/sup ">  </sup> AIR<sup class="+ topic/ph hi-d/sup ">  </sup>, content in the application security sandbox (such as
 * content installed with the AIR application) can use any request headers, without error. However, for content
 * running in Adobe AIR that is in a different security sandbox,
 * <ph class="- topic/ph ">or for content running in Flash<sup class="+ topic/ph hi-d/sup ">  </sup> Player,</ph>
 * using following request headers cause a runtime error to be thrown, and the
 * restricted terms are not case-sensitive (for example, <codeph class="+ topic/ph pr-d/codeph ">Get</codeph>, <codeph class="+ topic/ph pr-d/codeph ">get</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">GET</codeph>
 * are each not allowed): </p><p class="- topic/p ">In Flash Player and in Adobe AIR content outside of the application security sandbox,
 * the following request headers cannot be used, and the restricted terms are not case-sensitive
 * (for example, <codeph class="+ topic/ph pr-d/codeph ">Get</codeph>, <codeph class="+ topic/ph pr-d/codeph ">get</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">GET</codeph> are all not allowed). Also,
 * hyphenated terms apply if an underscore character is used (for example, both <codeph class="+ topic/ph pr-d/codeph ">Content-Length</codeph> and
 * <codeph class="+ topic/ph pr-d/codeph ">Content_Length</codeph> are not allowed): </p><p class="- topic/p "><codeph class="+ topic/ph pr-d/codeph ">Accept-Charset</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Accept-Encoding</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Accept-Ranges</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Age</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Allow</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">Allowed</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Authorization</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Charge-To</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Connect</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">Connection</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">Content-Length</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Content-Location</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Content-Range</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Cookie</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">Date</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Delete</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">ETag</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Expect</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Get</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Head</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Host</codeph>, <codeph class="+ topic/ph pr-d/codeph ">If-Modified-Since</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">Keep-Alive</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Last-Modified</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Location</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">Max-Forwards</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Options</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Origin</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Post</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">Proxy-Authenticate</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Proxy-Authorization</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Proxy-Connection</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">Public</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Put</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">Range</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Referer</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Request-Range</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Retry-After</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Server</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">TE</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Trace</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Trailer</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Transfer-Encoding</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">Upgrade</codeph>, <codeph class="+ topic/ph pr-d/codeph ">URI</codeph>, <codeph class="+ topic/ph pr-d/codeph ">User-Agent</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Vary</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Via</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Warning</codeph>,
 * <codeph class="+ topic/ph pr-d/codeph ">WWW-Authenticate</codeph>, <codeph class="+ topic/ph pr-d/codeph ">x-flash-version</codeph>.</p><p class="- topic/p ">URLRequestHeader objects are restricted in length. If the cumulative length of a
 * URLRequestHeader object (the length of the <codeph class="+ topic/ph pr-d/codeph ">name</codeph> property plus the <codeph class="+ topic/ph pr-d/codeph ">value</codeph>
 * property) or an array of URLRequestHeader objects used in the <codeph class="+ topic/ph pr-d/codeph ">URLRequest.requestHeaders</codeph>
 * property exceeds the acceptable length, an exception is thrown.</p><p class="- topic/p ">Content running in Adobe AIR sets the <codeph class="+ topic/ph pr-d/codeph ">ACCEPT</codeph> header to the following, unless you
 * specify a setting for the <codeph class="+ topic/ph pr-d/codeph ">ACCEPT</codeph> header in the <codeph class="+ topic/ph pr-d/codeph ">requestHeaders</codeph>
 * property of the URLRequest class:</p><codeph class="+ topic/ph pr-d/codeph ">text/xml,
 * application/xml,
 * application/xhtml+xml,
 * text/html;q=0.9,
 * text/plain;q=0.8,
 * image/png,
 * application/x-shockwave-flash,
 * video/mp4;q=0.9,
 * flv-application/octet-stream;q=0.8,
 * video/x-flv;q=0.7,
 * audio/mp4,
 * ~~/~~;q=0.5</codeph><p class="- topic/p ">Not all methods that accept URLRequest parameters support the <codeph class="+ topic/ph pr-d/codeph ">requestHeaders</codeph> property,
 * consult the documentation for the method you are calling. For example, the <codeph class="+ topic/ph pr-d/codeph ">FileReference.upload()</codeph>
 * and <codeph class="+ topic/ph pr-d/codeph ">FileReference.download()</codeph> methods do not
 * support the <codeph class="+ topic/ph pr-d/codeph ">URLRequest.requestHeaders</codeph> property.</p><p class="- topic/p ">Due to browser limitations, custom HTTP request headers are only supported for <codeph class="+ topic/ph pr-d/codeph ">POST</codeph> requests,
 * not for <codeph class="+ topic/ph pr-d/codeph ">GET</codeph> requests.</p>
 *
 *   EXAMPLE:
 *
 *   The following example adds a single HTTP request header <codeph class="+ topic/ph pr-d/codeph ">header</codeph> to the array for the <codeph class="+ topic/ph pr-d/codeph ">requestHeaders</codeph> property. The header indicates that the application should forward the request to the origin server even if it has a cached copy of what is being requested.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.events.*;
 * import flash.net.URLLoader;
 * import flash.net.URLRequest;
 * import flash.net.URLRequestHeader;
 * import flash.net.URLRequestMethod;
 * import flash.net.URLVariables;
 *
 *   public class URLRequestHeaderExample extends Sprite {
 * public function URLRequestHeaderExample() {
 * var loader:URLLoader = new URLLoader();
 * configureListeners(loader);
 *
 *   var header:URLRequestHeader = new URLRequestHeader("pragma", "no-cache");
 * var request:URLRequest = new URLRequest("http://www.[yourdomain].com/greeting.cfm");
 * request.data = new URLVariables("name=John+Doe");
 * request.method = URLRequestMethod.POST;
 * request.requestHeaders.push(header);
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

namespace flash
{
    namespace net
    {
        class URLRequestHeader: public Object
        {
            /**
             * An HTTP request header name (such as Content-Type or SOAPAction).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string name;

            /**
             * The value associated with the name property (such as text/plain).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string value;

            /**
             * Creates a new URLRequestHeader object that encapsulates a single HTTP request header.
             * URLRequestHeader objects are used in the requestHeaders
             * property of the URLRequest class.
             * @param   name    An HTTP request header name (such as Content-Type
             *   or SOAPAction).
             * @param   value   The value associated with the name property
             *   (such as text/plain).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            URLRequestHeader(std::string name, std::string value);
        };
    }
}

#endif // FLEX11_6_FLASH_NET_URLREQUESTHEADER_AS
#endif // __cplusplus

