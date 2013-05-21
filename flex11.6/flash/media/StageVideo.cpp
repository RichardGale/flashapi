

#include "StageVideo.h"
#include "flash/events/EventDispatcher.h"
#include "flash/net/NetStream.h"
#include "flash/media/Camera.h"
#include "flash/geom/Rectangle.h"
#include "flash/geom/Point.h"

    /**
     * Dispatched by the StageVideo object when the render state of the StageVideo object changes.
     * @eventType   flash.events.StageVideoEvent.RENDER_STATE
     */

using namespace flash::events;
using namespace flash::geom;
using namespace flash::media;
using namespace flash::net;

namespace flash {
namespace media {


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
        flash::geom::Rectangle* StageVideo::viewPort()                       ;
        void StageVideo::viewPort(Rectangle* rect)       ;

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
        void StageVideo::pan(Point* point)       ;
        Point* StageVideo::pan()        ;

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
        void StageVideo::zoom(Point* point)       ;
        Point* StageVideo::zoom()        ;

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
        void StageVideo::depth(int depth)       ;
        int StageVideo::depth()      ;

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
        int StageVideo::videoWidth()      ;

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
        int StageVideo::videoHeight()      ;

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
        std::vector<std::string> StageVideo::colorSpaces()                  ;

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
        void StageVideo::attachNetStream(NetStream* netStream)       ;

        void StageVideo::attachCamera(Camera* theCamera)       ;

        StageVideo::StageVideo();
}
}

