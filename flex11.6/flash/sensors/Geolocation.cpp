

#include "Geolocation.h"
#include "flash/events/EventDispatcher.h"

    /**
     * The Geolocation object dispatches status events when the user changes access 
     * to the location sensor.
     * @eventType   flash.events.StatusEvent.STATUS
     */

using namespace flash::events;

namespace flash {
namespace sensors {


        /**
         * Whether a location sensor is available on the device (true); otherwise false.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        bool Geolocation::isSupported()          ;

        /**
         * Specifies whether the user has denied access to the geolocation (true) 
         * or allowed access (false). When this value changes, 
         * a status event is dispatched.
         * @langversion 3.0
         * @playerversion   AIR 2
         */
        bool Geolocation::muted()          ;

        /**
         * Creates a new Geolocation instance.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        Geolocation::Geolocation();

        /**
         * Used to set the time interval for updates, in milliseconds. The update interval is only used as a
         * hint to conserve the battery power. The actual time between location updates may be greater or
         * lesser than this value.Any change in the update interval using this method 
         * affects all registered update event listeners. The Geolocation class 
         * can be used without calling the setRequestedUpdateInterval method. 
         * In this case, the platform will return updates based on its default interval.
         * 
         *   Note: First-generation iPhones, which do not include a GPS unit, dispatch 
         * update events only occasionally. On these devices, a Geolocation object initially 
         * dispatches one or two update  events. It then dispatches update events 
         * when information changes noticeably.
         * @param   interval    requested update interval. If interval <= 0, then any call to this method
         *   has no effect.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         * @throws  ArgumentError The specified interval is less than zero.
         */
        void Geolocation::setRequestedUpdateInterval(float interval)       ;
}
}

