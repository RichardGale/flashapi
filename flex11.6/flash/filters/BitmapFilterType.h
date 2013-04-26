#if !defined(FLEX11_6_FLASH_FILTERS_BITMAPFILTERTYPE_AS)
#define FLEX11_6_FLASH_FILTERS_BITMAPFILTERTYPE_AS
#if defined(__cplusplus)


/**
 * The BitmapFilterType class contains values to set the type of a BitmapFilter.
 *
 *   EXAMPLE:
 *
 *   The following example draws a gray square and applies a BevelFilter object to it.
 * The example sets the <codeph class="+ topic/ph pr-d/codeph ">type</codeph> property by using the constant <codeph class="+ topic/ph pr-d/codeph ">BitmapFilterType.HIGH</codeph>.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.filters.BevelFilter;
 * import flash.filters.BitmapFilter;
 * import flash.filters.BitmapFilterQuality;
 * import flash.filters.BitmapFilterType;
 *
 *   public class BitmapFilterTypeExample extends Sprite {
 * private var bgColor:uint = 0x999999;
 * private var size:uint    = 80;
 * private var offset:uint  = 50;
 *
 *   public function BitmapFilterTypeExample() {
 * draw();
 * var filter:BitmapFilter = getBitmapFilter();
 * var myFilters:Array = new Array();
 * myFilters.push(filter);
 * filters = myFilters;
 * }
 *
 *   private function getBitmapFilter():BitmapFilter {
 * var distance:Number       = 5;
 * var angleInDegrees:Number = 45;
 * var highlightColor:Number = 0xCCCCCC;
 * var highlightAlpha:Number = 0.8;
 * var shadowColor:Number    = 0x808080;
 * var shadowAlpha:Number    = 0.8;
 * var blurX:Number          = 5;
 * var blurY:Number          = 5;
 * var strength:Number       = 5;
 * var quality:Number        = BitmapFilterQuality.HIGH;
 * var type:String           = BitmapFilterType.INNER;
 * var knockout:Boolean      = false;
 *
 *   return new BevelFilter(distance,
 * angleInDegrees,
 * highlightColor,
 * highlightAlpha,
 * shadowColor,
 * shadowAlpha,
 * blurX,
 * blurY,
 * strength,
 * quality,
 * type,
 * knockout);
 * }
 *
 *   private function draw():void {
 * graphics.beginFill(bgColor);
 * graphics.drawRect(offset, offset, size, size);
 * graphics.endFill();
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 */

namespace flash
{
    namespace filters
    {
        class BitmapFilterType: public Object
        {
            /**
             * Defines the setting that applies a filter to the inner area of an object.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string INNER;

            /**
             * Defines the setting that applies a filter to the outer area of an object.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string OUTER;

            /**
             * Defines the setting that applies a filter to the entire area of an object.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const std::string FULL;

        public:
            BitmapFilterType();
        };
    }
}

#endif // FLEX11_6_FLASH_FILTERS_BITMAPFILTERTYPE_AS
#endif // __cplusplus

