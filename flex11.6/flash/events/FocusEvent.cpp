

#include "FocusEvent.h"
#include "flash/display/InteractiveObject.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.FocusEvent.FOCUS_IN

using namespace flash::display;
using namespace flash::events;

namespace flash {
namespace events {


        /**
         * Defines the value of the type property of a focusIn event object. 
         * This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.keyCode0; applies only to keyFocusChange events.relatedObjectThe complementary InteractiveObject instance that is affected by the change in focus.shiftKeyfalse; applies only to keyFocusChange events.targetThe InteractiveObject instance that has just received focus. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * directionThe direction from which focus was assigned. This property reports
         * the value of the direction parameter of the assignFocus() method of the stage. 
         * If the focus changed through some other means, the value will always be FocusDirection.NONE.
         * Applies only to focusIn events. For all other focus events the value will be 
         * FocusDirection.NONE.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string FocusEvent::FOCUS_IN="focusIn";

        /**
         * Defines the value of the type property of a focusOut event object. 
         * This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.keyCode0; applies only to keyFocusChange events.relatedObjectThe complementary InteractiveObject instance that is affected by the change in focus.shiftKeyfalse; applies only to keyFocusChange events.targetThe InteractiveObject instance that has just lost focus. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string FocusEvent::FOCUS_OUT="focusOut";

        /**
         * Defines the value of the type property of a keyFocusChange event object.
         * 
         *   This event has the following properties:PropertyValuebubblestruecancelabletrue; call the preventDefault() method
         * to cancel default behavior.currentTargetThe object that is actively processing 
         * the Event 
         * object with an event listener.keyCodeThe key code value of the key pressed to trigger a keyFocusChange event.relatedObjectThe complementary InteractiveObject instance that is affected by the change in focus.shiftKeytrue if the Shift key modifier is activated; false otherwise.targetThe InteractiveObject instance that currently has focus. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string FocusEvent::KEY_FOCUS_CHANGE="keyFocusChange";

        /**
         * Defines the value of the type property of a mouseFocusChange event object. 
         * This event has the following properties:PropertyValuebubblestruecancelabletrue; call the preventDefault() method 
         * to cancel default behavior.currentTargetThe object that is actively processing the Event 
         * object with an event listener.keyCode0; applies only to keyFocusChange events.relatedObjectThe complementary InteractiveObject instance that is affected by the change in focus.shiftKeyfalse; applies only to keyFocusChange events.targetThe InteractiveObject instance that currently has focus. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string FocusEvent::MOUSE_FOCUS_CHANGE="mouseFocusChange";

        /**
         * A reference to the complementary InteractiveObject instance that is affected by the
         * change in focus. For example, when a focusOut event occurs, the
         * relatedObject represents the InteractiveObject instance that has gained focus.
         * The value of this property can be null in two circumstances: if there no related object, 
         * or there is a related object, but it is in a security sandbox to which you don't have access.
         * Use the isRelatedObjectInaccessible() property to determine which of these reasons applies.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::display::InteractiveObject* FocusEvent::relatedObject()                                  ;
        void FocusEvent::relatedObject(InteractiveObject* value)       ;

        /**
         * Indicates whether the Shift key modifier is activated, in which case the value is 
         * true. Otherwise, the value is false. This property is 
         * used only if the FocusEvent is of type keyFocusChange.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        bool FocusEvent::shiftKey()          ;
        void FocusEvent::shiftKey(bool value)       ;

        /**
         * The key code value of the key pressed to trigger a keyFocusChange event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        unsigned int FocusEvent::keyCode()       ;
        void FocusEvent::keyCode(unsigned int value)       ;

        /**
         * If true, the relatedObject property is set to null for 
         * reasons related to security sandboxes.  If the nominal value of relatedObject is a reference to a
         * DisplayObject in another sandbox, relatedObject is set to
         * null unless there is permission in both directions across this sandbox boundary.  Permission is
         * established by calling Security.allowDomain() from a SWF file, or by providing
         * a policy file from the server of an image file, and setting the LoaderContext.checkPolicyFile
         * property when loading the image.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   Lite 4
         */
        bool FocusEvent::isRelatedObjectInaccessible()          ;
        void FocusEvent::isRelatedObjectInaccessible(bool value)       ;

        /**
         * Creates an Event object with specific information relevant to focus events.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Possible values are:
         *   FocusEvent.FOCUS_IN, FocusEvent.FOCUS_OUT, FocusEvent.KEY_FOCUS_CHANGE, and FocusEvent.MOUSE_FOCUS_CHANGE.
         * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow.
         * @param   cancelable  Determines whether the Event object can be canceled.
         * @param   relatedObject   Indicates the complementary InteractiveObject instance that is affected by the change in focus. For example, when a focusIn event occurs, relatedObject represents the InteractiveObject that has lost focus.
         * @param   shiftKey    Indicates whether the Shift key modifier is activated.
         * @param   keyCode Indicates the code of the key pressed to trigger a keyFocusChange event.
         * @param   direction   Indicates from which direction the target interactive object is being activated. Set to
         *   FocusDirection.NONE (the default value) for all events other than focusIn.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        FocusEvent::FocusEvent(std::string type, bool bubbles, bool cancelable, InteractiveObject* relatedObject, bool shiftKey, unsigned int keyCode);

        /**
         * Creates a copy of the FocusEvent object and sets the value of each property to match that of the original.
         * @return  A new FocusEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::events::Event* FocusEvent::clone()                     ;

        /**
         * Returns a string that contains all the properties of the FocusEvent object. The string is in the following format:
         * [FocusEvent type=value bubbles=value cancelable=value relatedObject=value shiftKey=value] keyCode=value]
         * @return  A string that contains all the properties of the FocusEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string FocusEvent::toString()         ;
}
}

