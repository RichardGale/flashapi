#if !defined(FLEX11_6_FLASH_EVENTS_STAGEVIDEOAVAILABILITYEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_STAGEVIDEOAVAILABILITYEVENT_AS
#if defined(__cplusplus)


/**
 * <p class="- topic/p ">This event fires when the state of the <codeph class="+ topic/ph pr-d/codeph ">Stage.stageVideos</codeph> property changes.
 * This property can change when a user expands a video to full screen display from a <codeph class="+ topic/ph pr-d/codeph ">wmode</codeph>
 * that does not support StageVideo (for example, <codeph class="+ topic/ph pr-d/codeph ">wmode=normal</codeph>, <codeph class="+ topic/ph pr-d/codeph ">wmode=opaque</codeph>, or
 * <codeph class="+ topic/ph pr-d/codeph ">wmode=transparent</codeph>). Expanding to full screen can cause the <codeph class="+ topic/ph pr-d/codeph ">Stage.stageVideos</codeph>
 * vector to become populated. Conversely, exiting full screen display can cause the <codeph class="+ topic/ph pr-d/codeph ">Stage.stageVideos</codeph>
 * vector to become empty.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">NOTE:</b> This notification occurs only when the state of the <codeph class="+ topic/ph pr-d/codeph ">Stage.stageVideos</codeph> property changes.
 * As a result, behavior may vary according to platform and browser. On Windows, for example,
 * the <codeph class="+ topic/ph pr-d/codeph ">stageVideoAvailability</codeph> event is not dispatched when you go into full screen mode while
 * <codeph class="+ topic/ph pr-d/codeph ">wmode</codeph> is set to <codeph class="+ topic/ph pr-d/codeph ">direct</codeph>. On some other platforms, however, the same behavior causes Flash Player
 * to reallocate resources. In those cases, the <codeph class="+ topic/ph pr-d/codeph ">Stage.stageVideos</codeph> property state changes, and the event fires.
 * You can detect changes to full screen mode by listening to the <codeph class="+ topic/ph pr-d/codeph ">flash.events.FullScreenEvent</codeph> event. This event is dispatched
 * by the Stage object.</p>
 * @langversion 3.0
 * @playerversion   Flash 10.2
 * @playerversion   AIR (unsupported)
 */

namespace flash
{
    namespace events
    {
        class StageVideoAvailabilityEvent: public Event
        {
            /**
             * Defines the value of the type property of a stageVideoAvailability event object.
             * This event has the following properties:PropertyValueavailabilityThe status reported by the event.bubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the event.targetThe Stage object reporting on the availability of stage video.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            static const std::string STAGE_VIDEO_AVAILABILITY;

            /**
             * Reports the current availability of stage video using a constant of the flash.media.StageVideoAvailability class.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            std::string  availability();

            /**
             * Constructor.
             * @param   type    The type of event. Possible values are: StageVideoAvailabilityEvent.STAGE_VIDEO_AVAILABILITY.
             * @param   bubbles Indicates whether this Event object participates in the bubbling stage of the event flow.
             * @param   cancelable  Indicates whether you can cancel the action that triggers this event.
             * @param   availability    The current availability of stage video.
             * @langversion 3.0
             * @playerversion   Flash 10.2
             * @playerversion   AIR (unsupported)
             */
        public:
            StageVideoAvailabilityEvent(std::string type, bool bubbles, bool cancelable, std::string availability);
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_STAGEVIDEOAVAILABILITYEVENT_AS
#endif // __cplusplus

