#if !defined(FLEX11_6_FLASH_EVENTS_NETDATAEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_NETDATAEVENT_AS
#if defined(__cplusplus)


#include "flash/events/Event.h"

/**
 * A NetStream object dispatches a NetDataEvent object when a data message is encountered in the media stream.
 *
 *   <p class="- topic/p ">A NetDataEvent is dispatched for the following messages:</p><ul class="- topic/ul "><li class="- topic/li ">onCuePoint</li><li class="- topic/li ">onImageData</li><li class="- topic/li ">onMetaData</li><li class="- topic/li ">onPlayStatus (for code NetStream.Play.Complete)</li><li class="- topic/li ">onTextData</li><li class="- topic/li ">onXMPData</li></ul>
 * @langversion 3.0
 * @playerversion   Flash 10.3
 * @playerversion   AIR 2.7
 */
using namespace flash::events;

namespace flash
{
    namespace events
    {
        class NetDataEvent: public Event
        {
            /**
             * The NetDataEvent.MEDIA_TYPE_DATA constant defines the value of the type property of the NetDataEvent object
             * dispatched when a data message in the media stream is encountered by the NetStream object.
             * @langversion 3.0
             * @playerversion   Flash 10.3
             * @playerversion   AIR 2.7
             */
        public:
            static const std::string MEDIA_TYPE_DATA;

            /**
             * The timestamp of the data message in the media stream.
             * @langversion 3.0
             * @playerversion   Flash 10.3
             * @playerversion   AIR 2.7
             */
        public:
            float        timestamp();

            /**
             * A data object describing the message. The info object has two properties:
             * info.handler and info.args.
             * info.handler is the handler name, such as "onMetaData" or "onXMPData".
             * info.args is an array of arguments.
             * @langversion 3.0
             * @playerversion   Flash 10.3
             * @playerversion   AIR 2.7
             */
        public:
            Object      *info();

            /**
             * Creates a copy of an NetDataEvent object and sets the value of each property to match that of
             * the original.
             * @return  A new NetDataEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 10.3
             * @playerversion   AIR 2.7
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates an event object that contains information about media data events.
             * Event objects are passed as parameters to Event listeners.
             * @param   type    The type of the event. Event listeners can access this information through the
             *   inherited type property.
             * @param   bubbles Determines whether the Event object participates in the bubbling phase of the
             *   event flow. Event listeners can access this information through the inherited
             *   bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can
             *   access this information through the inherited cancelable property.
             * @param   timestamp   timestamp of the data message
             * @param   info    data message object
             * @langversion 3.0
             * @playerversion   Flash 10.3
             * @playerversion   AIR 2.7
             */
        public:
            NetDataEvent(std::string type, bool bubbles, bool cancelable, float timestamp, Object *info);

            /**
             * Returns a string that contains all the properties of the NetDataEvent object. The following
             * format is used:
             * [NetDataEvent type=value bubbles=value cancelable=value
             * timestamp=value]
             * @return  A string that contains all the properties of the NetMediaEvent object.
             * @langversion 3.0
             * @playerversion   Flash 10.3
             * @playerversion   AIR 2.7
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_NETDATAEVENT_AS
#endif // __cplusplus

