#if !defined(FLEX11_6_FLASH_EVENTS_TOUCHEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_TOUCHEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace display
    {
        class InteractiveObject;
    }
}
#include "flash/events/Event.h"

/// @eventType  flash.events.TouchEvent.TOUCH_BEGIN
//[Event(name="touchBegin",type="flash.events.TouchEvent")]

/// @eventType  flash.events.TouchEvent.TOUCH_END
//[Event(name="touchEnd",type="flash.events.TouchEvent")]

/// @eventType  flash.events.TouchEvent.TOUCH_MOVE
//[Event(name="touchMove",type="flash.events.TouchEvent")]

/// @eventType  flash.events.TouchEvent.TOUCH_OUT
//[Event(name="touchOut",type="flash.events.TouchEvent")]

/// @eventType  flash.events.TouchEvent.TOUCH_OVER
//[Event(name="touchOver",type="flash.events.TouchEvent")]

/// @eventType  flash.events.TouchEvent.TOUCH_ROLL_OUT
//[Event(name="touchRollOut",type="flash.events.TouchEvent")]

/// @eventType  flash.events.TouchEvent.TOUCH_ROLL_OVER
//[Event(name="touchRollOver",type="flash.events.TouchEvent")]


//[Event(name="touchTap",type="flash.events.TouchEvent")]

using namespace flash::display;
using namespace flash::events;

namespace flash
{
    namespace events
    {
        /// @eventType  flash.events.TouchEvent.TOUCH_TAP


        /**
         * The TouchEvent class lets you handle events on devices that detect user contact with
         * the device (such as a finger on a touch screen).
         * When a user interacts with a device such as a mobile phone or tablet with a touch screen, the user typically
         * touches the screen with his or her fingers or a pointing device. You can develop applications that respond to
         * basic touch events (such as a single finger tap) with the TouchEvent class. Create event listeners using the event types defined in this class.
         * For user interaction with multiple points of contact (such as several fingers moving across a touch screen at the same time) use
         * the related GestureEvent, PressAndTapGestureEvent, and TransformGestureEvent classes. And, use the properties and methods of these classes
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
         *   The following example shows event handling for the <codeph class="+ topic/ph pr-d/codeph ">TOUCH_BEGIN</codeph>, <codeph class="+ topic/ph pr-d/codeph ">TOUCH_MOVE</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">TOUCH_END</codeph> events.
         * While the point of contact moves across the screen (<codeph class="+ topic/ph pr-d/codeph ">onTouchMove</codeph>), the x-coordinate relative to the stage is traced to output.
         * For the <codeph class="+ topic/ph pr-d/codeph ">Sprite.startTouchDrag</codeph> parameters in the <codeph class="+ topic/ph pr-d/codeph ">onTouchBegin</codeph> function, the value for touchPointID is the value assigned to the event object.
         * The bounds parameter is the rectangle defining the boundaries of
         * the parent display object (bg is a display object containing MySprite).
         * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * Multitouch.inputMode = MultitouchInputMode.TOUCH_POINT;
         *
         *   MySprite.addEventListener(TouchEvent.TOUCH_BEGIN, onTouchBegin);
         * MySprite.addEventListener(TouchEvent.TOUCH_MOVE, onTouchMove);
         * MySprite.addEventListener(TouchEvent.TOUCH_END, onTouchEnd);
         *
         *   function onTouchBegin(eBegin:TouchEvent) {
         * eBegin.target.startTouchDrag(eBegin.touchPointID, false, bg.getRect(this));
         * trace("touch begin");
         *
         *   }
         *
         *   function onTouchMove(eMove:TouchEvent) {
         * trace(eMove.stageX);
         * }
         *
         *   function onTouchEnd(eEnd:TouchEvent) {
         * eEnd.target.stopTouchDrag(eEnd.touchPointID);
         * trace("touch end");
         * }
         * </codeblock>
         *
         *   EXAMPLE:
         *
         *   The following example shows how to handle touch events and touch event phases, as well as the <codeph class="+ topic/ph pr-d/codeph ">Multitouch.maxTouchPoints</codeph> and the
         * touch event object's <codeph class="+ topic/ph pr-d/codeph ">touchPointID</codeph> properties.
         * This example comes from Christian Cantrell, and is explained in more detail in his quickstart:
         * <xref href="http://www.adobe.com/devnet/flash/articles/multitouch_gestures.html" scope="external" class="- topic/xref ">Multi-touch and gesture support on the Flash Platform</xref>.
         * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package
         * {
         * import flash.display.Sprite;
         * import flash.events.TouchEvent;
         * import flash.text.AntiAliasType;
         * import flash.text.TextField;
         * import flash.text.TextFormat;
         * import flash.ui.Multitouch;
         * import flash.ui.MultitouchInputMode;
         *
         *   [SWF(width=320, height=460, frameRate=24, backgroundColor=0xEB7F00)]
         * public class TouchExample2 extends Sprite
         * {
         * private var dots:Object;
         * private var labels:Object;
         * private var labelFormat:TextFormat;
         * private var dotCount:uint;
         * private var dotsLeft:TextField;
         * private static const LABEL_SPACING:uint = 15;
         *
         *   public function TouchExample2()
         * {
         * super();
         *
         *   this.labelFormat = new TextFormat();
         * labelFormat.color = 0xACF0F2;
         * labelFormat.font = "Helvetica";
         * labelFormat.size = 11;
         *
         *   this.dotCount = 0;
         *
         *   this.dotsLeft = new TextField();
         * this.dotsLeft.width = 300;
         * this.dotsLeft.defaultTextFormat = this.labelFormat;
         * this.dotsLeft.x = 3;
         * this.dotsLeft.y = 0;
         * this.stage.addChild(this.dotsLeft);
         * this.updateDotsLeft();
         *
         *   this.dots = new Object();
         * this.labels = new Object();
         *
         *   Multitouch.inputMode = MultitouchInputMode.TOUCH_POINT;
         * this.stage.addEventListener(TouchEvent.TOUCH_BEGIN, onTouchBegin);
         * this.stage.addEventListener(TouchEvent.TOUCH_MOVE, onTouchMove);
         * this.stage.addEventListener(TouchEvent.TOUCH_END, onTouchEnd);
         * }
         *
         *   private function onTouchBegin(e:TouchEvent):void
         * {
         * if (this.dotCount == Multitouch.maxTouchPoints) return;
         * var dot:Sprite = this.getCircle();
         * dot.x = e.stageX;
         * dot.y = e.stageY;
         * this.stage.addChild(dot);
         * dot.startTouchDrag(e.touchPointID, true);
         * this.dots[e.touchPointID] = dot;
         *
         *   ++this.dotCount;
         *
         *   var label:TextField = this.getLabel(e.stageX + ", " + e.stageY);
         * label.x = 3;
         * label.y = this.dotCount * LABEL_SPACING;
         * this.stage.addChild(label);
         * this.labels[e.touchPointID] = label;
         *
         *   this.updateDotsLeft();
         * }
         *
         *   private function onTouchMove(e:TouchEvent):void
         * {
         * var label:TextField = this.labels[e.touchPointID];
         * label.text = (e.stageX + ", " + e.stageY);
         * }
         *
         *   private function onTouchEnd(e:TouchEvent):void
         * {
         * var dot:Sprite = this.dots[e.touchPointID];
         * var label:TextField = this.labels[e.touchPointID];
         *
         *   this.stage.removeChild(dot);
         * this.stage.removeChild(label);
         *
         *   delete this.dots[e.touchPointID];
         * delete this.labels[e.touchPointID];
         *
         *   --this.dotCount;
         *
         *   this.updateDotsLeft();
         * }
         *
         *   private function getCircle(circumference:uint = 40):Sprite
         * {
         * var circle:Sprite = new Sprite();
         * circle.graphics.beginFill(0x1695A3);
         * circle.graphics.drawCircle(0, 0, circumference);
         * return circle;
         * }
         *
         *   private function getLabel(initialText:String):TextField
         * {
         * var label:TextField = new TextField();
         * label.defaultTextFormat = this.labelFormat;
         * label.selectable = false;
         * label.antiAliasType = AntiAliasType.ADVANCED;
         * label.text = initialText;
         * return label;
         * }
         *
         *   private function updateDotsLeft():void
         * {
         * this.dotsLeft.text = "Touches Remaining: " + (Multitouch.maxTouchPoints - this.dotCount);
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        class TouchEvent : public flash::events::Event
        {
            /**
             * Defines the value of the type property of a TOUCH_BEGIN touch event object.
             *
             *   The dispatched TouchEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.eventPhaseThe current phase in the event flow.isRelatedObjectInaccessibletrue if the relatedObject property is set to null because of security sandbox rules.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.pressureA value between 0.0 and 1.0 indicating force of the contact with the device. If the device does not support detecting the pressure, the value is 1.0.relatedObjectA reference to a display list object related to the event.shiftKeytrue if the Shift key is active; false if it is inactive.sizeXWidth of the contact area.sizeYHeight of the contact area.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.touchPointIDA unique identification number (as an int) assigned to the touch point.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string TOUCH_BEGIN;

            /**
             * Defines the value of the type property of a TOUCH_END touch event object.
             *
             *   The dispatched TouchEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.eventPhaseThe current phase in the event flow.isRelatedObjectInaccessibletrue if the relatedObject property is set to null because of security sandbox rules.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.pressureA value between 0.0 and 1.0 indicating force of the contact with the device. If the device does not support detecting the pressure, the value is 1.0.relatedObjectA reference to a display list object related to the event.shiftKeytrue if the Shift key is active; false if it is inactive.sizeXWidth of the contact area.sizeYHeight of the contact area.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.touchPointIDA unique identification number (as an int) assigned to the touch point.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string TOUCH_END;

            /**
             * Defines the value of the type property of a TOUCH_MOVE touch event object.
             *
             *   The dispatched TouchEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.eventPhaseThe current phase in the event flow.isRelatedObjectInaccessibletrue if the relatedObject property is set to null because of security sandbox rules.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.pressureA value between 0.0 and 1.0 indicating force of the contact with the device. If the device does not support detecting the pressure, the value is 1.0.relatedObjectA reference to a display list object related to the event.shiftKeytrue if the Shift key is active; false if it is inactive.sizeXWidth of the contact area.sizeYHeight of the contact area.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.touchPointIDA unique identification number (as an int) assigned to the touch point.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string TOUCH_MOVE;

            /**
             * Defines the value of the type property of a TOUCH_OVER touch event object.
             *
             *   The dispatched TouchEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.eventPhaseThe current phase in the event flow.isRelatedObjectInaccessibletrue if the relatedObject property is set to null because of security sandbox rules.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.pressureA value between 0.0 and 1.0 indicating force of the contact with the device. If the device does not support detecting the pressure, the value is 1.0.relatedObjectA reference to a display list object related to the event.shiftKeytrue if the Shift key is active; false if it is inactive.sizeXWidth of the contact area.sizeYHeight of the contact area.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.touchPointIDA unique identification number (as an int) assigned to the touch point.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string TOUCH_OVER;

            /**
             * Defines the value of the type property of a TOUCH_OUT touch event object.
             *
             *   The dispatched TouchEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.eventPhaseThe current phase in the event flow.isRelatedObjectInaccessibletrue if the relatedObject property is set to null because of security sandbox rules.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.pressureA value between 0.0 and 1.0 indicating force of the contact with the device. If the device does not support detecting the pressure, the value is 1.0.relatedObjectA reference to a display list object related to the event.shiftKeytrue if the Shift key is active; false if it is inactive.sizeXWidth of the contact area.sizeYHeight of the contact area.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.touchPointIDA unique identification number (as an int) assigned to the touch point.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string TOUCH_OUT;

            /**
             * Defines the value of the type property of a TOUCH_ROLL_OVER touch event object.
             *
             *   The dispatched TouchEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.eventPhaseThe current phase in the event flow.isRelatedObjectInaccessibletrue if the relatedObject property is set to null because of security sandbox rules.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.pressureA value between 0.0 and 1.0 indicating force of the contact with the device. If the device does not support detecting the pressure, the value is 1.0.relatedObjectA reference to a display list object related to the event.shiftKeytrue if the Shift key is active; false if it is inactive.sizeXWidth of the contact area.sizeYHeight of the contact area.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.touchPointIDA unique identification number (as an int) assigned to the touch point.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string TOUCH_ROLL_OVER;

            /**
             * Defines the value of the type property of a TOUCH_ROLL_OUT touch event object.
             *
             *   The dispatched TouchEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.eventPhaseThe current phase in the event flow.isRelatedObjectInaccessibletrue if the relatedObject property is set to null because of security sandbox rules.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.pressureA value between 0.0 and 1.0 indicating force of the contact with the device. If the device does not support detecting the pressure, the value is 1.0.relatedObjectA reference to a display list object related to the event.shiftKeytrue if the Shift key is active; false if it is inactive.sizeXWidth of the contact area.sizeYHeight of the contact area.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.touchPointIDA unique identification number (as an int) assigned to the touch point.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string TOUCH_ROLL_OUT;

            /**
             * Defines the value of the type property of a TOUCH_TAP touch event object.
             *
             *   The dispatched TouchEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.eventPhaseThe current phase in the event flow.isRelatedObjectInaccessibletrue if the relatedObject property is set to null because of security sandbox rules.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.pressureA value between 0.0 and 1.0 indicating force of the contact with the device. If the device does not support detecting the pressure, the value is 1.0.relatedObjectA reference to a display list object related to the event.shiftKeytrue if the Shift key is active; false if it is inactive.sizeXWidth of the contact area.sizeYHeight of the contact area.stageXThe horizontal coordinate at which the event occurred in global stage coordinates.stageYThe vertical coordinate at which the event occurred in global stage coordinates.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.touchPointIDA unique identification number (as an int) assigned to the touch point.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string TOUCH_TAP;
        public:
            static const std::string PROXIMITY_BEGIN;
        public:
            static const std::string PROXIMITY_END;
        public:
            static const std::string PROXIMITY_MOVE;
        public:
            static const std::string PROXIMITY_OUT;
        public:
            static const std::string PROXIMITY_OVER;
        public:
            static const std::string PROXIMITY_ROLL_OUT;
        public:
            static const std::string PROXIMITY_ROLL_OVER;

            /**
             * The horizontal coordinate at which the event occurred relative to the containing sprite.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float        localX();
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
            float        localY();
        public:
            void         localY(float value);

            /**
             * A unique identification number (as an int) assigned to the touch point.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            int          touchPointID();
        public:
            void         touchPointID(int value);

            /**
             * Indicates whether the first point of contact is mapped to mouse events.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            bool         isPrimaryTouchPoint();
        public:
            void         isPrimaryTouchPoint(bool value);

            /**
             * Width of the contact area.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float        sizeX();
        public:
            void         sizeX(float value);

            /**
             * Height of the contact area.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float        sizeY();
        public:
            void         sizeY(float value);

            /**
             * A value between 0.0 and 1.0 indicating force of the contact with the device.
             * If the device does not support detecting the pressure, the value is 1.0.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float        pressure();
        public:
            void         pressure(float value);

            /**
             * A reference to a display list object that is related to the event. For example, when a touchOut event occurs,
             * relatedObject represents the display list object to which the pointing device now points.
             * This property applies to the touchOut, touchOver, touchRollOut, and touchRollOver events.
             * The value of this property can be null in two circumstances: if there is no related object,
             * or there is a related object, but it is in a security sandbox to which you don't have access.
             * Use the isRelatedObjectInaccessible() property to determine which of these reasons applies.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            flash::display::InteractiveObject *relatedObject();
        public:
            void         relatedObject(InteractiveObject *value);

            /**
             * On Windows or Linux, indicates whether the Ctrl key is active (true) or inactive (false).
             * On Macintosh, indicates whether either the Control key or the Command key is activated.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            bool         ctrlKey();
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
            bool         altKey();
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
            bool         shiftKey();
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
            float        stageX();

            /**
             * The vertical coordinate at which the event occurred in global Stage coordinates.
             * This property is calculated when the localY property is set.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float        stageY();

            /**
             * If true, the relatedObject property is set to null for
             * reasons related to security sandboxes.  If the nominal value of relatedObject is a reference to a
             * DisplayObject in another sandbox, relatedObject is set to
             * null unless there is permission in both directions across this sandbox boundary. Permission is
             * established by calling Security.allowDomain() from a SWF file, or by providing
             * a policy file from the server of an image file, and setting the LoaderContext.checkPolicyFile
             * property when loading the image.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            bool         isRelatedObjectInaccessible();
        public:
            void         isRelatedObjectInaccessible(bool value);

            /**
             * Creates a copy of the TouchEvent object and sets the value of each property to match that of the original.
             * @return  A new TouchEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Returns a string that contains all the properties of the TouchEvent object. The string is in the following format:
             * [TouchEvent type=value bubbles=value cancelable=value ... ]
             * @return  A string that contains all the properties of the TouchEvent object.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            std::string toString();

            /**
             * Creates an Event object that contains information about touch events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Possible values are: TouchEvent.TOUCH_BEGIN,
             *   TouchEvent.TOUCH_END, TouchEvent.TOUCH_MOVE,
             *   TouchEvent.TOUCH_OUT, TouchEvent.TOUCH_OVER,
             *   TouchEvent.TOUCH_ROLL_OUT, TouchEvent.TOUCH_ROLL_OVER,
             *   and TouchEvent.TOUCH_TAP.
             * @param   bubbles Determines whether the Event object participates in the bubbling phase of the event flow.
             * @param   cancelable  Determines whether the Event object can be canceled.
             * @param   touchPointID    A unique identification number (as an int) assigned to the touch point.
             * @param   isPrimaryTouchPoint Indicates whether the first point of contact is mapped to mouse events.
             * @param   localX  The horizontal coordinate at which the event occurred relative to the containing sprite.
             * @param   localY  The vertical coordinate at which the event occurred relative to the containing sprite.
             * @param   sizeX   Width of the contact area.
             * @param   sizeY   Height of the contact area.
             * @param   pressure    A value between 0.0 and 1.0 indicating force of the contact with the device.
             *   If the device does not support detecting the pressure, the value is 1.0.
             * @param   relatedObject   The complementary InteractiveObject instance that is affected by the event. For example, when a touchOut event occurs,
             *   relatedObject represents the display list object to which the pointing device now points.
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
            TouchEvent(std::string type, bool bubbles   =true, bool cancelable   =false, int touchPointID=0, bool isPrimaryTouchPoint   =false, float localX =Number::NaN, float localY =Number::NaN, float sizeX =Number::NaN, float sizeY =Number::NaN, float pressure =Number::NaN, InteractiveObject *relatedObject=NULL, bool ctrlKey   =false, bool altKey   =false, bool shiftKey   =false);

            /**
             * Instructs Flash Player or Adobe AIR to render after processing of this event completes, if the display list has been modified.
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

#endif // FLEX11_6_FLASH_EVENTS_TOUCHEVENT_AS
#endif // __cplusplus

