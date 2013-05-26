#if !defined(FLEX11_6_FLASH_EVENTS_GESTUREEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_GESTUREEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/Event.h"

/// @eventType  flash.events.GestureEvent.GESTURE_TWO_FINGER_TAP
//[Event(name="gestureTwoFingerTap",type="flash.events.GestureEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /**
         * The GestureEvent class lets you handle multi-touch events on devices that detect complex user contact with
         * the device (such as pressing two fingers on a touch screen at the same time).
         * When a user interacts with a device such as a mobile phone or tablet with a touch screen, the user typically
         * touches and moves across the screen with his or her fingers or a pointing device. You can develop applications that respond to
         * this user interaction with the GestureEvent and TransformGestureEvent classes. Create event listeners using the event types defined here, or in
         * the related TouchEvent and TransformGestureEvent classes. And, use the properties and methods of these classes
         * to construct event handlers that respond to the user touching the device.
         * <p class="- topic/p ">Use the Multitouch class to determine the current environment's support for touch interaction, and to
         * manage the support of touch interaction if the current environment supports it.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> When objects are nested on the display list, touch events target the deepest possible
         * nested object that is visible in the display list. This object is called the target node. To have a target node's
         * ancestor (an object containing the target node in the display list) receive notification of a touch event, use
         * <codeph class="+ topic/ph pr-d/codeph ">EventDispatcher.addEventListener()</codeph> on the ancestor node with the type parameter set to the specific
         * touch event you want to detect.</p>
         *
         *   EXAMPLE:
         *
         *   The following example shows event handling for the <codeph class="+ topic/ph pr-d/codeph ">GESTURE_TWO_FINGER_TAP</codeph> event.
         * While the user performs a two-finger tap gesture, mySprite rotates and myTextField populates with the phase <codeph class="+ topic/ph pr-d/codeph ">all</codeph>,
         * which is the only phase for two-finger tap events. Other gestures from the TransformGestureEvent class support begin, update,
         * and end phases.
         * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * Multitouch.inputMode = MultitouchInputMode.GESTURE;
         *
         *   var mySprite = new Sprite();
         * mySprite.addEventListener(GestureEvent.GESTURE_TWO_FINGER_TAP , onTwoFingerTap );
         * mySprite.graphics.beginFill(0x336699);
         * mySprite.graphics.drawRect(0, 0, 100, 80);
         * var myTextField = new TextField();
         * myTextField.y = 200;
         * addChild(mySprite);
         * addChild(myTextField);
         *
         *   function onTwoFingerTap(evt:GestureEvent):void {
         *
         *   evt.target.rotation -= 45;
         * myTextField.text = evt.phase; //"all"
         *
         *   }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        class GestureEvent : public flash::events::Event
        {
            /**
             * Defines the value of the type property of a GESTURE_TWO_FINGER_TAP gesture event object.
             *
             *   The dispatched GestureEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKey(AIR only) true on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.phaseThe current phase in the event flow. For two-finger tap events,
             * this value is always all corresponding to the value GesturePhase.ALL once the event is dispatched.isRelatedObjectInaccessibletrue if the relatedObject property is set to null because of security sandbox rules.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.shiftKeytrue if the Shift key is active; false if it is inactive.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string GESTURE_TWO_FINGER_TAP;

            /**
             * The horizontal coordinate at which the event occurred relative to the containing sprite.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       localX();
        public:
            void         localX(float value);

            /**
             * The vertical coordinate at which the event occurred relative to the containing sprite.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       localY();
        public:
            void         localY(float value);

            /**
             * A value from the GesturePhase class indicating the progress of the touch gesture. For most gestures,
             * the value is begin, update, or end. For the swipe and two-finger tap gestures,
             * the phase value is always all once the event is dispatched.
             * Use this value to determine when an event handler responds to a complex user interaction, or responds in
             * different ways depending on the current phase of a multi-touch gesture (such as expanding, moving, and "dropping" as
             * a user touches and drags a visual object across a screen).
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            std::string       phase();
        public:
            void         phase(std::string value);

            /**
             * On Windows or Linux, indicates whether the Ctrl key is active (true) or inactive (false).
             * On Macintosh, indicates whether either the Control key or the Command key is activated.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            bool      ctrlKey();
        public:
            void         ctrlKey(bool value);

            /**
             * Indicates whether the Alt key is active (true) or inactive (false).
             * Supported for Windows and Linux operating systems only.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @internal    Reserved in case Desktop Player wants to capture this key in a future implementation.
             *   The Option key modifier on Macintosh system must be represented using this key modifier. So far, it seems
             *   only the Windows version is hooked up.
             */
        public:
            bool      altKey();
        public:
            void         altKey(bool value);

            /**
             * Indicates whether the Shift key is active (true) or inactive
             * (false).
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            bool      shiftKey();
        public:
            void         shiftKey(bool value);

            /**
             * The horizontal coordinate at which the event occurred in global Stage coordinates.
             * This property is calculated when the localX property is set.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       stageX();

            /**
             * The vertical coordinate at which the event occurred in global Stage coordinates.
             * This property is calculated when the localY property is set.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       stageY();

            /**
             * Creates a copy of the GestureEvent object and sets the value of each property to match that of the original.
             * @return  A new GestureEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates an Event object that contains information about multi-touch events
             * (such as pressing two fingers on a touch screen at the same time).
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. The supported value is: GestureEvent.GESTURE_TWO_FINGER_TAP.
             * @param   bubbles Determines whether the Event object participates in the bubbling phase of the event flow.
             * @param   cancelable  Determines whether the Event object can be canceled.
             * @param   phase   A value from the GesturePhase class indicating the progress of the touch gesture (begin, update, end, or all).
             * @param   localX  The horizontal coordinate at which the event occurred relative to the containing sprite.
             * @param   localY  The vertical coordinate at which the event occurred relative to the containing sprite.
             * @param   ctrlKey On Windows or Linux, indicates whether the Ctrl key is activated. On Mac, indicates whether either the Ctrl key or the Command key is activated.
             * @param   altKey  Indicates whether the Alt key is activated (Windows or Linux only).
             * @param   shiftKey    Indicates whether the Shift key is activated.
             * @param   commandKey  (AIR only) Indicates whether the Command key is activated (Mac only). This parameter is for Adobe AIR only; do not set it for Flash Player content.
             * @param   controlKey  (AIR only) Indicates whether the Control or Ctrl key is activated. This parameter is for Adobe AIR only; do not set it for Flash Player content.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            GestureEvent(std::string type, bool bubbles=true, bool cancelable=false, std::string phase="", float localX=0, float localY=0, bool ctrlKey=false, bool altKey=false, bool shiftKey=false);

            /**
             * Returns a string that contains all the properties of the GestureEvent object. The string is in the following format:
             * [GestureEvent type=value bubbles=value cancelable=value ... ]
             * @return  A string that contains all the properties of the GestureEvent object.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            std::string   toString();

            /**
             * Refreshes the Flash runtime display after processing the gesture event, in case the display list has been modified by the event handler.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            void     updateAfterEvent();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_GESTUREEVENT_AS
#endif // __cplusplus

