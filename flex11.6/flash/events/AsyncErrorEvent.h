#if !defined(FLEX11_6_FLASH_EVENTS_ASYNCERROREVENT_AS)
#define FLEX11_6_FLASH_EVENTS_ASYNCERROREVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace events
    {
        class Event;
    }
}

/// @eventType  flash.events.AsyncErrorEvent.ASYNC_ERROR
//[Event(name="asyncError",type="flash.events.AsyncErrorEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /**
         * An object dispatches an AsyncErrorEvent when an exception is thrown from native
         * asynchronous code, which could be from, for example, LocalConnection, NetConnection,
         * <ph class="- topic/ph ">SharedObject</ph>, or NetStream. There is only one type of asynchronous error event:
         * <codeph class="+ topic/ph pr-d/codeph ">AsyncErrorEvent.ASYNC_ERROR</codeph>.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        class AsyncErrorEvent : public ErrorEvent
        {
            /**
             * The AsyncErrorEvent.ASYNC_ERROR constant defines the value of the
             * type property of an asyncError event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default
             * behavior to cancel. currentTargetThe object that is actively processing the
             * Event object with an event listener. targetThe object dispatching the event.errorThe error that triggered the event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string ASYNC_ERROR;

            /**
             * The exception that was thrown.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            Error *error;

            /**
             * Creates an AsyncErrorEvent object that contains information about asyncError events.
             * AsyncErrorEvent objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Event listeners can access this information through
             *   the inherited type property. There is only one type of error event:
             *   ErrorEvent.ERROR.
             * @param   bubbles Determines whether the Event object bubbles. Event listeners can access
             *   this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners
             *   can access this information through the inherited cancelable property.
             * @param   text    Text to be displayed as an error message. Event listeners can access this
             *   information through the text property.
             * @param   error   The exception that occurred.
             *   If error is non-null, the event's errorId property is set from the error's
             *   errorId property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            AsyncErrorEvent(std::string type, bool bubbles=false, bool cancelable=false, std::string text="", Error *error=NULL);

            /**
             * Creates a copy of the AsyncErrorEvent object and sets the value of each property to match
             * that of the original.
             * @return  A new AsyncErrorEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Returns a string that contains all the properties of the AsyncErrorEvent object. The
             * string is in the following format:
             * [AsyncErrorEvent type=value bubbles=value
             * cancelable=value ... error=value errorID=value]
             * The errorId is only available in Adobe AIR
             * @return  A string that contains all the properties of the AsyncErrorEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string   toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_ASYNCERROREVENT_AS
#endif // __cplusplus

