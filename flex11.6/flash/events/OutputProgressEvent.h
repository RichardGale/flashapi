#if !defined(FLEX11_6_FLASH_EVENTS_OUTPUTPROGRESSEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_OUTPUTPROGRESSEVENT_AS
#if defined(__cplusplus)


#include "flash/events/Event.h"

/// @eventType  flash.events.OutputProgressEvent.OUTPUT_PROGRESS
//[Event(name="outputProgress",type="flash.events.OutputProgressEvent")]

/**
 * A FileStream object dispatches OutputProgressEvent objects as pending asynchronous file write operations are
 * performed. There is one type of output progress event: <codeph class="+ topic/ph pr-d/codeph ">OutputProgressEvent.OUTPUT_PROGRESS</codeph>.
 * @langversion 3.0
 * @playerversion   AIR 1.0
 */
using namespace flash::events;

namespace flash
{
    namespace events
    {
        class OutputProgressEvent: public Event
        {
            /**
             * Defines the value of the type property of an outputProgress event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsebytesPendingThe number of bytes remaining to be written at the time the
             * listener processes the event.bytesTotalThe total number of bytes that ultimately
             * will be written if the write process succeeds.cancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe FileStream object reporting progress.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string OUTPUT_PROGRESS;

            /**
             * The number of bytes not yet written when the listener processes the event.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            float        bytesPending();
        public:
            void         bytesPending(float value);

            /**
             * The total number of bytes written so far, plus the number of pending bytes to be written.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            float        bytesTotal();
        public:
            void         bytesTotal(float value);

            /**
             * Creates a copy of the OutputProgressEvent object and sets each property's value to match that of the original.
             * @return  A new OutputProgressEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates an Event object that contains information about output progress events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. There is only one type of error event:
             *   OutputProgressEvent.OUTPUT_PROGRESS.
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow.
             * @param   cancelable  Determines whether the Event object can be canceled.
             * @param   bytesPending    The number of bytes not yet written.
             * @param   bytesTotal  The total number of bytes written or with pending writes.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            OutputProgressEvent(std::string type, bool bubbles, bool cancelable, float bytesPending, float bytesTotal);

            /**
             * Returns a string that contains all the properties of the OutputProgressEvent object. The string is in the following format:
             *
             *   [OutputProgressEvent type=value bubbles=value cancelable=value eventPhase=value bytesPending=value bytesTotal=value]
             * @return  A string that contains all the properties of the OutputProgressEvent object.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_OUTPUTPROGRESSEVENT_AS
#endif // __cplusplus

