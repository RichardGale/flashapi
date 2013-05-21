

#include "ElementFormat.h"
#include "flash/text/engine/FontDescription.h"
#include "flash/text/engine/FontMetrics.h"
#include "flash/text/engine/ElementFormat.h"

    /**
     * The ElementFormat class represents formatting information which can be applied to a ContentElement. Use the ElementFormat class
     * to create specific text formatting for the various subclasses of ContentElement. The properties of the ElementFormat class apply to device and
     * embedded fonts.
     * 
     *   <p class="- topic/p ">An ElementFormat object that is applied to a ContentElement in a TextBlock does not invalidate the TextBlock. 
     * Once an ElementFormat has been
     * applied to a ContentElement, its <codeph class="+ topic/ph pr-d/codeph ">locked</codeph> property is set to <codeph class="+ topic/ph pr-d/codeph ">true</codeph>.
     * The properties of a locked ElementFormat object cannot be changed. Instead, use the <codeph class="+ topic/ph pr-d/codeph ">clone()</codeph>
     * method to create an unlocked copy of the object, which can be modified and assigned to the ContentElement.</p>
     * 
     *   EXAMPLE:
     * 
     *   <p class="- topic/p ">This example creates two <codeph class="+ topic/ph pr-d/codeph ">ElementFormat</codeph> objects and sets several of
     * their properties. It then assigns the new ElementFormats to a <codeph class="+ topic/ph pr-d/codeph ">TextElement</codeph> object,
     * which has been assigned as the content of a <codeph class="+ topic/ph pr-d/codeph ">TextBlock</codeph>. Note that changing the
     * <codeph class="+ topic/ph pr-d/codeph ">ElementFormat</codeph> of a <codeph class="+ topic/ph pr-d/codeph ">TextElement</codeph> does not affect TextLines that
     * have been previously created by the parent TextBlock.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * 
     *   package {
     * 
     *   import flash.display.Sprite;
     * import flash.text.engine.*;
     * 
     *   public class ElementFormatExample extends Sprite {
     * 
     *   public function ElementFormatExample():void {
     * var fd:FontDescription = new FontDescription();
     * fd.fontName = "Garamond";
     * fd.fontWeight = flash.text.engine.FontWeight.BOLD;
     * 
     *   var ef1:ElementFormat = new ElementFormat(fd);
     * ef1.fontSize = 30;
     * ef1.color = 0xFF0000;
     * ef1.alpha = 100;
     * ef1.kerning = flash.text.engine.Kerning.ON;
     * ef1.trackingRight = 2;
     * ef1.typographicCase = flash.text.engine.TypographicCase.UPPERCASE;
     * ef1.alignmentBaseline = flash.text.engine.TextBaseline.DESCENT;
     * ef1.ligatureLevel = flash.text.engine.LigatureLevel.EXOTIC;
     * 
     *   var ef2:ElementFormat = new ElementFormat(fd);
     * ef2.fontSize = 30;
     * ef2.color = 0xFF0000;
     * ef2.alpha = 0.3;
     * ef2.kerning = flash.text.engine.Kerning.OFF;
     * ef2.typographicCase = flash.text.engine.TypographicCase.LOWERCASE;
     * ef2.digitCase = flash.text.engine.DigitCase.OLD_STYLE;
     * ef2.textRotation = flash.text.engine.TextRotation.ROTATE_180;
     * 
     *   var str:String = "This is flash text 0123456789";
     * var tb:TextBlock = new TextBlock();
     * var te1:TextElement = new TextElement(str, ef1);
     * tb.content = te1;
     * var line1:TextLine = tb.createTextLine(null, 600);
     * addChild(line1);
     * line1.x = 15;
     * line1.y = 30;
     * 
     *   tb.content.elementFormat = ef2;
     * var line2:TextLine = tb.createTextLine(null, 600);
     * addChild(line2);
     * line2.x = 15;
     * line2.y = 60;
     * 
     *   }
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
         * Specifies the type of baseline in the containing element to which to align the dominant baselines of elements having 
         * this format. Use TextBaseline constants for this property.
         * 
         *   The largest vertical element in the line determines the alignment of baselines unless 
         * TextBlock.baselineFontDescription and TextBlock.baselineFontSize are set to override that logic.The default value is TextBaseline.USE_DOMINANT_BASELINE.To set values for this property, use the following string values:String valueDescriptionTextBaseline.ROMANThe dominantBaseline aligns with the roman baseline of the line.TextBaseline.ASCENTThe dominantBaseline aligns with the ascent baseline of the line.TextBaseline.DESCENTThe dominantBaseline aligns with the descent baseline of the line.TextBaseline.IDEOGRAPHIC_TOPThe dominantBaseline aligns with the ideographic top baseline of the line.TextBaseline.IDEOGRAPHIC_CENTERThe dominantBaseline aligns with the ideographic center baseline of the line.TextBaseline.IDEOGRAPHIC_BOTTOMThe dominantBaseline aligns with the ideographic bottom baseline of the line.TextBaseline.USE_DOMINANT_BASELINEThe dominantBaseline aligns with the same baseline of the line.SubclassEffect of setting propertyGraphicElementSets the alignment baseline of the line to which the dominantBaseline of the graphic element aligns.GroupElementHas no effect.TextElementSets the alignment baseline of the line to which the dominantBaseline of the text element aligns.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to any value which is not a member of TextBaseline.
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        std::string ElementFormat::alignmentBaseline()         ;
        void ElementFormat::alignmentBaseline(std::string alignmentBaseline)       ;

        /**
         * Specifies the transparency of the line elements affected by this obect. Valid values range from 0 (fully transparent) 
         * to 1 (fully opaque). Display objects with alpha set to 0 are active, even though they are invisible.
         * 
         *   The default value is 1.SubclassEffect of setting propertyGraphicElementApplies the specified alpha to the graphic element. Combines
         * multiplicatively with any alpha set on the graphic DisplayObject
         * itself or on the TextLine.GroupElementHas no effect.TextElementApplies the specified alpha to the text element. Combines
         * multiplicatively with any alpha set on the TextLine.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        float ElementFormat::alpha()         ;
        void ElementFormat::alpha(float value)       ;

        /**
         * Indicates the baseline shift for the element in pixels.
         * The element is shifted away from the dominantBaseline by this amount.
         * The offset is added to the y position of the members of the element, so in non-rotated 
         * text, a positive baseline shift moves the element down and a negative baseline shift
         * moves the element up.The default value is 0.0, indicating no shift.SubclassEffect of setting propertyGraphicElementShifts the graphic away from the baseline.GroupElementHas no effect.TextElementShifts the text away from the baseline.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        float ElementFormat::baselineShift()         ;
        void ElementFormat::baselineShift(float value)       ;

        /**
         * The line break opportunity applied to this text. 
         * This property determines which characters can be used for breaking when wrapping text is broken into multiple lines.
         * Use BreakOpportunity
         * constants for this property.
         * 
         *   The default value is BreakOpportunity.AUTO.To set values for this property, use the following string values:String valueDescriptionBreakOpportunity.AUTOLine breaking opportunities are based on standard Unicode character properties, such as breaking between words and on hyphens.BreakOpportunity.ANYAny character in the ContentElement object is treated as a line break opportunity. This value is typically used when Roman text is embedded in Asian text and it is desirable for breaks to happen in the middle of words.BreakOpportunity.NONENo characters in the range are treated as line break opportunities.BreakOpportunity.ALLAll characters in the range are treated as line break opportunities, meaning that a line break will occur 
         * after each character. Useful for creating effects like text on a path.SubclassEffect of setting propertyGraphicElementHas no effect.GroupElementDetermines the break opportunity between adjacent text elements in the group.
         * If the elementFormat of the group is null, the format of the first
         * of the adjacent elements is used.TextElementDetermines the break opportunity between the characters in the text element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to a value not a member of BreakOpportunity.
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        std::string ElementFormat::breakOpportunity()         ;
        void ElementFormat::breakOpportunity(std::string opportunityType)       ;

        /**
         * Indicates the color of the text. An integer containing three 8-bit RGB components; for example,
         * 0xFF0000 is red and 0x00FF00 is green.
         * 
         *   The default value is 0x000000, which is black.SubclassEffect of setting propertyGraphicElementHas no effect.GroupElementHas no effect.TextElementSets the color of the text.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        unsigned int ElementFormat::color()       ;
        void ElementFormat::color(unsigned int value)       ;

        /**
         * Specifies the type of baseline to use as the dominant baseline. The dominant baseline is aligned 
         * with the alignment baseline to determine the vertical position of the element on the line.
         * Use TextBaseline constants for this property.
         * 
         *   The content of the element determines the baselines.
         * In the case of a TextElement, the font and the point size determine the baselines.
         * In the case of a GraphicElement, the height of the element determines the baselines.The default value is TextBaseline.ROMAN.To set values for this property, use the following string values:String valueDescriptionTextBaseline.ROMANThe roman baseline of the element aligns with the alignmentBaseline.TextBaseline.ASCENTThe ascent baseline of the element aligns with the alignmentBaseline.TextBaseline.DESCENTThe descent baseline of the element aligns with the alignmentBaseline.TextBaseline.IDEOGRAPHIC_TOPThe ideographic top baseline of the element aligns with the alignmentBaseline.TextBaseline.IDEOGRAPHIC_CENTERThe ideographic center baseline of the element aligns with the alignmentBaseline.TextBaseline.IDEOGRAPHIC_BOTTOMThe ideographic bottom baseline of the element aligns with the alignmentBaseline.SubclassEffect of setting propertyGraphicElementDetermines which of the baselines of the graphic element aligns with the alignmentBaseline.GroupElementHas no effect.TextElementDetermines which of the baselines of the text element aligns with the alignmentBaseline.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to any value which is not a member of TextBaseline.
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        std::string ElementFormat::dominantBaseline()         ;
        void ElementFormat::dominantBaseline(std::string dominantBaseline)       ;

        /**
         * An object whose properties describe a font.
         * 
         *   The default value is a default-constructed FontDescription object.When the fontDescription property is set, the FontDescription object provided is locked:  its locked
         * property is set to true.  A locked FontDescription cannot be modified.SubclassEffect of setting propertyGraphicElementHas no effect.GroupElementHas no effect.TextElementDetermines the font used for the text in the element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        flash::text::engine::FontDescription* ElementFormat::fontDescription()                                    ;
        void ElementFormat::fontDescription(FontDescription* value)       ;

        /**
         * The digit case used for this text. 
         * Digit case affects the style and positioning of groups of numeric characters.
         * Use DigitCase
         * constants for this property.
         * 
         *   The default value is DigitCase.DEFAULT.To set values for this property, use the following string values:String valueDescriptionDigitCase.DEFAULTApplies default digit case to the text.DigitCase.LININGApplies lining digit case to the text.DigitCase.OLD_STYLEApplies old style digit case to the text.SubclassEffect of setting propertyGraphicElementHas no effect.GroupElementHas no effect.TextElementDetermines the digit case used for the text in the element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to any value which is not a member of DigitCase.
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        std::string ElementFormat::digitCase()         ;
        void ElementFormat::digitCase(std::string digitCaseType)       ;

        /**
         * The digit width used for this text. Use DigitWidth
         * constants for this property.
         * 
         *   The default value is DigitWidth.DEFAULT.To set values for this property, use the following string values:String valueDescriptionDigitWidth.DEFAULTApplies default digit width to the text.DigitWidth.PROPORTIONALApplies proportional digit width to the text.DigitWidth.TABULARApplies tabular digit width to the text.SubclassEffect of setting propertyGraphicElementHas no effect.GroupElementHas no effect.TextElementDetermines the digit width used for the text in the element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to any value which is not a member of DigitWidth.
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        std::string ElementFormat::digitWidth()         ;
        void ElementFormat::digitWidth(std::string digitWidthType)       ;

        /**
         * The ligature level used for this text. 
         * A ligature occurs where two or more letter-forms are joined as a single glyph. Ligatures 
         * usually replace consecutive characters sharing common components, such as the letter pairs 'fi', 'fl', or 'ae'.
         * They are used with both Latin and non-Latin character sets. Use LigatureLevel
         * constants for this property.
         * 
         *   The default value is LigatureLevel.COMMON.To set values for this property, use the following string values:String valueDescriptionLigatureLevel.NONENo ligatures are created.LigatureLevel.MINIMUMMinimal ligatures are created.LigatureLevel.COMMONCommon ligatures are created.LigatureLevel.UNCOMMONUncommon ligatures are created.LigatureLevel.EXOTICExotic ligatures are created.SubclassEffect of setting propertyGraphicElementHas no effect.GroupElementDetermines the ligature level between adjacent text elements in the group.
         * If the elementFormat of the group is null, the format of the first
         * of the adjacent elements is used.TextElementDetermines the ligature level between the characters in the text element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to any value which is not a member of LigatureLevel.
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        std::string ElementFormat::ligatureLevel()         ;
        void ElementFormat::ligatureLevel(std::string ligatureLevelType)       ;

        /**
         * The size of text in pixels.
         * 
         *   The default value is 12.0.SubclassEffect of setting propertyGraphicElementHas no effect.GroupElementHas no effect.TextElementDetermines the size in pixels for the text in the element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to a value less than zero.
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        float ElementFormat::fontSize()         ;
        void ElementFormat::fontSize(float value)       ;

        /**
         * Kerning adjusts the pixels between certain character pairs to improve readability.
         * Kerning is supported for all fonts which have kerning tables.
         * 
         *   The default value is Kerning.ON.To set values for this property, use the following constants in the Kerning class:String valueDescriptionKerning.ONKerning is enabled.Kerning.OFFKerning is disabled.Kerning.AUTOKerning is enabled except where inappropriate in Asian typography. Kerning is applied between two 
         * characters if neither is Kanji, Hiragana, or Katakana.SubclassEffect of setting propertyGraphicElementHas no effect.GroupElementDetermines whether kerning is applied between adjacent text elements in the group.
         * If the elementFormat of the group is null, the format of the first
         * of the adjacent elements is used.TextElementDetermines whether kerning is applied between the characters in the text element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        std::string ElementFormat::kerning()         ;
        void ElementFormat::kerning(std::string value)       ;

        /**
         * The locale of the text.  Controls case transformations and shaping.
         * Standard locale identifiers are used.  For example "en", "en_US" and "en-US" are all
         * English, "ja" is Japanese. See iso639-2 code list 
         * for a list of locale codes.
         * 
         *   The default value is "en".SubclassEffect of setting propertyGraphicElementHas no effect.GroupElementHas no effect.TextElementDetermines transformations and shaping for the text in the element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        std::string ElementFormat::locale()         ;
        void ElementFormat::locale(std::string value)       ;

        /**
         * Sets the rotation applied to individual glyphs. Use constants defined in the TextRotation class
         * for this property.
         * 
         *   The default value is TextRotation.AUTO.The final rotation of any glyph is the sum of ElementFormat.textRotation, ContentElement.textRotation, and TextBlock.lineRotation.You typically use this property for Asian text where characters must be rotated to display properly in vertical layout.
         * Use TextRotation.AUTO in combination with TextBlock.lineRotation = TextRotation.ROTATE_90
         * to accomplish this.Setting this property on fonts which do not contain vertical layout information can give undesirable results.
         * Fonts that contain a vmtx or VORG table, such as the Japanese font, "MS Mincho", work correctly because the 
         * tables supply the data that the layout engine requires for correct layout. Fonts such as Verdana, which do not contain the necessary information,
         * do not.To set values for this property, use the following string values:String valueDescriptionTextRotation.ROTATE_0Glyphs are not rotated.TextRotation.ROTATE_90Glyphs are rotated 90 degrees clockwise.TextRotation.ROTATE_180Glyphs are rotated 180 degrees.TextRotation.ROTATE_270Glyphs are rotated 270 degrees clockwise.TextRotation.AUTOSpecifies a 90 degree counter clockwise rotation for full width and wide glyphs only,
         * as determined by the Unicode properties of the glyph.
         * This value is typically used with Asian text to rotate
         * only those glyphs that require rotation.
         * This rotation is applied only in vertical text to return full width and wide 
         * characters to a vertical orientation without affecting other characters.SubclassEffect of setting propertyGraphicElementHas no effect.GroupElementHas no effect.TextElementDetermines the rotation of the glyphs in the text element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to any value which is not a member of TextRotation.
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        std::string ElementFormat::textRotation()         ;
        void ElementFormat::textRotation(std::string value)       ;

        /**
         * The tracking or manual kerning applied to the right of each glyph in pixels.
         * If kerning is enabled, the trackingRight value is added to the values in the 
         * kerning table for the font.  If kerning is disabled, the trackingRight value
         * is used as a manual kerning value. Supports both positive and negative values.
         * 
         *   Typically, the desired tracking value is split between trackingRight and trackingLeft.
         * Otherwise, in mixed directionality text, there is twice the tracking at one bidi boundary and none at the other.The default value is 0.0.SubclassEffect of setting propertyGraphicElementDetermines the tracking applied to the right side of the graphic.GroupElementHas no effect.TextElementDetermines the tracking applied to the right side of characters in the text element.Example:
         * <codeblock>
         * 
         *   //positive tracking added to kerning
         * var ef1:ElementFormat = new ElementFormat();
         * ef1.kerning = flash.text.engine.Kerning.ON;
         * ef1.trackingRight = 0.5;
         * 
         *   //negative manual kerning
         * var ef2:ElementFormat = new ElementFormat();
         * ef2.kerning = flash.text.engine.Kerning.OFF;
         * ef2.trackingRight = -1.0;
         * 
         *   </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5.
         * @playerversion   Lite 4
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        float ElementFormat::trackingRight()         ;
        void ElementFormat::trackingRight(float value)       ;

        /**
         * The tracking or manual kerning applied to the left of each glyph in pixels.
         * If kerning is enabled, the trackingLeft value is added to the values in the 
         * kerning table for the font.  If kerning is disabled, the trackingLeft value
         * is used as a manual kerning value. Supports both positive and negative values.
         * 
         *   Typically, the desired tracking value is split between trackingRight and trackingLeft.
         * Otherwise, in mixed directionality text, there is twice the tracking at one bidi boundary and none at the other.The default value is 0.0.SubclassEffect of setting propertyGraphicElementDetermines the tracking applied to the left side of the graphic.GroupElementHas no effect.TextElementDetermines the tracking applied to the left side of characters in the text element.Example:
         * <codeblock>
         * 
         *   //positive tracking added to kerning
         * var ef1:ElementFormat = new ElementFormat();
         * ef1.kerning = flash.text.engine.Kerning.ON;
         * ef1.trackingLeft = 0.5;
         * 
         *   //negative manual kerning
         * var ef2:ElementFormat = new ElementFormat();
         * ef2.kerning = flash.text.engine.Kerning.OFF;
         * ef2.trackingLeft = -1.0;
         * 
         *   </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5.
         * @playerversion   Lite 4
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        float ElementFormat::trackingLeft()         ;
        void ElementFormat::trackingLeft(float value)       ;

        /**
         * The typographic case used for this text. Use constants defined in the TypographicCase class for this property.
         * 
         *   The default value is TypographicCase.DEFAULT.To set values for this property, use the following string values:String valueDescriptionTypographicCase.DEFAULTSpecifies that normal case is used for all characters.TypographicCase.TITLESpecifies that uppercase characters use title glyphs on output.TypographicCase.CAPSSpecifies that spacing is adjusted for uppercase characters on output.TypographicCase.SMALL_CAPSSpecifies that uppercase characters use small caps glyphs on output.TypographicCase.UPPERCASESpecifies that all characters use uppercase glyphs on output.TypographicCase.LOWERCASESpecifies that all characters use lowercase glyphs on output.TypographicCase.CAPS_AND_SMALL_CAPSSpecifies that all lowercase characters use small caps glyphs on output.SubclassEffect of setting propertyGraphicElementHas no effect.GroupElementHas no effect.TextElementDetermines the typographic case used for the text in the element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError If set to a value not a member of TypographicCase.
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        std::string ElementFormat::typographicCase()         ;
        void ElementFormat::typographicCase(std::string typographicCaseType)       ;

        /**
         * Indicates whether the ElementFormat is locked.  If true the ElementFormat cannot be modified.
         * Call ElementFormat.clone() to get an unlocked copy of the ElementFormat object.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5.
         * @playerversion   Lite 4
         * @throws  IllegalOperationError If set after the ElementFormat object is locked (locked is true).
         */
        bool ElementFormat::locked()          ;
        void ElementFormat::locked(bool value)       ;

        /**
         * Creates an ElementFormat object.
         * @param   fontDescription The FontDescription object which identifies the font used with this element format.
         *   The default value is null.  If no font description is provided, a default font description is constructed.
         * @param   fontSize    The size of text in pixels.
         * @param   color   The color of text. A hexadecimal number containing three 8-bit RGB
         *   components; for example, 0xFF0000 is red and 0x00FF00 is green.
         * @param   alpha   The alpha property applied to all line atoms based on the element format.
         * @param   textRotation    the rotation applied to individual glyphs. Use TextRotation
         *   constants for this property.
         * @param   dominantBaseline    The baseline to which the glyphs in the text snap.
         *   Use TextBaseline constants for this property.
         * @param   alignmentBaseline   The baseline on the containing line to which the dominant baseline snaps.
         *   Use TextBaseline constants for this property.
         * @param   baselineShift   The baseline shift for the text in pixels em.
         * @param   kerning The kerning used for this text. Use constants defined in the Kerning class.
         * @param   trackingRight   The tracking or manual kerning applied to the right of each glyph in pixels.
         * @param   trackingLeft    The tracking or manual kerning applied to the left of each glyph in pixels.
         * @param   locale  The locale of the text.
         * @param   breakOpportunity    The line break opportunity applied to this text. Use BreakOpportunity
         *   constants for this property.
         * @param   digitCase   The digit case used for this text. Use DigitCase
         *   constants for this property.
         * @param   digitWidth  The digit width used for this text. Use DigitWidth
         *   constants for this property.
         * @param   ligatureLevel   The ligature level used for this text. Use LigatureLevel
         *   constants for this property.
         * @param   typographicCase The typographic case used for this text. Use TypographicCase
         *   constants for this property.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         * @throws  ArgumentError The fontSize specified is less than 0.
         * @throws  ArgumentError The textRotation specified is not a member of TextRotation.
         * @throws  ArgumentError The dominantBaseline specified is not a member of TextBaseline.
         * @throws  ArgumentError The alignmentBaseline specified is not a member of TextBaseline.
         * @throws  ArgumentError The kerning specified is not a member of Kerning.
         * @throws  ArgumentError The breakOpportunity specified is not a member of BreakOpportunity.
         * @throws  ArgumentError The digitCase specified is not a member of DigitCase.
         * @throws  ArgumentError The digitWidth specified is not a member of DigitWidth.
         * @throws  ArgumentError The ligatureLevel specified is not a member of LigatureLevel.
         * @throws  ArgumentError The typographicCase specified is not a member of TypographicCase.
         */
        ElementFormat::ElementFormat(FontDescription* fontDescription, float fontSize, unsigned int color, float alpha, std::string textRotation, std::string dominantBaseline, std::string alignmentBaseline, float baselineShift, std::string kerning, float trackingRight, float trackingLeft, std::string locale, std::string breakOpportunity, std::string digitCase, std::string digitWidth, std::string ligatureLevel, std::string typographicCase);

        /**
         * Returns a FontMetrics object with properties which describe the emBox, strikethrough position,
         * strikethrough thickness, underline position, and underline thickness for the font specified by 
         * fontDescription and fontSize.
         * @return  A FontMetrics object describing properties of the font specified by fontDescription.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        flash::text::engine::FontMetrics* ElementFormat::getFontMetrics()                                ;

        /**
         * Constructs an unlocked, cloned copy of the ElementFormat.
         * @return  An unlocked copy of the ElementFormat object.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        flash::text::engine::ElementFormat* ElementFormat::clone()                                  ;
}
}
}

