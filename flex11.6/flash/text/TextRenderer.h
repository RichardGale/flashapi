#if !defined(FLEX11_6_FLASH_TEXT_TEXTRENDERER_AS)
#define FLEX11_6_FLASH_TEXT_TEXTRENDERER_AS
#if defined(__cplusplus)


/**
 * The TextRenderer class provides functionality for the advanced anti-aliasing capability of
 * embedded fonts. Advanced anti-aliasing allows font faces to render at very high quality at
 * small sizes. Use advanced anti-aliasing with applications that have a lot of small text. Adobe does not recommend using advanced
 * anti-aliasing for very large fonts (larger than 48 points).
 * Advanced anti-aliasing is available in Flash Player 8 and later only.
 *
 *   <p class="- topic/p ">To set advanced anti-aliasing on a text field, set the <codeph class="+ topic/ph pr-d/codeph ">antiAliasType</codeph> property of
 * the TextField instance.</p><p class="- topic/p ">Advanced anti-aliasing provides continuous stroke modulation (CSM), which is continuous
 * modulation of both stroke weight and edge sharpness. As an advanced feature, you can
 * use the <codeph class="+ topic/ph pr-d/codeph ">setAdvancedAntiAliasingTable()</codeph> method to define settings for specific
 * typefaces and font sizes.</p>
 *
 *   EXAMPLE:
 *
 *   The following example creates the TextRendererExample class
 * to demonstrate visual examples of advanced anti-aliasing settings with small
 * and large font sizes. Before testing this example, you will need to embed a
 * font.
 * If you are using Flex, embed a font in the following manner:
 * <ol class="- topic/ol "><li class="- topic/li ">Place the Georgia font, named georgia.ttf in the same directory as this AS file.</li><li class="- topic/li ">Add the following lines directly underneath the class definition:</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">[Embed(source="georgia.ttf", fontFamily="Georgia")]</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">private var embeddedFont:String;</codeph></li></ol>
 * If you are using Flash, embed a font in the following manner:
 * <ol class="- topic/ol "><li class="- topic/li ">Place a text field on the stage and select it.</li><li class="- topic/li ">In the Property Inspector, set that text field's font to Georgia</li><li class="- topic/li ">In the Property Inspector, press "Embed..." and select "All"</li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Notes:</b><ul class="- topic/ul "><li class="- topic/li ">You will need to compile the SWF file with "Local playback security" set to "Access local files only".</li></ul></p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.DisplayObject;
 * import flash.display.Sprite;
 * import flash.events.*;
 * import flash.text.*;
 *
 *   public class TextRendererExample2 extends Sprite {
 *
 *   private var gutter:int = 10;
 *
 *   public function TextRendererExample2() {
 * createTextField(8,AntiAliasType.NORMAL);
 * createTextField(8,AntiAliasType.ADVANCED);
 * createTextField(24,AntiAliasType.NORMAL);
 * createTextField(24,AntiAliasType.ADVANCED);
 * }
 *
 *   private function createTextField(fontSize:Number,antiAliasType:String):TextField {
 * var tf:TextField = new TextField();
 * tf.embedFonts = true;
 * tf.autoSize = TextFieldAutoSize.LEFT;
 * tf.antiAliasType = antiAliasType;
 * tf.defaultTextFormat = getTextFormat(fontSize);
 * tf.selectable = false;
 * tf.mouseEnabled = true;
 * tf.text = "The quick brown fox jumped over the lazy dog.";
 * if(numChildren &gt; 0) {
 * var sibling:DisplayObject = getChildAt(numChildren - 1);
 * tf.y = sibling.y + sibling.height + gutter;
 * }
 * addChild(tf);
 * return tf;
 * }
 *
 *   private function getTextFormat(fontSize:Number):TextFormat {
 * var format:TextFormat = new TextFormat();
 * format.size = fontSize;
 * format.font = "Georgia";
 * return format;
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @internal    -- Class sample changed due to bug 193833
 */

namespace flash
{
    namespace text
    {
        class TextRenderer: public Object
        {
        public:
            static std::string  antiAliasType();
        public:
            static void         antiAliasType(std::string value);

            /**
             * The adaptively sampled distance fields (ADFs) quality level for advanced anti-aliasing. The only acceptable values are
             * 3, 4, and 7.
             *
             *   Advanced anti-aliasing uses ADFs to
             * represent the outlines that determine a glyph. The higher the quality, the more
             * cache space is required for ADF structures. A value of 3 takes the least amount
             * of memory and provides the lowest quality. Larger fonts require more cache space;
             * at a font size of 64 pixels, the quality level increases from 3 to 4 or
             * from 4 to 7 unless, the level is already set to 7.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example specifies the <code>maxLevel</code> value for the entire
             *   SWF file, and then displays a text field with the value set. For the
             *   text in this example to display correctly, there must be a font symbol available with
             *   a linkage identifier of <code>"CustomFont"</code>.
             *   <listing version="2.0">
             *   import flash.text.TextRenderer;
             *   TextRenderer.maxLevel = 3;
             *
             *     var txtFormat:TextFormat = new TextFormat();
             *   txtFormat.font = "CustomFont";
             *   txtFormat.size = 64;
             *
             *     var label:TextField = this.createTextField("label", this.getNextHighestDepth(), 10, 10, 500, 100);
             *   label.setNewTextFormat(txtFormat);
             *   label.text = "Hello World";
             *   label.embedFonts = true;
             *   trace("TextRenderer.maxLevel: " + TextRenderer.maxLevel);
             *   </listing>
             */
        public:
            static int          maxLevel();
        public:
            static void         maxLevel(int value);

            /**
             * Controls the rendering of advanced anti-aliased text. The visual quality of text is very subjective, and while
             * Flash Player tries to use the best settings for various conditions, designers may choose a different
             * look or feel for their text. Also, using displayMode allows a designer to override Flash
             * Player's subpixel choice and create visual consistency independent of the user's hardware. Use the values in the TextDisplayMode class to set this property.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static std::string  displayMode();
        public:
            static void         displayMode(std::string value);

            /**
             * Sets a custom continuous stroke modulation (CSM) lookup table for a font.
             * Flash Player attempts to detect the best CSM for your font. If you are not
             * satisfied with the CSM that the Flash Player provides, you can customize
             * your own CSM by using the setAdvancedAntiAliasingTable() method.
             * @param   fontName    The name of the font for which you are applying settings.
             * @param   fontStyle   The font style indicated by using one of the values from
             *   the flash.text.FontStyle class.
             * @param   colorType   This value determines whether the stroke is dark or whether it is light.
             *   Use one of the values from the flash.text.TextColorType class.
             * @param   advancedAntiAliasingTable   An array of one or more CSMSettings objects
             *   for the specified font. Each object contains the following properties:
             *
             *     fontSizeinsideCutOffoutsideCutOffThe advancedAntiAliasingTable array can contain multiple entries
             *   that specify CSM settings for different font sizes.The fontSize is the size, in pixels, for which the settings apply.Advanced anti-aliasing uses adaptively sampled distance fields (ADFs) to
             *   represent the outlines that determine a glyph. Flash Player uses an outside cutoff value
             *   (outsideCutOff),
             *   below which densities are set to zero, and an inside cutoff value (insideCutOff),
             *   above which densities
             *   are set to a maximum density value (such as 255). Between these two cutoff values,
             *   the mapping function is a linear curve ranging from zero at the outside cutoff
             *   to the maximum density at the inside cutoff.Adjusting the outside and inside cutoff values affects stroke weight and
             *   edge sharpness. The spacing between these two parameters is comparable to twice the
             *   filter radius of classic anti-aliasing methods; a narrow spacing provides a sharper edge,
             *   while a wider spacing provides a softer, more filtered edge. When
             *   the spacing is zero, the resulting density image is a bi-level bitmap. When the
             *   spacing is very wide, the resulting density image has a watercolor-like edge.Typically, users prefer sharp, high-contrast edges at small point sizes, and
             *   softer edges for animated text and larger point sizes. The outside cutoff typically has a negative value, and the inside cutoff typically
             *   has a positive value, and their midpoint typically lies near zero. Adjusting these
             *   parameters to shift the midpoint toward negative infinity increases the stroke
             *   weight; shifting the midpoint toward positive infinity decreases the stroke weight.
             *   Make sure that the outside cutoff value is always less than or equal to the inside cutoff value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample The following example creates two anti-alias entries and two text fields to
             *   illustrate them. For this example to work, the SWF file must have a shared font embedded with a linkage identifier of <code>
             *   "myArial"</code>.
             *   To embed the font, follow these steps:
             *   <ol class="- topic/ol "><li class="- topic/li ">Open your Library.</li><li class="- topic/li ">Click the Library options menu in the upper-right corner of the Library.</li><li class="- topic/li ">Select New Font from the pop-up menu.</li><li class="- topic/li ">Name the font <b class="+ topic/ph hi-d/b ">myArial</b>.</li><li class="- topic/li ">Select Arial from the font pop-up menu.</li><li class="- topic/li ">Click OK.</li><li class="- topic/li ">Right-click the newly created font, and select Linkage.</li><li class="- topic/li ">Select the Export for ActionScript check box.</li><li class="- topic/li ">Click OK to accept the default identifier, myArial.</li></ol><listing version="2.0">
             *   import flash.text.TextRenderer;
             *
             *     var antiAliasEntry_1 = {fontSize:24, insideCutoff:1.61, outsideCutoff:-3.43};
             *   var antiAliasEntry_2 = {fontSize:48, insideCutoff:0.8, outsideCutoff:-0.8};
             *   var arialTable:Array = new Array(antiAliasEntry_1, antiAliasEntry_2);
             *
             *     var lbl_1:TextField = createLabel(0, 0, 300, 100, 24);
             *   var lbl_2:TextField = createLabel(0, 100, 300, 100, 48);
             *
             *     TextRenderer.setAdvancedAntiAliasingTable("Arial", "none", "dark", arialTable);
             *
             *     function createLabel(x:Number, y:Number, width:Number, height:Number, fontSize:Number):TextField {
             *   var depth:Number = this.getNextHighestDepth();
             *
             *     var tmpTxt = this.createTextField("txt_" + depth, depth, x, y, width, height);
             *   tmpTxt.antiAliasType = "advanced";
             *   tmpTxt.gridFitType = "pixel";
             *   tmpTxt.border = true;
             *   tmpTxt.text = "Hello World";
             *   tmpTxt.embedFonts = true;
             *   tmpTxt.setTextFormat(getTextFormat(fontSize));
             *   return tmpTxt;
             *   }
             *
             *     function getTextFormat(fontSize:Number):TextFormat {
             *   var tf:TextFormat = new TextFormat();
             *   tf.align = "center";
             *   tf.size = fontSize;
             *   tf.font = "myArial";
             *   return tf;
             *   }
             *   </listing>
             */
        public:
            static void     setAdvancedAntiAliasingTable(std::string fontName, std::string fontStyle, std::string colorType, std::vector<void *> advancedAntiAliasingTable);

        public:
            TextRenderer();
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_TEXTRENDERER_AS
#endif // __cplusplus

