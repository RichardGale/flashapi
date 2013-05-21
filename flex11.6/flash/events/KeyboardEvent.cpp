

#include "KeyboardEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.KeyboardEvent.KEY_DOWN

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * The KeyboardEvent.KEY_DOWN constant defines the value of the type property of a keyDown event object.
         * 
         *   This event has the following properties:PropertyValuebubblestruecancelabletrue in AIR, false in Flash Player; 
         * in AIR, canceling this event prevents the character from being entered into a text field.charCodeThe character code value of the key pressed or released.commandKeytrue on Mac if the Command key is active. Otherwise, falsecontrolKeytrue on Windows and Linux if the Ctrl key is active. true on Mac if either the Control key is active. Otherwise, falsectrlKeytrue on Windows and Linux if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.keyCodeThe key code value of the key pressed or released.keyLocationThe location of the key on the keyboard.shiftKeytrue if the Shift key is active; false if it is inactive.targetThe InteractiveObject instance with focus. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string KeyboardEvent::KEY_DOWN="keyDown";

        /**
         * The KeyboardEvent.KEY_UP constant defines the value of the type property of a keyUp event object. 
         * This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.charCodeContains the character code value of the key pressed or released.commandKeytrue on Mac if the Command key is active. Otherwise, falsecontrolKeytrue on Windows and Linux if the Ctrl key is active. true on Mac if either the Control key is active. Otherwise, falsectrlKeytrue on Windows if the Ctrl key is active. true on Mac if either the Ctrl key or the Command key is active. Otherwise, false.currentTargetThe object that is actively processing the Event 
         * object with an event listener.keyCodeThe key code value of the key pressed or released.keyLocationThe location of the key on the keyboard.shiftKeytrue if the Shift key is active; false if it is inactive.targetThe InteractiveObject instance with focus. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string KeyboardEvent::KEY_UP="keyUp";

        /**
         * Contains the character code value of the key pressed or released.
         * The character code values are English keyboard values. For example,
         * if you press Shift+3, charCode is # on a Japanese keyboard,
         * just as it is on an English keyboard.
         * Note: When an input method editor (IME) is running,
         * charCode does not report accurate character codes.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        unsigned int KeyboardEvent::charCode()       ;
        void KeyboardEvent::charCode(unsigned int value)       ;

        /**
         * The key code value of the key pressed or released.
         * Note: When an input method editor (IME) is running,
         * keyCode does not report accurate key codes.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        unsigned int KeyboardEvent::keyCode()       ;
        void KeyboardEvent::keyCode(unsigned int value)       ;

        /**
         * Indicates the location of the key on the keyboard. This is useful for differentiating keys 
         * that appear more than once on a keyboard. For example, you can differentiate between the 
         * left and right Shift keys by the value of this property: KeyLocation.LEFT 
         * for the left and KeyLocation.RIGHT for the right. Another example is 
         * differentiating between number keys pressed on the standard keyboard
         * (KeyLocation.STANDARD) versus the numeric keypad (KeyLocation.NUM_PAD).
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        unsigned int KeyboardEvent::keyLocation()       ;
        void KeyboardEvent::keyLocation(unsigned int value)       ;

        /**
         * On Windows and Linux, indicates whether the Ctrl key is active (true) or inactive (false);
         * On Mac OS, indicates whether either the Ctrl key or the Command key is active.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        bool KeyboardEvent::ctrlKey()          ;
        void KeyboardEvent::ctrlKey(bool value)       ;

        /**
         * Indicates whether the Alt key is active (true) or inactive (false) on Windows; 
         * indicates whether the Option key is active on Mac OS.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        bool KeyboardEvent::altKey()          ;
        void KeyboardEvent::altKey(bool value)       ;

        /**
         * Indicates whether the Shift key modifier is active (true) or inactive 
         * (false).
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        bool KeyboardEvent::shiftKey()          ;
        void KeyboardEvent::shiftKey(bool value)       ;

        /**
         * Creates a copy of the KeyboardEvent object and sets the value of each property to match that of the original.
         * @return  A new KeyboardEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::events::Event* KeyboardEvent::clone()                     ;

        /**
         * Creates an Event object that contains specific information about keyboard events.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Possible values are:
         *   KeyboardEvent.KEY_DOWN and KeyboardEvent.KEY_UP
         * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow.
         * @param   cancelable  Determines whether the Event object can be canceled.
         * @param   charCodeValue   The character code value of the key pressed or released. The character code values returned are English keyboard values. For example, if you press Shift+3, the Keyboard.charCode() property returns # on a Japanese keyboard, just as it does on an English keyboard.
         * @param   keyCodeValue    The key code value of the key pressed or released.
         * @param   keyLocationValue    The location of the key on the keyboard.
         * @param   ctrlKeyValue    On Windows, indicates whether the Ctrl key is activated. On Mac, indicates whether either the Ctrl key or the Command key is activated.
         * @param   altKeyValue Indicates whether the Alt key modifier is activated (Windows only).
         * @param   shiftKeyValue   Indicates whether the Shift key modifier is activated.
         * @param   controlKeyValue Indicates whether the Control key is activated on Mac, and whether the Control or Ctrl keys are activated on WIndows and Linux.
         * @param   commandKeyValue Indicates whether the Command key is activated (Mac only).
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        KeyboardEvent::KeyboardEvent(std::string type, bool bubbles, bool cancelable, unsigned int charCodeValue, unsigned int keyCodeValue, unsigned int keyLocationValue, bool ctrlKeyValue, bool altKeyValue, bool shiftKeyValue);

        /**
         * Returns a string that contains all the properties of the KeyboardEvent object. The string 
         * is in the following format:
         * [KeyboardEvent type=value bubbles=value cancelable=value ... shiftKey=value]
         * @return  A string that contains all the properties of the KeyboardEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string KeyboardEvent::toString()         ;

        /**
         * Indicates that the display should be rendered after processing of this event completes, if the display 
         * list has been modified
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        void KeyboardEvent::updateAfterEvent()       ;
}
}

