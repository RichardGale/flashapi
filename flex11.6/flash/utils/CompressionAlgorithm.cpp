

    /**
     * The CompressionAlgorithm class defines string constants for the names of compress and uncompress options. These constants 
     * are used as values of the <codeph class="+ topic/ph pr-d/codeph ">algorithm</codeph> parameter of the <codeph class="+ topic/ph pr-d/codeph ">ByteArray.compress()</codeph> 
     * and <codeph class="+ topic/ph pr-d/codeph ">ByteArray.uncompress()</codeph> methods.
     * @langversion 3.0
     * @playerversion   AIR 1.0
     */


namespace flash {
namespace utils {


        /**
         * Defines the string to use for the zlib compression algorithm.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        const std::string CompressionAlgorithm::ZLIB   = "zlib";

        /**
         * Defines the string to use for the deflate compression algorithm.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        const std::string CompressionAlgorithm::DEFLATE   = "deflate";
        const std::string CompressionAlgorithm::LZMA  ;

        CompressionAlgorithm::CompressionAlgorithm();
}
}

