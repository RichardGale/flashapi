#if !defined(FLEX11_6_FLASH_EVENTS_ACTIVITYEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_ACTIVITYEVENT_AS
#if defined(__cplusplus)


#include "flash/events/Event.h"

/// @eventType  flash.events.ActivityEvent.ACTIVITY
//[Event(name="activity",type="flash.events.ActivityEvent")]

/**
 * A Camera or Microphone object dispatches an ActivityEvent object whenever a camera or microphone reports that it has
 * become active or inactive. There is only one type of activity event: <codeph class="+ topic/ph pr-d/codeph ">ActivityEvent.ACTIVITY</codeph>.
 *
 *   EXAMPLE:
 *
 *   The following example demonstrates the use of the ActivityEvent class by
 * attaching an event listener method named <codeph class="+ topic/ph pr-d/codeph ">activityHandler()</codeph> to the microphone and
 * generating text information every time the microphone generates an <codeph class="+ topic/ph pr-d/codeph ">activity</codeph> event.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.events.ActivityEvent;
 * import flash.media.Microphone;
 *
 *   public class ActivityEventExample extends Sprite {
 * public function ActivityEventExample() {
 * var mic:Microphone = Microphone.getMicrophone();
 * mic.addEventListener(ActivityEvent.ACTIVITY, activityHandler);
 * }
 *
 *   private function activityHandler(event:ActivityEvent):void {
 * trace("event: " + event);
 * trace("event.activating: " + event.activating);
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 */
using namespace flash::events;

namespace flash
{
    namespace events
    {
        class ActivityEvent: public Event
        {
            /**
             * The ActivityEvent.ACTIVITY constant defines the value of the type property of an activity event object.
             * This event has the following properties:PropertyValueactivatingtrue if the device is activating or false if it is deactivating.bubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe object beginning or ending a session, such as a Camera or
             * Microphone object.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string ACTIVITY;

            /**
             * Indicates whether the device is activating (true) or deactivating
             * (false).
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool         activating();
        public:
            void         activating(bool value);

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
        public:
            ActivityEvent(std::string type, bool bubbles, bool cancelable, bool activating);

            /**
             * Creates a copy of an ActivityEvent object and sets the value of each property to match that of
             * the original.
             * @return  A new ActivityEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            flash::events::Event *clone();

            /**
             * Returns a string that contains all the properties of the ActivityEvent object. The following
             * format is used:
             * [ActivityEvent type=value bubbles=value cancelable=value
             * activating=value]
             * @return  A string that contains all the properties of the ActivityEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_ACTIVITYEVENT_AS
#endif // __cplusplus

