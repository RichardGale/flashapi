

    /**
     * The PixelSnapping class is an enumeration of constant values for setting the pixel snapping options 
     * by using the <codeph class="+ topic/ph pr-d/codeph ">pixelSnapping</codeph> property of a Bitmap object.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */


namespace flash {
namespace display {


        /**
         * A constant value used in the pixelSnapping property of a Bitmap object 
         * to specify that no pixel snapping occurs.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string PixelSnapping::NEVER   = "never";

        /**
         * A constant value used in the pixelSnapping property of a Bitmap object 
         * to specify that the bitmap image is always snapped to the nearest 
         * pixel, independent of any transformation.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string PixelSnapping::ALWAYS   = "always";

        /**
         * A constant value used in the pixelSnapping property of a Bitmap object 
         * to specify that the bitmap image is snapped to the nearest pixel if it is drawn with no rotation
         * or skew and it is drawn at a scale factor of 99.9% to 100.1%. If these conditions are satisfied,
         * the image is drawn at 100% scale, snapped to the nearest pixel. Internally, this setting allows the image
         * to be drawn as fast as possible by using the vector renderer.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string PixelSnapping::AUTO   = "auto";

        PixelSnapping::PixelSnapping();
}
}

