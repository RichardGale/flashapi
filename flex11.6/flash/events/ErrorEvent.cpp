

#include "ErrorEvent.h"
#include "flash/events/Event.h"
#include "flash/events/TextEvent.h"

    /// @eventType  flash.events.ErrorEvent.ERROR

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * Defines the value of the type property of an error event object. 
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe object experiencing a network operation failure.textText to be displayed as an error message.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        const std::string ErrorEvent::ERROR   = "error";

        /**
         * Contains the reference number associated with the specific error.
         * For a custom ErrorEvent object, this number is the value from the id
         * parameter supplied in the constructor.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         * @playerversion   Flash 10.1
         */
        int ErrorEvent::errorID()      ;

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
        ErrorEvent::ErrorEvent(std::string type, bool bubbles, bool cancelable, std::string text, int id);

        /**
         * Creates a copy of the ErrorEvent object and sets the value of each property to match that of the original.
         * @return  A new ErrorEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        flash::events::Event* ErrorEvent::clone()                     ;

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
        std::string ErrorEvent::toString()         ;
}
}

