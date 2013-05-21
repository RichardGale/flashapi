

#include "FullScreenEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.FullScreenEvent.FULL_SCREEN

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * The FullScreenEvent.FULL_SCREEN constant defines the value of the type property of a fullScreen event object. 
         * This event has the following properties:PropertyValuefullScreentrue if the display state is full screen or false if it is normal.bubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe Stage object.
         * @langversion 3.0
         * @playerversion   Flash 9.0.28.0
         * @playerversion   Lite 4
         */
        const std::string FullScreenEvent::FULL_SCREEN="fullScreen";
        const std::string FullScreenEvent::FULL_SCREEN_INTERACTIVE_ACCEPTED;

        /**
         * Indicates whether the Stage object is in full-screen mode (true) or not (false).
         * @langversion 3.0
         * @playerversion   Flash 9.0.28.0
         * @playerversion   Lite 4
         */
        bool FullScreenEvent::fullScreen()          ;

        bool FullScreenEvent::interactive()          ;

        /**
         * Creates a copy of a FullScreenEvent object and sets the value of each property to match that of 
         * the original.
         * @return  A new FullScreenEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9.0.28.0
         * @playerversion   Lite 4
         */
        flash::events::Event* FullScreenEvent::clone()                     ;

        /**
         * Creates an event object that contains information about fullScreen events.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Event listeners can access this information through the 
         *   inherited type property. There is only one type of fullScreen event: 
         *   FullScreenEvent.FULL_SCREEN.
         * @param   bubbles Determines whether the Event object participates in the bubbling phase of the 
         *   event flow. Event listeners can access this information through the inherited 
         *   bubbles property.
         * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can 
         *   access this information through the inherited cancelable property.
         * @param   fullScreen  Indicates whether the device is activating (true) or 
         *   deactivating (false). Event listeners can access this information through the 
         *   activating property.
         * @langversion 3.0
         * @playerversion   Flash 9.0.28.0
         * @playerversion   Lite 4
         */
        FullScreenEvent::FullScreenEvent(std::string type, bool bubbles, bool cancelable, bool fullScreen, bool interactive);

        /**
         * Returns a string that contains all the properties of the FullScreenEvent object. The following 
         * format is used:
         * [FullScreenEvent type=value bubbles=value cancelable=value 
         * activating=value]
         * @return  A string that contains all the properties of the FullScreenEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9.0.28.0
         * @playerversion   Lite 4
         */
        std::string FullScreenEvent::toString()         ;
}
}

