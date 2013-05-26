#if !defined(FLEX11_6_FLASH_TEXT_FONTSTYLE_AS)
#define FLEX11_6_FLASH_TEXT_FONTSTYLE_AS
#if defined(__cplusplus)


/**
 * The FontStyle class provides values for the TextRenderer class.
 * @langversion 3.0
 * @playerversion   Flash 9
 */

#include "flex11.6.h"



namespace flash
{
    namespace text
    {
        class FontStyle : public Object
        {
            /**
             * Defines the plain style of a font for the fontStyle parameter in the setAdvancedAntiAliasingTable() method. Use the syntax FontStyle.REGULAR.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string REGULAR;

            /**
             * Defines the bold style of a font for the fontStyle parameter in the setAdvancedAntiAliasingTable() method. Use the syntax FontStyle.BOLD.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string BOLD;

            /**
             * Defines the italic style of a font for the fontStyle parameter in the setAdvancedAntiAliasingTable() method. Use the syntax FontStyle.ITALIC.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string ITALIC;

            /**
             * Defines the combined bold and italic style of a font for the fontStyle parameter in the setAdvancedAntiAliasingTable() method. Use the syntax FontStyle.BOLD_ITALIC.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string BOLD_ITALIC;

        public:
            FontStyle();
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_FONTSTYLE_AS
#endif // __cplusplus

