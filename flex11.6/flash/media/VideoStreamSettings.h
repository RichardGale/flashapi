#if !defined(FLEX11_6_FLASH_MEDIA_VIDEOSTREAMSETTINGS_AS)
#define FLEX11_6_FLASH_MEDIA_VIDEOSTREAMSETTINGS_AS
#if defined(__cplusplus)



#include "flex11.6.h"



namespace flash
{
    namespace media
    {
        class VideoStreamSettings : public Object
        {
        public:
            int          width();

        public:
            int          height();

        public:
            float       fps();

        public:
            int          quality();

        public:
            int          bandwidth();

        public:
            int          keyFrameInterval();

        public:
            std::string       codec();

        public:
            void     setMode(int width, int height, float fps);

        public:
            VideoStreamSettings();

        public:
            void     setQuality(int bandwidth, int quality);

        public:
            void     setKeyFrameInterval(int keyFrameInterval);
        };
    }
}

#endif // FLEX11_6_FLASH_MEDIA_VIDEOSTREAMSETTINGS_AS
#endif // __cplusplus

