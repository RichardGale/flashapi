

    /**
     * The DisplacementMapFilterMode class provides values for the <codeph class="+ topic/ph pr-d/codeph ">mode</codeph> property
     * of the DisplacementMapFilter class.
     * @langversion 3.0
     * @playerversion   Flash 9
     */


namespace flash {
namespace filters {


        /**
         * Wraps the displacement value to the other side of the source image.
         * Use with the DisplacementMapFilter.mode property.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string DisplacementMapFilterMode::WRAP   = "wrap";

        /**
         * Clamps the displacement value to the edge of the source image.
         * 
         *   Use with the DisplacementMapFilter.mode property.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string DisplacementMapFilterMode::CLAMP   = "clamp";

        /**
         * If the displacement value is out of range, ignores the displacement and uses the source pixel.
         * 
         *   Use with the DisplacementMapFilter.mode property.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string DisplacementMapFilterMode::IGNORE   = "ignore";

        /**
         * If the displacement value is outside the image, substitutes the values in 
         * the color and alpha properties.
         * 
         *   Use with the DisplacementMapFilter.mode property.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string DisplacementMapFilterMode::COLOR   = "color";

        DisplacementMapFilterMode::DisplacementMapFilterMode();
}
}

