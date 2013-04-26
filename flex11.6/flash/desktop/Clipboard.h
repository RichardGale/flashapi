#if !defined(FLEX11_6_FLASH_DESKTOP_CLIPBOARD_AS)
#define FLEX11_6_FLASH_DESKTOP_CLIPBOARD_AS
#if defined(__cplusplus)



namespace flash
{
    namespace utils
    {
        class Dictionary;
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
 * The Clipboard class provides a container for transferring data and objects through the clipboard.
 * The operating system clipboard can be accessed through the static <codeph class="+ topic/ph pr-d/codeph ">generalClipboard</codeph> property.
 *
 *   <p class="- topic/p ">A Clipboard object can contain the same information in more than one format.
 * By supplying information in multiple formats, you increase the chances that another
 * application will be able to use that information. Add data to a Clipboard object
 * with the <codeph class="+ topic/ph pr-d/codeph ">setData()</codeph> or <codeph class="+ topic/ph pr-d/codeph ">setDataHandler()</codeph> method.</p><p class="- topic/p ">The standard formats are:</p><ul class="- topic/ul "><li class="- topic/li ">BITMAP_FORMAT: a BitmapData object (AIR only)</li><li class="- topic/li ">FILE_LIST_FORMAT: an array of File objects (AIR only)</li><li class="- topic/li ">HTML_FORMAT: HTML-formatted string data</li><li class="- topic/li ">TEXT_FORMAT: string data</li><li class="- topic/li ">RICH_TEXT_FORMAT: a ByteArray containing Rich Text Format data</li><li class="- topic/li ">URL_FORMAT: a URL string (AIR only)</li></ul><p class="- topic/p ">These constants for the names of the standard formats are defined in the ClipboardFormats class.</p><p class="- topic/p ">When a transfer to or from the operating system occurs,
 * the standard formats are automatically translated between
 * <ph class="- topic/ph ">ActionScript</ph> data types and the native operating system clipboard types.</p><p class="- topic/p ">You can use application-defined formats to add
 * <ph class="- topic/ph ">ActionScript</ph> objects to a
 * Clipboard object. If an object is serializable, both a reference and a clone
 * of the object can be made available. Object references are valid only within the
 * originating application.</p><p class="- topic/p ">When it is computationally expensive to convert the information to be transferred into a
 * particular format, you can supply the name of a function that performs the conversion.
 * The function is called if and only if that format is read by the receiving component or application.
 * Add a deferred rendering function to a Clipboard object with the  <codeph class="+ topic/ph pr-d/codeph ">setDataHandler()</codeph> method.
 * Note that in some cases,
 * the operating system calls the function before a drop occurs. For example, when you use a handler function to
 * provide the data for a file dragged from an AIR application to the file system, the operating
 * system calls the data handler function as soon as the drag gesture leaves the AIR application   typically resulting
 * in an undesireable pause as the file data is downloaded or created.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note for AIR applications:</b> The clipboard object referenced by the event objects dispatched for HTML
 * drag-and-drop and copy-and-paste events are not the same type as the AIR Clipboard object.
 * The JavaScript clipboard object is described in the AIR developer's guide.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note for Flash Player applications:</b> In Flash Player 10, a paste operation from the clipboard first
 * requires a user event (such as a keyboard shortcut for the Paste command or a mouse click on the Paste command
 * in a context menu). <codeph class="+ topic/ph pr-d/codeph ">Clipboard.getData()</codeph>
 * will return the contents of the clipboard only if the InteractiveObject has received
 * and is acting on a paste event. Calling <codeph class="+ topic/ph pr-d/codeph ">Clipboard.getData()</codeph> under any other circumstances
 * will be unsuccessful. The same restriction applies in AIR for content outside the
 * application sandbox.</p><p class="- topic/p ">On Linux, clipboard data does not persist when an AIR application closes.</p>
 *
 *   EXAMPLE:
 *
 *   The following example, for Adobe AIR, uses the ClipboardExample class to
 * copy a string from one variable to another via the system clipboard.
 * This task is accomplished by performing the following steps:
 *
 *   <ol class="- topic/ol "><li class="- topic/li ">Write the data, in this case a string, to <codeph class="+ topic/ph pr-d/codeph ">Clipboard.generalClipboard</codeph>.</li><li class="- topic/li ">Read the clipboard contents from <codeph class="+ topic/ph pr-d/codeph ">Clipboard.generalClipboard</codeph>.</li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> Because of security restrictions on accessing clipboard data, this example
 * does not work in Flash Player. In Flash Player, you can only call the <codeph class="+ topic/ph pr-d/codeph ">getData()</codeph>
 * method of the Clipboard object in a <codeph class="+ topic/ph pr-d/codeph ">paste</codeph> event handler.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package
 * {
 * import flash.display.Sprite;
 * import flash.desktop.Clipboard;
 * import flash.desktop.ClipboardFormats;
 * import flash.desktop.ClipboardTransferMode;
 *
 *   public class ClipboardExample extends Sprite
 * {
 * public function ClipboardExample()
 * {
 * var sally:String = "Sally";
 * var person:String;
 *
 *   copy(sally);
 * person = paste();
 * trace(person); //traces: "Sally"
 * }
 *
 *   private function copy(text:String):void
 * {
 * Clipboard.generalClipboard.clear();
 * Clipboard.generalClipboard.setData(ClipboardFormats.TEXT_FORMAT, text);
 * }
 *
 *   private function paste():String
 * {
 * if(Clipboard.generalClipboard.hasFormat(ClipboardFormats.TEXT_FORMAT))
 * {
 * return String(Clipboard.generalClipboard.getData(ClipboardFormats.TEXT_FORMAT));
 * }
 * else
 * {
 * return null;
 * }
 * }
 *
 *   }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.0
 * @internal    NativeDragManager is AIR only and is not in FP10.
 */
using namespace flash::utils;
using namespace flash::utils;

namespace flash
{
    namespace desktop
    {
        class Clipboard: public Object
        {
            /**
             * The operating system clipboard.
             *
             *   Any data pasted to the system clipboard is available to other
             * applications. This may include insecure remote code running in
             * a web browser.Note: In Flash Player 10 applications, a paste operation from the clipboard first
             * requires a user event (such as a keyboard shortcut for the Paste command or a mouse click on the Paste command
             * in a context menu). Clipboard.getData()
             * will return the contents of the clipboard only if the InteractiveObject has received
             * and is acting on a paste event. Calling Clipboard.getData() under any other circumstances
             * will be unsuccessful. The same restriction applies in AIR for content outside the
             * application sandbox.The generalClipboard object is created automatically.
             * You cannot assign another instance of a Clipboard to this property.
             * Instead, you use the getData() and setData()
             * methods to read and write data to the existing object.You should always clear the clipboard before writing new data to it
             * to ensure that old data in all formats is erased.The generalClipboard object cannot be passed to the AIR NativeDragManager.
             * Create a new Clipboard object for native drag-and-drop operations in an AIR application.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.0
             */
        public:
            static flash::desktop::Clipboard *generalClipboard();

            /**
             * An array of strings containing the names of the data formats available
             * in this Clipboard object.
             *
             *   String constants for the names of the standard formats are defined in the
             * ClipboardFormats class. Other, application-defined, strings may also be used as format
             * names to transfer data as an object.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.0
             */
        public:
            std::vector<void *> formats();

            /**
             * Creates an empty Clipboard object.
             *
             *   Create Clipboard objects to hold the data of a native drag-and-drop gesture in Adobe AIR. Clipboard
             * objects can be used for only one drag-and-drop gesture; they cannot be reused.Do not create a Clipboard object for copy-and-paste operations. Use the single
             * Clipboard.generalClipboard object instead.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.0
             * @internal    the example located at examples\Clipboard.clipboard.1.as should not be displayed with FP10 docs because FP10 will throw an error when new Clipboard() is called.
             * @throws  IllegalOperationError new Clipboard() is not supported in Flash Player, since only the operating system clipboard can be used in Flash Player. For copy-and-paste operations involving the operating system clipboard, use the Clipboard.generalClipboard object rather than creating a new Clipboard object. Does not throw an error in an AIR application.
             */
        public:
            Clipboard();

            /**
             * Deletes all data representations from this Clipboard object.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.0
             * @throws  SecurityError Call to generalClipboard.clear() is not permitted in this context.
             *   In Flash Player, you can only call this method successfully during the processing of a user event
             *   (as in a key press or mouse click). In AIR, this restriction only applies to content outside of the
             *   application security sandbox.
             */
        public:
            void     clear();

            /**
             * Deletes the data representation for the specified format.
             * @param   format  The data format to remove.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.0
             * @throws  SecurityError Call to generalClipboard.clearData() is not permitted in this context.
             *   In Flash Player, you can only call this method successfully during the processing of a user event
             *   (as in a key press or mouse click). In AIR, this restriction only applies to content outside of the
             *   application security sandbox.
             */
        public:
            void     clearData(std::string format);

            /**
             * Adds a representation of the information to be transferred in the specified data format.
             *
             *   In the application sandbox of Adobe AIR, setData() can be called anytime. In other
             * contexts, setData() can only be called in response to a user-generated event such as
             * a key press or mouse click.Different representations of the same information can be added to the clipboard as
             * different formats, which increases the ability of other components or applications to
             * make use of the available data.
             * For example, an image could be added as bitmap data for use by image editing applications,
             * as a URL, and as an encoded PNG file for transfer to the native file system.The data parameter must be the appropriate data type for the specified format:FormatTypeDescriptionClipboardFormats.TEXT_FORMATStringstring dataClipboardFormats.HTML_FORMATStringHTML string dataClipboardFormats.URL_FORMATStringURL string (AIR only)ClipboardFormats.RICH_TEXT_FORMATByteArrayRich Text Format dataClipboardFormats.BITMAP_FORMATBitmapDatabitmap data (AIR only)ClipboardFormats.FILE_LIST_FORMATarray of Filean array of files (AIR only)Custom format nameanyobject reference and serialized cloneCustom format names cannot begin with "air:" or "flash:". To prevent name collisions
             * when using custom formats, you may want to use your application ID or a package name as a
             * prefix to the format, such as "com.example.applicationName.dataPacket".When transferring within or between applications, the serializable parameter
             * determines whether both a reference and a copy are available, or whether only a reference to
             * an object is available. Set serializable to true to make both the reference
             * and a copy of the data object available. Set serializable to false
             * to make only the object reference available. Object references are valid only within the current
             * application so setting serializable to false also means that the data
             * in that format is not available to other Flash Player or AIR applications. A component can choose to get
             * the reference or the copy of the object by setting the appropriate clipboard transfer mode
             * when accessing the data for that format.Note: The standard formats are always converted to native formats when data is pasted or
             * dragged outside a supported application, so the value of the serializable
             * parameter does not affect the availability of data in the standard formats to non-Flash-based applications.To defer rendering of the data for a format, use the setDataHandler() method instead.
             * If both the setData() and the setDataHandler() methods are used to add a
             * data representation with the same format name, then the handler function will never be called.Note: On Mac OS, when you set the format parameter to ClipboardFormats.URL_FORMAT,
             * the URL is transferred only if it is a valid URL. Otherwise, the Clipboard object is emptied (and calling
             * getData() returns null).
             * @param   format  The format of the data.
             * @param   data    The information to add.
             * @param   serializable    Specify true for objects that can be serialized (and deserialized).
             * @return  true if the data was succesfully set;
             *   false otherwise. In Flash Player, returns false when format is an
             *   unsupported member of ClipboardFormats. (Flash Player does not support ClipboardFormats.URL_FORMAT,
             *   ClipboardFormats.FILE_LIST_FORMAT, ClipboardFormats.FILE_PROMISE_LIST_FORMAT,
             *   or ClipboardFormats.BITMAP_FORMAT).
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.0
             * @throws  IllegalOperationError The Clipboard object requested is no longer in scope (which can occur
             *   with clipboards created for drag-and-drop operations).
             * @throws  SecurityError Reading from or writing to the clipboard is not permitted in this context.
             *   In Flash Player, you can only call this method successfully during the processing of a user event
             *   (as in a key press or mouse click). In AIR, this restriction only applies to content outside of the
             *   application security sandbox.
             * @throws  TypeError format or data is null.
             */
        public:
            bool     setData(std::string format, Object *data, bool serializable);

            /**
             * Adds a reference to a handler function that produces the data to be transfered.
             *
             *   Use a handler function to defer creation or rendering of the data until it is actually accessed.The handler function must return the appropriate data type for the specified format:FormatReturn TypeClipboardFormats.TEXT_FORMATStringClipboardFormats.HTML_FORMATStringClipboardFormats.URL_FORMATString (AIR only)ClipboardFormats.RICH_TEXT_FORMATByteArrayClipboardFormats.BITMAP_FORMATBitmapData (AIR only)ClipboardFormats.FILE_LIST_FORMATArray of File (AIR only)ClipboardFormats.FILE_PROMISE_LIST_FORMATArray of File (AIR only)Custom format nameNon-voidThe handler function is called when and only when the data in the specified format is read. Note that in some cases,
             * the operating system calls the function before a drop occurs. For example, when you use a handler function to
             * provide the data for a file dragged from an AIR application to the file system, the operating
             * system calls the data handler function as soon as the drag gesture leaves the AIR application   typically resulting
             * in an undesireable pause as the file data is downloaded or created. You can use a URLFilePromise for this purpose instead.Note that the underlying data can change between the time the handler is added and the time the data is
             * read unless your application takes steps to protect the data.
             * The behavior that occurs when data on the clipboard represented by a handler function is read more than once
             * is not guaranteed. The clipboard might return the data produced by the first function call or it might call the
             * function again. Do not rely on either behavior.In the application sandbox of Adobe AIR, setDataHandler() can be called anytime. In other
             * contexts, setDataHandler() can only be called in response to a user-generated event such as
             * a key press or mouse click.To add data directly to this Clipboard object, use the setData() method instead.
             * If both the setData() and the setDataHandler() methods are called with the same
             * format name, then the handler function is never called.Note: On Mac OS, when you set the format parameter to ClipboardFormats.URL_FORMAT,
             * the URL is transferred only if the handler function returns a valid URL. Otherwise, the Clipboard object is emptied
             * (and calling getData() returns null).
             * @param   format  A function that returns the data to be transferred.
             * @param   handler The format of the data.
             * @param   serializable    Specify true if the object returned by handler
             *   can be serialized (and deserialized).
             * @return  true if the handler was succesfully set;
             *   false otherwise.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.0
             * @throws  TypeError format or handler is null.
             * @throws  IllegalOperationError The Clipboard object requested is no longer in scope (AIR only).
             * @throws  SecurityError Reading from or writing to the clipboard is not permitted in this context.
             *   In Flash Player, you can only call this method successfully during the processing of a user event
             *   (such as a key press or mouse click). In AIR, this restriction only applies to content outside of the
             *   application security sandbox.
             */
        public:
            bool     setDataHandler(std::string format, Function *handler, bool serializable);

            /**
             * Gets the clipboard data if data in the specified format is present.
             *
             *   Flash Player requires that the getData() be called in a paste event handler.
             * In AIR, this restriction only applies to content outside of the application security sandbox.When a standard data format is accessed, the data is returned as a new
             * object of the corresponding Flash data type.When an application-defined format is accessed, the value of the
             * transferMode parameter determines whether a reference to the original
             * object or an anonymous object containing a serialized copy of the original
             * object is returned. When an originalPreferred or clonePreferred mode is specified,
             * Flash Player or AIR returns the alternate version if the preferred version is not available.
             * When an originalOnly or cloneOnly mode is specified, Flash Player or AIR returns
             * null if the requested version is not available.
             * @param   format  The data format to return. The format string can contain one of the standard
             *   names defined in the ClipboardFormats class, or an application-defined name.
             * @param   transferMode    Specifies whether to return a reference or serialized copy
             *   when an application-defined data format is accessed. The value must be one
             *   of the names defined in the ClipboardTransferMode class. This value is
             *   ignored for the standard data formats; a copy is always returned.
             * @return  An object of the type corresponding to the data format.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.0
             * @throws  Error transferMode is not one of the names defined in the ClipboardTransferMode class.
             * @throws  IllegalOperationError The Clipboard object requested is no longer in scope (AIR only).
             * @throws  SecurityError Reading from or writing to the clipboard is not permitted in this context.
             *   In Flash Player, you can only call this method successfully during the processing of a paste event.
             *   In AIR, this restriction only applies to content outside of the application security sandbox.
             */
        public:
            Object  *getData(std::string format, std::string transferMode);

            /**
             * Checks whether data in the specified format exists in this Clipboard object.
             *
             *   Use the constants in the ClipboardFormats class to reference the standard format names.
             * @param   format  The format type to check.
             * @return  true, if data in the specified format is present.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @throws  IllegalOperationError The Clipboard object requested is no longer in scope.
             * @throws  SecurityError Reading from or writing to the clipboard is not permitted in this context.
             */
        public:
            bool     hasFormat(std::string format);
        };
    }
}

#endif // FLEX11_6_FLASH_DESKTOP_CLIPBOARD_AS
#endif // __cplusplus

