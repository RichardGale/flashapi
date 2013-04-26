#if !defined(FLEX11_6_FLASH_SYSTEM_IMAGEDECODINGPOLICY_AS)
#define FLEX11_6_FLASH_SYSTEM_IMAGEDECODINGPOLICY_AS
#if defined(__cplusplus)


/**
 * The ImageDecodingPolicy class defines values for the <codeph class="+ topic/ph pr-d/codeph ">imageDecodingPolicy</codeph> property
 * of the LoaderContext class.
 * @langversion 3.0
 * @playerversion   AIR 2.6
 */

namespace flash
{
    namespace system
    {
        class ImageDecodingPolicy: public Object
        {
            /**
             * Specifies that the image being loaded will not be decoded until needed.
             * @langversion 3.0
             * @playerversion   AIR 2.6
             */
        public:
            static const std::string ON_DEMAND;

            /**
             * Specifies that the image will be decoded when it is loaded, before the
             * complete event is sent.
             * @langversion 3.0
             * @playerversion   AIR 2.6
             */
        public:
            static const std::string ON_LOAD;

        public:
            ImageDecodingPolicy();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_IMAGEDECODINGPOLICY_AS
#endif // __cplusplus

