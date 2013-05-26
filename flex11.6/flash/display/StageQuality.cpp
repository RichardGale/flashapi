

    /**
     * The StageQuality class provides values for the <codeph class="+ topic/ph pr-d/codeph ">Stage.quality</codeph> property.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */


namespace flash {
namespace display {


        /**
         * Specifies low rendering quality: graphics are not anti-aliased, and bitmaps are not smoothed.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string StageQuality::LOW   = "low";

        /**
         * Specifies medium rendering quality: graphics are anti-aliased using a 2 x 2 pixel grid, 
         * but bitmaps are not smoothed. This setting is suitable for movies that do not contain text.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string StageQuality::MEDIUM   = "medium";

        /**
         * Specifies high rendering quality: graphics are anti-aliased using a 4 x 4 pixel grid, 
         * and bitmaps are smoothed if the movie is static.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string StageQuality::HIGH   = "high";

        /**
         * Specifies very high rendering quality: graphics are anti-aliased using a 4 x 4 pixel 
         * grid and bitmaps are always smoothed.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string StageQuality::BEST   = "best";
        const std::string StageQuality::HIGH_8X8  ;
        const std::string StageQuality::HIGH_8X8_LINEAR  ;
        const std::string StageQuality::HIGH_16X16  ;
        const std::string StageQuality::HIGH_16X16_LINEAR  ;

        StageQuality::StageQuality();
}
}

