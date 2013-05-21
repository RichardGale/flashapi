#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_TEXTLINEMIRRORREGION_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_TEXTLINEMIRRORREGION_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace text
    {
        namespace engine
        {
            class TextLine;
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
namespace flash
{
    namespace text
    {
        namespace engine
        {
            class ContentElement;
        }
    }
}
namespace flash
{
    namespace geom
    {
        class Rectangle;
    }
}

/**
 * The TextLineMirrorRegion class represents a portion of a text line wherein events are mirrored to another event dispatcher.
 *
 *   <p class="- topic/p ">After normal event-dispatching for a text line finishes, if the line is valid and event propagation has not been stopped,
 * events are re dispatched to the mirror regions of the line.</p><p class="- topic/p ">Mirroring of mouse events is a special case.  Because mirror regions aren't actually display objects, <codeph class="+ topic/ph pr-d/codeph ">mouseOver</codeph> and <codeph class="+ topic/ph pr-d/codeph ">mouseOut</codeph>
 * events are simulated for them. The <codeph class="+ topic/ph pr-d/codeph ">rollOver</codeph> and <codeph class="+ topic/ph pr-d/codeph ">rollOut</codeph> events are not simulated.  All naturally occuring
 * <codeph class="+ topic/ph pr-d/codeph ">mouseOver</codeph>, <codeph class="+ topic/ph pr-d/codeph ">mouseOut</codeph>, <codeph class="+ topic/ph pr-d/codeph ">rollOver</codeph> and <codeph class="+ topic/ph pr-d/codeph ">rollOut</codeph> events (whether targetted at the
 * text line or at children of the text line) are ignored - they are not mirrored.</p><p class="- topic/p ">You cannot create a TextLineMirrorRegion object directly from ActionScript code.
 * If you call <codeph class="+ topic/ph pr-d/codeph ">new TextLineMirrorRegion()</codeph>, an exception is thrown. A TextLineMirrorRegion is created and associated with a text line when that
 * text line is created from a ContentElement object with an event mirror set.</p><p class="- topic/p ">The TextLineMirrorRegion class is final; it cannot be subclassed.</p>
 *
 *   EXAMPLE:
 *
 *   This example displays a block of text with mirror regions that turn red when you click
 * them.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 *
 *   import flash.display.Sprite;
 * import flash.text.engine.TextBlock;
 * import flash.text.engine.TextLine;
 * import flash.text.engine.TextElement;
 * import flash.text.engine.ElementFormat;
 * import flash.text.engine.FontDescription;
 * import flash.text.engine.ContentElement;
 * import flash.text.engine.GroupElement;
 * import flash.text.engine.TextLineMirrorRegion;
 * import flash.events.MouseEvent;
 * import flash.events.EventDispatcher;
 * import flash.ui.Mouse;
 *
 *   public class TextLineMirrorRegionExample extends Sprite {
 *
 *   var myEvent:EventDispatcher = new EventDispatcher();
 * var fontDescription:FontDescription = new FontDescription();
 * var textBlock:TextBlock = new TextBlock();
 *
 *   public function TextLineMirrorRegionExample():void {
 *
 *   fontDescription.fontWeight = "bold";
 * var blackFormat:ElementFormat = new ElementFormat();
 * blackFormat.fontSize = 18;
 * blackFormat.color = 0x000000;
 * blackFormat.fontDescription = fontDescription;
 *
 *   var textElement1 = new TextElement("Click on different parts of me to find the ", blackFormat);
 * var textElement2 = new TextElement("mirror regions",blackFormat);
 * var textElement3 = new TextElement(". If I am a mirror region, I'll ",blackFormat);
 * var textElement4 = new TextElement("turn red",blackFormat);
 * var textElement5 = new TextElement(".",blackFormat);
 *
 *   myEvent.addEventListener("click", clickHandler);
 * myEvent.addEventListener("mouseOut", mouseOutHandler);
 * myEvent.addEventListener("mouseOver", mouseOverHandler);
 *
 *   var groupVector:Vector.&lt;ContentElement&gt; = new Vector.&lt;ContentElement&gt;;
 * groupVector.push(textElement1, textElement2, textElement3, textElement4, textElement5);
 * var groupElement:GroupElement = new GroupElement(groupVector);
 *
 *   textElement2.eventMirror=myEvent;
 * textElement4.eventMirror=myEvent;
 *
 *   textBlock.content = groupElement;
 * createLines(textBlock);
 * }
 *
 *   private function clickHandler(event:MouseEvent):void
 * {
 * var redFormat:ElementFormat = new ElementFormat();
 * redFormat.color = 0xCC0000;
 * redFormat.fontSize = 18;
 * redFormat.fontDescription = fontDescription;
 * var line:TextLine = event.target as TextLine;
 * var region:TextLineMirrorRegion = line.getMirrorRegion(myEvent);
 * region.element.elementFormat = redFormat;
 * createLines(textBlock);
 * }
 *
 *   private function mouseOverHandler(event:MouseEvent):void
 * {
 * Mouse.cursor = "button";
 * }
 *
 *   private function mouseOutHandler(event:MouseEvent):void
 * {
 * Mouse.cursor = "arrow";
 * }
 *
 *   private function createLines(textBlock:TextBlock):void
 * {
 * var purgeLine:TextLine = textBlock.firstLine;
 *
 *   while (purgeLine)
 * {
 * removeChild (purgeLine);
 * purgeLine = purgeLine.nextLine;
 * }
 * var lineWidth:Number = 150;
 * var xPos:Number = 15.0;
 * var yPos:Number = 20.0;
 * var textLine:TextLine = textBlock.createTextLine (null, lineWidth);
 *
 *   while (textLine)
 * {
 * textLine.x = xPos;
 * textLine.y = yPos;
 * yPos += textLine.height + 2;
 * addChild (textLine);
 * textLine = textBlock.createTextLine (textLine, lineWidth);
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 * @playerversion   Lite 4
 */

using namespace flash::events;
using namespace flash::geom;
using namespace flash::text::engine;

namespace flash
{
    namespace text
    {
        namespace engine
        {
            class TextLineMirrorRegion : public Object
            {
                /**
                 * The TextLine containing this mirror region.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                flash::text::engine::TextLine *textLine();

                /**
                 * The next TextLineMirrorRegion in the set derived from the text element, or null if the current region is the last mirror region
                 * in the set. May be on the same line or on another text line.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                flash::text::engine::TextLineMirrorRegion *nextRegion();

                /**
                 * The previous TextLineMirrorRegion in the set derived from the text element, or null if the current region is the first mirror
                 * region in the set. May be on the same line or on another text line.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                flash::text::engine::TextLineMirrorRegion *previousRegion();

                /**
                 * The EventDispatcher object to which events affecting the mirror region are mirrored.
                 * This includes mouse events that specifically occur in the mirror region, and all other events
                 * that target the text line.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                flash::events::EventDispatcher *mirror();

                /**
                 * The ContentElement object from which the mirror region was derived.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  IllegalOperationError The TextLine to which this element belongs is not valid.
                 */
            public:
                flash::text::engine::ContentElement *element();

                /**
                 * The bounds of the mirror region, relative to the text line.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                flash::geom::Rectangle *bounds();

            public:
                TextLineMirrorRegion();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_TEXTLINEMIRRORREGION_AS
#endif // __cplusplus

