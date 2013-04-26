#if !defined(FLEX11_6_FLASH_TEXT_STATICTEXT_AS)
#define FLEX11_6_FLASH_TEXT_STATICTEXT_AS
#if defined(__cplusplus)


#include "flash/display/DisplayObject.h"

/**
 * This class represents StaticText objects on the display list.
 * You cannot create a StaticText object using ActionScript. Only the authoring tool
 * can create a StaticText object. An attempt to create a new StaticText object generates
 * an <codeph class="+ topic/ph pr-d/codeph ">ArgumentError</codeph>.
 *
 *   <p class="- topic/p ">To create a reference to an existing static text field in ActionScript 3.0,
 * you can iterate over the items in the display list. For example, the following snippet checks
 * to see if the display list contains a static text field and assigns the field to
 * a variable:</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * var i:uint;
 * for (i = 0; i &lt; this.numChildren; i++) {
 * var displayitem:DisplayObject = this.getChildAt(i);
 * if (displayitem instanceof StaticText) {
 * trace("a static text field is item " + i + " on the display list");
 * var myFieldLabel:StaticText = StaticText(displayitem);
 * trace("and contains the text: " + myFieldLabel.text);
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
using namespace flash::display;

namespace flash
{
    namespace text
    {
        class StaticText: public DisplayObject
        {
            /**
             * Returns the current text of the static text field. The authoring tool may export multiple text field
             * objects comprising the complete text. For example, for vertical text, the authoring tool will create
             * one text field per character.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  text();

        public:
            StaticText();
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_STATICTEXT_AS
#endif // __cplusplus

