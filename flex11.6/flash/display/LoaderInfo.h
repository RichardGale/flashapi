#if !defined(FLEX11_6_FLASH_DISPLAY_LOADERINFO_AS)
#define FLEX11_6_FLASH_DISPLAY_LOADERINFO_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"

namespace flash
{
    namespace system
    {
        class ApplicationDomain;
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
    namespace display
    {
        class Loader;
    }
}
namespace flash
{
    namespace display
    {
        class DisplayObject;
    }
}
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}
namespace flash
{
    namespace events
    {
        class UncaughtErrorEvents;
    }
}

/**
 * Dispatched when a network request is made over HTTP and an HTTP status code can be detected.
 * @eventType   flash.events.HTTPStatusEvent.HTTP_STATUS
 */
//[Event(name="httpStatus",type="flash.events.HTTPStatusEvent")]

/**
 * Dispatched by a LoaderInfo object whenever a loaded object is removed by using the unload()
 * method of the Loader object, or when a second load is performed by the same Loader object and the
 * original content is removed prior to the load beginning.
 * @eventType   flash.events.Event.UNLOAD
 */
//[Event(name="unload",type="flash.events.Event")]

/**
 * Dispatched when data is received as the download operation progresses.
 * @eventType   flash.events.ProgressEvent.PROGRESS
 */
//[Event(name="progress",type="flash.events.ProgressEvent")]

/**
 * Dispatched when a load operation starts.
 * @eventType   flash.events.Event.OPEN
 */
//[Event(name="open",type="flash.events.Event")]

/**
 * Dispatched when an input or output error occurs that causes a load operation to fail.
 * @eventType   flash.events.IOErrorEvent.IO_ERROR
 */
//[Event(name="ioError",type="flash.events.IOErrorEvent")]

/**
 * Dispatched when the properties and methods of a loaded SWF file are
 * accessible and ready for use.
 * @eventType   flash.events.Event.INIT
 */
//[Event(name="init",type="flash.events.Event")]

/**
 * Dispatched when data has loaded successfully.
 * @eventType   flash.events.Event.COMPLETE
 */
//[Event(name="complete",type="flash.events.Event")]

using namespace flash::display;
using namespace flash::events;
using namespace flash::system;
using namespace flash::utils;

namespace flash
{
    namespace display
    {
        /**
         * The LoaderInfo class provides information about a loaded SWF file or a loaded image file
         * (JPEG, GIF, or PNG).  LoaderInfo objects are available for any display object.
         * The information provided includes load progress, the URLs of the loader and
         * loaded content, the number of bytes total for the media, and the nominal height and width of the
         * media.
         *
         *   <p class="- topic/p ">You can access LoaderInfo objects in two ways: </p><ul class="- topic/ul "><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">contentLoaderInfo</codeph> property of a flash.display.Loader object
         * The <codeph class="+ topic/ph pr-d/codeph ">contentLoaderInfo</codeph> property is always available for any Loader object.
         * For a Loader object that has not called the <codeph class="+ topic/ph pr-d/codeph ">load()</codeph> or <codeph class="+ topic/ph pr-d/codeph ">loadBytes()</codeph>
         * method, or that has not sufficiently loaded, attempting to access many of the properties of the
         * <codeph class="+ topic/ph pr-d/codeph ">contentLoaderInfo</codeph> property throws an error.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">loaderInfo</codeph> property of a display object. </li></ul><p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">contentLoaderInfo</codeph> property of a Loader object provides information about
         * the content that the Loader object is loading, whereas the <codeph class="+ topic/ph pr-d/codeph ">loaderInfo</codeph> property of
         * a DisplayObject provides information about the root SWF file for that display object. </p><p class="- topic/p ">When you use a Loader object to load a display object (such as a SWF file or a bitmap), the
         * <codeph class="+ topic/ph pr-d/codeph ">loaderInfo</codeph> property of the display object is the same as the <codeph class="+ topic/ph pr-d/codeph ">contentLoaderInfo</codeph>
         * property of the Loader object (<codeph class="+ topic/ph pr-d/codeph ">DisplayObject.loaderInfo = Loader.contentLoaderInfo</codeph>).
         * Because the instance of the main class of the SWF file has
         * no Loader object, the <codeph class="+ topic/ph pr-d/codeph ">loaderInfo</codeph> property is the only way to
         * access the LoaderInfo for the instance of the main class of the SWF file.</p><p class="- topic/p ">The following diagram shows the different uses of the LoaderInfo object   for the instance of the main class of
         * the SWF file, for the <codeph class="+ topic/ph pr-d/codeph ">contentLoaderInfo</codeph> property of a Loader object, and for the <codeph class="+ topic/ph pr-d/codeph ">loaderInfo</codeph>
         * property of a loaded object:</p><p class="- topic/p "><adobeimage alt="An image of different LoaderInfo situations" href="../../images/loaderInfo_object.jpg" placement="inline" class="+ topic/image adobe-d/adobeimage " /></p><p class="- topic/p ">When a loading operation is not complete, some properties of the <codeph class="+ topic/ph pr-d/codeph ">contentLoaderInfo</codeph>
         * property of a Loader object are not available.  You can obtain some properties, such as
         * <codeph class="+ topic/ph pr-d/codeph ">bytesLoaded</codeph>, <codeph class="+ topic/ph pr-d/codeph ">bytesTotal</codeph>, <codeph class="+ topic/ph pr-d/codeph ">url</codeph>, <codeph class="+ topic/ph pr-d/codeph ">loaderURL</codeph>,
         * and <codeph class="+ topic/ph pr-d/codeph ">applicationDomain</codeph>. When the <codeph class="+ topic/ph pr-d/codeph ">loaderInfo</codeph> object dispatches the
         * <codeph class="+ topic/ph pr-d/codeph ">init</codeph> event, you can access all properties of the <codeph class="+ topic/ph pr-d/codeph ">loaderInfo</codeph> object and
         * the loaded image or SWF file.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> All properties of LoaderInfo objects are read-only.</p><p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">EventDispatcher.dispatchEvent()</codeph> method
         *
         *   is not applicable to LoaderInfo objects. If you call <codeph class="+ topic/ph pr-d/codeph ">dispatchEvent()</codeph>
         * on a LoaderInfo object, an IllegalOperationError exception is thrown.</p>
         *
         *   EXAMPLE:
         *
         *   The following example uses the LoaderInfoExample class to display an image on
         * the stage.  This is accomplished by performing the following steps:
         * <ol class="- topic/ol "><li class="- topic/li ">A property <codeph class="+ topic/ph pr-d/codeph ">url</codeph> is created, which is the location and name of the image.</li><li class="- topic/li ">The class constructor creates a Loader object named <codeph class="+ topic/ph pr-d/codeph ">loader</codeph>.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">loader</codeph> object instantiates an event listener to ensure that the image loads properly.</li><li class="- topic/li ">The constructor creates a new instance of a URLRequest object, <codeph class="+ topic/ph pr-d/codeph ">request</codeph>,
         * with <codeph class="+ topic/ph pr-d/codeph ">url</codeph> passed so that the file name and location are known.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">request</codeph> object is then passed to the <codeph class="+ topic/ph pr-d/codeph ">load()</codeph> method of the
         * <codeph class="+ topic/ph pr-d/codeph ">loader</codeph> object, which loads the image onto the display list.</li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Important:</b> This example requires that you add a file named Image.gif in the same directory
         * as the compiled SWF file. Use an image that has an area that fits within the dimensions of the main SWF file.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Loader;
         * import flash.display.LoaderInfo;
         * import flash.display.Sprite;
         * import flash.events.*;
         * import flash.net.URLRequest;
         *
         *   public class LoaderInfoExample extends Sprite {
         * private var url:String = "Image.gif";
         *
         *   public function LoaderInfoExample() {
         * var loader:Loader = new Loader();
         * loader.contentLoaderInfo.addEventListener(Event.INIT, initHandler);
         * loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
         * var request:URLRequest = new URLRequest(url);
         * loader.load(request);
         * addChild(loader);
         * }
         *
         *   private function initHandler(event:Event):void {
         * var loader:Loader = Loader(event.target.loader);
         * var info:LoaderInfo = LoaderInfo(loader.contentLoaderInfo);
         * trace("initHandler: loaderURL=" + info.loaderURL + " url=" + info.url);
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
         * @internal    Update the places LoaderInfo can be obtained from (playerglobal.as) and double-check loader vs. loadee.
         */
        class LoaderInfo : public flash::events::EventDispatcher
        {
            /**
             * The URL of the SWF file that initiated the loading of the media
             * described by this LoaderInfo object.  For the instance of the main class of the SWF file, this
             * URL is the same as the SWF file's own URL.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string       loaderURL();

            /**
             * The URL of the media being loaded.
             *
             *   Before the first progress event is dispatched by this LoaderInfo
             * object's corresponding Loader object, the value of the url property
             * might reflect only the initial URL specified in the call to the load()
             * method  of the Loader object.  After the first progress event, the
             * url property reflects the media's final URL, after any redirects and relative
             * URLs are resolved.In some cases, the value of the url property is truncated; see the
             * isURLInaccessible property for details.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string       url();

            /**
             * Indicates if the LoaderInfo.url property has been
             * truncated. When the isURLInaccessible value is true the
             * LoaderInfo.url value is only the domain of the final URL from which the content loaded.
             * For example, the property is truncated if the content is loaded from http://www.adobe.com/assets/hello.swf,
             * and the LoaderInfo.url property has the value http://www.adobe.com. The isURLInaccessible
             * value is true only when all of the following are also true:
             *
             *   An HTTP redirect occurred while loading the content.The SWF file calling Loader.load() is from a different domain than
             * the content's final URL.The SWF file calling Loader.load() does not have permission to access
             * the content. Permission is granted to access the content the same way permission is granted for
             * BitmapData.draw():
             * call Security.allowDomain() to access a SWF file
             * (or for non-SWF file content, establish a policy file and use the LoaderContext.checkPolicyFile
             * property).Note: The isURLInaccessible property was added for Flash Player 10.1 and AIR 2.0.
             * However, this property is made available to SWF files of all versions when the
             * Flash runtime supports it. So, using some authoring tools in "strict mode" causes a compilation error. To work around the error
             * use the indirect syntax myLoaderInfo["isURLInaccessible"], or disable strict mode. If you are using Flash Professional CS5
             * or Flex SDK 4.1, you can use and compile this API for runtimes released before Flash Player 10.1 and AIR 2.For application content in AIR, the value of this property is always false.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            bool      isURLInaccessible();

            /**
             * The number of bytes that are loaded for the media. When this number equals
             * the value of bytesTotal, all of the bytes are loaded.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int         bytesLoaded();

            /**
             * The number of compressed bytes in the entire media file.
             *
             *   Before the first progress event is dispatched by
             * this LoaderInfo object's corresponding Loader object, bytesTotal is 0.
             * After the first progress event from the Loader object, bytesTotal
             * reflects the actual number of bytes to be downloaded.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int         bytesTotal();

            /**
             * When an external SWF file is loaded, all ActionScript 3.0 definitions contained in the loaded
             * class are stored in the applicationDomain property.
             *
             *   All code in a SWF file is defined to exist in an application domain. The current application
             * domain is where your main application runs. The system domain contains all application domains,
             * including the current domain and all classes used by Flash Player or Adobe AIR.All application domains, except the system domain, have an associated parent domain.
             * The parent domain of your main application's applicationDomain is the system domain.
             * Loaded classes are defined only when their parent doesn't already define them.
             * You cannot override a loaded class definition with a newer definition.For usage examples of application domains, see the "Client System Environment" chapter
             * in the ActionScript 3.0 Developer's Guide.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    Need better description and example.
             * @throws  SecurityError This security sandbox of the caller is not allowed to access this ApplicationDomain.
             */
        public:
            flash::system::ApplicationDomain *applicationDomain();

            /**
             * The file format version of the loaded SWF file.
             *
             *   The file format is specified using the enumerations in the
             * SWFVersion class, such as SWFVersion.FLASH7 and SWFVersion.FLASH9.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error If the file is not downloaded sufficiently to retrieve the requested information.
             * @throws  Error If the file is not a SWF file.
             */
        public:
            unsigned int         swfVersion();

            /**
             * The ActionScript version of the loaded SWF file.
             *
             *   The language version is specified by using the enumerations in the
             * ActionScriptVersion class, such as ActionScriptVersion.ACTIONSCRIPT2
             * and ActionScriptVersion.ACTIONSCRIPT3.
             *
             *   Note: This property always has a value of either ActionScriptVersion.ACTIONSCRIPT2 or
             * ActionScriptVersion.ACTIONSCRIPT3.  ActionScript 1.0 and 2.0 are
             * both reported as ActionScriptVersion.ACTIONSCRIPT2 (version 2.0).  This property
             * only distinguishes ActionScript 1.0 and 2.0 from ActionScript 3.0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error If the file is not downloaded sufficiently to retrieve the requested information.
             * @throws  Error If the file is not a SWF file.
             */
        public:
            unsigned int         actionScriptVersion();

            /**
             * The nominal frame rate, in frames per second, of the loaded SWF file. This
             * number is often an integer, but need not be.
             *
             *   This value may differ from the actual frame rate in use.
             * Flash Player or Adobe AIR only uses a single frame rate for all loaded SWF files at
             * any one time, and this frame rate is determined by the nominal
             * frame rate of the main SWF file. Also, the main frame rate may not be able to be achieved, depending on hardware, sound synchronization,
             * and other factors.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error If the file is not downloaded sufficiently to retrieve the requested information.
             * @throws  Error If the file is not a SWF file.
             */
        public:
            float       frameRate();

            /**
             * An object that contains name-value pairs that represent the parameters provided
             * to the loaded SWF file.
             *
             *   You can use a for-in loop to extract all the names and values
             * from the parameters object.The two sources of parameters are: the query string in the
             * URL of the main SWF file, and the value of the FlashVars HTML parameter (this affects
             * only the main SWF file).The parameters property replaces the ActionScript 1.0 and 2.0 technique of
             * providing SWF file parameters as properties of the main timeline.The value of the parameters property is null for Loader objects
             * that contain SWF files that use ActionScript 1.0 or 2.0. It is only
             * non-null for Loader objects that contain SWF files that use ActionScript 3.0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            Object       *parameters();

            /**
             * The nominal width of the loaded content. This value might differ from the actual
             * width at which the content is displayed, since the loaded content or its parent
             * display objects might be scaled.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error If the file is not downloaded sufficiently to retrieve the requested information.
             */
        public:
            int          width();

            /**
             * The nominal height of the loaded file. This value might differ from the actual
             * height at which the content is displayed, since the loaded content or its parent
             * display objects might be scaled.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error If the file is not downloaded sufficiently to retrieve the requested information.
             */
        public:
            int          height();

            /**
             * The MIME type of the loaded file. The value is null if not enough of the file has loaded
             * in order to determine the type. The following list gives the possible values:
             *
             *   "application/x-shockwave-flash""image/jpeg""image/gif""image/png"
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string       contentType();

            /**
             * An EventDispatcher instance that can be used to exchange events across security boundaries.
             * Even when the Loader object and the loaded content originate from security domains that do not trust
             * one another, both can access sharedEvents and send and receive events via this object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::EventDispatcher *sharedEvents();

            /**
             * A object that can be set by code in the Loader object's sandbox to expose properties and methods that can be accessed
             * by the loaded content's code. This sandbox bridge lets content from a non-application domain have controlled
             * access to scripts in the AIR application sandbox, and vice versa. The sandbox bridge serves as a gateway between
             * the sandboxes, providing explicit interaction between application and non-application security sandboxes.
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  SecurityError Only content in the Loader object's sandbox can set this property.
             */
        public:
            Object       *parentSandboxBridge();
        public:
            void         parentSandboxBridge(Object *door);

            /**
             * A object that can be set by the loaded content's code to expose properties and methods that can be accessed
             * by code in the Loader object's sandbox. This sandbox bridge lets content from a non-application domain have
             * controlled access to scripts in the AIR application sandbox, and vice versa. The sandbox bridge serves as a gateway between
             * the sandboxes, providing explicit interaction between application and non-application security sandboxes.
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  SecurityError Only content in the loaded content's sandbox can set this property.
             */
        public:
            Object       *childSandboxBridge();
        public:
            void         childSandboxBridge(Object *door);

            /**
             * Expresses the domain relationship between the loader and the content: true if they have
             * the same origin domain; false otherwise.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error  Thrown if the file is not downloaded sufficiently
             *   to retrieve the requested information.
             */
        public:
            bool      sameDomain();

            /**
             * Expresses the trust relationship from content (child) to the Loader (parent).
             * If the child has allowed the parent access, true; otherwise,
             * false. This property is set to true if the child object
             * has called the allowDomain() method to grant permission to the parent domain
             * or if a URL policy is loaded at the child domain that grants permission
             * to the parent domain. If child and parent are in
             * the same domain, this property is set to true.
             *
             *   For more information related to security, see the Flash Player Developer Center Topic:
             * Security.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error  Thrown if the file is not downloaded sufficiently
             *   to retrieve the requested information.
             */
        public:
            bool      childAllowsParent();

            /**
             * Expresses the trust relationship from Loader (parent) to the content (child).
             * If the parent has allowed the child access, true; otherwise,
             * false. This property is set to true if the parent object
             * called the allowDomain() method to grant permission to the child domain
             * or if a URL policy file is loaded at the parent domain granting permission
             * to the child domain. If child and parent are in
             * the same domain, this property is set to true.
             *
             *   For more information related to security, see the Flash Player Developer Center Topic:
             * Security.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error  Thrown if the file is not downloaded sufficiently
             *   to retrieve the requested information.
             */
        public:
            bool      parentAllowsChild();

            /**
             * The Loader object associated with this LoaderInfo object. If this LoaderInfo object
             * is the loaderInfo property of the instance of the main class of the SWF file, no
             * Loader object is associated.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError If the object accessing this API is prevented from
             *   accessing the Loader object because of security restrictions. This can occur,
             *   for instance, when a loaded SWF file attempts to access its loaderInfo.loader
             *   property and it is not granted security permission to access the loading SWF file.
             *
             *     For more information related to security, see the Flash Player Developer Center Topic:
             *   Security.
             */
        public:
            flash::display::Loader *loader();

            /**
             * The loaded object associated with this LoaderInfo object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError If the object accessing this API is prevented from
             *   accessing the loaded object due to security restrictions. This situation can occur,
             *   for instance, when a Loader object attempts to access the contentLoaderInfo.content
             *   property and it is not granted security permission to access the loaded content.
             *
             *     For more information related to security, see the Flash Player Developer Center Topic:
             *   Security.
             */
        public:
            flash::display::DisplayObject *content();

            /**
             * The bytes associated with a LoaderInfo object.
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             * @playerversion   Lite 4
             * @throws  SecurityError If the object accessing this API is prevented from
             *   accessing the loaded object due to security restrictions. This situation can occur,
             *   for instance, when a Loader object attempts to access the contentLoaderInfo.content
             *   property and it is not granted security permission to access the loaded content.
             *
             *     For more information related to security, see the Flash Player Developer Center Topic:
             *   Security.
             */
        public:
            flash::utils::ByteArray *bytes();

            /**
             * An object that dispatches an uncaughtError event when an unhandled error
             * occurs in code in this LoaderInfo object's SWF file. An uncaught error happens when
             * an error is thrown outside of any try..catch blocks or when an ErrorEvent
             * object is dispatched with no registered listeners.
             *
             *   This property is created when the SWF associated with this LoaderInfo has finished
             * loading. Until then the uncaughtErrorEvents property is null.
             * In an ActionScript-only project, you can access this property during or after the execution
             * of the constructor function of the main class of the SWF file. For a Flex project,
             * the uncaughtErrorEvents property is available after the
             * applicationComplete event is dispatched.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            flash::events::UncaughtErrorEvents *uncaughtErrorEvents();

            /**
             * Returns the LoaderInfo object associated with a SWF file defined as an object.
             * @param   object  The object for which you want to get an associated LoaderInfo object.
             * @return  The associated LoaderInfo object. Returns null when called
             *   in non-debugger builds (or when debugging is not enabled) or if the referenced object
             *   does not have an associated LoaderInfo object (such as some objects used by the AIR runtime).
             * @langversion 3.0
             * @playerversion   Flash 9.0.115.0
             * @playerversion   Lite 4
             * @throws  SecurityError The caller is not running in the local trusted sandbox.
             */
        public:
            static flash::display::LoaderInfo *getLoaderInfoByDefinition(Object *object);

        public:
            LoaderInfo();

        public:
            bool  dispatchEvent(Event *event);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_LOADERINFO_AS
#endif // __cplusplus

