

#include "AsyncErrorEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.AsyncErrorEvent.ASYNC_ERROR

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * The AsyncErrorEvent.ASYNC_ERROR constant defines the value of the 
         * type property of an asyncError event object. 
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default
         * behavior to cancel. currentTargetThe object that is actively processing the
         * Event object with an event listener. targetThe object dispatching the event.errorThe error that triggered the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string AsyncErrorEvent::ASYNC_ERROR="asyncError";

        /**
         * The exception that was thrown.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
                   

        /**
         * Creates an AsyncErrorEvent object that contains information about asyncError events.
         * AsyncErrorEvent objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Event listeners can access this information through 
         *   the inherited type property. There is only one type of error event:
         *   ErrorEvent.ERROR.
         * @param   bubbles Determines whether the Event object bubbles. Event listeners can access
         *   this information through the inherited bubbles property.
         * @param   cancelable  Determines whether the Event object can be canceled. Event listeners
         *   can access this information through the inherited cancelable property.
         * @param   text    Text to be displayed as an error message. Event listeners can access this
         *   information through the text property.
         * @param   error   The exception that occurred.
         *   If error is non-null, the event's errorId property is set from the error's
         *   errorId property.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        AsyncErrorEvent::AsyncErrorEvent(std::string type, bool bubbles, bool cancelable, std::string text, Error* error);

        /**
         * Creates a copy of the AsyncErrorEvent object and sets the value of each property to match
         * that of the original.
         * @return  A new AsyncErrorEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::events::Event* AsyncErrorEvent::clone()                     ;

        /**
         * Returns a string that contains all the properties of the AsyncErrorEvent object. The
         * string is in the following format:
         * [AsyncErrorEvent type=value bubbles=value
         * cancelable=value ... error=value errorID=value]
         * The errorId is only available in Adobe AIR
         * @return  A string that contains all the properties of the AsyncErrorEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string AsyncErrorEvent::toString()         ;
}
}

