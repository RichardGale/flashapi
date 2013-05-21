#if !defined(FLEX11_6_FLASH_EVENTS_DATAEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_DATAEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace events
    {
        class Event;
    }
}

/// @eventType  flash.events.DataEvent.DATA
//[Event(name="data",type="flash.events.DataEvent")]


//[Event(name="uploadCompleteData",type="flash.events.DataEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /// @eventType  flash.events.DataEvent.UPLOAD_COMPLETE_DATA


        /**
         * An object dispatches a DataEvent object when raw data has completed loading.
         * There are two types of data event:
         * <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">DataEvent.DATA</codeph>: dispatched for data sent or received.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">DataEvent.UPLOAD_COMPLETE_DATA</codeph>: dispatched when data is sent and the server has responded.</li></ul>
         *
         *   EXAMPLE:
         *
         *   The following example creates an XMLSocket and connects it to a socket server
         * running on port 8080 of <codeph class="+ topic/ph pr-d/codeph ">yourDomain</codeph>. An event listener is attached to the XMLSocket
         * object that listens for <codeph class="+ topic/ph pr-d/codeph ">data</codeph> events, which are dispatched whenever raw data
         * is received.
         *
         *   <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Notes:</b><ul class="- topic/ul "><li class="- topic/li ">To generate a <codeph class="+ topic/ph pr-d/codeph ">securityError</codeph> event in this example, you need to compile the SWF file with "Local playback security" set
         * to "Access network only".</li><li class="- topic/li ">You need a server running on [<codeph class="+ topic/ph pr-d/codeph ">yourDomain</codeph>] using port 8080.</li></ul></p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Sprite;
         * import flash.events.DataEvent;
         * import flash.net.XMLSocket;
         *
         *   public class DataEventExample extends Sprite {
         * private var hostName:String = "[yourDomain]";
         * private var port:uint = 8080;
         * private var socket:XMLSocket;
         *
         *   public function DataEventExample() {
         * socket = new XMLSocket();
         * socket.addEventListener(DataEvent.DATA, dataHandler);
         * socket.connect(hostName, port);
         * }
         *
         *   private function dataHandler(event:DataEvent):void {
         * trace("dataHandler: " + event.data);
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        class DataEvent : public TextEvent
        {
            /**
             * Defines the value of the type property of a data event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.dataThe raw data loaded into Flash Player or Adobe AIR.targetThe XMLSocket object receiving data.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string DATA;

            /**
             * Defines the value of the type property of an uploadCompleteData event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.dataThe raw data returned from the server after a successful file upload.targetThe FileReference object receiving data after a successful upload.
             * @langversion 3.0
             * @playerversion   Flash 9.0.28.0
             * @playerversion   Lite 4
             */
        public:
            static const std::string UPLOAD_COMPLETE_DATA;

            /**
             * The raw data loaded into Flash Player or Adobe AIR.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  data();
        public:
            void         data(std::string value);

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
        public:
            DataEvent(std::string type, bool bubbles   =false, bool cancelable   =false, std::string data="");

            /**
             * Creates a copy of the DataEvent object and sets the value of each property to match that of the
             * original.
             * @return  A new DataEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

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
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_DATAEVENT_AS
#endif // __cplusplus

