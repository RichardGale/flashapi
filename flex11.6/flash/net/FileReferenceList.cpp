

#include "FileReferenceList.h"
#include "flash/events/EventDispatcher.h"

    /**
     * Dispatched when the user selects one or more files to upload from the file-browsing dialog box.
     * @eventType   flash.events.Event.SELECT
     */

using namespace flash::events;

namespace flash {
namespace net {


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
        std::vector<void*> FileReferenceList::fileList()        ;

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
        bool FileReferenceList::browse(std::vector<void*> typeFilter)          ;

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
        FileReferenceList::FileReferenceList();
}
}

