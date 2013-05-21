

    /**
     * The RenderingMode class provides values for rendering mode in the FontDescription class.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {
namespace engine {


        /**
         * Sets rendering mode to the rendering mode that is used in Flash Player 7 and earlier.
         * This setting is recommended for animated text.
         * This constant is used for the renderingMode property in the FontDescription 
         * class.
         * Use the syntax RenderingMode.NORMAL.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string RenderingMode::NORMAL="normal";

        /**
         * Sets rendering mode to CFF (Compact Font Format). CFF rendering improves readability of text on a display. 
         * This setting is recommended for applications that have a lot of small text.
         * This constant is used for the renderingMode property in the FontDescription 
         * class.
         * Use the syntax RenderingMode.CFF.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string RenderingMode::CFF="cff";

        RenderingMode::RenderingMode();
}
}
}

