

    /**
     * This class defines an enumeration that describes possible levels of video decoding.
     * @langversion 3.0
     * @playerversion   Flash 10.2
     * @playerversion   AIR (unsupported)
     */


namespace flash {
namespace media {


        /**
         * Video decoding is not supported.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR (unsupported)
         */
        const std::string VideoStatus::UNAVAILABLE   = "unavailable";

        /**
         * Indicates software video decoding.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR (unsupported)
         */
        const std::string VideoStatus::SOFTWARE   = "software";

        /**
         * Indicates hardware-accelerated (GPU) video decoding.
         * @langversion 3.0
         * @playerversion   Flash 10.2
         * @playerversion   AIR (unsupported)
         */
        const std::string VideoStatus::ACCELERATED   = "accelerated";

        VideoStatus::VideoStatus();
}
}

