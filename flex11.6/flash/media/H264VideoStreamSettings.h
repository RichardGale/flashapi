#if !defined(FLEX11_6_FLASH_MEDIA_H264VIDEOSTREAMSETTINGS_AS)
#define FLEX11_6_FLASH_MEDIA_H264VIDEOSTREAMSETTINGS_AS
#if defined(__cplusplus)



namespace flash
{
    namespace media
    {
        class H264VideoStreamSettings : public VideoStreamSettings
        {
        public:
            std::string  codec();

        public:
            std::string  profile();

        public:
            std::string  level();

        public:
            H264VideoStreamSettings();

        public:
            void     setProfileLevel(std::string profile, std::string level);
        };
    }
}

#endif // FLEX11_6_FLASH_MEDIA_H264VIDEOSTREAMSETTINGS_AS
#endif // __cplusplus

