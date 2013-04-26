#if !defined(FLEX11_6_FLASH_TEXT_TEXTINTERACTIONMODE_AS)
#define FLEX11_6_FLASH_TEXT_TEXTINTERACTIONMODE_AS
#if defined(__cplusplus)


/**
 * A class that defines the Interactive mode of a text field object.
 * @langversion 3.0
 * @playerversion   Flash 11
 */

namespace flash
{
    namespace text
    {
        class TextInteractionMode: public Object
        {
            /**
             * The text field's default interaction mode is NORMAL and it varies across platform.
             * On Desktop, the normal mode implies that the text field is in scrollable + selection mode.
             * On Mobile platforms like Android, normal mode implies that the text field can only be scrolled but
             * the text can not be selected.
             * @langversion 3.0
             * @playerversion   Flash 11
             */
        public:
            static const std::string NORMAL;

            /**
             * On mobile platforms like Android, the text field starts in normal mode(which implies scroll and non-selectable mode).
             * The user can switch to selection mode through the in-built context menu of the text field object.
             * @langversion 3.0
             * @playerversion   Flash 11
             */
        public:
            static const std::string SELECTION;

        public:
            TextInteractionMode();
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_TEXTINTERACTIONMODE_AS
#endif // __cplusplus

