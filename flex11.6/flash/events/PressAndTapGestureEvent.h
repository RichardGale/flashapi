#if !defined(FLEX11_6_FLASH_EVENTS_PRESSANDTAPGESTUREEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_PRESSANDTAPGESTUREEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace events
    {
        class Event;
    }
}

/// @eventType  flash.events.PressAndTapGestureEvent.GESTURE_PRESS_AND_TAP
//[Event(name="gesturePressAndTap",type="flash.events.PressAndTapGestureEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /**
         * The PressAndTapGestureEvent class lets you handle press-and-tap gesture on touch-enabled devices.
         * Objects that inherit properties from the InteractiveObject class capture the primary touch point
         * (press) and a secondary point (tap) in the dispatched event object.
         * The press-and-tap gesture is typically used to raise a context-sensitive popup menu.
         *
         *   EXAMPLE:
         *
         *   The following example shows event handling for the <codeph class="+ topic/ph pr-d/codeph ">GESTURE_PRESS_AND_TAP</codeph> event.
         * While the user performs a press-and-tap gesture, mySprite rotates and myTextField populates with the current phase.
         * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * Multitouch.inputMode = MultitouchInputMode.GESTURE;
         *
         *   var mySprite = new Sprite();
         * mySprite.addEventListener(PressAndTapGestureEvent.GESTURE_PRESS_AND_TAP , onPressAndTap );
         * mySprite.graphics.beginFill(0x336699);
         * mySprite.graphics.drawRect(0, 0, 100, 80);
         * var myTextField = new TextField();
         * myTextField.y = 200;
         * addChild(mySprite);
         * addChild(myTextField);
         *
         *   function onPressAndTap(evt:PressAndTapGestureEvent):void {
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
        class PressAndTapGestureEvent : public GestureEvent
        {
            /**
             * Defines the value of the type property of a GESTURE_PRESS_AND_TAP touch event object.
             *
             *   The dispatched PressAndTapGestureEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.eventPhaseThe current phase as the event passes through the object hierarchy; a numeric value indicating the event is captured (1), at the target (2), or bubbling (3).localXThe horizontal coordinate at which the event occurred relative to the containing display object.localYThe vertical coordinate at which the event occurred relative to the containing display object.phaseThe current phase in the event flow; a value from the GesturePhase class.Possible values are:
             * GesturePhase.BEGIN, GesturePhase.UPDATE, GesturePhase.END, or GesturePhase.ALL.
             * A press-and-tap gesture either generates a GesturePhase.BEGIN, GesturePhase.UPDATE, GesturePhase.END sequence
             * or the gesture generates a single GesturePhase.ALL phase.shiftKeytrue if the Shift key is active; false if it is inactive.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.tapLocalXThe horizontal coordinate at which the event occurred relative to the containing interactive object.tapLocalYThe vertical coordinate at which the event occurred relative to the containing interactive object.tapStageXThe horizontal coordinate at which the tap touch occurred in global Stage coordinates.tapStageYThe vertical coordinate at which the tap touch occurred in global Stage coordinates.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string GESTURE_PRESS_AND_TAP;

            /**
             * The horizontal coordinate at which the event occurred relative to the containing interactive object.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       tapLocalX();
        public:
            void         tapLocalX(float value);

            /**
             * The vertical coordinate at which the event occurred relative to the containing interactive object.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       tapLocalY();
        public:
            void         tapLocalY(float value);

            /**
             * The horizontal coordinate at which the tap touch occurred in global Stage coordinates.
             * This property is calculated when the tapLocalX property is set.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       tapStageX();

            /**
             * The vertical coordinate at which the tap touch occurred in global Stage coordinates.
             * This property is calculated when the tapLocalX property is set.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float       tapStageY();

            /**
             * Creates a copy of the PressAndTapGestureEvent object and sets the value of each property to match that of the original.
             * @return  A new PressAndTapGestureEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates an Event object that contains information about complex multi-touch events, such as
             * a user raising a context-sensitive popup menu.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event: PressAndTapGestureEvent.GESTURE_PRESS_AND_TAP.
             * @param   bubbles Determines whether the Event object participates in the bubbling phase of the event flow.
             * @param   cancelable  Determines whether the Event object can be canceled.
             * @param   phase   This values tracks the beginning, progress, and end of a touch gesture. Possible values are: GesturePhase.BEGIN,
             *   GesturePhase.END, GesturePhase.UPDATE, or GesturePhase.ALL.
             * @param   localX  The horizontal coordinate at which the event occurred relative to the containing display object.
             * @param   localY  The vertical coordinate at which the event occurred relative to the containing display object.
             * @param   tapLocalX   The horizontal coordinate at which the event occurred relative to the containing interactive object.
             * @param   tapLocalY   The vertical coordinate at which the event occurred relative to the containing interactive object.
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
            PressAndTapGestureEvent(std::string type, bool bubbles=true, bool cancelable=false, std::string phase="", float localX=0, float localY=0, float tapLocalX=0, float tapLocalY=0, bool ctrlKey=false, bool altKey=false, bool shiftKey=false);

            /**
             * Returns a string that contains all the properties of the PressAndTapGestureEvent object. The string is in the following format:
             * [PressAndTapGestureEvent type=value bubbles=value cancelable=value ... ]
             * @return  A string that contains all the properties of the PressAndTapGestureEvent object.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            std::string   toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_PRESSANDTAPGESTUREEVENT_AS
#endif // __cplusplus

