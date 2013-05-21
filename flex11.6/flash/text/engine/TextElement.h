#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_TEXTELEMENT_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_TEXTELEMENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace text
    {
        namespace engine
        {
            class ElementFormat;
        }
    }
}
namespace flash
{
    namespace events
    {
        class EventDispatcher;
    }
}

/**
 * The TextElement class represents a string of formatted text. Assign a TextElement object to the <codeph class="+ topic/ph pr-d/codeph ">content</codeph>
 * property of a TextBlock object to create a block of text. Assign it to a GroupElement object to combine it with other text
 * and graphic elements as a unit. Use the ElementFormat class to format the text.
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 * @playerversion   Lite 4
 */

using namespace flash::events;
using namespace flash::text::engine;

namespace flash
{
    namespace text
    {
        namespace engine
        {
            class TextElement : public ContentElement
            {
                /**
                 * Receives the text that is the content of the element.
                 *
                 *   The default value is null.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                void         text(std::string value);

                /**
                 * Replaces the range of characters that the beginIndex and
                 * endIndex parameters specify with the contents
                 * of the newText parameter. The beginIndex and
                 * endIndex values refer to the current contents of text.
                 * To delete text, pass null for newText.To insert text, pass the same value for beginIndex and endIndex.
                 * The new text is inserted before the specified index.To append text, pass text.length for beginIndex and endIndex.To set all the text, pass 0 for beginIndex and text.length for endIndex.
                 * @param   beginIndex  The zero-based index value for the start position of the replacement range.
                 * @param   endIndex    The zero-based index value following the end position of the replacement range.
                 * @param   newText The text to use to replace the specified range of characters.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError The beginIndex or endIndex specified is out of range.
                 */
            public:
                void     replaceText(int beginIndex, int endIndex, std::string newText);

                /**
                 * Creates a new TextElement instance.
                 * @param   text    The text for the element.  The default value is null.
                 * @param   elementFormat   The element format for the text in the element.  The default value is null.
                 * @param   eventMirror The EventDispatcher object that receives copies of every
                 *   event dispatched to text lines based on this content element.  The default value is null.
                 * @param   textRotation    The rotation applied the element as a unit. Use TextRotation
                 *   constants for this property.  The default value is TextRotation.ROTATE_0.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                TextElement(std::string text="", ElementFormat *elementFormat=NULL, EventDispatcher *eventMirror=NULL, std::string textRotation="rotate0");
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_TEXTELEMENT_AS
#endif // __cplusplus

