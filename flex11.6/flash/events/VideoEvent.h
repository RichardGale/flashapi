#if !defined(FLEX11_6_FLASH_EVENTS_VIDEOEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_VIDEOEVENT_AS
#if defined(__cplusplus)


/**
 * <p class="- topic/p ">This event class reports the current video rendering status. Use this event for the following purposes:</p><ul class="- topic/ul "><li class="- topic/li ">To find out when size of the Video display changes or is initialized. Use this event instead of polling for size changes.
 * When you receive this event you can access <codeph class="+ topic/ph pr-d/codeph ">Video.videoSize</codeph> and <codeph class="+ topic/ph pr-d/codeph ">Video.videoHeight</codeph> to get the pixel
 * dimensions of the video that is currently playing.</li><li class="- topic/li ">To find out whether the video is decoded by software or the GPU. If the <codeph class="+ topic/ph pr-d/codeph ">status</codeph> property returns "accelerated",
 * you should switch to using the StageVideo class, if possible. </li></ul>
 * @langversion 3.0
 * @playerversion   Flash 10.2
 * @playerversion   AIR (unsupported)
 */

namespace flash
{
    namespace events
    {
        class VideoEvent: public Event
        {
            /**
             * Defines the value of the type property of a renderState event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the event.statusThe rendering status reported by the event.targetThe Video object reporting rendering status.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            static const std::string RENDER_STATE;

            /**
             * For internal use only. Use flash.media.VideoStatus.UNAVAILABLE instead.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            static const std::string RENDER_STATUS_UNAVAILABLE;

            /**
             * For internal use only. Use flash.media.VideoStatus.SOFTWARE instead.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            static const std::string RENDER_STATUS_SOFTWARE;

            /**
             * For internal use only. Use flash.media.VideoStatus.ACCELERATED instead.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            static const std::string RENDER_STATUS_ACCELERATED;
        public:
            const std::string codecInfo;

            /**
             * Returns the rendering status of the VideoEvent object. Possible values include "unavailable", "software", and "accelerated".
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            std::string  status();

            /**
             * Constructor.
             * @param   type    The type of event. Possible values are: VideoEvent.RENDER_STATE.
             * @param   bubbles Indicates whether this Event object participates in the bubbling stage of the event flow.
             * @param   cancelable  Indicates whether you can cancel the action that triggers this event.
             * @param   status  The rendering state of the video.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            VideoEvent(std::string type, bool bubbles, bool cancelable, std::string status);
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_VIDEOEVENT_AS
#endif // __cplusplus

