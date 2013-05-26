

    /**
     * The TextRotation class is an enumeration of constant values used with the following properties:
     * <codeph class="+ topic/ph pr-d/codeph ">ElementFormat.textRotation</codeph>, <codeph class="+ topic/ph pr-d/codeph ">ContentElement.textRotation</codeph>,
     * <codeph class="+ topic/ph pr-d/codeph ">TextBlock.lineRotation</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">TextLine.getAtomTextRotation()</codeph>.
     * 
     *   <p class="- topic/p ">The final rotation of any glyph is the sum of <codeph class="+ topic/ph pr-d/codeph ">TextBlock.lineRotation</codeph>,
     * <codeph class="+ topic/ph pr-d/codeph ">ElementFormat.textRotation</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">ContentElement.textRotation</codeph></p>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {
namespace engine {


        /**
         * Specifies no rotation.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextRotation::ROTATE_0   = "rotate0";

        /**
         * Specifies a 90 degree clockwise rotation.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextRotation::ROTATE_90   = "rotate90";

        /**
         * Specifies a 180 degree rotation.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextRotation::ROTATE_180   = "rotate180";

        /**
         * Specifies a 270 degree clockwise rotation.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextRotation::ROTATE_270   = "rotate270";

        /**
         * Specifies a 90 degree counter clockwise rotation for full width and wide glyphs only,
         * as determined by the Unicode properties of the glyph.
         * This value is typically used with Asian text to rotate
         * only those glyphs that require rotation.
         * This rotation is applied only in vertical text to return full width and wide 
         * characters to a vertical orientation without affecting other characters.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextRotation::AUTO   = "auto";

        TextRotation::TextRotation();
}
}
}

