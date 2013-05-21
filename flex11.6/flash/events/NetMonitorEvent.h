#if !defined(FLEX11_6_FLASH_EVENTS_NETMONITOREVENT_AS)
#define FLEX11_6_FLASH_EVENTS_NETMONITOREVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace net
    {
        class NetStream;
    }
}
#include "flash/events/Event.h"

/// @eventType  flash.events.NetMonitorEvent.NET_STREAM_CREATE
//[Event(name="netStreamCreate",type="flash.events.NetMonitorEvent")]

using namespace flash::events;
using namespace flash::net;

namespace flash
{
    namespace events
    {
        /**
         * A NetMonitor object dispatches NetMonitorEvent objects when a NetStream object is created.
         * @langversion 3.0
         * @playerversion   Flash 10.3
         * @playerversion   AIR 2.7
         */
        class NetMonitorEvent : public flash::events::Event
        {
            /**
             * The NetMonitorEvent.NET_STREAM_CREATE constant defines the value of the type property of an netStreamCreate event object.
             * The netStreamCreate event has the following properties:PropertyValuenetStreamNetStream object that has been created.bubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe object beginning or ending a session.
             * @langversion 3.0
             * @playerversion   Flash 10.3
             * @playerversion   AIR 2.7
             */
        public:
            static const std::string NET_STREAM_CREATE;

            /**
             * The new NetStream object.
             * @langversion 3.0
             * @playerversion   Flash 10.3
             * @playerversion   AIR 2.7
             */
        public:
            flash::net::NetStream *netStream();

            /**
             * Creates a copy of an NetMonitorEvent object and sets the value of each property to match that of
             * the original.
             * @return  A new NetMonitorEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 10.3
             * @playerversion   AIR 2.7
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates an event object that contains information about netStreamCreate events.
             * Event objects are passed as parameters to Event listeners.
             * @param   type    The type of the event. Event listeners can access this information through the
             *   inherited type property. There is only one type of event:
             *   NetMonitorEvent.NET_STREAM_CREATE.
             * @param   bubbles Determines whether the Event object participates in the bubbling phase of the
             *   event flow. Event listeners can access this information through the inherited
             *   bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can
             *   access this information through the inherited cancelable property.
             * @param   netStream   The new NetStream object that has been created. Event listeners can access
             *   this information through the netStream property.
             * @langversion 3.0
             * @playerversion   Flash 10.3
             * @playerversion   AIR 2.7
             */
        public:
            NetMonitorEvent(std::string type, bool bubbles   =false, bool cancelable   =false, NetStream *netStream=NULL);

            /**
             * Returns a string that contains all the properties of the NetMonitorEvent object. The following
             * format is used:
             * [NetMonitorEvent type=value bubbles=value cancelable=value
             * netStream=value]
             * @return  A string that contains all the properties of  NetMonitorEvent object.
             * @langversion 3.0
             * @playerversion   Flash 10.3
             * @playerversion   AIR 2.7
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_NETMONITOREVENT_AS
#endif // __cplusplus

