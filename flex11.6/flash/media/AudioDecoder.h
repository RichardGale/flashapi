#if !defined(FLEX11_6_FLASH_MEDIA_AUDIODECODER_AS)
#define FLEX11_6_FLASH_MEDIA_AUDIODECODER_AS
#if defined(__cplusplus)



#include "flex11.6.h"



namespace flash
{
    namespace media
    {
        class AudioDecoder : public Object
        {
        public:
            static const std::string DOLBY_DIGITAL;
        public:
            static const std::string DOLBY_DIGITAL_PLUS;
        public:
            static const std::string DTS;
        public:
            static const std::string DTS_EXPRESS;
        public:
            static const std::string DTS_HD_HIGH_RESOLUTION_AUDIO;
        public:
            static const std::string DTS_HD_MASTER_AUDIO;

        public:
            AudioDecoder();
        };
    }
}

#endif // FLEX11_6_FLASH_MEDIA_AUDIODECODER_AS
#endif // __cplusplus

