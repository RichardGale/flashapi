#if !defined(FLEX11_6_FLASH_UI_KEYBOARDTYPE_AS)
#define FLEX11_6_FLASH_UI_KEYBOARDTYPE_AS
#if defined(__cplusplus)


/**
 * The KeyboardType class is an enumeration class that provides values for different categories of physical computer or device keyboards.
 *
 *   <p class="- topic/p ">Use the values defined by the KeyboardType class with the <codeph class="+ topic/ph pr-d/codeph ">Keybooard.physicalKeyboardType</codeph>
 * property.</p>
 *
 *   EXAMPLE:
 *
 *   The following example is a simple test that indicates the current state of the "Num Lock" and "Caps Lock" keys
 * as well as the type of keybaord and touch screen type in the running environment. When testing this example, click the
 * text field to see the property values:
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * import flash.events.~~;
 * import flash.display.~~;
 * import flash.ui.Keyboard;
 * import flash.system.Capabilities;
 * import flash.text.TextField;
 *
 *   var keyboardInfoTxt:TextField = new TextField();
 * keyboardInfoTxt.x = 30;
 * keyboardInfoTxt.y = 50;
 * keyboardInfoTxt.width = 300;
 * keyboardInfoTxt.height = 100;
 * keyboardInfoTxt.border = true;
 *
 *   addChild(keyboardInfoTxt);
 *
 *   addEventListener (MouseEvent.CLICK, getScreenKeyboardType);
 *
 *   function getScreenKeyboardType(e:MouseEvent):void{
 * keyboardInfoTxt.text= "Caps Lock is : " + String(flash.ui.Keyboard.capsLock)+ "\n" +
 * "Num Lock is : " + String(flash.ui.Keyboard.numLock) +"\n" +
 * "Has Virtual Keyboard : " + String(flash.ui.Keyboard.hasVirtualKeyboard) + "\n" +
 * "Physical Keyboard Type : " + flash.ui.Keyboard.physicalKeyboardType + "\n" +
 * "flash.system.Capabilities.touchscreenType is : " + flash.system.Capabilities.touchscreenType;
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */


namespace flash
{
    namespace ui
    {
        class KeyboardType : public Object
        {
            /**
             * A standard keyboard with a full set of numbers and letters.
             *
             *   Most desktop computers and some mobile devices provide an alphanumeric keyboard.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string ALPHANUMERIC;

            /**
             * A phone-style 12-button keypad.
             *
             *   Many mobile devices provide a keypad, although some provide an alphanumeric keyboard.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string KEYPAD;

            /**
             * No physical keyboard is supported.
             *
             *   Typically, a virtual keyboard is provided in the absence of a physical keyboard.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string NONE;

        public:
            KeyboardType();
        };
    }
}

#endif // FLEX11_6_FLASH_UI_KEYBOARDTYPE_AS
#endif // __cplusplus

