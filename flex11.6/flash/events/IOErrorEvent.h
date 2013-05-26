#if !defined(FLEX11_6_FLASH_EVENTS_IOERROREVENT_AS)
#define FLEX11_6_FLASH_EVENTS_IOERROREVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace events
    {
        class Event;
    }
}

/// @eventType  flash.events.IOErrorEvent.IO_ERROR
//[Event(name="ioError",type="flash.events.IOErrorEvent")]

/// @eventType  flash.events.IOErrorEvent.STANDARD_ERROR_IO_ERROR
//[Event(name="IOErrorEvent",type="flash.events.IOErrorEvent")]

/// @eventType  flash.events.IOErrorEvent.STANDARD_INPUT_IO_ERROR
//[Event(name="IOErrorEvent",type="flash.events.IOErrorEvent")]


//[Event(name="IOErrorEvent",type="flash.events.IOErrorEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /// @eventType  flash.events.IOErrorEvent.STANDARD_OUTPUT_IO_ERROR


        /**
         * An IOErrorEvent object is dispatched when an error causes input or output operations to fail.
         *
         *   <p class="- topic/p ">You can check for error events that do not have any listeners by using the debugger
         * version of Flash Player or the AIR Debug Launcher (ADL). The string defined by the
         * <codeph class="+ topic/ph pr-d/codeph ">text</codeph> parameter of the IOErrorEvent constructor is displayed.</p>
         *
         *   EXAMPLE:
         *
         *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">IOErrorEventExample</codeph> class to show how an error
         * event object is dispatched when an attempt is made to load a nonexistent file.  The example carries out the following tasks:
         * <ol class="- topic/ol "><li class="- topic/li ">The class constructor creates a new instance of a URLLoader object and assigns it to the variable
         * <codeph class="+ topic/ph pr-d/codeph ">loader</codeph>.</li><li class="- topic/li ">The URLLoader instance instantiates an event listener of type <codeph class="+ topic/ph pr-d/codeph ">ioError</codeph>, which has
         * an associated subscriber method <codeph class="+ topic/ph pr-d/codeph ">ioErrorHandler()</codeph>, which simply prints information about
         * the event using <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph>.</li><li class="- topic/li ">Next, the constructor creates a new instance of a URLRequest object, <codeph class="+ topic/ph pr-d/codeph ">request</codeph>,
         * passing <codeph class="+ topic/ph pr-d/codeph ">MissingFile.xml</codeph> so that the name and location of the missing file are
         * known.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">request</codeph> variable is then passed to <codeph class="+ topic/ph pr-d/codeph ">loader.load()</codeph>, which attempts to load the
         * missing file.  Since the file is missing, the event handler dispatches an <codeph class="+ topic/ph pr-d/codeph ">ioError</codeph> event.</li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Notes:</b><ul class="- topic/ul "><li class="- topic/li ">You need to compile the SWF file with "Local Playback Security" set to "Access Local Files Only".</li><li class="- topic/li ">Make sure that you do not have a file named "MissingFile.xml" at the same level as your SWF file. </li></ul></p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Sprite;
         * import flash.events.IOErrorEvent;
         * import flash.net.URLLoader;
         * import flash.net.URLRequest;
         *
         *   public class IOErrorEventExample extends Sprite {
         * public function IOErrorEventExample() {
         * var loader:URLLoader = new URLLoader();
         * loader.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
         *
         *   var request:URLRequest = new URLRequest("MissingFile.xml");
         * loader.load(request);
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
         */
        class IOErrorEvent : public ErrorEvent
        {
            /**
             * Defines the value of the type property of an ioError event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.errorIDA reference number associated with the specific error (AIR only).targetThe network object experiencing the input/output error.textText to be displayed as an error message.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string IO_ERROR;
        public:
            static const std::string NETWORK_ERROR;
        public:
            static const std::string DISK_ERROR;
        public:
            static const std::string VERIFY_ERROR;

            /**
             * Creates an Event object that contains specific information about ioError events.
             * Event objects are passed as parameters to Event listeners.
             * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one type of input/output error event: IOErrorEvent.IO_ERROR.
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
             * @param   text    Text to be displayed as an error message. Event listeners can access this information through the text property.
             * @param   id  A reference number to associate with the specific error (supported in Adobe AIR only).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            IOErrorEvent(std::string type, bool bubbles=false, bool cancelable=false, std::string text="", int id=0);

            /**
             * Creates a copy of the IOErrorEvent object and sets the value of each property to match that of the original.
             * @return  A new IOErrorEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Returns a string that contains all the properties of the IOErrorEvent object. The string is in the following format:
             * [IOErrorEvent type=value bubbles=value cancelable=value text=value errorID=value]
             * The errorId is only available in Adobe AIR
             * @return  A string that contains all the properties of the IOErrorEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string   toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_IOERROREVENT_AS
#endif // __cplusplus

