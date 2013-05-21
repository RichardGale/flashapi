#if !defined(FLEX11_6_FLASH_UI_KEYBOARD_AS)
#define FLEX11_6_FLASH_UI_KEYBOARD_AS
#if defined(__cplusplus)


/**
 * The Keyboard class is used to build an interface that can be controlled by a user with a standard keyboard.
 * You can use the methods and properties of the Keyboard class without using a constructor.
 * The properties of the Keyboard class are constants representing the keys that are
 * most commonly used to control games.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace ui
    {
        class Keyboard : public Object
        {
            /**
             * The up arrow
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_UPARROW;

            /**
             * The down arrow
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_DOWNARROW;

            /**
             * The left arrow
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_LEFTARROW;

            /**
             * The right arrow
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_RIGHTARROW;

            /**
             * The F1 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F1;

            /**
             * The F2 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F2;

            /**
             * The F3 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F3;

            /**
             * The F4 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F4;

            /**
             * The F5 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F5;

            /**
             * The F6 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F6;

            /**
             * The F7 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F7;

            /**
             * The F8 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F8;

            /**
             * The F9 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F9;

            /**
             * The F10 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F10;

            /**
             * The F11 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F11;

            /**
             * The F12 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F12;

            /**
             * The F13 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F13;

            /**
             * The F14 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F14;

            /**
             * The F15 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F15;

            /**
             * The F16 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F16;

            /**
             * The F17 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F17;

            /**
             * The F18 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F18;

            /**
             * The F19 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F19;

            /**
             * The F20 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F20;

            /**
             * The F21 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F21;

            /**
             * The F22 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F22;

            /**
             * The F23 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F23;

            /**
             * The F24 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F24;

            /**
             * The F25 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F25;

            /**
             * The F26 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F26;

            /**
             * The F27 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F27;

            /**
             * The F28 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F28;

            /**
             * The F29 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F29;

            /**
             * The F30 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F30;

            /**
             * The F31 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F31;

            /**
             * The F32 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F32;

            /**
             * The F33 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F33;

            /**
             * The F34 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F34;

            /**
             * The F35 key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_F35;

            /**
             * The Insert key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_INSERT;

            /**
             * The Delete key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_DELETE;

            /**
             * The Home key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_HOME;

            /**
             * The Begin key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_BEGIN;

            /**
             * The End key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_END;

            /**
             * The Page Up key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_PAGEUP;

            /**
             * The Page Down key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_PAGEDOWN;

            /**
             * The Print Screen
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_PRINTSCREEN;

            /**
             * The Scroll Lock key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_SCROLLLOCK;

            /**
             * The Pause key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_PAUSE;

            /**
             * The System Request key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_SYSREQ;

            /**
             * The Break key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_BREAK;

            /**
             * The Reset key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_RESET;

            /**
             * The Stop key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_STOP;

            /**
             * The Menu key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_MENU;

            /**
             * The User key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_USER;

            /**
             * The System key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_SYSTEM;

            /**
             * The Print key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_PRINT;

            /**
             * The Clear Line key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_CLEARLINE;

            /**
             * The Clear Display key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_CLEARDISPLAY;

            /**
             * The Insert Line key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_INSERTLINE;

            /**
             * The Delete Line key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_DELETELINE;

            /**
             * The Insert Character key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_INSERTCHAR;

            /**
             * The Delete Character key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_DELETECHAR;

            /**
             * The Previous key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_PREV;

            /**
             * The Next key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_NEXT;

            /**
             * The Select key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_SELECT;

            /**
             * The Execute key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_EXECUTE;

            /**
             * The Undo key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_UNDO;

            /**
             * The Redo key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_REDO;

            /**
             * The Find key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_FIND;

            /**
             * The Help key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_HELP;

            /**
             * The Mode Switch key
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string KEYNAME_MODESWITCH;

            /**
             * The OS X Unicode up arrow constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_UPARROW;

            /**
             * The OS X Unicode down arrow constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_DOWNARROW;

            /**
             * The OS X Unicode left arrow constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_LEFTARROW;

            /**
             * The OS X Unicode right arrow constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_RIGHTARROW;

            /**
             * The OS X Unicode F1 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F1;

            /**
             * The OS X Unicode F2 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F2;

            /**
             * The OS X Unicode F3 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F3;

            /**
             * The OS X Unicode F4 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F4;

            /**
             * The OS X Unicode F5 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F5;

            /**
             * The OS X Unicode F6 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F6;

            /**
             * The OS X Unicode F7 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F7;

            /**
             * The OS X Unicode F8 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F8;

            /**
             * The OS X Unicode F9 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F9;

            /**
             * The OS X Unicode F10 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F10;

            /**
             * The OS X Unicode F11 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F11;

            /**
             * The OS X Unicode F12 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F12;

            /**
             * The OS X Unicode F13 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F13;

            /**
             * The OS X Unicode F14 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F14;

            /**
             * The OS X Unicode F15 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F15;

            /**
             * The OS X Unicode F16 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F16;

            /**
             * The OS X Unicode F17 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F17;

            /**
             * The OS X Unicode F18 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F18;

            /**
             * The OS X Unicode F19 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F19;

            /**
             * The OS X Unicode F20 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F20;

            /**
             * The OS X Unicode F21 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F21;

            /**
             * The OS X Unicode F22 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F22;

            /**
             * The OS X Unicode F23 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F23;

            /**
             * The OS X Unicode F24 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F24;

            /**
             * The OS X Unicode F25 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F25;

            /**
             * The OS X Unicode F26 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F26;

            /**
             * The OS X Unicode F27 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F27;

            /**
             * The OS X Unicode F28 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F28;

            /**
             * The OS X Unicode F29 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F29;

            /**
             * The OS X Unicode F30 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F30;

            /**
             * The OS X Unicode F31 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F31;

            /**
             * The OS X Unicode F32 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F32;

            /**
             * The OS X Unicode F33 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F33;

            /**
             * The OS X Unicode F34 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F34;

            /**
             * The OS X Unicode F35 constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_F35;

            /**
             * The OS X Unicode Insert constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_INSERT;

            /**
             * The OS X Unicode Delete constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_DELETE;

            /**
             * The OS X Unicode Home constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_HOME;

            /**
             * The OS X Unicode Begin constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_BEGIN;

            /**
             * The OS X Unicode End constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_END;

            /**
             * The OS X Unicode Page Up constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_PAGEUP;

            /**
             * The OS X Unicode Page Down constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_PAGEDOWN;

            /**
             * The OS X Unicode Print Screen constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_PRINTSCREEN;

            /**
             * The OS X Unicode Scroll Lock constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_SCROLLLOCK;

            /**
             * The OS X Unicode Pause constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_PAUSE;

            /**
             * The OS X Unicode System Request constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_SYSREQ;

            /**
             * The OS X Unicode Break constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_BREAK;

            /**
             * The OS X Unicode Reset constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_RESET;

            /**
             * The OS X Unicode Stop constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_STOP;

            /**
             * The OS X Unicode Menu constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_MENU;

            /**
             * The OS X Unicode User constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_USER;

            /**
             * The OS X Unicode System constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_SYSTEM;

            /**
             * The OS X Unicode Print constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_PRINT;

            /**
             * The OS X Unicode Clear Line constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_CLEARLINE;

            /**
             * The OS X Unicode Clear Display constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_CLEARDISPLAY;

            /**
             * The OS X Unicode Insert Line constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_INSERTLINE;

            /**
             * The OS X Unicode Delete Line constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_DELETELINE;

            /**
             * The OS X Unicode Insert Character constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_INSERTCHAR;

            /**
             * The OS X Unicode Delete Character constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_DELETECHAR;

            /**
             * The OS X Unicode Previous constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_PREV;

            /**
             * The OS X Unicode Next constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_NEXT;

            /**
             * The OS X Unicode Select constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_SELECT;

            /**
             * The OS X Unicode Execute constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_EXECUTE;

            /**
             * The OS X Unicode Undo constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_UNDO;

            /**
             * The OS X Unicode Redo constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_REDO;

            /**
             * The OS X Unicode Find constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_FIND;

            /**
             * The OS X Unicode Help constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_HELP;

            /**
             * The OS X Unicode Mode Switch constant
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string STRING_MODESWITCH;

            /**
             * An array containing all the defined key name constants.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::vector<void *> CharCodeStrings;

            /**
             * Constant associated with the key code value for the 0 key (48).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int NUMBER_0;

            /**
             * Constant associated with the key code value for the 1 key (49).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int NUMBER_1;

            /**
             * Constant associated with the key code value for the 2 key (50).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int NUMBER_2;

            /**
             * Constant associated with the key code value for the 3 key (51).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int NUMBER_3;

            /**
             * Constant associated with the key code value for the 4 key (52).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int NUMBER_4;

            /**
             * Constant associated with the key code value for the 5 key (53).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int NUMBER_5;

            /**
             * Constant associated with the key code value for the 6 key (54).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int NUMBER_6;

            /**
             * Constant associated with the key code value for the 7 key (55).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int NUMBER_7;

            /**
             * Constant associated with the key code value for the 8 key (56).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int NUMBER_8;

            /**
             * Constant associated with the key code value for the 9 key (57).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int NUMBER_9;

            /**
             * Constant associated with the key code value for the A key (65).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int A;

            /**
             * Constant associated with the key code value for the B key (66).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int B;

            /**
             * Constant associated with the key code value for the C key (67).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int C;

            /**
             * Constant associated with the key code value for the D key (68).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int D;

            /**
             * Constant associated with the key code value for the E key (69).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int E;

            /**
             * Constant associated with the key code value for the F key (70).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int F;

            /**
             * Constant associated with the key code value for the G key (71).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int G;

            /**
             * Constant associated with the key code value for the H key (72).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int H;

            /**
             * Constant associated with the key code value for the I key (73).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int I;

            /**
             * Constant associated with the key code value for the J key (74).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int J;

            /**
             * Constant associated with the key code value for the K key (75).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int K;

            /**
             * Constant associated with the key code value for the L key (76).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int L;

            /**
             * Constant associated with the key code value for the M key (77).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int M;

            /**
             * Constant associated with the key code value for the N key (78).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int N;

            /**
             * Constant associated with the key code value for the O key (79).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int O;

            /**
             * Constant associated with the key code value for the P key (80).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int P;

            /**
             * Constant associated with the key code value for the Q key (81).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int Q;

            /**
             * Constant associated with the key code value for the R key (82).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int R;

            /**
             * Constant associated with the key code value for the S key (83).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int S;

            /**
             * Constant associated with the key code value for the T key (84).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int T;

            /**
             * Constant associated with the key code value for the U key (85).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int U;

            /**
             * Constant associated with the key code value for the V key (86).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int V;

            /**
             * Constant associated with the key code value for the W key (87).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int W;

            /**
             * Constant associated with the key code value for the X key (88).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int X;

            /**
             * Constant associated with the key code value for the Y key (89).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int Y;

            /**
             * Constant associated with the key code value for the Z key (90).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int Z;

            /**
             * Constant associated with the key code value for the ; key (186).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int SEMICOLON;

            /**
             * Constant associated with the key code value for the = key (187).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int EQUAL;

            /**
             * Constant associated with the key code value for the , key (188).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int COMMA;

            /**
             * Constant associated with the key code value for the - key (189).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int MINUS;

            /**
             * Constant associated with the key code value for the . key (190).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int PERIOD;

            /**
             * Constant associated with the key code value for the / key (191).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int SLASH;

            /**
             * Constant associated with the key code value for the ` key (192).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int BACKQUOTE;

            /**
             * Constant associated with the key code value for the [ key (219).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int LEFTBRACKET;

            /**
             * Constant associated with the key code value for the \ key (220).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int BACKSLASH;

            /**
             * Constant associated with the key code value for the ] key (221).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int RIGHTBRACKET;

            /**
             * Constant associated with the key code value for the ' key (222).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int QUOTE;

            /**
             * Constant associated with the key code value for the Alternate (Option) key (18).
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int ALTERNATE;

            /**
             * Constant associated with the key code value for the Backspace key (8).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int BACKSPACE;

            /**
             * Constant associated with the key code value for the Caps Lock key (20).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int CAPS_LOCK;

            /**
             * Constant associated with the Mac command key (15).  This constant is currently only used for setting menu key equivalents.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int COMMAND;

            /**
             * Constant associated with the key code value for the Control key (17).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int CONTROL;

            /**
             * Constant associated with the key code value for the Delete key (46).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int DELETE;

            /**
             * Constant associated with the key code value for the Down Arrow key (40).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int DOWN;

            /**
             * Constant associated with the key code value for the End key (35).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int END;

            /**
             * Constant associated with the key code value for the Enter key (13).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int ENTER;

            /**
             * Constant associated with the key code value for the Escape key (27).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int ESCAPE;

            /**
             * Constant associated with the key code value for the F1 key (112).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F1;

            /**
             * Constant associated with the key code value for the F2 key (113).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F2;

            /**
             * Constant associated with the key code value for the F3 key (114).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F3;

            /**
             * Constant associated with the key code value for the F4 key (115).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F4;

            /**
             * Constant associated with the key code value for the F5 key (116).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F5;

            /**
             * Constant associated with the key code value for the F6 key (117).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F6;

            /**
             * Constant associated with the key code value for the F7 key (118).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F7;

            /**
             * Constant associated with the key code value for the F8 key (119).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F8;

            /**
             * Constant associated with the key code value for the F9 key (120).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F9;

            /**
             * Constant associated with the key code value for the F10 key (121).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F10;

            /**
             * Constant associated with the key code value for the F11 key (122).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F11;

            /**
             * Constant associated with the key code value for the F12 key (123).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F12;

            /**
             * Constant associated with the key code value for the F13 key (124).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F13;

            /**
             * Constant associated with the key code value for the F14 key (125).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F14;

            /**
             * Constant associated with the key code value for the F15 key (126).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int F15;

            /**
             * Constant associated with the key code value for the Home key (36).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int HOME;

            /**
             * Constant associated with the key code value for the Insert key (45).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int INSERT;

            /**
             * Constant associated with the key code value for the Left Arrow key (37).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int LEFT;

            /**
             * Constant associated with the pseudo-key code for the the number pad (21).  Use to
             * set numpad modifier on key equivalents
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const unsigned int NUMPAD;

            /**
             * Constant associated with the key code value for the number 0 key on the number pad (96).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_0;

            /**
             * Constant associated with the key code value for the number 1 key on the number pad (97).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_1;

            /**
             * Constant associated with the key code value for the number 2 key on the number pad (98).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_2;

            /**
             * Constant associated with the key code value for the number 3 key on the number pad (99).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_3;

            /**
             * Constant associated with the key code value for the number 4 key on the number pad (100).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_4;

            /**
             * Constant associated with the key code value for the number 5 key on the number pad (101).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_5;

            /**
             * Constant associated with the key code value for the number 6 key on the number pad (102).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_6;

            /**
             * Constant associated with the key code value for the number 7 key on the number pad (103).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_7;

            /**
             * Constant associated with the key code value for the number 8 key on the number pad (104).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_8;

            /**
             * Constant associated with the key code value for the number 9 key on the number pad (105).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_9;

            /**
             * Constant associated with the key code value for the addition key on the number pad (107).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_ADD;

            /**
             * Constant associated with the key code value for the decimal key on the number pad (110).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_DECIMAL;

            /**
             * Constant associated with the key code value for the division key on the number pad (111).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_DIVIDE;

            /**
             * Constant associated with the key code value for the Enter key on the number pad (108).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_ENTER;

            /**
             * Constant associated with the key code value for the multiplication key on the number pad (106).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_MULTIPLY;

            /**
             * Constant associated with the key code value for the subtraction key on the number pad (109).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int NUMPAD_SUBTRACT;

            /**
             * Constant associated with the key code value for the Page Down key (34).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int PAGE_DOWN;

            /**
             * Constant associated with the key code value for the Page Up key (33).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int PAGE_UP;

            /**
             * Constant associated with the key code value for the Right Arrow key (39).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int RIGHT;

            /**
             * Constant associated with the key code value for the Shift key (16).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int SHIFT;

            /**
             * Constant associated with the key code value for the Spacebar (32).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int SPACE;

            /**
             * Constant associated with the key code value for the Tab key (9).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int TAB;

            /**
             * Constant associated with the key code value for the Up Arrow key (38).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int UP;

            /**
             * Red function key button
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int RED;

            /**
             * Green function key button
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int GREEN;

            /**
             * Yellow function key button
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int YELLOW;

            /**
             * Blue function key button
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int BLUE;

            /**
             * Channel up
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int CHANNEL_UP;

            /**
             * Channel down
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int CHANNEL_DOWN;

            /**
             * Record item or engage record transport mode
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int RECORD;

            /**
             * Engage play transport mode
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int PLAY;

            /**
             * Engage pause transport mode
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int PAUSE;

            /**
             * Engage stop transport mode
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int STOP;

            /**
             * Engage fast-forward transport mode
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int FAST_FORWARD;

            /**
             * Engage rewind transport mode
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int REWIND;

            /**
             * Quick skip ahead (usually 30 seconds)
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int SKIP_FORWARD;

            /**
             * Quick skip backward (usually 7-10 seconds)
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int SKIP_BACKWARD;

            /**
             * Skip to next track or chapter
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int NEXT;

            /**
             * Skip to previous track or chapter
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int PREVIOUS;

            /**
             * Return to live [position in broadcast]
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int LIVE;

            /**
             * Watch last channel or show watched
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int LAST;

            /**
             * Engage menu
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int MENU;

            /**
             * Info button
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int INFO;

            /**
             * Engage program guide
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int GUIDE;

            /**
             * Exits current application mode
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int EXIT;

            /**
             * Return to previous page in application
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int BACK;

            /**
             * Select the audio mode
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int AUDIO;

            /**
             * Toggle subtitles
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int SUBTITLE;

            /**
             * Engage DVR application mode
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int DVR;

            /**
             * Engage video-on-demand
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int VOD;

            /**
             * Cycle input
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int INPUT;

            /**
             * Engage setup application or menu
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int SETUP;

            /**
             * Engage help application or context-sensitive help
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int HELP;

            /**
             * Engage "Master Shell" e.g. TiVo or other vendor button
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int MASTER_SHELL;

            /**
             * Search button
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const unsigned int SEARCH;

            /**
             * Specifies whether the Caps Lock key is activated (true) or not (false).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static bool         capsLock();

            /**
             * Specifies whether the Num Lock key is activated (true) or not (false).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static bool         numLock();

            /**
             * Indicates whether the computer or device provides a virtual keyboard.
             * If the current environment provides a virtual keyboard, this value is true.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static bool         hasVirtualKeyboard();

            /**
             * Indicates the type of physical keyboard provided by the computer or device, if any.
             *
             *   Use the constants defined in the KeyboardType class to test the values reported by this property.Note: If a computer or device has both an alphanumeric keyboard and a 12-button keypad, this
             * property only reports the presence of the alphanumeric keyboard.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static std::string  physicalKeyboardType();

        public:
            Keyboard();

            /**
             * Specifies whether the last key pressed is accessible by other SWF files.
             * By default, security restrictions prevent code from a SWF file in one domain
             * from accessing a keystroke generated from a SWF file in another domain.
             * @return  The value true if the last key pressed can be accessed.
             *   If access is not permitted, this method returns false.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static bool     isAccessible();
        };
    }
}

#endif // FLEX11_6_FLASH_UI_KEYBOARD_AS
#endif // __cplusplus

