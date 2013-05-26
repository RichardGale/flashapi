

#include "GestureEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.GestureEvent.GESTURE_TWO_FINGER_TAP

using namespace flash::events;

namespace flash {
namespace events {


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
        const std::string GestureEvent::GESTURE_TWO_FINGER_TAP   = "gestureTwoFingerTap";

        /**
         * The horizontal coordinate at which the event occurred relative to the containing sprite.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float GestureEvent::localX()         ;
        void GestureEvent::localX(float value)       ;

        /**
         * The vertical coordinate at which the event occurred relative to the containing sprite.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float GestureEvent::localY()         ;
        void GestureEvent::localY(float value)       ;

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
        std::string GestureEvent::phase()         ;
        void GestureEvent::phase(std::string value)       ;

        /**
         * On Windows or Linux, indicates whether the Ctrl key is active (true) or inactive (false).
         * On Macintosh, indicates whether either the Control key or the Command key is activated.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool GestureEvent::ctrlKey()          ;
        void GestureEvent::ctrlKey(bool value)       ;

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
        bool GestureEvent::altKey()          ;
        void GestureEvent::altKey(bool value)       ;

        /**
         * Indicates whether the Shift key is active (true) or inactive 
         * (false).
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool GestureEvent::shiftKey()          ;
        void GestureEvent::shiftKey(bool value)       ;

        /**
         * The horizontal coordinate at which the event occurred in global Stage coordinates.  
         * This property is calculated when the localX property is set.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float GestureEvent::stageX()         ;

        /**
         * The vertical coordinate at which the event occurred in global Stage coordinates. 
         * This property is calculated when the localY property is set.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        float GestureEvent::stageY()         ;

        /**
         * Creates a copy of the GestureEvent object and sets the value of each property to match that of the original.
         * @return  A new GestureEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        flash::events::Event* GestureEvent::clone()                     ;

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
        GestureEvent::GestureEvent(std::string type, bool bubbles, bool cancelable, std::string phase, float localX, float localY, bool ctrlKey, bool altKey, bool shiftKey);

        /**
         * Returns a string that contains all the properties of the GestureEvent object. The string is in the following format:
         * [GestureEvent type=value bubbles=value cancelable=value ... ]
         * @return  A string that contains all the properties of the GestureEvent object.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        std::string GestureEvent::toString()         ;

        /**
         * Refreshes the Flash runtime display after processing the gesture event, in case the display list has been modified by the event handler.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        void GestureEvent::updateAfterEvent()       ;
}
}

