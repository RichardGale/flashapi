

    /**
     * The ImageDecodingPolicy class defines values for the <codeph class="+ topic/ph pr-d/codeph ">imageDecodingPolicy</codeph> property 
     * of the LoaderContext class.
     * @langversion 3.0
     * @playerversion   AIR 2.6
     */


namespace flash {
namespace system {


        /**
         * Specifies that the image being loaded will not be decoded until needed.
         * @langversion 3.0
         * @playerversion   AIR 2.6
         */
        const std::string ImageDecodingPolicy::ON_DEMAND="onDemand";

        /**
         * Specifies that the image will be decoded when it is loaded, before the 
         * complete event is sent.
         * @langversion 3.0
         * @playerversion   AIR 2.6
         */
        const std::string ImageDecodingPolicy::ON_LOAD="onLoad";

        ImageDecodingPolicy::ImageDecodingPolicy();
}
}

