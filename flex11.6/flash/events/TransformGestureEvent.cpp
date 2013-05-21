

#include "TransformGestureEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.TransformGestureEvent.GESTURE_PAN

using namespace flash::events;

namespace flash {
namespace events {


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
        const std::string TransformGestureEvent::GESTURE_ZOOM="gestureZoom";

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
        const std::string TransformGestureEvent::GESTURE_PAN="gesturePan";

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
        const std::string TransformGestureEvent::GESTURE_ROTATE="gestureRotate";

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
        const std::string TransformGestureEvent::GESTURE_SWIPE="gestureSwipe";

        /**
         * The horizontal scale of the display object, since the previous gesture event.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float TransformGestureEvent::scaleX()         ;
        void TransformGestureEvent::scaleX(float value)       ;

        /**
         * The vertical scale of the display object, since the previous gesture event.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float TransformGestureEvent::scaleY()         ;
        void TransformGestureEvent::scaleY(float value)       ;

        /**
         * The current rotation angle, in degrees, of the display object along the z-axis, since the previous gesture event.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float TransformGestureEvent::rotation()         ;
        void TransformGestureEvent::rotation(float value)       ;

        /**
         * The horizontal translation of the display object, since the previous gesture event.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float TransformGestureEvent::offsetX()         ;
        void TransformGestureEvent::offsetX(float value)       ;

        /**
         * The vertical translation of the display object, since the previous gesture event.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float TransformGestureEvent::offsetY()         ;
        void TransformGestureEvent::offsetY(float value)       ;

        /**
         * Creates a copy of the TransformGestureEvent object and sets the value of each property to match that of the original.
         * @return  A new TransformGestureEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        flash::events::Event* TransformGestureEvent::clone()                     ;

        /**
         * Returns a string that contains all the properties of the TransformGestureEvent object. The string is in the following format:
         * [TransformGestureEvent type=value bubbles=value cancelable=value ... ]
         * @return  A string that contains all the properties of the TransformGestureEvent object.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        std::string TransformGestureEvent::toString()         ;

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
        TransformGestureEvent::TransformGestureEvent(std::string type, bool bubbles, bool cancelable, std::string phase, float localX, float localY, float scaleX, float scaleY, float rotation, float offsetX, float offsetY, bool ctrlKey, bool altKey, bool shiftKey);
}
}

