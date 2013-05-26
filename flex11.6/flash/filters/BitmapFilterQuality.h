#if !defined(FLEX11_6_FLASH_FILTERS_BITMAPFILTERQUALITY_AS)
#define FLEX11_6_FLASH_FILTERS_BITMAPFILTERQUALITY_AS
#if defined(__cplusplus)


/**
 * The BitmapFilterQuality class contains values to set the rendering quality of a BitmapFilter object.
 *
 *   EXAMPLE:
 *
 *   The following example draws a gray square and applies a BevelFilter object to it.
 * The example sets the <codeph class="+ topic/ph pr-d/codeph ">quality</codeph> property by using the
 * constant <codeph class="+ topic/ph pr-d/codeph ">BitmapFilterQuality.HIGH</codeph>.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.filters.BevelFilter;
 * import flash.filters.BitmapFilter;
 * import flash.filters.BitmapFilterQuality;
 * import flash.filters.BitmapFilterType;
 *
 *   public class BitmapFilterQualityExample extends Sprite {
 * private var bgColor:uint = 0x999999;
 * private var size:uint    = 80;
 * private var offset:uint  = 50;
 *
 *   public function BitmapFilterQualityExample() {
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

#include "flex11.6.h"



namespace flash
{
    namespace filters
    {
        class BitmapFilterQuality : public Object
        {
            /**
             * Defines the low quality filter setting.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const int LOW;

            /**
             * Defines the medium quality filter setting.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const int MEDIUM;

            /**
             * Defines the high quality filter setting.
             * @langversion 3.0
             * @playerversion   Flash 9
             */
        public:
            static const int HIGH;

        public:
            BitmapFilterQuality();
        };
    }
}

#endif // FLEX11_6_FLASH_FILTERS_BITMAPFILTERQUALITY_AS
#endif // __cplusplus

