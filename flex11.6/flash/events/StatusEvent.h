#if !defined(FLEX11_6_FLASH_EVENTS_STATUSEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_STATUSEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/Event.h"

/// @eventType  flash.events.StatusEvent.STATUS
//[Event(name="status",type="flash.events.StatusEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /**
         * An object dispatches a StatusEvent object when a device, such as a camera or microphone, or an object such as a LocalConnection object reports its status. There is only one type of status event: <codeph class="+ topic/ph pr-d/codeph ">StatusEvent.STATUS</codeph>.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    includeExample examples\StatusEventExample.as -noswf
         */
        class StatusEvent : public flash::events::Event
        {
            /**
             * Defines the value of the type property of a status event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.codeA description of the object's status.currentTargetThe object that is actively processing the Event
             * object with an event listener.levelThe category of the message, such as "status", "warning" or "error".targetThe object reporting its status.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string STATUS;

            /**
             * A description of the object's status.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string       code();
        public:
            void         code(std::string value);

            /**
             * The category of the message, such as "status", "warning" or "error".
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string       level();
        public:
            void         level(std::string value);

            /**
             * Creates a copy of the StatusEvent object and sets the value of each property to match that of the original.
             * @return  A new StatusEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates an Event object that contains information about status events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one type of status event: StatusEvent.STATUS.
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
             * @param   code    A description of the object's status. Event listeners can access this information through the code property.
             * @param   level   The category of the message, such as "status", "warning" or "error". Event listeners can access this information through the level property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            StatusEvent(std::string type, bool bubbles=false, bool cancelable=false, std::string code="", std::string level="");

            /**
             * Returns a string that contains all the properties of the StatusEvent object. The string is in the following format:
             * [StatusEvent type=value bubbles=value cancelable=value code=value level=value]
             * @return  A string that contains all the properties of the StatusEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string   toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_STATUSEVENT_AS
#endif // __cplusplus

