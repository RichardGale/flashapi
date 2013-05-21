#if !defined(FLEX11_6_FLASH_UTILS_COMPRESSIONALGORITHM_AS)
#define FLEX11_6_FLASH_UTILS_COMPRESSIONALGORITHM_AS
#if defined(__cplusplus)


/**
 * The CompressionAlgorithm class defines string constants for the names of compress and uncompress options. These constants
 * are used as values of the <codeph class="+ topic/ph pr-d/codeph ">algorithm</codeph> parameter of the <codeph class="+ topic/ph pr-d/codeph ">ByteArray.compress()</codeph>
 * and <codeph class="+ topic/ph pr-d/codeph ">ByteArray.uncompress()</codeph> methods.
 * @langversion 3.0
 * @playerversion   AIR 1.0
 */


namespace flash
{
    namespace utils
    {
        class CompressionAlgorithm : public Object
        {
            /**
             * Defines the string to use for the zlib compression algorithm.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string ZLIB;

            /**
             * Defines the string to use for the deflate compression algorithm.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string DEFLATE;
        public:
            static const std::string LZMA;

        public:
            CompressionAlgorithm();
        };
    }
}

#endif // FLEX11_6_FLASH_UTILS_COMPRESSIONALGORITHM_AS
#endif // __cplusplus

