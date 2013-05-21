

#include "ProgressEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.ProgressEvent.PROGRESS

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * Defines the value of the type property of a progress event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsebytesLoadedThe number of items or bytes loaded at the time the listener processes the event.bytesTotalThe total number of items or bytes that ultimately will  be loaded if the loading process succeeds.cancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe object reporting progress.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string ProgressEvent::PROGRESS="progress";

        /**
         * Defines the value of the type property of a socketData event object.
         * 
         *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event.bytesLoadedThe number of items or bytes loaded at the time the listener processes the event.bytesTotal0; this property is not used by socketData event objects.targetThe socket reporting progress.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string ProgressEvent::SOCKET_DATA="socketData";

        /**
         * The number of items or bytes loaded when the listener processes the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        float ProgressEvent::bytesLoaded()         ;
        void ProgressEvent::bytesLoaded(float value)       ;

        /**
         * The total number of items or bytes that will be loaded if the loading process succeeds. 
         * If the progress event is dispatched/attached to a Socket object, the bytesTotal will always be 0 
         * unless a value is specified in the bytesTotal parameter of the constructor. 
         * The actual number of bytes sent back or forth is not set and is up to the application developer.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        float ProgressEvent::bytesTotal()         ;
        void ProgressEvent::bytesTotal(float value)       ;

        /**
         * Creates an Event object that contains information about progress events.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Possible values are:ProgressEvent.PROGRESS, 
         *   ProgressEvent.SOCKET_DATA, ProgressEvent.STANDARD_ERROR_DATA, ProgressEvent.STANDARD_INPUT_PROGRESS, and ProgressEvent.STANDARD_OUTPUT_DATA.
         * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow.
         * @param   cancelable  Determines whether the Event object can be canceled.
         * @param   bytesLoaded The number of items or bytes loaded at the time the listener processes the event.
         * @param   bytesTotal  The total number of items or bytes that will be loaded if the loading process succeeds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        ProgressEvent::ProgressEvent(std::string type, bool bubbles, bool cancelable, float bytesLoaded, float bytesTotal);

        /**
         * Creates a copy of the ProgressEvent object and sets each property's value to match that of the original.
         * @return  A new ProgressEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::events::Event* ProgressEvent::clone()                     ;

        /**
         * Returns a string that contains all the properties of the ProgressEvent object. The string is in the following format:
         * [ProgressEvent type=value bubbles=value cancelable=value bytesLoaded=value bytesTotal=value]
         * @return  A string that contains all the properties of the ProgressEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string ProgressEvent::toString()         ;
}
}

