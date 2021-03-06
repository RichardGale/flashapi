

    /**
     * The CFFHinting class defines values for cff hinting in the FontDescription class.
     * 
     *   <p class="- topic/p ">Hinting adjusts the display of an outline font so it lines up with the pixel grid. 
     * At small screen sizes, hinting produces a clear, legible text for human readers.
     * </p>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {
namespace engine {


        /**
         * No hinting is applied. Horizontal stems in the glyphs are not forced to the pixel grid. 
         * This constant is used in setting the cffHinting property of the 
         * FontDescription class. Recommended setting for animation or for large font sizes.
         * Use the syntax CFFHinting.NONE.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string CFFHinting::NONE   = "none";

        /**
         * Fits strong horizontal stems to the pixel grid for improved readability.
         * This constant is used in setting the cffHinting property of the 
         * FontDescription class. Use the syntax CFFHinting.HORIZONTAL_STEM.
         * 
         *   Note: Not recommended for animation.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string CFFHinting::HORIZONTAL_STEM   = "horizontalStem";

        CFFHinting::CFFHinting();
}
}
}

