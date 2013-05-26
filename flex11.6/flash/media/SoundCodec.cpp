

    /**
     * The SoundCodec class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">codec</codeph> property
     * of the <codeph class="+ topic/ph pr-d/codeph ">Microphone</codeph> class.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     */


namespace flash {
namespace media {


        /**
         * Specifies that the Nellymoser codec be used for compressing audio.
         * This constant is the default value of the Microphone.codec property.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string SoundCodec::NELLYMOSER   = "NellyMoser";

        /**
         * Specifies that the Speex codec be used for compressing audio.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        const std::string SoundCodec::SPEEX   = "Speex";
        const std::string SoundCodec::PCMA  ;
        const std::string SoundCodec::PCMU  ;

        SoundCodec::SoundCodec();
}
}

