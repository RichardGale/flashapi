

#include "DataEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.DataEvent.DATA

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * Defines the value of the type property of a data event object.  
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.dataThe raw data loaded into Flash Player or Adobe AIR.targetThe XMLSocket object receiving data.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string DataEvent::DATA   = "data";

        /**
         * Defines the value of the type property of an uploadCompleteData event object.
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.dataThe raw data returned from the server after a successful file upload.targetThe FileReference object receiving data after a successful upload.
         * @langversion 3.0
         * @playerversion   Flash 9.0.28.0
         * @playerversion   Lite 4
         */
        const std::string DataEvent::UPLOAD_COMPLETE_DATA   = "uploadCompleteData";

        /**
         * The raw data loaded into Flash Player or Adobe AIR.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string DataEvent::data()         ;
        void DataEvent::data(std::string value)       ;

        /**
         * Creates an event object that contains information about data events.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Event listeners can access this information through the
         *   inherited type property. There is only one type of data event:
         *   DataEvent.DATA.
         * @param   bubbles Determines whether the Event object participates in the bubbling phase of the
         *   event flow. Event listeners can access this information through the inherited
         *   bubbles property.
         * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can
         *   access this information through the inherited cancelable property.
         * @param   data    The raw data loaded into Flash Player or Adobe AIR. Event listeners can access this information
         *   through the data property.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        DataEvent::DataEvent(std::string type, bool bubbles, bool cancelable, std::string data);

        /**
         * Creates a copy of the DataEvent object and sets the value of each property to match that of the
         * original.
         * @return  A new DataEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::events::Event* DataEvent::clone()                     ;

        /**
         * Returns a string that contains all the properties of the DataEvent object. The string is in 
         * the following format:
         * [DataEvent type=value bubbles=value cancelable=value
         * data=value]
         * @return  A string that contains all the properties of the DataEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string DataEvent::toString()         ;
}
}

