

#include "Microphone.h"
#include "flash/events/EventDispatcher.h"
#include "flash/media/Microphone.h"
#include "flash/media/SoundTransform.h"
#include "flash/media/MicrophoneEnhancedOptions.h"

    /**
     * Dispatched when a microphone reports its status.
     * @eventType   flash.events.StatusEvent.STATUS
     */

using namespace flash::events;
using namespace flash::media;

namespace flash {
namespace media {


        /**
         * An array of strings containing the names of all available sound capture devices. 
         * The names are returned without 
         * having to display the Flash Player Privacy Settings panel to the user. This array 
         * provides the zero-based index of each sound capture device and the 
         * number of sound capture devices on the system, through the Microphone.names.length property. 
         * For more information, see the Array class entry.
         * 
         *   Calling Microphone.names requires an extensive examination of the hardware, and it
         * may take several seconds to build the array. In most cases, you can just use the default microphone.Note: To determine the name of the current microphone, 
         * use the name property.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        std::vector<void*> Microphone::names()        ;

        /**
         * The isSupported property is set to true if the 
         * Microphone class is supported on the current platform, otherwise it is
         * set to false.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool Microphone::isSupported()          ;

        void Microphone::gain(float gain)       ;

        void Microphone::rate(int rate)       ;
        /**
         * The rate at which the microphone is capturing sound, in kHz. Acceptable values are 5, 8, 11, 22, and 44. The default value is 8 
         * kHz if your sound capture device supports this value. Otherwise, the default value is the next available capture level above 8 kHz
         * that your sound capture device supports, usually 11 kHz.
         * 
         *   Note: The actual rate differs slightly from the rate value, as noted
         * in the following table:rate valueActual frequency4444,100 Hz2222,050 Hz1111,025 Hz88,000 Hz55,512 Hz
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        int Microphone::rate()      ;

        void Microphone::codec(std::string codec)       ;
        /**
         * The codec to use for compressing audio. Available codecs are Nellymoser (the default) and Speex. The enumeration class SoundCodec contains
         * the various values that are valid for the codec property.
         * 
         *   If you use the Nellymoser codec, you can set the sample rate using Microphone.rate(). 
         * If you use the Speex codec, the sample rate is set to 16 kHz.Speex includes voice activity detection (VAD) and automatically reduces bandwidth when no voice is detected. 
         * When using the Speex codec, Adobe recommends that you set the silence level to 0. To set the silence level, use the
         * Microphone.setSilenceLevel() method.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::string Microphone::codec()         ;

        /**
         * Number of Speex speech frames transmitted in a packet (message). 
         * Each frame is 20 ms long. The default value is two frames per packet.
         * 
         *   The more Speex frames in a message, the lower the bandwidth required but the longer the delay in sending the
         * message. Fewer Speex frames increases bandwidth required but reduces delay.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        int Microphone::framesPerPacket()      ;
        void Microphone::framesPerPacket(int frames)       ;

        /**
         * The encoded speech quality when using the Speex codec. Possible values are from 0 to 10. The default value is 6. 
         * Higher numbers represent higher quality but require more bandwidth, as shown in the following table. The bit rate values that are listed 
         * represent net bit rates and do not include packetization overhead.
         * Quality valueRequired bit rate (kilobits per second)0 3.9515.7527.7539.80412.8516.8620.6723.8827.8934.21042.2
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        int Microphone::encodeQuality()      ;
        void Microphone::encodeQuality(int quality)       ;

        /**
         * Maximum attenuation of the noise in dB (negative number) used for Speex encoder. If enabled, noise suppression is applied to sound captured from Microphone before
         * Speex compression. Set to 0 to disable noise suppression. Noise suppression is enabled by default with maximum attenuation of -30 dB. Ignored when Nellymoser
         * codec is selected.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        int Microphone::noiseSuppressionLevel()      ;
        void Microphone::noiseSuppressionLevel(int level)       ;

        /**
         * Enable Speex voice activity detection.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool Microphone::enableVAD()          ;
        void Microphone::enableVAD(bool enable)       ;

        /**
         * The amount of sound the microphone is detecting. Values range from 
         * 0 (no sound is detected) to 100 (very loud sound is detected). The value of this property can 
         * help you determine a good value to pass to the Microphone.setSilenceLevel() method.
         * 
         *   If the microphone muted property is true, the value of this property is always -1.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        float Microphone::activityLevel()         ;

        /**
         * The amount by which the microphone boosts the signal. Valid values are 0 to 100. The default value is 50.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        float Microphone::gain()         ;

        /**
         * The index of the microphone, as reflected in the array returned by 
         * Microphone.names.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        int Microphone::index()      ;

        /**
         * Specifies whether the user has denied access to the microphone (true) 
         * or allowed access (false). When this value changes, 
         * a status event is dispatched.
         * For more information, see Microphone.getMicrophone().
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        bool Microphone::muted()          ;

        /**
         * The name of the current sound capture device, as returned by the sound capture hardware.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        std::string Microphone::name()         ;

        /**
         * The amount of sound required to activate the microphone and dispatch 
         * the activity event. The default value is 10.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        float Microphone::silenceLevel()         ;

        /**
         * The number of milliseconds between the time the microphone stops 
         * detecting sound and the time the activity event is dispatched. The default 
         * value is 2000 (2 seconds).
         * 
         *   To set this value, use the Microphone.setSilenceLevel() method.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        int Microphone::silenceTimeout()      ;

        /**
         * Set to true if echo suppression is enabled; false otherwise. The default value is 
         * false unless the user has selected Reduce Echo in the Flash Player Microphone Settings panel.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        bool Microphone::useEchoSuppression()          ;

        /**
         * Controls the sound of this microphone object when it is in loopback mode.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @internal    Document this better with examples.
         */
        flash::media::SoundTransform* Microphone::soundTransform()                             ;
        void Microphone::soundTransform(SoundTransform* sndTransform)       ;

        /**
         * Controls enhanced microphone options. For more information, see  
         * MicrophoneEnhancedOptions class. This property is ignored for non-enhanced Microphone instances.
         * @langversion 3.0
         * @playerversion   Flash 10.3
         * @playerversion   AIR 2.7
         */
        flash::media::MicrophoneEnhancedOptions* Microphone::enhancedOptions()                                        ;
        void Microphone::enhancedOptions(MicrophoneEnhancedOptions* options)       ;

        /**
         * Returns a reference to a Microphone object for capturing audio.
         * To begin capturing the audio, you must attach the Microphone
         * object to a NetStream object (see NetStream.attachAudio()).
         * 
         *   Multiple calls to Microphone.getMicrophone() reference the same microphone. 
         * Thus, if your code contains the lines mic1 = Microphone.getMicrophone() 
         * and
         * mic2 = Microphone.getMicrophone()  
         * , both mic1 and mic2 
         * reference the same (default) microphone.
         * In general, you should not pass a value for index. Simply call 
         * air.Microphone.getMicrophone()
         * to return a reference to the default microphone. 
         * Using the Microphone Settings section in the Flash Player settings panel, the user can specify the default 
         * microphone the application should use. (The user access the Flash Player settings panel by right-clicking
         * Flash Player content running in a web browser.) If you pass a value for index, you can 
         * reference a microphone other than the one the user chooses. You can use index in 
         * rare cases   for example, if your application is capturing audio from two microphones 
         * at the same time. Content running in Adobe AIR also uses the Flash Player setting for the default 
         * microphone.
         * Use the Microphone.index property to get the index value of the current
         * Microphone object. You can then pass this value to other methods of the
         * Microphone class.
         * 
         *   When a SWF file tries to access the object returned by Microphone.getMicrophone()
         *    for example, when you call NetStream.attachAudio()   
         * Flash Player displays a Privacy dialog box that lets the user choose whether to 
         * allow or deny access to the microphone. (Make sure your Stage size is at least 
         * 215 x 138 pixels; this is the minimum size Flash Player requires to display the dialog box.)
         * 
         *   When the user responds to this dialog box, a status event is dispatched
         * that indicates the user's response. You can also check the Microphone.muted
         * property to determine if the user has allowed or denied access to the microphone.
         * 
         *   If Microphone.getMicrophone() returns null, either the microphone is in use 
         * by another application, or there are no microphones installed on the system. To determine 
         * whether any microphones are installed, use Microphones.names.length. To display 
         * the Flash Player Microphone Settings panel, which lets the user choose the microphone to be 
         * referenced by Microphone.getMicrophone, use Security.showSettings().
         * @param   index   The index value of the microphone.
         * @return  A reference to a Microphone object for capturing audio.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        flash::media::Microphone* Microphone::getMicrophone(int index)                         ;

        Microphone::Microphone();

        /**
         * Returns a reference to an enhanced Microphone object that can 
         * perform acoustic echo cancellation. Use acoustic echo cancellation to create audio/video chat applications
         * that don't require headsets.
         * 
         *   The index parameter for the Microphone.getEnhancedMicrophone() method and the Microphone.getMicrophone()
         * method work the same way.Important: At any given time you can have only a single instance of enhanced microphone device.
         * All other Microphone instances stop providing audio data and receive a StatusEvent with the 
         * code property Microphone.Unavailable. When enhanced audio fails to initialize, 
         * calls to this method return null, setting a value for Microphone.enhancedOptions has no effect, 
         * and all existing Microphone instances function as before.To configure an enhanced Microphone object, set the Microphone.enhancedOptions property. The following
         * code uses an enhanced Microphone object and full-duplex acoustic echo cancellation in a local test:
         * var mic:Microphone = Microphone.getEnhancedMicrophone();
         * var options:MicrophoneEnhancedOptions = new MicrophoneEnhancedOptions();
         * options.mode = MicrophoneEnhancedMode.FULL_DUPLEX;
         * mic.enhancedOptions = options;
         * mic.setLoopBack(true);
         * The setUseEchoSuppression() method is ignored when using acoustic echo cancellation.
         * 
         *   When a SWF file tries to access the object returned by Microphone.getEnhancedMicrophone()
         *    for example, when you call NetStream.attachAudio()   
         * Flash Player displays a Privacy dialog box that lets the user choose whether to 
         * allow or deny access to the microphone. (Make sure your Stage size is at least 
         * 215 x 138 pixels; this is the minimum size Flash Player requires to display the dialog box.)
         * @param   index   The index value of the microphone.
         * @return  A reference to a Microphone object for capturing audio. If enhanced audio fails to initialize, returns null.
         * @langversion 3.0
         * @playerversion   Flash 10.3
         * @playerversion   AIR 2.7
         */
        flash::media::Microphone* Microphone::getEnhancedMicrophone(int index)                         ;

        /**
         * Sets the minimum input level that should be considered sound and (optionally) the amount
         * of silent time signifying that silence has actually begun.
         * To prevent the microphone from detecting sound at all, pass a value of 100 for 
         * silenceLevel; the activity event is never dispatched. To determine the amount of sound the microphone is currently detecting, use Microphone.activityLevel. Speex includes voice activity detection (VAD) and automatically reduces bandwidth when no voice is detected. 
         * When using the Speex codec, Adobe recommends that you set the silence level to 0.Activity detection is the ability to detect when audio levels suggest that a person is talking. 
         * When someone is not talking, bandwidth can be saved because there is no need to send the associated
         * audio stream. This information can also be used for visual feedback so that users know 
         * they (or others) are silent.Silence values correspond directly to activity values. Complete silence is an activity value of 0. 
         * Constant loud noise (as loud as can be registered based on the current gain setting) is an activity value 
         * of 100. After gain is appropriately adjusted, your activity value is less than your silence value when
         * you're not talking; when you are talking, the activity value exceeds your silence value.This method is similar to Camera.setMotionLevel(); both methods are used to
         * specify when the activity event is dispatched. However, these methods have 
         * a significantly different impact on publishing streams:Camera.setMotionLevel() is designed to detect motion and does not affect bandwidth
         * usage. Even if a video stream does not detect motion, video is still sent.Microphone.setSilenceLevel() is designed to optimize bandwidth. When an audio
         * stream is considered silent, no audio data is sent. Instead, a single message is sent, indicating 
         * that silence has started.
         * @param   silenceLevel    The amount of sound required to activate the microphone
         *   and dispatch the activity event. Acceptable values range from 0 to 100.
         * @param   timeout The number of milliseconds that must elapse without
         *   activity before Flash Player or Adobe AIR considers sound to have stopped and dispatches the 
         *   dispatch event. The default value is 2000 (2 seconds). 
         *   (Note: The default value shown 
         *   in the signature, -1, is an internal value that indicates to Flash Player or Adobe AIR to use 2000.)
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        void Microphone::setSilenceLevel(float silenceLevel, int timeout)       ;

        /**
         * Specifies whether to use the echo suppression feature of the audio codec. The default value is 
         * false unless the user has selected Reduce Echo in the Flash Player Microphone 
         * Settings panel.
         * 
         *   Echo suppression is an effort to reduce the effects of audio feedback, which is caused when
         * sound going out the speaker is picked up by the microphone on the same system. (This is different
         * from acoustic echo cancellation, which completely removes the feedback. The setUseEchoSuppression() method
         * is ignored when you call the getEnhancedMicrophone() method to use acoustic echo cancellation.)Generally, echo suppression is advisable when the sound being captured is played through 
         * speakers     instead of a headset    . If your SWF file allows users to specify the
         * sound output device, you may want to call Microphone.setUseEchoSuppression(true) 
         * if they indicate they are using speakers and will be using the microphone as well. Users can also adjust these settings in the Flash Player Microphone Settings panel.
         * @param   useEchoSuppression  A Boolean value indicating whether to use echo suppression 
         *   (true) or not (false).
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        void Microphone::setUseEchoSuppression(bool useEchoSuppression)       ;

        /**
         * Routes audio captured by a microphone to the local speakers.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @internal    Document this better with examples.
         */
        void Microphone::setLoopBack(bool state)       ;
}
}

