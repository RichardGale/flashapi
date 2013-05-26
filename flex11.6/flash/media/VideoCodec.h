#if !defined(FLEX11_6_FLASH_MEDIA_VIDEOCODEC_AS)
#define FLEX11_6_FLASH_MEDIA_VIDEOCODEC_AS
#if defined(__cplusplus)



#include "flex11.6.h"



namespace flash
{
    namespace media
    {
        class VideoCodec : public Object
        {
        public:
            static const std::string H264AVC;
        public:
            static const std::string SORENSON;
        public:
            static const std::string VP6;

        public:
            VideoCodec();
        };
    }
}

#endif // FLEX11_6_FLASH_MEDIA_VIDEOCODEC_AS
#endif // __cplusplus

