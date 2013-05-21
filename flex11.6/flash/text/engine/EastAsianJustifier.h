#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_EASTASIANJUSTIFIER_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_EASTASIANJUSTIFIER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/text/engine/TextJustifier.h"

/**
 * The EastAsianJustifier class has properties to control the justification options for text lines whose
 * content is primarily East Asian text.
 *
 *   <p class="- topic/p "> Use the constructor <codeph class="+ topic/ph pr-d/codeph ">new EastAsianJustifier()</codeph> to create an EastAsianJustifier object
 * before setting its properties. Setting the properties of an EastAsianJustifier object after it has been applied to a TextBlock does
 * not invalidate the TextBlock.</p>
 *
 *   EXAMPLE:
 *
 *   This example displays a block of Japanese text vertically,
 * using EastAsianJustifier properties to justify the text.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.text.engine.TextBlock;
 * import flash.text.engine.TextLine;
 * import flash.text.engine.TextElement;
 * import flash.text.engine.TextBaseline;
 * import flash.text.engine.EastAsianJustifier;
 * import flash.text.engine.LineJustification;
 * import flash.text.engine.TextRotation;
 * import flash.text.engine.FontDescription;
 * import flash.text.engine.ElementFormat;
 * import flash.display.Stage;
 * import flash.display.Sprite;
 * import flash.system.Capabilities;
 *
 *   public class EastAsianJustifierExample extends Sprite {
 *
 *   public function EastAsianJustifierExample():void {
 *
 *   var Japanese_txt:String = String.fromCharCode(
 * 0x5185, 0x95A3, 0x5E9C, 0x304C, 0x300C, 0x653F, 0x5E9C, 0x30A4,
 * 0x30F3, 0x30BF, 0x30FC, 0x30CD, 0x30C3, 0x30C8, 0x30C6, 0x30EC,
 * 0x30D3, 0x300D, 0x306E, 0x52D5, 0x753B, 0x914D, 0x4FE1, 0x5411,
 * 0x3051, 0x306B, 0x30A2, 0x30C9, 0x30D3, 0x30B7, 0x30B9, 0x30C6,
 * 0x30E0, 0x30BA, 0x793E, 0x306E
 * ) +
 * "FMS 2" +
 * String.fromCharCode(0x3092, 0x63A1, 0x7528, 0x3059, 0x308B, 0x3068,
 * 0x767a, 0x8868, 0x3057, 0x307e, 0x3057, 0x305F, 0x3002);
 *
 *   var textBlock:TextBlock = new TextBlock();
 * var font:FontDescription = new FontDescription();
 * var format:ElementFormat = new ElementFormat();
 * format.fontSize = 12;
 * format.locale = "ja";
 * format.color = 0xCC0000;
 * textBlock.baselineZero = TextBaseline.IDEOGRAPHIC_CENTER;
 * textBlock.textJustifier = new EastAsianJustifier("ja", LineJustification.ALL_INCLUDING_LAST);
 * textBlock.lineRotation = TextRotation.ROTATE_90;
 * var linePosition:Number = this.stage.stageWidth - 75;
 * if (Capabilities.os.search("Mac OS") &gt; -1)
 * // set fontName: Kozuka Mincho Pro R
 * font.fontName = String.fromCharCode(0x5C0F, 0x585A, 0x660E, 0x671D) + " Pro R";
 * else
 * font.fontName = "Kozuka Mincho Pro R";
 * textBlock.content = new TextElement(Japanese_txt, format);
 * var previousLine:TextLine = null;
 *
 *   while (true)
 * {
 * var textLine:TextLine = textBlock.createTextLine(previousLine, 320);
 * if (textLine == null)
 * break;
 * textLine.y = 20;
 * textLine.x = linePosition;
 * linePosition -= 25;
 * addChild(textLine);
 * previousLine = textLine;
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

namespace flash
{
    namespace text
    {
        namespace engine
        {
            class EastAsianJustifier : public flash::text::engine::TextJustifier
            {
                /**
                 * Specifies the justification style for the text in a text block.
                 *
                 *   The default value is JustificationStyle.PUSH_IN_KINSOKU.Use one of the constants in the JustificationStyle class to set the value for this
                 * property. The following table lists the possible values:String valueDescriptionJustificationStyle.PUSH_IN_KINSOKUSpecifies push in justification.JustificationStyle.PUSH_OUT_ONLYSpecifies push out justification.JustificationStyle.PRIORITIZE_LEAST_ADJUSTMENTSpecifies justification wherein the least adjustment is prioritized.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                std::string  justificationStyle();
            public:
                void         justificationStyle(std::string value);

            public:
                bool         composeTrailingIdeographicSpaces();
            public:
                void         composeTrailingIdeographicSpaces(bool value);

                /**
                 * Creates an EastAsianJustifier object.
                 * @param   locale  The locale to determine the justification rules.
                 *   The default value is "ja".
                 * @param   lineJustification   The type of line justification for the paragraph.
                 *   Use LineJustification constants for this property.
                 *   The default value is LineJustification.ALL_BUT_LAST.
                 * @param   justificationStyle  The justification style for the text in a text block using an East Asian justifier.
                 *   Use JustificationStyle constants for this property.
                 *   The default value is JustificationStyle.PUSH_IN_KINSOKU.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  ArgumentError The locale specified is null or too short to represent a valid locale.
                 * @throws  ArgumentError The lineJustification specified is not a member of LineJustification.
                 * @throws  ArgumentError The justificationStyle specified is not a member of JustificationStyle.
                 */
            public:
                EastAsianJustifier(std::string locale="ja", std::string lineJustification="allButLast", std::string justificationStyle="pushInKinsoku");

                /**
                 * Constructs a cloned copy of the EastAsianJustifier.
                 * @return  A copy of the EastAsianJustifier object.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @internal    In the Flash Player 10 release, this method is for internal use. In future releases,
                 *   users will be able to subclass this class and will then need to use this method. This class is
                 *   currently stored as a live reference, but there is no way to track when its properties change.
                 *   This means that when changes are made, text blocks are not invalidated, which in the current
                 *   implementation can lead to player crashes.  Even from the API perspective its wrong, as the affected
                 *   text lines should be marked INVALID when format changes are made, but they   re not. The solution is
                 *   to use a copy-on-set model.  When the object is passed in, the player copies it, so later changes to
                 *   the object that was passed in have no effect. The setter makes an internal copy of the array; the
                 *   getter returns a copy of the internal copy. Operations like
                 *   myBlock.textJustifier.justificationStyle = JustificationStyle.PUSH_IN_KINSOKU will have no effect.
                 *   Users who subclass this class in the future will need to use the clone() method to
                 *   implement this technique of 'locking' the format once it has been set.
                 */
            public:
                flash::text::engine::TextJustifier *clone();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_EASTASIANJUSTIFIER_AS
#endif // __cplusplus

