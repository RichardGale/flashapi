

#include "GeolocationEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.GeolocationEvent.UPDATE

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * Defines the value of the type property of a GeolocationEvent event object.  
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the event 
         * object with an event listener.targetThe Geolocation object receiving data.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        const std::string GeolocationEvent::UPDATE="update";

        /**
         * The latitude in degrees. The latitude values have the following range: (-90 <= latitude <= 90). Negative latitude is 
         * south and positive latitude is north.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float GeolocationEvent::latitude()         ;
        void GeolocationEvent::latitude(float value)       ;

        /**
         * The longitude in degrees. The longitude values have the following range: (-180 <= longitude < 180). Negative longitude is 
         * west and positive longitude is east.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float GeolocationEvent::longitude()         ;
        void GeolocationEvent::longitude(float value)       ;

        /**
         * The altitude in meters.
         * 
         *   If altitude is not supported by the device, then this property is set to NaN.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float GeolocationEvent::altitude()         ;
        void GeolocationEvent::altitude(float value)       ;

        /**
         * The horizontal accuracy in meters.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float GeolocationEvent::horizontalAccuracy()         ;
        void GeolocationEvent::horizontalAccuracy(float value)       ;

        /**
         * The vertical accuracy in meters.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float GeolocationEvent::verticalAccuracy()         ;
        void GeolocationEvent::verticalAccuracy(float value)       ;

        /**
         * The speed in meters/second.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float GeolocationEvent::speed()         ;
        void GeolocationEvent::speed(float value)       ;

        /**
         * The direction of movement (with respect to true north) in integer degrees. This is not the same as
         * "bearing", which returns the direction of movement with respect to another point.
         * 
         *   Note: On Android devices, heading is not supported. The value of the heading
         * property is always NaN (Not a Number).
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float GeolocationEvent::heading()         ;
        void GeolocationEvent::heading(float value)       ;

        /**
         * The number of milliseconds at the time of the event since the runtime was initialized. 
         * For example, if the device captures geolocation data 4 seconds after the application initializes, 
         * then the timestamp property of the event is set to 4000.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float GeolocationEvent::timestamp()         ;
        void GeolocationEvent::timestamp(float value)       ;

        /**
         * Creates a GeolocationEvent object that contains information about the 
         * location of the device. Event objects are passed as parameters to event listeners.
         * @param   type    Specifies the type of the event. Event listeners can access this information
         *   through the inherited type property. There is only one type of update 
         *   event: GeolocationEvent.UPDATE.
         * @param   bubbles Indicates whether the event is a bubbling event. Event listeners can access
         *   this information through the inherited bubbles property.
         * @param   cancelable  Determines whether the event object can be canceled. Event listeners can access 
         *   this information through the inherited cancelable property.
         * @param   latitude    Returns the latitude in degrees. The values have the following range: (-90 <= Lat <= +90).
         * @param   longitude   Returns the longitude in degrees. The values have the following range: (-180 <= Long < +180).
         * @param   altitude    Returns the altitude in meters.
         * @param   hAccuracy   Returns the horizontal accuracy in meters.
         * @param   vAccuracy   Returns the vertical accuracy in meters.
         * @param   speed   Returns the speed in meters/second.
         * @param   heading Returns the direction of movement (with respect to True North) in integer degrees.
         * @param   timestamp   Specifies the timestamp of the geolocation update.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        GeolocationEvent::GeolocationEvent(std::string type, bool bubbles, bool cancelable, float latitude, float longitude, float altitude, float hAccuracy, float vAccuracy, float speed, float heading, float timestamp);

        /**
         * Creates a copy of the GeolocationEvent object and sets the value of each property to match that of the original.
         * @return  A new GeolocationEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   AIR 2
         */
        flash::events::Event* GeolocationEvent::clone()                     ;

        /**
         * Returns a string that contains all the properties of the GeolocationEvent object. 
         * The string is in the following format:
         * 
         *   [GeolocationEvent type=value bubbles=value cancelable=value status=value]
         * @return  A string that contains all the properties of the GeolocationEvent object.
         * @langversion 3.0
         * @playerversion   AIR 2
         */
        std::string GeolocationEvent::toString()         ;
}
}

