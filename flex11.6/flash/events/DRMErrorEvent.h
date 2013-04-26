#if !defined(FLEX11_6_FLASH_EVENTS_DRMERROREVENT_AS)
#define FLEX11_6_FLASH_EVENTS_DRMERROREVENT_AS
#if defined(__cplusplus)


namespace flash
{
    namespace events
    {
        class Event;
    }
}
namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMContentData;
        }
    }
}

/// @eventType  flash.events.DRMErrorEvent.DRM_ERROR
//[Event(name="drmError",type="flash.events.DRMErrorEvent")]

/**
 * The DRMErrorEvent class provides information about errors that occur when playing digital rights management (DRM)
 * encrypted files.
 *
 *   <p class="- topic/p ">The runtime dispatches a DRMErrorEvent object when a NetStream object, trying to play a digital rights management
 * (DRM) encrypted file, encounters a DRM-related error. For example, a DRMErrorEvent object is dispatched
 * when the content provider does not support the viewing application,
 * or when the user authorization fails, possibly because the user has not purchased the content.</p><p class="- topic/p ">
 * In the case of invalid user credentials, the DRMAuthenticateEvent object handles the error by repeatedly dispatching
 * until the user enters valid credentials, or the application denies further attempts. The application should listen
 * to any other DRM error events in order to detect, identify, and handle the DRM-related errors.
 * </p><p class="- topic/p ">
 * This class provides properties containing the object throwing the exception, the error code, and,
 * where applicable, a suberror code and text message containing information related to the error. For
 * a description of DRM-related error codes, see the <xref href="../../runtimeErrors.html" class="- topic/xref ">Runtime error codes</xref>.
 * The DRM-related error codes start at error 3300.
 * </p>
 *
 *   EXAMPLE:
 *
 *   <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">package
 * {
 * import flash.display.Sprite;
 * import flash.events.AsyncErrorEvent;
 * import flash.events.NetStatusEvent;
 * import flash.events.DRMErrorEvent;
 * import flash.media.Video;
 * import flash.net.NetConnection;
 * import flash.net.NetStream;
 *
 *   public class DRMVideoExample extends Sprite
 * {
 * var videoURL:String = "Video.flv";
 * var videoConnection:NetConnection;
 * var videoStream:NetStream;
 * var video:Video = new Video();
 *
 *   public function DRMVideoExample()
 * {
 * videoConnection = new NetConnection();
 * videoConnection.addEventListener(NetStatusEvent.NET_STATUS, netStatusHandler);
 * videoConnection.connect(null);
 * }
 *
 *   private function connectStream():void {
 * videoStream = new NetStream(videoConnection);
 * videoStream.addEventListener(NetStatusEvent.NET_STATUS, netStatusHandler);
 * videoStream.addEventListener(AsyncErrorEvent.ASYNC_ERROR, asyncErrorHandler);
 * videoStream.addEventListener(DRMErrorEvent.DRM_ERROR, drmErrorEventHandler);
 * video.attachNetStream(videoStream);
 * videoStream.play(videoURL);
 * addChild(video);
 * }
 *
 *   private function netStatusHandler(event:NetStatusEvent):void {
 * switch (event.info.code) {
 * case "NetConnection.Connect.Success":
 * connectStream();
 * break;
 * case "NetStream.Play.StreamNotFound":
 * trace("Unable to locate video: " + videoURL);
 * break;
 * }
 * }
 *
 *   private function asyncErrorHandler(event:AsyncErrorEvent):void {
 * // ignore AsyncErrorEvent events.
 * }
 *
 *   private function drmErrorEventHandler(event:DRMErrorEvent):void {
 * trace(event.toString());
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   AIR 1.0
 * @playerversion   Flash 10.1
 */
using namespace flash::events;
using namespace flash::net::drm;

namespace flash
{
    namespace events
    {
        class DRMErrorEvent: public ErrorEvent
        {
            /**
             * The DRMErrorEvent.DRM_ERROR constant defines the value of the
             * type property of a drmError event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.errorIDA numerical error code assigned to the problem.subErrorIDAn error code that indicates more detailed information about
             * the underlying problem.targetThe NetStream object.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @playerversion   Flash 10.1
             */
        public:
            static const std::string DRM_ERROR;
        public:
            static const std::string DRM_LOAD_DEVICEID_ERROR;

            /**
             * An error ID that indicates more detailed information about the underlying problem.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @playerversion   Flash 10.1
             */
        public:
            int          subErrorID();

            /**
             * The DRMContentData for the media file.
             *
             *   You can use the object referenced by the contentData property
             * to retrieve the related DRM voucher from the DRMManager voucher cache. The voucher
             * properties describe the license available to the user and may explain why the
             * DRM-protected content cannot be viewed.
             * @langversion 3.0
             * @playerversion   AIR 1.5
             * @playerversion   Flash 10.1
             */
        public:
            flash::net::drm::DRMContentData *contentData();
        public:
            void         contentData(DRMContentData *value);

            /**
             * Indicates whether a system update is needed to play the DRM-protected content.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Flash 10.1
             */
        public:
            bool         systemUpdateNeeded();

            /**
             * Indicates whether a DRM update is needed to play the DRM-protected content.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @playerversion   Flash 10.1
             */
        public:
            bool         drmUpdateNeeded();

            /**
             * Creates a copy of the DRMErrorEvent object and sets the value of each property to match
             * that of the original.
             * @return  A new DRMErrorEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @playerversion   Flash 10.1
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates an Event object that contains specific information about DRM error events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one type of DRMAuthenticate event: DRMAuthenticateEvent.DRM_AUTHENTICATE.
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
             * @param   inErrorDetail   Where applicable, the specific syntactical details of the error.
             * @param   inErrorCode The major error code.
             * @param   insubErrorID    The minor error ID.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @playerversion   Flash 10.1
             */
        public:
            DRMErrorEvent(std::string type, bool bubbles, bool cancelable, std::string inErrorDetail, int inErrorCode, int insubErrorID, DRMContentData *inMetadata, bool inSystemUpdateNeeded, bool inDrmUpdateNeeded);

            /**
             * Returns a string that contains all the properties of the DRMErrorEvent object.
             * The string is in the following format:
             * [DRMErrorEvent type=value bubbles=value cancelable=value
             * eventPhase=value errroID=value subErrorID=value text=value
             * @return  A string that contains all the properties of the DRMErrorEvent object.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @playerversion   Flash 10.1
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_DRMERROREVENT_AS
#endif // __cplusplus

