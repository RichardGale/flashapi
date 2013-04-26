#if !defined(FLEX11_6_FLASH_MEDIA_STAGEVIDEOAVAILABILITY_AS)
#define FLEX11_6_FLASH_MEDIA_STAGEVIDEOAVAILABILITY_AS
#if defined(__cplusplus)


/**
 * This class defines an enumeration that indicates whether stage video is currently available.
 * @langversion 3.0
 * @playerversion   Flash 10.2
 * @playerversion   AIR (unsupported)
 */

namespace flash
{
    namespace media
    {
        class StageVideoAvailability: public Object
        {
            /**
             * Stage video is currently available.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            static const std::string AVAILABLE;

            /**
             * Stage video is not currently available.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            static const std::string UNAVAILABLE;

        public:
            StageVideoAvailability();
        };
    }
}

#endif // FLEX11_6_FLASH_MEDIA_STAGEVIDEOAVAILABILITY_AS
#endif // __cplusplus

