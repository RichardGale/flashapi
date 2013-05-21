

#include "SoftKeyboardEvent.h"
#include "flash/events/Event.h"
#include "flash/display/InteractiveObject.h"

    /**
     * A SoftKeyboardEvent object is dispatched when a virtual keyboard is activated or deactivated.
     * 
     *   <p class="- topic/p ">SoftKeyboardEvents are dispatched by TextFields and by InteractiveObjects that have their 
     * <codeph class="+ topic/ph pr-d/codeph ">needsSoftKeyboard</codeph>property set to <codeph class="+ topic/ph pr-d/codeph ">true</codeph>.</p>
     * @langversion 3.0
     * @playerversion   Flash 10.2
     * @playerversion   AIR 2.6
     */

using namespace flash::display;
using namespace flash::events;

namespace flash {
namespace events {


        /**
         * The SoftKeyboardEvent.SOFT_KEYBOARD_ACTIVATE constant defines the value of the 
         * type property of the SoftKeyboardEvent object dispatched when a soft keyboard 
         * is displayed.
         * 
         *   The softKeyboardActivate event is dispatched after the softKeyboardActivating event and 
         * cannot be canceled. To prevent the virtual keyboard from displaying, cancel the softKeyboardActivating event.This event has the following properties:PropertyValuetypeSOFT_KEYBOARD_ACTIVATEbubblestruecancelablefalse; it is too late to cancel.relatedObjectValA reference to a display list object that is related to the event.triggerTypeValIndicates whether the keyboard event was triggered by an application or user.currentTargetThe object that is actively processing the Event 
         * object with an event listener.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        const std::string SoftKeyboardEvent::SOFT_KEYBOARD_ACTIVATE="softKeyboardActivate";

        /**
         * The SoftKeyboardEvent.SOFT_KEYBOARD_DEACTIVATE constant defines the value of the
         * type property of the SoftKeyboardEvent object dispatched when a soft keyboard 
         * is lowered or hidden..
         * 
         *   This event has the following properties:PropertyValuetypeSOFT_KEYBOARD_DEACTIVATEbubblestruecancelablefalse; canceling is not allowed.relatedObjectValA reference to a display list object that is related to the event.triggerTypeValIndicates whether the keyboard event was triggered by an application or user.currentTargetThe object that is actively processing the Event 
         * object with an event listener.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        const std::string SoftKeyboardEvent::SOFT_KEYBOARD_DEACTIVATE="softKeyboardDeactivate";

        /**
         * The SoftKeyboardEvent.SOFT_KEYBOARD_ACTIVATING constant defines the value of the 
         * type property of the SoftKeyboardEvent object dispatched immediately before a 
         * soft keyboard is displayed. If canceled by calling preventDefault,
         * the soft keyboard does not open.
         * 
         *   This event has the following properties:PropertyValuetypeSOFT_KEYBOARD_ACTIVATINGbubblestruecancelabletrue; canceling prevents the keyboard from opening.relatedObjectValA reference to a display list object that is related to the event.triggerTypeValIndicates whether the keyboard event was triggered by an application or user.currentTargetThe object that is actively processing the Event 
         * object with an event listener.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        const std::string SoftKeyboardEvent::SOFT_KEYBOARD_ACTIVATING="softKeyboardActivating";

        /**
         * Indicates whether the change in keyboard status has been triggered by
         * an application (such as programmatic use of requestSoftKeyboard()) or by the user
         * (such as selecting a text field).
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        std::string SoftKeyboardEvent::triggerType()         ;

        /**
         * A reference to a display list object that is related to the event.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        flash::display::InteractiveObject* SoftKeyboardEvent::relatedObject()                                  ;
        void SoftKeyboardEvent::relatedObject(InteractiveObject* value)       ;

        /**
         * Creates a copy of a SoftKeyboardEvent object and sets the value of each property to match that of 
         * the original.
         * @return  A new SoftKeyboardEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        flash::events::Event* SoftKeyboardEvent::clone()                     ;

        /**
         * Creates an event object that contains information about soft keyboard activation and deactivation events.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event as a constant value (such as SOFT_KEYBOARD_ACTIVATE).
         *   Event listeners can access this information through the 
         *   inherited type property.
         * @param   bubbles Determines whether the Event object participates in the bubbling phase of the 
         *   event flow. Event listeners can access this information through the inherited 
         *   bubbles property.
         * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can 
         *   access this information through the inherited cancelable property.
         * @param   relatedObjectVal    A reference to a display list object that is related to the event.
         * @param   triggerTypeVal  Indicates whether the keyboard event was triggered by an application or user.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        SoftKeyboardEvent::SoftKeyboardEvent(std::string type, bool bubbles, bool cancelable, InteractiveObject* relatedObjectVal, std::string triggerTypeVal);

        /**
         * Returns a string that contains all the properties of the SoftKeyboardEvent object. The following 
         * format is used:
         * [SoftKeyboardEvent type=value bubbles=value cancelable=value relatedObjectVal=value
         * triggerTypeVal=value activating=value]
         * @return  A string that contains all the properties of the SoftKeyboardEvent object.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR 2.6
         */
        std::string SoftKeyboardEvent::toString()         ;
}
}

