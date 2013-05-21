#if !defined(FLEX11_6_FLASH_NET_FILEREFERENCE_AS)
#define FLEX11_6_FLASH_NET_FILEREFERENCE_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace net
    {
        class URLRequest;
    }
}
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

/**
 * Dispatched after data is received from the server after a successful upload.
 * @eventType   flash.events.DataEvent.UPLOAD_COMPLETE_DATA
 */
//[Event(name="uploadCompleteData",type="flash.events.DataEvent")]

/**
 * Dispatched if a call to the upload() or uploadUnencoded()
 * method attempts to access data over HTTP and Adobe AIR is able to detect and return
 * the status code for the request.
 * @eventType   flash.events.HTTPStatusEvent.HTTP_RESPONSE_STATUS
 */
//[Event(name="httpResponseStatus",type="flash.events.HTTPStatusEvent")]

/**
 * Dispatched when an upload fails and an HTTP status code is available
 * to describe the failure.
 * @eventType   flash.events.HTTPStatusEvent.HTTP_STATUS
 */
//[Event(name="httpStatus",type="flash.events.HTTPStatusEvent")]

/**
 * Dispatched when the user selects a file for upload or download from the file-browsing dialog box.
 * @eventType   flash.events.Event.SELECT
 */
//[Event(name="select",type="flash.events.Event")]

/**
 * Dispatched when a call to the FileReference.upload()
 * or FileReference.download() method tries to upload a file to a server or
 * get a file from a server that is outside the caller's security sandbox.
 * @eventType   flash.events.SecurityErrorEvent.SECURITY_ERROR
 */
//[Event(name="securityError",type="flash.events.SecurityErrorEvent")]

/**
 * Dispatched periodically during the file upload or download operation.
 * @eventType   flash.events.ProgressEvent.PROGRESS
 */
//[Event(name="progress",type="flash.events.ProgressEvent")]

/**
 * Dispatched when an upload or download operation starts.
 * @eventType   flash.events.Event.OPEN
 */
//[Event(name="open",type="flash.events.Event")]

/**
 * Dispatched when the upload or download fails.
 * @eventType   flash.events.IOErrorEvent.IO_ERROR
 */
//[Event(name="ioError",type="flash.events.IOErrorEvent")]

/**
 * Dispatched when download is complete or when upload generates an HTTP status code of 200.
 * @eventType   flash.events.Event.COMPLETE
 */
//[Event(name="complete",type="flash.events.Event")]

/**
 * Dispatched when a file upload or download is canceled through the file-browsing dialog
 * box by the user.
 * @eventType   flash.events.Event.CANCEL
 */
//[Event(name="cancel",type="flash.events.Event")]

using namespace flash::events;
using namespace flash::net;
using namespace flash::utils;

namespace flash
{
    namespace net
    {
        /**
         * The FileReference class provides a means to upload and
         * download files between a user's computer and a server. An operating-system
         * dialog box prompts the user to select a file to upload or a location for
         * download. Each FileReference object refers to a single file on the user's disk
         * and has properties that contain information about
         * the file's size, type, name, creation date, modification date, and creator type
         * (Macintosh only).
         *
         *   <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> In Adobe AIR, the File class, which extends the FileReference class,
         * provides more capabilities and has less security restrictions than the FileReference class.</p><p class="- topic/p ">FileReference instances are created in the following ways:</p><ul class="- topic/ul "><li class="- topic/li ">When you use the <codeph class="+ topic/ph pr-d/codeph ">new</codeph> operator with the FileReference constructor:
         *
         *   <codeph class="+ topic/ph pr-d/codeph ">var myFileReference = new FileReference();</codeph></li><li class="- topic/li ">When you call the <codeph class="+ topic/ph pr-d/codeph ">FileReferenceList.browse()</codeph> method, which creates an array of FileReference objects.</li></ul><p class="- topic/p ">During an upload operation, all the properties of a FileReference object are
         * populated by calls to the <codeph class="+ topic/ph pr-d/codeph ">FileReference.browse()</codeph> or <codeph class="+ topic/ph pr-d/codeph ">FileReferenceList.browse()</codeph> methods.
         * During a download operation, the <codeph class="+ topic/ph pr-d/codeph ">name</codeph> property is populated when the
         * <codeph class="+ topic/ph pr-d/codeph ">select</codeph> event is dispatched; all other properties are populated when the
         * <codeph class="+ topic/ph pr-d/codeph ">complete</codeph> event is dispatched.</p><p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">browse()</codeph> method opens an operating-system dialog box that prompts the
         * user to select a file for upload. The <codeph class="+ topic/ph pr-d/codeph ">FileReference.browse()</codeph> method
         * lets the user select a single file; the <codeph class="+ topic/ph pr-d/codeph ">FileReferenceList.browse()</codeph> method
         * lets the user select multiple files. After a successful call to the <codeph class="+ topic/ph pr-d/codeph ">browse()</codeph> method,
         * call the <codeph class="+ topic/ph pr-d/codeph ">FileReference.upload()</codeph> method to upload one file at a time. The
         * <codeph class="+ topic/ph pr-d/codeph ">FileReference.download()</codeph> method prompts the user for a location to save
         * the file and initiates downloading from a remote URL.</p><p class="- topic/p ">The FileReference and FileReferenceList classes do not let you set the default file location
         * for the dialog box that the <codeph class="+ topic/ph pr-d/codeph ">browse()</codeph> or <codeph class="+ topic/ph pr-d/codeph ">download()</codeph> methods generate.
         * The default location shown in the dialog box is the most
         * recently browsed folder, if that location can be determined, or the desktop.
         * The classes do not allow you to read from or write to the transferred file.
         * They do not allow the SWF file that initiated the
         * upload or download to access the uploaded or downloaded file or the file's location on
         * the user's disk.</p><p class="- topic/p ">The FileReference and FileReferenceList classes also do not provide
         * methods for authentication. With servers that require authentication, you can
         * download files with the Flash<sup class="+ topic/ph hi-d/sup ">  </sup> Player browser plug-in, but
         * uploading (on all players) and downloading (on the stand-alone or
         * external player) fails. Listen for FileReference events to determine whether
         * operations complete successfully and to handle errors.</p><p class="- topic/p ">For <ph class="- topic/ph ">content running in Flash Player or for</ph>
         * content running in Adobe AIR outside of the application security sandbox,
         * uploading and downloading operations can access files only within its own domain and within
         * any domains that a URL policy file specifies. Put a policy file on the file server
         * if the content initiating the upload or download doesn't come from the same domain as the file server.</p><p class="- topic/p ">Note that because of new functionality added to the Flash Player, when publishing to Flash Player 10, you can have
         * only one of the following operations active at one time: <codeph class="+ topic/ph pr-d/codeph ">FileReference.browse()</codeph>,
         * <codeph class="+ topic/ph pr-d/codeph ">FileReference.upload()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">FileReference.download()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">FileReference.load()</codeph>,
         * <codeph class="+ topic/ph pr-d/codeph ">FileReference.save()</codeph>. Otherwise, Flash Player throws a runtime error (code 2174). Use <codeph class="+ topic/ph pr-d/codeph ">FileReference.cancel()</codeph>
         * to stop an operation in progress. This restriction applies only to Flash Player 10. Previous versions of Flash Player
         * are unaffected by this restriction on simultaneous multiple operations.</p><p class="- topic/p ">While calls to the <codeph class="+ topic/ph pr-d/codeph ">FileReference.browse()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">FileReferenceList.browse()</codeph>,
         * or <codeph class="+ topic/ph pr-d/codeph ">FileReference.download()</codeph> methods are executing, SWF file playback pauses in stand-alone and external versions
         * of Flash Player and in AIR for Linux and Mac OS X 10.1 and earlier</p><p class="- topic/p ">The following sample HTTP <codeph class="+ topic/ph pr-d/codeph ">POST</codeph> request is sent from Flash Player to a server-side
         * script if no parameters are specified:
         * </p><pre xml:space="preserve" class="- topic/pre ">
         * POST /handler.cfm HTTP/1.1
         * Accept: text/~~
         * Content-Type: multipart/form-data;
         * boundary=----------Ij5ae0ae0KM7GI3KM7
         * User-Agent: Shockwave Flash
         * Host: www.example.com
         * Content-Length: 421
         * Connection: Keep-Alive
         * Cache-Control: no-cache
         *
         *   ------------Ij5GI3GI3ei4GI3ei4KM7GI3KM7KM7
         * Content-Disposition: form-data; name="Filename"
         *
         *   MyFile.jpg
         * ------------Ij5GI3GI3ei4GI3ei4KM7GI3KM7KM7
         * Content-Disposition: form-data; name="Filedata"; filename="MyFile.jpg"
         * Content-Type: application/octet-stream
         *
         *   FileDataHere
         * ------------Ij5GI3GI3ei4GI3ei4KM7GI3KM7KM7
         * Content-Disposition: form-data; name="Upload"
         *
         *   Submit Query
         * ------------Ij5GI3GI3ei4GI3ei4KM7GI3KM7KM7--
         * </pre><p class="- topic/p ">Flash Player sends the following HTTP <codeph class="+ topic/ph pr-d/codeph ">POST</codeph> request if the user
         * specifies the parameters <codeph class="+ topic/ph pr-d/codeph ">"api_sig"</codeph>, <codeph class="+ topic/ph pr-d/codeph ">"api_key"</codeph>, and
         * <codeph class="+ topic/ph pr-d/codeph ">"auth_token"</codeph>:
         * </p><pre xml:space="preserve" class="- topic/pre ">
         * POST /handler.cfm HTTP/1.1
         * Accept: text/~~
         * Content-Type: multipart/form-data;
         * boundary=----------Ij5ae0ae0KM7GI3KM7
         * User-Agent: Shockwave Flash
         * Host: www.example.com
         * Content-Length: 421
         * Connection: Keep-Alive
         * Cache-Control: no-cache
         *
         *   ------------Ij5GI3GI3ei4GI3ei4KM7GI3KM7KM7
         * Content-Disposition: form-data; name="Filename"
         *
         *   MyFile.jpg
         * ------------Ij5GI3GI3ei4GI3ei4KM7GI3KM7KM7
         * Content-Disposition: form-data; name="api_sig"
         *
         *   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
         * ------------Ij5GI3GI3ei4GI3ei4KM7GI3KM7KM7
         * Content-Disposition: form-data; name="api_key"
         *
         *   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
         * ------------Ij5GI3GI3ei4GI3ei4KM7GI3KM7KM7
         * Content-Disposition: form-data; name="auth_token"
         *
         *   XXXXXXXXXXXXXXXXXXXXXX
         * ------------Ij5GI3GI3ei4GI3ei4KM7GI3KM7KM7
         * Content-Disposition: form-data; name="Filedata"; filename="MyFile.jpg"
         * Content-Type: application/octet-stream
         *
         *   FileDataHere
         * ------------Ij5GI3GI3ei4GI3ei4KM7GI3KM7KM7
         * Content-Disposition: form-data; name="Upload"
         *
         *   Submit Query
         * ------------Ij5GI3GI3ei4GI3ei4KM7GI3KM7KM7--
         * </pre>
         *
         *   EXAMPLE:
         *
         *   The following example displays the
         * data format and status information for a file loaded at runtime.
         * <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b>
         * To run this example, change the uploadURL.url property to point to an actual URL,
         * rather than the fictional one in the example. The URL should point to a file named
         * <codeph class="+ topic/ph pr-d/codeph ">yourUploadHandlerScript.cfm</codeph> in the root    web directory of the URL specified.
         * Based on your configuration, you might also need to compile the SWF file with Local Playback Security set to Access Network Only
         * or to update Flash Player security settings to allow this file network access.
         * </p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Sprite;
         * import flash.events.*;
         * import flash.net.FileFilter;
         * import flash.net.FileReference;
         * import flash.net.URLRequest;
         *
         *   public class FileReferenceExample extends Sprite {
         * private var uploadURL:URLRequest;
         * private var file:FileReference;
         *
         *   public function FileReferenceExample() {
         * uploadURL = new URLRequest();
         * uploadURL.url = "http://www.[yourDomain].com/yourUploadHandlerScript.cfm";
         * file = new FileReference();
         * configureListeners(file);
         * file.browse(getTypes());
         * }
         *
         *   private function configureListeners(dispatcher:IEventDispatcher):void {
         * dispatcher.addEventListener(Event.CANCEL, cancelHandler);
         * dispatcher.addEventListener(Event.COMPLETE, completeHandler);
         * dispatcher.addEventListener(HTTPStatusEvent.HTTP_STATUS, httpStatusHandler);
         * dispatcher.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
         * dispatcher.addEventListener(Event.OPEN, openHandler);
         * dispatcher.addEventListener(ProgressEvent.PROGRESS, progressHandler);
         * dispatcher.addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);
         * dispatcher.addEventListener(Event.SELECT, selectHandler);
         * dispatcher.addEventListener(DataEvent.UPLOAD_COMPLETE_DATA,uploadCompleteDataHandler);
         * }
         *
         *   private function getTypes():Array {
         * var allTypes:Array = new Array(getImageTypeFilter(), getTextTypeFilter());
         * return allTypes;
         * }
         *
         *   private function getImageTypeFilter():FileFilter {
         * return new FileFilter("Images (*.jpg, *.jpeg, *.gif, *.png)", "*.jpg;*.jpeg;*.gif;*.png");
         * }
         *
         *   private function getTextTypeFilter():FileFilter {
         * return new FileFilter("Text Files (*.txt, *.rtf)", "*.txt;*.rtf");
         * }
         *
         *   private function cancelHandler(event:Event):void {
         * trace("cancelHandler: " + event);
         * }
         *
         *   private function completeHandler(event:Event):void {
         * trace("completeHandler: " + event);
         * }
         *
         *   private function uploadCompleteDataHandler(event:DataEvent):void {
         * trace("uploadCompleteData: " + event);
         * }
         *
         *   private function httpStatusHandler(event:HTTPStatusEvent):void {
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
         * var file:FileReference = FileReference(event.target);
         * trace("progressHandler name=" + file.name + " bytesLoaded=" + event.bytesLoaded + " bytesTotal=" + event.bytesTotal);
         * }
         *
         *   private function securityErrorHandler(event:SecurityErrorEvent):void {
         * trace("securityErrorHandler: " + event);
         * }
         *
         *   private function selectHandler(event:Event):void {
         * var file:FileReference = FileReference(event.target);
         * trace("selectHandler: name=" + file.name + " URL=" + uploadURL.url);
         * file.upload(uploadURL);
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        class FileReference : public flash::events::EventDispatcher
        {
            /**
             * The creation date of the file on the local disk. If the object is
             * was not populated, a call to get the value of this property returns null.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @throws  IllegalOperationError If the FileReference.browse(),
             *   FileReferenceList.browse(), or FileReference.download() method was not called
             *   successfully, an exception is thrown with a message indicating that functions were called in the
             *   incorrect sequence or an earlier call was unsuccessful.
             *   In this case, the value of the creationDate property is null.
             * @throws  IOError If the file information cannot be accessed, an exception is thrown with a message
             *   indicating a file I/O error.
             */
        public:
            Date        *creationDate();

            /**
             * The Macintosh creator type of the file, which is only used in Mac OS versions
             * prior to Mac OS X. In Windows or Linux, this property is null.
             * If the FileReference object
             * was not populated, a call to get the value of this property returns null.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @throws  IllegalOperationError On Macintosh, if the FileReference.browse(),
             *   FileReferenceList.browse(), or FileReference.download() method was not called
             *   successfully, an exception is thrown with a message indicating that functions were called in the
             *   incorrect sequence or an earlier call was unsuccessful. In this case, the value of the creator property
             *   is null.
             */
        public:
            std::string  creator();

            /**
             * The date that the file on the local disk was last modified. If the FileReference
             * object was not populated, a call to get the value of this property returns null.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Flash 9
             * @throws  IllegalOperationError If the FileReference.browse(),
             *   FileReferenceList.browse(), or FileReference.download() method was not called
             *   successfully, an exception is thrown with a message indicating that functions were called in the
             *   incorrect sequence or an earlier call was unsuccessful. In this case,
             *   the value of the modificationDate property is null.
             * @throws  IOError If the file information cannot be accessed, an exception is thrown with a message
             *   indicating a file I/O error.
             */
        public:
            Date        *modificationDate();

            /**
             * The name of the file on the local disk. If the FileReference object
             * was not populated (by a valid call to FileReference.download() or
             * FileReference.browse()), Flash Player throws an error when you try to get the
             * value of this property.
             * All the properties of a FileReference object are populated by calling the browse() method.
             * Unlike other FileReference properties, if you call the download() method,
             * the name property is populated when the select event is dispatched.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @refpath
             * @throws  IllegalOperationError If the FileReference.browse(),
             *   FileReferenceList.browse(), or FileReference.download() method was not called
             *   successfully, an exception is thrown with a message indicating that functions were called in the
             *   incorrect sequence or an earlier call was unsuccessful.
             */
        public:
            std::string  name();

            /**
             * The size of the file on the local disk in bytes. If size is 0,
             * an exception is thrown.Note: In the initial version of ActionScript 3.0, the size property was
             * defined as a uint object, which supported files with sizes up to about 4 GB. It is now implemented as a Number
             * object to support larger files.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @refpath
             * @throws  IllegalOperationError If the FileReference.browse(),
             *   FileReferenceList.browse(), or FileReference.download() method was not called
             *   successfully, an exception is thrown with a message indicating that functions were called in the
             *   incorrect sequence or an earlier call was unsuccessful.
             * @throws  IOError If the file cannot be opened or read, or if a similar error is encountered in
             *   accessing the file, an exception is thrown with a message indicating a file I/O error.
             */
        public:
            float        size();

            /**
             * The file type.
             *
             *   In Windows or Linux, this property is the file extension. On the Macintosh, this property is
             * the four-character file type, which is only used in Mac OS versions prior to Mac OS X. If the FileReference object
             * was not populated, a call to get the value of this property returns null.For Windows, Linux, and Mac OS X, the file extension     the portion of the name property that
             * follows the last occurrence of the dot (.) character     identifies the file type.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @throws  IllegalOperationError If the FileReference.browse(),
             *   FileReferenceList.browse(), or FileReference.download() method was not called
             *   successfully, an exception is thrown with a message indicating that functions were called in the
             *   incorrect sequence or an earlier call was unsuccessful. In this case, the value of the type property
             *   is null.
             */
        public:
            std::string  type();

            /**
             * The ByteArray object representing the data from the loaded file after a successful call to the load() method.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @refpath
             * @throws  IllegalOperationError If the load() method was not called
             *   successfully, an exception is thrown with a message indicating that functions were called in the
             *   incorrect sequence or an earlier call was unsuccessful. In this case, the value of the data property
             *   is null.
             * @throws  IOError If the file cannot be opened or read, or if a similar error is encountered in
             *   accessing the file, an exception is thrown with a message indicating a file I/O error. In this case, the value
             *   of the data property is null.
             */
        public:
            flash::utils::ByteArray *data();

            /**
             * Creates a new FileReference object. When populated, a FileReference object represents a file
             * on the user's local disk.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example creates a new <code>FileReference</code> object and
             *   initiates the download of a pdf file.
             *   <listing version="2.0">
             *   import flash.net.FileReference;
             *
             *     var listener:Object = new Object();
             *   listener.onComplete = function(file:FileReference) {
             *   trace("onComplete : " + file.name);
             *   }
             *
             *     var url:String = "http://www.adobe.com/platform/whitepapers/platform_overview.pdf";
             *   var fileRef:FileReference = new FileReference();
             *   fileRef.addListener(listener);
             *   fileRef.download(url, "FlashPlatform.pdf");
             *   </listing>
             */
        public:
            FileReference();

            /**
             * Cancels any ongoing upload or download operation on this FileReference object.
             * Calling this method does not dispatch the cancel event; that event
             * is dispatched only when the user cancels the operation by dismissing the
             * file upload or download dialog box.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            void     cancel();

            /**
             * Opens a dialog box that lets the user download a file from a remote server.
             * Although Flash Player has no restriction on the size of files you can upload or download,
             * the player officially supports uploads or downloads of up to 100 MB.The download() method first opens
             * an operating-system dialog box that asks the user to enter a filename and
             * select a location on the local computer
             * to save the file. When the user selects a location and confirms the download operation
             * (for example, by clicking Save), the download from the remote server begins.
             * Listeners receive events to indicate the progress, success, or
             * failure of the download.
             * To ascertain the status of the dialog box and the download operation after calling
             * download(), your code must listen for events
             * such as cancel, open,
             * progress, and complete.
             * The FileReference.upload() and FileReference.download() functions
             * are nonblocking. These functions return after they are called, before the file transmission
             * is complete. In addition, if the FileReference object goes out of scope, any upload or download
             * that is not yet completed on that object is canceled upon leaving the scope.
             * Be sure that your FileReference object remains in scope for as long as the
             * upload or download is expected to continue.When the file is downloaded successfully, the
             * properties of the FileReference object are populated with the properties
             * of the local file. The complete event is dispatched if the
             * download is successful.Only one browse() or download() session can
             * be performed at a time (because only one dialog box can be invoked at a time).This method supports downloading of any file type, with either HTTP or HTTPS.You cannot connect to commonly reserved ports.
             * For a complete list of blocked ports, see "Restricting Networking APIs" in the
             * ActionScript 3.0 Developer's Guide.Note: If your server requires user authentication, only
             * SWF files running in a browser     that is, using the browser plug-in or ActiveX control
             * can provide a dialog box to prompt the user for a user name and password for authentication,
             * and only for downloads. For uploads using the plug-in or ActiveX control, or for
             * uploads and downloads using the stand-alone or external player, the file transfer fails.When you use this method , consider the Flash Player
             * security model: Loading operations are not allowed if the calling SWF file is in an untrusted local sandbox.The default behavior is to deny access between sandboxes. A website can enable access to a
             * resource by adding a URL policy file.You can prevent a SWF file from using this method by setting the  allowNetworking
             * parameter of the the object and embed tags in the HTML
             * page that contains the SWF content.In Flash Player 10 and Flash Player 9 Update 5, you can only call this method successfully in response
             * to a user event (for example, in an event handler for a mouse click or keypress event). Otherwise, calling
             * this method results in Flash Player throwing an Error exception.However, in Adobe AIR,
             * content in the application security sandbox (content
             * installed with the AIR application) is not restricted by these security limitations.For more information related to security, see the Flash Player Developer Center Topic:
             * Security.When you download a file using this method, it is flagged as downloaded on operating systems
             * that flag downloaded files:Windows XP service pack 2 and later, and on Windows VistaMac OS 10.5 and laterSome operating systems, such as Linux, do not flag downloaded files.Note that because of new functionality added to the Flash Player, when publishing to Flash Player 10, you can have
             * only one of the following operations active at one time: FileReference.browse(),
             * FileReference.upload(), FileReference.download(), FileReference.load(),
             * FileReference.save(). Otherwise, Flash Player throws a runtime error (code 2174). Use FileReference.cancel()
             * to stop an operation in progress. This restriction applies only to Flash Player 10. Previous versions of Flash Player
             * are unaffected by this restriction on simultaneous multiple operations.In Adobe AIR, the download dialog is not always displayed in front of windows that are
             * "owned" by another window (windows that have a non-null owner property).
             * To avoid window ordering issues, hide owned windows before calling this method.
             * @param   request The URLRequest object. The url property of the URLRequest object
             *   should contain the URL of the file to download to the local computer.
             *   If this parameter is null, an exception is thrown. The requestHeaders property
             *   of the URLRequest object is ignored; custom HTTP request headers are not supported in uploads or downloads.
             *
             *     To send POST or GET parameters to the server, set the value of URLRequest.data
             *   to your parameters, and set URLRequest.method to either URLRequestMethod.POST
             *   or URLRequestMethod.GET.
             *
             *     On some browsers, URL strings are limited in length. Lengths greater than 256 characters may
             *   fail on some browsers or servers.
             * @param   defaultFileName The default filename displayed in the dialog box for the file
             *   to be downloaded. This string must not contain the following characters:
             *   / \ : ~~ ? " < > | %
             *   If you omit this parameter, the filename of the
             *   remote URL is parsed and used as the default.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @throws  IllegalOperationError Thrown in the following situations: 1) Another browse session is in
             *   progress; only one file browsing session can be performed at a time.
             *   2) The value passed to request does not contain
             *   a valid path or protocol.
             *   3) The filename to download contains prohibited characters.
             *   4) A setting in the user's mms.cfg file prohibits this operation.
             * @throws  SecurityError Local untrusted content may not communicate with the Internet. To avoid this situation, reclassify this
             *   SWF file as local-with-networking or trusted. This exception is thrown with a message indicating the filename
             *   and the URL that may not be accessed because of local file security restrictions.
             * @throws  SecurityError You cannot connect to commonly reserved ports.
             *   For a complete list of blocked ports, see "Restricting Networking APIs" in the
             *   ActionScript 3.0 Developer's Guide.
             * @throws  ArgumentError If url.data is of type ByteArray, an exception is
             *   thrown. For use with the FileReference.upload() and
             *   FileReference.download() methods, url.data can only be of type
             *   URLVariables or String.
             * @throws  MemoryError This error can occur for the following reasons:
             *   1) Flash Player cannot convert the URLRequest.data
             *   parameter from UTF8 to MBCS. This error is applicable if the URLRequest object
             *   passed to the FileReference.download() method is set to perform a GET operation and if
             *   System.useCodePage is set to true.
             *   2) Flash Player cannot allocate memory for the POST data. This error is
             *   applicable if the URLRequest object passed to the FileReference.download() method is set
             *   to perform a POST operation.
             * @throws  Error If the method is not called in response to a user action, such as a mouse
             *   event or keypress event.
             */
        public:
            void     download(URLRequest *request, std::string defaultFileName="");

            /**
             * Starts the upload of the file to a remote server. Although
             * Flash Player has no restriction on the size of files you can upload or download,
             * the player officially supports uploads or downloads of up to 100 MB.
             * You must call the FileReference.browse() or FileReferenceList.browse()
             * method before you call this method.
             *
             *   For the Adobe AIR File class, which extends the FileReference class, you can use the upload()
             * method to upload any file. For the FileReference class (used in Flash Player), the user must first
             * select a file.Listeners receive events to indicate the progress, success, or
             * failure of the upload. Although you can use the FileReferenceList object to let users
             * select multiple files for upload, you must upload the files one by one; to do so, iterate through
             * the FileReferenceList.fileList array of FileReference objects.The FileReference.upload() and FileReference.download() functions
             * are nonblocking. These functions return after they are called, before the file transmission
             * is complete. In addition, if the FileReference object goes out of scope, any upload or download
             * that is not yet completed on that object is canceled upon leaving the scope.
             * Be sure that your FileReference object remains in scope for as long as the
             * upload or download is expected to continue.The file is uploaded to the URL passed in the url parameter. The URL
             * must be a server script configured to accept uploads. Flash Player uploads files by using
             * the HTTP POST method. The server script that handles the upload
             * should expect a POST request with the following elements:Content-Type of multipart/form-dataContent-Disposition with a name attribute set to "Filedata" by default
             * and a filename attribute set to the name of the original fileThe binary contents of the fileYou cannot connect to commonly reserved ports.
             * For a complete list of blocked ports, see "Restricting Networking APIs" in the
             * ActionScript 3.0 Developer's Guide.For a sample POST request, see the description of the uploadDataFieldName
             * parameter. You can send POST or GET parameters to the server with the upload()
             * method; see the description of the request parameter.If the testUpload parameter is true,
             * and the file to be uploaded is bigger than approximately 10 KB, Flash Player on Windows
             * first sends a test upload POST operation with zero content before uploading the actual file,
             * to verify that the transmission is likely to succeed. Flash Player then sends
             * a second POST operation that contains the actual file content.
             * For files smaller than 10 KB, Flash Player performs a single
             * upload POST with the actual file content to be uploaded.
             * Flash Player on Macintosh does not perform test upload POST operations.Note: If your server requires user authentication, only
             * SWF files running in a browser     that is, using the browser plug-in or ActiveX control
             * can provide a dialog box to prompt the user for a username and password for authentication,
             * and only for downloads. For uploads using the plug-in or ActiveX control, or for
             * uploads and downloads using the stand-alone or external player, the file transfer fails.When you use this method , consider the Flash Player
             * security model: Loading operations are not allowed if the calling SWF file is in an untrusted local sandbox.The default behavior is to deny access between sandboxes. A website can enable access to a
             * resource by adding a URL policy file.You can prevent a SWF file from using this method by setting the  allowNetworking
             * parameter of the the object and embed tags in the HTML
             * page that contains the SWF content.However, in Adobe AIR, content in the application security sandbox (content
             * installed with the AIR application) are not restricted by these security limitations.For more information related to security, see the Flash Player Developer Center Topic:
             * Security.Note that because of new functionality added to the Flash Player, when publishing to Flash Player 10, you can have
             * only one of the following operations active at one time: FileReference.browse(),
             * FileReference.upload(), FileReference.download(), FileReference.load(),
             * FileReference.save(). Otherwise, Flash Player throws a runtime error (code 2174). Use FileReference.cancel()
             * to stop an operation in progress. This restriction applies only to Flash Player 10. Previous versions of Flash Player
             * are unaffected by this restriction on simultaneous multiple operations.
             * @param   request The URLRequest object; the url property of the URLRequest object
             *   should contain the URL of the server script
             *   configured to handle upload through HTTP POST calls.
             *   On some browsers, URL strings are limited in length.
             *   Lengths greater than 256 characters may fail on some browsers or servers.
             *   If this parameter is null, an exception is thrown. The requestHeaders property
             *   of the URLRequest object is ignored; custom HTTP request headers are not supported in uploads or downloads.
             *
             *     The URL can be HTTP or, for secure uploads, HTTPS.
             *   To use HTTPS, use an HTTPS url in the url parameter.
             *   If you do not specify a port number in the url
             *   parameter, port 80 is used for HTTP and port 443 us used for HTTPS, by default.To send POST or GET parameters to the server, set the data property
             *   of the URLRequest object to your parameters, and set the method property
             *   to either URLRequestMethod.POST or
             *   URLRequestMethod.GET.
             * @param   uploadDataFieldName The field name that precedes the file data in the upload POST operation.
             *   The uploadDataFieldName value must be non-null and a non-empty String.
             *   By default, the value of uploadDataFieldName is "Filedata",
             *   as shown in the following sample POST request:
             *
             *     Content-Type: multipart/form-data; boundary=AaB03x
             *   --AaB03x
             *   Content-Disposition: form-data; name="Filedata"; filename="example.jpg"
             *   Content-Type: application/octet-stream
             *   ... contents of example.jpg ...
             *   --AaB03x--
             * @param   testUpload  A setting to request a test file upload. If testUpload
             *   is true, for files larger than 10 KB, Flash Player attempts
             *   a test file upload POST with a Content-Length of 0. The test upload
             *   checks whether the actual file upload will be successful and that server
             *   authentication, if required, will succeed. A test upload
             *   is only available for Windows players.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @throws  SecurityError Local untrusted SWF files may not communicate with
             *   the Internet. To avoid this situation, reclassify this SWF file
             *   as local-with-networking or trusted. This exception is thrown with a message indicating the name of
             *   the local file and the URL that may not be accessed.
             * @throws  SecurityError You cannot connect to commonly reserved ports.
             *   For a complete list of blocked ports, see "Restricting Networking APIs" in the
             *   ActionScript 3.0 Developer's Guide.
             * @throws  IllegalOperationError Thrown in the following situations: 1) Another FileReference or
             *   FileReferenceList browse session is in progress; only one file browsing session may be performed
             *   at a time.
             *   2) The URL parameter is not a valid path or protocol. File upload must use HTTP,
             *   and file download must use FTP or HTTP.
             *   3) The uploadDataFieldName parameter is set to null.
             *   4) A setting in the user's mms.cfg file prohibits this operation.
             * @throws  ArgumentError Thrown in the following situations: 1) The uploadDataFieldName
             *   parameter is an empty string. 2) url.data is of type ByteArray.
             *   For use with the FileReference.upload() and
             *   FileReference.download() methods, url.data may only be of type
             *   URLVariables or String. 3) In the AIR runtime (in the application security sandbox), the method of the
             *   URLRequest is not GET or POST (use uploadEncoded() instead).
             * @throws  MemoryError This error can occur for the following reasons:
             *   1) Flash Player cannot convert the URLRequest.data
             *   parameter from UTF8 to MBCS. This error is applicable if the URLRequest object
             *   passed to FileReference.upload() is set to perform a GET operation and if
             *   System.useCodePage is set to true.
             *   2) Flash Player cannot allocate memory for the POST data. This error is
             *   applicable if the URLRequest object passed to FileReference.upload() is set
             *   to perform a POST operation.
             */
        public:
            void     upload(URLRequest *request, std::string uploadDataFieldName="Filedata", bool testUpload   =false);

            /**
             * Starts the load of a local file selected by a user.
             * Although Flash Player has no restriction on the size of files you can upload,
             * download, load or save, it officially supports sizes of up to 100 MB. For content running in Flash Player,
             * you must call the FileReference.browse() or FileReferenceList.browse() method before
             * you call the load() method. However, content running in AIR in the application sandbox can call
             * the load() method of a File object without first calling the browse() method.
             * (The AIR File class extends the FileReference class.)Listeners receive events to indicate the progress, success, or
             * failure of the load. Although you can use the FileReferenceList object to let users
             * select multiple files to load, you must load the files one by one. To load the files
             * one by one, iterate through the FileReferenceList.fileList array of FileReference objects.Adobe AIR also includes the FileStream class which provides more options for
             * reading files.The FileReference.upload(), FileReference.download(), FileReference.load()
             * and FileReference.save() functions
             * are nonblocking. These functions return after they are called, before the file transmission
             * is complete. In addition, if the FileReference object goes out of scope, any transaction
             * that is not yet completed on that object is canceled upon leaving the scope.
             * Be sure that your FileReference object remains in scope for as long as the
             * upload, download, load or save is expected to continue.If the file finishes loading successfully, its contents are stored as a byte array
             * in the data property of the FileReference object.The following security considerations apply:Loading operations are not allowed if the calling SWF file is in an untrusted local sandbox.The default behavior is to deny access between sandboxes. A website can enable access to a
             * resource by adding a cross-domain policy file.You can prevent a file from using this method by setting the  allowNetworking
             * parameter of the the object and embed tags in the HTML
             * page that contains the SWF content.However, these considerations do not apply to AIR content in the application sandbox.Note that when publishing to Flash Player 10 or AIR 1.5, you can have only one of the following operations active at one time:
             * FileReference.browse(), FileReference.upload(), FileReference.download(), FileReference.load(),
             * FileReference.save(). Otherwise, the application throws a runtime error (code 2174). Use FileReference.cancel()
             * to stop an operation in progress. This restriction applies only to Flash Player 10 and AIR 1.5. Previous versions of Flash Player
             * or AIR are unaffected by this restriction on simultaneous multiple operations.In Adobe AIR, the file-browsing dialog is not always displayed in front of windows that are
             * "owned" by another window (windows that have a non-null owner property).
             * To avoid window ordering issues, hide owned windows before calling this method.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @throws  IllegalOperationError Thrown in the following situations: 1) Another FileReference or
             *   FileReferenceList browse session is in progress; only one file browsing session may be performed
             *   at a time.
             *   2) A setting in the user's mms.cfg file prohibits this operation.
             * @throws  MemoryError This error can occur if the application cannot allocate memory for the file.
             *   The file may be too large or available memory may be too low.
             */
        public:
            void     load();

            /**
             * Opens a dialog box that lets the user save a file to the local filesystem.
             * Although Flash Player has no restriction on
             * the size of files you can upload, download, load or save,
             * the player officially supports sizes of up to 100 MB.The save() method first opens
             * an operating-system dialog box that asks the user to enter a filename and
             * select a location on the local computer
             * to save the file. When the user selects a location and confirms the save operation
             * (for example, by clicking Save), the save process begins.
             * Listeners receive events to indicate the progress, success, or
             * failure of the save operation.
             * To ascertain the status of the dialog box and the save operation after calling
             * save(), your code must listen for events
             * such as cancel, open,
             * progress, and complete.
             * Adobe AIR also includes the FileStream class which provides more options for
             * saving files locally.The FileReference.upload(), FileReference.download(), FileReference.load()
             * and FileReference.save() functions
             * are nonblocking. These functions return after they are called, before the file transmission
             * is complete. In addition, if the FileReference object goes out of scope, any transaction
             * that is not yet completed on that object is canceled upon leaving the scope.
             * Be sure that your FileReference object remains in scope for as long as the
             * upload, download, load or save is expected to continue.When the file is saved successfully, the
             * properties of the FileReference object are populated with the properties
             * of the local file. The complete event is dispatched if the
             * save is successful.Only one browse() or save() session can
             * be performed at a time (because only one dialog box can be invoked at a time).In Flash Player, you can only call this method successfully in response to
             * a user event (for example, in an event handler for a mouse click or keypress event). Otherwise, calling
             * this method results in Flash Player throwing an Error exception. This limitation does not apply to
             * AIR content in the application sandbox.In Adobe AIR, the save dialog is not always displayed in front of windows that are
             * "owned" by another window (windows that have a non-null owner property).
             * To avoid window ordering issues, hide owned windows before calling this method.
             * @param   data    The data to be saved. The data can be in one of several formats, and will be treated
             *   appropriately:
             *   If the value is null, the application throws an ArgumentError exception.If the value is a String, it is saved as a UTF-8 text file.If the value is XML, it is written to a text file in XML format, with all formatting preserved.If the value is a ByteArray object, it is written to a data file verbatim.If the value is none of the above, the save() method calls the toString() method of the
             *   object to convert the data to a string, and it then saves the data as a text file. If that fails, the application throws
             *   an ArgumentError exception.
             * @param   defaultFileName The default filename displayed in the dialog box for the file
             *   to be saved. This string must not contain the following characters:
             *   / \ : ~~ ? " < > | %
             *
             *     If a File object calls this method, the filename will be that of the file the File object references. (The AIR File class
             *   extends the FileReference class.)
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @throws  IllegalOperationError Thrown in the following situations: 1) Another browse session is in
             *   progress; only one file browsing session can be performed at a time.
             *   2) The filename to download contains prohibited characters.
             *   3) A setting in the user's mms.cfg file prohibits this operation.
             * @throws  ArgumentError If data is not of type ByteArray, and it does not
             *   have a toString() method, an exception is thrown.  If data is
             *   not of type XML, and it does not have a toXMLString() method, an exception is thrown.
             * @throws  Error If the method is not called in response to a user action, such as a mouse
             *   event or keypress event.
             * @throws  MemoryError This error can occur if Flash Player cannot allocate memory for the file.
             *   The file may be too large or available memory may be too low.
             */
        public:
            void     save(void *data, std::string defaultFileName="");

            /**
             * Displays a file-browsing dialog box that lets the
             * user select a file to upload. The dialog box is native to the user's
             * operating system. The user can select a file on the local computer
             * or from other systems, for example, through a UNC path on Windows.
             *
             *   Note: The File class, available in Adobe AIR, includes methods for
             * accessing more specific system file selection dialog boxes. These methods are
             * File.browseForDirectory(), File.browseForOpen(),
             * File.browseForOpenMultiple(), and File.browseForSave().When you call this method and the user
             * successfully selects a file, the properties of this FileReference object are populated with
             * the properties of that file. Each subsequent time that the FileReference.browse() method
             * is called, the FileReference
             * object's properties are reset to the file that the user selects in the dialog box.
             * Only one browse() or download() session
             * can be performed at a time (because only one dialog box can be invoked at a time).Using the typeFilter parameter, you can determine which files the dialog box displays.In Flash Player 10 and Flash Player 9 Update 5, you can only call this method successfully in response
             * to a user event (for example, in an event handler for a mouse click or keypress event). Otherwise, calling
             * this method results in Flash Player throwing an Error exception.Note that because of new functionality added to the Flash Player, when publishing to Flash Player 10, you can have
             * only one of the following operations active at one time: FileReference.browse(),
             * FileReference.upload(), FileReference.download(), FileReference.load(),
             * FileReference.save(). Otherwise, Flash Player throws a runtime error (code 2174). Use FileReference.cancel()
             * to stop an operation in progress. This restriction applies only to Flash Player 10. Previous versions of Flash Player
             * are unaffected by this restriction on simultaneous multiple operations.In Adobe AIR, the file-browsing dialog is not always displayed in front of windows that are
             * "owned" by another window (windows that have a non-null owner property).
             * To avoid window ordering issues, hide owned windows before calling this method.
             * @param   typeFilter  An array of FileFilter instances used to filter the files that are
             *   displayed in the dialog box. If you omit this parameter,
             *   all files are displayed.
             *   For more information, see the FileFilter class.
             * @return  Returns true if the parameters are valid and the file-browsing dialog box
             *   opens.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @throws  IllegalOperationError Thrown in the following situations:
             *   1) Another FileReference or FileReferenceList browse session is in
             *   progress; only one file browsing session may be performed at a time.
             *   2) A setting in the user's mms.cfg file prohibits this operation.
             * @throws  ArgumentError If the typeFilter array contains
             *   FileFilter objects that are incorrectly formatted, an exception is thrown.
             *   For information on the correct format for FileFilter objects,
             *   see the FileFilter class.
             * @throws  Error If the method is not called in response to a user action, such as a mouse
             *   event or keypress event.
             */
        public:
            bool     browse(std::vector<void *> typeFilter=std::vector<void *>());
        };
    }
}

#endif // FLEX11_6_FLASH_NET_FILEREFERENCE_AS
#endif // __cplusplus

