#if !defined(FLEX11_6_FLASH_TEXT_ENGINE_FONTDESCRIPTION_AS)
#define FLEX11_6_FLASH_TEXT_ENGINE_FONTDESCRIPTION_AS
#if defined(__cplusplus)




/**
 * The FontDescription class represents the information necessary to describe a font.
 *
 *   <p class="- topic/p ">A FontDescription object is applied to an ElementFormat,
 * which is in turn applied to a ContentElement in a TextBlock. Once a FontDescription has been
 * applied to an ElementFormat, its <codeph class="+ topic/ph pr-d/codeph ">locked</codeph> property is set to <codeph class="+ topic/ph pr-d/codeph ">true</codeph>.
 * The properties of a locked FontDescription object cannot be changed. Instead, use the <codeph class="+ topic/ph pr-d/codeph ">clone()</codeph>
 * method to create an unlocked copy of the object, which can be modified and assigned to the ElementFormat.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> FTE (Flash Text Engine) does not support Type 1 fonts or bitmap fonts such as Type 3,
 * ATC, sfnt-wrapped CID, or Naked CID.</p>
 *
 *   EXAMPLE:
 *
 *   <p class="- topic/p ">This example creates a <codeph class="+ topic/ph pr-d/codeph ">FontDescription</codeph> object, assigns
 * a device font to it, sets various font properties,
 * and assigns the new object to an <codeph class="+ topic/ph pr-d/codeph ">ElementFormat</codeph> object.
 * Additional font formatting is done within <codeph class="+ topic/ph pr-d/codeph ">ElementFormat</codeph>. A new
 * <codeph class="+ topic/ph pr-d/codeph ">TextElement</codeph> is created, using the <codeph class="+ topic/ph pr-d/codeph ">ElementFormat</codeph>, and
 * the <codeph class="+ topic/ph pr-d/codeph ">TextElement</codeph> is used as content for a <codeph class="+ topic/ph pr-d/codeph ">TextBlock</codeph>. A
 * line of text is created from the <codeph class="+ topic/ph pr-d/codeph ">TextBlock</codeph>.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 *
 *   import flash.display.Sprite;
 * import flash.text.engine.*;
 *
 *   public class FontDescriptionExample extends Sprite {
 *
 *   public function FontDescriptionExample():void {
 * var fd:FontDescription = new FontDescription();
 * fd.fontLookup = flash.text.engine.FontLookup.DEVICE;
 * fd.fontName = "Palatino";
 * fd.fontWeight = flash.text.engine.FontWeight.BOLD;
 * fd.fontPosture = flash.text.engine.FontPosture.ITALIC;
 *
 *   var ef1:ElementFormat = new ElementFormat(fd);
 * ef1.fontSize = 30;
 * ef1.color = 0xFF0000;
 *
 *   var str:String = "This is flash text 0123456789";
 * var tb:TextBlock = new TextBlock();
 * var te1:TextElement = new TextElement(str, ef1);
 * tb.content = te1;
 * var line1:TextLine = tb.createTextLine(null, 600);
 * addChild(line1);
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

namespace flash
{
    namespace text
    {
        namespace engine
        {
            class FontDescription: public Object
            {
                /**
                 * The rendering mode used for this text. Use RenderingMode
                 * constants for this property.
                 *
                 *   Applies only to embedded fonts.The default value is RenderingMode.CFF.To set values for this property, use the following constants from the RenderingMode class:String valueDescriptionRenderingMode.NORMALApplies the regular text rendering, which matches the type of rendering that
                 * Flash Player 7 and earlier versions used.RenderingMode.CFFApplies CFF (Compact Font Format) rendering, which makes text more legible. (This feature became
                 * available in Flash Player 10.) CFF rendering allows for high-quality rendering
                 * of font faces at small sizes.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  ArgumentError If set to any value which is not a member of RenderingMode.
                 * @throws  IllegalOperationError If set after the FontDescription object is locked (locked is true).
                 */
            public:
                std::string  renderingMode();
            public:
                void         renderingMode(std::string value);

                /**
                 * Specifies how the font should be looked up.
                 *
                 *   The default value is FontLookup.DEVICE.To set values for this property, use the following string values:String valueDescriptionFontLookup.DEVICEThe runtime looks up a device font with the specified name
                 * on the local system with which to render the text.FontLookup.EMBEDDED_CFFThe runtime looks up an embedded CFF font with the specified name
                 * with which to render the text.  Only fonts of type flash.text.Font.fontType.EMBEDDED_CFF
                 * are considered.
                 * If the specified CFF font is not embedded in the application, the runtime attempts
                 * to use a fallback device font for each glyph.  This method is less efficient
                 * than selecting a device font in the first place.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  IllegalOperationError If set after the FontDescription object is locked (locked is true).
                 */
            public:
                std::string  fontLookup();
            public:
                void         fontLookup(std::string value);

                /**
                 * The name of the font to use, or a comma-separated list of font names.  The runtime renders
                 * the element with the first available font in the list.  For example "Arial, Helvetica, _sans"
                 * causes the player to search for Arial, then Helvetica, if Arial is not found, then _sans, if neither is found.
                 *
                 *   Flash runtimes support three generic device font names: _sans (for sans serif fonts), _serif (for serif fonts),
                 * and _typewriter (for mono-space fonts).  These are mapped to specific device fonts depending on the platform.The default value is "_serif".Flash runtimes provide font fallback for glyphs which are not found in the selected font.
                 * Whether the font in use is embedded or device, if the glyph is not found in the font,
                 * the runtime attempts to render it using another device font likely to contain the glyph.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @throws  IllegalOperationError If set after the FontDescription object is locked (locked is true).
                 */
            public:
                std::string  fontName();
            public:
                void         fontName(std::string value);

                /**
                 * Specifies the font posture.
                 *
                 *   The default value is FontPosture.NORMAL.To set values for this property, use the following constants from the FontPosture class:ValueDescriptionFontPosture.NORMALNormal font posture.FontPosture.ITALICItalic font posture.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  ArgumentError If set to any value which is not a member of FontPosture.
                 * @throws  IllegalOperationError If set after the FontDescription object is locked (locked is true).
                 */
            public:
                std::string  fontPosture();
            public:
                void         fontPosture(std::string value);

                /**
                 * Specifies the font weight.
                 *
                 *   The default value is FontWeight.NORMAL.To set values for this property, use the following constants from the FontWeight class:String valueDescriptionFontWeight.NORMALNormal font weight.FontWeight.BOLDBold font weight.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  ArgumentError If set to any value which is not a member of FontWeight.
                 * @throws  IllegalOperationError If set after the FontDescription object is locked (locked is true).
                 */
            public:
                std::string  fontWeight();
            public:
                void         fontWeight(std::string value);

                /**
                 * The type of CFF hinting used for this text. Use CFFHinting
                 * constants for this property. This property applies only if the
                 * RenderingMode property of the text is set to RenderingMode.CFF.
                 *
                 *   The type of CFF (Compact Font Format) hinting used determines whether the Flash runtime forces strong horizontal
                 * stems to fit to a sub-pixel grid or not.Applies only to embedded fonts.The default value is CFFHinting.HORIZONTAL_STEM.For the CFFHinting property, you can use the following constants from the CFFHinting class:String valueDescriptionCFFHinting.NONESpecifies no CFF hinting. Horizontal stems in the glyphs are not
                 * forced to the sub-pixel grid. This setting is appropriate for animation or
                 * for large font sizes.CFFHinting.HORIZONTAL_STEMSpecifies CFF hinting. Strong horizontal stems are fit to the sub-pixel grid on
                 * a screen. To use this setting, the
                 * RenderingMode property must be set to RenderingMode.CFF.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  ArgumentError If set to any value which is not a member of CFFHinting.
                 * @throws  IllegalOperationError If set after the FontDescription object is locked (locked is true).
                 */
            public:
                std::string  cffHinting();
            public:
                void         cffHinting(std::string value);

                /**
                 * Indicates whether or not the FontDescription is locked.  If true the FontDescription cannot be modified.
                 * Call FontDescription.clone() to get an unlocked copy of the FontDescription object.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5.
                 * @playerversion   Lite 4
                 * @throws  IllegalOperationError If set after the FontDescription object is locked (locked is true).
                 */
            public:
                bool         locked();
            public:
                void         locked(bool value);

                /**
                 * Creates a FontDescription object.
                 * @param   fontName    The name of the font to use, or a comma-separated list of font names.
                 * @param   fontWeight  Specifies the font weight.
                 * @param   fontPosture Specifies the font posture.
                 * @param   fontLookup  Specifies how to look up the font.
                 * @param   renderingMode   The rendering mode used for this text. Use RenderingMode
                 *   constants for this property.
                 * @param   cffHinting  The type of CFF (Compact Font Format) hinting used for this text. Use CFFHinting
                 *   constants for this property.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  ArgumentError The fontWeight specified is not a member of FontWeight.
                 * @throws  ArgumentError The fontPosture specified is not a member of FontPosture.
                 * @throws  ArgumentError The fontLookup specified is not a member of FontLookup.
                 * @throws  ArgumentError The renderingMode specified is not a member of RenderingMode.
                 * @throws  ArgumentError The cffHinting specified is not a member of CFFHinting.
                 */
            public:
                FontDescription(std::string fontName, std::string fontWeight, std::string fontPosture, std::string fontLookup, std::string renderingMode, std::string cffHinting);

                /**
                 * Returns true if an embedded font is available with the specified fontName, fontWeight, and fontPosture
                 * where Font.fontType is flash.text.FontType.EMBEDDED_CFF.  Starting with Flash Player 10,
                 * two kinds of embedded fonts can appear in application content. Normal embedded fonts are only used by TextField.
                 * CFF embedded fonts are only used by the flash.text.engine classes.  The two types are distinguised by the
                 * fontType property of the Font class, as returned by the enumerateFonts() function.
                 *
                 *   The flash.text.engine classes cannot use a font of type EMBEDDED. If fontLookup is set
                 * to FontLookup.EMBEDDED_CFF and the only font available at run time with the specified name, weight, and posture is of type
                 * EMBEDDED, the runtime falls back to device fonts on a glyph-by-glyph basis to render the text,
                 * as if no embedded font were available with the specified name and style.If both EMBEDDED and EMBEDDED_CFF fonts are available with the same name, weight, and posture, the EMBEDDED_CFF
                 * font is selected and text renders with the EMBEDDED_CFF font.
                 * @param   fontName    The name of the embedded font to check.
                 * @param   fontWeight  Specifies the font weight.  Use FontWeight.
                 * @param   fontPosture Specifies the font posture.  Use FontPosture.
                 * @return  true if a compatible embedded font is available, otherwise false.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 * @throws  ArgumentError The fontWeight specified is not a member of FontWeight.
                 * @throws  ArgumentError The fontPosture specified is not a member of FontPosture.
                 */
            public:
                static bool     isFontCompatible(std::string fontName, std::string fontWeight, std::string fontPosture);

                /**
                 * Returns true if a usable device font is available with the specified fontName, fontWeight, and fontPosture.
                 *
                 *   The flash.text.engine classes can only use OpenType and TrueType device fonts.  If a font based on an older font technology is used,
                 * the runtime falls back to known good device fonts on a glyph-by-glyph basis to render the text
                 * @param   fontName    The name of the device font to check.
                 * @param   fontWeight  Specifies the font weight.  Use FontWeight.
                 * @param   fontPosture Specifies the font posture.  Use FontPosture.
                 * @return  true if a compatible device font is available, otherwise false.
                 * @langversion 3.0
                 * @playerversion   Flash 10.1
                 * @playerversion   AIR 2
                 * @throws  ArgumentError The fontWeight specified is not a member of FontWeight.
                 * @throws  ArgumentError The fontPosture specified is not a member of FontPosture.
                 */
            public:
                static bool     isDeviceFontCompatible(std::string fontName, std::string fontWeight, std::string fontPosture);

                /**
                 * Constructs an unlocked, cloned copy of the FontDescription.
                 * @return  An unlocked copy of the FontDescription object.
                 * @langversion 3.0
                 * @playerversion   Flash 10
                 * @playerversion   AIR 1.5
                 * @playerversion   Lite 4
                 */
            public:
                flash::text::engine::FontDescription *clone();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_TEXT_ENGINE_FONTDESCRIPTION_AS
#endif // __cplusplus

