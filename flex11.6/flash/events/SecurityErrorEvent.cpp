

#include "SecurityErrorEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.SecurityErrorEvent.SECURITY_ERROR

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * The SecurityErrorEvent.SECURITY_ERROR constant defines the value of the type property of a securityError event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe network object reporting the security error.textText to be displayed as an error message.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    (at)see flash.display.LoaderInfo#event:securityError
         */
        const std::string SecurityErrorEvent::SECURITY_ERROR="securityError";

        /**
         * Creates a copy of the SecurityErrorEvent object and sets the value of each property to match that of the original.
         * @return  A new securityErrorEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::events::Event* SecurityErrorEvent::clone()                     ;

        /**
         * Creates an Event object that contains information about security error events.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one type of error event: SecurityErrorEvent.SECURITY_ERROR.
         * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
         * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
         * @param   text    Text to be displayed as an error message. Event listeners can access this information through the text property.
         * @param   id  A reference number to associate with the specific error.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        SecurityErrorEvent::SecurityErrorEvent(std::string type, bool bubbles, bool cancelable, std::string text, int id);

        /**
         * Returns a string that contains all the properties of the SecurityErrorEvent object. The string is in the following format:
         * [securityErrorEvent type=value bubbles=value cancelable=value text=value errorID=value]
         * The errorId is only available in Adobe AIR
         * @return  A string that contains all the properties of the SecurityErrorEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string SecurityErrorEvent::toString()         ;
}
}

