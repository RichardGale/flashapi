#if !defined(FLEX11_6_FLASH_EVENTS_KEYBOARDEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_KEYBOARDEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/Event.h"

/// @eventType  flash.events.KeyboardEvent.KEY_DOWN
//[Event(name="keyDown",type="flash.events.KeyboardEvent")]


//[Event(name="keyUp",type="flash.events.KeyboardEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /// @eventType  flash.events.KeyboardEvent.KEY_UP


        /**
         * A KeyboardEvent object id dispatched in response to user input through a keyboard.
         * There are two types of keyboard events: <codeph class="+ topic/ph pr-d/codeph ">KeyboardEvent.KEY_DOWN</codeph> and
         * <codeph class="+ topic/ph pr-d/codeph ">KeyboardEvent.KEY_UP</codeph><p class="- topic/p ">Because mappings between keys and specific characters vary by device
         * and operating system, use the TextEvent event type for processing character input.</p><p class="- topic/p ">To listen globally for key events, listen on the Stage for the capture and target
         * or bubble phase.</p>
         *
         *   EXAMPLE:
         *
         *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">KeyboardEventExample</codeph> class to show
         * keyboard events and their listener functions. The example carries out the following tasks:
         * <ol class="- topic/ol "><li class="- topic/li ">It creates a new Sprite instance named <codeph class="+ topic/ph pr-d/codeph ">child</codeph>.</li><li class="- topic/li ">It declares properties for later use in setting a square's background color and size.</li><li class="- topic/li ">Using methods of Sprite, it draws a light-blue square that it displays on the Stage
         * at default coordinates (0,0) by calling the <codeph class="+ topic/ph pr-d/codeph ">addChild()</codeph> method.</li><li class="- topic/li ">It adds one mouse event and two keyboard type event listeners:
         * <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">click</codeph>/<codeph class="+ topic/ph pr-d/codeph ">clickHandler</codeph> which is dispatched when you click on the square to set focus on the <codeph class="+ topic/ph pr-d/codeph ">child</codeph> sprite so it can listen for keyboard events.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">keyDown</codeph>/<codeph class="+ topic/ph pr-d/codeph ">keyDownHandler</codeph> which is dispatched whenever any key  is pressed. The subscriber method prints information about the event
         * using the <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph> statement.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">keyUp</codeph>/<codeph class="+ topic/ph pr-d/codeph ">keyUpHandler</codeph> which is dispatched when a key is
         * released.</li></ul></li></ol><p class="- topic/p ">When you test this example, you need to click the square first for the keyboard events to work.</p><p product="flash" class="- topic/p ">Also, if you are using the Test Movie command in Flash, the authoring
         * interface may respond to certain keys instead of the event listeners attached to
         * the child sprite.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Sprite;
         * import flash.display.DisplayObject;
         * import flash.events.*;
         *
         *   public class KeyboardEventExample extends Sprite {
         * private var child:Sprite = new Sprite();
         * private var bgColor:uint = 0x00CCFF;
         * private var size:uint = 80;
         *
         *   public function KeyboardEventExample() {
         * child.graphics.beginFill(bgColor);
         * child.graphics.drawRect(0, 0, size, size);
         * child.graphics.endFill();
         * addChild(child);
         * child.addEventListener(MouseEvent.CLICK, clickHandler);
         * child.addEventListener(KeyboardEvent.KEY_DOWN, keyDownHandler);
         * child.addEventListener(KeyboardEvent.KEY_UP, keyUpHandler);
         *
         *   }
         *
         *   private function clickHandler(event:MouseEvent):void {
         * stage.focus = child;
         * }
         *
         *   private function keyDownHandler(event:KeyboardEvent):void {
         * trace("keyDownHandler: " + event.keyCode);
         * trace("ctrlKey: " + event.ctrlKey);
         * trace("keyLocation: " + event.keyLocation);
         * trace("shiftKey: " + event.shiftKey);
         * trace("altKey: " + event.altKey);
         *
         *   }
         *
         *   private function keyUpHandler(event:KeyboardEvent):void {
         * trace("keyUpHandler: " + event.keyCode);
         * }
         *
         *   }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        class KeyboardEvent : public flash::events::Event
        {
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
        public:
            static const std::string KEY_DOWN;

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
        public:
            static const std::string KEY_UP;

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
        public:
            unsigned int charCode();
        public:
            void         charCode(unsigned int value);

            /**
             * The key code value of the key pressed or released.
             * Note: When an input method editor (IME) is running,
             * keyCode does not report accurate key codes.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int keyCode();
        public:
            void         keyCode(unsigned int value);

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
        public:
            unsigned int keyLocation();
        public:
            void         keyLocation(unsigned int value);

            /**
             * On Windows and Linux, indicates whether the Ctrl key is active (true) or inactive (false);
             * On Mac OS, indicates whether either the Ctrl key or the Command key is active.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool         ctrlKey();
        public:
            void         ctrlKey(bool value);

            /**
             * Indicates whether the Alt key is active (true) or inactive (false) on Windows;
             * indicates whether the Option key is active on Mac OS.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool         altKey();
        public:
            void         altKey(bool value);

            /**
             * Indicates whether the Shift key modifier is active (true) or inactive
             * (false).
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool         shiftKey();
        public:
            void         shiftKey(bool value);

            /**
             * Creates a copy of the KeyboardEvent object and sets the value of each property to match that of the original.
             * @return  A new KeyboardEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

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
        public:
            KeyboardEvent(std::string type, bool bubbles   =true, bool cancelable   =false, unsigned int charCodeValue=0, unsigned int keyCodeValue=0, unsigned int keyLocationValue=0, bool ctrlKeyValue   =false, bool altKeyValue   =false, bool shiftKeyValue   =false);

            /**
             * Returns a string that contains all the properties of the KeyboardEvent object. The string
             * is in the following format:
             * [KeyboardEvent type=value bubbles=value cancelable=value ... shiftKey=value]
             * @return  A string that contains all the properties of the KeyboardEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string toString();

            /**
             * Indicates that the display should be rendered after processing of this event completes, if the display
             * list has been modified
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            void     updateAfterEvent();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_KEYBOARDEVENT_AS
#endif // __cplusplus

