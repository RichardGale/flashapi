#if !defined(FLEX11_6_FLASH_EVENTS_GEOLOCATIONEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_GEOLOCATIONEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/Event.h"

/// @eventType  flash.events.GeolocationEvent.UPDATE
//[Event(name="update",type="flash.events.GeolocationEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /**
         * A Geolocation object dispatches GeolocationEvent objects when it receives updates from the location sensor installed on the device.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        class GeolocationEvent : public flash::events::Event
        {
            /**
             * Defines the value of the type property of a GeolocationEvent event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the event
             * object with an event listener.targetThe Geolocation object receiving data.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string UPDATE;

            /**
             * The latitude in degrees. The latitude values have the following range: (-90 <= latitude <= 90). Negative latitude is
             * south and positive latitude is north.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       latitude();
        public:
            void         latitude(float value);

            /**
             * The longitude in degrees. The longitude values have the following range: (-180 <= longitude < 180). Negative longitude is
             * west and positive longitude is east.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       longitude();
        public:
            void         longitude(float value);

            /**
             * The altitude in meters.
             *
             *   If altitude is not supported by the device, then this property is set to NaN.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       altitude();
        public:
            void         altitude(float value);

            /**
             * The horizontal accuracy in meters.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       horizontalAccuracy();
        public:
            void         horizontalAccuracy(float value);

            /**
             * The vertical accuracy in meters.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       verticalAccuracy();
        public:
            void         verticalAccuracy(float value);

            /**
             * The speed in meters/second.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       speed();
        public:
            void         speed(float value);

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
        public:
            float       heading();
        public:
            void         heading(float value);

            /**
             * The number of milliseconds at the time of the event since the runtime was initialized.
             * For example, if the device captures geolocation data 4 seconds after the application initializes,
             * then the timestamp property of the event is set to 4000.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       timestamp();
        public:
            void         timestamp(float value);

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
        public:
            GeolocationEvent(std::string type, bool bubbles=false, bool cancelable=false, float latitude=0, float longitude=0, float altitude=0, float hAccuracy=0, float vAccuracy=0, float speed=0, float heading=0, float timestamp=0);

            /**
             * Creates a copy of the GeolocationEvent object and sets the value of each property to match that of the original.
             * @return  A new GeolocationEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            flash::events::Event *clone();

            /**
             * Returns a string that contains all the properties of the GeolocationEvent object.
             * The string is in the following format:
             *
             *   [GeolocationEvent type=value bubbles=value cancelable=value status=value]
             * @return  A string that contains all the properties of the GeolocationEvent object.
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            std::string   toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_GEOLOCATIONEVENT_AS
#endif // __cplusplus

