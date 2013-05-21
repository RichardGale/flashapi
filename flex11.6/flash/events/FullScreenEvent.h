#if !defined(FLEX11_6_FLASH_EVENTS_FULLSCREENEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_FULLSCREENEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace events
    {
        class Event;
    }
}

/// @eventType  flash.events.FullScreenEvent.FULL_SCREEN
//[Event(name="fullScreen",type="flash.events.FullScreenEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /**
         * The Stage object dispatches a FullScreenEvent object whenever the Stage enters or leaves full-screen display mode.
         * There is only one type of <codeph class="+ topic/ph pr-d/codeph ">fullScreen</codeph> event: <codeph class="+ topic/ph pr-d/codeph ">FullScreenEvent.FULL_SCREEN</codeph>.
         * @langversion 3.0
         * @playerversion   Flash 9.0.28.0
         * @playerversion   Lite 4
         */
        class FullScreenEvent : public ActivityEvent
        {
            /**
             * The FullScreenEvent.FULL_SCREEN constant defines the value of the type property of a fullScreen event object.
             * This event has the following properties:PropertyValuefullScreentrue if the display state is full screen or false if it is normal.bubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe Stage object.
             * @langversion 3.0
             * @playerversion   Flash 9.0.28.0
             * @playerversion   Lite 4
             */
        public:
            static const std::string FULL_SCREEN;
        public:
            static const std::string FULL_SCREEN_INTERACTIVE_ACCEPTED;

            /**
             * Indicates whether the Stage object is in full-screen mode (true) or not (false).
             * @langversion 3.0
             * @playerversion   Flash 9.0.28.0
             * @playerversion   Lite 4
             */
        public:
            bool         fullScreen();

        public:
            bool         interactive();

            /**
             * Creates a copy of a FullScreenEvent object and sets the value of each property to match that of
             * the original.
             * @return  A new FullScreenEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9.0.28.0
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

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
        public:
            FullScreenEvent(std::string type, bool bubbles   =false, bool cancelable   =false, bool fullScreen   =false, bool interactive   =false);

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
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_FULLSCREENEVENT_AS
#endif // __cplusplus

