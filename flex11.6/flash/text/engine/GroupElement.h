#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_GROUPELEMENT_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_GROUPELEMENT_AS
#if defined(__cplusplus)


#include "flash/text/engine/ContentElement.h"

namespace flash
{
    namespace text
    {
        namespace engine
        {
            class TextElement;
        }
    }
}
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
 * A GroupElement object groups a collection of TextElement, GraphicElement, or other GroupElement objects
 * that you can assign as a unit to the <codeph class="+ topic/ph pr-d/codeph ">content</codeph> property of a TextBlock object. A GroupElement
 * object can also simply share common formatting within another GroupElement object.
 *
 *   <p class="- topic/p ">When a GroupElement contains another GroupElement, the inner GroupElement retains its own formatting (ElementFormat settings). It does
 * not inherit the formatting of the outer GroupElement.</p><p class="- topic/p ">On a GroupElement, most of the format properties have no impact. For this reason, it is legal to create a text line for a GroupElement object
 * that has a null <codeph class="+ topic/ph pr-d/codeph ">elementFormat</codeph> parameter. A few format properties such as <codeph class="+ topic/ph pr-d/codeph ">kerning</codeph> and <codeph class="+ topic/ph pr-d/codeph ">ligature</codeph>
 * do affect formatting where intersections occur between members of the group. If the group has a null format, the format of the preceding
 * element determines the formatting where intersections occur between members of the group.</p>
 *
 *   EXAMPLE:
 *
 *   This example creates a red box as a GraphicElement object and combines
 * it with two TextElement objects to create a GroupElement object. It assigns the GroupElement
 * object to the <codeph class="+ topic/ph pr-d/codeph ">content</codeph> property of a TextBlock, from which it creates three lines.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 *
 *   import flash.display.Sprite;
 * import flash.display.MovieClip;
 * import flash.text.engine.ContentElement;
 * import flash.text.engine.TextBlock;
 * import flash.text.engine.TextElement;
 * import flash.text.engine.GraphicElement;
 * import flash.text.engine.GroupElement;
 * import flash.text.engine.TextLine;
 * import flash.text.engine.ElementFormat;
 * import flash.text.engine.FontDescription;
 *
 *   public class GroupElementExample extends Sprite {
 *
 *   public function GroupElementExample():void {
 *
 *   var redBox:MovieClip = new MovieClip();
 * redBox.graphics.beginFill(0xCC0000, 1.0);
 * redBox.graphics.drawRect(0, 0, 20, 20);
 * redBox.graphics.endFill();
 *
 *   var format:ElementFormat = new ElementFormat();
 * var fontDescription:FontDescription = new FontDescription("Arial");
 * format.fontSize = 16;
 * format.fontDescription = fontDescription;
 *
 *   var str1:String = "This red box is a GraphicElement ";
 * var str2:String = " in the middle of two TextElements, " +
 * " which together make " +
 * "up a GroupElement in a TextBlock that is broken into three lines.";
 *
 *   var textElement1:TextElement = new TextElement(str1,format);
 * var graphicElement:GraphicElement = new GraphicElement(redBox,redBox.width,redBox.height, format);
 * var textElement2:TextElement = new TextElement(str2, format);
 * var groupVector:Vector.&lt;ContentElement&gt; = new Vector.&lt;ContentElement&gt;();
 * groupVector.push(textElement1, graphicElement, textElement2);
 * var groupElement = new GroupElement(groupVector);
 * var textBlock:TextBlock = new TextBlock();
 * textBlock.content = groupElement;
 * createTextLines(textBlock);
 * }
 *
 *   private function createTextLines(textBlock:TextBlock):void
 * {
 *
 *   var yPos = 20;
 * var line_length:Number = 450;
 * var textLine:TextLine = textBlock.createTextLine (null, line_length);
 *
 *   while (textLine)
 * {
 * addChild(textLine);
 * textLine.x = 15;
 * yPos += textLine.height+8;
 * textLine.y = yPos;
 * textLine = textBlock.createTextLine(textLine, line_length);
 * }
 * }
 * }
 * }
 *
 *   </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 * @playerversion   Lite 4
 */
using namespace flash::text::engine;
using namespace flash::text::engine;
using namespace flash::text::engine;
using namespace flash::events;

namespace flash
{
    namespace text
    {
        namespace engine
        {
            class GroupElement: public ContentElement
            {
                /**
                 * The number of elements in the group.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                int          elementCount();

                /**
                 * Retrieves an element from within the group.
                 * @param   index   The index of the element to retrieve.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError If index is out of range.
                 */
            public:
                flash::text::engine::ContentElement *getElementAt(int index);

                /**
                 * Creates a new GroupElement instance.
                 * @param   elements    A Vector of ContentElement objects to be contained in the GroupElement.
                 *   The Vector can be empty.  The default value is null.
                 * @param   elementFormat   The element format for the group.  The default value is null.
                 *   This format applies to the intersections between elements in the group; those elements do not inherit the format.
                 * @param   eventMirror The EventDispatcher object that receives copies of every
                 *   event dispatched to text lines created based on this content element.  The default value is null.
                 * @param   textRotation    The rotation applied to the element as a unit. Use TextRotation constants for
                 *   this property. The default value is TextRotation.ROTATE_0.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  ArgumentError The specified element contains null elements.
                 * @throws  ArgumentError The specified element contains an element that is not a known subclass of ContentElement.
                 * @throws  ArgumentError The specified element contains elements that are specified as the content of a TextBlock.
                 * @throws  ArgumentError The specified element contains elements that are already members of a group, or appear more than once in
                 *   the elements.
                 */
            public:
                GroupElement(std::vector<flash::text::engine::ContentElement *> *elements, ElementFormat *elementFormat, EventDispatcher *eventMirror, std::string textRotation);

                /**
                 * Sets the elements in the group to the contents of the Vector.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  ArgumentError The value specified contains null elements.
                 * @throws  ArgumentError The value specified contains this.
                 * @throws  ArgumentError The value specified contains elements that are not a known subclass of ContentElement .
                 * @throws  ArgumentError The value specified contains elements that are specified as the content of a TextBlock.
                 * @throws  ArgumentError The value specified contains elements that are already members of a group, or appear more than once
                 *   in the value.
                 * @throws  ArgumentError If the operation would result in nested rotations within the GroupElement.
                 */
            public:
                void     setElements(std::vector<flash::text::engine::ContentElement *> *value);

                /**
                 * Replaces the range of elements that the beginIndex and endIndex
                 * parameters specify with a new GroupElement containing those elements.
                 * As designed, the elements from beginIndex to endIndex-1 are replaced.
                 * @param   beginIndex  The zero-based index value for the start position of the range to group.
                 * @param   endIndex    The zero-based index value following the end position of the range to group.
                 * @return  The new group.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError If beginIndex or endIndex is out of range.
                 */
            public:
                flash::text::engine::GroupElement *groupElements(int beginIndex, int endIndex);

                /**
                 * Ungroups the elements in a nested GroupElement that groupIndex specifies within an outer
                 * GroupElement object. After the operation, the ungrouped elements replace the nested GroupElement, which becomes an orphan
                 * with a nullgroup property.
                 * @param   groupIndex  The zero-based index value for the position of the group to be split.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError If groupIndex is out of range.
                 * @throws  ArgumentError If the element at groupIndex is not a GroupElement.
                 */
            public:
                void     ungroupElements(int groupIndex);

                /**
                 * Merges the text from the range of elements that the beginIndex and endIndex
                 * parameters specify into the element specified by beginIndex without affecting the format of that element.
                 * As designed, the text from elements from beginIndex to endIndex-1 are merged.
                 * After their text has been merged, elements from beginIndex+1 to endIndex-1 are removed from the group and orphaned,
                 * with nullgroup properties.
                 * @param   beginIndex  The zero-based index value for the start position of the range to merge.
                 * @param   endIndex    The zero-based index value following the end position of the range to merge.
                 * @return  The first text element in the range, now containing all the text in the range.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError If beginIndex or endIndex is out of range.
                 * @throws  ArgumentError If any of the elements in the specified range is not TextElement.
                 */
            public:
                flash::text::engine::TextElement *mergeTextElements(int beginIndex, int endIndex);

                /**
                 * Splits a TextElement into two, creating a new TextElement at the specified position.
                 * @param   elementIndex    The zero-based index value for the position of the element in the group.
                 * @param   splitIndex  The zero-based index value for the character in the TextElement where the split is to occur.
                 *   The specified character is the first character in the new TextElement.
                 * @return  The new text element containing the latter portion of the original text element.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError If elementIndex or charIndex is out of range.
                 * @throws  ArgumentError If the element at elementIndex is not a TextElement.
                 */
            public:
                flash::text::engine::TextElement *splitTextElement(int elementIndex, int splitIndex);

                /**
                 * Replaces the range of elements that the beginIndex and
                 * endIndex parameters specify with the contents
                 * of the newElements parameter.
                 * The elements from beginIndex to endIndex-1 are replaced.
                 * To delete elements, pass null for newElements.
                 * To insert an element, pass the same value for beginIndex and endIndex.
                 * The new element is inserted before the specified index.
                 * To append an element, pass elementCount for beginIndex and endIndex.After the operation, the replaced elements are orphaned, with nullgroup properties and returned.
                 * @param   beginIndex  The zero-based index value for the start position of the replacement range.
                 * @param   endIndex    The zero-based index value following the end position of the replacement range.
                 * @param   newElements The elements to use to replace the specified range of elements.
                 * @return  A Vector containing the elements that were replaced.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError The beginIndex or endIndex specified is out of range.
                 * @throws  ArgumentError The newElements specified contain null elements.
                 * @throws  ArgumentError The newElements specified contain this.
                 * @throws  ArgumentError The newElements specified contain elements that are not a known subclass of ContentElement .
                 * @throws  ArgumentError The newElements specified contain elements that are specified as the content of a TextBlock.
                 * @throws  ArgumentError The newElements specified contain elements that are already members of a group or appear
                 *   more than once in the elements.
                 * @throws  ArgumentError If the operation would result in nested rotations within the GroupElement.
                 */
            public:
                std::vector<flash::text::engine::ContentElement *> *replaceElements(int beginIndex, int endIndex, std::vector<flash::text::engine::ContentElement *> *newElements);

                /**
                 * Returns the element containing the character specified by the charIndex parameter.
                 * @param   charIndex   The zero-based index value for the character whose element you want to find.
                 *   A value of 0 corresponds to the first character in the group, not the first character in the TextBlock.
                 * @return  The element containing the character at charIndex.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError If charIndex is not in the range of 0 - rawText.length.
                 */
            public:
                flash::text::engine::ContentElement *getElementAtCharIndex(int charIndex);

                /**
                 * Returns the index of the element specified by the element parameter.
                 * @param   element The element in the group whose index you want to retrieve.
                 * @return  The index of the element specified by element, or -1 if the element is not in the group.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                int      getElementIndex(ContentElement *element);
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_GROUPELEMENT_AS
#endif // __cplusplus

