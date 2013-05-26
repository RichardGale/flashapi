

#include "SampleDataEvent.h"
#include "flash/events/Event.h"
#include "flash/utils/ByteArray.h"

    /// @eventType  flash.events.SampleDataEvent.SAMPLE_DATA

using namespace flash::events;
using namespace flash::utils;

namespace flash {
namespace events {


        /**
         * Defines the value of the type property of a SampleDataEvent event object. 
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.positionThe point from which audio data is provided.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string SampleDataEvent::SAMPLE_DATA   = "sampleData";

        /**
         * The position of the data in the audio stream.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        float SampleDataEvent::position()         ;
        void SampleDataEvent::position(float theposition)       ;

        /**
         * The data in the audio stream.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        flash::utils::ByteArray* SampleDataEvent::data()                        ;
        void SampleDataEvent::data(ByteArray* thedata)       ;

        /**
         * Creates a copy of the SampleDataEvent object and sets each property's value to match that of the original.
         * @return  A new SampleDataEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        flash::events::Event* SampleDataEvent::clone()                     ;

        /**
         * Creates an event object that contains information about audio data events. 
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. This value is:Event.SAMPLE_DATA.
         * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow.
         * @param   cancelable  Determines whether the Event object can be canceled.
         * @param   theposition The position of the data in the audio stream.
         * @param   thedata A byte array of data.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        SampleDataEvent::SampleDataEvent(std::string type, bool bubbles, bool cancelable, float theposition, ByteArray* thedata);

        /**
         * Returns a string that contains all the properties of the SampleDataEvent object. The string is in the following format:
         * [SampleDataEvent type=value bubbles=value cancelable=value theposition=value thedata=value]
         * @return  A string that contains all the properties of the SampleDataEvent object.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::string SampleDataEvent::toString()         ;
}
}

