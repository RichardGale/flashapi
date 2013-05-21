

#include "IMEEvent.h"
#include "flash/text/ime/IIMEClient.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.IMEEvent.IME_COMPOSITION

using namespace flash::events;
using namespace flash::text::ime;

namespace flash {
namespace events {


        /**
         * Defines the value of the type property of an imeComposition event object. 
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe IME object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string IMEEvent::IME_COMPOSITION="imeComposition";

        /**
         * To handle IME text input, the receiver must set the imeClient field of the event to an object
         * that implements the IIMEClient interface. If imeClient is unset, the runtime uses out-of-line 
         * IME composition instead, and sends the final composition as a TEXT_INPUT event.
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe IME object.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @airversion  AIR 2
         */
        const std::string IMEEvent::IME_START_COMPOSITION="imeStartComposition";

        /**
         * Specifies an object that implements the IMEClient interface. Components based on the flash.text.engine 
         * package must implement this interface to support editing text inline using an IME.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @airversion  AIR 2
         */
        flash::text::ime::IIMEClient* IMEEvent::imeClient()                            ;
        void IMEEvent::imeClient(IIMEClient* value)       ;

        /**
         * Creates a copy of the IMEEvent object and sets the value of each property to match that of the original.
         * @return  A new IMEEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::events::Event* IMEEvent::clone()                     ;

        /**
         * Creates an Event object with specific information relevant to IME events.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one IME event: IMEEvent.IME_COMPOSITION.
         * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
         * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
         * @param   text    The reading string from the IME. This is the initial string as typed by the user, before selection of any candidates. The final composition string is delivered to the object with keyboard focus in a TextEvent.TEXT_INPUT event. Event listeners can access this information through the text property.
         * @param   imeClient   A set of callbacks used by the text engine to communicate with the IME. Useful if your code has its own text engine and is rendering lines of text itself, rather than using TextField objects or the TextLayoutFramework.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        IMEEvent::IMEEvent(std::string type, bool bubbles, bool cancelable, std::string text, IIMEClient* imeClient);

        /**
         * Returns a string that contains all the properties of the IMEEvent object. The string is in the following format:
         * [IMEEvent type=value bubbles=value cancelable=value text=value]
         * @return  A string that contains all the properties of the IMEEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string IMEEvent::toString()         ;
}
}

