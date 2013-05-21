

    /// @eventType  flash.events.StageVideoEvent.RENDER_STATE


namespace flash {
namespace events {


        /**
         * The StageVideoEvent.RENDER_STATE constant defines the value of the type property of a renderState event object. 
         * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.colorSpaceThe available color spaces for displaying the video.currentTargetThe object that is actively processing the StageVideoEvent 
         * object with an event listener.statusIndicates whether the video is being rendered (decoded and displayed) by hardware or software, or not at all.targetThe StageVideo object that changed state.
         * @langversion 3.0
         * @playerversion   AIR 2.5
         * @playerversion   Flash 10.2
         */
        const std::string StageVideoEvent::RENDER_STATE="renderState";

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
        const std::string StageVideoEvent::RENDER_STATUS_UNAVAILABLE="unavailable";

        /**
         * Indicates that software is decoding and displaying the video.
         * 
         *   This value is one of the possible values of the StageVideoEvent object status property.For example, if the platform does not support hardware decoding and display of the audio or video codec
         * of the video, the
         * StageVideoEvent object has this status value.
         * @langversion 3.0
         * @playerversion   AIR 2.5
         */
        const std::string StageVideoEvent::RENDER_STATUS_SOFTWARE="software";

        /**
         * Indicates that hardware is decoding and displaying the video.
         * 
         *   This value is one of the possible values of the StageVideoEvent object status property.
         * @langversion 3.0
         * @playerversion   AIR 2.5
         */
        const std::string StageVideoEvent::RENDER_STATUS_ACCELERATED="accelerated";
                     

        /**
         * The status of the StageVideo object.
         * @langversion 3.0
         * @playerversion   AIR 2.5
         * @playerversion   Flash 10.2
         */
        std::string StageVideoEvent::status()         ;

        /**
         * The color space used by the video being displayed in the StageVideo object.
         * @langversion 3.0
         * @playerversion   AIR 2.5
         * @playerversion   Flash 10.2
         */
        std::string StageVideoEvent::colorSpace()         ;

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
        StageVideoEvent::StageVideoEvent(std::string type, bool bubbles, bool cancelable, std::string status, std::string colorSpace);
}
}

