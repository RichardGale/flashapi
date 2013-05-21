#if !defined(FLEX11_6_FLASH_TEXT_TEXTFORMAT_AS)
#define FLEX11_6_FLASH_TEXT_TEXTFORMAT_AS
#if defined(__cplusplus)


/**
 * The TextFormat class represents character formatting information.  Use the TextFormat class
 * to create specific text formatting for text fields. You can apply text formatting
 * to both static and dynamic text fields. The properties of the TextFormat class apply to device and
 * embedded fonts. However, for embedded fonts, bold and italic text actually require specific fonts. If you
 * want to display bold or italic text with an embedded font, you need to embed the bold and italic variations
 * of that font.
 *
 *   <p class="- topic/p "> You must use the constructor <codeph class="+ topic/ph pr-d/codeph ">new TextFormat()</codeph> to create a TextFormat object
 * before setting its properties.
 * When you apply a TextFormat object to a text field using the <codeph class="+ topic/ph pr-d/codeph ">TextField.defaultTextFormat</codeph> property
 * or the <codeph class="+ topic/ph pr-d/codeph ">TextField.setTextFormat()</codeph> method, only its defined properties are applied. Use
 * the <codeph class="+ topic/ph pr-d/codeph ">TextField.defaultTextFormat</codeph> property to apply formatting BEFORE you add text to the <codeph class="+ topic/ph pr-d/codeph ">TextField</codeph>,
 * and the <codeph class="+ topic/ph pr-d/codeph ">setTextFormat()</codeph> method to add formatting AFTER you add text to the <codeph class="+ topic/ph pr-d/codeph ">TextField</codeph>.
 * The TextFormat properties are <codeph class="+ topic/ph pr-d/codeph ">null</codeph> by default
 * because if you don't provide values for the properties, Flash Player uses its own default formatting.
 * The default formatting that Flash Player uses for each property (if property's value is <codeph class="+ topic/ph pr-d/codeph ">null</codeph>)
 * is as follows:</p><adobetable class="innertable"><tgroup cols="1" class="- topic/tgroup "><tbody class="- topic/tbody "><row class="- topic/row "><entry class="- topic/entry ">align = "left"</entry></row><row class="- topic/row "><entry class="- topic/entry ">blockIndent = 0</entry></row><row class="- topic/row "><entry class="- topic/entry ">bold = false</entry></row><row class="- topic/row "><entry class="- topic/entry ">bullet = false</entry></row><row class="- topic/row "><entry class="- topic/entry ">color = 0x000000</entry></row><row class="- topic/row "><entry class="- topic/entry ">font = "Times New Roman" (default font is Times on Mac OS X)</entry></row><row class="- topic/row "><entry class="- topic/entry ">indent = 0</entry></row><row class="- topic/row "><entry class="- topic/entry ">italic = false</entry></row><row class="- topic/row "><entry class="- topic/entry ">kerning = false</entry></row><row class="- topic/row "><entry class="- topic/entry ">leading = 0</entry></row><row class="- topic/row "><entry class="- topic/entry ">leftMargin = 0</entry></row><row class="- topic/row "><entry class="- topic/entry ">letterSpacing = 0</entry></row><row class="- topic/row "><entry class="- topic/entry ">rightMargin = 0</entry></row><row class="- topic/row "><entry class="- topic/entry ">size = 12</entry></row><row class="- topic/row "><entry class="- topic/entry ">tabStops = [] (empty array)</entry></row><row class="- topic/row "><entry class="- topic/entry ">target = "" (empty string)</entry></row><row class="- topic/row "><entry class="- topic/entry ">underline = false</entry></row><row class="- topic/row "><entry class="- topic/entry ">url = "" (empty string)</entry></row></tbody></tgroup></adobetable><p class="- topic/p ">The default formatting for each property is also described in each property description.</p>
 *
 *   EXAMPLE:
 *
 *   The following example creates the TextFieldExample class to display a text message with
 * the default location (x = 0, y = 0).  This is accomplished using the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">A property <codeph class="+ topic/ph pr-d/codeph ">label</codeph> of type TextField is created.</li><li class="- topic/li ">The class constructor calls the function <codeph class="+ topic/ph pr-d/codeph ">configureLabel()</codeph></li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">configureLabel()</codeph> function first creates a new TextField object and assigns it to
 * <codeph class="+ topic/ph pr-d/codeph ">label</codeph> then sets its parameters to
 * <ul class="- topic/ul "><li class="- topic/li ">Left-justify the text field</li><li class="- topic/li ">Enable the background fill</li><li class="- topic/li ">Enable the border.</li></ul></li><li class="- topic/li ">Next, <codeph class="+ topic/ph pr-d/codeph ">configureLabel()</codeph> creates the local variable, <codeph class="+ topic/ph pr-d/codeph ">format</codeph>, and assigns it to
 * a new TextFormat instance with its parameters set to:
 * <ul class="- topic/ul "><li class="- topic/li ">Font type = Verdana</li><li class="- topic/li ">Font Color = solid red</li><li class="- topic/li ">Font size = 10</li><li class="- topic/li ">Font underline = true.</li></ul></li><li class="- topic/li ">The label's <codeph class="+ topic/ph pr-d/codeph ">defaultTextFormat</codeph> property is set to <codeph class="+ topic/ph pr-d/codeph ">format</codeph>, and the
 * <codeph class="+ topic/ph pr-d/codeph ">label</codeph> instance is added to the display list, which initially displays a text field with
 * no text (as tiny box with a white background) on the stage.</li><li class="- topic/li ">Finally (back in the constructor), the label's text is then set to display "Hello
 * World and welcome to the show", at coordinates x = 0, y = 0 by calling <codeph class="+ topic/ph pr-d/codeph ">setLabel()</codeph>.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.text.TextField;
 * import flash.text.TextFieldAutoSize;
 * import flash.text.TextFormat;
 *
 *   public class TextFormatExample extends Sprite {
 * private var label:TextField;
 *
 *   public function TextFormatExample() {
 * configureLabel();
 * setLabel("Hello World and welcome to the show");
 * }
 *
 *   public function setLabel(str:String):void {
 * label.text = str;
 * }
 *
 *   private function configureLabel():void {
 * label = new TextField();
 * label.autoSize = TextFieldAutoSize.LEFT;
 * label.background = true;
 * label.border = true;
 *
 *   var format:TextFormat = new TextFormat();
 * format.font = "Verdana";
 * format.color = 0xFF0000;
 * format.size = 10;
 * format.underline = true;
 *
 *   label.defaultTextFormat = format;
 * addChild(label);
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 * @internal    Insure the above example is correct and meets example standards
 */


namespace flash
{
    namespace text
    {
        class TextFormat : public Object
        {
            /**
             * Indicates the alignment of the paragraph. Valid values are TextFormatAlign constants.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             * @throws  ArgumentError The align specified is not a member of flash.text.TextFormatAlign.
             */
        public:
            std::string  align();
        public:
            void         align(std::string value);

            /**
             * Indicates the block indentation in pixels. Block indentation is applied to
             * an entire block of text; that is, to all lines of the text. In contrast, normal indentation
             * (TextFormat.indent) affects only the first line of each paragraph.
             * If this property is null, the TextFormat object does not specify block indentation
             * (block indentation is 0).
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            Object      *blockIndent();
        public:
            void         blockIndent(Object *value);

            /**
             * Specifies whether the text is boldface. The default value is null,
             * which means no boldface is used.
             * If the value is true, then
             * the text is boldface.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            Object      *bold();
        public:
            void         bold(Object *value);

            /**
             * Indicates that the text is part of a bulleted list. In a bulleted
             * list, each paragraph of text is indented. To the left of the first line of each paragraph, a bullet
             * symbol is displayed. The default value is null, which means no bulleted list
             * is used.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            Object      *bullet();
        public:
            void         bullet(Object *value);

            /**
             * Indicates the color of the text. A number containing three 8-bit RGB components; for example,
             * 0xFF0000 is red, and 0x00FF00 is green. The default value is null,
             * which means that Flash Player uses the color black (0x000000).
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            Object      *color();
        public:
            void         color(Object *value);

        public:
            std::string  display();
        public:
            void         display(std::string value);

            /**
             * The name of the font for text in this text format, as a string. The default value is
             * null, which means that Flash Player uses Times New Roman font for the text.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            std::string  font();
        public:
            void         font(std::string value);

            /**
             * Indicates the indentation from the left
             * margin to the first character in the paragraph. The default value is null, which
             * indicates that no indentation is used.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            Object      *indent();
        public:
            void         indent(Object *value);

            /**
             * Indicates whether text in this text format is italicized. The default
             * value is null, which means no italics are used.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            Object      *italic();
        public:
            void         italic(Object *value);

            /**
             * A Boolean value that indicates whether kerning is enabled (true)
             * or disabled (false). Kerning adjusts the pixels between certain character pairs to improve readability, and
             * should be used only when necessary, such as with headings in large fonts. Kerning is
             * supported for embedded fonts only.
             *
             *   Certain fonts such as Verdana and monospaced fonts,
             * such as Courier New,  do not support kerning.The default value is null, which means that kerning is not enabled.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @internal    Add better description and example.
             */
        public:
            Object      *kerning();
        public:
            void         kerning(Object *value);

            /**
             * An integer representing the amount of vertical space (called leading)
             * between lines. The default value is null, which indicates that the
             * amount of leading used is 0.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            Object      *leading();
        public:
            void         leading(Object *value);

            /**
             * The left margin of the paragraph, in pixels. The default value is null, which
             * indicates that the left margin is 0 pixels.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            Object      *leftMargin();
        public:
            void         leftMargin(Object *value);

            /**
             * A number representing the amount of space that is uniformly distributed between all characters.
             * The value specifies the number of pixels that are added to the advance after each character.
             * The default value is null, which means that 0 pixels of letter spacing is used.
             * You can use decimal values such as 1.75.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @internal    Add better description and example.
             */
        public:
            Object      *letterSpacing();
        public:
            void         letterSpacing(Object *value);

            /**
             * The right margin of the paragraph, in pixels. The default value is null,
             * which indicates that the right margin is 0 pixels.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            Object      *rightMargin();
        public:
            void         rightMargin(Object *value);

            /**
             * The size in pixels of text in this text format. The default value is null, which
             * means that a size of 12 is used.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            Object      *size();
        public:
            void         size(Object *value);

            /**
             * Specifies custom tab stops as an array of non-negative integers. Each tab stop is
             * specified in pixels. If custom tab stops are not specified (null), the default tab
             * stop is 4 (average character width).
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            std::vector<void *> tabStops();
        public:
            void         tabStops(std::vector<void *> value);

            /**
             * Indicates the target window where the hyperlink is displayed. If the target window is an
             * empty string, the text is displayed in the default target window _self. You can choose
             * a custom name or one of the following four names: _self specifies the current frame in
             * the current window, _blank specifies a new window, _parent specifies the
             * parent of the current frame, and _top specifies the top-level frame in the current
             * window. If the TextFormat.url property is an empty string or null,
             * you can get or set this property, but the property will have no effect.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            std::string  target();
        public:
            void         target(std::string value);

            /**
             * Indicates whether the text that uses this text format is underlined (true)
             * or not (false). This underlining is similar to that produced by the
             * <U> tag, but the latter is not true underlining, because it does not skip
             * descenders correctly. The default value is null, which indicates that underlining
             * is not used.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            Object      *underline();
        public:
            void         underline(Object *value);

            /**
             * Indicates the target URL for the text in this text format. If the url
             * property is an empty string, the text does not have a hyperlink. The default value is null,
             * which indicates that the text does not have a hyperlink.
             * Note: The text with the assigned text format must be set with the htmlText
             * property for the hyperlink to work.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            std::string  url();
        public:
            void         url(std::string value);

            /**
             * Creates a TextFormat object with the specified properties. You can then change the
             * properties of the TextFormat object to change the formatting of text fields.
             *
             *   Any parameter may be set to null to indicate that it is not defined. All of the
             * parameters are optional; any omitted parameters are treated as null.
             * @param   font    The name of a font for text as a string.
             * @param   size    An integer that indicates the size in pixels.
             * @param   color   The color of text using this text format. A number containing three 8-bit RGB
             *   components; for example, 0xFF0000 is red, and 0x00FF00 is green.
             * @param   bold    A Boolean value that indicates whether the text is boldface.
             * @param   italic  A Boolean value that indicates whether the text is italicized.
             * @param   underline   A Boolean value that indicates whether the text is underlined.
             * @param   url The URL to which the text in this text format hyperlinks. If url is
             *   an empty string, the text does not have a hyperlink.
             * @param   target  The target window where the hyperlink is displayed. If the target window is an empty
             *   string, the text is displayed in the default target window _self. If the
             *   url parameter is set to an empty string or to the value null, you can get or
             *   set this property, but the property will have no effect.
             * @param   align   The alignment of the paragraph, as a TextFormatAlign value.
             * @param   leftMargin  Indicates the left margin of the paragraph, in pixels.
             * @param   rightMargin Indicates the right margin of the paragraph, in pixels.
             * @param   indent  An integer that indicates the indentation from the left margin to the first character
             *   in the paragraph.
             * @param   leading A number that indicates the amount of leading vertical space between lines.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Lite 4
             */
        public:
            TextFormat(std::string font="", Object *size=NULL, Object *color=NULL, Object *bold=NULL, Object *italic=NULL, Object *underline=NULL, std::string url="", std::string target="", std::string align="", Object *leftMargin=NULL, Object *rightMargin=NULL, Object *indent=NULL, Object *leading=NULL);
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_TEXTFORMAT_AS
#endif // __cplusplus

