

    /**
     * The TextBaseline class is an enumeration of constant values to use in setting the <codeph class="+ topic/ph pr-d/codeph ">dominantBaseline</codeph> and
     * <codeph class="+ topic/ph pr-d/codeph ">alignmentBaseline</codeph> properties of the ElementFormat class.  You can also use it in the 
     * <codeph class="+ topic/ph pr-d/codeph ">baselineZero</codeph> property of the TextBlock class.
     * Consider this situation:
     * <p class="- topic/p "><adobeimage alt="Text baseline alignment" href="../../../images/textBaselines.gif" placement="inline" class="+ topic/image adobe-d/adobeimage " /></p><p class="- topic/p ">The line consists of four <codeph class="+ topic/ph pr-d/codeph ">TextElement</codeph> objects, containing 'a', 'b', 'cccccccc', and 'X' respectively.
     * The element containing 'X' determines the line baselines because it is the largest element in the line.
     * The roman baseline of the 'X' element is aligned with the roman baseline of the line.
     * The ideographic top of the 'a' element is aligned with the ideographic top of the line.
     * The ideographic bottom of the 'b' element is aligned with the ideographic bottom of the line.
     * The ideographic center of the 'cccccccc' element is aligned with the ideographic center of the line.</p>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {
namespace engine {


        /**
         * Specifies a roman baseline.  
         * For a text element, the font and point size of the text determine this value.
         * For a graphic element, the text engine uses the geometric bottom of the element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextBaseline::ROMAN   = "roman";

        /**
         * Specifies an ascent baseline.
         * For a text element, the font and point size of the text determine this value.
         * For a graphic element, the text engine uses the geometric top of the element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextBaseline::ASCENT   = "ascent";

        /**
         * Specifies a descent baseline.
         * For a text element, the font and point size of the text determine this value.
         * For a graphic element, the text element uses the geometric bottom of the element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextBaseline::DESCENT   = "descent";

        /**
         * Specifies an ideographic top baseline.
         * For a text element, the font and point size of the text determine this value.
         * For a graphic element, the text engine uses the geometric top of the element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextBaseline::IDEOGRAPHIC_TOP   = "ideographicTop";

        /**
         * Specifies an ideographic center baseline.
         * For a text element, the font and point size of the text determine this value.
         * For a graphic element, the text engine uses the geometric center of the element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextBaseline::IDEOGRAPHIC_CENTER   = "ideographicCenter";

        /**
         * Specifies an ideographic bottom baseline.
         * For a text element, the font and point size of the text determine this value.
         * For a graphic element, the text engine uses the geometric bottom of the element.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextBaseline::IDEOGRAPHIC_BOTTOM   = "ideographicBottom";

        /**
         * Specifies that the alignmentBaseline is the same as the dominantBaseline.
         * Use this value only to set ElementFormat.alignmentBaseline.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TextBaseline::USE_DOMINANT_BASELINE   = "useDominantBaseline";

        TextBaseline::TextBaseline();
}
}
}

