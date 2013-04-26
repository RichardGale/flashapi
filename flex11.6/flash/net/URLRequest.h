#if !defined(FLEX11_6_FLASH_NET_URLREQUEST_AS)
#define FLEX11_6_FLASH_NET_URLREQUEST_AS
#if defined(__cplusplus)


/**
 * The URLRequest class captures all of the information in a single HTTP request. URLRequest
 * objects are passed to the <codeph class="+ topic/ph pr-d/codeph ">load()</codeph> methods of the Loader, URLStream,
 * and URLLoader classes, and to other loading operations, to initiate URL downloads.
 * They are also passed to the <codeph class="+ topic/ph pr-d/codeph ">upload()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">download()</codeph> methods
 * of the FileReference class.
 *
 *   <p class="- topic/p ">A SWF file in the local-with-filesystem sandbox may not load data from,
 * or provide data to, a resource that is in the network sandbox. </p><p class="- topic/p ">By default, the calling <ph class="- topic/ph ">SWF </ph>file
 * and the URL you load must be in the same domain. For example, a <ph class="- topic/ph ">SWF </ph>file
 * at www.adobe.com can load data only from sources that are also at www.adobe.com.
 * <ph class="- topic/ph ">To load data from a different domain, place a URL policy file on the server
 * hosting the data.</ph></p><p class="- topic/p "> However, in Adobe AIR, content in the application security sandbox (content
 * installed with the AIR application) is not restricted by these security limitations.
 * For content running in Adobe AIR, files in the application security sandbox
 * can access URLs using any of the following URL schemes:</p><ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">http</codeph> and <codeph class="+ topic/ph pr-d/codeph ">https</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">file</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">app-storage</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">app</codeph></li></ul><p class="- topic/p ">Content <ph class="- topic/ph ">running in Adobe AIR </ph>that is not in the application security
 * sandbox observes the same restrictions as content running in the browser
 * <ph class="- topic/ph ">(in Flash Player)</ph>, and loading is
 * governed by the content's domain<ph class="- topic/ph "> and any permissions granted in URL
 * policy files</ph>.</p><p class="- topic/p ">For more information related to security, see the Flash Player Developer Center Topic:
 * <xref href="http://www.adobe.com/go/devnet_security_en" scope="external" class="- topic/xref ">Security</xref>.</p>
 *
 *   EXAMPLE:
 *
 *   The following example creates a new Loader object and passes it
 * a URLRequest object that contains the path to an XML file. If the loading operation is
 * successful, a <codeph class="+ topic/ph pr-d/codeph ">complete</codeph> event is dispatched and the data in the XML
 * file traces to the output. Additional event handlers capture other events, including error
 * events.
 * <p class="- topic/p ">To run this example, place a file named XMLFile.xml in the same directory
 * as your SWF file.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.events.*;
 * import flash.net.*;
 *
 *   public class URLRequestExample extends Sprite {
 *
 *   public function URLRequestExample() {
 * var loader:URLLoader = new URLLoader();
 * configureListeners(loader);
 *
 *   var request:URLRequest = new URLRequest("XMLFile.xml");
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
 * @internal    The above include is not a mistake, but rather code re-use.
 */

namespace flash
{
    namespace net
    {
        class URLRequest: public Object
        {
            /**
             * The URL to be requested.
             *
             *   Be sure to encode any characters that are either described as unsafe in the Uniform Resource Locator
             * specification (see http://www.faqs.org/rfcs/rfc1738.html) or that are reserved in the
             * URL scheme of the URLRequest object (when not used for their reserved purpose). For example,
             * use "%25" for the percent (%) symbol and "%23" for the number sign (#), as in
             * "http://www.example.com/orderForm.cfm?item=%23B-3&discount=50%25".By default, the URL must be in the same domain as the calling file,
             * unless the content is running in the Adobe AIR application
             * security sandbox. If you need to load data from a different domain,
             * put a URL policy file on the server that is hosting the data. For more information,
             * see the description of the URLRequest class.For content running in Adobe AIR, files
             * in the application security sandobx
             *     files installed with the AIR application     can access URLs using any of the
             * following URL schemes:http and httpsfileapp-storageappNote: IPv6 (Internet Protocol version 6) is supported in
             * AIR and in Flash Player 9.0.115.0 and later.
             *
             *   IPv6 is a version of Internet Protocol that supports
             * 128-bit addresses (an improvement on the earlier IPv4 protocol that supports 32-bit
             * addresses). You might need to activate IPv6 on your networking interfaces. For more
             * information, see the Help for the operating system hosting the data.
             * If IPv6 is supported on the hosting system, you can specify numeric IPv6 literal addresses
             * in URLs enclosed in brackets ([]), as in the following.
             * rtmp://[2001:db8:ccc3:ffff:0:444d:555e:666f]:1935/test
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  url();
        public:
            void         url(std::string value);

            /**
             * An object containing data to be transmitted with the URL request.
             *
             *   This property is used in conjunction with the method property.
             * When the value of method is GET,
             * the value of data is appended to the value of URLRequest.url,
             * using HTTP query-string syntax. When the method value is POST
             * (or any value other than GET), the value
             * of data is transmitted in the body of the HTTP request.The URLRequest API offers binary POST support and support for URL-encoded variables,
             * as well as support for strings. The data object can be a ByteArray, URLVariables,
             * or String object.The way in which the data is used depends on the type of object used:If the object is a ByteArray object, the binary
             * data of the ByteArray object is used as POST data. For GET, data of ByteArray type
             * is not supported. Also, data of ByteArray type is not supported for
             * FileReference.upload() and FileReference.download().If the object is a URLVariables object and the method is POST,
             * the variables are encoded using x-www-form-urlencoded format
             * and the resulting string is used as POST data. An exception is a call to
             * FileReference.upload(), in which the variables are sent as separate fields in
             * a multipart/form-data post.If the object is a URLVariables object and the method is GET,
             * the URLVariables object defines variables to be sent with the URLRequest object.Otherwise, the object is converted to a string, and the string
             * is used as the POST or GET data.This data is not sent until a method, such as navigateToURL()
             * or FileReference.upload(), uses the URLRequest object.Note: The value of contentType must correspond to the type of data
             * in the data property. See the note in the description of the
             * contentType property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            Object      *data();
        public:
            void         data(Object *value);

            /**
             * Controls the HTTP form submission method.
             *
             *   For SWF content running in Flash Player
             * (in the browser), this property is limited to GET or
             * POST operations, and valid values are URLRequestMethod.GET
             * or URLRequestMethod.POST.For content running in Adobe AIR, you
             * can use any string value
             * if the content is in the application security sandbox. Otherwise,
             * as with content running in Flash Player,
             * you are restricted to using GET or POST operations.For content running in Adobe AIR, when
             * using the navigateToURL() function, the runtime treats a URLRequest that uses the POST
             * method (one that has its method property set to URLRequestMethod.POST)
             * as using the GET method.Note:
             * If running in Flash Player and the referenced form has no body,
             * Flash Player automatically uses a GET operation, even if the method is set to
             * URLRequestMethod.POST. For this reason, it is recommended to always include
             * a "dummy" body to ensure that the correct method is used.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  ArgumentError If the value parameter is not
             *   URLRequestMethod.GET or URLRequestMethod.POST.
             */
        public:
            std::string  method();
        public:
            void         method(std::string value);

            /**
             * The MIME content type of the content in the the data property.
             *
             *   The default value is application/x-www-form-urlencoded.Note:The FileReference.upload(),
             * FileReference.download(), and HTMLLoader.load() methods do not
             * support the URLRequest.contentType property.When sending a POST request, the values of the contentType
             * and data properties must correspond properly. The value of the contentType
             * property instructs servers on how to interpret the value of the data property. If the value of the data property is a URLVariables object, the value of
             * contentType must be application/x-www-form-urlencoded.  If the value of the data property is any other type, the value of contentType
             * should indicate the type of the POST data that will be sent (which is the binary or string data
             * contained in the value of the data property). For FileReference.upload(),
             * the Content-Type of the request is set automatically to multipart/form-data,
             * and the value of the contentType property is ignored. In Flash Player 10 and later, if you use a multipart Content-Type (for example "multipart/form-data")
             * that contains an upload (indicated by a "filename" parameter in a "content-disposition" header within the POST body),
             * the POST operation is subject to the security rules applied to uploads:The POST operation must be performed in response to a user-initiated action, such as a mouse click or key press.If the POST operation is cross-domain (the POST target is not on the same server as the SWF file
             * that is sending the POST request),
             * the target server must provide a URL policy file that permits cross-domain access.Also, for any multipart Content-Type, the syntax must be valid (according to the RFC2046 standards).
             * If the syntax appears to be invalid, the POST operation is subject to the security rules applied to uploads.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  contentType();
        public:
            void         contentType(std::string value);

            /**
             * The array of HTTP request headers to be appended to the
             * HTTP request. The array is composed of URLRequestHeader objects.
             * Each object in the array must be a URLRequestHeader object that
             * contains a name string and a value string, as follows:
             *
             *   <codeblock>
             *
             *   var rhArray:Array = new Array(new URLRequestHeader("Content-Type", "text/html"));
             *
             *   </codeblock>
             * Flash Player and the AIR runtime impose
             * certain restrictions on request headers;
             * for more information, see the URLRequestHeader class description.Not all methods that accept URLRequest parameters support the requestHeaders property,
             * consult the documentation for the method you are calling. For example, the FileReference.upload()
             * and FileReference.download() methods do not
             * support the URLRequest.requestHeaders property.Due to browser limitations, custom HTTP request headers are only supported for POST requests,
             * not for GET requests.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::vector<void *> requestHeaders();
        public:
            void         requestHeaders(std::vector<void *> value);

            /**
             * A string that uniquely identifies the signed Adobe platform component to be stored
             * to (or retrieved from) the Flash Player cache.  An Adobe
             * platform component is a signed file (a SWZ file) that contains SWF content that is cached
             * persistently on a user's machine. All SWZ files are signed by Adobe. A digest
             * corresponds to a single cached file; if you change the file in any way, its digest
             * will change in an unpredictable way. By using a digest, you can verify the cached file across
             * multiple domains. Two files with the same digest are the same file, and two files with different
             * digests are not the same file. A file cannot (practically) be created to "spoof" a digest and
             * pretend to be another digest. The digest is based on an SHA-256 message digest algorithm
             * (64 characters long in hexadecimal format).For example, the Flex SDK includes a SWZ for the Flex framework (and it
             * provides the digest string for that SWZ file). You can post this SWZ on your web server and load it
             * in your SWF file (using the load() method of a URLLoader object). If the end user's
             * machine already has the matching SWZ file cached, the application uses the cached SWZ file.
             * (A SWZ file matches if its digest matches the one you provide.) Otherwise, the
             * application downloads the SWZ file from the URL you specify. Only set the digest parameter in a URLRequest object
             * used in a call to the URLLoader.load() method to load a SWZ file. If the digest
             * property of a a URLRequest object is set when it is used in other methods, the application throws an
             * IOError exception.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             * @playerversion   Lite 4
             * @throws  ArgumentError The digest provided does not match the digest of the file that is
             *   extracted from the downloaded signed file or the signed file loaded out of the cache. The
             *   application also throws this error if the provided digest is the wrong length or contains invalid
             *   (nonhexadecimal) characters.
             */
        public:
            std::string  digest();
        public:
            void         digest(std::string value);

            /**
             * Creates a URLRequest object.
             *
             *   If System.useCodePage is true, the request is encoded using the
             * system code page, rather than Unicode.
             *
             *   If System.useCodePage is false, the request is encoded using Unicode, rather than the
             * system code page.
             * @param   url The URL to be requested. You can set the URL later by using the url property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            URLRequest(std::string url);
        };
    }
}

#endif // FLEX11_6_FLASH_NET_URLREQUEST_AS
#endif // __cplusplus

