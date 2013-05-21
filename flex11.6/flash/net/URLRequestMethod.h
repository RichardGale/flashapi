#if !defined(FLEX11_6_FLASH_NET_URLREQUESTMETHOD_AS)
#define FLEX11_6_FLASH_NET_URLREQUESTMETHOD_AS
#if defined(__cplusplus)


/**
 * The URLRequestMethod class provides values that specify whether the URLRequest object should
 * use the <codeph class="+ topic/ph pr-d/codeph ">POST</codeph> method or the <codeph class="+ topic/ph pr-d/codeph ">GET</codeph> method when sending data to a server.
 *
 *   EXAMPLE:
 *
 *   The following example loads and displays the
 * data found in a local text file. It also traces event handling information.
 *
 *   <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b>To run this example, put a file named example.txt
 * in the same directory as your SWF file. That file should be a simple text file containing
 * a few words or lines of text.
 * </p><p class="- topic/p ">The example code does the following:</p><ol class="- topic/ol "><li class="- topic/li ">The constructor function creates a URLLoader instance named <codeph class="+ topic/ph pr-d/codeph ">loader</codeph>.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">loader</codeph> object is passed to the <codeph class="+ topic/ph pr-d/codeph ">configureListeners()</codeph> method,
 * which adds listeners for each of the supported URLLoader events.</li><li class="- topic/li ">A URLRequest instance named <codeph class="+ topic/ph pr-d/codeph ">request</codeph> is created, which specifies name of the file to be loaded.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">method</codeph> property of the request is set to <codeph class="+ topic/ph pr-d/codeph ">URLRequestMethod.POST</codeph>.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">request</codeph> object is then passed to <codeph class="+ topic/ph pr-d/codeph ">loader.load()</codeph>, which loads the text file.</li><li class="- topic/li ">When the URLLoader has finished loading the text file the <codeph class="+ topic/ph pr-d/codeph ">Event.COMPLETE</codeph> event fires,
 * triggering the <codeph class="+ topic/ph pr-d/codeph ">completeHandler()</codeph> method. The <codeph class="+ topic/ph pr-d/codeph ">completeHandler()</codeph> method simply traces
 * the <codeph class="+ topic/ph pr-d/codeph ">data</codeph> property, the contents of the text file.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.events.*;
 * import flash.net.*;
 *
 *   public class URLRequestMethodExample extends Sprite {
 *
 *   public function URLRequestMethodExample() {
 * var loader:URLLoader = new URLLoader();
 * configureListeners(loader);
 *
 *   var request:URLRequest = new URLRequest("example.txt");
 *
 *   request.method = URLRequestMethod.POST;
 * loader.load(request);
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
        class URLRequestMethod : public Object
        {
            /**
             * Specifies that the URLRequest object is a POST.
             *
             *   Note:For content running in Adobe AIR, when
             * using the navigateToURL() function, the runtime
             * treats a URLRequest that uses the POST method (one that has its method property set to
             * URLRequestMethod.POST) as using the GET method.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string POST;

            /**
             * Specifies that the URLRequest object is a GET.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string GET;

            /**
             * Specifies that the URLRequest object is a PUT.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string PUT;

            /**
             * Specifies that the URLRequest object is a DELETE.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string DELETE;

            /**
             * Specifies that the URLRequest object is a HEAD.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string HEAD;

            /**
             * Specifies that the URLRequest object is OPTIONS.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string OPTIONS;

        public:
            URLRequestMethod();
        };
    }
}

#endif // FLEX11_6_FLASH_NET_URLREQUESTMETHOD_AS
#endif // __cplusplus

