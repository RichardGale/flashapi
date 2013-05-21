#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_TEXTLINE_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_TEXTLINE_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/display/DisplayObjectContainer.h"
namespace flash
{
    namespace text
    {
        namespace engine
        {
            class TextBlock;
        }
    }
}

namespace flash
{
    namespace text
    {
        namespace engine
        {
            class TextLineMirrorRegion;
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
    namespace geom
    {
        class Rectangle;
    }
}
namespace flash
{
    namespace display
    {
        class DisplayObject;
    }
}
namespace flash
{
    namespace ui
    {
        class ContextMenu;
    }
}

/**
 * The TextLine class is used to display text on the display list.
 *
 *   <p class="- topic/p ">You cannot create a TextLine object directly from ActionScript code.
 * If you call <codeph class="+ topic/ph pr-d/codeph ">new TextLine()</codeph>, an exception is thrown.
 * To create a TextLine object, call the <codeph class="+ topic/ph pr-d/codeph ">createTextLine()</codeph> method of a TextBlock.</p><p class="- topic/p ">The TextLine encapsulates the minimum information necessary to render its contents
 * and to provide interactivity through some methods that describe the properties
 * of the atoms of the line.  The term atom refers to both graphic elements and characters (including groups of combining characters),
 * the indivisible entities that make up a text line.</p><p class="- topic/p ">After normal event-dispatching for a text line finishes, if the line is valid, events are mirrored to the event dispatchers that are
 * specified in the <codeph class="+ topic/ph pr-d/codeph ">eventMirror</codeph> properties of the content element objects that contributed to the text line. These objects are recorded in the
 * <codeph class="+ topic/ph pr-d/codeph ">TextLine.mirrorRegions</codeph> property. The events are not mirrored if event propagation failed or was stopped, or if the text line is not valid.</p><p class="- topic/p ">Mirroring of mouse events is a special case.  Because mirror regions aren't actually display objects, <codeph class="+ topic/ph pr-d/codeph ">mouseOver</codeph> and <codeph class="+ topic/ph pr-d/codeph ">mouseOut</codeph>
 * events are simulated for them.  <codeph class="+ topic/ph pr-d/codeph ">rollOver</codeph> and <codeph class="+ topic/ph pr-d/codeph ">rollOut</codeph> events are not simulated.  All naturally occurring
 * <codeph class="+ topic/ph pr-d/codeph ">mouseOver</codeph>, <codeph class="+ topic/ph pr-d/codeph ">mouseOut</codeph>, <codeph class="+ topic/ph pr-d/codeph ">rollOver</codeph> and <codeph class="+ topic/ph pr-d/codeph ">rollOut</codeph> events (whether targeted at the
 * text line or at children of the text line) are ignored - they are not mirrored.</p><p class="- topic/p ">The origin of a text line object is the beginning of the baseline. If you don't set the vertical position (<codeph class="+ topic/ph pr-d/codeph ">y</codeph> property)
 * of a line that contains Latin text on a Roman baseline, only the descenders of the text appear below the top of the Sprite to which
 * you add the text line. See the following diagram:</p><p class="- topic/p "><adobeimage alt="Text baselines" href="../../../images/TextLine.gif" placement="inline" class="+ topic/image adobe-d/adobeimage " /></p><p class="- topic/p ">The TextLine class has several ancestor classes     DisplayObjectContainer, InteractiveObject,
 * DisplayObject, and EventDispatcher     from which it inherits properties and methods.
 * The following inherited properties are inapplicable to TextLine objects: </p><ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">contextMenu</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">focusRect</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">tabChildren</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">tabEnabled</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">tabIndex</codeph></li></ul><p class="- topic/p ">If you try to set these properties, the text engine throws the error: IllegalOperationError. You can read these properties, but they
 * always contain default values.</p>
 *
 *   EXAMPLE:
 *
 *   This example displays various text lines and steps through the atoms in a text
 * block, using <codeph class="+ topic/ph pr-d/codeph ">getAtomBounds()</codeph> to frame each one.
 * <ol class="- topic/ol "><li class="- topic/li ">Add the NumericStepper component to the library.</li><li class="- topic/li ">Save this code as TextLineExample.as in the same directory as your FLA.</li><li class="- topic/li ">Set the Class in the Properties window of the FLA to TextLineExample.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.text.engine.TextBlock;
 * import flash.text.engine.TextElement;
 * import flash.text.engine.TextLine;
 * import flash.text.engine.ElementFormat;
 * import flash.text.engine.FontDescription;
 * import flash.text.engine.FontPosture;
 * import flash.text.engine.FontWeight;
 * import fl.controls.NumericStepper;
 * import flash.events.Event;
 * import flash.geom.Rectangle;
 *
 *   public class TextLineExample extends Sprite {
 *
 *   private var atomStepper:NumericStepper = new NumericStepper();
 * private var atomDataContainer:Sprite;
 * private var fontDescriptionItalic:FontDescription = new FontDescription("Arial", FontWeight.NORMAL, FontPosture.ITALIC);
 * private var fontDescriptionNormal:FontDescription = new FontDescription("Arial", FontWeight.NORMAL , FontPosture.NORMAL);
 * private var textBlock:TextBlock = new TextBlock();
 * private var textLine:TextLine;
 *
 *   public function TextLineExample():void {
 *
 *   var myText:String = "I am a TextElement, created from a String and assigned " +
 * "to the content property of a TextBlock. From the text block, " +
 * "the createTextLine() method created these lines, 300 pixels wide, "  +
 * "for display." ;
 *
 *   atomStepper.minimum = 0;
 * atomStepper.value = 0;
 * atomStepper.width = 50;
 * addChild(atomStepper);
 * atomStepper.x = 20;
 * atomStepper.y = 120;
 * atomStepper.addEventListener(Event.CHANGE, nsChange);
 *
 *   var directions:String = "Click up / down arrows to frame atoms in text block above.";
 *
 *   var formatItalic:ElementFormat = new ElementFormat(fontDescriptionItalic);
 * formatItalic.fontSize = 12;
 * var textElement1:TextElement = new TextElement(directions, formatItalic);
 * textBlock.content = textElement1;
 * createLines(textBlock, 15, 160, 400, this);
 *
 *   var formatNormal:ElementFormat = new ElementFormat(fontDescriptionNormal);
 * formatNormal.fontSize = 16;
 * var textElement2:TextElement = new TextElement(myText, formatNormal);
 * textBlock.content = textElement2;
 * createLines(textBlock, 15.0, 20.0, 300, this);
 * textLine = textBlock.firstLine;
 * atomStepper.maximum = textLine.atomCount - 1;
 * showAtom(textLine, 0);
 * }
 *
 *   private function nsChange(event:Event):void
 * {
 * removeAtom(textLine);
 * if (atomStepper.value == textLine.atomCount - 1)
 * {
 * if(textLine != textBlock.lastLine)
 * {
 * textLine = textLine.nextLine;
 * atomStepper.maximum = textLine.atomCount - 1;
 * atomStepper.value = 0;
 * }
 * }
 * showAtom(textLine, atomStepper.value);
 * }
 *
 *   private function createLines(textBlock, startX, startY, width, container)
 * {
 * var textLine:TextLine = textBlock.createTextLine (null, width);
 * while (textLine)
 * {
 * textLine.x = startX;
 * textLine.y = startY;
 * startY += textLine.height + 2;
 * container.addChild(textLine);
 * textLine = textBlock.createTextLine (textLine, width);
 * }
 * }
 *
 *   private function showAtom(textLine, i):void
 * {
 * var box:Sprite = new Sprite();
 * var mcGraphics = box.graphics;
 * var bounds:Rectangle = textLine.getAtomBounds(i);
 * mcGraphics.lineStyle(1, 0xFF0000, 1.0);
 * mcGraphics.drawRect(bounds.left, bounds.top, bounds.width, bounds.height);
 * textLine.userData = textLine.addChild(box);
 * displayAtomData(textLine,i);
 * }
 *
 *   private function displayAtomData(textLine, i)
 * {
 * if(atomDataContainer != null)
 * removeChild(atomDataContainer);
 * atomDataContainer=new Sprite();
 * var format = new ElementFormat(fontDescriptionNormal);
 * format.color = 0x00000FF;
 * var n:int = 0;
 * var nxtY:Number = 0;
 * var atomInfo:String = "value of getAtomBidiLevel() is: " + textLine.getAtomBidiLevel(i)+"\n"
 * +"value of getAtomCenter() is: " + textLine.getAtomCenter(i)+"\n"
 * +"value of getAtomIndexAtCharIndex() is: " + textLine.getAtomIndexAtCharIndex(i)+"\n"
 * +"value of getAtomTextBlockBeginIndex() is: " + textLine.getAtomTextBlockBeginIndex(i)+"\n"
 * +"value of getAtomTextBlockEndIndex() is: " + textLine.getAtomTextBlockEndIndex(i)+"\n"
 * +"value of getAtomTextRotation() is: " + textLine.getAtomTextRotation(i)+"\n";
 * var atomtextBlock:TextBlock = new TextBlock();
 * var textElement3:TextElement = new TextElement(atomInfo, format);
 * atomtextBlock.content = textElement3;
 * createLines(atomtextBlock,20,200,500, atomDataContainer)
 * addChild(atomDataContainer);
 * }
 *
 *   private function removeAtom(textLine):void
 * {
 * textLine.removeChild(textLine.userData);
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 * @playerversion   Lite 4
 */

using namespace flash::display;
using namespace flash::events;
using namespace flash::geom;
using namespace flash::text::engine;
using namespace flash::ui;

namespace flash
{
    namespace text
    {
        namespace engine
        {
            class TextLine : public flash::display::DisplayObjectContainer
            {
                /**
                 * The maximum requested width of a text line, in pixels. The TextBlock.createTextLine() method uses this constant
                 * as the default value for the width parameter, if you do not specify a value.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                static const int MAX_LINE_WIDTH;

                /**
                 * Provides a way for the application to associate arbitrary data with the text line.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                void *userData;

            public:
                void         focusRect(Object *focusRect);

            public:
                void         tabChildren(bool enable);

            public:
                void         tabEnabled(bool enabled);

            public:
                void         tabIndex(int index);

                /**
                 * The TextBlock containing this text line, or null if the validity of the line is TextLineValidity.STATIC,
                 * meaning that the connection between the line and the TextBlock has been severed.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                flash::text::engine::TextBlock *textBlock();

                /**
                 * Indicates whether the text line contains any graphic elements.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                bool         hasGraphicElement();

                /**
                 * Indicates whether the text line contains any tabs.
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 */
            public:
                bool         hasTabs();

                /**
                 * The next TextLine in the TextBlock, or null if the current line is the last line in the block
                 * or the validity of the line is TextLineValidity.STATIC.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                flash::text::engine::TextLine *nextLine();

                /**
                 * The previous TextLine in the TextBlock, or null if the line is the first line in the block
                 * or the validity of the line is TextLineValidity.STATIC.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                flash::text::engine::TextLine *previousLine();

                /**
                 * Specifies the number of pixels from the baseline to the top of the tallest characters in the line. For a TextLine that contains only a
                 * graphic element, ascent is set to 0.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float        ascent();

                /**
                 * Specifies the number of pixels from the baseline to the bottom of the lowest-descending characters in the line. For a TextLine that
                 * contains only a graphic element, descent is set to 0.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float        descent();

                /**
                 * The logical height of the text line, which is equal to ascent + descent.
                 * To get the inked height, access the inherited height property.
                 *
                 *   The value is calculated based on the difference between the baselines that bound the line,
                 * either ideo top/bottom or ascent/descent depending on whether TextBlock.baselineZero is ideo or not.
                 * Graphic elements are not considered when computing these baselines.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float        textHeight();

                /**
                 * The logical width of the text line, which is the width that the text engine uses to lay out the line. Access the inherited
                 * width property to get the actual width of the bounding box of all the drawn pixels.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float        textWidth();

                /**
                 * Specifies the number of pixels from the baseline to the top of the tallest character or graphic in the line.
                 * @langversion 3.0
                 * @playerversion   Flash 10.2
                 */
            public:
                float        totalAscent();

                /**
                 * Specifies the number of pixels from the baseline to the bottom of the lowest-descending character or graphic in the line.
                 * @langversion 3.0
                 * @playerversion   Flash 10.2
                 */
            public:
                float        totalDescent();

                /**
                 * The total logical height of the text line, which is equal to totalAscent + totalDescent.
                 * @langversion 3.0
                 * @playerversion   Flash 10.2
                 */
            public:
                float        totalHeight();

                /**
                 * The index of the first character of the line in the raw text of the text block.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                int          textBlockBeginIndex();

                /**
                 * The length of the raw text in the text block that became the line,
                 * including the U+FDEF characters representing graphic elements
                 * and any trailing spaces, which are part of the line but not are displayed.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                int          rawTextLength();

                /**
                 * The width that was specified to the TextBlock.createTextLine() method when it created the line.
                 * This value is useful when deciding if a change requires rebreaking the line.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float        specifiedWidth();

                /**
                 * The width of the line if it was not justified. For unjustified text, this value is the same as textWidth. For
                 * justified text, this value is what the length would have been without justification, and textWidth represents
                 * the actual line width. For example, when the following String is justified and submitted to TextBlock.createTextLine()
                 * with a width of 500, it has an actual width of 500 but an unjustified width of 268.9921875.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                float        unjustifiedTextWidth();

                /**
                 * Specifies the current validity of the text line.
                 * Values for this property are found in the members of the
                 * TextLineValidity class.
                 * The rules for setting this property are as follows:
                 *
                 *   A line is considered USER_INVALID if validity is set to any string which is not a member of TextLineValidity.
                 * USER_INVALID is an abstraction used here to represent any such value.When the contents of the TextBlock are modified, the Flash runtime marks affected text lines, the previous line, and all following lines as INVALID.
                 * The previous line must be marked invalid when a change allows the previous line to absorb part of the content that was
                 * originally on the first affected line.Newly broken lines are always VALID. The Flash runtime may change lines that follow from VALID to POSSIBLY_INVALID or INVALID.
                 * It may change POSSIBLY_INVALID lines to VALID if the line breaks match up, or to INVALID if they don't.Application code can mark VALID lines as INVALID or USER_INVALID, and can mark USER_INVALID lines as VALID. Application code cannot mark lines POSSIBLY_INVALID.Application code can mark any line STATIC.  Doing so causes the block member to become null.
                 * Any graphic elements in a STATIC text line are removed and reparented if they are part of a new text line broken
                 * from the text block from which the STATIC text line originally derived.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  ArgumentError If current value is TextLineValidity.STATIC.
                 * @throws  ArgumentError If current value is TextLineValidity.INVALID and new value is anything other than
                 *   TextValidity.STATIC.
                 * @throws  ArgumentError If current value is TextLineValidity.POSSIBLY_INVALID and new value is
                 *   TextLineValidity.VALID.
                 * @throws  ArgumentError If new value is TextLineValidity.POSSIBLY_INVALID.
                 */
            public:
                std::string  validity();
            public:
                void         validity(std::string value);

                /**
                 * The number of atoms in the line, which is the number of indivisible elements, including spaces and graphic
                 * elements.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  IllegalOperationError The validity of the line is TextLineValidity.STATIC.
                 */
            public:
                int          atomCount();

                /**
                 * A Vector containing the TextLineMirrorRegion objects associated with the line, or null if none exist.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                std::vector<flash::text::engine::TextLineMirrorRegion *> mirrorRegions();

            public:
                void         contextMenu(ContextMenu *value);

            public:
                TextLine();

                /**
                 * Returns the first TextLineMirrorRegion on the line whose mirror property matches
                 * that specified by the mirror parameter, or null if no match exists.
                 * Even a single TextElement can produce multiple TextLineMirrorRegion
                 * objects on one or more lines, depending on bidirectional level and line breaking. The nextRegion and
                 * previousRegion properties link all the mirror regions generated from one text element.
                 * @param   mirror  The EventDispatcher mirror object to search for.
                 * @return  The first TextLineMirrorRegion on the line whose mirror property matches
                 *   the specified value, or null if no match exists.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                flash::text::engine::TextLineMirrorRegion *getMirrorRegion(EventDispatcher *mirror);

                /**
                 * This method is deprecated and has no effect.  Atom data is compressed and is not a factor in managing memory efficiency.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                void     flushAtomData();

                /**
                 * Returns the index of the atom at the point specified by the x
                 * and y parameters, or -1 if no atom exists at that point.
                 *
                 *   This method takes global coordinates so that you can easily use it with MouseEvent.stageX
                 * and MouseEvent.stageY properties.
                 * @param   stageX  The global x coordinate of the point to test.
                 * @param   stageY  The global y coordinate of the point to test.
                 * @return  The index of the atom under the point.  Returns -1 if the point is not over any atom.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  IllegalOperationError The validity of the line is TextLineValidity.STATIC.
                 */
            public:
                int      getAtomIndexAtPoint(float stageX, float stageY);

                /**
                 * Returns the index of the atom containing the character specified by the charIndex parameter,
                 * or -1 if the character does not contribute to any atom in the line.
                 * The charIndex is relative to the entire contents of the text block containing the line.
                 * @param   charIndex   The zero-based index value of the character (for example, the first character is 0,
                 *   the second character is 1, and so on).
                 * @return  The index of the atom containing the character at charIndex.
                 *   Returns -1 if the character does not contribute to any atom in the line.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  IllegalOperationError The validity of the line is TextLineValidity.STATIC.
                 */
            public:
                int      getAtomIndexAtCharIndex(int charIndex);

                /**
                 * Gets the bounds of the atom at the specified index relative to the text line. The bounds of the specified atom consist of
                 * its horizontal position (x) in the line, its vertical position in the line (y), its width (w),
                 * and its height (h). All values are in pixels.
                 * @param   atomIndex   The zero-based index value of the atom (for example, the first atom is 0,
                 *   the second atom is 1, and so on).
                 * @return  The bounds of the atom at atomIndex.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError The atom index specified is out of range.
                 * @throws  IllegalOperationError The validity of the line is TextLineValidity.STATIC.
                 */
            public:
                flash::geom::Rectangle *getAtomBounds(int atomIndex);

                /**
                 * Gets the bidirectional level of the atom at the specified index. Determined by a combination of
                 * TextBlock.bidiLevel and the Unicode bidirectional properties of the characters that
                 * form the line.
                 *
                 *   For example, if you start a text block with some Hebrew text, you set TextBlock.bidiLevel to 1, establishing
                 * a default of right to left.  If within the text you have a quote in English (left to right), that text has an AtomBidiLevel of
                 * 2. If within the English you have  a bit of Arabic (right to left), AtomBidiLevel for that run goes to 3.  If within the
                 * Arabic a number (left to right) occurs, the AtomBidiLevel setting for the number is 4. It does not matter in which line the
                 * atoms end up; the Hebrew atoms are AtomBidiLevel 1, the English atoms are AtomBidiLevel 2, Arabic atoms
                 * are AtomBidiLevel 3, and the number atoms are AtomBidiLevel 4.
                 * @param   atomIndex   The zero-based index value of the atom (for example, the first atom is 0,
                 *   the second atom is 1, and so on).
                 * @return  The bidirectional level of the atom at atomIndex.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError The specified atom index is out of range.
                 * @throws  IllegalOperationError The validity of the line is TextLineValidity.STATIC.
                 */
            public:
                int      getAtomBidiLevel(int atomIndex);

                /**
                 * Gets the rotation of the atom at the specified index.  TextRotation constants are used for this property.
                 * The rotation of the atom is the cumulative rotations of the element and the line.  Its primary use is for
                 * setting the orientation of the caret (cursor) when interacting with a TextLine.
                 * @param   atomIndex   The zero-based index value of the atom (for example, the first atom is 0,
                 *   the second atom is 1, and so on).
                 * @return  The rotation of the atom at atomIndex.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError The specified atom index is out of range.
                 * @throws  IllegalOperationError The validity of the line is TextLineValidity.STATIC.
                 */
            public:
                std::string getAtomTextRotation(int atomIndex);

                /**
                 * Gets the text block begin index of the atom at the specified index.
                 * @param   atomIndex   The zero-based index value of the atom (for example, the first atom is 0,
                 *   the second atom is 1, and so on).
                 * @return  The text block begin index of the atom at atomIndex.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError The atom index specified is out of range.
                 * @throws  IllegalOperationError The validity of the line is TextLineValidity.STATIC.
                 */
            public:
                int      getAtomTextBlockBeginIndex(int atomIndex);

                /**
                 * Gets the text block end index of the atom at the specified index.
                 * @param   atomIndex   The zero-based index value of the atom (for example, the first atom is 0,
                 *   the second atom is 1, and so on).
                 * @return  The text block end index of the atom at atomIndex.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError The atom index specified is out of range.
                 * @throws  IllegalOperationError The validity of the line is TextLineValidity.STATIC.
                 */
            public:
                int      getAtomTextBlockEndIndex(int atomIndex);

                /**
                 * Gets the center of the atom as measured along the baseline at the specified index.
                 * @param   atomIndex   The zero-based index value of the atom (for example, the first atom is 0,
                 *   the second atom is 1, and so on).
                 * @return  The center of the atom at atomIndex.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError The atom index specified is out of range.
                 * @throws  IllegalOperationError The validity of the line is TextLineValidity.STATIC.
                 */
            public:
                float    getAtomCenter(int atomIndex);

                /**
                 * Indicates whether a word boundary occurs to the left of the atom at the specified index.
                 * Word boundaries are determined based on the Unicode properties of the characters which contributed to the line.
                 * @param   atomIndex   The zero-based index value of the atom (for example, the first atom is 0,
                 *   the second atom is 1, and so on).
                 * @return  A Boolean value that indicates whether a word boundary occurs to the left of the atom at atomIndex.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError The atom index specified is out of range.
                 * @throws  IllegalOperationError The validity of the line is TextLineValidity.STATIC.
                 */
            public:
                bool     getAtomWordBoundaryOnLeft(int atomIndex);

                /**
                 * Gets the graphic of the atom at the specified index, or null if the atom is a character.
                 * @param   atomIndex   The zero-based index value of the atom (for example, the first atom is 0,
                 *   the second atom is 1, and so on).
                 * @return  The graphic of the atom at atomIndex.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  RangeError The atom index specified is out of range.
                 * @throws  IllegalOperationError The validity of the line is TextLineValidity.STATIC.
                 */
            public:
                flash::display::DisplayObject *getAtomGraphic(int atomIndex);

                /**
                 * Gets the position of the specified baseline, relative to TextBlock.baselineZero.
                 * @param   baseline    The baseline for which to retrieve the position.  Use TextBaseline values.
                 * @return  The position of the specified baseline relative to TextBlock.baselineZero.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  ArgumentError If the baseline specified is not a member of TextBaseline.
                 */
            public:
                float    getBaselinePosition(std::string baseline);

                /**
                 * Dumps the underlying contents of the TextLine as an XML string.
                 * This can be useful in automated testing, and includes text, formatting, and layout information.
                 *
                 *   The following describes the output:
                 * [LINE]
                 * <line ascent=[Number] descent=[Number] rotation=[int]>
                 * <elements>
                 * [0-N ELEMENT]
                 * </elements>
                 * <clusters>
                 * [0-N CLUSTER]
                 * </clusters>
                 * </line>
                 *
                 *   [ELEMENT]
                 * <glyph isEmbedded=[Boolean] fontName=[String] isBold=[Boolean] isItalic=[Boolean] gid=[int] pointSize=[Number] x=[Number] y=[Number] rotation=[int]/>
                 * or
                 * <graphic child=[int] x=[Number] y=[Number] rotation=[int]/>
                 * or
                 * <embeddedRun x=[Number] y=[Number]>
                 * [LINE]
                 * </embeddedRun>
                 *
                 *   [CLUSTER]
                 * <cluster xLeft=[Number] xCenter=[Number] xRight=[Number] cursorOnLeft=[Boolean] cursorOnRight=[Boolean] wordBoundaryOnLeft=[Boolean] wordBoundaryOnRight=[Boolean]/>
                 * Note: The content and format of the output from this method could change in the future. Adobe does not guarantee backward
                 * compatibility for this method.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 */
            public:
                std::string dump();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_TEXTLINE_AS
#endif // __cplusplus

