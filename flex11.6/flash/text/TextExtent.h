#if !defined(FLEX11_6_FLASH_TEXT_TEXTEXTENT_AS)
#define FLEX11_6_FLASH_TEXT_TEXTEXTENT_AS
#if defined(__cplusplus)


/**
 * The TextExtent class contains information about the extents of some
 * text in a text field.  Objects of this class are returned by the
 * <codeph class="+ topic/ph pr-d/codeph ">TextFormat.getTextExtent</codeph> method.
 * @playerversion   Flash 9
 */

#include "flex11.6.h"



namespace flash
{
    namespace text
    {
        class TextExtent : public Object
        {
        public:
            float width;
        public:
            float height;
        public:
            float textFieldWidth;
        public:
            float textFieldHeight;
        public:
            float ascent;
        public:
            float descent;

        public:
            TextExtent(float width, float height, float textFieldWidth, float textFieldHeight, float ascent, float descent);
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_TEXTEXTENT_AS
#endif // __cplusplus

