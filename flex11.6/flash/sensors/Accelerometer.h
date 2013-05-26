#if !defined(FLEX11_6_FLASH_SENSORS_ACCELEROMETER_AS)
#define FLEX11_6_FLASH_SENSORS_ACCELEROMETER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"

/**
 * Dispatched when an accelerometer changes its status.
 * @eventType   flash.events.StatusEvent.STATUS
 */
//[Event(name="status",type="flash.events.StatusEvent")]

/**
 * The update event is dispatched in response to updates from the accelerometer sensor.
 * @eventType   flash.events.AccelerometerEvent.UPDATE
 */
//[Event(name="update",type="flash.events.AccelerometerEvent")]

using namespace flash::events;

namespace flash
{
    namespace sensors
    {
        /**
         * The Accelerometer class dispatches events based on activity detected by the device's motion sensor.
         * This data represents the device's location or
         * movement along a 3-dimensional axis. When the device moves, the sensor detects this movement and
         * returns acceleration data. The Accelerometer class provides methods to query whether or not
         * accelerometer is supported, and also to set the rate at which acceleration events are dispatched.
         * <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> Use the <codeph class="+ topic/ph pr-d/codeph ">Accelerometer.isSupported</codeph> property to test the runtime environment for the ability
         * to use this feature. While the Accelerometer class and its members are accessible to the Runtime Versions listed for
         * each API entry, the current environment for the runtime determines the availability of this feature. For example, you can
         * compile code using the Accelerometer class properties for Flash Player 10.1, but you need to use the <codeph class="+ topic/ph pr-d/codeph ">Accelerometer.isSupported</codeph>
         * property to test for the availability of the Accelerometer feature in the current deployment environment for the Flash Player runtime. If
         * <codeph class="+ topic/ph pr-d/codeph ">Accelerometer.isSupported</codeph> is <codeph class="+ topic/ph pr-d/codeph ">true</codeph> at runtime, then Accelerometer support currently exists.</p><p class="- topic/p "><i class="+ topic/ph hi-d/i ">AIR profile support:</i> This feature is supported
         * only on mobile devices. It is not supported on desktop or AIR for TV devices. See
         * <xref href="http://help.adobe.com/en_US/air/build/WS144092a96ffef7cc16ddeea2126bb46b82f-8000.html" class="- topic/xref ">
         * AIR Profile Support</xref> for more information regarding API support across multiple profiles.
         * </p>
         *
         *   EXAMPLE:
         *
         *   In the following example, the application moves a Sprite
         * based on accelerometer <codeph class="+ topic/ph pr-d/codeph ">update</codeph> events. The accelerometer
         * <codeph class="+ topic/ph pr-d/codeph ">update</codeph> events indicate movement of the device.
         * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package
         * {
         * import flash.display.Sprite;
         * import flash.display.StageAlign;
         * import flash.display.StageScaleMode;
         * import flash.events.Event;
         * import flash.events.AccelerometerEvent;
         * import flash.sensors.Accelerometer;
         *
         *   public class AccelerometerTest extends Sprite
         * {
         * private var ball:Sprite;
         * private var accelerometer:Accelerometer;
         * private var xSpeed:Number = 0;
         * private var ySpeed:Number = 0;
         * private const RADIUS = 20;
         *
         *   public final function AccelerometerTest()
         * {
         * stage.scaleMode = StageScaleMode.NO_SCALE;
         * stage.align = StageAlign.TOP_LEFT;
         *
         *   createBall();
         *
         *   if (Accelerometer.isSupported)
         * {
         * accelerometer = new Accelerometer();
         * accelerometer.addEventListener(AccelerometerEvent.UPDATE, accUpdateHandler);
         * stage.addEventListener(Event.ENTER_FRAME, enterFrameHandler);
         * }
         * }
         *
         *   private final function createBall():void
         * {
         * ball = new Sprite();
         * ball.graphics.beginFill(0xFF0000);
         * ball.graphics.drawCircle(0, 0, RADIUS);
         * ball.cacheAsBitmap = true;
         * ball.x = stage.stageWidth / 2;
         * ball.y = stage.stageHeight / 2;
         * addChild(ball);
         * }
         *
         *   private final function enterFrameHandler(event:Event):void
         * {
         * event.stopPropagation();
         * moveBall();
         * }
         * private final function moveBall():void
         * {
         * var newX:Number = ball.x + xSpeed;
         * var newY:Number = ball.y + ySpeed;
         * if (newX &lt; 20)
         * {
         * ball.x = RADIUS;
         * xSpeed = 0;
         * }
         * else if (newX &gt; stage.stageWidth - RADIUS)
         * {
         * ball.x = stage.stageWidth - RADIUS;
         * xSpeed = 0;
         * }
         * else
         * {
         * ball.x += xSpeed;
         * }
         *
         *   if (newY &lt; RADIUS)
         * {
         * ball.y = RADIUS;
         * ySpeed = 0;
         * }
         * else if (newY &gt; stage.stageHeight - RADIUS)
         * {
         * ball.y = stage.stageHeight - RADIUS;
         * ySpeed = 0;
         * }
         * else
         * {
         * ball.y += ySpeed;
         * }
         * }
         *
         *   private final function accUpdateHandler(event:AccelerometerEvent):void
         * {
         * xSpeed -= event.accelerationX * 2;
         * ySpeed += event.accelerationY * 2;
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   AIR 2
         * @playerversion   Flash 10.1
         * @playerversion   Lite 4
         */
        class Accelerometer : public flash::events::EventDispatcher
        {
            /**
             * The isSupported property is set to true if the accelerometer sensor is
             * available on the device, otherwise it is set to false.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Flash 10.1
             * @playerversion   Lite 4
             */
        public:
            static bool      isSupported();

            /**
             * Specifies whether the user has denied access to the accelerometer (true)
             * or allowed access (false). When this value changes,
             * a status event is dispatched.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Flash 10.1
             */
        public:
            bool      muted();

            /**
             * Creates a new Accelerometer instance.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Flash 10.1
             * @playerversion   Lite 4
             */
        public:
            Accelerometer();

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
        public:
            void     setRequestedUpdateInterval(float interval);
        };
    }
}

#endif // FLEX11_6_FLASH_SENSORS_ACCELEROMETER_AS
#endif // __cplusplus

