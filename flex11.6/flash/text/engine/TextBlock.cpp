

#include "TextBlock.h"
#include "flash/text/engine/FontDescription.h"
#include "flash/text/engine/ContentElement.h"
#include "flash/text/engine/TextLine.h"
#include "flash/text/engine/TextJustifier.h"
#include "flash/text/engine/TabStop.h"

    /**
     * The TextBlock class is a factory for the creation of TextLine objects, which you can 
     * render by placing them on the display list.
     * 
     *   <p class="- topic/p ">The TextBlock class is intended to contain a single paragraph because the Unicode 
     * bidirectional and line-break algorithms operate on one paragraph at a time. For applications 
     * that compose multiple paragraphs of text, use a markup language, or text analysis to 
     * divide the text into paragraphs and create one TextBlock per paragraph.</p><p class="- topic/p ">The TextBlock object stores its content in the <codeph class="+ topic/ph pr-d/codeph ">content</codeph> property, which is an
     * instance of the ContentElement class.  Because you can't create an instance of the ContentElement
     * class, set <codeph class="+ topic/ph pr-d/codeph ">content</codeph> to an instance of one of its subclasses: TextElement,
     * GraphicElement, or GroupElement. Use TextElement for purely text content, GraphicElement for
     * an image or graphic content, and GroupElement for content that contains a combination of TextElement,  
     * GraphicElement, and other GroupElement objects. See the ContentElement class and
     * its subclasses for details on managing formatted runs of text, embedded sub-runs, and graphic elements.</p><p class="- topic/p ">After you create the TextBlock instance and set the <codeph class="+ topic/ph pr-d/codeph ">content</codeph> property, call the
     * <codeph class="+ topic/ph pr-d/codeph ">createTextLine()</codeph> method to create lines of text, which are instances of the <codeph class="+ topic/ph pr-d/codeph ">TextLine</codeph> class. </p>
     * 
     *   EXAMPLE:
     * 
     *   This example displays three TextBlock paragraphs of Japanese and English
     * text. The Japanese text is converted to Strings from Unicode character codes. 
     * When you click on the button, the example rotates the text from horizontal to
     * vertical or from veritcal to horizontal.
     * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package { 
     * import fl.controls.Button;
     * import flash.text.engine.TextBlock;
     * import flash.text.engine.TextLine;
     * import flash.text.engine.TextElement;
     * import flash.text.engine.ElementFormat;
     * import flash.text.engine.TextRotation;
     * import flash.text.engine.TextBaseline;
     * import flash.text.engine.LineJustification;
     * import flash.text.engine.FontDescription;
     * import flash.text.engine.EastAsianJustifier; 
     * import flash.display.Loader;
     * import flash.display.Sprite;
     * import flash.display.Stage;
     * import flash.events.MouseEvent;
     * import flash.system.Capabilities;
     * 
     *   public class TextBlockExample extends Sprite {
     * 
     *   var vertical:Boolean;    
     * var container:Sprite;
     * var textBlocks:Vector.&lt;TextBlock&gt;;
     * var loader:Loader = new Loader();
     * var directionButton:Button = new Button();
     * 
     *   public function TextBlockExample():void {
     * addChild(directionButton);
     * directionButton.width = 30;
     * directionButton.move(50, 350);
     * directionButton.addEventListener(MouseEvent.CLICK, clickHandler);
     * createContent();
     * createLines();
     * }
     * 
     *   private function createEmptyBlock():TextBlock {
     * 
     *   var textBlock:TextBlock = new TextBlock();
     * textBlock.baselineZero = TextBaseline.IDEOGRAPHIC_CENTER;
     * textBlock.textJustifier = new EastAsianJustifier("ja", LineJustification.ALL_BUT_LAST);
     * textBlock.lineRotation = vertical? TextRotation.ROTATE_90: TextRotation.ROTATE_0;
     * return textBlock;    
     * }
     * 
     *   private function paragraph1(format:ElementFormat):TextBlock {
     * 
     *   var textBlock:TextBlock = createEmptyBlock();
     * textBlock.content = new TextElement(
     * String.fromCharCode(
     * 0x5185, 0x95A3, 0x5E9C, 0x304C, 0x300C, 0x653F, 0x5E9C, 0x30A4,
     * 0x30F3, 0x30BF, 0x30FC, 0x30CD, 0x30C3, 0x30C8, 0x30C6, 0x30EC, 
     * 0x30D3, 0x300D, 0x306E, 0x52D5, 0x753B, 0x914D, 0x4FE1, 0x5411, 
     * 0x3051, 0x306B, 0x30A2, 0x30C9, 0x30D3, 0x30B7, 0x30B9, 0x30C6, 
     * 0x30E0, 0x30BA, 0x793E, 0x306E
     * ) +
     * "FMS 2" +
     * String.fromCharCode(0x3092, 0x63A1, 0x7528, 0x3059, 0x308B, 0x3068, 
     * 0x767a, 0x8868, 0x3057, 0x307e, 0x3057, 0x305F, 0x3002), format);
     * return textBlock;
     * }
     * 
     *   private function paragraph2(format:ElementFormat):TextBlock {
     * 
     *   var textBlock:TextBlock = createEmptyBlock();
     * textBlock.content = new TextElement(
     * String.fromCharCode(
     * 0x30AF, 0x30ED, 0x30B9, 0x30D7, 0x30E9, 0x30C3, 0x30C8, 0x30D5, 
     * 0x30A9, 0x30FC, 0x30E0, 0x4E0A, 0x3067, 0x518D, 0x751F, 0x53EF, 
     * 0x80FD, 0x306A
     * ) + 
     * "Flash Video" +
     * String.fromCharCode(
     * 0x3092, 0x914D, 0x4FE1, 0x3001, 0x653F, 0x5E9C, 0x6700, 0x65B0, 
     * 0x60C5, 0x5831, 0x3092, 0x3088, 0x308A, 0x591A, 0x304F, 0x306E, 
     * 0x56FD, 0x6C11, 0x306B, 0x9AD8, 0x54C1, 0x8CEA, 0x306A, 0x753B, 
     * 0x50CF, 0x3067, 0x7C21, 0x5358, 0x304B, 0x3064, 0x30EA, 0x30A2, 
     * 0x30EB, 0x30BF, 0x30A4, 0x30E0, 0x306B, 0x63D0, 0x4F9B, 0x3059, 
     * 0x308B, 0x3053, 0x3068, 0x304C, 0x53EF, 0x80FD, 0x306B, 0x306A, 
     * 0x308A, 0x307e, 0x3057, 0x305F, 0x3002), format);
     * return textBlock;    
     * }
     * 
     *   private function paragraph3(format:ElementFormat):TextBlock {
     * 
     *   var textBlock:TextBlock = createEmptyBlock();
     * textBlock.content = new TextElement(
     * String.fromCharCode(0x3010) +
     * "2007" +
     * String.fromCharCode(0x5E74) + "2" + String.fromCharCode(0x6708) +
     * "21" +
     * String.fromCharCode(0x65E5, 0x3011),
     * format);
     * return textBlock;    
     * }
     * 
     *   private function createContent():void {
     * 
     *   var font:FontDescription = new FontDescription();
     * if (Capabilities.os.search("Mac OS") &gt; -1) 
     * font.fontName = String.fromCharCode(0x5C0F, 0x585A, 0x660E, 0x671D) + " Pro R"; // "Kozuka Mincho Pro R"                    koFont.fontName = "Adobe " + String.fromCharCode(0xBA85, 0xC870) + " Std M"; // "Adobe Myungjo Std M"
     * else 
     * font.fontName = "Kozuka Mincho Pro R";        
     * var format:ElementFormat = new ElementFormat();
     * format.fontDescription = font;
     * format.fontSize = 12;
     * format.locale = "ja";
     * format.color = 0x000000;
     * if (!vertical) 
     * format.textRotation = TextRotation.ROTATE_0; 
     * textBlocks = new Vector.&lt;TextBlock&gt;();
     * textBlocks.push(
     * paragraph1(format),
     * paragraph2(format),
     * paragraph3(format)//,
     * );
     * }
     * 
     *   private function createLines():void {
     * 
     *   if (container != null) {
     * removeChild(container);
     * }            
     * container = new Sprite();
     * container.y = 45;
     * container.x = 40;
     * addChild(container);
     * var linePosition:Number = vertical? this.stage.stageWidth - 120: 12;
     * 
     *   for (var i:uint = 0; i &lt; textBlocks.length; i++) {
     * var textBlock:TextBlock = textBlocks[i];
     * var previousLine:TextLine = null;
     * 
     *   while (true) {
     * var textLine:TextLine = textBlock.createTextLine(
     * previousLine, 
     * 300);
     * if (textLine == null) 
     * break;
     * if (vertical) 
     * {
     * textLine.x = linePosition;
     * linePosition -= 24;
     * directionButton.label = " -- ";
     * }
     * else 
     * {
     * textLine.y = linePosition+50;
     * linePosition += 24;
     * directionButton.label = " | ";
     * }
     * container.addChild(textLine);                
     * previousLine = textLine;
     * }
     * if (vertical) 
     * linePosition -= 16;
     * else 
     * linePosition += 16; 
     * }
     * }
     * 
     *   private function clickHandler(event:MouseEvent):void {
     * 
     *   vertical = !vertical;
     * createContent();
     * createLines();
     * }
     * }
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */

using namespace flash::text::engine;

namespace flash {
namespace text {
namespace engine {


        /**
         * Provides a way for the application to associate arbitrary data with the text block. The data could be information that refers to the content, 
         * such as a revision date or the name of the author, or it could be cached data that you use during processing.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
                   

        /**
         * Specifies that you want to enhance screen appearance at the expense of what-you-see-is-what-you-get (WYSIWYG) print fidelity.
         * For platforms and fonts that do not support sub pixel glyph positioning during device font rendering, but 
         * do support non-linear scaling, setting this property to true enables the use of those metrics at some cost to
         * WYSIWYG print fidelity, particularly for small point sizes.  Non linear font scaling works by selectivly scaling the width 
         * of individual glyphs to conceal unsightly gaps caused by pixel snapping.
         * 
         *   On platforms which do support sub-pixel glyph positioning, this flag is ignored.This flag has no effect on embedded font renderingThe default value is true.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        bool TextBlock::applyNonLinearFontScaling()          ;
        void TextBlock::applyNonLinearFontScaling(bool value)       ;

        /**
         * The font used to determine the baselines for all the lines created from the block, independent of their content.  Baselines depend on font and font size.
         * 
         *   The default value is null.  When the baseline font is null, the baseline font size is ignored and 
         * the baseline for any given line is based on the font and size of the largest text in the line.  When you specify both 
         * baselineFontDescription and baselineFontSize, they determine the baselines for all the lines 
         * in the text block, independent of their content. This combination is most often useful in Asian typography.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        flash::text::engine::FontDescription* TextBlock::baselineFontDescription()                                    ;
        void TextBlock::baselineFontDescription(FontDescription* value)       ;

        /**
         * The font size used to calculate the baselines for the lines created from the block.  Baselines depend on font and font size.
         * 
         *   The default value is 12.  When the baseline font is null, the baseline font size is ignored and 
         * the baseline for any given line is based on the font and size of the largest text in the line.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError The baselineFontSize specified is less than 0.
         */
        float TextBlock::baselineFontSize()         ;
        void TextBlock::baselineFontSize(float value)       ;

        /**
         * Specifies which baseline is at y=0 for lines created from this block.
         * Valid values for this property are found in the members of the 
         * TextBaseline class.
         * 
         *   The default value is TextBaseline.ROMAN.To set values for this property, use the following string values:String valueDescriptionTextBaseline.ROMANThe roman baseline of the lines is at y=0.TextBaseline.ASCENTThe ascent baseline of the lines is at y=0.TextBaseline.DESCENTThe descent baseline of the lines is at y=0.TextBaseline.IDEOGRAPHIC_TOPThe ideographic top baseline of the lines is at y=0.TextBaseline.IDEOGRAPHIC_CENTERThe ideographic center baseline of the lines is at y=0.TextBaseline.IDEOGRAPHIC_BOTTOMThe ideographic bottom baseline of the lines is at y=0.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to any value which is not a member of TextBaseline.
         */
        std::string TextBlock::baselineZero()         ;
        void TextBlock::baselineZero(std::string value)       ;

        /**
         * Holds the contents of the text block. Because ContentElement is a base class, assign content
         * an instance of a ContentElement subclass: TextElement, GraphicElement, or GroupElement. A TextElement object 
         * contains a String, a GraphicElement object contains a DisplayObject, and a GroupElement contains a Vector object that 
         * contains one or more TextElement, GraphicElement, or other GroupElement objects. Use a TextElement for a 
         * paragraph of homogenous text, a GraphicElement for a graphic, and a GroupElement for a combination of text and graphic 
         * elements or multiples instances of these elements, as well as other GroupElement objects.
         * 
         *   The default value is null.Modifying the content property changes the validity of all previously created lines to 
         * TextLineValidity.INVALID. After changing content, the firstInvalidLine property  
         * equals the firstLine property and you must rebreak all lines in the TextBlock.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to a value which is not a known subclass of ContentElement.
         * @throws  ArgumentError The value specified is already a member of a group.
         */
        flash::text::engine::ContentElement* TextBlock::content()                                   ;
        void TextBlock::content(ContentElement* value)       ;

        /**
         * Specifies the default bidirectional embedding level of the text in the text block.
         * An even value means left-to-right and an odd value means right-to-left.  You can increment bidiLevel to  
         * indicate the number of levels by which particular text is embedded with respect to left-to-right 
         * and right-to-left.
         * 
         *   The default value is 0.Modifying bidiLevel changes the validity of all previously broken lines to TextLineValidity.INVALID. After 
         * changing bidiLevel, the firstInvalidLine property equals the firstLine property, and you must 
         * rebreak all the lines in the TextBlock.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to a value which is less than 0.
         */
        int TextBlock::bidiLevel()      ;
        void TextBlock::bidiLevel(int value)       ;

        /**
         * Identifies the first line in the text block in which TextLine.validity is not equal to 
         * TextLineValidity.VALID.
         * 
         *   The default value is null.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        flash::text::engine::TextLine* TextBlock::firstInvalidLine()                             ;

        /**
         * The first TextLine in the TextBlock, if any.
         * 
         *   The default value is null.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        flash::text::engine::TextLine* TextBlock::firstLine()                             ;

        /**
         * The last TextLine in the TextBlock, if any.
         * 
         *   The default value is null.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        flash::text::engine::TextLine* TextBlock::lastLine()                             ;

        /**
         * Specifies the TextJustifier to use during line creation.
         * 
         *   The default value is a constructed default TextJustifier object.When the textJustifier property is set, the TextBlock makes a copy of the object for internal use.  
         * Modifying the original object does not affect the TextBlock.  When the textJustifier property is queried, a copy 
         * of the internal object is returned.  Again, modifying this returned object does not affect the TextBlock.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to a value which is not a known subclass of TextJustifier.
         */
        flash::text::engine::TextJustifier* TextBlock::textJustifier()                                  ;
        void TextBlock::textJustifier(TextJustifier* value)       ;

        /**
         * Indicates the result of a createTextLine() operation.  
         * Changing the content of the block invalidates previously broken lines and resets
         * this property to null.
         * 
         *   The default value is null.Values for this property are found in TextLineCreationResultString valueDescriptionTextLineCreationResult.SUCCESSThe line was successfully broken.TextLineCreationResult.COMPLETEEither the new line created aligned perfectly with following lines which 
         * have transitioned from POSSIBLY_INVALID to VALID, or 
         * no line was created because all text in the block had already been broken.TextLineCreationResult.INSUFFICIENT_WIDTHNo line was created because no text could fit in the specified width.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        std::string TextBlock::textLineCreationResult()         ;

        /**
         * Rotates the text lines in the text block as a unit. Call the createTextLine() method after
         * setting lineRotation for it to take effect. The default value is TextRotation.ROTATE_0.
         * 
         *   The final rotation of any glyph depends on the values of 
         * ElementFormat.textRotation, ContentElement.textRotation, and TextBlock.lineRotation.TextBlock.lineRotation is typically used for Asian text.
         * To create a paragraph of vertical Japanese text, do the following:Set the TextBlock.lineRotation property to TextRotation.ROTATE_90.Leave the ElementFormat.textRotation property of the content as the default, TextRotation.AUTO.Use the following constants, which are defined in the TextRotation class, to set the 
         * value for this property:String valueDescriptionTextRotation.ROTATE_0Lines are not rotated.TextRotation.ROTATE_90Lines are rotated 90 degrees clockwise.TextRotation.ROTATE_180Lines are rotated 180 degrees.TextRotation.ROTATE_270Lines are rotated 270 degrees clockwise.TextRotation.AUTONot supported.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to any value which is not a member of TextRotation.
         * @throws  ArgumentError If set to TextRotation.AUTO.
         */
        std::string TextBlock::lineRotation()         ;
        void TextBlock::lineRotation(std::string value)       ;

        /**
         * Specifies the tab stops for the text in the text block, 
         * in the form of a Vector of TabStop objects.
         * 
         *   The default value is null, which means no tab stops are specified. When no tab stops are specified (or the insertion point is beyond the last specified tab stop)
         * the runtime creates half-inch tabs by default.When the tabStops property is set, the TextBlock makes a copy of the Vector for internal use.  
         * Modifying the original Vector or its contents does not affect the TextBlock.  When the tabStops property is queried, a copy 
         * of the internal Vector is returned.  Again, modifying this returned vector or its contents does not affect the TextBlock.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError The tabStops specified contain null elements.
         * @throws  ArgumentError The tabStops specified are not sorted by increasing position.
         */
        std::vector<flash::text::engine::TabStop*> TextBlock::tabStops()                                     ;
        void TextBlock::tabStops(std::vector<TabStop*> value)       ;

        /**
         * Creates a TextBlock object
         * @param   content The contents of the text block.
         * @param   tabStops    The tab stops for the text in the text block.
         * @param   textJustifier   The TextJustifier object to use during line creation for this block.
         *   If no justifier is provided, a default justifier is constructed based on an English locale.
         * @param   lineRotation    The rotation applied to the text lines generated from the text block as units.
         * @param   baselineZero    Specifies which baseline is at y=0 for all lines in the block.
         * @param   bidiLevel   The default bidirectional embedding level of the text in the text block.
         * @param   applyNonLinearFontScaling   Specifies that you want to enhance screen appearance at the expense of WYSIWYG print fidelity.
         * @param   baselineFontDescription Specifies a font description from which to derive line baselines for all lines in the block.
         * @param   baselineFontSize    Specifies the size to use with the baselineFontDescription.  
         *   This parameter is ignored if baselineFontDescription is null.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError The content specified is not a known subclass of ContentElement.
         * @throws  ArgumentError The content specified is already a member of a group.
         * @throws  ArgumentError The lineRotation specified is not a member of TextRotation.
         * @throws  ArgumentError The baselineZero specified is not a member of TextBaseline.
         * @throws  ArgumentError The bidiLevel specified is less than 0.
         * @throws  ArgumentError The tabStops specified contain null elements.
         * @throws  ArgumentError The tabStops specified are not sorted by increasing position.
         * @throws  ArgumentError The baselineFontSize specified is less than 0.
         */
        TextBlock::TextBlock(ContentElement* content, std::vector<flash::text::engine::TabStop*> tabStops, TextJustifier* textJustifier, std::string lineRotation, std::string baselineZero, int bidiLevel, bool applyNonLinearFontScaling, FontDescription* baselineFontDescription, float baselineFontSize);

        /**
         * Finds the index of the next atom boundary from the specified character index, not including the character at the specified index.
         * The characters between atom boundaries combine to form one atom in a TextLine, such as an 'e' and a combining acute accent.
         * @param   afterCharIndex  Specifies the index of the character from which to search for the next atom boundary.
         * @return  The index of the next atom boundary from the specified character index.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  RangeError The index specified is out of range.
         * @throws  IllegalOperationError The TextLine to which the indexed character belongs is not valid.
         */
        int TextBlock::findNextAtomBoundary(int afterCharIndex)      ;

        /**
         * Finds the index of the previous atom boundary to the specified character index, not including the character at the specified index.
         * The characters between atom boundaries combine to form one atom in a TextLine, such as an 'e' and a combining acute accent.
         * @param   beforeCharIndex Specifies the index of the character from which to search for the previous atom boundary.
         * @return  The index of the previous atom boundary to the specified character index.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  RangeError The index specified is out of range.
         * @throws  IllegalOperationError The TextLine to which the indexed character belongs is not valid.
         */
        int TextBlock::findPreviousAtomBoundary(int beforeCharIndex)      ;

        /**
         * Finds the index of the next word boundary from the specified character index, not including the character at the specified index.
         * Word boundaries are determined based on the Unicode properties of the characters.
         * @param   afterCharIndex  Specifies the index of the character from which to search for the next word boundary.
         * @return  The index of the next word boundary from the specified character index.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  RangeError The index specified is out of range.
         * @throws  IllegalOperationError The TextLine to which the indexed character belongs is not valid.
         */
        int TextBlock::findNextWordBoundary(int afterCharIndex)      ;

        /**
         * Finds the index of the previous word boundary to the specified character index, not including the character at the specified index.
         * Word boundaries are determined based on the Unicode properties of the characters.
         * @param   beforeCharIndex Specifies the index of the character from which to search for the previous word boundary.
         * @return  The index of the previous word boundary to the specified character index.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  RangeError The index specified is out of range.
         * @throws  IllegalOperationError The TextLine to which the indexed character belongs is not valid.
         */
        int TextBlock::findPreviousWordBoundary(int beforeCharIndex)      ;

        /**
         * Returns the TextLine containing the character specified by the charIndex parameter.
         * @param   charIndex   The zero-based index value of the character (for example, the first character is 0,
         *   the second character is 1, and so on).
         * @return  The TextLine containing the character at charIndex.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  RangeError The character index specified is out of range.
         */
        flash::text::engine::TextLine* TextBlock::getTextLineAtCharIndex(int charIndex)                             ;

        /**
         * Instructs the text block to create a line of text from its content, beginning at the point 
         * specified by the previousLine parameter and breaking at the point specified by the
         * width parameter. The text line is a TextLine object, which you can add 
         * to the display list.
         * 
         *   Breaking lines over a range of a text block that has already been broken can change the validity
         * of lines in and beyond the area where breaking takes place.  The status of lines can change from VALID to INVALID or 
         * POSSIBLY_INVALID.  If a newly broken line aligns perfectly with a previously broken line which has a status
         * of POSSIBLY_INVALID, that previously broken line and all following POSSIBLY_INVALID lines change back
         * to a status of VALID.  The validity of lines that have been set to values that are not members of 
         * TextLineValidity do not change to VALID, but could change to INVALID.
         * Check the firstInvalidLine property after any change to the text block
         * to see where to begin or continue rebreaking text lines.You can create artificial word breaks by including the Unicode Zero Width Space (ZWSP) character in the text.
         * This can be useful for languages such as Thai, which require a dictionary for correct line breaking.
         * The Flash runtime does not include such a dictionary.In order to reduce memory overhead, when all the desired lines have been created, unless it is expected that the 
         * lines will need to be repeatedly rebroken due to, for example, the resizing of the container, the user should call 
         * the releaseLineCreationData() method allowing the text block to dispose of the temporary data associated with line breaking.
         * @param   previousLine    Specifies the previously broken line after which breaking is to commence.  Can be null
         *   when breaking the first line.
         * @param   width   Specifies the desired width of the line in pixels.  The actual width may be less.
         * @param   lineOffset  An optional parameter which specifies the difference in pixels between the origin of the line and the origin of the tab stops.  
         *   This can be used when lines are not aligned, but it is desirable for their tabs to be so.
         *   The default value for this parameter is 0.0.
         * @param   fitSomething    An optional parameter which instructs Flash Player to fit at least one character into the text line, no matter what
         *   width has been specified (even if width is zero or negative, which would otherwise result in an exception being thrown).
         * @return  A text line, or null if the text block is empty or the width specified is less than the width of the next element.
         *   To distinguish between these cases, check the textLineCreationResult property of the text block.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If the TextLine specified by previousLine is not valid.
         * @throws  ArgumentError If the TextLine specified by previousLine is owned by a different TextBlock.
         * @throws  ArgumentError If width is less than zero, unless fitSomething is true.
         * @throws  ArgumentError If width is greater than TextLine.MAX_LINE_WIDTH.
         * @throws  IllegalOperationError If one or more elements in the content of the text block has a null ElementFormat.
         */
        flash::text::engine::TextLine* TextBlock::createTextLine(TextLine* previousLine, float width, float lineOffset, bool fitSomething)                             ;

        /**
         * Instructs the text block to re-use an existing text line to create a line of text from its content, beginning at the point 
         * specified by the previousLine parameter and breaking at the point specified by the
         * width parameter. The text line is a TextLine object, which you can add 
         * to the display list.  By re-using an existing text line, performance is enhanced due to reduced object creation.
         * 
         *   The textLine being recreated is released from whatever text block it is in, if any.
         * In addition, all properties, including inherited properties from DisplayObjectContainer, 
         * InteractiveObject, and DisplayObject are reset to their default values.
         * Finally, all children of the line are removed including graphic elements and other decorations, and all event 
         * listeners on the line are removed.  To improve performance, the only exception to this complete reset is that
         * the line itself is not removed from its parent.Breaking lines over a range of a text block that has already been broken can change the validity
         * of lines in and beyond the area where breaking takes place.  The status of lines can change from VALID to INVALID or 
         * POSSIBLY_INVALID.  If a newly broken line aligns perfectly with a previously broken line which has a status
         * of POSSIBLY_INVALID, that previously broken line and all following POSSIBLY_INVALID lines change back
         * to a status of VALID.  The validity of lines that have been set to values that are not members of 
         * TextLineValidity do not change to VALID, but could change to INVALID.
         * Check the firstInvalidLine property after any change to the text block
         * to see where to begin or continue rebreaking text lines.You can create artificial word breaks by including the Unicode Zero Width Space (ZWSP) character in the text.
         * This can be useful for languages such as Thai, which require a dictionary for correct line breaking.
         * The Flash runtime does not include such a dictionary.In order to reduce memory overhead, when all the desired lines have been created, unless it is expected that the 
         * lines will need to be repeatedly rebroken due to, for example, the resizing of the container, the user should call 
         * the releaseLineCreationData() method allowing the text block to dispose of the temporary data associated with line breaking.
         * @param   textLine    Specifies a previously created TextLine to be re-used.
         * @param   previousLine    Specifies the previously broken line after which breaking is to commence. Can be null
         *   when breaking the first line.
         * @param   width   Specifies the desired width of the line in pixels.  The actual width may be less.
         * @param   lineOffset  An optional parameter which specifies the difference in pixels between the origin of the line and the origin of the tab stops.  
         *   This can be used when lines are not aligned, but it is desirable for their tabs to be so.
         *   The default value for this parameter is 0.0.
         * @param   fitSomething    An optional parameter which instructs Flash Player to fit at least one character into the text line, no matter what
         *   width has been specified (even if width is zero or negative, which would otherwise result in an exception being thrown).
         * @return  A text line, or null if the text block is empty or the width specified is less than the width of the next element.
         *   To distinguish between these cases, check the textLineCreationResult property of the text block.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         * @throws  ArgumentError If textLine is null.
         * @throws  ArgumentError If the TextLine specified by previousLine is not valid.
         * @throws  ArgumentError If the TextLine specified by previousLine is owned by a different TextBlock.
         * @throws  ArgumentError If the TextLine specified by previousLine is also specified by textLine.
         * @throws  ArgumentError If width is less than zero, unless fitSomething is true.
         * @throws  ArgumentError If width is greater than TextLine.MAX_LINE_WIDTH.
         * @throws  IllegalOperationError If one or more elements in the content of the text block has a null ElementFormat.
         */
        flash::text::engine::TextLine* TextBlock::recreateTextLine(TextLine* textLine, TextLine* previousLine, float width, float lineOffset, bool fitSomething)                             ;

        /**
         * Instructs the text block to release all the temporary data associated with the creation of text lines. 
         * To minimize an application's memory foot print, you should call the releaseLineCreationData() method when you are
         * done creating text lines from a text block.  However, to maximize performance for rebreaking the lines
         * (for example when the container is resized) the releaseLineCreationData() method should not be called.
         * It is up to the application to balance memory vs. performance.
         * 
         *   The recommended process for text that is not expected to change is: initialize a text block, 
         * call the createTextLine() method as often as necessary to create the desired output, and then call 
         * the releaseLineCreationData() method.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        void TextBlock::releaseLineCreationData()       ;

        /**
         * Removes a range of text lines from the list of lines maintained by the TextBlock.
         * This allows the lines to be garbage-collected if no other references exist.
         * 
         *   Sets the textBlock, nextLine, and previousLine
         * members of the removed lines to null.
         * Sets the validity of the removed lines and of all lines which follow
         * the removed lines in the TextBlock to TextLineValidity.INVALID.
         * @param   firstLine   Specifies the first line to release.
         * @param   lastLine    Specifies the last line to release.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If the TextLine specified by firstLine or lastLine is not 
         *   in the list of text lines maintained by the text block.
         */
        void TextBlock::releaseLines(TextLine* firstLine, TextLine* lastLine)       ;

        /**
         * Dumps the underlying contents of the TextBlock as an XML string.
         * This can be useful in automated testing, and includes text, formatting, and layout information.
         * 
         *   The following describes the output:
         * >block<
         * [0-N LINE]
         * >/block<
         * For a description of the output for each line, see the TextLine.dump() method.Note: The content and format of the output may change in the future. Adobe does not guarantee backward compatibility
         * of this method.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::string TextBlock::dump()         ;
}
}
}

