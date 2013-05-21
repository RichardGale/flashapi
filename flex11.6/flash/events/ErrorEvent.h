#if !defined(FLEX11_6_FLASH_EVENTS_ERROREVENT_AS)
#define FLEX11_6_FLASH_EVENTS_ERROREVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace events
    {
        class Event;
    }
}
#include "flash/events/TextEvent.h"

/// @eventType  flash.events.ErrorEvent.ERROR
//[Event(name="error",type="flash.events.ErrorEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /**
         * An object dispatches an ErrorEvent object when an error causes an asynchronous operation
         * to fail.
         *
         *   <p class="- topic/p ">The ErrorEvent class defines only one type of <codeph class="+ topic/ph pr-d/codeph ">error</codeph> event:
         * <codeph class="+ topic/ph pr-d/codeph ">ErrorEvent.ERROR</codeph>. The ErrorEvent class also serves as the base class for
         * several other error event classes, including the AsyncErrorEvent, IOErrorEvent,
         * SecurityErrorEvent, SQLErrorEvent, and UncaughtErrorEvent classes.</p><p class="- topic/p ">You can check for <codeph class="+ topic/ph pr-d/codeph ">error</codeph> events that do not have any listeners by
         * registering a listener for the <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph> (UncaughtErrorEvent.UNCAUGHT_ERROR)
         * event.</p><p class="- topic/p ">An uncaught error also causes an error dialog box displaying the error event to appear
         * when content is running in the <ph class="- topic/ph ">debugger version of Flash
         * Player or the</ph> AIR Debug Launcher (ADL) application.</p>
         *
         *   EXAMPLE:
         *
         *   The following example demonstrates the use of a single error handler (<codeph class="+ topic/ph pr-d/codeph ">errorHandler()</codeph>)
         * that captures multiple types of error events. If there is an <codeph class="+ topic/ph pr-d/codeph ">ioError</codeph> event, the handler
         * attempts to load from the network, which then throws a <codeph class="+ topic/ph pr-d/codeph ">securityError</codeph>.
         *
         *   <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note: </b> This example does not work if you have a file named
         * MissingFile.xml in the same directory as your SWF file.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Sprite;
         * import flash.net.URLLoader;
         * import flash.net.URLRequest;
         * import flash.events.*;
         *
         *   public class ErrorEventExample extends Sprite {
         * private var loader:URLLoader;
         * private var request:URLRequest;
         *
         *   public function ErrorEventExample() {
         * loader = new URLLoader();
         * loader.addEventListener(IOErrorEvent.IO_ERROR, errorHandler);
         * loader.addEventListener(SecurityErrorEvent.SECURITY_ERROR, errorHandler);
         *
         *   request = new URLRequest();
         * loadFromFileSystem();
         * }
         *
         *   private function loadFromFileSystem():void {
         * request.url = "MissingFile.xml";
         * loader.load(request);
         * }
         *
         *   private function loadFromNetwork():void {
         * request.url = "http://www.[yourDomain].com/MissingFile.xml";
         * loader.load(request);
         * }
         *
         *   private function errorHandler(event:ErrorEvent):void {
         * trace("errorHandler: " + event);
         * if(event is IOErrorEvent) {
         * loadFromNetwork();
         * }
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        class ErrorEvent : public flash::events::TextEvent
        {
            /**
             * Defines the value of the type property of an error event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe object experiencing a network operation failure.textText to be displayed as an error message.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static const std::string ERROR;

            /**
             * Contains the reference number associated with the specific error.
             * For a custom ErrorEvent object, this number is the value from the id
             * parameter supplied in the constructor.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @playerversion   Flash 10.1
             */
        public:
            int          errorID();

            /**
             * Creates an Event object that contains information about error events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one type of error event: ErrorEvent.ERROR.
             * @param   bubbles Determines whether the Event object bubbles. Event listeners can access this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
             * @param   text    Text to be displayed as an error message. Event listeners can access this information through the text property.
             * @param   id  A reference number to associate with the specific error (supported in Adobe AIR only).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            ErrorEvent(std::string type, bool bubbles   =false, bool cancelable   =false, std::string text="", int id=0);

            /**
             * Creates a copy of the ErrorEvent object and sets the value of each property to match that of the original.
             * @return  A new ErrorEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Returns a string that contains all the properties of the ErrorEvent object. The string is in the following format:
             * [ErrorEvent type=value bubbles=value cancelable=value text=value errorID=value]Note: The errorId value returned by the toString() method is only available for Adobe AIR.
             * While Flash Player 10.1 supports the errorID property, calling toString() on the ErrorEvent object does
             * not provide the errorId value in Flash Player.
             * @return  A string that contains all the properties of the ErrorEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_ERROREVENT_AS
#endif // __cplusplus

