

#include "ActivityEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.ActivityEvent.ACTIVITY

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * The ActivityEvent.ACTIVITY constant defines the value of the type property of an activity event object. 
         * This event has the following properties:PropertyValueactivatingtrue if the device is activating or false if it is deactivating.bubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe object beginning or ending a session, such as a Camera or 
         * Microphone object.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string ActivityEvent::ACTIVITY="activity";

        /**
         * Indicates whether the device is activating (true) or deactivating 
         * (false).
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        bool ActivityEvent::activating()          ;
        void ActivityEvent::activating(bool value)       ;

        /**
         * Creates an event object that contains information about activity events.
         * Event objects are passed as parameters to Event listeners.
         * @param   type    The type of the event. Event listeners can access this information through the 
         *   inherited type property. There is only one type of activity event: 
         *   ActivityEvent.ACTIVITY.
         * @param   bubbles Determines whether the Event object participates in the bubbling phase of the 
         *   event flow. Event listeners can access this information through the inherited 
         *   bubbles property.
         * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can 
         *   access this information through the inherited cancelable property.
         * @param   activating  Indicates whether the device is activating (true) or 
         *   deactivating (false). Event listeners can access this information through the 
         *   activating property.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        ActivityEvent::ActivityEvent(std::string type, bool bubbles, bool cancelable, bool activating);

        /**
         * Creates a copy of an ActivityEvent object and sets the value of each property to match that of 
         * the original.
         * @return  A new ActivityEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        flash::events::Event* ActivityEvent::clone()                     ;

        /**
         * Returns a string that contains all the properties of the ActivityEvent object. The following 
         * format is used:
         * [ActivityEvent type=value bubbles=value cancelable=value 
         * activating=value]
         * @return  A string that contains all the properties of the ActivityEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        std::string ActivityEvent::toString()         ;
}
}

