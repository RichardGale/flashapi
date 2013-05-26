

    /**
     * The FontLookup class is an enumeration of constant values used with <codeph class="+ topic/ph pr-d/codeph ">FontDescription.fontLookup</codeph>.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {
namespace engine {


        /**
         * Used to indicate device font lookup.
         * The Flash runtime uses the fonts installed on the system that is running application.
         * 
         *   Using device fonts results in a smaller movie size, because font data
         * is not included in the file.Text rendered with device fonts is not always displayed the same across different
         * systems and platforms, because the Flash runtime uses the fonts that are installed on the system.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string FontLookup::DEVICE   = "device";

        /**
         * Used to indicate embedded CFF (Compact Font Format) font lookup.
         * The Flash runtime uses font outlines embedded in the published application.
         * 
         *   Text rendered with embedded fonts is always displayed
         * in the chosen font, whether that font is installed
         * on the playback system or not.One drawback to embedded fonts is that they increase the size of the application.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string FontLookup::EMBEDDED_CFF   = "embeddedCFF";

        FontLookup::FontLookup();
}
}
}

