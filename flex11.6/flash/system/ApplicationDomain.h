#if !defined(FLEX11_6_FLASH_SYSTEM_APPLICATIONDOMAIN_AS)
#define FLEX11_6_FLASH_SYSTEM_APPLICATIONDOMAIN_AS
#if defined(__cplusplus)


#include "flex11.6.h"

namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

/**
 * The ApplicationDomain class is a container for discrete groups of class definitions.
 * Application domains are used to partition classes that are in the same security domain.
 * They allow multiple definitions of the same class to exist and allow children to reuse parent
 * definitions.
 *
 *   <p class="- topic/p ">Application domains are used when an external SWF file is loaded through the Loader class.
 * All ActionScript 3.0 definitions in the loaded SWF file are stored in the application
 * domain, which is specified by the <codeph class="+ topic/ph pr-d/codeph ">applicationDomain</codeph> property of the LoaderContext
 * object that you pass as a <codeph class="+ topic/ph pr-d/codeph ">context</codeph> parameter of the Loader object's <codeph class="+ topic/ph pr-d/codeph ">load()</codeph> or
 * <codeph class="+ topic/ph pr-d/codeph ">loadBytes()</codeph> method. The LoaderInfo object also contains an
 * <codeph class="+ topic/ph pr-d/codeph ">applicationDomain</codeph> property, which is read-only.</p><p class="- topic/p ">All code in a SWF file is defined to exist in an application domain. The current application
 * domain is where your main application runs. The system domain contains all application domains,
 * including the current domain, which means that it contains all Flash Player classes.</p><p class="- topic/p ">Every application domain, except the system domain, has an associated parent domain.
 * The parent domain of your main application's application domain is the system domain.
 * Loaded classes are defined only when their parent doesn't already define them.
 * You cannot override a loaded class definition with a newer definition.</p><p class="- topic/p ">For usage examples of application domains, see the <i class="+ topic/ph hi-d/i ">ActionScript 3.0 Developer's Guide</i>.</p><p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">ApplicationDomain()</codeph> constructor function allows you to create an ApplicationDomain object.</p>
 *
 *   EXAMPLE:
 *
 *   The following example demonstrates runtime class loading as well as how to call public methods of a class that reside in another SWF.
 * <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Notes:</b></p><ul class="- topic/ul "><li class="- topic/li ">Since the ClassLoader class loads a SWF file, local security needs to be at the file system level.</li><li class="- topic/li ">To run this example, you must have a swf file called RuntimeClasses.swf existing in the same folder
 * as the ApplicationDomainExample.swf file.</li></ul><p class="- topic/p ">Begin by creating the RuntimeClasses.swf file from the following code:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * public class RuntimeClasses extends Sprite
 * {
 * public function RuntimeClasses()
 * {}
 *
 *   public function greet():String {
 * return("Hello World");
 * }
 * }
 * }
 * </codeblock><p class="- topic/p ">Then implement the following code:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.DisplayObject;
 * import flash.display.Sprite;
 * import flash.errors.IllegalOperationError;
 * import flash.events.Event;
 * import flash.text.TextField;
 *
 *   public class ApplicationDomainExample extends Sprite {
 * private var loader:ClassLoader;
 * private var tf:TextField = new TextField();
 *
 *   public function ApplicationDomainExample() {
 * addChild(tf);
 *
 *   loader = new ClassLoader();
 * loader.addEventListener(ClassLoader.LOAD_ERROR,loadErrorHandler);
 * loader.addEventListener(ClassLoader.CLASS_LOADED,classLoadedHandler);
 * loader.load("RuntimeClasses.swf");
 * }
 *
 *   private function loadErrorHandler(e:Event):void {
 * tf.text = "Load failed";
 * throw new IllegalOperationError("Cannot load the specified file.");
 * }
 *
 *   private function classLoadedHandler(e:Event):void {
 * var runtimeClassRef:Class = loader.getClass("RuntimeClasses");
 * var greeter:Object = new runtimeClassRef();
 *
 *   tf.text = greeter.greet();
 * }
 * }
 * }
 *
 *   import flash.display.Loader;
 * import flash.errors.IllegalOperationError;
 * import flash.events.Event;
 * import flash.events.EventDispatcher;
 * import flash.events.IOErrorEvent;
 * import flash.events.SecurityErrorEvent;
 * import flash.net.URLRequest;
 * import flash.system.ApplicationDomain;
 * import flash.system.LoaderContext;
 *
 *   class ClassLoader extends EventDispatcher {
 * public static var CLASS_LOADED:String = "classLoaded";
 * public static var LOAD_ERROR:String = "loadError";
 * private var loader:Loader;
 * private var swfLib:String;
 * private var request:URLRequest;
 * private var loadedClass:Class;
 *
 *   public function ClassLoader() {
 *
 *   loader = new Loader();
 * loader.contentLoaderInfo.addEventListener(Event.COMPLETE,completeHandler);
 * loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR,ioErrorHandler);
 * loader.contentLoaderInfo.addEventListener(SecurityErrorEvent.SECURITY_ERROR,securityErrorHandler);
 * }
 *
 *   public function load(lib:String):void {
 * swfLib = lib;
 * request = new URLRequest(swfLib);
 * var context:LoaderContext = new LoaderContext();
 * context.applicationDomain=ApplicationDomain.currentDomain;
 * loader.load(request,context);
 * }
 *
 *   public function getClass(className:String):Class {
 * try {
 * return loader.contentLoaderInfo.applicationDomain.getDefinition(className)  as  Class;
 * } catch (e:Error) {
 * throw new IllegalOperationError(className + " definition not found in " + swfLib);
 * }
 * return null;
 * }
 *
 *   private function completeHandler(e:Event):void {
 * dispatchEvent(new Event(ClassLoader.CLASS_LOADED));
 * }
 *
 *   private function ioErrorHandler(e:Event):void {
 * dispatchEvent(new Event(ClassLoader.LOAD_ERROR));
 * }
 *
 *   private function securityErrorHandler(e:Event):void {
 * dispatchEvent(new Event(ClassLoader.LOAD_ERROR));
 * }
 * }
 * </codeblock>
 *
 *   EXAMPLE:
 *
 *   If multiple SWF files contain compiled classes with the same name but provide different implementation, you can partition the classes of externally loaded SWF files separate from the classes of each other following this example.
 * Previously, the child SWF was instructed to use <codeph class="+ topic/ph pr-d/codeph ">ApplicationDomain.currentDomain</codeph>. In this case, a new <codeph class="+ topic/ph pr-d/codeph ">ApplicationDomain</codeph> is created,
 * so that then the properties and methods of the <codeph class="+ topic/ph pr-d/codeph ">Greeter</codeph> class of whichever SWF loads second will not replace the properties and methods of the first <codeph class="+ topic/ph pr-d/codeph ">Greeter</codeph> class.
 * You can test this by modifying the <codeph class="+ topic/ph pr-d/codeph ">context.applicationDomain</codeph> property in the <codeph class="+ topic/ph pr-d/codeph ">load</codeph> method of <codeph class="+ topic/ph pr-d/codeph ">ClassLoader</codeph>.
 * <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Notes:</b></p><ul class="- topic/ul "><li class="- topic/li ">Since the ClassLoader class loads a SWF file, local security needs to be at the file system level.</li><li class="- topic/li ">To run this example, you must have two SWF files called Greeter.swf existing in an "en" and "es" folder respectively.</li></ul><p class="- topic/p ">Create a Greeter.as file in the "en" directory with the following code:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * public class Greeter extends Sprite
 * {
 * public function Greeter()
 * {
 * }
 *
 *   public function greet():String {
 * return("Good Morning");
 * }
 * }
 * }
 * </codeblock><p class="- topic/p ">Then create a very similar Greeter.as file in the "es" directory:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * public class Greeter extends Sprite
 * {
 * public function Greeter()
 * {
 * }
 *
 *   public function greet():String {
 * return("Buenos Dias");
 * }
 * }
 * }
 * </codeblock><p class="- topic/p ">Compile SWF files for both and then implement the following code:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.DisplayObject;
 * import flash.display.Sprite;
 * import flash.errors.IllegalOperationError;
 * import flash.events.Event;
 * import flash.text.TextField;
 * import flash.text.TextFieldAutoSize;
 *
 *   public class ApplicationDomainExample2 extends Sprite {
 * private var spanishGreeterLoader:ClassLoader;
 * private var englishGreeterLoader:ClassLoader;
 * private var tf:TextField = new TextField();
 * private var greetersLoaded:uint = 0;
 *
 *   public function ApplicationDomainExample2() {
 * tf.autoSize = TextFieldAutoSize.LEFT;
 * addChild(tf);
 *
 *   spanishGreeterLoader = new ClassLoader();
 * spanishGreeterLoader.addEventListener(ClassLoader.LOAD_ERROR,loadErrorHandler);
 * spanishGreeterLoader.addEventListener(ClassLoader.CLASS_LOADED,classLoadedHandler);
 * spanishGreeterLoader.load("es/Greeter.swf");
 *
 *   englishGreeterLoader = new ClassLoader();
 * englishGreeterLoader.addEventListener(ClassLoader.LOAD_ERROR,loadErrorHandler);
 * englishGreeterLoader.addEventListener(ClassLoader.CLASS_LOADED,classLoadedHandler);
 * englishGreeterLoader.load("en/Greeter.swf");
 * }
 *
 *   private function loadErrorHandler(e:Event):void {
 * tf.text = "Load failed";
 * throw new IllegalOperationError("Cannot load the specified file.");
 * }
 *
 *   private function classLoadedHandler(e:Event):void {
 * greetersLoaded++;
 * if(greetersLoaded == 2) {
 * greet();
 * }
 * }
 *
 *   private function greet():void {
 * var spanishGreeter:Class = spanishGreeterLoader.getClass("Greeter");
 * var englishGreeter:Class = englishGreeterLoader.getClass("Greeter");
 * var greeter1 = new spanishGreeter();
 * var greeter2 = new englishGreeter();
 *
 *   tf.text = greeter1.greet() + "\n" + greeter2.greet();
 * }
 * }
 * }
 *
 *   import flash.display.Loader;
 * import flash.errors.IllegalOperationError;
 * import flash.events.Event;
 * import flash.events.EventDispatcher;
 * import flash.events.IOErrorEvent;
 * import flash.events.SecurityErrorEvent;
 * import flash.net.URLRequest;
 * import flash.system.ApplicationDomain;
 * import flash.system.LoaderContext;
 *
 *   class ClassLoader extends EventDispatcher {
 * public static var CLASS_LOADED:String = "classLoaded";
 * public static var LOAD_ERROR:String = "loadError";
 * private var loader:Loader;
 * private var swfLib:String;
 * private var request:URLRequest;
 * private var loadedClass:Class;
 *
 *   public function ClassLoader() {
 *
 *   loader = new Loader();
 * loader.contentLoaderInfo.addEventListener(Event.COMPLETE,completeHandler);
 * loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR,ioErrorHandler);
 * loader.contentLoaderInfo.addEventListener(SecurityErrorEvent.SECURITY_ERROR,securityErrorHandler);
 * }
 *
 *   public function load(lib:String):void {
 * swfLib = lib;
 * request = new URLRequest(swfLib);
 * var context:LoaderContext = new LoaderContext();
 * //        context.applicationDomain = ApplicationDomain.currentDomain;
 * context.applicationDomain = new ApplicationDomain();
 * loader.load(request,context);
 * }
 *
 *   public function getClass(className:String):Class {
 * try {
 * return loader.contentLoaderInfo.applicationDomain.getDefinition(className)  as  Class;
 * } catch (e:Error) {
 * throw new IllegalOperationError(className + " definition not found in " + swfLib);
 * }
 * return null;
 * }
 *
 *   private function completeHandler(e:Event):void {
 * dispatchEvent(new Event(ClassLoader.CLASS_LOADED));
 * }
 *
 *   private function ioErrorHandler(e:Event):void {
 * dispatchEvent(new Event(ClassLoader.LOAD_ERROR));
 * }
 *
 *   private function securityErrorHandler(e:Event):void {
 * dispatchEvent(new Event(ClassLoader.LOAD_ERROR));
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 * @internal    Security considerations for application domains are discussed in the
 *   applicationDomain property entries of URLRequest and LoaderInfo.
 */

using namespace flash::utils;

namespace flash
{
    namespace system
    {
        class ApplicationDomain : public Object
        {
            /**
             * Gets the current application domain in which your code is executing.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    Question: Do you call System.currentDomain? or Loader.currentDomain or request.currentDomain?
             */
        public:
            static flash::system::ApplicationDomain *currentDomain();

            /**
             * Gets the minimum memory object length required to be used as
             * ApplicationDomain.domainMemory.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            static unsigned int         MIN_DOMAIN_MEMORY_LENGTH();

            /**
             * Gets the parent domain of this application domain.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::system::ApplicationDomain *parentDomain();

            /**
             * Gets and sets the object on which domain-global memory operations
             * will operate within this ApplicationDomain.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            flash::utils::ByteArray *domainMemory();
        public:
            void         domainMemory(ByteArray *mem);

            /**
             * Creates a new application domain.
             * @param   parentDomain    If no parent domain is passed in, this application domain takes the system domain as its parent.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            ApplicationDomain(ApplicationDomain *parentDomain=NULL);

            /**
             * Gets a public definition from the specified application domain.
             * The definition can be that of a class, a namespace, or a function.
             * @param   name    The name of the definition.
             * @return  The object associated with the definition.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    throws SecurityError The definition belongs to a domain to which
             *   the calling code does not have access.
             * @throws  ReferenceError No public definition exists with the
             *   specified name.
             */
        public:
            Object   *getDefinition(std::string name);

            /**
             * Checks to see if a public definition exists within the specified application domain.
             * The definition can be that of a class, a namespace, or a function.
             * @param   name    The name of the definition.
             * @return  A value of true if the specified definition exists; otherwise, false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool  hasDefinition(std::string name);

        public:
            std::vector<std::string> getQualifiedDefinitionNames();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_APPLICATIONDOMAIN_AS
#endif // __cplusplus

