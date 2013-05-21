#if !defined(FLEX11_6_FLASH_MEDIA_STAGEVIDEO_AS)
#define FLEX11_6_FLASH_MEDIA_STAGEVIDEO_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace net
    {
        class NetStream;
    }
}
namespace flash
{
    namespace media
    {
        class Camera;
    }
}
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

/**
 * Dispatched by the StageVideo object when the render state of the StageVideo object changes.
 * @eventType   flash.events.StageVideoEvent.RENDER_STATE
 */
//[Event(name="renderState",type="flash.events.StageVideoEvent")]

using namespace flash::events;
using namespace flash::geom;
using namespace flash::media;
using namespace flash::net;

namespace flash
{
    namespace media
    {
        /**
         * The StageVideo object uses the device's hardware acceleration capabilities, if available, to display
         * live or recorded video in an application. Hardware acceleration capabilities are available on most devices.
         * The StageVideo object supports the same video formats as the Video object.
         * See the flash.net.NetStream class for more information about these formats.
         *
         *   <p class="- topic/p "><i class="+ topic/ph hi-d/i ">AIR profile support:</i> In AIR 2.5, this feature is supported
         * only on devices that run AIR for TV. See
         * <xref href="http://help.adobe.com/en_US/air/build/WS144092a96ffef7cc16ddeea2126bb46b82f-8000.html" class="- topic/xref ">
         * AIR Profile Support</xref> for more information regarding API support across multiple profiles.
         * </p><p class="- topic/p ">The video displayed by the StageVideo object always appears in a rectangular area on the stage
         * behind all Flash display list objects. Therefore, the StageVideo object takes advantage of hardware acceleration
         * while supporting the most common case for displaying video: a rectangular display area overlaid with
         * video controls.</p><p class="- topic/p ">The benefits to using a StageVideo object instead of the Video object are:</p><p class="- topic/p "><ul class="- topic/ul "><li class="- topic/li ">Optimal video playback performance because of using hardware acceleration.</li><li class="- topic/li ">Decreased processor and power usage.</li><li class="- topic/li ">Flexibility and creativity for development of content, such as video controls,
         * that appears in front of the StageVideo object.</li></ul></p><p class="- topic/p ">Because the StageVideo object uses device hardware capabilities, a StageVideo object is subject to the following constraints
         * compared to a Video object:</p><p class="- topic/p "><ul class="- topic/ul "><li class="- topic/li ">The video display area can only be a rectangle. You cannot use more advanced display areas, such as
         * elliptical or irregular shapes.</li><li class="- topic/li ">You cannot rotate a StageVideo object.</li><li class="- topic/li ">You cannot bitmap cache a StageVideo object,</li><li class="- topic/li ">You cannot use BitmapData to access the video data.</li><li class="- topic/li ">You cannot embed the video in the SWF file.  You can use a StageVideo object only with the NetStream object.</li><li class="- topic/li ">You cannot apply filters, blend modes, or alpha values to a StageVideo object.</li><li class="- topic/li ">You cannot apply color transforms, 3D transforms, or matrix transforms to a StageVideo object.</li><li class="- topic/li ">You cannot apply a mask or scale9Grid to a StageVideo object.</li><li class="- topic/li ">Blend modes that you apply to display objects that are in front of a StageVideo object do not apply to the StageVideo object.</li><li class="- topic/li ">You can place a StageVideo object only on full pixel boundaries.</li><li class="- topic/li ">For each SWF file, Flash Player limits the number of StageVideo objects that can concurrently display
         * videos to four. However, the actual limit can be lower, depending on device hardware resources.
         * On AIR for TV devices, only one StageVideo object at a time can display a video.</li><li class="- topic/li ">The video timing is not synchronized with the timing of Flash content that the runtime displays.</li><li class="- topic/li ">Though the video presentation is the best available for the given device hardware, it is not 100% "pixel identical" across devices.
         * Slight variations can occur due to driver and hardware differences.</li><li class="- topic/li ">A few devices do not support all required color spaces. For example, some devices do not support BT.709, the H.264 standard. In such
         * cases you can use BT.601 for fast display.</li><li class="- topic/li ">You cannot use stage video with WMODE settings such as <codeph class="+ topic/ph pr-d/codeph ">normal</codeph>, <codeph class="+ topic/ph pr-d/codeph ">opaque</codeph>, or <codeph class="+ topic/ph pr-d/codeph ">transparent</codeph>.
         * Stage video supports only <codeph class="+ topic/ph pr-d/codeph ">WMODE=direct</codeph> when not in full screen mode. WMODE has no effect in Safari 4 or higher, IE 9 or higher,
         * or in AIR for TV.</li></ul></p><p class="- topic/p ">The following steps summarize how to use a StageVideo object to play a video:</p><p class="- topic/p "><ol class="- topic/ol "><li class="- topic/li ">Listen for the StageVideoAvailabilityEvent.STAGE_VIDEO_AVAILABILITY event to find out when the
         * Stage.stageVideos vector has changed. (Not supported for AIR 2.5 for TV.) </li><li class="- topic/li ">If the StageVideoAvailabilityEvent.STAGE_VIDEO_AVAILABILITY event reports that stage video is available,
         * use the <codeph class="+ topic/ph pr-d/codeph ">Stage.stageVideos</codeph> Vector object within the event handler to access a StageVideo object.
         * In AIR 2.5 for TV, access <codeph class="+ topic/ph pr-d/codeph ">Stage.stageVideos</codeph> after the first SWF frame has rendered.
         * <b class="+ topic/ph hi-d/b ">Note:</b> You cannot create a StageVideo object.</li><li class="- topic/li ">Attach a NetStream object using <codeph class="+ topic/ph pr-d/codeph ">StageVideo.attachNetStream()</codeph>.</li><li class="- topic/li ">Play the video using <codeph class="+ topic/ph pr-d/codeph ">NetStream.play()</codeph>.</li><li class="- topic/li ">Listen for the <codeph class="+ topic/ph pr-d/codeph ">StageVideoEvent.RENDER_STATE</codeph> event on the StageVideo object to determine the status of playing the video.
         * Receipt of this event also indicates that the width and height properties of the video have been initialized or changed. </li><li class="- topic/li ">Listen for the <codeph class="+ topic/ph pr-d/codeph ">VideoEvent.RENDER_STATE</codeph> event on the Video object. This event provides the same statuses as
         * StageVideoEvent.RENDER_STATE, so you can also use it to determine whether GPU acceleration is available. Receipt of this event
         * also indicates that the width and height properties of the video have been initialized or changed. (Not supported for AIR 2.5 for TV.)</li></ol></p><p class="- topic/p ">If a <codeph class="+ topic/ph pr-d/codeph ">StageVideoEvent.RENDER_STATE</codeph> event indicates that the video cannot be played,
         * you can revert to using a Video object instead of a StageVideo object. This event is
         * dispatched after the video has been attached to a NetStream object and is playing. Also, depending on the platform,
         * any change in the playing status can result in dispatching the event.
         * Handle the <codeph class="+ topic/ph pr-d/codeph ">StageVideoEvent.RENDER_STATE</codeph> event to ensure that the application plays the video
         * or gracefully does not play the video.
         * </p><p class="- topic/p ">If a running video goes into full screen mode from a WMODE that does not support stage video, stage video can become available.
         * Likewise, if the user exits full screen mode, stage video can become unavailable. In these cases, the Stage.stageVideos vector changes.
         * To receive notification of this change, listen to the StageVideoAvailabilityEvent.STAGE_VIDEO_AVAILABITY event. <b class="+ topic/ph hi-d/b ">NOTE:</b> This notification
         * is not available in AIR 2.5 for TV.</p>
         * @langversion 3.0
         * @playerversion   AIR 2.5
         * @playerversion   Flash 10.2
         */
        class StageVideo : public flash::events::EventDispatcher
        {
            /**
             * The absolute position and size of the video surface in pixels.
             *
             *   The position of the video is relative to the upper left corner of the stage.
             * The valid range of the x and y properties of the viewPort
             * Rectangle object are -8192 to 8191. Therefore, you can position the video
             * completely or partially off the stage. You can also make the video larger than the stage if you
             * make the width and height properties of the viewPort
             * property larger than the stage.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             * @playerversion   Flash 10.2
             * @throws  RangeError The Rectangle value is not valid.
             */
        public:
            flash::geom::Rectangle *viewPort();
        public:
            void         viewPort(Rectangle *rect);

            /**
             * The pan setting for displaying the video, specified as a Point object.
             *
             *   By default, the value of pan is (0,0).
             * This default value centers the video in the rectangle specified by StageVideo.viewPort.The pan value is significant only when the zoom property value is not the
             * default value (1.0, 1.0). When a video displays in the StageVideo.viewPort rectangle
             * with the default zoom value, the platform sizes the video to fit exactly into the rectangle. Therefore, the entire
             * video is visible. However, if a zoom factor is specified, the entire video is not visible. In this case, you can
             * set the pan value to specify which subrectangle of the video to show
             * in the StageVideo.viewPort rectangle.The valid values of the pan property range from (-1.0, -1.0) to (1.0, 1.0).
             * Specifically:
             * A pan value of (-1.0, -1.0) places the upper-left pixel of the video at the upper-left
             * position of the StageVideo.viewPort rectangle.
             *
             *   A pan value of (1.0, 1.0) places the lower-right pixel of the video at the lower-right
             * position of the StageVideo.viewPort rectangle.
             *
             *   A pan value of (1.0, -1.0) places the upper-right pixel of the video at the upper-right
             * position of the StageVideo.viewPort rectangle.
             *
             *   A pan value of (-1.0, 1.0) places the lower-left pixel of the video at the lower-left
             * position of the StageVideo.viewPort rectangle.
             * Values between -1.0 and 1.0 pan according to scale.If you set the pan property to a value outside the valid range,
             * a RangeError exception is thrown.
             * The runtime resets the value to the last valid value.Also, consider that to use a StageVideo object, you assign an element
             * of the Stage.stageVideos Vector object to a StageVideo variable. When you set
             * the pan property of the StageVideo variable, the underlying Stage.stageVideos Vector
             * element also changes. If you later assign that element to another StageVideo variable to play
             * another video, reset the pan property.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             * @playerversion   Flash 10.2
             * @throws  RangeError The Point value is not valid.
             */
        public:
            void         pan(Point *point);
        public:
            Point       *pan();

            /**
             * The zoom setting of the video, specified as a Point object.
             *
             *   The zoom point is a scale factor. By default, the value of zoom is (1.0, 1.0).
             * This default value displays the entire video in the StageVideo.viewPort rectangle.The valid values of the zoom property range from (1.0, 1.0) to (16.0, 16.0).
             * The x property of the zoom Point object specifies the zoom value for the horizontal pixels, and
             * the y property specifies the zoom value for the vertical pixels.For example, a zoom value of (2.0, 2.0) displays only half the horizontal pixels
             * and half the vertical pixels in the StageVideo.viewPort rectangle. That is, the video still fills the
             * StageVideo.viewPort rectangle, but only half the video is visible, creating a 2x zoom effect.
             * Similarly, a zoom value of (16.0, 16.0) displays only 1/16 of the horizontal pixels
             * and 1/16 of the vertical pixels in the StageVideo.viewPort rectangle,
             * zooming in the maximum amount of 16x.When you set the zoom property, set the pan property so that the StageVideo.viewPort rectangle
             * shows the appropriate subrectangle of the video.Consider the following situation where it is useful to set a different value for the
             * x and y properties of the zoom Point object.
             * First, note that when a video displays in the StageVideo.viewPort rectangle
             * with the default zoom value, the platform sizes the video to fit exactly into the rectangle.
             * If the video's rectangle does not scale evenly to the StageVideo.viewPort rectangle,
             * the video display can be distorted.
             * That is, the aspect ratios of the video and the StageVideo.viewPort are not equal.
             * This case can occur, for example, if the video has a different width than height, but the StageVideo.viewPort
             * property specifies a square.
             * To resolve the distortion, set different values for the
             * x and y properties of the zoom Point object.
             * Then set the pan property to make sure the StageVideo.viewPort rectangle
             * shows the appropriate subrectangle of the video.If you set the zoom property to a value outside the valid range,
             * a RangeError exception is thrown.
             * The runtime resets the value to the last valid value.Also, consider that to use a StageVideo object, you assign an element
             * of the Stage.stageVideos Vector object to a StageVideo variable. When you set
             * the zoom property of the StageVideo variable, the underlying Stage.stageVideos Vector
             * element also changes. If you later assign that element to another StageVideo variable to play
             * another video, reset the zoom property.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             * @playerversion   Flash 10.2
             * @throws  RangeError The Point value is not valid.
             */
        public:
            void         zoom(Point *point);
        public:
            Point       *zoom();

            /**
             * The depth level of a StageVideo object relative to other StageVideo objects.
             *
             *   StageVideo objects always display behind other objects on the stage. If a platform supports more than one
             * StageVideo object, the depth property indicates a StageVideo object's depth level.
             * The bottom StageVideo object's depth property has the smallest value.
             * If multiple StageVideo objects have the same depth setting, the order they appear in the
             * stage,stageVideos Vector determines their relative depth.Note: AIR for TV devices support only one StageVideo object. Therefore, this property is not
             * applicable for those devices. It is a placeholder
             * for future support on other devices.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             * @playerversion   Flash 10.2
             */
        public:
            void         depth(int depth);
        public:
            int          depth();

            /**
             * An integer specifying the width of the video stream, in pixels.
             *
             *   You may want to use this property, for example, to ensure that the user is seeing the
             * video at the same width at which it was captured,
             * regardless of the size of the StageVideo.viewPort rectangle.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             * @playerversion   Flash 10.2
             */
        public:
            int          videoWidth();

            /**
             * An integer specifying the height of the video stream, in pixels.
             *
             *   You may want to use this property, for example, to ensure that the user is seeing the
             * video at the same height at which it was captured,
             * regardless of the size of the StageVideo.viewPort rectangle.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             * @playerversion   Flash 10.2
             */
        public:
            int          videoHeight();

            /**
             * Returns the names of available color spaces for this video surface.
             * Usually this list includes "BT.601" and "BT.709". On some configurations, only
             * "BT.601" is supported which means a video is possibly not rendered in the
             * correct color space.
             *
             *   Note: On AIR for TV devices, a value of "BT.601" indicates software playback,
             * and a value of "BT.709" indicates hardware playback.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             * @playerversion   Flash 10.2
             */
        public:
            std::vector<std::string> colorSpaces();

            /**
             * Specifies a video stream to be displayed within the boundaries of the StageVideo object in the application.
             * The video stream is either a video file played with NetStream.play(), or null.
             * A video file can be stored on the local file
             * system or on Flash Media Server. If the value of the netStream argument is null,
             * the video is no longer played in the StageVideo object.
             *
             *   Before calling attachNetStream() a second time,
             * call the currently attached NetStream object's close() method.
             * Calling close()
             * releases all the resources, including hardware decoders, involved with playing the video.
             * Then you can call attachNetStream()
             * with either another NetStream object or null.
             * You do not need to use this method if a video file contains only audio; the audio
             * portion of a video file is played automatically
             * when you call NetStream.play(). To control the audio
             * associated with a video file, use the soundTransform property
             * of the NetStream object that plays the video file.
             * @param   netStream   A NetStream object. To drop the connection to the StageVideo object, pass
             *   null.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             * @playerversion   Flash 10.2
             */
        public:
            void     attachNetStream(NetStream *netStream);

        public:
            void     attachCamera(Camera *theCamera);

        public:
            StageVideo();
        };
    }
}

#endif // FLEX11_6_FLASH_MEDIA_STAGEVIDEO_AS
#endif // __cplusplus

