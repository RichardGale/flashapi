

#include "TimerEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.TimerEvent.TIMER_COMPLETE

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * Defines the value of the type property of a timer event object.
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe Timer object that has reached its interval.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string TimerEvent::TIMER   = "timer";

        /**
         * Defines the value of the type property of a timerComplete event object.
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe Timer object that has completed its requests.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string TimerEvent::TIMER_COMPLETE   = "timerComplete";

        /**
         * Creates a copy of the TimerEvent object and sets each property's value to match that of the original.
         * @return  A new TimerEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::events::Event* TimerEvent::clone()                     ;

        /**
         * Creates an Event object with specific information relevant to timer events.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Event listeners can access this information through the inherited type property.
         * @param   bubbles Determines whether the Event object bubbles. Event listeners can access this information through the inherited bubbles property.
         * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        TimerEvent::TimerEvent(std::string type, bool bubbles, bool cancelable);

        /**
         * Returns a string that contains all the properties of the TimerEvent object. The string is in the following format:
         * [TimerEvent type=value bubbles=value cancelable=value]
         * @return  A string that contains all the properties of the TimerEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string TimerEvent::toString()         ;

        /**
         * Instructs Flash Player or the AIR runtime to render 
         * after processing of this event completes, if the display list has been modified.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void TimerEvent::updateAfterEvent()       ;
}
}

