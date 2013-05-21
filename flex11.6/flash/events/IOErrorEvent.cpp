

#include "IOErrorEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.IOErrorEvent.IO_ERROR

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * Defines the value of the type property of an ioError event object.
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.errorIDA reference number associated with the specific error (AIR only).targetThe network object experiencing the input/output error.textText to be displayed as an error message.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string IOErrorEvent::IO_ERROR="ioError";
        const std::string IOErrorEvent::NETWORK_ERROR;
        const std::string IOErrorEvent::DISK_ERROR;
        const std::string IOErrorEvent::VERIFY_ERROR;

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
        IOErrorEvent::IOErrorEvent(std::string type, bool bubbles, bool cancelable, std::string text, int id);

        /**
         * Creates a copy of the IOErrorEvent object and sets the value of each property to match that of the original.
         * @return  A new IOErrorEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::events::Event* IOErrorEvent::clone()                     ;

        /**
         * Returns a string that contains all the properties of the IOErrorEvent object. The string is in the following format:
         * [IOErrorEvent type=value bubbles=value cancelable=value text=value errorID=value]
         * The errorId is only available in Adobe AIR
         * @return  A string that contains all the properties of the IOErrorEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string IOErrorEvent::toString()         ;
}
}

