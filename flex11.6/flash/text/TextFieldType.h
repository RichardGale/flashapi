#if !defined(FLEX11_6_FLASH_TEXT_TEXTFIELDTYPE_AS)
#define FLEX11_6_FLASH_TEXT_TEXTFIELDTYPE_AS
#if defined(__cplusplus)


/**
 * The TextFieldType class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">type</codeph> property
 * of the TextField class.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



namespace flash
{
    namespace text
    {
        class TextFieldType : public Object
        {
            /**
             * Used to specify an input TextField.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string INPUT;

            /**
             * Used to specify a dynamic TextField.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string DYNAMIC;

        public:
            TextFieldType();
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_TEXTFIELDTYPE_AS
#endif // __cplusplus

