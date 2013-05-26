#if !defined(FLEX11_6_FLASH_TEXT_TEXTFIELDAUTOSIZE_AS)
#define FLEX11_6_FLASH_TEXT_TEXTFIELDAUTOSIZE_AS
#if defined(__cplusplus)


/**
 * The TextFieldAutoSize class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">autoSize</codeph>
 * property of the TextField class.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



namespace flash
{
    namespace text
    {
        class TextFieldAutoSize : public Object
        {
            /**
             * Specifies that no resizing is to occur.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string NONE;

            /**
             * Specifies that the text is to be treated as left-justified text,
             * meaning that the left side of the text field remains fixed and any
             * resizing of a single line is on the right side.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string LEFT;

            /**
             * Specifies that the text is to be treated as center-justified text.
             * Any resizing of a single line of a text field is equally distributed
             * to both the right and left sides.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string CENTER;

            /**
             * Specifies that the text is to be treated as right-justified text,
             * meaning that the right side of the text field remains fixed and any
             * resizing of a single line is on the left side.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string RIGHT;

        public:
            TextFieldAutoSize();
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_TEXTFIELDAUTOSIZE_AS
#endif // __cplusplus

