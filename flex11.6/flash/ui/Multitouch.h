#if !defined(FLEX11_6_FLASH_UI_MULTITOUCH_AS)
#define FLEX11_6_FLASH_UI_MULTITOUCH_AS
#if defined(__cplusplus)


/**
 * The Multitouch class manages and provides information about the current environment's support for handling
 * contact from user input devices, including contact that has two or more touch points (such as a user's fingers on a touch screen).
 * When a user interacts with a device such as a mobile phone or tablet with a touch screen, the user typically
 * touches the screen with his or her fingers or a pointing device. While there is a broad range of pointing devices,
 * such as a mouse or a stylus, many of these devices only have a single point of contact with an application. For pointing
 * devices with a single point of contact,
 * user interaction events can be handled as a mouse event, or using a basic set of touch events (called "touch point" events).
 * However, for pointing devices that have several
 * points of contact and perform complex movement, such as the human hand, Flash runtimes support an additional set of event handling API called gesture events. The API
 * for handling user interaction with these gesture events includes the following classes:
 * <p class="- topic/p "><ul class="- topic/ul "><li class="- topic/li ">flash.events.TouchEvent</li><li class="- topic/li ">flash.events.GestureEvent</li><li class="- topic/li ">flash.events.GesturePhase</li><li class="- topic/li ">flash.events.TransformGestureEvent</li><li class="- topic/li ">flash.events.PressAndTapGestureEvent</li></ul></p><p class="- topic/p ">Use the listed classes to write code that handles touch events. Use the Multitouch class to determine the
 * current environment's support for touch interaction, and to manage the support of touch interaction if
 * the current environment supports touch input.</p><p class="- topic/p ">You cannot create a Multitouch object directly from ActionScript code. If you call <codeph class="+ topic/ph pr-d/codeph ">new Multitouch()</codeph>, an exception is thrown.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> The Multitouch feature is not supported for SWF files embedded in HTML running on Mac OS.</p>
 *
 *   EXAMPLE:
 *
 *   The following example first checks to see if gesture events are supported
 * (if the machine doesn't support gesture events, the vector array <codeph class="+ topic/ph pr-d/codeph ">Multitouch.supportedGestures</codeph>
 * returns <codeph class="+ topic/ph pr-d/codeph ">null</codeph> and assigning <codeph class="+ topic/ph pr-d/codeph ">null</codeph> to the vector of strings causes a run-time error).
 * If gesture events are supported, the example displays the events from
 * the TransformGestureEvent class supported in the current environment:
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.ui.Multitouch;
 * import flash.ui.MultitouchInputMode;
 * import flash.display.Sprite;
 * import flash.text.TextField;
 *
 *   public class MultitouchExample extends Sprite {
 *
 *   Multitouch.inputMode = MultitouchInputMode.GESTURE;
 *
 *   public function MultitouchExample() {
 *
 *   if(Multitouch.supportsGestureEvents){
 * var supportedGesturesVar:Vector.&lt;String&gt; = Multitouch.supportedGestures;
 * var deviceSupports:TextField = new TextField();
 * deviceSupports.width = 200;
 * deviceSupports.height = 200;
 * deviceSupports.wordWrap = true;
 *
 *   for (var i:int=0; i&lt;supportedGesturesVar.length; ++i) {
 * deviceSupports.appendText(supportedGesturesVar[i] + ",  ");
 * addChild(deviceSupports);
 * }
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



namespace flash
{
    namespace ui
    {
        class Multitouch : public Object
        {
            /**
             * Identifies the multi-touch mode for touch and gesture event handling. Use this property to manage
             * whether or not events are dispatched as touch events with multiple points of contact and specific events
             * for different gestures (such as rotation and pan), or only a single point of contact (such as tap), or
             * none at all (contact is handled as a mouse event). To set this property, use values from the flash.ui.MultitouchInputMode class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static std::string       inputMode();
        public:
            static void         inputMode(std::string value);

            /**
             * Indicates whether the current environment supports basic touch input, such as a single finger tap.
             * Touch events are listed in the TouchEvent class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static bool      supportsTouchEvents();

            /**
             * Indicates whether the current environment supports gesture input, such as rotating two fingers
             * around a touch screen. Gesture events are listed in the TransformGestureEvent, PressAndTapGestureEvent, and GestureEvent classes.
             * Note:  For Mac OS 10.5.3 and later, this value is always true. Multitouch.supportsGestureEvent returns
             * true even if the hardware does not support gesture events.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static bool      supportsGestureEvents();

            /**
             * A Vector array (a typed array of string values) of multi-touch contact types supported in the current environment. The array of strings
             * can be used as event types to register event listeners. Possible values are constants from the GestureEvent, PressAndTapGestureEvent, and
             * TransformGestureEvent classes (such as GESTURE_PAN).
             * If the Flash runtime is in an environment that does not support any multi-touch gestures, the value is null.Note: For Mac OS 10.5.3 and later, Multitouch.supportedGestures returns
             * non-null values (possibly indicating incorrectly that gesture events are supported) even if the current hardware does not support gesture input.Use this property to test for multi-touch gesture support. Then, use event handlers for the available multi-touch
             * gestures. For those gestures that are not supported in the current evironment, you'll need to create alternative
             * event handling.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static std::vector<std::string> supportedGestures();

            /**
             * The maximum number of concurrent touch points supported by the current environment.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static int          maxTouchPoints();

        public:
            static bool      mapTouchToMouse();
        public:
            static void         mapTouchToMouse(bool value);

        public:
            Multitouch();
        };
    }
}

#endif // FLEX11_6_FLASH_UI_MULTITOUCH_AS
#endif // __cplusplus

