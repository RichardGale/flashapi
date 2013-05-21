#if !defined(FLEX11_6_FLASH_NET_URLLOADERDATAFORMAT_AS)
#define FLEX11_6_FLASH_NET_URLLOADERDATAFORMAT_AS
#if defined(__cplusplus)


/**
 * The URLLoaderDataFormat class provides values that specify how downloaded data is received.
 *
 *   EXAMPLE:
 *
 *   The following example uses the URLLoaderDataFormatExample class to display
 * data format and status information for a file loaded at runtime.  This is accomplished
 * using the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">The class constructor creates a URLLoader instance named <codeph class="+ topic/ph pr-d/codeph ">loader</codeph> and a URLRequest
 * instance named <codeph class="+ topic/ph pr-d/codeph ">request</codeph>, which is the location and name of the file to be loaded.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">loader</codeph> object is passed to the <codeph class="+ topic/ph pr-d/codeph ">configureListeners()</codeph> method, which adds
 * listeners for each of the supported URLLoader events:
 * <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">completeHandler()</codeph>: listens for the <codeph class="+ topic/ph pr-d/codeph ">complete</codeph> event, which is dispatched
 * after TextFile.txt has successfully loaded.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">openHandler()</codeph>: listens for the <codeph class="+ topic/ph pr-d/codeph ">open</codeph> event, dispatched upon start of the
 * download (to the player) of TextFile.txt.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">progressHandler()</codeph>: listens for the <codeph class="+ topic/ph pr-d/codeph ">progress</codeph> events, dispatched when data
 * is received as the download operation progresses.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">securityErrorHandler()</codeph>: listens for <codeph class="+ topic/ph pr-d/codeph ">securityError</codeph> events, which would be
 * dispatched if the text file was accessed with the wrong local playback security setting.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">httpStatusHandler()</codeph>: listens for <codeph class="+ topic/ph pr-d/codeph ">httpStatusHandler</codeph> events, which will not be
 * dispatched in this case since TextFile.txt is local.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">ioErrorHandler()</codeph>: listens for <codeph class="+ topic/ph pr-d/codeph ">ioError</codeph> events, which would happen only
 * if there were a serious problem with the file, such as if it were missing.</li></ul></li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">request</codeph> object is then passed to the <codeph class="+ topic/ph pr-d/codeph ">loader.load()</codeph> method, which loads the text file
 * into memory using a <codeph class="+ topic/ph pr-d/codeph ">DisplayObject</codeph> object.</li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Notes:</b><ul class="- topic/ul "><li class="- topic/li ">You will need to compile the SWF file with "Local playback security" set to "Access local files only".
 * </li><li class="- topic/li ">This example requires that a file named TextFile.txt be placed in the same directory as your SWF file.
 * If you would like to see this example identify binary or URL-encoded data files, you will need to
 * provide the file in the proper data format and change TextFile.txt to the name and location of the new
 * file.</li></ul></p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.events.*;
 * import flash.net.*;
 *
 *   public class URLLoaderDataFormatExample extends Sprite {
 * private var source:String = "TextFile.txt";
 * private var dataFormat:String = URLLoaderDataFormat.TEXT;
 *
 *   public function URLLoaderDataFormatExample () {
 * var loader:URLLoader = new URLLoader();
 * loader.dataFormat = dataFormat;
 * configureListeners(loader);
 * var request:URLRequest = new URLRequest(source);
 * try {
 * loader.load(request);
 * } catch (error:Error) {
 * trace("Error loading requested document: " + source);
 * }
 * }
 *
 *   private function configureListeners(dispatcher:URLLoader):void {
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
 * switch(loader.dataFormat) {
 * case URLLoaderDataFormat.TEXT :
 * trace("completeHandler (text): " + loader.data);
 * break;
 * case URLLoaderDataFormat.BINARY :
 * trace("completeHandler (binary): " + loader.data);
 * break;
 * case URLLoaderDataFormat.VARIABLES :
 * trace("completeHandler (variables): " + loader.data);
 * break;
 * }
 * }
 *
 *   private function httpStatusHandler(event:Event):void {
 * trace("httpStatusHandler: " + event);
 * }
 *
 *   private function ioErrorHandler(event:IOErrorEvent):void {
 * trace("ioErrorHandler: " + event);
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
        class URLLoaderDataFormat : public Object
        {
            /**
             * Specifies that downloaded data is received as text.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string TEXT;

            /**
             * Specifies that downloaded data is received as raw binary data.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string BINARY;

            /**
             * Specifies that downloaded data is received as URL-encoded variables.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string VARIABLES;

        public:
            URLLoaderDataFormat();
        };
    }
}

#endif // FLEX11_6_FLASH_NET_URLLOADERDATAFORMAT_AS
#endif // __cplusplus

