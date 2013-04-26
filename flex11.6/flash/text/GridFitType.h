#if !defined(FLEX11_6_FLASH_TEXT_GRIDFITTYPE_AS)
#define FLEX11_6_FLASH_TEXT_GRIDFITTYPE_AS
#if defined(__cplusplus)


/**
 * The GridFitType class defines values for grid fitting in the TextField class.
 * @langversion 3.0
 * @playerversion   Flash 9
 */

namespace flash
{
    namespace text
    {
        class GridFitType: public Object
        {
            /**
             * Doesn't set grid fitting. Horizontal and vertical lines
             * in the glyphs are not forced to the pixel grid.
             * This constant is used in setting the gridFitType property of the
             * TextField class. This is often a good setting for animation
             * or for large font sizes.
             * Use the syntax GridFitType.NONE.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string NONE;

            /**
             * Fits strong horizontal and vertical lines to the pixel grid.
             * This constant is used in setting the gridFitType property of the
             * TextField class. This setting only works for left-justified text
             * fields and acts like the GridFitType.SUBPIXEL constant in static
             * text. This setting generally provides the best readability for left-aligned text.
             * Use the syntax GridFitType.PIXEL.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string PIXEL;

            /**
             * Fits strong horizontal and vertical lines to the sub-pixel
             * grid on LCD monitors. (Red, green, and blue are actual pixels on an LCD screen.)
             * This is often a good setting for right-aligned or center-aligned dynamic
             * text, and it is sometimes a useful tradeoff for animation vs. text quality.
             * This constant is used in setting the gridFitType property of the
             * TextField class.
             * Use the syntax GridFitType.SUBPIXEL.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string SUBPIXEL;

        public:
            GridFitType();
        };
    }
}

#endif // FLEX11_6_FLASH_TEXT_GRIDFITTYPE_AS
#endif // __cplusplus

