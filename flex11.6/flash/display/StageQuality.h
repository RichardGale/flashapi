#if !defined(FLEX11_6_FLASH_DISPLAY_STAGEQUALITY_AS)
#define FLEX11_6_FLASH_DISPLAY_STAGEQUALITY_AS
#if defined(__cplusplus)


/**
 * The StageQuality class provides values for the <codeph class="+ topic/ph pr-d/codeph ">Stage.quality</codeph> property.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace display
    {
        class StageQuality : public Object
        {
            /**
             * Specifies low rendering quality: graphics are not anti-aliased, and bitmaps are not smoothed.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string LOW;

            /**
             * Specifies medium rendering quality: graphics are anti-aliased using a 2 x 2 pixel grid,
             * but bitmaps are not smoothed. This setting is suitable for movies that do not contain text.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string MEDIUM;

            /**
             * Specifies high rendering quality: graphics are anti-aliased using a 4 x 4 pixel grid,
             * and bitmaps are smoothed if the movie is static.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string HIGH;

            /**
             * Specifies very high rendering quality: graphics are anti-aliased using a 4 x 4 pixel
             * grid and bitmaps are always smoothed.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string BEST;
        public:
            static const std::string HIGH_8X8;
        public:
            static const std::string HIGH_8X8_LINEAR;
        public:
            static const std::string HIGH_16X16;
        public:
            static const std::string HIGH_16X16_LINEAR;

        public:
            StageQuality();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_STAGEQUALITY_AS
#endif // __cplusplus

