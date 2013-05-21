

#include "NetMonitor.h"
#include "flash/events/EventDispatcher.h"
#include "flash/net/NetStream.h"

    /**
     * Dispatched when a new NetStream object is created within the security context of this NetMonitor instance.
     * @eventType   flash.events.NetMonitorEvent.NET_STREAM_CREATE
     */

using namespace flash::events;
using namespace flash::net;

namespace flash {
namespace net {


        /**
         * Retrieves all NetStream objects belonging to this NetMonitor object's security context.
         * 
         *   Avoid caching the list of NetStream objects. Maintaining a reference to these NetStream objects
         * can introduce memory leaks into an application by preventing the garbage collector from reclaiming 
         * an object's resources when it is no longer being used.Note: if the NetStream monitoring is not supported on the current platform, the list returned by 
         * this function is always empty.
         * @return  Vector of NetStream objects
         * @langversion 3.0
         * @playerversion   Flash 10.3
         * @playerversion   Flash AIR  2.7
         */
        std::vector<flash::net::NetStream*> NetMonitor::listStreams()                               ;

        NetMonitor::NetMonitor();
}
}

