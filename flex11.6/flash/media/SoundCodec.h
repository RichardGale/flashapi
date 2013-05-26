#if !defined(FLEX11_6_FLASH_MEDIA_SOUNDCODEC_AS)
#define FLEX11_6_FLASH_MEDIA_SOUNDCODEC_AS
#if defined(__cplusplus)


/**
 * The SoundCodec class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">codec</codeph> property
 * of the <codeph class="+ topic/ph pr-d/codeph ">Microphone</codeph> class.
 * @langversion 3.0
 * @playerversion   Flash 10
 * @playerversion   AIR 1.5
 */

#include "flex11.6.h"



namespace flash
{
    namespace media
    {
        class SoundCodec : public Object
        {
            /**
             * Specifies that the Nellymoser codec be used for compressing audio.
             * This constant is the default value of the Microphone.codec property.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string NELLYMOSER;

            /**
             * Specifies that the Speex codec be used for compressing audio.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             */
        public:
            static const std::string SPEEX;
        public:
            static const std::string PCMA;
        public:
            static const std::string PCMU;

        public:
            SoundCodec();
        };
    }
}

#endif // FLEX11_6_FLASH_MEDIA_SOUNDCODEC_AS
#endif // __cplusplus

