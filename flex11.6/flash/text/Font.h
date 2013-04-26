#if !defined(FLEX11_6_FLASH_TEXT_FONT_AS)
#define FLEX11_6_FLASH_TEXT_FONT_AS
#if defined(__cplusplus)


/**
 * The Font class is used to manage embedded fonts in SWF files. Embedded fonts
 * are represented as a subclass of the Font class. The Font class is currently useful only to
 * find out information about embedded fonts; you cannot alter a font by
 * using this class.
 *
 *   You cannot use the Font class to load external fonts, or to create an instance
 * of a Font object by itself. Use the Font class as an abstract base class.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

namespace flash
{
    namespace text
    {
        class Font: public Object
        {
            /**
             * The name of an embedded font.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  fontName();

            /**
             * The style of the font. This value can be any of the values defined in the FontStyle class.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  fontStyle();

            /**
             * The type of the font. This value can be any of the constants defined in the FontType class.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  fontType();

            /**
             * Specifies whether to provide a list of the currently available embedded fonts.
             * @param   enumerateDeviceFonts    Indicates whether you want to limit the list to only the currently available embedded fonts.
             *   If this is set to true then a list of all fonts, both device fonts and embedded fonts, is returned.
             *   If this is set to false then only a list of embedded fonts is returned.
             * @return  A list of available fonts as an array of Font objects.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static std::vector<void *> enumerateFonts(bool enumerateDeviceFonts);

        public:
            Font();

            /**
             * Registers a font class in the global font list.
             * @param   font    The class you want to add to the global font list.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static void     registerFont(Class *font);

            /**
             * Specifies whether a provided string can be displayed using the currently assigned font.
             * @param   str The string to test against the current font.
             * @return  A value of true if the specified string can be fully displayed using this font.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool     hasGlyphs(std::string str);
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_FONT_AS
#endif // __cplusplus

