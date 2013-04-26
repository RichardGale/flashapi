#if !defined(FLEX11_6_FLASH_SENSORS_GEOLOCATION_AS)
#define FLEX11_6_FLASH_SENSORS_GEOLOCATION_AS
#if defined(__cplusplus)


#include "flash/events/EventDispatcher.h"

/**
 * The Geolocation object dispatches status events when the user changes access
 * to the location sensor.
 * @eventType   flash.events.StatusEvent.STATUS
 */
//[Event(name="status",type="flash.events.StatusEvent")]

/**
 * The update event is dispatched in response to updates from the location sensor.
 * @eventType   flash.events.GeolocationEvent.UPDATE
 */
//[Event(name="update",type="flash.events.GeolocationEvent")]

/**
 * The Geolocation class dispatches events in response to the device's location sensor.
 *
 *   <p class="- topic/p ">If a device supports geolocation, you can use this class to obtain the current geographical
 * location of the device. The geographical location is displayed on the device in the form of latitudinal
 * and longitudinal coordinates (in WGS-84 standard format). When the location of the device changes,
 * you can receive updates about the changes. If the device supports this feature, you will be able to obtain
 * information about the altitude, accuracy, heading, speed, and timestamp of the latest change in the location.</p><p class="- topic/p "><i class="+ topic/ph hi-d/i ">AIR profile support:</i> This feature is supported
 * only on mobile devices. It is not supported on desktop or AIR for TV devices. You can test
 * for support at run time using the <codeph class="+ topic/ph pr-d/codeph ">Geolocation.isSupported</codeph> property. See
 * <xref href="http://help.adobe.com/en_US/air/build/WS144092a96ffef7cc16ddeea2126bb46b82f-8000.html" class="- topic/xref ">
 * AIR Profile Support</xref> for more information regarding API support across multiple profiles.
 * </p>
 *
 *   EXAMPLE:
 *
 *   In the following example, the application displays the latitude,
 * longitude, and horizontal accuracy of geolocation <codeph class="+ topic/ph pr-d/codeph ">update</codeph> events
 * as they are received.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package
 * {
 * import flash.display.Sprite;
 * import flash.display.StageAlign;
 * import flash.display.StageScaleMode;
 * import flash.events.GeolocationEvent;
 * import flash.sensors.Geolocation;
 * import flash.text.TextField;
 * import flash.text.TextFormat;
 *
 *   public class GeolocationTest extends Sprite
 * {
 * private var geo:Geolocation;
 * private var log:TextField;
 *
 *   public function GeolocationTest()
 * {
 * stage.scaleMode = StageScaleMode.NO_SCALE;
 * stage.align = StageAlign.TOP_LEFT;
 * setUpTextField();
 *
 *   if (Geolocation.isSupported)
 * {
 * geo = new Geolocation();
 * geo.setRequestedUpdateInterval(100);
 * geo.addEventListener(GeolocationEvent.UPDATE, geolocationUpdateHandler);
 * }
 * else
 * {
 * log.text =  "No geolocation support.";
 * }
 * }
 *
 *   private function geolocationUpdateHandler(event:GeolocationEvent):void
 * {
 * log.text = "latitude:" + event.latitude.toString() + "  \n";
 * log.appendText("longitude:" + event.longitude.toString() + "  \n");
 * log.appendText("horizontal accuracy:" + event.horizontalAccuracy.toString() + " m");
 * }
 * private function setUpTextField():void
 * {
 * log = new TextField();
 * var format:TextFormat = new TextFormat("_sans", 24);
 * log.defaultTextFormat = format;
 * log.border = true;
 * log.wordWrap = true;
 * log.multiline = true;
 * log.x = 10;
 * log.y = 10;
 * log.height = stage.stageHeight - 20;
 * log.width = stage.stageWidth - 20;
 * addChild(log);
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   AIR 2
 * @playerversion   Lite 4
 */
using namespace flash::events;

namespace flash
{
    namespace sensors
    {
        class Geolocation: public EventDispatcher
        {
            /**
             * Whether a location sensor is available on the device (true); otherwise false.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static bool         isSupported();

            /**
             * Specifies whether the user has denied access to the geolocation (true)
             * or allowed access (false). When this value changes,
             * a status event is dispatched.
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            bool         muted();

            /**
             * Creates a new Geolocation instance.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            Geolocation();

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
        public:
            void     setRequestedUpdateInterval(float interval);
        };
    }
}

#endif // FLEX11_6_FLASH_SENSORS_GEOLOCATION_AS
#endif // __cplusplus

