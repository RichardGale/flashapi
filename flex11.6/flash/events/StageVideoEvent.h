#if !defined(FLEX11_6_FLASH_EVENTS_STAGEVIDEOEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_STAGEVIDEOEVENT_AS
#if defined(__cplusplus)



//[Event(name="renderState",type="flash.events.StageVideoEvent")]/// @eventType  flash.events.StageVideoEvent.RENDER_STATE

/**
 * A StageVideo object dispatches a StageVideoEvent object after the <codeph class="+ topic/ph pr-d/codeph ">attachNetStream()</codeph> method
 * of the StageVideo object and the <codeph class="+ topic/ph pr-d/codeph ">play()</codeph> method of
 * the attached NetStream object have both been called. Also, depending on the platform,
 * any change in the playing status can result in dispatching the event.
 * The one type of StageVideoEvent is <codeph class="+ topic/ph pr-d/codeph ">StageVideoEvent.RENDER_STATE</codeph>.
 * @langversion 3.0
 * @playerversion   AIR 2.5
 * @playerversion   Flash 10.2
 */

namespace flash
{
    namespace events
    {
        class StageVideoEvent: public Event
        {
            /**
             * The StageVideoEvent.RENDER_STATE constant defines the value of the type property of a renderState event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.colorSpaceThe available color spaces for displaying the video.currentTargetThe object that is actively processing the StageVideoEvent
             * object with an event listener.statusIndicates whether the video is being rendered (decoded and displayed) by hardware or software, or not at all.targetThe StageVideo object that changed state.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             * @playerversion   Flash 10.2
             */
        public:
            static const std::string RENDER_STATE;

            /**
             * Indicates that displaying the video using the StageVideo object is not possible.
             *
             *   This value is one of the possible values of the StageVideoEvent object status property.For example, consider a platform that does not support decoding and displaying the video's audio or video codec
             * with either software or hardware. In this case, the StageVideoEvent object has this status value.This status value also is used if no hardware decoders are available. This situation
             * can occur in AIR for TV. For backward compatibility with its previous releases, AIR for TV
             * allows you to use a Video object for hardware decoding and display. By using a Video object, you are using
             * the underlying hardware decoder and therefore you have one less StageVideo object available for use.
             * Note that using a StageVideo object for hardware video decoding and display is recommended.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const std::string RENDER_STATUS_UNAVAILABLE;

            /**
             * Indicates that software is decoding and displaying the video.
             *
             *   This value is one of the possible values of the StageVideoEvent object status property.For example, if the platform does not support hardware decoding and display of the audio or video codec
             * of the video, the
             * StageVideoEvent object has this status value.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const std::string RENDER_STATUS_SOFTWARE;

            /**
             * Indicates that hardware is decoding and displaying the video.
             *
             *   This value is one of the possible values of the StageVideoEvent object status property.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             */
        public:
            static const std::string RENDER_STATUS_ACCELERATED;
        public:
            const std::string codecInfo;

            /**
             * The status of the StageVideo object.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             * @playerversion   Flash 10.2
             */
        public:
            std::string  status();

            /**
             * The color space used by the video being displayed in the StageVideo object.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             * @playerversion   Flash 10.2
             */
        public:
            std::string  colorSpace();

            /**
             * Creates an Event object that contains information about StageVideo events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Event listeners can access this information through the inherited type property. The one type of StageVideoEvent is StageVideoEvent.RENDER_STATE.
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
             * @param   status  Indicates the status of the target StageVideo object.
             * @param   colorSpace  The color space used by the video being displayed.
             * @langversion 3.0
             * @playerversion   AIR 2.5
             * @playerversion   Flash 10.2
             */
        public:
            StageVideoEvent(std::string type, bool bubbles, bool cancelable, std::string status, std::string colorSpace);
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_STAGEVIDEOEVENT_AS
#endif // __cplusplus

