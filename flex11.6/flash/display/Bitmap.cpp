

#include "Bitmap.h"
#include "flash/display/BitmapData.h"

    /**
     * The Bitmap class represents display objects that represent bitmap images. These can be images
     * that you load with the flash.display.Loader class, or they can be images that you create with
     * the <codeph class="+ topic/ph pr-d/codeph ">Bitmap()</codeph> constructor.
     * 
     *   <p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">Bitmap()</codeph> constructor allows you to create a Bitmap object that 
     * contains a reference to a BitmapData object. After you create a Bitmap object, use the 
     * <codeph class="+ topic/ph pr-d/codeph ">addChild()</codeph> or <codeph class="+ topic/ph pr-d/codeph ">addChildAt()</codeph> method of the parent DisplayObjectContainer 
     * instance to place the bitmap on the display list.</p><p class="- topic/p ">A Bitmap object can share its BitmapData reference among several Bitmap objects,
     * independent of translation or rotation properties. Because you can create multiple Bitmap
     * objects that reference the same BitmapData object, multiple display objects can use the
     * same complex BitmapData object without incurring the memory overhead of a BitmapData
     * object for each display object instance.</p><p class="- topic/p ">A BitmapData object can be drawn to the screen by a Bitmap object in one of two ways:
     * by using the vector renderer as a fill-bitmap shape, or by using a faster pixel-copying routine.
     * The pixel-copying routine is substantially faster than the vector renderer, but the Bitmap object
     * must meet certain conditions to use it:</p><ul class="- topic/ul "><li class="- topic/li "> No stretching, rotation, or skewing can be applied to the Bitmap object.</li><li class="- topic/li "> No color transform can be applied to the Bitmap object. </li><li class="- topic/li "> No blend mode can be applied to the Bitmap object. </li><li class="- topic/li "> No clipping can be done through mask layers or <codeph class="+ topic/ph pr-d/codeph ">setMask()</codeph> methods. </li><li class="- topic/li "> The image itself cannot be a mask. </li><li class="- topic/li "> The destination coordinates must be on a whole pixel boundary. </li></ul><p class="- topic/p ">If you load a Bitmap object from a domain other than that of the Loader object used to
     * load the image, and there is no URL policy file that permits access to the domain of
     * the Loader object, then a script in that domain cannot access the Bitmap
     * object or its properties and methods. For more information, see the Flash Player Developer Center Topic: 
     * <xref href="http://www.adobe.com/go/devnet_security_en" scope="external" class="- topic/xref ">Security</xref>.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> The Bitmap class is not a subclass of the InteractiveObject class, so
     * it cannot dispatch mouse events. However, you can use the <codeph class="+ topic/ph pr-d/codeph ">addEventListener()</codeph> method
     * of the display object container that contains the Bitmap object.</p>
     * 
     *   EXAMPLE:
     * 
     *   The following example uses the BitmapExample class to load the
     * "Image.gif" image into a DisplayObject in the default location (<i class="+ topic/ph hi-d/i ">x = 0, y = 0</i>). A copy
     * of Image.gif is then placed to the right of the original, which has new colors applied to pixels
     * that pass a test using the <codeph class="+ topic/ph pr-d/codeph ">threshold()</codeph> method.
     * This task is accomplished using the following steps:
     * <ol class="- topic/ol "><li class="- topic/li ">A property <codeph class="+ topic/ph pr-d/codeph ">url</codeph> is created, which is the location and name of the image file</li><li class="- topic/li ">The class constructor calls the <codeph class="+ topic/ph pr-d/codeph ">configureAssets()</codeph> method, which, in turn, calls the 
     * <codeph class="+ topic/ph pr-d/codeph ">completeHandler()</codeph> method.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">configureAssets()</codeph> creates a Loader object, which then instantiates an event listener,
     * which is dispatched when <codeph class="+ topic/ph pr-d/codeph ">completeHandler()</codeph> completes the image manipulation.</li><li class="- topic/li ">Next, the <codeph class="+ topic/ph pr-d/codeph ">buildChild()</codeph> method creates a new instance of a URLRequest object,
     * <codeph class="+ topic/ph pr-d/codeph ">request</codeph>, with <codeph class="+ topic/ph pr-d/codeph ">url</codeph> passed so the file name and location are known.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">request</codeph> object is passed to the <codeph class="+ topic/ph pr-d/codeph ">loader.load()</codeph> method, which loads the image
     * into memory via a display object.</li><li class="- topic/li ">The image is then placed on the display list, which promptly displays the image on screen at
     * coordinates <i class="+ topic/ph hi-d/i ">x = 0, y = 0</i>.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">completeHandler()</codeph> method then performs the following tasks:
     * <ol outputclass="A" class="- topic/ol "><li class="- topic/li ">Creates a second Loader object, along with a Bitmap object, which is initialized with the
     * Loader object.</li><li class="- topic/li ">Creates a second Bitmap object, <codeph class="+ topic/ph pr-d/codeph ">duplicate</codeph>, which in turn calls the
     * <codeph class="+ topic/ph pr-d/codeph ">duplicateImage()</codeph> method, which creates a duplicate of the original image. </li><li class="- topic/li ">Creates a BitmapData object, which is assigned to the <codeph class="+ topic/ph pr-d/codeph ">duplicate</codeph> object's
     * BitmapData object.</li><li class="- topic/li ">Creates a new Rectangle object initialized with the same coordinates, width, and height
     * as the original image.</li><li class="- topic/li ">Creates a new Point object, which defaults to <i class="+ topic/ph hi-d/i ">x = 0, y = 0</i>.</li><li class="- topic/li ">Creates the following variables:
     * <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">operation</codeph>: applies the new color when the threshold
     * value is &gt;= the original.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">threshold</codeph>: the value against which each pixel is compared is set to
     * light gray with an alpha of 0xCC. </li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">color</codeph>: the color that the pixels will be set to that pass the threshold
     * test, which is solid yellow in this case.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">mask</codeph>: set to the exact opposite of color, (transparent blue).</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">copySource</codeph>: set to false, indicating that the pixel values are not copied
     * in the event the threshold value does not pass.  This value has no meaning because
     * the image is duplicated and only pixels that pass the threshold test are changed.</li></ul></li><li class="- topic/li ">Calls the <codeph class="+ topic/ph pr-d/codeph ">threshold()</codeph> method by using the preceding variables.  The resulting threshold
     * equation is as follows: <codeph class="+ topic/ph pr-d/codeph ">if (current pixel Value &amp; 0x000000FF) &gt;=
     * (0xCCCCCCCC &amp; 0x000000FF) then set pixel to 0xFFFFFF00</codeph>. </li></ol></li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Notes:</b><ul class="- topic/ul "><li class="- topic/li ">You will need to compile the SWF file with "Local playback security" set to "Access local files only".
     * </li><li class="- topic/li ">This example requires that a file named Image.gif be placed in the same directory as your SWF file.
     * </li><li class="- topic/li ">It is recommended that you use an image up to 80 pixels wide. </li></ul></p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
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
     *   public class BitmapExample extends Sprite {
     * private var url:String = "Image.gif";
     * private var size:uint = 80;
     * 
     *   public function BitmapExample() {
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
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */

using namespace flash::display;

namespace flash {
namespace display {


        /**
         * Controls whether or not the Bitmap object is snapped to the nearest pixel. The PixelSnapping
         * class includes possible values:
         * 
         *   PixelSnapping.NEVER   No pixel snapping occurs.PixelSnapping.ALWAYS   The image is always snapped to the nearest
         * pixel, independent of transformation.PixelSnapping.AUTO   The image is snapped
         * to the nearest pixel if it is drawn with no rotation
         * or skew and it is drawn at a scale factor of 99.9% to 100.1%. If these conditions are satisfied,
         * the bitmap image is drawn at 100% scale, snapped to the nearest pixel. Internally, this value allows the image
         * to be drawn as fast as possible using the vector renderer.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string Bitmap::pixelSnapping()         ;
        void Bitmap::pixelSnapping(std::string value)       ;

        /**
         * Controls whether or not the bitmap is smoothed when scaled. If true, the bitmap is
         * smoothed when scaled. If false, the bitmap is not smoothed when scaled.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        bool Bitmap::smoothing()          ;
        void Bitmap::smoothing(bool value)       ;

        /**
         * The BitmapData object being referenced.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::display::BitmapData* Bitmap::bitmapData()                           ;
        void Bitmap::bitmapData(BitmapData* value)       ;

        /**
         * Initializes a Bitmap object to refer to the specified BitmapData object.
         * @param   bitmapData  The BitmapData object being referenced.
         * @param   pixelSnapping   Whether or not the Bitmap object is snapped to the nearest pixel.
         * @param   smoothing   Whether or not the bitmap is smoothed when scaled. For example, the 
         *   following examples show the same bitmap scaled by a factor of 3, with 
         *   smoothing set to false (left) and true (right):
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        Bitmap::Bitmap(BitmapData* bitmapData, std::string pixelSnapping, bool smoothing);
}
}

