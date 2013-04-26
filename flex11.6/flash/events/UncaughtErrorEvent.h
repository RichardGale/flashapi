#if !defined(FLEX11_6_FLASH_EVENTS_UNCAUGHTERROREVENT_AS)
#define FLEX11_6_FLASH_EVENTS_UNCAUGHTERROREVENT_AS
#if defined(__cplusplus)


namespace flash
{
    namespace events
    {
        class Event;
    }
}

/// @eventType  flash.events.UncaughtErrorEvent.UNCAUGHT_ERROR
//[Event(name="uncaughtError",type="flash.events.UncaughtErrorEvent")]

/**
 * An UncaughtErrorEvent object is dispatched by an instance of the UncaughtErrorEvents
 * class when an uncaught error occurs. An uncaught error happens when an error is
 * thrown outside of any <codeph class="+ topic/ph pr-d/codeph ">try..catch</codeph> blocks or when an ErrorEvent
 * object is dispatched with no registered listeners. The uncaught error event
 * functionality is often described as a "global error handler."
 *
 *   <p class="- topic/p ">The UncaughtErrorEvents object that dispatches the event is associated with
 * either a LoaderInfo object or a Loader object. Use the following properties to
 * access an UncaughtErrorEvents instance:</p><ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">LoaderInfo.uncaughtErrorEvents</codeph>: to
 * detect uncaught errors in code defined in the same SWF.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">Loader.uncaughtErrorEvents</codeph>: to detect uncaught
 * errors in code defined in the SWF loaded by a Loader object.</li></ul><p class="- topic/p ">When an <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph> event happens, even if the event is handled,
 * execution does not continue in the call stack that caused the error. If the error is
 * a synchronous error, any code remaining in the function where the error happened is
 * not executed. Consequently, it is likely that when an uncaught error event happens,
 * your application is in an unstable state. Since there can be many causes for an
 * uncaught error, it is impossible to predict what functionality is available. For
 * example, your application may be able to execute network operations or file
 * operations. However, those operations aren't necessarily available.</p><p class="- topic/p ">When one SWF loads another, <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph> events bubble down and up
 * again through the LoaderInfo heirarchy. For example, suppose A.swf loads B.swf using a
 * Loader instance. If an uncaught error occurs in B.swf, an <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph>
 * event is dispatched to LoaderInfo and Loader objects in the following
 * sequence:</p><ol class="- topic/ol "><li class="- topic/li ">(Capture phase) A.swf's LoaderInfo</li><li class="- topic/li ">(Capture phase) Loader in A.swf</li><li class="- topic/li ">(Target phase) B.swf's LoaderInfo</li><li class="- topic/li ">(Bubble phase) Loader in A.swf</li><li class="- topic/li ">(Bubble phase) A.swf's LoaderInfo</li></ol><p class="- topic/p ">A Loader object's <codeph class="+ topic/ph pr-d/codeph ">uncaughtErrorEvents</codeph> property
 * never dispatches an <codeph class="+ topic/ph pr-d/codeph ">uncaughtErrorEvent</codeph> in the target phase. It only
 * dispatches the event in the capture and bubbling phases.</p><p class="- topic/p ">As with other event bubbling, calling <codeph class="+ topic/ph pr-d/codeph ">stopPropagation()</codeph> or
 * <codeph class="+ topic/ph pr-d/codeph ">stopImmediatePropagation()</codeph> stops the event from being dispatched
 * to any other listeners, with one important difference. A Loader object's
 * UncaughtErrorEvents object is treated as a pair with the loaded SWF's
 * <codeph class="+ topic/ph pr-d/codeph ">LoaderInfo.uncaughtErrorEvents</codeph> object for event propagation purposes.
 * If a listener registered with one of those objects calls the <codeph class="+ topic/ph pr-d/codeph ">stopPropagation()</codeph>
 * method, events are still dispatched to other listeners registered with that
 * UncaughtErrorEvents object <i class="+ topic/ph hi-d/i ">and</i> to listeners registered with its partner
 * UncaughtErrorEvents object before event propagation ends. The
 * <codeph class="+ topic/ph pr-d/codeph ">stopImmediatePropagation()</codeph> method still prevents events from being
 * dispatched to all additional listeners.</p><p class="- topic/p ">When content is running in a debugger version of the runtime, such as the
 * debugger version of Flash Player or the AIR Debug Launcher (ADL), an uncaught
 * error dialog appears when an uncaught error happens.
 * For those runtime versions, the error dialog appears even when a listener is registered
 * for the <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph> event. To prevent the dialog from appearing
 * in that situation, call the UncaughtErrorEvent object's
 * <codeph class="+ topic/ph pr-d/codeph ">preventDefault()</codeph> method.</p><p class="- topic/p ">If the content loaded by a Loader object is an AVM1 (ActionScript 2) SWF file,
 * uncaught errors in the AVM1 SWF file do not result in an <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph>
 * event. In addition, JavaScript errors in HTML content loaded in an HTMLLoader object
 * (including a Flex HTML control) do not result in an <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph> event.</p>
 *
 *   EXAMPLE:
 *
 *   The following example demonstrates the use of an uncaught error event
 * handler to detect uncaught errors in an ActionScript project. The example defines
 * an <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph> event handler to detect uncaught errors. It also
 * provides a button that, when clicked, throws an error that is caught by the
 * uncaught error handler.
 *
 *   <p class="- topic/p ">In the constructor, the code registers a listener for the <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph>
 * event dispatched by the LoaderInfo object's <codeph class="+ topic/ph pr-d/codeph ">uncaughtErrorEvents</codeph> property.</p><p class="- topic/p ">In the <codeph class="+ topic/ph pr-d/codeph ">uncaughtErrorHandler()</codeph> method, the code checks the data type of
 * the <codeph class="+ topic/ph pr-d/codeph ">error</codeph> property and responds accordingly.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package
 * {
 * import flash.display.Sprite;
 * import flash.events.ErrorEvent;
 * import flash.events.MouseEvent;
 * import flash.events.UncaughtErrorEvent;
 *
 *   public class UncaughtErrorEventExample extends Sprite
 * {
 * public function UncaughtErrorEventExample()
 * {
 * loaderInfo.uncaughtErrorEvents.addEventListener(UncaughtErrorEvent.UNCAUGHT_ERROR, uncaughtErrorHandler);
 *
 *   drawUI();
 * }
 *
 *   private function uncaughtErrorHandler(event:UncaughtErrorEvent):void
 * {
 * if (event.error is Error)
 * {
 * var error:Error = event.error as Error;
 * // do something with the error
 * }
 * else if (event.error is ErrorEvent)
 * {
 * var errorEvent:ErrorEvent = event.error as ErrorEvent;
 * // do something with the error
 * }
 * else
 * {
 * // a non-Error, non-ErrorEvent type was thrown and uncaught
 * }
 * }
 *
 *   private function drawUI():void
 * {
 * var btn:Sprite = new Sprite();
 * btn.graphics.clear();
 * btn.graphics.beginFill(0xFFCC00);
 * btn.graphics.drawRect(0, 0, 100, 50);
 * btn.graphics.endFill();
 * addChild(btn);
 * btn.addEventListener(MouseEvent.CLICK, clickHandler);
 * }
 *
 *   private function clickHandler(event:MouseEvent):void
 * {
 * throw new Error("Gak!");
 * }
 * }
 * }
 * </codeblock>
 *
 *   EXAMPLE:
 *
 *   The following example is the Flex equivalent of the previous example,
 * using an MXML document instead of an ActionScript class as the root content.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * &lt;?xml version="1.0" encoding="utf-8"?&gt;
 * &lt;s:WindowedApplication xmlns:fx="http://ns.adobe.com/mxml/2009"
 * xmlns:s="library://ns.adobe.com/flex/spark"
 * xmlns:mx="library://ns.adobe.com/flex/halo"
 * applicationComplete="applicationCompleteHandler();"&gt;
 *
 *   &lt;fx:Script&gt;
 * &lt;![CDATA[
 * import flash.events.ErrorEvent;
 * import flash.events.MouseEvent;
 * import flash.events.UncaughtErrorEvent;
 *
 *   private function applicationCompleteHandler():void
 * {
 * loaderInfo.uncaughtErrorEvents.addEventListener(UncaughtErrorEvent.UNCAUGHT_ERROR, uncaughtErrorHandler);
 * }
 *
 *   private function uncaughtErrorHandler(event:UncaughtErrorEvent):void
 * {
 * if (event.error is Error)
 * {
 * var error:Error = event.error as Error;
 * // do something with the error
 * }
 * else if (event.error is ErrorEvent)
 * {
 * var errorEvent:ErrorEvent = event.error as ErrorEvent;
 * // do something with the error
 * }
 * else
 * {
 * // a non-Error, non-ErrorEvent type was thrown and uncaught
 * }
 * }
 *
 *   private function clickHandler(event:MouseEvent):void
 * {
 * throw new Error("Gak!");
 * }
 * ]]&gt;
 * &lt;/fx:Script&gt;
 *
 *   &lt;s:Button label="Cause Error" click="clickHandler(event);"/&gt;
 * &lt;/s:WindowedApplication&gt;
 * </codeblock>
 *
 *   EXAMPLE:
 *
 *   The following example demonstrates the use of an uncaught error event
 * handler to detect uncaught errors in a loaded SWF. The example defines
 * an <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph> event handler to detect uncaught errors.
 *
 *   <p class="- topic/p ">In the constructor, the code creates a Loader object and registers a listener for
 * the <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph> event dispatched by the Loader object's
 * <codeph class="+ topic/ph pr-d/codeph ">uncaughtErrorEvents</codeph> property.</p><p class="- topic/p ">In the <codeph class="+ topic/ph pr-d/codeph ">uncaughtErrorHandler()</codeph> method, the code checks the data type of
 * the <codeph class="+ topic/ph pr-d/codeph ">error</codeph> property and responds accordingly.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package
 * {
 * import flash.display.Loader;
 * import flash.display.Sprite;
 * import flash.events.ErrorEvent;
 * import flash.events.UncaughtErrorEvent;
 * import flash.net.URLRequest;
 *
 *   public class LoaderUncaughtErrorEventExample extends Sprite
 * {
 * private var ldr:Loader;
 *
 *   public function LoaderUncaughtErrorEventExample()
 * {
 * ldr = new Loader();
 * ldr.load(new URLRequest("child.swf"));
 * ldr.uncaughtErrorEvents.addEventListener(UncaughtErrorEvent.UNCAUGHT_ERROR, uncaughtErrorHandler);
 * }
 *
 *   private function uncaughtErrorHandler(event:UncaughtErrorEvent):void
 * {
 * if (event.error is Error)
 * {
 * var error:Error = event.error as Error;
 * // do something with the error
 * }
 * else if (event.error is ErrorEvent)
 * {
 * var errorEvent:ErrorEvent = event.error as ErrorEvent;
 * // do something with the error
 * }
 * else
 * {
 * // a non-Error, non-ErrorEvent type was thrown and uncaught
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */
using namespace flash::events;

namespace flash
{
    namespace events
    {
        class UncaughtErrorEvent: public ErrorEvent
        {
            /**
             * Defines the value of the type property of an uncaughtError event object.
             * This event has the following properties:PropertyValuebubblestruecancelabletrue; cancelling the event prevents the uncaught error dialog from appearing in debugger runtime versionscurrentTargetThe object that is actively processing the Event object with an event listener.errorThe uncaught error.targetThe LoaderInfo object associated with the SWF where the error happened.textText error message.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string UNCAUGHT_ERROR;

            /**
             * The error object associated with the uncaught error. Typically, this
             * object's data type is one of the following:
             *
             *   An Error instance (or one of its subclasses), if the uncaught error is
             * a synchronous error created by a throw statement, such as an
             * error that could have been caught using a try..catch blockAn ErrorEvent instance (or one of its subclasses), if the uncaught error
             * is an asynchronous error that dispatches an error event when the error happensHowever, the error property can potentially be an object of any
             * data type. ActionScript does not require a throw
             * statement to be used only with Error objects. For example, the following
             * code is legal both at compile time and run time:
             * <codeblock>
             * throw new Sprite()
             * </codeblock>
             * If that throw statement is not caught by a
             * try..catch block, the throw statement
             * triggers an uncaughtError event. In that case, the
             * error property of the UncaughtErrorEvent object that's dispatched
             * is the Sprite object that's constructed in the throw statement.Consequently, in your uncaughtError listener, you should check
             * the data type of the error property. The following example
             * demonstrates this check:
             * <codeblock>
             *
             *   function uncaughtErrorHandler(event:UncaughtErrorEvent):void
             * {
             * var message:String;
             *
             *   if (event.error is Error)
             * {
             * message = Error(event.error).message;
             * }
             * else if (event.error is ErrorEvent)
             * {
             * message = ErrorEvent(event.error).text;
             * }
             * else
             * {
             * message = event.error.toString();
             * }
             * }
             * </codeblock>
             * If the error property contains an Error instance (or Error subclass),
             * the available error information varies depending on the version of the runtime
             * in which the content is running. The following functionality is only available
             * when content is running in a debugger version of the runtime, such as the
             * debugger version of Flash Player or the AIR Debug Launcher (ADL):Error.getStackTrace() to get the call stack that led to
             * the error. In non-debugger runtime versions, this method returns
             * null. Note that call stack information is never available
             * when the error property is an ErrorEvent instance.Complete Error.message text. In non-debugger runtime versions,
             * this property contains a short version of the error message, which is often a
             * combination of the Error.errorID and Error.name properties.All other properties and methods of the Error class are available in all
             * runtime versions.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            void        *error();

            /**
             * Creates a copy of the UncaughtErrorEvent object and sets the value of
             * each property to match that of the original.
             * @return  A new UncaughtErrorEvent object with property values that match those
             *   of the original.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            flash::events::Event *clone();

            /**
             * Returns a string that contains all the properties of the UncaughtErrorEvent object.
             * @return  A string that contains all the properties of the UncaughtErrorEvent object.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string toString();

            /**
             * Creates an UncaughtErrorEvent object that contains information about an
             * uncaughtError event.
             * @param   type    The type of the event.
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
             * @param   error_in    The object associated with the error that was not caught or handled (an Error or ErrorEvent object under normal circumstances).
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            UncaughtErrorEvent(std::string type, bool bubbles, bool cancelable, void *error_in);
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_UNCAUGHTERROREVENT_AS
#endif // __cplusplus

