#if !defined(FLEX11_6_FLASH_DISPLAY_BITMAPDATACHANNEL_AS)
#define FLEX11_6_FLASH_DISPLAY_BITMAPDATACHANNEL_AS
#if defined(__cplusplus)


/**
 * The BitmapDataChannel class is an enumeration of constant values that indicate which channel to
 * use: red, blue, green, or alpha transparency.
 *
 *   <p class="- topic/p ">When you call some methods, you can use the bitwise OR operator (<codeph class="+ topic/ph pr-d/codeph ">|</codeph>)
 * to combine BitmapDataChannel constants to indicate multiple color channels.</p><p class="- topic/p ">The BitmapDataChannel constants are provided for use as values in the following:</p><ul class="- topic/ul "><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">sourceChannel</codeph> and <codeph class="+ topic/ph pr-d/codeph ">destChannel</codeph> parameters of the
 * <codeph class="+ topic/ph pr-d/codeph ">flash.display.BitmapData.copyChannel()</codeph> method</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">channelOptions</codeph> parameter of the
 * <codeph class="+ topic/ph pr-d/codeph ">flash.display.BitmapData.noise()</codeph> method</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">flash.filters.DisplacementMapFilter.componentX</codeph> and
 * <codeph class="+ topic/ph pr-d/codeph ">flash.filters.DisplacementMapFilter.componentY</codeph> properties</li></ul>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

namespace flash
{
    namespace display
    {
        class BitmapDataChannel: public Object
        {
            /**
             * The red channel.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int RED;

            /**
             * The green channel.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int GREEN;

            /**
             * The blue channel.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int BLUE;

            /**
             * The alpha channel.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const unsigned int ALPHA;

        public:
            BitmapDataChannel();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_BITMAPDATACHANNEL_AS
#endif // __cplusplus

