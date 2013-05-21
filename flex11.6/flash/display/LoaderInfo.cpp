

#include "LoaderInfo.h"
#include "flash/events/EventDispatcher.h"
#include "flash/display/LoaderInfo.h"
#include "flash/system/ApplicationDomain.h"
#include "flash/events/Event.h"
#include "flash/display/Loader.h"
#include "flash/display/DisplayObject.h"
#include "flash/utils/ByteArray.h"
#include "flash/events/UncaughtErrorEvents.h"

    /**
     * Dispatched when a network request is made over HTTP and an HTTP status code can be detected.
     * @eventType   flash.events.HTTPStatusEvent.HTTP_STATUS
     */

using namespace flash::display;
using namespace flash::events;
using namespace flash::system;
using namespace flash::utils;

namespace flash {
namespace display {


        /**
         * The URL of the SWF file that initiated the loading of the media
         * described by this LoaderInfo object.  For the instance of the main class of the SWF file, this
         * URL is the same as the SWF file's own URL.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string LoaderInfo::loaderURL()         ;

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
        std::string LoaderInfo::url()         ;

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
        bool LoaderInfo::isURLInaccessible()          ;

        /**
         * The number of bytes that are loaded for the media. When this number equals
         * the value of bytesTotal, all of the bytes are loaded.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        unsigned int LoaderInfo::bytesLoaded()       ;

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
        unsigned int LoaderInfo::bytesTotal()       ;

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
        flash::system::ApplicationDomain* LoaderInfo::applicationDomain()                                 ;

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
        unsigned int LoaderInfo::swfVersion()       ;

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
        unsigned int LoaderInfo::actionScriptVersion()       ;

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
        float LoaderInfo::frameRate()         ;

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
        Object* LoaderInfo::parameters()         ;

        /**
         * The nominal width of the loaded content. This value might differ from the actual
         * width at which the content is displayed, since the loaded content or its parent
         * display objects might be scaled.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  Error If the file is not downloaded sufficiently to retrieve the requested information.
         */
        int LoaderInfo::width()      ;

        /**
         * The nominal height of the loaded file. This value might differ from the actual
         * height at which the content is displayed, since the loaded content or its parent
         * display objects might be scaled.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  Error If the file is not downloaded sufficiently to retrieve the requested information.
         */
        int LoaderInfo::height()      ;

        /**
         * The MIME type of the loaded file. The value is null if not enough of the file has loaded 
         * in order to determine the type. The following list gives the possible values:
         * 
         *   "application/x-shockwave-flash""image/jpeg""image/gif""image/png"
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string LoaderInfo::contentType()         ;

        /**
         * An EventDispatcher instance that can be used to exchange events across security boundaries.
         * Even when the Loader object and the loaded content originate from security domains that do not trust
         * one another, both can access sharedEvents and send and receive events via this object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::events::EventDispatcher* LoaderInfo::sharedEvents()                               ;

        /**
         * A object that can be set by code in the Loader object's sandbox to expose properties and methods that can be accessed 
         * by the loaded content's code. This sandbox bridge lets content from a non-application domain have controlled 
         * access to scripts in the AIR application sandbox, and vice versa. The sandbox bridge serves as a gateway between 
         * the sandboxes, providing explicit interaction between application and non-application security sandboxes.
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         * @throws  SecurityError Only content in the Loader object's sandbox can set this property.
         */
        Object* LoaderInfo::parentSandboxBridge()         ;
        void LoaderInfo::parentSandboxBridge(Object* door)       ;

        /**
         * A object that can be set by the loaded content's code to expose properties and methods that can be accessed 
         * by code in the Loader object's sandbox. This sandbox bridge lets content from a non-application domain have 
         * controlled access to scripts in the AIR application sandbox, and vice versa. The sandbox bridge serves as a gateway between 
         * the sandboxes, providing explicit interaction between application and non-application security sandboxes.
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         * @throws  SecurityError Only content in the loaded content's sandbox can set this property.
         */
        Object* LoaderInfo::childSandboxBridge()         ;
        void LoaderInfo::childSandboxBridge(Object* door)       ;

        /**
         * Expresses the domain relationship between the loader and the content: true if they have 
         * the same origin domain; false otherwise.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  Error  Thrown if the file is not downloaded sufficiently 
         *   to retrieve the requested information.
         */
        bool LoaderInfo::sameDomain()          ;

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
        bool LoaderInfo::childAllowsParent()          ;

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
        bool LoaderInfo::parentAllowsChild()          ;

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
        flash::display::Loader* LoaderInfo::loader()                       ;

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
        flash::display::DisplayObject* LoaderInfo::content()                              ;

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
        flash::utils::ByteArray* LoaderInfo::bytes()                        ;

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
        flash::events::UncaughtErrorEvents* LoaderInfo::uncaughtErrorEvents()                                   ;

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
        flash::display::LoaderInfo* LoaderInfo::getLoaderInfoByDefinition(Object* object)                           ;

        LoaderInfo::LoaderInfo();

        bool LoaderInfo::dispatchEvent(Event* event)          ;
}
}

