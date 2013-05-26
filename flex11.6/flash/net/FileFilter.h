#if !defined(FLEX11_6_FLASH_NET_FILEFILTER_AS)
#define FLEX11_6_FLASH_NET_FILEFILTER_AS
#if defined(__cplusplus)


/**
 * The FileFilter class is used to indicate what files on the user's system are shown
 * in the file-browsing dialog box that is displayed when the <codeph class="+ topic/ph pr-d/codeph ">FileReference.browse()</codeph>
 * method, the <codeph class="+ topic/ph pr-d/codeph ">FileReferenceList.browse()</codeph> method is called or a
 * browse method of a File, FileReference, or FileReferenceList object is called.
 * FileFilter instances are passed as a value for the optional <codeph class="+ topic/ph pr-d/codeph ">typeFilter</codeph> parameter to the method.
 * If you use a FileFilter instance, extensions and file types that aren't specified in the FileFilter instance
 * are filtered out; that is, they are not available to the user for selection.
 * If no FileFilter object is passed to the method, all files are shown in the dialog box.
 *
 *   <p class="- topic/p ">You can use FileFilter instances in one of two ways:</p><ul class="- topic/ul "><li class="- topic/li ">A description with file extensions only</li><li class="- topic/li ">A description with file extensions and Macintosh file types</li></ul><p class="- topic/p ">The two formats are not interchangeable within a single call to the browse method.
 * You must use one or the other.</p><p class="- topic/p ">You can pass one or more FileFilter instances to the browse method, as shown in the following:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * var imagesFilter:FileFilter = new FileFilter("Images", "~~.jpg;~~.gif;~~.png");
 * var docFilter:FileFilter = new FileFilter("Documents", "~~.pdf;~~.doc;~~.txt");
 * var myFileReference:FileReference = new FileReference();
 * myFileReference.browse([imagesFilter, docFilter]);
 * </codeblock><p class="- topic/p ">Or in an AIR application:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * var imagesFilter:FileFilter = new FileFilter("Images", "~~.jpg;~~.gif;~~.png");
 * var docFilter:FileFilter = new FileFilter("Documents", "~~.pdf;~~.doc;~~.txt");
 * var myFile:File = new File();
 * myFile.browseForOpen("Open", [imagesFilter, docFilter]);
 * </codeblock><p class="- topic/p ">The list of extensions in the <codeph class="+ topic/ph pr-d/codeph ">FileFilter.extension</codeph> property
 * is used to filter the files shown in the file browsing dialog. The list is not actually
 * displayed in the dialog box; to display the file types
 * for users, you must list the file types in the description string as well as in the extension
 * list. The description string is displayed in the dialog box in Windows and Linux.
 * (It is not used on the Macintosh<sup class="+ topic/ph hi-d/sup ">  </sup>.) On the Macintosh, if you supply a list of Macintosh file types,
 * that list is used to filter the files. If not, the list of file extensions is used. </p>
 * @langversion 3.0
 * @playerversion   Flash 9
 */

#include "flex11.6.h"



namespace flash
{
    namespace net
    {
        class FileFilter : public Object
        {
            /**
             * The description string for the filter. The description
             * is visible to the user in the dialog box that opens
             * when FileReference.browse()
             * or FileReferenceList.browse() is called.
             * The description string contains a string, such as
             * "Images (~~.gif, ~~.jpg, ~~.png)", that can
             * help instruct the user on what file types can be uploaded
             * or downloaded. Note that the actual file types that are supported by
             * this FileReference object are stored in the extension
             * property.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            std::string       description();
        public:
            void         description(std::string value);

            /**
             * A list of file extensions. This list indicates the types of files
             * that you want to show in the file-browsing dialog box. (The list
             * is not visible to the user; the user sees only the value of the
             * description property.) The extension property contains
             * a semicolon-delimited list of file extensions,
             * with a wildcard (~~) preceding each extension, as shown
             * in the following string: "~~.jpg;~~.gif;~~.png".
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            std::string       extension();
        public:
            void         extension(std::string value);

            /**
             * A list of Macintosh file types. This list indicates the types of files
             * that you want to show in the file-browsing dialog box. (This list
             * itself is not visible to the user; the user sees only the value of the
             * description property.) The macType property contains
             * a semicolon-delimited list of Macintosh file types, as shown
             * in the following string: "JPEG;jp2_;GIFF".
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            std::string       macType();
        public:
            void         macType(std::string value);

            /**
             * Creates a new FileFilter instance.
             * @param   description The description string that is visible to users when they select files for uploading.
             * @param   extension   A list of file extensions that indicate which file formats are visible to users
             *   when they select files for uploading.
             * @param   macType A list of Macintosh file types that indicate which file types are visible to
             *   users when they select files for uploading. If no value is passed, this parameter is set to null.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            FileFilter(std::string description, std::string extension, std::string macType="");
        };
    }
}

#endif // FLEX11_6_FLASH_NET_FILEFILTER_AS
#endif // __cplusplus

