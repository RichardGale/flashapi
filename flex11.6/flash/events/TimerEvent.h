#if !defined(FLEX11_6_FLASH_EVENTS_TIMEREVENT_AS)
#define FLEX11_6_FLASH_EVENTS_TIMEREVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/Event.h"

/// @eventType  flash.events.TimerEvent.TIMER_COMPLETE
//[Event(name="timerComplete",type="flash.events.TimerEvent")]


//[Event(name="timer",type="flash.events.TimerEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /// @eventType  flash.events.TimerEvent.TIMER


        /**
         * A Timer object dispatches a TimerEvent objects whenever the Timer object reaches the interval
         * specified by the <codeph class="+ topic/ph pr-d/codeph ">Timer.delay</codeph> property.
         *
         *   EXAMPLE:
         *
         *   The following example uses the TimerExample class to show how a
         * listener method <codeph class="+ topic/ph pr-d/codeph ">timerHandler()</codeph> can be instantiated and set to listen for a new TimerEvent
         * to be dispatched, which happens when the Timer's <codeph class="+ topic/ph pr-d/codeph ">start()</codeph> method is called.
         * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.utils.Timer;
         * import flash.events.TimerEvent;
         * import flash.display.Sprite;
         *
         *   public class TimerEventExample extends Sprite {
         *
         *   public function TimerEventExample() {
         * var myTimer:Timer = new Timer(1000, 2);
         * myTimer.addEventListener(TimerEvent.TIMER, timerHandler);
         * myTimer.start();
         * }
         *
         *   public function timerHandler(event:TimerEvent):void {
         * trace("timerHandler: " + event);
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        class TimerEvent : public flash::events::Event
        {
            /**
             * Defines the value of the type property of a timer event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe Timer object that has reached its interval.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string TIMER;

            /**
             * Defines the value of the type property of a timerComplete event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe Timer object that has completed its requests.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string TIMER_COMPLETE;

            /**
             * Creates a copy of the TimerEvent object and sets each property's value to match that of the original.
             * @return  A new TimerEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

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
        public:
            TimerEvent(std::string type, bool bubbles=false, bool cancelable=false);

            /**
             * Returns a string that contains all the properties of the TimerEvent object. The string is in the following format:
             * [TimerEvent type=value bubbles=value cancelable=value]
             * @return  A string that contains all the properties of the TimerEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string   toString();

            /**
             * Instructs Flash Player or the AIR runtime to render
             * after processing of this event completes, if the display list has been modified.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     updateAfterEvent();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_TIMEREVENT_AS
#endif // __cplusplus

