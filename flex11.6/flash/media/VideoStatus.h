#if !defined(FLEX11_6_FLASH_MEDIA_VIDEOSTATUS_AS)
#define FLEX11_6_FLASH_MEDIA_VIDEOSTATUS_AS
#if defined(__cplusplus)


/**
 * This class defines an enumeration that describes possible levels of video decoding.
 * @langversion 3.0
 * @playerversion   Flash 10.2
 * @playerversion   AIR (unsupported)
 */


namespace flash
{
    namespace media
    {
        class VideoStatus : public Object
        {
            /**
             * Video decoding is not supported.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            static const std::string UNAVAILABLE;

            /**
             * Indicates software video decoding.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            static const std::string SOFTWARE;

            /**
             * Indicates hardware-accelerated (GPU) video decoding.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            static const std::string ACCELERATED;

        public:
            VideoStatus();
        };
    }
}

#endif // FLEX11_6_FLASH_MEDIA_VIDEOSTATUS_AS
#endif // __cplusplus

