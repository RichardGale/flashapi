#if !defined(FLEX11_6_FLASH_EVENTS_TRANSFORMGESTUREEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_TRANSFORMGESTUREEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace events
    {
        class Event;
    }
}

/// @eventType  flash.events.TransformGestureEvent.GESTURE_PAN
//[Event(name="gesturePan",type="flash.events.TransformGestureEvent")]

/// @eventType  flash.events.TransformGestureEvent.GESTURE_ROTATE
//[Event(name="gestureRotate",type="flash.events.TransformGestureEvent")]

/// @eventType  flash.events.TransformGestureEvent.GESTURE_SWIPE
//[Event(name="gestureSwipe",type="flash.events.TransformGestureEvent")]


//[Event(name="gestureZoom",type="flash.events.TransformGestureEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /// @eventType  flash.events.TransformGestureEvent.GESTURE_ZOOM


        /**
         * The TransformGestureEvent class lets you handle complex movement input events (such as moving fingers across a touch screen)
         * that the device or operating system interprets as a gesture. A gesture can have one or more touch points.
         * When a user interacts with a device such as a mobile phone or tablet with a touch screen, the user typically
         * touches and moves across the screen with his or her fingers or a pointing device. You can develop applications that respond to
         * this user interaction with the GestureEvent, PressAndTapGestureEvent, and TransformGestureEvent classes. Create event listeners using the event types defined here, or in
         * the related GestureEvent and TouchEvent classes. And, use the properties and methods of these classes
         * to construct event handlers that respond to the user touching the device.
         * <p class="- topic/p ">A device or operating system interprets gesture input. So, different devices or operating systems have different requirements for
         * individual gesture types. A swipe on one device might require different input movement than a swipe on another device. Refer to the hardware
         * or operating system documentation to discover how the device or operating system interprets contact as a specific gesture.</p><p class="- topic/p ">Use the Multitouch class to determine the current environment's support for touch interaction, and to
         * manage the support of touch interaction if the current environment supports it.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> When objects are nested on the display list, touch events target the deepest possible
         * nested object that is visible in the display list. This object is called the target node. To have a target node's
         * ancestor (an object containing the target node in the display list) receive notification of a touch event, use
         * <codeph class="+ topic/ph pr-d/codeph ">EventDispatcher.addEventListener()</codeph> on the ancestor node with the type parameter set to the specific
         * touch event you want to detect.</p><p class="- topic/p ">While the user is in contact with the device, the TransformGestureEvent object's scale, rotation, and offset properties are incremental values
         * from the previous gesture event. For example, as a gesture increases the size of a display object, the scale values might go in sequence <codeph class="+ topic/ph pr-d/codeph ">1.03</codeph>,
         * <codeph class="+ topic/ph pr-d/codeph ">1.01</codeph>, <codeph class="+ topic/ph pr-d/codeph ">1.01</codeph>, <codeph class="+ topic/ph pr-d/codeph ">1.02</codeph> indicating the display object scaled 1.0717 times its original size by the end of the gesture.</p><p class="- topic/p ">For TransformGestureEvent objects, properties not modified by the current gesture are set to identity values. For example, a pan gesture does not have a rotation
         * or scale transformation, so the <codeph class="+ topic/ph pr-d/codeph ">rotation</codeph> value of the event object is <codeph class="+ topic/ph pr-d/codeph ">0</codeph>, the <codeph class="+ topic/ph pr-d/codeph ">scaleX</codeph> and <codeph class="+ topic/ph pr-d/codeph ">scaleY</codeph> properties are <codeph class="+ topic/ph pr-d/codeph ">1</codeph>.</p>
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
         *
         *   EXAMPLE:
         *
         *   The following example shows how to handle transform gesture events. This example assumes an image is on your local system
         * called "african_elephant.jpg" and in the same directory as the TransformGestureExample2 class.
         * This example comes from Christian Cantrell, and is explained in more detail in his quickstart:
         * <xref href="http://www.adobe.com/devnet/flash/articles/multitouch_gestures.html" scope="external" class="- topic/xref ">Multi-touch and gesture support on the Flash Platform</xref>.
         * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package
         * {
         * import flash.display.Bitmap;
         * import flash.display.Sprite;
         * import flash.events.TransformGestureEvent;
         * import flash.text.TextField;
         * import flash.text.TextFormat;
         * import flash.ui.Multitouch;
         * import flash.ui.MultitouchInputMode;
         *
         *   [SWF(width=320, height=460, frameRate=24, backgroundColor=0x000000)]
         * public class TransformGestureExample2 extends Sprite
         * {
         * [Embed(source="african_elephant.jpg")]
         * public var ElephantImage:Class;
         * public var scaleDebug:TextField;
         * public var rotateDebug:TextField;
         *
         *   public function TransformGestureExample2()
         * {
         * // Debug
         * var tf:TextFormat = new TextFormat();
         * tf.color = 0xffffff;
         * tf.font = "Helvetica";
         * tf.size = 11;
         * this.scaleDebug = new TextField();
         * this.scaleDebug.width = 310;
         * this.scaleDebug.defaultTextFormat = tf;
         * this.scaleDebug.x = 2;
         * this.scaleDebug.y = 2;
         * this.stage.addChild(this.scaleDebug);
         * this.rotateDebug = new TextField();
         * this.rotateDebug.width = 310;
         * this.rotateDebug.defaultTextFormat = tf;
         * this.rotateDebug.x = 2;
         * this.rotateDebug.y = 15;
         * this.stage.addChild(this.rotateDebug);
         *
         *   var elephantBitmap:Bitmap = new ElephantImage();
         * var elephant:Sprite = new Sprite();
         *
         *   elephant.addChild(elephantBitmap);
         *
         *   elephant.x = 160;
         * elephant.y = 230;
         *
         *   elephantBitmap.x = (300 - (elephantBitmap.bitmapData.width / 2)) * -1;
         * elephantBitmap.y = (400 - (elephantBitmap.bitmapData.height / 2)) *-1;
         *
         *   this.addChild(elephant);
         *
         *   Multitouch.inputMode = MultitouchInputMode.GESTURE;
         * elephant.addEventListener(TransformGestureEvent.GESTURE_ZOOM, onZoom);
         * elephant.addEventListener(TransformGestureEvent.GESTURE_ROTATE, onRotate);
         * }
         *
         *   private function onZoom(e:TransformGestureEvent):void
         * {
         * this.scaleDebug.text = (e.scaleX + ", " + e.scaleY);
         * var elephant:Sprite = e.target as Sprite;
         * elephant.scaleX *= e.scaleX;
         * elephant.scaleY *= e.scaleY;
         * }
         *
         *   private function onRotate(e:TransformGestureEvent):void
         * {
         * var elephant:Sprite = e.target as Sprite;
         * this.rotateDebug.text = String(e.rotation);
         * elephant.rotation += e.rotation;
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        class TransformGestureEvent : public GestureEvent
        {
            /**
             * Defines the value of the type property of a GESTURE_ZOOM touch event object.
             *
             *   The dispatched TransformGestureEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.phaseThe current phase in the event flow; a value from the GesturePhase class.localXThe horizontal coordinate at which the event occurred relative to the containing display object.localYThe vertical coordinate at which the event occurred relative to the containing display object.scaleXThe horizontal scale of the display object since the previous gesture event.scaleYThe vertical scale of the display object since the previous gesture event.rotationThe current rotation angle, in degrees, of the display object along the z-axis, since the previous gesture event.offsetXThe horizontal translation of the display object from its position at the previous gesture event.offsetYThe vertical translation of the display object from its position at the previous gesture event.shiftKeytrue if the Shift key is active; false if it is inactive.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string GESTURE_ZOOM;

            /**
             * Defines the value of the type property of a GESTURE_PAN touch event object.
             *
             *   The dispatched TransformGestureEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.phaseThe current phase in the event flow; a value from the GesturePhase class.localXThe horizontal coordinate at which the event occurred relative to the containing display object.localYThe vertical coordinate at which the event occurred relative to the containing display object.scaleXThe horizontal scale of the display object since the previous gesture event. For pan gestures this value is 1.scaleYThe vertical scale of the display object since the previous gesture event. For pan gestures this value is 1.rotationThe current rotation angle, in degrees, of the display object along the z-axis, since the previous gesture event.
             * For pan gestures this value is 0.offsetXThe horizontal translation of the display object from its position at the previous gesture event.offsetYThe vertical translation of the display object from its position at the previous gesture event.shiftKeytrue if the Shift key is active; false if it is inactive.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string GESTURE_PAN;

            /**
             * Defines the value of the type property of a GESTURE_ROTATE touch event object.
             *
             *   The dispatched TransformGestureEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.phaseThe current phase in the event flow; a value from the GesturePhase class.localXThe horizontal coordinate at which the event occurred relative to the containing display object.localYThe vertical coordinate at which the event occurred relative to the containing display object.scaleXThe horizontal scale of the display object since the previous gesture event.scaleYThe vertical scale of the display object since the previous gesture event.rotationThe current rotation angle, in degrees, of the display object along the z-axis, since the previous gesture event.offsetXThe horizontal translation of the display object from its position at the previous gesture event.offsetYThe vertical translation of the display object from its position at the previous gesture event.shiftKeytrue if the Shift key is active; false if it is inactive.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string GESTURE_ROTATE;

            /**
             * Defines the value of the type property of a GESTURE_SWIPE touch event object.
             *
             *   The dispatched TransformGestureEvent object has the following properties:PropertyValuealtKeytrue if the Alt key is active (Windows or Linux).bubblestruecancelablefalse; there is no default behavior to cancel.commandKeytrue on the Mac if the Command key is active; false if it is inactive. Always false on Windows.controlKeytrue if the Ctrl or Control key is active; false if it is inactive.ctrlKeytrue on Windows or Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event
             * object with an event listener.phaseThe current phase in the event flow. For swipe events,
             * this value is always all corresponding to the value GesturePhase.ALL once the event is dispatched.localXThe horizontal coordinate at which the event occurred relative to the containing sprite.localYThe vertical coordinate at which the event occurred relative to the containing sprite.scaleXThe horizontal scale of the display object. For swipe gestures this value is 1scaleYThe vertical scale of the display object. For swipe gestures this value is 1rotationThe current rotation angle, in degrees, of the display object along the z-axis.  For swipe gestures this value is 0offsetXIndicates horizontal direction: 1 for right and -1 for left.offsetYIndicates vertical direction: 1 for down and -1 for up.shiftKeytrue if the Shift key is active; false if it is inactive.targetThe InteractiveObject instance under the touching device.
             * The target is not always the object in the display list
             * that registered the event listener. Use the currentTarget
             * property to access the object in the display list that is currently processing the event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            static const std::string GESTURE_SWIPE;

            /**
             * The horizontal scale of the display object, since the previous gesture event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float        scaleX();
        public:
            void         scaleX(float value);

            /**
             * The vertical scale of the display object, since the previous gesture event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float        scaleY();
        public:
            void         scaleY(float value);

            /**
             * The current rotation angle, in degrees, of the display object along the z-axis, since the previous gesture event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float        rotation();
        public:
            void         rotation(float value);

            /**
             * The horizontal translation of the display object, since the previous gesture event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float        offsetX();
        public:
            void         offsetX(float value);

            /**
             * The vertical translation of the display object, since the previous gesture event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            float        offsetY();
        public:
            void         offsetY(float value);

            /**
             * Creates a copy of the TransformGestureEvent object and sets the value of each property to match that of the original.
             * @return  A new TransformGestureEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Returns a string that contains all the properties of the TransformGestureEvent object. The string is in the following format:
             * [TransformGestureEvent type=value bubbles=value cancelable=value ... ]
             * @return  A string that contains all the properties of the TransformGestureEvent object.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @playerversion   Lite 4
             */
        public:
            std::string toString();

            /**
             * Creates an Event object that contains information about complex multi-touch events, such as
             * a user sliding his or her finger across a screen.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Possible values are: TransformGestureEvent.GESTURE_PAN,
             *   TransformGestureEvent.GESTURE_ROTATE, TransformGestureEvent.GESTURE_SWIPE and TransformGestureEvent.GESTURE_ZOOM.
             * @param   bubbles Determines whether the Event object participates in the bubbling phase of the event flow.
             * @param   cancelable  Determines whether the Event object can be canceled.
             * @param   phase   This values tracks the beginning, progress, and end of a touch gesture. Possible values are: GesturePhase.BEGIN,
             *   GesturePhase.END, and GesturePhase.UPDATE.
             * @param   localX  The horizontal coordinate at which the event occurred relative to the containing display object.
             * @param   localY  The vertical coordinate at which the event occurred relative to the containing display object.
             * @param   scaleX  The horizontal scale of the display object.
             * @param   scaleY  The vertical scale of the display object.
             * @param   rotation    The current rotation angle, in degrees, of the display object along the z-axis.
             * @param   offsetX The horizontal translation of the display object from its original position.
             * @param   offsetY The vertical translation of the display object from its original position.
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
            TransformGestureEvent(std::string type, bool bubbles   =true, bool cancelable   =false, std::string phase="", float localX =0, float localY =0, float scaleX =1, float scaleY =1, float rotation =0, float offsetX =0, float offsetY =0, bool ctrlKey   =false, bool altKey   =false, bool shiftKey   =false);
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_TRANSFORMGESTUREEVENT_AS
#endif // __cplusplus

