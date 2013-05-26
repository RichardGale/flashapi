#if !defined(FLEX11_6_FLASH_NET_FILEREFERENCELIST_AS)
#define FLEX11_6_FLASH_NET_FILEREFERENCELIST_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"

/**
 * Dispatched when the user selects one or more files to upload from the file-browsing dialog box.
 * @eventType   flash.events.Event.SELECT
 */
//[Event(name="select",type="flash.events.Event")]

/**
 * Dispatched when the user dismisses the file-browsing dialog box.
 * @eventType   flash.events.Event.CANCEL
 */
//[Event(name="cancel",type="flash.events.Event")]

using namespace flash::events;

namespace flash
{
    namespace net
    {
        /**
         * The FileReferenceList class provides a means to let users select one or more files for uploading.
         * A FileReferenceList object represents a group of one or more local files on the user's disk as
         * an array of FileReference objects. For detailed information and important considerations about
         * FileReference objects and the FileReference class, which you use with FileReferenceList,
         * see the FileReference class.
         *
         *   <p class="- topic/p ">To work with the FileReferenceList class:</p><ul class="- topic/ul "><li class="- topic/li ">Instantiate the class: <codeph class="+ topic/ph pr-d/codeph ">var myFileRef = new FileReferenceList();</codeph></li><li class="- topic/li ">Call the <codeph class="+ topic/ph pr-d/codeph ">FileReferenceList.browse()</codeph> method, which opens a dialog box that
         * lets the user select one or more files for upload: <codeph class="+ topic/ph pr-d/codeph ">myFileRef.browse();</codeph></li><li class="- topic/li ">After the <codeph class="+ topic/ph pr-d/codeph ">browse()</codeph> method is called successfully, the <codeph class="+ topic/ph pr-d/codeph ">fileList</codeph> property of
         * the FileReferenceList object is populated with an array of FileReference objects.</li><li class="- topic/li ">Call <codeph class="+ topic/ph pr-d/codeph ">FileReference.upload()</codeph> on each element in the
         * <codeph class="+ topic/ph pr-d/codeph ">fileList</codeph> array.</li></ul><p class="- topic/p ">The FileReferenceList class includes a <codeph class="+ topic/ph pr-d/codeph ">browse()</codeph> method and a
         * <codeph class="+ topic/ph pr-d/codeph ">fileList</codeph> property for working with multiple files. While a call to <codeph class="+ topic/ph pr-d/codeph ">FileReferenceList.browse()</codeph>
         * is executing, SWF file playback pauses in stand-alone and external versions of Flash Player
         * and in AIR for Linux and Mac OS X 10.1 and earlier.</p>
         *
         *   EXAMPLE:
         *
         *   The following example shows how you can use events to manage the upload of multiple files.
         * The CustomFileReferenceList class extends FileReferenceList and includes a <codeph class="+ topic/ph pr-d/codeph ">complete</codeph> event,
         * which is dispatched
         * when each individual file in the FileReferenceList object is uploaded. The <codeph class="+ topic/ph pr-d/codeph ">LIST_COMPLETE</codeph>
         * event in the FileReferenceListExample class is dispatched when all the files in the FileReferenceList
         * object have been uploaded.
         *
         *   <p class="- topic/p ">To run this example, place a script that is written to accept
         * a file upload at http://www.[yourDomain].com/yourUploadHandlerScript.cfm.
         * Based on the location of your SWF file and where you are uploading files to, you
         * also might need to compile the SWF file with Local Playback Security set to Access Network Only
         * or update Flash<sup class="+ topic/ph hi-d/sup ">  </sup> Player security settings to allow this file network access.
         * If your upload server is remote and you run this example from your desktop computer,
         * your server must have a crossdomain.xml file.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         *
         *   package {
         * import flash.display.Sprite;
         * import flash.events.*;
         * import flash.net.FileReference;
         * import flash.net.FileReferenceList;
         *
         *   public class FileReferenceListExample extends Sprite {
         * public static var LIST_COMPLETE:String = "listComplete";
         * public function FileReferenceListExample() {
         * initiateFileUpload();
         * }
         *
         *   private function initiateFileUpload():void {
         * var fileRef:CustomFileReferenceList = new CustomFileReferenceList();
         * fileRef.addEventListener(FileReferenceListExample.LIST_COMPLETE, listCompleteHandler);
         * fileRef.browse(fileRef.getTypes());
         * }
         *
         *   private function listCompleteHandler(event:Event):void {
         * trace("listCompleteHandler");
         * }
         * }
         * }
         *
         *   import flash.events.*;
         * import flash.net.FileReference;
         * import flash.net.FileReferenceList;
         * import flash.net.FileFilter;
         * import flash.net.URLRequest;
         *
         *   class CustomFileReferenceList extends FileReferenceList {
         * private var uploadURL:URLRequest;
         * private var pendingFiles:Array;
         *
         *   public function CustomFileReferenceList() {
         * uploadURL = new URLRequest();
         * uploadURL.url = "http://www.[yourDomain].com/yourUploadHandlerScript.cfm";
         * initializeListListeners();
         * }
         *
         *   private function initializeListListeners():void {
         * addEventListener(Event.SELECT, selectHandler);
         * addEventListener(Event.CANCEL, cancelHandler);
         * }
         *
         *   public function getTypes():Array {
         * var allTypes:Array = new Array();
         * allTypes.push(getImageTypeFilter());
         * allTypes.push(getTextTypeFilter());
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
         *   private function doOnComplete():void {
         * var event:Event = new Event(FileReferenceListExample.LIST_COMPLETE);
         * dispatchEvent(event);
         * }
         *
         *   private function addPendingFile(file:FileReference):void {
         * trace("addPendingFile: name=" + file.name);
         * pendingFiles.push(file);
         * file.addEventListener(Event.OPEN, openHandler);
         * file.addEventListener(Event.COMPLETE, completeHandler);
         * file.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
         * file.addEventListener(ProgressEvent.PROGRESS, progressHandler);
         * file.addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);
         * file.upload(uploadURL);
         * }
         *
         *   private function removePendingFile(file:FileReference):void {
         * for (var i:uint; i &lt; pendingFiles.length; i++) {
         * if (pendingFiles[i].name == file.name) {
         * pendingFiles.splice(i, 1);
         * if (pendingFiles.length == 0) {
         * doOnComplete();
         * }
         * return;
         * }
         * }
         * }
         *
         *   private function selectHandler(event:Event):void {
         * trace("selectHandler: " + fileList.length + " files");
         * pendingFiles = new Array();
         * var file:FileReference;
         * for (var i:uint = 0; i &lt; fileList.length; i++) {
         * file = FileReference(fileList[i]);
         * addPendingFile(file);
         * }
         * }
         *
         *   private function cancelHandler(event:Event):void {
         * var file:FileReference = FileReference(event.target);
         * trace("cancelHandler: name=" + file.name);
         * }
         *
         *   private function openHandler(event:Event):void {
         * var file:FileReference = FileReference(event.target);
         * trace("openHandler: name=" + file.name);
         * }
         *
         *   private function progressHandler(event:ProgressEvent):void {
         * var file:FileReference = FileReference(event.target);
         * trace("progressHandler: name=" + file.name + " bytesLoaded=" + event.bytesLoaded + " bytesTotal=" + event.bytesTotal);
         * }
         *
         *   private function completeHandler(event:Event):void {
         * var file:FileReference = FileReference(event.target);
         * trace("completeHandler: name=" + file.name);
         * removePendingFile(file);
         * }
         *
         *   private function httpErrorHandler(event:Event):void {
         * var file:FileReference = FileReference(event.target);
         * trace("httpErrorHandler: name=" + file.name);
         * }
         *
         *   private function ioErrorHandler(event:Event):void {
         * var file:FileReference = FileReference(event.target);
         * trace("ioErrorHandler: name=" + file.name);
         * }
         *
         *   private function securityErrorHandler(event:Event):void {
         * var file:FileReference = FileReference(event.target);
         * trace("securityErrorHandler: name=" + file.name + " event=" + event.toString());
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        class FileReferenceList : public flash::events::EventDispatcher
        {
            /**
             * An array of FileReference objects.
             *
             *   When the FileReferenceList.browse() method is called and the user
             * has selected one or more files from the dialog box that the browse() method opens,
             * this property is populated with an array of FileReference objects,
             * each of which represents the files the user selected.
             * You can then use this array to upload each file with the FileReference.upload()method.
             * You must upload one file at a time.The fileList property is populated anew each time browse() is called on
             * that FileReferenceList object.The properties of FileReference objects are described
             * in the FileReference class documentation.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @oldexample  The following example demonstrates the <code>fileList</code> property.
             *   <listing version="2.0">
             *   import flash.net.FileReferenceList;
             *   import flash.net.FileReference;
             *
             *     var listener:Object = new Object();
             *   listener.onSelect = function(fileRefList:FileReferenceList) {
             *   trace("onSelect");
             *   var list:Array = fileRefList.fileList;
             *   var item:FileReference;
             *   for(var i:Number = 0; i &lt; list.length; i++) {
             *   item = list[i];
             *   trace("name: " + item.name);
             *   }
             *   }
             *
             *     var fileRef:FileReferenceList = new FileReferenceList();
             *   fileRef.addListener(listener);
             *   fileRef.browse();
             *   </listing>
             */
        public:
            std::vector<void *>        fileList();

            /**
             * Displays a file-browsing dialog box that lets the
             * user select one or more local files to upload. The dialog box is native to the user's
             * operating system.
             *
             *   In Flash Player 10 and later, you can call this method successfully
             * only in response to a user event (for example, in an event handler for a mouse click or keypress event).
             * Otherwise, calling this method results in Flash Player throwing an Error.When you call this method and the user successfully selects files,
             * the fileList property of this FileReferenceList object is populated with
             * an array of FileReference objects, one for each file that the user selects.
             * Each subsequent time that the FileReferenceList.browse() method is called, the
             * FileReferenceList.fileList property is reset to the file(s) that the
             * user selects in the dialog box.Using the typeFilter parameter, you can determine which files
             * the dialog box displays.Only one FileReference.browse(), FileReference.download(),
             * or FileReferenceList.browse() session can be performed at a time
             * on a FileReferenceList object
             * (because only one dialog box can be opened at a time).
             * @param   typeFilter  An array of FileFilter instances used to filter the files that are
             *   displayed in the dialog box. If you omit this parameter, all files are displayed.
             *   For more information, see the FileFilter class.
             * @return  Returns true if the parameters are valid and the file-browsing dialog box
             *   opens.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @oldexample  <pre xml:space="preserve" class="- topic/pre ">
             *   // ask the user to choose an image file for upload
             *   var fileRef = new FileReference();
             *   if (fileRef.browse(["Images", "jpg;gif;png", "Flash Movies", "swf"])) {
             *   trace("Opened " + fileRef.name);
             *   } else {
             *   trace("User canceled");
             *   }
             *   </pre>
             * @throws  IllegalOperationError Thrown for the following reasons: 1) Another FileReference
             *   or FileReferenceList browse session is in progress; only one file browsing session
             *   may be performed at a time. 2) A setting in the user's mms.cfg file prohibits this operation.
             * @throws  ArgumentError If the typeFilter array does not contain correctly formatted
             *   FileFilter objects, an exception is thrown. For details on correct filter formatting,
             *   see the FileFilter documentation.
             * @throws  Error If the method is not called in response to a user action, such as a mouse
             *   event or keypress event.
             */
        public:
            bool  browse(std::vector<void *> typeFilter=std::vector<void *>());

            /**
             * Creates a new FileReferenceList object. A FileReferenceList object contains nothing
             * until you call the browse() method on it and the user selects one or more files.
             * When you call browse() on the
             * FileReference object, the fileList property of the object is populated
             * with an array of FileReference objects.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example creates a new <code>FileReferenceList</code> object,
             *   iterates over each selected file, and outputs their names.
             *   <listing version="2.0">
             *   import flash.net.FileReferenceList;
             *
             *     var listener:Object = new Object();
             *   listener.onSelect = function(fileRefList:FileReferenceList) {
             *   trace("onSelect");
             *   var arr:Array = fileRefList.fileList;
             *   for(var i:Number = 0; i &lt; arr.length; i++) {
             *   trace("name: " + arr[i].name);
             *   }
             *   }
             *
             *     var fileRef:FileReferenceList = new FileReferenceList();
             *   fileRef.addListener(listener);
             *   fileRef.browse();
             *   </listing>
             */
        public:
            FileReferenceList();
        };
    }
}

#endif // FLEX11_6_FLASH_NET_FILEREFERENCELIST_AS
#endif // __cplusplus

