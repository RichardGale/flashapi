#if !defined(FLEX11_6_FLASH_EVENTS_GESTUREPHASE_AS)
#define FLEX11_6_FLASH_EVENTS_GESTUREPHASE_AS
#if defined(__cplusplus)


/**
 * The GesturePhase class is an enumeration class of constant values for use with the GestureEvent, PressAndTapGestureEvent, and TransformGestureEvent
 * classes. Use these values to track the beginning, progress, and end of a touch gesture (such as moving several fingers across
 * a touch enabled screen) so your application can respond to individual stages of user contact. Some gestures (swipe and two-finger tap gestures)
 * do not have multiple phases, and set the event object <codeph class="+ topic/ph pr-d/codeph ">phase</codeph> property to <codeph class="+ topic/ph pr-d/codeph ">all</codeph>.
 *
 *   EXAMPLE:
 *
 *   The following example shows event handling for the <codeph class="+ topic/ph pr-d/codeph ">GESTURE_ROTATE</codeph> events.
 * While the user performs a rotation gesture on the touch-enabled device, mySprite rotates and myTextField populates with the current phase.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * Multitouch.inputMode = MultitouchInputMode.GESTURE;
 *
 *   var mySprite = new Sprite();
 * mySprite.addEventListener(TransformGestureEvent.GESTURE_ROTATE , onRotate );
 * mySprite.graphics.beginFill(0x336699);
 * mySprite.graphics.drawRect(0, 0, 100, 80);
 * var myTextField = new TextField();
 * myTextField.y = 200;
 * addChild(mySprite);
 * addChild(myTextField);
 *
 *   function onRotate(evt:TransformGestureEvent):void {
 *
 *   evt.target.rotation -= 45;
 *
 *   if (evt.phase==GesturePhase.BEGIN) {
 * myTextField.text = "Begin";
 * }
 * if (evt.phase==GesturePhase.UPDATE) {
 * myTextField.text = "Update";
 * }
 * if (evt.phase==GesturePhase.END) {
 * myTextField.text = "End";
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace events
    {
        class GesturePhase : public Object
        {
            /**
             * The beginning of a new gesture (such as touching a finger to a touch enabled screen).
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string BEGIN;

            /**
             * The progress of a gesture (such as moving a finger across a touch enabled screen).
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string UPDATE;

            /**
             * The completion of a gesture (such as lifting a finger off a touch enabled screen).
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string END;

            /**
             * A single value that encompasses all phases of simple gestures like two-finger-tap or swipe.
             * For gestures that set the event object phase property to all (swipe and two-finger tap gestures),
             * the phase value is always all once the event is dispatched.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string ALL;

        public:
            GesturePhase();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_GESTUREPHASE_AS
#endif // __cplusplus

