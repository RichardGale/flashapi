#if !defined(FLEX11_6_FLASH_DISPLAY_BITMAPDATA_AS)
#define FLEX11_6_FLASH_DISPLAY_BITMAPDATA_AS
#if defined(__cplusplus)



namespace flash
{
    namespace geom
    {
        class Rectangle;
    }
}
namespace flash
{
    namespace geom
    {
        class Point;
    }
}
namespace flash
{
    namespace filters
    {
        class BitmapFilter;
    }
}
namespace flash
{
    namespace geom
    {
        class ColorTransform;
    }
}
#include "flash/display/IBitmapDrawable.h"
namespace flash
{
    namespace geom
    {
        class Matrix;
    }
}
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

/**
 * The BitmapData class lets you work with the data (pixels) of a <ph class="- topic/ph ">Bitmap object</ph>
 * . You can use the methods of the BitmapData class
 * to create arbitrarily sized transparent or opaque bitmap images and manipulate them in various
 * ways at runtime. <ph class="- topic/ph ">You can also access the BitmapData for a bitmap image
 * that you load with the <codeph class="+ topic/ph pr-d/codeph ">flash.display.Loader</codeph> class.</ph><p class="- topic/p ">This class lets you separate bitmap rendering operations from the
 * internal display updating routines of Flash Player.  By manipulating
 * a BitmapData object directly, you can create complex images without incurring the
 * per-frame overhead of constantly redrawing the content from vector data.</p><p class="- topic/p ">The methods of the BitmapData class support
 * effects that are not available through the filters available to non-bitmap display objects.</p><p class="- topic/p ">A BitmapData object contains an array of pixel data. This data can represent either
 * a fully opaque bitmap or a transparent bitmap that contains alpha channel data.
 * Either type of BitmapData object is stored as a buffer of 32-bit integers.
 * Each 32-bit integer determines the properties of a single pixel in the bitmap.</p><p class="- topic/p ">Each 32-bit integer is a combination of four 8-bit channel values (from 0 to 255) that
 * describe the alpha transparency and the red, green, and blue (ARGB) values of the pixel.
 * (For ARGB values, the most significant byte represents the alpha channel value, followed by red,
 * green, and blue.)</p><p class="- topic/p ">The four channels (alpha, red, green, and blue) are represented as numbers
 * when you use them with the <codeph class="+ topic/ph pr-d/codeph ">BitmapData.copyChannel()</codeph> method or the
 * <codeph class="+ topic/ph pr-d/codeph ">DisplacementMapFilter.componentX</codeph>
 * and <codeph class="+ topic/ph pr-d/codeph ">DisplacementMapFilter.componentY</codeph> properties, and these numbers
 * are represented by the following constants in the BitmapDataChannel class:</p><ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">BitmapDataChannel.ALPHA</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">BitmapDataChannel.RED</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">BitmapDataChannel.GREEN</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">BitmapDataChannel.BLUE</codeph></li></ul><p class="- topic/p ">You can attach BitmapData objects to a Bitmap object by using the
 * <codeph class="+ topic/ph pr-d/codeph ">bitmapData</codeph> property of the Bitmap object.</p><p class="- topic/p ">You can use a BitmapData object to fill a Graphics object by using the
 * <codeph class="+ topic/ph pr-d/codeph ">Graphics.beginBitmapFill()</codeph> method.</p><p class="- topic/p ">In the AIR runtime, the DockIcon, Icon, InteractiveIcon, and SystemTrayIcon classes each include
 * a <codeph class="+ topic/ph pr-d/codeph ">bitmaps</codeph> property that is an array of BitmapData objects that define the bitmap images
 * for an icon.</p><p class="- topic/p ">In  AIR 1.5 and Flash Player 10, the maximum size for a BitmapData object is 8,191 pixels in width or height,
 * and the total number of pixels cannot exceed 16,777,215 pixels. (So, if a BitmapData object is 8,191 pixels
 * wide, it can only be 2,048 pixels high.) In Flash Player 9 and earlier and AIR 1.1 and earlier, the limitation is
 * 2,880 pixels in height and 2,880 in width.</p><p class="- topic/p ">Calls to any method or property of a BitmapData object throw an ArgumentError error if
 * the BitmapData object is invalid (for example, if it has <codeph class="+ topic/ph pr-d/codeph ">height == 0</codeph> and
 * <codeph class="+ topic/ph pr-d/codeph ">width == 0</codeph>) or it has been disposed of via dispose(). </p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the class BitmapDataExample to load the
 * image Image.gif into a DisplayObject in the default location (0, 0). A copy
 * of Image.gif is then placed to the right of the original, which has new colors applied to pixels
 * that pass a test using the <codeph class="+ topic/ph pr-d/codeph ">threshold()</codeph> method.
 * The task is accomplished using the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">A <codeph class="+ topic/ph pr-d/codeph ">url</codeph> property is created, which is the location and name of the image file</li><li class="- topic/li ">The class constructor creates a Loader object, which then instantiates an event listener,
 * which is dispatched when the <codeph class="+ topic/ph pr-d/codeph ">completeHandler()</codeph> method completes the image manipulation.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">request</codeph> URLRequest object is then passed to <codeph class="+ topic/ph pr-d/codeph ">loader.load()</codeph>, which loads the image
 * into memory by using a display object.</li><li class="- topic/li ">The image is then placed on the display list, which displays the image on screen at
 * coordinates <i class="+ topic/ph hi-d/i ">x = 0, y = 0</i>.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">completeHandler()</codeph> method then does the following:
 * <ul class="- topic/ul "><li class="- topic/li ">Creates a second Loader, along with a Bitmap object, which is initialized with the
 * Loader object.</li><li class="- topic/li ">Creates a second Bitmap object, <codeph class="+ topic/ph pr-d/codeph ">duplicate</codeph>, which in turn calls the
 * <codeph class="+ topic/ph pr-d/codeph ">duplicateImage()</codeph> method, which creates a duplicate of the original image. </li><li class="- topic/li ">Creates a BitmapData object that is assigned to the <codeph class="+ topic/ph pr-d/codeph ">duplicate</codeph> object's
 * BitmapData object.</li><li class="- topic/li ">Creates a new Rectangle object initialized with the same coordinates, width, and height
 * as the original image.</li><li class="- topic/li ">Creates a new Point object, which defaults to <i class="+ topic/ph hi-d/i ">x = 0, y = 0</i>.</li><li class="- topic/li ">Creates the following variables:
 * <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">operation</codeph>    Applies the new color when the threshold
 * value is greater than or equal to the original.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">threshold</codeph>    The value against which each pixel is compared (in this example,
 * light gray with an alpha of 0xCC). </li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">color</codeph>    The color that the pixels are set to that pass the threshold
 * test, which is solid yellow in this case.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">mask</codeph>    The exact opposite of color (transparent blue).</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">copySource</codeph>    Set to <codeph class="+ topic/ph pr-d/codeph ">false</codeph>, indicating the pixel values are
 * not copied if the threshold value does not pass.  This value has no meaning because
 * the image is duplicated and only pixels that pass the threshold test are changed.</li></ul></li><li class="- topic/li ">Calls the <codeph class="+ topic/ph pr-d/codeph ">threshold()</codeph> method using the preceding variables.  The resulting threshold
 * equation is as follows: <codeph class="+ topic/ph pr-d/codeph ">if (current pixel Value &amp; 0x000000FF) &gt;=
 * (0xCCCCCCCC &amp; 0x000000FF) then set pixel to 0xFFFFFF00</codeph>. </li></ul></li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Notes:</b><ul class="- topic/ul "><li class="- topic/li ">You will need to compile the SWF file with Local Playback Security set to Access Local Files Only.
 * </li><li class="- topic/li ">This example requires that a file named Image.gif be placed in the same directory as your SWF file.
 * </li><li class="- topic/li ">It is recommended that you use an image of up to approximately 80 pixels in width. </li></ul></p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Bitmap;
 * import flash.display.BitmapData;
 * import flash.display.Loader;
 * import flash.display.Sprite;
 * import flash.events.*;
 * import flash.geom.Point;
 * import flash.geom.Rectangle;
 * import flash.net.URLRequest;
 *
 *   public class BitmapDataExample extends Sprite {
 * private var url:String = "Image.gif";
 * private var size:uint = 80;
 *
 *   public function BitmapDataExample() {
 * configureAssets();
 * }
 *
 *   private function configureAssets():void {
 * var loader:Loader = new Loader();
 * loader.contentLoaderInfo.addEventListener(Event.COMPLETE, completeHandler);
 * loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
 *
 *   var request:URLRequest = new URLRequest(url);
 * loader.x = size * numChildren;
 * loader.load(request);
 * addChild(loader);
 * }
 *
 *   private function duplicateImage(original:Bitmap):Bitmap {
 * var image:Bitmap = new Bitmap(original.bitmapData.clone());
 * image.x = size * numChildren;
 * addChild(image);
 * return image;
 * }
 *
 *   private function completeHandler(event:Event):void {
 * var loader:Loader = Loader(event.target.loader);
 * var image:Bitmap = Bitmap(loader.content);
 *
 *   var duplicate:Bitmap = duplicateImage(image);
 * var bitmapData:BitmapData = duplicate.bitmapData;
 * var sourceRect:Rectangle = new Rectangle(0, 0, bitmapData.width, bitmapData.height);
 * var destPoint:Point = new Point();
 * var operation:String = "&gt;=";
 * var threshold:uint = 0xCCCCCCCC;
 * var color:uint = 0xFFFFFF00;
 * var mask:uint = 0x000000FF;
 * var copySource:Boolean = true;
 *
 *   bitmapData.threshold(bitmapData,
 * sourceRect,
 * destPoint,
 * operation,
 * threshold,
 * color,
 * mask,
 * copySource);
 * }
 *
 *   private function ioErrorHandler(event:IOErrorEvent):void {
 * trace("Unable to load image: " + url);
 * }
 * }
 * }
 * </codeblock>
 *
 *   EXAMPLE:
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   AIR 1.0
 * @playerversion   Lite 4
 */
using namespace flash::geom;
using namespace flash::geom;
using namespace flash::filters;
using namespace flash::geom;
using namespace flash::display;
using namespace flash::geom;
using namespace flash::utils;

namespace flash
{
    namespace display
    {
        class BitmapData: public Object, public IBitmapDrawable
        {
            /**
             * The width of the bitmap image in pixels.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            int          width();

            /**
             * The height of the bitmap image in pixels.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            int          height();

            /**
             * Defines whether the bitmap image supports per-pixel transparency. You can set this value only when you construct
             * a BitmapData object by passing in true for the transparent parameter of the constructor. Then, after you create
             * a BitmapData object, you can check whether it supports per-pixel transparency by determining if the value of the
             * transparent property is true.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            bool         transparent();

            /**
             * The rectangle that defines the size and location of the bitmap image. The top and left of the
             * rectangle are 0; the width and height are equal to the width and height in pixels of the
             * BitmapData object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            flash::geom::Rectangle *rect();

            /**
             * Creates a  BitmapData object with a specified width and height.
             * If you specify a value for the  fillColor parameter, every pixel in the bitmap is set
             * to that color.
             *
             *   By default, the bitmap is created as transparent, unless you pass the value false
             * for the transparent parameter. After you create an opaque bitmap, you cannot change it to
             * a transparent bitmap. Every pixel in an opaque bitmap uses only 24 bits of color channel information.
             * If you define the bitmap as transparent, every pixel uses 32 bits of color channel information,
             * including an alpha transparency channel.In  AIR 1.5 and Flash Player 10, the maximum size for a BitmapData object is 8,191 pixels in width or height,
             * and the total number of pixels cannot exceed 16,777,215 pixels. (So, if a BitmapData object is 8,191 pixels
             * wide, it can only be 2,048 pixels high.) In Flash Player 9 and earlier and AIR 1.1 and earlier, the limitation is
             * 2,880 pixels in height and 2,880 pixels in width.
             * If you specify a width or height value that is greater than 2880, a new instance is not created.
             * @param   width   The width of the bitmap image in pixels.
             * @param   height  The height of the bitmap image in pixels.
             * @param   transparent Specifies whether the bitmap image  supports per-pixel transparency.
             *   The default value is true (transparent). To create a fully transparent bitmap, set the value
             *   of the transparent parameter to true and the value of the fillColor
             *   parameter to 0x00000000 (or to 0). Setting the transparent property to false
             *   can result in minor improvements in rendering performance.
             * @param   fillColor   A 32-bit ARGB color value that you use to fill the bitmap image area.
             *   The default value is 0xFFFFFFFF (solid white).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  ArgumentError width and/or height exceed the maximum dimensions.
             */
        public:
            BitmapData(int width, int height, bool transparent, unsigned int fillColor);

            /**
             * Returns a new BitmapData object that is a clone of the original instance
             * with an exact copy of the contained bitmap.
             * @return  A new BitmapData object that is identical to the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            flash::display::BitmapData *clone();

            /**
             * Returns an integer that represents  an RGB pixel value from a BitmapData object at
             * a specific point (x, y). The getPixel() method returns an
             * unmultiplied pixel value. No alpha information is returned.
             *
             *   All pixels in a BitmapData object are stored as premultiplied color values.
             * A premultiplied image pixel has the red, green, and blue
             * color channel values already multiplied by the alpha data. For example, if the
             * alpha value is 0, the values for the RGB channels are also 0, independent of their unmultiplied
             * values. This loss of data can cause some problems when you perform operations. All BitmapData
             * methods take and return unmultiplied values. The internal pixel representation is converted
             * from premultiplied to unmultiplied before it is returned as a value. During a set operation,
             * the pixel value is premultiplied before the raw image pixel is set.
             * @param   x   The x position of the pixel.
             * @param   y   The y position of the pixel.
             * @return  A number that represents an RGB pixel value. If the (x, y) coordinates are
             *   outside the bounds of the image, the method returns 0.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            unsigned int getPixel(int x, int y);

            /**
             * Returns an ARGB color value that contains alpha channel data and RGB
             * data. This method is similar to the getPixel() method, which returns an
             * RGB color without alpha channel data.
             *
             *   All pixels in a BitmapData object are stored as premultiplied color values.
             * A premultiplied image pixel has the red, green, and blue
             * color channel values already multiplied by the alpha data. For example, if the
             * alpha value is 0, the values for the RGB channels are also 0, independent of their unmultiplied
             * values. This loss of data can cause some problems when you perform operations. All BitmapData
             * methods take and return unmultiplied values. The internal pixel representation is converted
             * from premultiplied to unmultiplied before it is returned as a value. During a set operation,
             * the pixel value is premultiplied before the raw image pixel is set.
             * @param   x   The x position of the pixel.
             * @param   y   The y position of the pixel.
             * @return  A number representing an ARGB pixel value. If the (x, y) coordinates are
             *   outside the bounds of the image, 0 is returned.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            unsigned int getPixel32(int x, int y);

            /**
             * Sets a single pixel of a BitmapData object. The current
             * alpha channel value of the image pixel is preserved during this
             * operation. The value of the RGB color parameter is treated as an unmultiplied color value.
             *
             *   Note: To increase performance, when you use the setPixel() or
             * setPixel32() method repeatedly, call the lock() method before
             * you call the setPixel() or setPixel32() method, and then call
             * the unlock() method when you have made all pixel changes. This process prevents objects
             * that reference this BitmapData instance from updating until you finish making
             * the pixel changes.
             * @param   x   The x position of the pixel whose value changes.
             * @param   y   The y position of the pixel whose value changes.
             * @param   color   The resulting RGB color for the pixel.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            void     setPixel(int x, int y, unsigned int color);

            /**
             * Sets the color and alpha transparency values of a single pixel of a BitmapData
             * object. This method is similar to the setPixel() method; the main difference is
             * that the setPixel32() method takes an
             * ARGB color value that contains alpha channel information.
             *
             *   All pixels in a BitmapData object are stored as premultiplied color values.
             * A premultiplied image pixel has the red, green, and blue
             * color channel values already multiplied by the alpha data. For example, if the
             * alpha value is 0, the values for the RGB channels are also 0, independent of their unmultiplied
             * values. This loss of data can cause some problems when you perform operations. All BitmapData
             * methods take and return unmultiplied values. The internal pixel representation is converted
             * from premultiplied to unmultiplied before it is returned as a value. During a set operation,
             * the pixel value is premultiplied before the raw image pixel is set.Note: To increase performance, when you use the setPixel() or
             * setPixel32() method repeatedly, call the lock() method before
             * you call the setPixel() or setPixel32() method, and then call
             * the unlock() method when you have made all pixel changes. This process prevents objects
             * that reference this BitmapData instance from updating until you finish making
             * the pixel changes.
             * @param   x   The x position of the pixel whose value changes.
             * @param   y   The y position of the pixel whose value changes.
             * @param   color   The resulting ARGB color for the pixel. If the bitmap is opaque
             *   (not transparent), the alpha transparency portion of this color value is ignored.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            void     setPixel32(int x, int y, unsigned int color);

            /**
             * Takes a source image and a filter object and generates the
             * filtered image.
             *
             *   This method relies on the behavior of built-in filter
             * objects, which determine the destination
             * rectangle that is affected by an input source rectangle.After a filter is applied, the resulting image can be larger than the input image.
             * For example, if you use a BlurFilter class
             * to blur a source rectangle of (50,50,100,100) and a
             * destination point of (10,10), the area that changes in the
             * destination image is larger than (10,10,60,60) because of
             * the blurring. This happens internally during the applyFilter()
             * call.If the sourceRect parameter of the sourceBitmapData parameter is
             * an interior region, such as (50,50,100,100) in a 200 x 200 image, the filter uses the source
             * pixels outside the sourceRect parameter to generate
             * the destination rectangle.If the BitmapData object and the object specified as the sourceBitmapData
             * parameter are the same object, the application uses a temporary copy of the object to
             * perform the filter. For best performance, avoid this situation.
             * @param   sourceBitmapData    The input bitmap image to use. The source image can be a different
             *   BitmapData object or it can refer to the current BitmapData instance.
             * @param   sourceRect  A rectangle that defines the area of the source image to use as input.
             * @param   destPoint   The point within the destination image (the current BitmapData
             *   instance) that corresponds to the upper-left corner of the source rectangle.
             * @param   filter  The filter object that you use to perform the filtering operation. Each type
             *   of filter has certain requirements, as follows:
             *
             *     BlurFilter
             *   This filter can use source and destination images
             *   that are either opaque or transparent. If the formats of the images do
             *   not match, the copy of the source image that is made during the
             *   filtering matches the format of the destination image.BevelFilter, DropShadowFilter, GlowFilter, ChromeFilter
             *   The destination image of these filters must be a transparent
             *   image. Calling DropShadowFilter or GlowFilter creates an image that
             *   contains the alpha channel data of the drop shadow or glow. It does not
             *   create the drop shadow onto the destination image. If you use any of these
             *   filters with an opaque destination image, an exception
             *   is thrown.ConvolutionFilter     This filter can use source and
             *   destination images that are either opaque or transparent.ColorMatrixFilter     This filter can use source and
             *   destination images that are either opaque or transparent.DisplacementMapFilter     This filter can use source and
             *   destination images that are either opaque or transparent, but the
             *   source and destination image formats must be the same.
             * @return  A number that indicates whether the filter was applied successfully.
             *   If 0 is returned, the filter was applied successfully.
             *   If a negative number is returned, an error occurred during the application of the filter.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @throws  TypeError The sourceBitmapData, sourceRect, destPoint or filter are null.
             * @throws  IllegalOperationError The transparency of the BitmapData objects are not
             *   compatible with the filter operation.
             */
        public:
            void     applyFilter(BitmapData *sourceBitmapData, Rectangle *sourceRect, Point *destPoint, BitmapFilter *filter);

            /**
             * Adjusts the color values in a specified area of a bitmap image by using a
             * ColorTransform object. If the rectangle
             * matches the boundaries of the bitmap image, this method transforms the color values of
             * the entire image.
             * @param   rect    A Rectangle object that defines the area of the image in which the
             *   ColorTransform object is applied.
             * @param   colorTransform  A ColorTransform object that describes the color transformation
             *   values to apply.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  TypeError The rect or colorTransform are null.
             */
        public:
            void     colorTransform(Rectangle *rect, ColorTransform *colorTransform);

            /**
             * Compares two BitmapData objects. If the two BitmapData objects have the same dimensions
             * (width and height), the method returns a new BitmapData object, in which each pixel is
             * the "difference" between the pixels in the two source objects:
             *
             *   If two pixels are equal, the difference pixel is 0x00000000. If two pixels have different RGB values (ignoring the alpha value), the difference
             * pixel is 0xRRGGBB where RR/GG/BB are the individual difference values between red, green,
             * and blue channels (the pixel value in the source object minus the pixel value in the
             * otherBitmapData object). Alpha channel differences are ignored in this case. If only the alpha channel value is different, the pixel value is 0xZZFFFFFF,
             * where ZZ is the difference in the alpha values (the alpha value in the source object
             * minus the alpha value in the otherBitmapData object).For example, consider the following two BitmapData objects:
             * <codeblock>
             *
             *   var bmd1:BitmapData = new BitmapData(50, 50, true, 0xFFFF8800);
             * var bmd2:BitmapData = new BitmapData(50, 50, true, 0xCCCC6600);
             * var diffBmpData:BitmapData = bmd1.compare(bmd2) as BitmapData;
             * trace ("0x" + diffBmpData.getPixel(0,0).toString(16); // 0x332200
             *
             *   </codeblock>
             * Note: The colors used to fill the two BitmapData objects have slightly different RGB values
             * (0xFF0000 and 0xFFAA00). The result of the compare() method is a new BitmapData
             * object with each pixel showing the difference in the RGB values between the two bitmaps.Consider the following two BitmapData objects, in which the RGB colors are the same,
             * but the alpha values are different:
             * <codeblock>
             *
             *   var bmd1:BitmapData = new BitmapData(50, 50, true, 0xFFFFAA00);
             * var bmd2:BitmapData = new BitmapData(50, 50, true, 0xCCFFAA00);
             * var diffBmpData:BitmapData = bmd1.compare(bmd2) as BitmapData;
             * trace ("0x" + diffBmpData.getPixel32(0,0).toString(16); // 0x33ffffff
             *
             *   </codeblock>
             * The result of the compare() method is a new BitmapData
             * object with each pixel showing the difference in the alpha values between the two bitmaps.If the BitmapData objects are equivalent (with the same width, height, and identical pixel values),
             * the method returns the number 0.If the widths of the BitmapData objects are not equal, the method returns the number -3. If the heights of the BitmapData objects are not equal, but the widths are the same,
             * the method returns the number -4.The following example compares two Bitmap objects with different widths (50 and 60):
             * <codeblock>
             *
             *   var bmd1:BitmapData = new BitmapData(100, 50, false, 0xFFFF0000);
             * var bmd2:BitmapData = new BitmapData(100, 60, false, 0xFFFFAA00);
             * trace(bmd1.compare(bmd2)); // -4
             *
             *   </codeblock>
             * @param   otherBitmapData The BitmapData object to compare with the source BitmapData object.
             * @return  If the two BitmapData objects have the same dimensions (width and height), the
             *   method returns a new BitmapData object that has the difference between the two objects (see the
             *   main discussion). If the BitmapData objects are equivalent, the method returns the number 0.
             *   If the widths of the BitmapData objects are not equal, the method returns the number -3.
             *   If the heights of the BitmapData objects are not equal, the method returns the number -4.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  TypeError The otherBitmapData is null.
             */
        public:
            Object  *compare(BitmapData *otherBitmapData);

            /**
             * Transfers data from one channel of another BitmapData object or the current
             * BitmapData object into a channel of the current BitmapData object.
             * All of the data in the other channels in the destination BitmapData object are
             * preserved.
             *
             *   The source channel value and destination channel value can be
             * one of following values: BitmapDataChannel.REDBitmapDataChannel.GREENBitmapDataChannel.BLUEBitmapDataChannel.ALPHA
             * @param   sourceBitmapData    The input bitmap image to use. The source image can be a different BitmapData object
             *   or it can refer to the current BitmapData object.
             * @param   sourceRect  The source Rectangle object. To copy only channel data from a smaller area
             *   within the bitmap, specify a source rectangle that is smaller than the overall size of the
             *   BitmapData object.
             * @param   destPoint   The destination Point object that represents the upper-left corner of the rectangular area
             *   where the new channel data is placed.
             *   To copy only channel data
             *   from one area to a different area in the destination image, specify a point other than (0,0).
             * @param   sourceChannel   The source channel. Use a value from the BitmapDataChannel class
             *   (BitmapDataChannel.RED, BitmapDataChannel.BLUE,
             *   BitmapDataChannel.GREEN, BitmapDataChannel.ALPHA).
             * @param   destChannel The destination channel. Use a value from the BitmapDataChannel class
             *   (BitmapDataChannel.RED, BitmapDataChannel.BLUE,
             *   BitmapDataChannel.GREEN, BitmapDataChannel.ALPHA).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  TypeError The sourceBitmapData, sourceRect or destPoint are null.
             */
        public:
            void     copyChannel(BitmapData *sourceBitmapData, Rectangle *sourceRect, Point *destPoint, unsigned int sourceChannel, unsigned int destChannel);

            /**
             * Provides a fast routine to perform pixel manipulation
             * between images with no stretching, rotation, or color effects. This method copies a
             * rectangular area of a source image to a
             * rectangular area of the same size at the destination point of the destination
             * BitmapData object.
             *
             *   If you include the alphaBitmap and alphaPoint parameters, you can use a secondary
             * image as an alpha source for the source image. If the source
             * image has alpha data, both sets of alpha data are used to
             * composite pixels from the source image to the destination image. The
             * alphaPoint parameter is the point in the alpha image that
             * corresponds to the upper-left corner of the source
             * rectangle. Any pixels outside the intersection of the source
             * image and alpha image are not copied to the destination image.The mergeAlpha property controls whether or not the alpha
             * channel is used when a transparent image is copied onto
             * another transparent image. To copy
             * pixels with the alpha channel data, set the mergeAlpha
             * property to true. By default, the mergeAlpha property is
             * false.
             * @param   sourceBitmapData    The input bitmap image from which to copy pixels. The source image can be a
             *   different BitmapData instance, or it can refer to the current BitmapData
             *   instance.
             * @param   sourceRect  A rectangle that defines the area of the source image to use as input.
             * @param   destPoint   The destination point that represents the upper-left corner of the rectangular
             *   area where the new pixels are placed.
             * @param   alphaBitmapData A secondary, alpha BitmapData object source.
             * @param   alphaPoint  The point in the alpha BitmapData object source that corresponds to
             *   the upper-left corner of the sourceRect parameter.
             * @param   mergeAlpha  To use the alpha channel, set the value to
             *   true. To copy pixels with no alpha channel, set the value to
             *   false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  TypeError The sourceBitmapData, sourceRect, destPoint are null.
             */
        public:
            void     copyPixels(BitmapData *sourceBitmapData, Rectangle *sourceRect, Point *destPoint, BitmapData *alphaBitmapData, Point *alphaPoint, bool mergeAlpha);

            /**
             * Frees memory that is used to store the BitmapData object.
             *
             *   When the dispose() method is called on an image, the width and height of the image are set to 0.
             * All subsequent calls to methods or properties of this BitmapData instance fail, and an
             * exception is thrown. BitmapData.dispose() releases the memory occupied by the actual bitmap data, immediately (a bitmap can consume up to 64 MB of memory).
             * After using BitmapData.dispose(), the BitmapData object is no longer usable and the Flash runtime throws an exception if you call
             * functions on the BitmapData object.
             * However, BitmapData.dispose() does not garbage collect the BitmapData object (approximately 128 bytes); the memory occupied by the actual
             * BitmapData object is released at the time the BitmapData object is collected by the garbage collector.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            void     dispose();

            /**
             * Draws the source display object onto the bitmap image, using the
             * Flash runtime vector renderer.
             * You can specify matrix, colorTransform,
             * blendMode, and a destination clipRect parameter to control
             * how the rendering performs. Optionally, you can specify whether the bitmap
             * should be smoothed when scaled (this works only if the source object
             * is a BitmapData object).
             *
             *   This method directly corresponds to how objects are drawn
             * with the standard vector renderer for objects in the authoring tool
             * interface.The source display object does not use any of its applied transformations
             * for this call. It is treated as it exists in the library or
             * file, with no matrix transform, no color transform, and no blend
             * mode. To draw a display object (such as a movie clip) by using its own transform properties,
             * you can copy its transform property object to the transform property
             * of the Bitmap object that uses the BitmapData object.This method is supported over RTMP in Flash Player 9.0.115.0
             * and later and in Adobe AIR. You can control access to streams on
             * Flash Media Server in a server-side script. For more information, see the Client.audioSampleAccess
             * and Client.videoSampleAccess properties in Server-Side ActionScript Language Reference for Adobe Flash Media Server.If the source object and (in the case of a Sprite or MovieClip object) all
             * of its child objects do not come from the same domain as the caller, or are not in a content that is
             * accessible to the caller by having called the Security.allowDomain() method, a call to
             * the draw() throws a SecurityError exception. This restriction does not apply
             * to AIR content in the application security sandbox.There are also restrictions on using a loaded bitmap image as the source.
             * A call to the draw() method is successful if the loaded image comes from the same domain as the caller.
             * Also, a cross-domain policy file on the image's server can grant permission to the domain of the SWF content
             * calling the draw() method. In this case, you must set the checkPolicyFile property
             * of a LoaderContext object, and use this object as the context parameter when calling the load()
             * method of the Loader object used to load the image. These restrictions do not apply to AIR content in the
             * application security sandbox.On Windows, the draw() method cannot capture SWF content embedded in an HTML
             * page in an HTMLLoader object in Adobe AIR.The draw() method cannot capture PDF content in Adobe AIR.
             * Nor can it capture  or SWF content embedded in HTML in which the wmode attribute is set
             * to "window" in Adobe AIR.
             * @param   source  The display object or BitmapData object to draw to the BitmapData object.
             *   (The DisplayObject and BitmapData classes implement the IBitmapDrawable interface.)
             * @param   matrix  A Matrix object used to scale, rotate, or translate the coordinates
             *   of the bitmap. If you do not want to apply a matrix transformation to the image,
             *   set this parameter to an identity matrix, created with the default
             *   new Matrix() constructor, or pass a null value.
             * @param   colorTransform  A ColorTransform object that you use to adjust the color values of
             *   the bitmap. If no object is supplied, the bitmap image's colors are not transformed.
             *   If you must pass this parameter but you do not want to transform the image, set this
             *   parameter to a ColorTransform object created with the default new ColorTransform()
             *   constructor.
             * @param   blendMode   A string value, from the flash.display.BlendMode class, specifying the
             *   blend mode to be applied to the resulting bitmap.
             * @param   clipRect    A Rectangle object that defines the area of the source object to draw.
             *   If you do not supply this value, no clipping occurs and the entire source object is drawn.
             * @param   smoothing   A Boolean value that determines whether a BitmapData object is
             *   smoothed when scaled or rotated, due to a scaling or rotation in the matrix
             *   parameter. The smoothing parameter only applies if the source
             *   parameter is a BitmapData object. With smoothing set to false,
             *   the rotated or scaled BitmapData image can appear pixelated or jagged. For example, the following
             *   two images use the same BitmapData object for the source parameter, but the
             *   smoothing parameter is set to true on the left and false
             *   on the right:
             *
             *     Drawing a bitmap with smoothing set to true takes longer
             *   than doing so with smoothing set to false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  ArgumentError The source parameter is not a BitmapData
             *   or DisplayObject object.
             * @throws  SecurityError The source object and (in the case of
             *   a Sprite or MovieClip object) all of its child objects do not come from the same domain as
             *   the caller, or are not in a content that is accessible to the caller by having called the
             *   Security.allowDomain() method. This restriction does not apply
             *   to AIR content in the application security sandbox.
             * @throws  ArgumentError The source is null or not a valid IBitmapDrawable object.
             */
        public:
            void     draw(IBitmapDrawable *source, Matrix *matrix, ColorTransform *colorTransform, std::string blendMode, Rectangle *clipRect, bool smoothing);

        public:
            void     drawWithQuality(IBitmapDrawable *source, Matrix *matrix, ColorTransform *colorTransform, std::string blendMode, Rectangle *clipRect, bool smoothing, std::string quality);

            /**
             * Fills a rectangular area of pixels with a specified ARGB color.
             * @param   rect    The rectangular area to fill.
             * @param   color   The ARGB color value that fills the area. ARGB colors are often
             *   specified in hexadecimal format; for example, 0xFF336699.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  TypeError The rect is null.
             */
        public:
            void     fillRect(Rectangle *rect, unsigned int color);

            /**
             * Performs a flood fill operation on an image starting
             * at an (x, y) coordinate and filling with a certain color. The
             * floodFill() method is similar to the paint bucket tool in various paint
             * programs. The color is an ARGB color that contains alpha information and
             * color information.
             * @param   x   The x coordinate of the image.
             * @param   y   The y coordinate of the image.
             * @param   color   The ARGB color to use as a fill.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            void     floodFill(int x, int y, unsigned int color);

            /**
             * Determines the destination rectangle that the applyFilter() method call affects, given a
             * BitmapData object, a source rectangle, and a filter object.
             *
             *   For example, a blur filter normally affects an area larger than the size of the original
             * image. A 100 x 200 pixel image that is being filtered by a default BlurFilter
             * instance, where blurX = blurY = 4 generates a destination rectangle of
             * (-2,-2,104,204).
             * The generateFilterRect() method lets you find out the size of this destination
             * rectangle in advance so that you can size the destination image appropriately before you perform a filter
             * operation.Some filters clip their destination rectangle based on the source image size.
             * For example, an inner DropShadow does not generate a larger result than its source
             * image. In this API, the BitmapData object is used as the source bounds and not the
             * source rect parameter.
             * @param   sourceRect  A rectangle defining the area of the source image to use as input.
             * @param   filter  A filter object that you use to calculate the destination rectangle.
             * @return  A destination rectangle computed by using an image, the sourceRect parameter,
             *   and a filter.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @throws  TypeError The sourceRect or filter are null.
             */
        public:
            flash::geom::Rectangle *generateFilterRect(Rectangle *sourceRect, BitmapFilter *filter);

            /**
             * Determines a rectangular region that either fully encloses all pixels of a specified color within the
             * bitmap image (if the findColor parameter is set to true) or fully encloses
             * all pixels that do not include the specified color (if the findColor parameter is set
             * to false).
             *
             *   For example, if you have a source image and you want to determine the rectangle of
             * the image that contains a nonzero alpha channel, pass
             * {mask: 0xFF000000, color: 0x00000000} as parameters. If the findColor
             * parameter is set to true, the entire image is searched for the bounds of pixels
             * for which (value & mask) == color (where value is the color value
             * of the pixel). If the findColor parameter is set to false, the entire
             * image is searched for the bounds of pixels for which (value & mask) != color
             * (where value is the color value of the pixel). To determine white space around an
             * image, pass {mask: 0xFFFFFFFF, color: 0xFFFFFFFF}
             * to find the bounds of nonwhite pixels.
             * @param   mask    A hexadecimal value, specifying the bits of the ARGB color to consider. The color
             *   value is combined with this hexadecimal value, by using the & (bitwise AND) operator.
             * @param   color   A hexadecimal value, specifying the ARGB color to match (if findColor
             *   is set to true) or not to match (if findColor
             *   is set to false).
             * @param   findColor   If the value is set to true, returns the bounds of a color value in an image.
             *   If the value is set to false, returns the bounds of where this color doesn't exist in an image.
             * @return  The region of the image that is the specified color.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            flash::geom::Rectangle *getColorBoundsRect(unsigned int mask, unsigned int color, bool findColor);

            /**
             * Generates a byte array from a rectangular region of pixel data.
             * Writes an unsigned integer (a 32-bit unmultiplied pixel value)
             * for each pixel into the byte array.
             * @param   rect    A rectangular area in the current BitmapData object.
             * @return  A ByteArray representing the pixels in the given Rectangle.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  TypeError The rect is null.
             */
        public:
            flash::utils::ByteArray *getPixels(Rectangle *rect);

        public:
            void     copyPixelsToByteArray(Rectangle *rect, ByteArray *data);

            /**
             * Generates a vector array from a rectangular region of pixel data.
             * Returns a Vector object of unsigned integers (a 32-bit unmultiplied pixel value)
             * for the specified rectangle.
             * @param   rect    A rectangular area in the current BitmapData object.
             * @return  A Vector representing the given Rectangle.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             * @throws  TypeError The rect is null.
             */
        public:
            std::vector<unsigned int> *getVector(Rectangle *rect);

            /**
             * Performs pixel-level hit detection between one bitmap image
             * and a point, rectangle, or other bitmap image. A hit is defined as
             * an overlap of a point or rectangle over an opaque pixel, or two
             * overlapping opaque pixels. No stretching,
             * rotation, or other transformation of either object is considered when
             * the hit test is performed.
             *
             *   If an image is an opaque image, it is considered a fully opaque rectangle for this
             * method. Both images must be transparent images to perform pixel-level hit testing that
             * considers transparency. When you are testing two transparent images, the alpha threshold
             * parameters control what alpha channel values, from 0 to 255, are considered opaque.
             * @param   firstPoint  A position of the upper-left corner of the BitmapData image in an arbitrary coordinate space.
             *   The same coordinate space is used in defining the secondBitmapPoint parameter.
             * @param   firstAlphaThreshold The smallest alpha channel value that is considered opaque for this hit test.
             * @param   secondObject    A  Rectangle, Point, Bitmap, or BitmapData object.
             * @param   secondBitmapDataPoint   A point that defines a pixel location in the second BitmapData object.
             *   Use this parameter only when the value of secondObject is a
             *   BitmapData object.
             * @param   secondAlphaThreshold    The smallest alpha channel value that is considered opaque in the second BitmapData object.
             *   Use this parameter only when the value of secondObject is a
             *   BitmapData object and both BitmapData objects are transparent.
             * @return  A value of true if a hit occurs; otherwise, false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  ArgumentError The secondObject parameter is not a Point, Rectangle,
             *   Bitmap, or BitmapData object.
             * @throws  TypeError The firstPoint is null.
             */
        public:
            bool     hitTest(Point *firstPoint, unsigned int firstAlphaThreshold, Object *secondObject, Point *secondBitmapDataPoint, unsigned int secondAlphaThreshold);

            /**
             * Performs per-channel blending from a source image to a destination image. For each channel
             * and each pixel, a new value is computed based on the channel values of the source and destination
             * pixels. For example, in the red channel, the new value is computed as follows (where redSrc
             * is the red channel value for a pixel in the source image and redDest is the red channel
             * value at the corresponding pixel of the destination image):
             *
             *   new redDest = [(redSrc * redMultiplier) + (redDest * (256 - redMultiplier))] / 256;
             * The redMultiplier, greenMultiplier, blueMultiplier, and
             * alphaMultiplier values are the multipliers used for each color channel. Use a hexadecimal
             * value ranging from 0 to 0x100 (256) where 0 specifies the full
             * value from the destination is used in the result, 0x100 specifies the full value from the
             * source is used, and numbers in between specify a blend is used (such as 0x80 for 50%).
             * @param   sourceBitmapData    The input bitmap image to use. The source image can be a different
             *   BitmapData object, or it can refer to the current BitmapData object.
             * @param   sourceRect  A rectangle that defines the area of the source image to use as input.
             * @param   destPoint   The point within the destination image (the current BitmapData
             *   instance) that corresponds to the upper-left corner of the source rectangle.
             * @param   redMultiplier   A hexadecimal uint value by which to multiply the red channel value.
             * @param   greenMultiplier A hexadecimal uint value by which to multiply the green channel value.
             * @param   blueMultiplier  A hexadecimal uint value by which to multiply the blue channel value.
             * @param   alphaMultiplier A hexadecimal uint value by which to multiply the alpha transparency value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  TypeError The sourceBitmapData, sourceRect or destPoint are null.
             */
        public:
            void     merge(BitmapData *sourceBitmapData, Rectangle *sourceRect, Point *destPoint, unsigned int redMultiplier, unsigned int greenMultiplier, unsigned int blueMultiplier, unsigned int alphaMultiplier);

            /**
             * Fills an image with pixels representing random noise.
             * @param   randomSeed  The random seed number to use. If you keep all other parameters
             *   the same, you can generate different pseudo-random results by varying the random seed value. The noise
             *   function is a mapping function, not a true random-number generation function, so it creates the same
             *   results each time from the same random seed.
             * @param   low The lowest value to generate for each channel (0 to 255).
             * @param   high    The highest value to generate for each channel (0 to 255).
             * @param   channelOptions  A number that can be a combination of any of
             *   the four color channel values (BitmapDataChannel.RED,
             *   BitmapDataChannel.BLUE, BitmapDataChannel.GREEN, and
             *   BitmapDataChannel.ALPHA). You can use the logical OR
             *   operator (|) to combine channel values.
             * @param   grayScale   A Boolean value. If the value is true, a grayscale image is created by setting
             *   all of the color channels to the same value.
             *   The alpha channel selection is not affected by
             *   setting this parameter to true.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             */
        public:
            void     noise(int randomSeed, unsigned int low, unsigned int high, unsigned int channelOptions, bool grayScale);

            /**
             * Remaps the color channel values in an image that has up to four arrays of color palette data, one
             * for each channel.
             *
             *   Flash runtimes use the following steps to
             * generate the resulting image:After the red, green, blue, and alpha
             * values are computed, they are added together using standard 32-bit-integer arithmetic. The red, green, blue, and alpha channel values of each pixel are extracted into separate 0 to 255 values.
             * These values are used to look up new color values in the appropriate array: redArray,
             * greenArray, blueArray, and alphaArray.
             * Each of these four arrays should contain 256 values. After all four of the new channel values are retrieved, they are combined into a standard
             * ARGB value that is applied to the pixel.Cross-channel effects can be supported with this method.
             * Each input array can contain full 32-bit values, and no shifting occurs when the
             * values are added together. This routine does not support per-channel
             * clamping. If no array is specified for a channel,
             * the color channel is copied from the source image to the
             * destination image.You can use this method for a variety of effects such as
             * general palette mapping (taking one channel and converting it
             * to a false color image). You can also use this method for a variety of advanced color
             * manipulation algorithms, such as gamma, curves, levels, and quantizing.
             * @param   sourceBitmapData    The input bitmap image to use. The source image can be a different
             *   BitmapData object, or it can refer to the current BitmapData instance.
             * @param   sourceRect  A rectangle that defines the area of the source image to use as input.
             * @param   destPoint   The point within the destination image (the current BitmapData
             *   object) that corresponds to the upper-left corner of the source rectangle.
             * @param   redArray    If redArray is not null, red = redArray[source red value]
             *   else red = source rect value.
             * @param   greenArray  If greenArray is not null, green = greenArray[source
             *   green value] else green = source green value.
             * @param   blueArray   If blueArray is not null, blue = blueArray[source blue
             *   value] else blue = source blue value.
             * @param   alphaArray  If alphaArray is not null, alpha = alphaArray[source
             *   alpha value] else alpha = source alpha value.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  TypeError The sourceBitmapData, sourceRect or destPoint are null.
             */
        public:
            void     paletteMap(BitmapData *sourceBitmapData, Rectangle *sourceRect, Point *destPoint, std::vector<void *> redArray, std::vector<void *> greenArray, std::vector<void *> blueArray, std::vector<void *> alphaArray);

            /**
             * Generates a Perlin noise image.
             *
             *   The Perlin noise generation algorithm interpolates and combines individual random noise functions (called octaves)
             * into a single function that generates more natural-seeming random noise. Like musical octaves, each octave function is twice the
             * frequency of the one before it. Perlin noise has been described as a "fractal sum of noise" because it combines multiple sets of noise data
             * with different levels of detail.You can use Perlin noise functions to simulate natural
             * phenomena and landscapes, such as wood grain, clouds, and mountain ranges. In most cases, the output of a Perlin noise function
             * is not displayed directly but is used to enhance other images and give them pseudo-random variations.Simple digital random noise functions often produce images with harsh, contrasting points. This kind of harsh contrast
             * is not often found in nature. The Perlin noise algorithm blends multiple noise functions that operate at different levels of detail.
             * This algorithm results in smaller variations among neighboring pixel values.
             * @param   baseX   Frequency to use in the x direction. For example, to generate a noise that
             *   is sized for a 64 x 128 image, pass 64 for the baseX value.
             * @param   baseY   Frequency to use in the y direction. For example, to generate a noise that
             *   is sized for a 64 x 128 image, pass 128 for the baseY value.
             * @param   numOctaves  Number of octaves or individual noise functions to combine to create this noise. Larger numbers of octaves create
             *   images with greater detail. Larger numbers of octaves also require more processing time.
             * @param   randomSeed  The random seed number to use. If you keep all other parameters the same, you can generate different
             *   pseudo-random results by varying the random seed value. The Perlin noise function is a mapping function, not a
             *   true random-number generation function, so it creates the same results each time from the same random seed.
             * @param   stitch  A Boolean value. If the value is true, the method attempts to smooth the transition edges of the image to create seamless textures for
             *   tiling as a bitmap fill.
             * @param   fractalNoise    A Boolean value. If the value is true, the method generates fractal noise; otherwise,
             *   it generates turbulence. An image with turbulence has visible discontinuities in the gradient
             *   that can make it better approximate sharper visual effects like flames and ocean waves.
             * @param   channelOptions  A number that can be a combination of any of
             *   the four color channel values (BitmapDataChannel.RED,
             *   BitmapDataChannel.BLUE, BitmapDataChannel.GREEN, and
             *   BitmapDataChannel.ALPHA). You can use the logical OR
             *   operator (|) to combine channel values.
             * @param   grayScale   A Boolean value. If the value is true, a grayscale image is created by setting
             *   each of the red, green, and blue color channels to
             *   identical values. The alpha channel value is not affected if this value is
             *   set to true.
             * @param   offsets An array of points that correspond to x and y offsets for each octave.
             *   By manipulating the offset values you can smoothly scroll the layers of a perlinNoise image.
             *   Each point in the offset array affects a specific octave noise function.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             */
        public:
            void     perlinNoise(float baseX, float baseY, unsigned int numOctaves, int randomSeed, bool stitch, bool fractalNoise, unsigned int channelOptions, bool grayScale, std::vector<void *> offsets);

            /**
             * Performs a pixel dissolve either from a source image to a destination image or by using the same image.
             * Flash runtimes use a randomSeed value
             * to generate a random pixel dissolve. The return value
             * of the function must be passed in on subsequent calls to
             * continue the pixel dissolve until it is finished.
             *
             *   If the source image does not equal the destination image,
             * pixels are copied from the source to the destination by using all of the
             * properties. This process allows dissolving from a blank image into a
             * fully populated image.If the source and destination images are equal, pixels are
             * filled with the color parameter. This process allows dissolving away
             * from a fully populated image. In this mode, the destination
             * point parameter is ignored.
             * @param   sourceBitmapData    The input bitmap image to use. The source image can be a different
             *   BitmapData object, or it can refer to the current BitmapData instance.
             * @param   sourceRect  A rectangle that defines the area of the source image to use as input.
             * @param   destPoint   The point within the destination image (the current BitmapData
             *   instance) that corresponds to the upper-left corner of the source rectangle.
             * @param   randomSeed  The random seed to use to start the pixel dissolve.
             * @param   numPixels   The default is 1/30 of the source area (width x height).
             * @param   fillColor   An ARGB color value that you use to fill pixels whose
             *   source value equals its destination value.
             * @return  The new random seed value to use for subsequent calls.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @throws  TypeError The sourceBitmapData, sourceRect or destPoint are null.
             * @throws  TypeError The numPixels value is negative
             */
        public:
            int      pixelDissolve(BitmapData *sourceBitmapData, Rectangle *sourceRect, Point *destPoint, int randomSeed, int numPixels, unsigned int fillColor);

            /**
             * Scrolls an image by a certain (x, y) pixel amount. Edge
             * regions outside the scrolling area are left unchanged.
             * @param   x   The amount by which to scroll horizontally.
             * @param   y   The amount by which to scroll vertically.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             */
        public:
            void     scroll(int x, int y);

            /**
             * Converts a byte array into a rectangular region of pixel data. For each
             * pixel, the ByteArray.readUnsignedInt() method is called and the return value is
             * written into the pixel.  If the byte array ends before the full rectangle
             * is written, the function returns.  The data in the byte array is
             * expected to be 32-bit ARGB pixel values. No seeking is performed
             * on the byte array before or after the pixels are read.
             * @param   rect    Specifies the rectangular region of the BitmapData object.
             * @param   inputByteArray  A ByteArray object that consists of 32-bit unmultiplied pixel values
             *   to be used in the rectangular region.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             * @throws  EOFError The inputByteArray object does not include enough data
             *   to fill the area of the rect rectangle. The method fills as many pixels as
             *   possible before throwing the exception.
             * @throws  TypeError The rect or inputByteArray are null.
             */
        public:
            void     setPixels(Rectangle *rect, ByteArray *inputByteArray);

            /**
             * Converts a Vector into a rectangular region of pixel data. For each pixel, a Vector element is read
             * and written into the BitmapData pixel. The data in the Vector is expected to be 32-bit ARGB pixel values.
             * @param   rect    Specifies the rectangular region of the BitmapData object.
             * @param   inputVector A Vector object that consists of 32-bit unmultiplied pixel values to be used
             *   in the rectangular region.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             * @throws  RangeError The vector array is not large enough to read all the pixel data.
             */
        public:
            void     setVector(Rectangle *rect, std::vector<unsigned int> *inputVector);

            /**
             * Tests pixel values in an image against a specified threshold and sets pixels that pass the test to new color values.
             * Using the threshold() method, you can isolate and replace color ranges in an image and perform other
             * logical operations on image pixels.
             *
             *   The threshold() method's test logic is as follows:If ((pixelValue & mask) operation (threshold & mask)), then
             * set the pixel to color;Otherwise, if copySource == true, then
             * set the pixel to corresponding pixel value from sourceBitmap.The operation parameter specifies the comparison operator to use for the threshold test.
             * For example, by using "==" as the operation parameter, you
             * can isolate a specific color value in an image. Or by using {operation:
             * "<", mask: 0xFF000000, threshold: 0x7F000000, color:
             * 0x00000000}, you can set all destination pixels to be fully transparent
             * when the source image pixel's alpha is less than 0x7F. You can use this technique
             * for animated transitions and other effects.
             * @param   sourceBitmapData    The input bitmap image to use. The source image can be a different
             *   BitmapData object or it can refer to the current BitmapData instance.
             * @param   sourceRect  A rectangle that defines the area of the source image to use as input.
             * @param   destPoint   The point within the destination image (the current BitmapData
             *   instance) that corresponds to the upper-left corner of the source rectangle.
             * @param   operation   One of the following comparison operators, passed as a String: "<", "<=", ">", ">=", "==", "!="
             * @param   threshold   The value that each pixel is tested against to see if it meets or exceeds the threshhold.
             * @param   color   The color value that a pixel is set to if the threshold test succeeds. The default value is 0x00000000.
             * @param   mask    The mask to use to isolate a color component.
             * @param   copySource  If the value is true, pixel values from the source image are copied to the destination
             *   when the threshold test fails. If the value is false, the source image is not copied when the
             *   threshold test fails.
             * @return  The number of pixels that were changed.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             * @throws  TypeError The sourceBitmapData, sourceRect destPoint or operation are null.
             * @throws  ArgumentError The operation string is not a valid operation
             */
        public:
            unsigned int threshold(BitmapData *sourceBitmapData, Rectangle *sourceRect, Point *destPoint, std::string operation, unsigned int threshold, unsigned int color, unsigned int mask, bool copySource);

            /**
             * Locks an image so that any objects that reference the BitmapData object, such as Bitmap objects,
             * are not updated when this BitmapData object changes. To improve performance, use this method
             * along with the unlock() method before and after numerous calls to the
             * setPixel() or setPixel32() method.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             */
        public:
            void     lock();

            /**
             * Unlocks an image so that any objects that reference the BitmapData object, such as Bitmap objects,
             * are updated when this BitmapData object changes. To improve performance, use this method
             * along with the lock() method before and after numerous calls to the
             * setPixel() or setPixel32() method.
             * @param   changeRect  The area of the BitmapData object that has changed. If you do not specify a value for
             *   this parameter, the entire area of the BitmapData object is considered
             *   changed. This parameter requires Flash Player version 9.0.115.0 or later.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             */
        public:
            void     unlock(Rectangle *changeRect);

            /**
             * Computes a 256-value binary number histogram of a BitmapData object. This method returns a Vector object
             * containing four Vector.<Number> instances (four Vector objects that contain Number objects).
             * The four Vector instances represent the red, green, blue and alpha components
             * in order. Each Vector instance contains 256 values that represent the population
             * count of an individual component value, from 0 to 255.
             * @param   hRect   The area of the BitmapData object to use.
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            std::vector<float> *histogram(Rectangle *hRect);

        public:
            ByteArray *encode(Rectangle *rect, Object *compressor, ByteArray *byteArray);
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_BITMAPDATA_AS
#endif // __cplusplus

