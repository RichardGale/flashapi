

#include "TouchEvent.h"
#include "flash/display/InteractiveObject.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.TouchEvent.TOUCH_BEGIN

using namespace flash::display;
using namespace flash::events;

namespace flash {
namespace events {


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
        const std::string TouchEvent::TOUCH_BEGIN   = "touchBegin";

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
        const std::string TouchEvent::TOUCH_END   = "touchEnd";

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
        const std::string TouchEvent::TOUCH_MOVE   = "touchMove";

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
        const std::string TouchEvent::TOUCH_OVER   = "touchOver";

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
        const std::string TouchEvent::TOUCH_OUT   = "touchOut";

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
        const std::string TouchEvent::TOUCH_ROLL_OVER   = "touchRollOver";

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
        const std::string TouchEvent::TOUCH_ROLL_OUT   = "touchRollOut";

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
        const std::string TouchEvent::TOUCH_TAP   = "touchTap";
        const std::string TouchEvent::PROXIMITY_BEGIN  ;
        const std::string TouchEvent::PROXIMITY_END  ;
        const std::string TouchEvent::PROXIMITY_MOVE  ;
        const std::string TouchEvent::PROXIMITY_OUT  ;
        const std::string TouchEvent::PROXIMITY_OVER  ;
        const std::string TouchEvent::PROXIMITY_ROLL_OUT  ;
        const std::string TouchEvent::PROXIMITY_ROLL_OVER  ;

        /**
         * The horizontal coordinate at which the event occurred relative to the containing sprite.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float TouchEvent::localX()         ;
        void TouchEvent::localX(float value)       ;

        /**
         * The vertical coordinate at which the event occurred relative to the containing sprite.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float TouchEvent::localY()         ;
        void TouchEvent::localY(float value)       ;

        /**
         * A unique identification number (as an int) assigned to the touch point.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        int TouchEvent::touchPointID()      ;
        void TouchEvent::touchPointID(int value)       ;

        /**
         * Indicates whether the first point of contact is mapped to mouse events.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        bool TouchEvent::isPrimaryTouchPoint()          ;
        void TouchEvent::isPrimaryTouchPoint(bool value)       ;

        /**
         * Width of the contact area.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float TouchEvent::sizeX()         ;
        void TouchEvent::sizeX(float value)       ;

        /**
         * Height of the contact area.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float TouchEvent::sizeY()         ;
        void TouchEvent::sizeY(float value)       ;

        /**
         * A value between 0.0 and 1.0 indicating force of the contact with the device. 
         * If the device does not support detecting the pressure, the value is 1.0.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float TouchEvent::pressure()         ;
        void TouchEvent::pressure(float value)       ;

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
        flash::display::InteractiveObject* TouchEvent::relatedObject()                                  ;
        void TouchEvent::relatedObject(InteractiveObject* value)       ;

        /**
         * On Windows or Linux, indicates whether the Ctrl key is active (true) or inactive (false).
         * On Macintosh, indicates whether either the Control key or the Command key is activated.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool TouchEvent::ctrlKey()          ;
        void TouchEvent::ctrlKey(bool value)       ;

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
        bool TouchEvent::altKey()          ;
        void TouchEvent::altKey(bool value)       ;

        /**
         * Indicates whether the Shift key is active (true) or inactive 
         * (false).
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool TouchEvent::shiftKey()          ;
        void TouchEvent::shiftKey(bool value)       ;

        /**
         * The horizontal coordinate at which the event occurred in global Stage coordinates.  
         * This property is calculated when the localX property is set.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float TouchEvent::stageX()         ;

        /**
         * The vertical coordinate at which the event occurred in global Stage coordinates. 
         * This property is calculated when the localY property is set.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float TouchEvent::stageY()         ;

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
        bool TouchEvent::isRelatedObjectInaccessible()          ;
        void TouchEvent::isRelatedObjectInaccessible(bool value)       ;

        /**
         * Creates a copy of the TouchEvent object and sets the value of each property to match that of the original.
         * @return  A new TouchEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        flash::events::Event* TouchEvent::clone()                     ;

        /**
         * Returns a string that contains all the properties of the TouchEvent object. The string is in the following format:
         * [TouchEvent type=value bubbles=value cancelable=value ... ]
         * @return  A string that contains all the properties of the TouchEvent object.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        std::string TouchEvent::toString()         ;

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
        TouchEvent::TouchEvent(std::string type, bool bubbles, bool cancelable, int touchPointID, bool isPrimaryTouchPoint, float localX, float localY, float sizeX, float sizeY, float pressure, InteractiveObject* relatedObject, bool ctrlKey, bool altKey, bool shiftKey);

        /**
         * Instructs Flash Player or Adobe AIR to render after processing of this event completes, if the display list has been modified.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        void TouchEvent::updateAfterEvent()       ;
}
}

