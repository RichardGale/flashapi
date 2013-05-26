#if !defined(FLEX11_6_FLASH_TEXT_FONTTYPE_AS)
#define FLEX11_6_FLASH_TEXT_FONTTYPE_AS
#if defined(__cplusplus)


/**
 * The FontType class contains the enumerated constants <codeph class="+ topic/ph pr-d/codeph ">"embedded"</codeph>
 * and <codeph class="+ topic/ph pr-d/codeph ">"device"</codeph> for the <codeph class="+ topic/ph pr-d/codeph ">fontType</codeph> property of the Font class.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



namespace flash
{
    namespace text
    {
        class FontType : public Object
        {
            /**
             * Indicates that this is an embedded font.
             * Font outlines are embedded in the published SWF file.
             *
             *   Text fields that use embedded fonts are always displayed
             * in the chosen font, whether or not that font is installed
             * on the playback system. Also, text fields that use embedded fonts
             * are always anti-aliased (smoothed). You
             * can select the amount of anti-aliasing you want by using the
             * TextField.antiAliasType property.One drawback to embedded fonts is that they increase the size of the SWF file.Fonts of type EMBEDDED can only be used by TextField.
             * If flash.text.engine classes are directed to use such a font they will fall back to device fonts.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string EMBEDDED;

            /**
             * Indicates that this is an embedded CFF font.
             * Font outlines and a subset of OpenType tables are embedded in the published SWF file.
             *
             *   Text that uses embedded CFF fonts is always displayed
             * in the chosen font, whether or not that font is installed
             * on the playback system. Also, text that uses embedded CFF fonts
             * is always anti-aliased (smoothed) by Flash Player. You
             * can select the rendering mode and hinting for an embedded CFF font using the
             * flash.text.engine.FontDescription.renderingMode and
             * flash.text.engine.FontDescription.cffHinting properties.One drawback to embedded CFF fonts is that they increase the size of the SWF file.
             * However, embedded CFF fonts are typically 20% to 30% smaller than regular embedded fonts.Fonts of type EMBEDDED_CFF can only be used by the flash.text.engine classes.
             * A TextField directed to use such a font will fail to render.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            static const std::string EMBEDDED_CFF;

            /**
             * Indicates that this is a device font.
             * The SWF file renders fonts with those installed on the system.
             *
             *   Using device fonts results in a smaller movie size, because font data
             * is not included in the file. Device fonts are often a good choice for
             * displaying text at small point sizes, because anti-aliased text can be blurry
             * at small sizes. Device fonts are also a good choice for large blocks of text,
             * such as scrolling text.Text fields that use device fonts may not be displayed the same across different
             * systems and platforms, because they are rendered with fonts installed on the system.
             * For the same reason, device fonts are not anti-aliased and may appear jagged at
             * large point sizes.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string DEVICE;

        public:
            FontType();
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_FONTTYPE_AS
#endif // __cplusplus

