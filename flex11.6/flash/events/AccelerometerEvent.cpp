

#include "AccelerometerEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.AccelerometerEvent.UPDATE

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * Defines the value of the type property of a AccelerometerEvent event object.  
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.timestampThe timestamp of the Accelerometer update.accelerationXThe acceleration value in Gs (9.8m/sec/sec) along the x-axis.accelerationYThe acceleration value in Gs (9.8m/sec/sec) along the y-axis. accelerationZThe acceleration value in Gs (9.8m/sec/sec) along the z-axis.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         * @playerversion   Lite 4
         */
        const std::string AccelerometerEvent::UPDATE="update";

        /**
         * Acceleration along the x-axis, measured in Gs. (1 G is roughly 9.8 m/sec/sec.) The x-axis runs from the left to the right of the device 
         * when it is in the upright position. The acceleration is positive if the device moves towards the right.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         * @playerversion   Lite 4
         */
        float AccelerometerEvent::accelerationX()         ;
        void AccelerometerEvent::accelerationX(float value)       ;

        /**
         * Acceleration along the y-axis, measured in Gs. (1 G is roughly 9.8 m/sec/sec.). 
         * The y-axis runs from the bottom to the top of the device when it is in the upright position. 
         * The acceleration is positive if the device moves up relative to this axis.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         * @playerversion   Lite 4
         */
        float AccelerometerEvent::accelerationY()         ;
        void AccelerometerEvent::accelerationY(float value)       ;

        /**
         * Acceleration along the z-axis, measured in Gs. (1 G is roughly 9.8 m/sec/sec.). 
         * The z-axis runs perpendicular to the face of the device. The acceleration is positive if you move the device 
         * so that the face moves higher.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         * @playerversion   Lite 4
         */
        float AccelerometerEvent::accelerationZ()         ;
        void AccelerometerEvent::accelerationZ(float value)       ;

        /**
         * The number of milliseconds at the time of the event since the runtime was initialized. 
         * For example, if the device captures accelerometer data 4 seconds after the application initializes, 
         * then the timestamp property of the event is set to 4000.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         * @playerversion   Lite 4
         */
        float AccelerometerEvent::timestamp()         ;
        void AccelerometerEvent::timestamp(float value)       ;

        /**
         * Creates an AccelerometerEvent object that contains information about acceleration along three dimensional axis.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one type of update event: AccelerometerEvent.UPDATE.
         * @param   bubbles Determines whether the Event object bubbles. Event listeners can access this information through the inherited bubbles property.
         * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
         * @param   timestamp   The timestamp of the Accelerometer update.
         * @param   accelerationX   The acceleration value in Gs (9.8m/sec/sec) along the x-axis.
         * @param   accelerationY   The acceleration value in Gs (9.8m/sec/sec) along the y-axis.
         * @param   accelerationZ   The acceleration value in Gs (9.8m/sec/sec) along the z-axis.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         * @playerversion   Lite 4
         */
        AccelerometerEvent::AccelerometerEvent(std::string type, bool bubbles, bool cancelable, float timestamp, float accelerationX, float accelerationY, float accelerationZ);

        /**
         * Creates a copy of an AccelerometerEvent object and sets the value of each property to match that of  
         * the original.
         * @return  A new AccelerometerEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         */
        flash::events::Event* AccelerometerEvent::clone()                     ;

        /**
         * Returns a string that contains all the properties of the AccelerometerEvent object. The following 
         * format is used:
         * 
         *   [AccelerometerEvent type=value bubbles=value cancelable=value 
         * timestamp=value accelerationX=value accelerationY=value accelerationZ=value ]
         * @return  A string that contains all the properties of the AccelerometerEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         */
        std::string AccelerometerEvent::toString()         ;
}
}

