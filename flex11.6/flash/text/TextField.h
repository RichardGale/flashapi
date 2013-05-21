#if !defined(FLEX11_6_FLASH_TEXT_TEXTFIELD_AS)
#define FLEX11_6_FLASH_TEXT_TEXTFIELD_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/display/InteractiveObject.h"
namespace flash
{
    namespace text
    {
        class TextFormat;
    }
}
namespace flash
{
    namespace text
    {
        class StyleSheet;
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
    namespace text
    {
        class TextLineMetrics;
    }
}
namespace flash
{
    namespace display
    {
        class DisplayObject;
    }
}

/**
 * Flash Player dispatches the textInteractionModeChange event when a user
 * changes the interaction mode of a text field.
 */
//[Event(name="textInteractionModeChange",type="flash.events.Event")]

/**
 * Flash Player dispatches the textInput event when a user enters one or more
 * characters of text.
 * @eventType   flash.events.TextEvent.TEXT_INPUT
 */
//[Event(name="textInput",type="flash.events.TextEvent")]

/**
 * Dispatched by a TextField object after the user scrolls.
 * @eventType   flash.events.Event.SCROLL
 */
//[Event(name="scroll",type="flash.events.Event")]

/**
 * Dispatched when a user clicks a hyperlink in an
 * HTML-enabled text field, where the URL begins with "event:".
 * @eventType   flash.events.TextEvent.LINK
 */
//[Event(name="link",type="flash.events.TextEvent")]

/**
 * Dispatched after a control value is modified, unlike
 * the textInput event, which is dispatched before the value is modified.
 * @eventType   flash.events.Event.CHANGE
 */
//[Event(name="change",type="flash.events.Event")]

using namespace flash::display;
using namespace flash::geom;
using namespace flash::text;

namespace flash
{
    namespace text
    {
        /**
         * The TextField class is used to create display objects for text display and input.
         * <ph outputclass="flexonly" class="- topic/ph ">You can use the TextField class to perform low-level text rendering.
         * However, in Flex, you typically use the Label, Text, TextArea, and TextInput controls to process text.</ph><ph outputclass="flashonly" class="- topic/ph ">You can give a text field an instance name in the Property inspector and
         * use the methods and properties of the TextField class to manipulate it with ActionScript.
         * TextField instance names are displayed in the Movie Explorer and in the Insert Target Path dialog box
         * in the Actions panel.</ph><p class="- topic/p ">To create a text field dynamically, use the <codeph class="+ topic/ph pr-d/codeph ">TextField()</codeph> constructor.</p><p class="- topic/p ">The methods of the TextField class let you set, select, and manipulate text in a dynamic or input
         * text field that you create during authoring or at runtime. </p><p class="- topic/p ">ActionScript provides several ways to
         * format your text at runtime. The TextFormat class lets you set character and paragraph formatting
         * for TextField objects. You can apply Cascading Style Sheets (CSS) styles
         * to text fields by using the <codeph class="+ topic/ph pr-d/codeph ">TextField.styleSheet</codeph> property and the StyleSheet class. You can use CSS to
         * style built-in HTML tags, define new formatting tags, or apply styles.
         * You can assign HTML formatted text, which optionally uses CSS styles, directly to a text
         * field. HTML text that you assign to a text field can contain embedded
         * media (movie clips, SWF files, GIF files, PNG files, and JPEG files). The text wraps around the
         * embedded media in the same way that a web browser wraps text around media embedded in an HTML document. </p><p class="- topic/p ">Flash Player supports a subset of HTML tags that you can use to format text. See the list of supported
         * HTML tags in the description of the <codeph class="+ topic/ph pr-d/codeph ">htmlText</codeph> property.</p>
         *
         *   EXAMPLE:
         *
         *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">TextFieldExample</codeph> class to
         * display a text message.  This is accomplished by using the following steps:
         * <ol class="- topic/ol "><li class="- topic/li ">A <codeph class="+ topic/ph pr-d/codeph ">label</codeph> property of type TextField is created.</li><li class="- topic/li ">The class constructor calls the <codeph class="+ topic/ph pr-d/codeph ">configureLabel()</codeph> function.</li><li class="- topic/li "> The <codeph class="+ topic/ph pr-d/codeph ">configureLabel()</codeph> method first creates a new TextField object and assigns it to
         * the <codeph class="+ topic/ph pr-d/codeph ">label</codeph> property, and then sets its parameters to the following:
         * <ul class="- topic/ul "><li class="- topic/li ">Left-justify the text field.</li><li class="- topic/li ">Enable the background fill.</li><li class="- topic/li ">Enable the border.</li></ul></li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">configureLabel()</codeph> method creates the <codeph class="+ topic/ph pr-d/codeph ">format</codeph> variable  and assigns it to
         * a new TextFormat instance with its parameters set to the following:
         * <ul class="- topic/ul "><li class="- topic/li ">Font type = Verdana</li><li class="- topic/li ">Font color = solid red</li><li class="- topic/li ">Font size = 10</li><li class="- topic/li ">Font underline = true</li></ul></li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">defaultTextFormat</codeph> property of the <codeph class="+ topic/ph pr-d/codeph ">label</codeph> text field
         * is set to <codeph class="+ topic/ph pr-d/codeph ">format</codeph>, and the <codeph class="+ topic/ph pr-d/codeph ">label</codeph> instance is added to the display list,
         * which initially displays a text field with no text on the stage.</li><li class="- topic/li ">The constructor sets the text of the <codeph class="+ topic/ph pr-d/codeph ">label</codeph> text field to
         * <codeph class="+ topic/ph pr-d/codeph ">"Hello world and welcome to the show."</codeph> by calling the
         * <codeph class="+ topic/ph pr-d/codeph ">setLabel()</codeph> method.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Sprite;
         * import flash.text.TextField;
         * import flash.text.TextFieldAutoSize;
         * import flash.text.TextFormat;
         *
         *   public class TextFieldExample extends Sprite {
         * private var label:TextField;
         * private var labelText:String = "Hello world and welcome to the show.";
         *
         *   public function TextFieldExample() {
         * configureLabel();
         * setLabel(labelText);
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
         */
        class TextField : public flash::display::InteractiveObject
        {
            /**
             * When set to true and the text field is not in focus, Flash Player highlights the
             * selection in the text field in gray. When set to false and the text field is not in
             * focus, Flash Player does not highlight the selection in the text field.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         alwaysShowSelection();
        public:
            void         alwaysShowSelection(bool value);

            /**
             * The type of anti-aliasing used for this text field. Use flash.text.AntiAliasType
             * constants for this property. You can control this setting only if the font is
             * embedded (with the embedFonts property set to true).
             * The default setting is flash.text.AntiAliasType.NORMAL.
             *
             *   To set values for this property, use the following string values:String valueDescriptionflash.text.AntiAliasType.NORMALApplies the regular text anti-aliasing. This value matches the type of anti-aliasing that
             * Flash Player 7 and earlier versions used.flash.text.AntiAliasType.ADVANCEDApplies advanced anti-aliasing, which makes text more legible. (This feature became
             * available in Flash Player 8.) Advanced anti-aliasing allows for high-quality rendering
             * of font faces at small sizes. It is best used with applications
             * with a lot of small text. Advanced anti-aliasing is not recommended for
             * fonts that are larger than 48 points.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample This example creates two text fields and applies advanced anti-aliasing to the first one
             *   only.  It assumes that you have a font
             *   embedded in the Library with the linkage identifier set to <code>"Times-12"</code>.
             *   To embed the font, follow these steps:
             *   <ol class="- topic/ol "><li class="- topic/li ">Open your Library</li><li class="- topic/li ">Click the Library options menu in the upper right corner of the Library</li><li class="- topic/li ">Select "New Font" from the dropdown list</li><li class="- topic/li ">Name the font "Times-12"</li><li class="- topic/li ">Select "Times New Roman" from the font dropdown list</li><li class="- topic/li ">Press the "OK" button</li><li class="- topic/li ">Right-click on the newly created font and select "Linkage..."</li><li class="- topic/li ">Check the "Export for ActionScript" box</li><li class="- topic/li ">Accept the default identifier "Times-12" by pressing the "OK" button</li></ol><listing version="2.0">
             *   var my_format:TextFormat = new TextFormat();
             *   my_format.font = "Times-12";
             *
             *     var my_text1:TextField = this.createTextField("my_text1", this.getNextHighestDepth(), 10, 10, 300, 30);
             *   my_text1.text = "This text uses advanced anti-aliasing.";
             *   my_text1.antiAliasType = "advanced";
             *   my_text1.border = true;
             *   my_text1.embedFonts = true;
             *   my_text1.setTextFormat(my_format);
             *
             *     var my_text2:TextField = this.createTextField("my_text2", this.getNextHighestDepth(), 10, 50, 300, 30);
             *   my_text2.text = "This text uses normal anti-aliasing."
             *   my_text2.antiAliasType = "normal";
             *   my_text2.border = true;
             *   my_text2.embedFonts = true;
             *   my_text2.setTextFormat(my_format);
             *   </listing>
             */
        public:
            std::string  antiAliasType();
        public:
            void         antiAliasType(std::string antiAliasType);

            /**
             * Controls automatic sizing and alignment of text fields.
             * Acceptable values for the TextFieldAutoSize constants: TextFieldAutoSize.NONE (the default),
             * TextFieldAutoSize.LEFT, TextFieldAutoSize.RIGHT, and TextFieldAutoSize.CENTER.
             *
             *   If autoSize is set to TextFieldAutoSize.NONE (the default) no resizing occurs.If autoSize is set to TextFieldAutoSize.LEFT, the text is
             * treated as left-justified text, meaning that the left margin of the text field remains fixed and any
             * resizing of a single line of the text field is on the right margin. If the text includes a line break
             * (for example, "\n" or "\r"), the bottom is also resized to fit the next
             * line of text. If wordWrap is also set to true, only the bottom
             * of the text field is resized and the right side remains fixed.If autoSize is set to TextFieldAutoSize.RIGHT, the text is treated as
             * right-justified text, meaning that the right margin of the text field remains fixed and any resizing
             * of a single line of the text field is on the left margin. If the text includes a line break
             * (for example, "\n" or "\r"), the bottom is also resized to fit the next
             * line of text. If wordWrap is also set to true, only the bottom
             * of the text field is resized and the left side remains fixed.If autoSize is set to TextFieldAutoSize.CENTER, the text is treated as
             * center-justified text, meaning that any resizing of a single line of the text field is equally distributed
             * to both the right and left margins. If the text includes a line break (for example, "\n" or
             * "\r"), the bottom is also resized to fit the next line of text. If wordWrap is also
             * set to true, only the bottom of the text field is resized and the left and
             * right sides remain fixed.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  ArgumentError The autoSize specified is not a member of flash.text.TextFieldAutoSize.
             */
        public:
            std::string  autoSize();
        public:
            void         autoSize(std::string value);

            /**
             * Specifies whether the text field has a background fill. If true, the text field has a
             * background fill. If false, the text field has no background fill.
             * Use the backgroundColor property to set the background color of a text field.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         background();
        public:
            void         background(bool value);

            /**
             * The color of the text field background. The default value is 0xFFFFFF (white).
             * This property can be retrieved or set, even if there currently is no background, but the
             * color is visible only if the text field has the background property set to
             * true.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int backgroundColor();
        public:
            void         backgroundColor(unsigned int value);

            /**
             * Specifies whether the text field has a border. If true, the text field has a border.
             * If false, the text field has no border. Use the borderColor property
             * to set the border color.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         border();
        public:
            void         border(bool value);

            /**
             * The color of the text field border. The default value is 0x000000 (black).
             * This property can be retrieved or set, even if there currently is no border, but the
             * color is visible only if the text field has the border property set to
             * true.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int borderColor();
        public:
            void         borderColor(unsigned int value);

            /**
             * An integer (1-based index) that indicates the bottommost line that is currently visible in
             * the specified text field. Think of the text field as a window onto a block of text.
             * The scrollV property is the 1-based index of the topmost visible line
             * in the window.
             *
             *   All the text between the lines indicated by scrollV and bottomScrollV
             * is currently visible in the text field.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int          bottomScrollV();

            /**
             * The index of the insertion point (caret) position. If no insertion point is displayed,
             * the value is the position the insertion point would be if you restored focus to the field (typically where the
             * insertion point last was, or 0 if the field has not had focus).
             *
             *   Selection span indexes are zero-based (for example, the first position is 0,
             * the second position is 1, and so on).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int          caretIndex();

            /**
             * A Boolean value that specifies whether extra white space (spaces, line breaks, and so on)
             * in a text field with HTML text is removed. The default value is false.
             * The condenseWhite property only affects text set with
             * the htmlText property, not the text property. If you set
             * text with the text property, condenseWhite is ignored.
             *
             *   If condenseWhite is set to true, use standard HTML commands such as
             * <BR> and <P> to place line breaks in the text field.Set the condenseWhite property before setting the htmlText property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         condenseWhite();
        public:
            void         condenseWhite(bool value);

            /**
             * Specifies the format applied to newly inserted text, such as text entered by a user or text inserted with the
             * replaceSelectedText() method.
             *
             *   Note: When selecting characters to be replaced with setSelection() and
             * replaceSelectedText(), the defaultTextFormat will be applied only if the
             * text has been selected up to and including the last character. Here is an example:
             * var my_txt:TextField new TextField();
             * my_txt.text = "Flash Macintosh version";
             * var my_fmt:TextFormat = new TextFormat();
             * my_fmt.color = 0xFF0000;
             * my_txt.defaultTextFormat = my_fmt;
             * my_txt.setSelection(6,15); // partial text selected - defaultTextFormat not applied
             * my_txt.setSelection(6,23); // text selected to end - defaultTextFormat applied
             * my_txt.replaceSelectedText("Windows version");
             * When you access the defaultTextFormat property, the returned TextFormat object has all
             * of its properties defined. No property is null.Note: You can't set this property if a style sheet is applied to the text field.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error This method cannot be used on a text field with a style sheet.
             */
        public:
            flash::text::TextFormat *defaultTextFormat();
        public:
            void         defaultTextFormat(TextFormat *format);

            /**
             * Specifies whether to render by using embedded font outlines.
             * If false, Flash Player renders the text field by using
             * device fonts.
             *
             *   If you set the embedFonts property to true for a text field,
             * you must specify a font for that text by using the font property of
             * a TextFormat object applied to the text field.
             * If the specified font is not embedded in the SWF file, the text is not displayed.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         embedFonts();
        public:
            void         embedFonts(bool value);

            /**
             * The type of grid fitting used for this text field. This property applies only if the
             * flash.text.AntiAliasType property of the text field is set to flash.text.AntiAliasType.ADVANCED.
             *
             *   The type of grid fitting used determines whether Flash Player forces strong horizontal and
             * vertical lines to fit to a pixel or subpixel grid, or not at all.For the flash.text.GridFitType property, you can use the following string values:String valueDescriptionflash.text.GridFitType.NONESpecifies no grid fitting. Horizontal and vertical lines in the glyphs are not
             * forced to the pixel grid. This setting is recommended for animation or
             * for large font sizes.flash.text.GridFitType.PIXELSpecifies that strong horizontal and vertical lines are fit to the
             * pixel grid. This setting works only for left-aligned text fields.
             * To use this setting, the flash.dispaly.AntiAliasType property of the text field
             * must be set to flash.text.AntiAliasType.ADVANCED.
             * This setting generally provides the best legibility for
             * left-aligned text.flash.text.GridFitType.SUBPIXELSpecifies that strong horizontal and vertical lines are fit to the subpixel grid on
             * an LCD monitor. To use this setting, the
             * flash.text.AntiAliasType property of the text field must be set to
             * flash.text.AntiAliasType.ADVANCED. The flash.text.GridFitType.SUBPIXEL setting is often good
             * for right-aligned or centered
             * dynamic text, and it is sometimes a useful trade-off for animation versus text quality.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @oldexample  This example shows three text fields that use the
             *   different <code>flash.text.GridFitType</code> settings.  It assumes that you have a font
             *   embedded in the Library with the linkage identifier set to <code>"Times-12"</code>.
             *   To embed the font, follow these steps:
             *   <ol class="- topic/ol "><li class="- topic/li ">Open your Library</li><li class="- topic/li ">Click the Library options menu in the upper right corner of the Library</li><li class="- topic/li ">Select "New Font" from the dropdown list</li><li class="- topic/li ">Name the font "Times-12"</li><li class="- topic/li ">Select "Times New Roman" from the font dropdown list</li><li class="- topic/li ">Press the "OK" button</li><li class="- topic/li ">Right-click on the newly created font and select "Linkage..."</li><li class="- topic/li ">Check the "Export for ActionScript" box</li><li class="- topic/li ">Accept the default identifier "Times-12" by pressing the "OK" button</li></ol><listing version="2.0">
             *   var my_format:TextFormat = new TextFormat();
             *   my_format.font = "Times-12";
             *
             *     var my_text1:TextField = this.createTextField("my_text1", this.getNextHighestDepth(), 9.5, 10, 400, 100);
             *   my_text1.text = "this.gridFitType = none";
             *   my_text1.embedFonts = true;
             *   my_text1.antiAliasType = "advanced";
             *   my_text1.gridFitType = "none";
             *   my_text1.setTextFormat(my_format);
             *
             *     var my_text2:TextField = this.createTextField("my_text2", this.getNextHighestDepth(), 9.5, 40, 400, 100);
             *   my_text2.text = "this.gridFitType = advanced";
             *   my_text2.embedFonts = true;
             *   my_text2.antiAliasType = "advanced";
             *   my_text2.gridFitType = "pixel";
             *   my_text2.setTextFormat(my_format);
             *
             *     var my_text3:TextField = this.createTextField("my_text3", this.getNextHighestDepth(), 9.5, 70, 400, 100);
             *   my_text3.text = "this.gridFitType = subpixel";
             *   my_text3.embedFonts = true;
             *   my_text3.antiAliasType = "advanced";
             *   my_text3.gridFitType = "subpixel";
             *   my_text3.setTextFormat(my_format);
             *   </listing>
             */
        public:
            std::string  gridFitType();
        public:
            void         gridFitType(std::string gridFitType);

            /**
             * Contains the HTML representation of the text field contents.
             *
             *   Flash Player supports the following HTML tags:
             * Tag
             *
             *   Description
             *
             *   Anchor tag
             *
             *   The <a> tag creates a hypertext link and supports the following attributes:
             * target: Specifies the name of the target window where you load the page.
             * Options include _self, _blank, _parent, and
             * _top. The _self option specifies the current frame in the current window,
             * _blank specifies a new window, _parent specifies the parent of the
             * current frame, and _top specifies the top-level frame in the current window.
             * href: Specifies a URL or an ActionScript link event.The URL can
             * be either absolute or relative to the location of the SWF file that
             * is loading the page. An example of an absolute reference to a URL is
             * http://www.adobe.com; an example of a relative reference is
             * /index.html. Absolute URLs must be prefixed with
             * http://; otherwise, Flash Player or AIR treats them as relative URLs.
             *
             *   You can use the link event to cause the link to execute an ActionScript
             * function in a SWF file instead of opening a URL. To specify a link event, use
             * the event scheme instead of the http scheme in your href attribute. An example
             * is href="event:myText" instead of href="http://myURL"; when the
             * user clicks a hypertext link that contains the event scheme, the text field dispatches a
             * link TextEvent with its text property set to "myText". You can then create an ActionScript
             * function that executes whenever the link TextEvent is dispatched.
             *
             *   You can also define a:link, a:hover, and a:active
             * styles for anchor tags by using style sheets.
             *
             *   Bold tag
             *
             *   The <b> tag renders text as bold. A bold typeface must be available for the font used.
             *
             *   Break tag
             *
             *   The <br> tag creates a line break in the text field. Set the text field to
             * be a multiline text field to use this tag.
             *
             *   Font tag
             *
             *   The <font> tag specifies a font or list of fonts to display the text.The font tag
             * supports the following attributes:
             * color: Only hexadecimal color (#FFFFFF) values are supported.
             * face: Specifies the name of the font to use. As shown in the following example,
             * you can specify a list of comma-delimited font names, in which case Flash Player selects the first available
             * font. If the specified font is not installed on the local computer system or isn't embedded in the SWF file,
             * Flash Player selects a substitute font.
             * size: Specifies the size of the font. You can use absolute pixel sizes, such as 16 or 18,
             * or relative point sizes, such as +2 or -4.
             *
             *   Image tag
             *
             *   The <img> tag lets you embed external image files (JPEG, GIF, PNG), SWF files, and
             * movie clips inside text fields. Text automatically flows around images you embed in text fields. You
             * must set the text field to be multiline to wrap text around an image.
             *
             *   The <img> tag supports the following attributes: src: Specifies the URL to an image or SWF file, or the linkage identifier for a movie clip
             * symbol in the library. This attribute is required; all other attributes are optional. External files (JPEG, GIF, PNG,
             * and SWF files) do not show until they are downloaded completely.
             * width: The width of the image, SWF file, or movie clip being inserted, in pixels.
             * height: The height of the image, SWF file, or movie clip being inserted, in pixels.
             * align: Specifies the horizontal alignment of the embedded image within the text field.
             * Valid values are left and right. The default value is left.
             * hspace: Specifies the amount of horizontal space that surrounds the image where
             * no text appears. The default value is 8.
             * vspace: Specifies the amount of vertical space that surrounds the image where no
             * text appears. The default value is 8.
             * id: Specifies the name for the movie clip instance (created by Flash Player) that contains
             * the embedded image file, SWF file, or movie clip. This approach is used to control the embedded content with
             * ActionScript.
             * checkPolicyFile: Specifies that Flash Player checks for a URL policy file
             * on the server associated with the image domain. If a policy file exists, SWF files in the domains
             * listed in the file can access the data of the loaded image, for example, by calling the
             * BitmapData.draw() method with this image as the source parameter.
             * For more information related to security, see the Flash Player Developer Center Topic:
             * Security.
             *
             *   Flash displays media embedded in a text field at full size. To specify the dimensions of the media
             * you are embedding, use the <img> tag height and width
             * attributes. In general, an image embedded in a text field appears on the line following the
             * <img> tag. However, when the <img> tag
             * is the first character in the text field, the image appears on the first line of the text field. For AIR content in the application security sandbox, AIR ignores img tags in
             * HTML content in ActionScript TextField objects. This is to prevent possible phishing attacks,
             * Italic tag
             *
             *   The <i> tag displays the tagged text in italics. An italic typeface must be available
             * for the font used.
             *
             *   List item tag
             *
             *   The <li> tag places a bullet in front of the text that it encloses.
             * Note: Because Flash Player and AIR do not recognize ordered and unordered list tags (<ol>
             * and <ul>, they do not modify how your list is rendered. All lists are unordered and all
             * list items use bullets.
             *
             *   Paragraph tag
             *
             *   The <p> tag creates a new paragraph. The text field must be set to be a multiline
             * text field to use this tag.
             *
             *   The <p> tag supports the following attributes:
             *
             *   align: Specifies alignment of text within the paragraph; valid values are left, right, justify, and center.
             *
             *   class: Specifies a CSS style class defined by a flash.text.StyleSheet object.
             *
             *   Span tag
             *
             *   The <span> tag is available only for use with CSS text styles. It supports the
             * following attribute:
             *
             *   class: Specifies a CSS style class defined by a flash.text.StyleSheet object.
             *
             *   Text format tag
             * The <textformat> tag lets you use a subset of paragraph formatting
             * properties of the TextFormat class within text fields, including line leading, indentation,
             * margins, and tab stops. You can combine <textformat> tags with the
             * built-in HTML tags. The <textformat> tag has the following attributes: blockindent: Specifies the block indentation in points; corresponds to
             * TextFormat.blockIndent.
             * indent: Specifies the indentation from the left margin to the first character
             * in the paragraph; corresponds to TextFormat.indent. Both positive and negative
             * numbers are acceptable.
             * leading: Specifies the amount of leading (vertical space) between lines;
             * corresponds to TextFormat.leading. Both positive and negative numbers are acceptable.
             * leftmargin: Specifies the left margin of the paragraph, in points; corresponds
             * to TextFormat.leftMargin.
             * rightmargin: Specifies the right margin of the paragraph, in points; corresponds
             * to TextFormat.rightMargin.
             * tabstops: Specifies custom tab stops as an array of non-negative integers;
             * corresponds to TextFormat.tabStops.
             *
             *   Underline tag
             *
             *   The <u> tag underlines the tagged text.
             * Flash Player and AIR support the following HTML entities:
             * Entity
             *
             *   Description
             *
             *   &amp;lt;
             *
             *   < (less than)
             *
             *   &amp;gt;
             *
             *   > (greater than)
             *
             *   &amp;amp;
             *
             *   & (ampersand)
             *
             *   &amp;quot;
             *
             *   " (double quotes)
             *
             *   &amp;apos;
             *
             *   ' (apostrophe, single quote)
             *
             *   Flash Player and AIR also support explicit character codes, such as
             * &#38; (ASCII ampersand) and &#x20AC; (Unicode     symbol).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  htmlText();
        public:
            void         htmlText(std::string value);

            /**
             * The number of characters in a text field. A character such as tab (\t) counts as one
             * character.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int          length();

            /**
             * The interaction mode property, Default value is TextInteractionMode.NORMAL.
             * On mobile platforms, the normal mode implies that the text can be scrolled but not selected.
             * One can switch to the selectable mode through the in-built context menu on the text field.
             * On Desktop, the normal mode implies that the text is in scrollable as well as selection mode.
             * @langversion 3.0
             * @playerversion   Flash 11
             * @playerversion   Lite 4
             */
        public:
            std::string  textInteractionMode();

            /**
             * The maximum number of characters that the text field can contain, as entered by a user.
             * A script can insert more text than maxChars allows; the maxChars property
             * indicates only how much text a user can enter. If the value of this property is 0,
             * a user can enter an unlimited amount of text.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int          maxChars();
        public:
            void         maxChars(int value);

            /**
             * The maximum value of scrollH.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int          maxScrollH();

            /**
             * The maximum value of scrollV.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int          maxScrollV();

            /**
             * A Boolean value that indicates whether Flash Player automatically scrolls multiline
             * text fields when the user clicks a text field and rolls the mouse wheel.
             * By default, this value is true. This property is useful if you want to prevent
             * mouse wheel scrolling of text fields, or implement your own text field scrolling.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool         mouseWheelEnabled();
        public:
            void         mouseWheelEnabled(bool value);

            /**
             * Indicates whether field is a multiline text field. If the value is true,
             * the text field is multiline; if the value is false, the text field is a single-line
             * text field. In a field of type TextFieldType.INPUT, the multiline value
             * determines whether the Enter key creates a new line (a value of false,
             * and the Enter key is ignored).
             * If you paste text into a TextField with a multiline value of false,
             * newlines are stripped out of the text.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         multiline();
        public:
            void         multiline(bool value);

            /**
             * Defines the number of text lines in a multiline text field.
             * If wordWrap property is set to true,
             * the number of lines increases when text wraps.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int          numLines();

            /**
             * Specifies whether the text field is a password text field. If the value of this property is true,
             * the text field is treated as a password text field and hides the input characters using asterisks instead of the
             * actual characters. If false, the text field is not treated as a password text field. When password mode
             * is enabled, the Cut and Copy commands and their corresponding keyboard shortcuts will
             * not function.  This security mechanism prevents an unscrupulous user from using the shortcuts to discover
             * a password on an unattended computer.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         displayAsPassword();
        public:
            void         displayAsPassword(bool value);

            /**
             * Indicates the set of characters that a user can enter into the text field. If the value of the
             * restrict property is null, you can enter any character. If the value of
             * the restrict property is an empty string, you cannot enter any character. If the value
             * of the restrict property is a string of characters, you can enter only characters in
             * the string into the text field. The string is scanned from left to right. You can specify a range by
             * using the hyphen (-) character. Only user interaction is restricted; a script can put any text into the
             * text field. This property does not synchronize with the Embed font options
             * in the Property inspector.If the string begins with a caret (^) character, all characters are initially accepted and
             * succeeding characters in the string are excluded from the set of accepted characters. If the string does
             * not begin with a caret (^) character, no characters are initially accepted and succeeding characters in the
             * string are included in the set of accepted characters.The following example allows only uppercase characters, spaces, and numbers to be entered into
             * a text field:
             * my_txt.restrict = "A-Z 0-9";
             * The following example includes all characters, but excludes lowercase letters:
             * my_txt.restrict = "^a-z";
             * You can use a backslash to enter a ^ or - verbatim. The accepted backslash sequences are \-, \^ or \\.
             * The backslash must be an actual character in the string, so when specified in ActionScript, a double backslash
             * must be used. For example, the following code includes only the dash (-) and caret (^):
             * my_txt.restrict = "\\-\\^";
             * The ^ can be used anywhere in the string to toggle between including characters and excluding characters.
             * The following code includes only uppercase letters, but excludes the uppercase letter Q:
             * my_txt.restrict = "A-Z^Q";
             * You can use the \u escape sequence to construct restrict strings.
             * The following code includes only the characters from ASCII 32 (space) to ASCII 126 (tilde).
             * my_txt.restrict = "\u0020-\u007E";
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  restrict();
        public:
            void         restrict(std::string value);

            /**
             * The current horizontal scrolling position. If the scrollH property is 0, the text
             * is not horizontally scrolled. This property value is an integer that represents the horizontal
             * position in pixels.
             *
             *   The units of horizontal scrolling are pixels, whereas the units of vertical scrolling are lines.
             * Horizontal scrolling is measured in pixels because most fonts you typically use are proportionally
             * spaced; that is, the characters can have different widths. Flash Player performs vertical scrolling by
             * line because users usually want to see a complete line of text rather than a
             * partial line. Even if a line uses multiple fonts, the height of the line adjusts to fit
             * the largest font in use.Note: The scrollH property is zero-based, not 1-based like
             * the scrollV vertical scrolling property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int          scrollH();
        public:
            void         scrollH(int value);

            /**
             * The vertical position of text in a text field. The scrollV property is useful for
             * directing users to a specific paragraph in a long passage, or creating scrolling text fields.
             *
             *   The units of vertical scrolling are lines, whereas the units of horizontal scrolling are pixels.
             * If the first line displayed is the first line in the text field, scrollV is set to 1 (not 0).
             * Horizontal scrolling is measured in pixels because most fonts are proportionally
             * spaced; that is, the characters can have different widths. Flash performs vertical scrolling by line
             * because users usually want to see a complete line of text rather than a partial line.
             * Even if there are multiple fonts on a line, the height of the line adjusts to fit the largest font in
             * use.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int          scrollV();
        public:
            void         scrollV(int value);

            /**
             * A Boolean value that indicates whether the text field is selectable. The value true
             * indicates that the text is selectable. The selectable property controls whether
             * a text field is selectable, not whether a text field is editable. A dynamic text field can
             * be selectable even if it is not editable. If a dynamic text field is not selectable, the user
             * cannot select its text.
             *
             *   If selectable is set to false, the text in the text field does not
             * respond to selection commands from the mouse or keyboard, and the text cannot be copied with the
             * Copy command. If selectable is set to true, the text in the text field
             * can be selected with the mouse or keyboard, and the text can be copied with the Copy command.
             * You can select text this way even if the text field is a dynamic text field instead of an input text field.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         selectable();
        public:
            void         selectable(bool value);

        public:
            std::string  selectedText();

            /**
             * The zero-based character index value of the first character in the current selection.
             * For example, the first character is 0, the second character is 1, and so on. If no
             * text is selected, this property is the value of caretIndex.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int          selectionBeginIndex();

            /**
             * The zero-based character index value of the last character in the current selection.
             * For example, the first character is 0, the second character is 1, and so on. If no
             * text is selected, this property is the value of caretIndex.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int          selectionEndIndex();

            /**
             * The sharpness of the glyph edges in this text field. This property applies
             * only if the flash.text.AntiAliasType property of the text field is set to
             * flash.text.AntiAliasType.ADVANCED. The range for
             * sharpness is a number from -400 to 400. If you attempt to set
             * sharpness to a value outside that range, Flash sets the property to
             * the nearest value in the range (either -400 or 400).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @oldexample  This example creates three text fields with
             *   <code>sharpness</code> set to <code>400</code>, <code>0</code>, and <code>-400</code>.
             *   It assumes that you have a font
             *   embedded in the Library with the linkage identifier set to <code>"Times-12"</code>.
             *   To embed the font, follow these steps:
             *   <ol class="- topic/ol "><li class="- topic/li ">Open your Library</li><li class="- topic/li ">Click the Library options menu in the upper right corner of the Library</li><li class="- topic/li ">Select "New Font" from the dropdown list</li><li class="- topic/li ">Name the font "Times-12"</li><li class="- topic/li ">Select "Times New Roman" from the font dropdown list</li><li class="- topic/li ">Press the "OK" button</li><li class="- topic/li ">Right-click on the newly created font and select "Linkage..."</li><li class="- topic/li ">Check the "Export for ActionScript" box</li><li class="- topic/li ">Accept the default identifier "Times-12" by pressing the "OK" button</li></ol><listing version="2.0">
             *   var my_format:TextFormat = new TextFormat();
             *   my_format.font = "Times-12";
             *
             *     var my_text1:TextField = this.createTextField("my_text1", this.getNextHighestDepth(), 10, 10, 400, 100);
             *   my_text1.text = "This text has sharpness set to 400."
             *   my_text1.embedFonts = true;
             *   my_text1.antiAliasType = "advanced";
             *   my_text1.gridFitType = "pixel";
             *   my_text1.sharpness = 400;
             *   my_text1.setTextFormat(my_format);
             *
             *     var my_text2:TextField = this.createTextField("my_text2", this.getNextHighestDepth(), 10, 40, 400, 100);
             *   my_text2.text = "This text has sharpness set to 0."
             *   my_text2.embedFonts = true;
             *   my_text2.antiAliasType = "advanced";
             *   my_text2.gridFitType = "pixel";
             *   my_text2.sharpness = 0;
             *   my_text2.setTextFormat(my_format);
             *
             *     var my_text3:TextField = this.createTextField("my_text3", this.getNextHighestDepth(), 10, 70, 400, 100);
             *   my_text3.text = "This text has sharpness set to -400."
             *   my_text3.embedFonts = true;
             *   my_text3.antiAliasType = "advanced";
             *   my_text3.gridFitType = "pixel";
             *   my_text3.sharpness = -400;
             *   my_text3.setTextFormat(my_format);
             *   </listing>
             */
        public:
            float        sharpness();
        public:
            void         sharpness(float value);

            /**
             * Attaches a style sheet to the text field. For information on creating style sheets, see the StyleSheet class
             * and the ActionScript 3.0 Developer's Guide.
             *
             *   You can change the style sheet associated with a text field at any time. If you change
             * the style sheet in use, the text field is redrawn with the new style sheet.
             * You can set the style sheet to null or undefined
             * to remove the style sheet. If the style sheet in use is removed, the text field is redrawn without a style sheet. Note: If the style sheet is removed, the contents of both TextField.text and
             * TextField.htmlText change to incorporate the formatting previously applied by the style sheet. To preserve
             * the original TextField.htmlText contents without the formatting, save the value in a variable before
             * removing the style sheet.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::text::StyleSheet *styleSheet();
        public:
            void         styleSheet(StyleSheet *value);

            /**
             * A string that is the current text in the text field. Lines are separated by the carriage
             * return character ('\r', ASCII 13). This property contains unformatted text in the text
             * field, without HTML tags.
             *
             *   To get the text in HTML form, use the htmlText property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  text();
        public:
            void         text(std::string value);

            /**
             * The color of the text in a text field, in hexadecimal format.
             * The hexadecimal color system uses six digits to represent
             * color values. Each digit has 16 possible values or characters. The characters range from
             * 0-9 and then A-F. For example, black is 0x000000; white is
             * 0xFFFFFF.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int textColor();
        public:
            void         textColor(unsigned int value);

            /**
             * The height of the text in pixels.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float        textHeight();

            /**
             * The width of the text in pixels.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            float        textWidth();

            /**
             * The thickness of the glyph edges in this text field. This property applies only
             * when flash.text.AntiAliasType is set to flash.text.AntiAliasType.ADVANCED.
             *
             *   The range for thickness is a number from -200 to 200. If you attempt to
             * set thickness to a value outside that range, the property is set to the
             * nearest value in the range (either -200 or 200).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @oldexample  This example creates two text fields and applies a <code>thickness</code> of -200 to one
             *   and 200 to the other.  It assumes that you have a font
             *   embedded in the Library with the linkage identifier set to <code>"Times-12"</code>.
             *   To embed the font, follow these steps:
             *   <ol class="- topic/ol "><li class="- topic/li ">Open your Library</li><li class="- topic/li ">Click the Library options menu in the upper right corner of the Library</li><li class="- topic/li ">Select "New Font" from the dropdown list</li><li class="- topic/li ">Name the font "Times-12"</li><li class="- topic/li ">Select "Times New Roman" from the font dropdown list</li><li class="- topic/li ">Press the "OK" button</li><li class="- topic/li ">Right-click on the newly created font and select "Linkage..."</li><li class="- topic/li ">Check the "Export for ActionScript" box</li><li class="- topic/li ">Accept the default identifier "Times-12" by pressing the "OK" button</li></ol><listing version="2.0">
             *   var my_format:TextFormat = new TextFormat();
             *   my_format.font = "Times-12";
             *
             *     var my_text1:TextField = this.createTextField("my_text1", this.getNextHighestDepth(), 10, 10, 300, 30);
             *   my_text1.text = "thickness = 200";
             *   my_text1.antiAliasType = "advanced";
             *   my_text1.border = true;
             *   my_text1.thickness = 200;
             *   my_text1.embedFonts = true;
             *   my_text1.setTextFormat(my_format);
             *
             *     var my_text2:TextField = this.createTextField("my_text2", this.getNextHighestDepth(), 10, 50, 300, 30);
             *   my_text2.text = "thickness = -200."
             *   my_text2.antiAliasType = "advanced";
             *   my_text2.thickness = -200;
             *   my_text2.border = true;
             *   my_text2.embedFonts = true;
             *   my_text2.setTextFormat(my_format);
             *   </listing>
             */
        public:
            float        thickness();
        public:
            void         thickness(float value);

            /**
             * The type of the text field.
             * Either one of the following TextFieldType constants: TextFieldType.DYNAMIC,
             * which specifies a dynamic text field, which a user cannot edit, or TextFieldType.INPUT,
             * which specifies an input text field, which a user can edit.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  ArgumentError The type specified is not a member of flash.text.TextFieldType.
             */
        public:
            std::string  type();
        public:
            void         type(std::string value);

            /**
             * A Boolean value that indicates whether the text field has word wrap. If the value of
             * wordWrap is true, the text field has word wrap;
             * if the value is false, the text field does not have word wrap. The default
             * value is false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         wordWrap();
        public:
            void         wordWrap(bool value);

            /**
             * Specifies whether to copy and paste the text formatting along with the text. When set to true,
             * Flash Player copies and pastes formatting (such as alignment, bold, and italics) when you copy and paste between text fields. Both the origin and destination text fields for the copy and paste procedure must have
             * useRichTextClipboard set to true. The default value
             * is false.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            bool         useRichTextClipboard();
        public:
            void         useRichTextClipboard(bool value);

            /**
             * Returns true if an embedded font is available with the specified fontName and fontStyle
             * where Font.fontType is flash.text.FontType.EMBEDDED.  Starting with Flash Player 10,
             * two kinds of embedded fonts can appear in a SWF file.  Normal embedded fonts are only used with
             * TextField objects.
             * CFF embedded fonts are only used with the flash.text.engine classes.  The two types are distinguished by the
             * fontType property of the Font class, as returned by the enumerateFonts() function.
             *
             *   TextField cannot use a font of type EMBEDDED_CFF. If embedFonts is set to true
             * and the only font available at run time with the specified name and style is of type EMBEDDED_CFF,
             * Flash Player fails to render the text, as if no embedded font were available with the specified name and style.If both EMBEDDED and EMBEDDED_CFF fonts are available with the same name and style, the EMBEDDED
             * font is selected and text renders with the EMBEDDED font.
             * @param   fontName    The name of the embedded font to check.
             * @param   fontStyle   Specifies the font style to check.  Use flash.text.FontStyle
             * @return  true if a compatible embedded font is available, otherwise false.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             * @throws  ArgumentError The fontStyle specified is not a member of flash.text.FontStyle.
             */
        public:
            static bool     isFontCompatible(std::string fontName, std::string fontStyle);

            /**
             * Creates a new TextField instance. After you create the TextField instance, call the
             * addChild() or addChildAt() method of the parent
             * DisplayObjectContainer object to add the TextField instance to the display list.
             * The default size for a text field is 100 x 100 pixels.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            TextField();

            /**
             * Appends the string specified by the newText parameter to the end of the text
             * of the text field. This method is more efficient than an addition assignment (+=) on
             * a text property (such as someTextField.text += moreText),
             * particularly for a text field that contains a significant amount of content.
             * @param   newText The string to append to the existing text.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     appendText(std::string newText);

            std::string copyRichText();

            /**
             * Returns a rectangle that is the bounding box of the character.
             * @param   charIndex   The zero-based index value for the character (for example, the first
             *   position is 0, the second position is 1, and so on).
             * @return  A rectangle with x and y minimum and maximum values
             *   defining the bounding box of the character.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::geom::Rectangle *getCharBoundaries(int charIndex);

            /**
             * Returns the zero-based index value of the character at the point specified by the x
             * and y parameters.
             * @param   x   The x coordinate of the character.
             * @param   y   The y coordinate of the character.
             * @return  The zero-based index value of the character (for example, the first position is 0,
             *   the second position is 1, and so on).  Returns -1 if the point is not over any character.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int      getCharIndexAtPoint(float x, float y);

            /**
             * Given a character index, returns the index of the first character in the same paragraph.
             * @param   charIndex   The zero-based index value of the character (for example, the first character is 0,
             *   the second character is 1, and so on).
             * @return  The zero-based index value of the first character in the same paragraph.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  RangeError The character index specified is out of range.
             */
        public:
            int      getFirstCharInParagraph(int charIndex);

            /**
             * Returns the zero-based index value of the line at the point specified by the x
             * and y parameters.
             * @param   x   The x coordinate of the line.
             * @param   y   The y coordinate of the line.
             * @return  The zero-based index value of the line (for example, the first line is 0, the
             *   second line is 1, and so on).  Returns -1 if the point is not over any line.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int      getLineIndexAtPoint(float x, float y);

            /**
             * Returns the zero-based index value of the line containing the character specified
             * by the charIndex parameter.
             * @param   charIndex   The zero-based index value of the character (for example, the first character is 0,
             *   the second character is 1, and so on).
             * @return  The zero-based index value of the line.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  RangeError The character index specified is out of range.
             */
        public:
            int      getLineIndexOfChar(int charIndex);

            /**
             * Returns the number of characters in a specific text line.
             * @param   lineIndex   The line number for which you want the length.
             * @return  The number of characters in the line.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  RangeError The line number specified is out of range.
             */
        public:
            int      getLineLength(int lineIndex);

            /**
             * Returns metrics information about a given text line.
             * @param   lineIndex   The line number for which you want metrics information.
             * @return  A TextLineMetrics object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  RangeError The line number specified is out of range.
             */
        public:
            flash::text::TextLineMetrics *getLineMetrics(int lineIndex);

            /**
             * Returns the character index of the first character in the line that
             * the lineIndex parameter specifies.
             * @param   lineIndex   The zero-based index value of the line (for example, the first line is 0,
             *   the second line is 1, and so on).
             * @return  The zero-based index value of the first character in the line.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  RangeError The line number specified is out of range.
             */
        public:
            int      getLineOffset(int lineIndex);

            /**
             * Returns the text of the line specified by the lineIndex parameter.
             * @param   lineIndex   The zero-based index value of the line (for example, the first line is 0,
             *   the second line is 1, and so on).
             * @return  The text string contained in the specified line.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  RangeError The line number specified is out of range.
             */
        public:
            std::string getLineText(int lineIndex);

            /**
             * Given a character index, returns the length of the paragraph containing the given character.
             * The length is relative to the first character in the paragraph (as returned by
             * getFirstCharInParagraph()), not to the character index passed in.
             * @param   charIndex   The zero-based index value of the character (for example, the first character is 0,
             *   the second character is 1, and so on).
             * @return  Returns the number of characters in the paragraph.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  RangeError The character index specified is out of range.
             */
        public:
            int      getParagraphLength(int charIndex);

            /**
             * Returns a TextFormat object that contains formatting information for the range of text that the
             * beginIndex and endIndex parameters specify. Only properties
             * that are common to the entire text specified are set in the resulting TextFormat object.
             * Any property that is mixed, meaning that it has different values
             * at different points in the text, has a value of null.
             *
             *   If you do not specify
             * values for these parameters, this method is applied to all the text in the text field.  The following table describes three possible usages:UsageDescriptionmy_textField.getTextFormat()Returns a TextFormat object containing formatting information for all text in a text field.
             * Only properties that are common to all text in the text field are set in the resulting TextFormat
             * object. Any property that is mixed, meaning that it has different values at different
             * points in the text, has a value of null.my_textField.getTextFormat(beginIndex:Number)Returns a TextFormat object containing a copy of the text format of the character at the
             * beginIndex position.my_textField.getTextFormat(beginIndex:Number,endIndex:Number)Returns a TextFormat object containing formatting information for the span of
             * text from beginIndex to endIndex-1. Only properties that are common
             * to all of the text in the specified range are set in the resulting TextFormat object. Any property
             * that is mixed (that is, has different values at different points in the range) has its value set to null.
             * @param   beginIndex  Optional; an integer that specifies the starting location of a range of text within the text field.
             * @param   endIndex    Optional; an integer that specifies the position of the first character after the desired
             *   text span. As designed, if you specify beginIndex and endIndex values,
             *   the text from beginIndex to endIndex-1 is read.
             * @return  The TextFormat object that represents the formatting properties for the specified text.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  RangeError The beginIndex or endIndex specified is out of range.
             */
        public:
            flash::text::TextFormat *getTextFormat(int beginIndex=-1, int endIndex=-1);

        public:
            std::vector<void *> getTextRuns(int beginIndex=0, int endIndex=2147483647);

        public:
            std::string getRawText();

        public:
            std::string getXMLText(int beginIndex=0, int endIndex=2147483647);

        public:
            void     insertXMLText(int beginIndex, int endIndex, std::string richText, bool pasting   =false);

            bool     pasteRichText(std::string richText);

            /**
             * Replaces the current selection with the contents of the value parameter.
             * The text is inserted at the position of the current selection, using the current default character
             * format and default paragraph format. The text is not treated as HTML.
             *
             *   You can use the replaceSelectedText() method to insert and delete text without disrupting
             * the character and paragraph formatting of the rest of the text.Note: This method does not work if a style sheet is applied to the text field.
             * @param   value   The string to replace the currently selected text.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error This method cannot be used on a text field with a style sheet.
             */
        public:
            void     replaceSelectedText(std::string value);

            /**
             * Replaces the range of characters that the beginIndex and
             * endIndex parameters specify with the contents
             * of the newText parameter. As designed, the text from
             * beginIndex to endIndex-1 is replaced.
             * Note: This method does not work if a style sheet is applied to the text field.
             * @param   beginIndex  The zero-based index value for the start position of the replacement range.
             * @param   endIndex    The zero-based index position of the first character after the desired
             *   text span.
             * @param   newText The text to use to replace the specified range of characters.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error This method cannot be used on a text field with a style sheet.
             */
        public:
            void     replaceText(int beginIndex, int endIndex, std::string newText);

            /**
             * Sets as selected the text designated by the index values of the
             * first and last characters, which are specified with the beginIndex
             * and endIndex parameters. If the two parameter values are the same,
             * this method sets the insertion point, as if you set the
             * caretIndex property.
             * @param   beginIndex  The zero-based index value of the first character in the selection
             *   (for example, the first character is 0, the second character is 1, and so on).
             * @param   endIndex    The zero-based index value of the last character in the selection.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    Need to add an example.
             */
        public:
            void     setSelection(int beginIndex, int endIndex);

            /**
             * Applies the text formatting that the format parameter specifies to the specified text in a text field.
             * The value of format must be a TextFormat object that specifies the
             * desired text formatting changes. Only the non-null properties of format are applied
             * to the text field. Any property of format that is set to null is not
             * applied. By default, all of the properties of a newly created TextFormat object are set to null.
             * Note: This method does not work if a style sheet is applied to the text field.The setTextFormat() method changes the text formatting applied to a range of
             * characters or to the entire body of text in a text field. To apply the properties of format to all text in the text
             * field, do not specify values for beginIndex and endIndex. To apply the
             * properties of the format to a range of text, specify values for the beginIndex and
             * the endIndex parameters. You can use the length property to determine
             * the index values.The two types of formatting information in a TextFormat object are
             * character level formatting and paragraph level formatting.
             * Each character in a text field can have its own character formatting
             * settings, such as font name, font size, bold, and italic.For paragraphs, the first character of the paragraph is examined for the paragraph formatting
             * settings for the entire paragraph. Examples of paragraph formatting settings are left margin,
             * right margin, and indentation.Any text inserted manually by the user, or replaced by the
             * replaceSelectedText() method, receives the default text field formatting for new text,
             * and not the formatting specified for the text insertion point. To set the default
             * formatting for new text, use defaultTextFormat.
             * @param   format  A TextFormat object that contains character and paragraph formatting information.
             * @param   beginIndex  Optional; an integer that specifies the zero-based index position specifying the
             *   first character of the desired range of text.
             * @param   endIndex    Optional; an integer that specifies the first character after the desired text span.
             *   As designed, if you specify beginIndex and endIndex values,
             *   the text from beginIndex to endIndex-1 is updated.
             *
             *     UsageDescriptionmy_textField.setTextFormat(textFormat:TextFormat)Applies the properties of textFormat to all text in the text
             *   field.my_textField.setTextFormat(textFormat:TextFormat, beginIndex:int)Applies the properties of textFormat to the text starting with the
             *   beginIndex position.my_textField.setTextFormat(textFormat:TextFormat, beginIndex:int,
             *   endIndex:int)Applies the properties of the textFormat parameter to the span of
             *   text from the beginIndex position to the endIndex-1 position.Notice that any text inserted manually by the user, or replaced by the
             *   replaceSelectedText() method, receives the default text field formatting for new
             *   text, and not the formatting specified for the text insertion point. To set a text field's
             *   default formatting for new text, use the defaultTextFormat property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  Error This method cannot be used on a text field with a style sheet.
             * @throws  RangeError The beginIndex or endIndex specified is out of range.
             */
        public:
            void     setTextFormat(TextFormat *format, int beginIndex=-1, int endIndex=-1);

            /**
             * Returns a DisplayObject reference for the given id, for an image or SWF file
             * that has been added to an HTML-formatted text field by using an <img> tag.
             * The <img> tag is in the following format:
             *
             *   <img src = 'filename.jpg' id = 'instanceName' >
             * @param   id  The id to match (in the id attribute of the
             *   <img> tag).
             * @return  The display object corresponding to the image or SWF file with the matching id
             *   attribute in the <img> tag of the text field. For media loaded from an external source,
             *   this object is a Loader object, and, once loaded, the media object is a child of that Loader object. For media
             *   embedded in the SWF file, it is the loaded object. If no <img> tag with
             *   the matching id exists, the method returns null.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::display::DisplayObject *getImageReference(std::string id);
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_TEXTFIELD_AS
#endif // __cplusplus

