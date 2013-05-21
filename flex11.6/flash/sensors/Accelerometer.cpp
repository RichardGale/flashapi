

#include "Accelerometer.h"
#include "flash/events/EventDispatcher.h"

    /**
     * Dispatched when an accelerometer changes its status.
     * @eventType   flash.events.StatusEvent.STATUS
     */

using namespace flash::events;

namespace flash {
namespace sensors {


        /**
         * The isSupported property is set to true if the accelerometer sensor is 
         * available on the device, otherwise it is set to false.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         * @playerversion   Lite 4
         */
        bool Accelerometer::isSupported()          ;

        /**
         * Specifies whether the user has denied access to the accelerometer (true) 
         * or allowed access (false). When this value changes, 
         * a status event is dispatched.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         */
        bool Accelerometer::muted()          ;

        /**
         * Creates a new Accelerometer instance.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         * @playerversion   Lite 4
         */
        Accelerometer::Accelerometer();

        /**
         * The setRequestedUpdateInterval method is used to set the desired time interval 
         * for updates. The time interval is measured in milliseconds. The update interval is only used as a 
         * hint to conserve the battery power. The actual time between acceleration updates may be greater
         * or lesser than this value. Any change in the update interval affects all registered listeners. 
         * You can use the Accelerometer class without calling the setRequestedUpdateInterval() 
         * method. In this case, the application receives updates based on the device's default interval.
         * @param   interval    The requested update interval. If interval is set to 0, then the minimum supported update interval is used.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         * @playerversion   Lite 4
         * @throws  ArgumentError The specified interval is less than zero.
         */
        void Accelerometer::setRequestedUpdateInterval(float interval)       ;
}
}

