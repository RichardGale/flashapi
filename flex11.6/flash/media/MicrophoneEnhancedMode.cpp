

    /**
     * The MicrophoneEnhancedMode class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">mode</codeph> property
     * of <codeph class="+ topic/ph pr-d/codeph ">MicrophoneEnhancedOptions</codeph> class.
     * @langversion 3.0
     * @playerversion   Flash 10.3
     * @playerversion   AIR 2.7
     */


namespace flash {
namespace media {


        /**
         * Use this mode to allow both parties to talk at the same time. Acoustic echo cancellation operates in full-duplex mode. 
         * Full-duplex mode is the highest quality echo cancellation.  This mode requires
         * high-quality microphones and speakers and the most computing power. Do not use this mode with a USB microphone.
         * @langversion 3.0
         * @playerversion   Flash 10.3
         * @playerversion   AIR 2.7
         */
        const std::string MicrophoneEnhancedMode::FULL_DUPLEX   = "fullDuplex";

        /**
         * Use this mode for older and lower-quality speakers and microphones. Acoustic echo cancellation operates in half-duplex mode. 
         * In half-duplex mode, only one party can speak at a time. Half-duplex mode requires simpler
         * processing than full-duplex mode. Half-duplex mode is the default mode for USB microphone devices.
         * 
         *   If the application uses the default enhancedOptions setting and a USB mic, Flash Player automatically switches to halfDuplex mode.
         * If the application uses the default enhancedOptions setting and the built-in microphone, Flash Player uses fullDuplex mode.
         * @langversion 3.0
         * @playerversion   Flash 10.3
         * @playerversion   AIR 2.7
         */
        const std::string MicrophoneEnhancedMode::HALF_DUPLEX   = "halfDuplex";

        /**
         * Use this mode when both parties are using headsets. Acoustic echo cancellation operates in low-echo mode. This mode requires the least amount
         * of computing power.
         * @langversion 3.0
         * @playerversion   Flash 10.3
         * @playerversion   AIR 2.7
         */
        const std::string MicrophoneEnhancedMode::HEADSET   = "headset";

        /**
         * Use this mode when the speaker is muted. Acoustic echo cancellation is turned off. Enhanced audio performs
         * noise suppression or automatic gain control (if enabled).
         * @langversion 3.0
         * @playerversion   Flash 10.3
         * @playerversion   AIR 2.7
         */
        const std::string MicrophoneEnhancedMode::SPEAKER_MUTE   = "speakerMute";

        /**
         * All enhanced audio functionality is turned off.
         * @langversion 3.0
         * @playerversion   Flash 10.3
         * @playerversion   AIR 2.7
         */
        const std::string MicrophoneEnhancedMode::OFF   = "off";

        MicrophoneEnhancedMode::MicrophoneEnhancedMode();
}
}

