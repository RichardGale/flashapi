#if !defined(FLEX11_6_FLASH_UI_MULTITOUCHINPUTMODE_AS)
#define FLEX11_6_FLASH_UI_MULTITOUCHINPUTMODE_AS
#if defined(__cplusplus)


/**
 * The MultitouchInputMode class provides values for the <codeph class="+ topic/ph pr-d/codeph ">inputMode</codeph> property in the flash.ui.Multitouch class.
 * These values set the type of touch events the Flash runtime dispatches when the user interacts with a touch-enabled device.
 *
 *   EXAMPLE:
 *
 *   The following example displays a message when the
 * square drawn on mySprite is tapped on a touch-enabled screen:
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * Multitouch.inputMode=MultitouchInputMode.TOUCH_POINT;
 *
 *   var mySprite:Sprite = new Sprite();
 * var myTextField:TextField = new TextField();
 *
 *   mySprite.graphics.beginFill(0x336699);
 * mySprite.graphics.drawRect(0,0,40,40);
 * addChild(mySprite);
 *
 *   mySprite.addEventListener(TouchEvent.TOUCH_TAP, taphandler);
 *
 *   function taphandler(e:TouchEvent): void {
 * myTextField.text = "I've been tapped";
 * myTextField.y = 50;
 * addChild(myTextField);
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 * @playerversion   Lite 4
 */

namespace flash
{
    namespace ui
    {
        class MultitouchInputMode: public Object
        {
            /**
             * Specifies that all user contact with a touch-enabled device is interpreted as a type of mouse event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string NONE;

            /**
             * Specifies that TransformGestureEvent, PressAndTapGestureEvent, and GestureEvent events are dispatched for the related user interaction supported by the current environment,
             * and other touch events (such as a simple tap) are interpreted as mouse events.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string GESTURE;

            /**
             * Specifies that events are dispatched only for basic touch events, such as a single finger tap. When you use this setting,
             * events listed in the TouchEvent class are dispatched; events listed in the TransformGestureEvent, PressAndTapGestureEvent, and GestureEvent classes are not dispatched.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string TOUCH_POINT;

        public:
            MultitouchInputMode();
        };
    }
}

#endif // FLEX11_6_FLASH_UI_MULTITOUCHINPUTMODE_AS
#endif // __cplusplus

