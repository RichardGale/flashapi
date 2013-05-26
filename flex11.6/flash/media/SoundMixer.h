#if !defined(FLEX11_6_FLASH_MEDIA_SOUNDMIXER_AS)
#define FLEX11_6_FLASH_MEDIA_SOUNDMIXER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}
namespace flash
{
    namespace media
    {
        class SoundTransform;
    }
}

/**
 * The SoundMixer class contains static properties and methods for global sound control
 * in the application. The SoundMixer class controls embedded and streaming sounds in the application.
 * it does not control dynamically created sounds (that is, sounds generated in response
 * to a Sound object dispatching a <codeph class="+ topic/ph pr-d/codeph ">sampleData</codeph> event).
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

using namespace flash::media;
using namespace flash::utils;

namespace flash
{
    namespace media
    {
        class SoundMixer : public Object
        {
            /**
             * The number of seconds to preload an embedded streaming sound into a buffer before it starts
             * to stream. The data in a loaded sound, including its buffer time,
             * cannot be accessed by a SWF file that is in a different domain
             * unless you implement a cross-domain policy file.
             * For more information about security and sound, see the Sound class description.
             * The data in a loaded sound, including its buffer time,
             * cannot be accessed by code in a file that is in a different domain
             * unless you implement a cross-domain policy file. However, in the application sandbox
             * in an AIR application, code can access data in sound files from any source.
             * For more information about security and sound, see the Sound class description.The SoundMixer.bufferTime property only affects the buffer time
             * for embedded streaming sounds in a SWF and is independent of dynamically created
             * Sound objects (that is, Sound objects created in ActionScript).
             * The value of SoundMixer.bufferTime cannot override
             * or set the default of the buffer time specified in the SoundLoaderContext object
             * that is passed to the Sound.load() method.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @refpath
             */
        public:
            static int          bufferTime();
        public:
            static void         bufferTime(int bufferTime);

            /**
             * The SoundTransform object that controls global sound properties. A SoundTransform object
             * includes properties for setting volume, panning, left speaker assignment, and right
             * speaker assignment. The SoundTransform object used in this property provides final sound settings
             * that are applied to all sounds after any individual sound settings are applied.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @refpath
             */
        public:
            static flash::media::SoundTransform *soundTransform();
        public:
            static void         soundTransform(SoundTransform *sndTransform);

        public:
            static std::string       audioPlaybackMode();
        public:
            static void         audioPlaybackMode(std::string value);

        public:
            static bool      useSpeakerphoneForVoice();
        public:
            static void         useSpeakerphoneForVoice(bool value);

        public:
            SoundMixer();

            /**
             * Stops all sounds currently playing.
             *
             *   >In Flash Professional, this method does not stop the playhead.
             * Sounds set to stream will resume playing as the playhead moves over the frames in which they
             * are located.When using this property, consider the following security model: By default, calling the SoundMixer.stopAll() method stops
             * only sounds in the same security sandbox as the object that is calling the method.
             * Any sounds whose playback was not started from the same sandbox as the calling object
             * are not stopped.When you load the sound, using the load() method of the Sound class, you can
             * specify a context parameter, which is a SoundLoaderContext object. If you set the
             * checkPolicyFile  property of the SoundLoaderContext object to true,
             * Flash Player or Adobe AIR
             * checks for a cross-domain policy file on the server from which the sound is loaded. If the server has a
             * cross-domain policy file, and the file permits the domain of the calling content, then the file can stop the loaded
             * sound by using the SoundMixer.stopAll() method; otherwise it cannot.However, in Adobe AIR, content in the application security sandbox (content
             * installed with the AIR application) are not restricted by these security limitations.For more information related to security, see the Flash Player Developer Center Topic:
             * Security.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static void     stopAll();

            /**
             * Takes a snapshot of the current sound wave and places it into the specified ByteArray object.
             * The values are formatted as normalized floating-point values, in the range -1.0 to 1.0.
             * The ByteArray object passed to the outputArray parameter is overwritten with the new values.
             * The size of the ByteArray object created is fixed to 512 floating-point values, where the
             * first 256 values represent the left channel, and the second 256 values represent
             * the right channel.
             *
             *   Note: This method is subject to local file security restrictions and
             * restrictions on cross-domain loading. If you are working with local files or sounds loaded from a server in a
             * different domain than the calling content, you might need to address sandbox restrictions
             * through a cross-domain policy file. For more information, see the Sound class description.
             * In addition, this method cannot be used to extract data from RTMP streams, even when
             * it is called by content that reside in the same domain as the RTMP server.This method is supported over RTMP in Flash Player 9.0.115.0
             * and later and in Adobe AIR. You can control access to streams on
             * Flash Media Server in a server-side script. For more information, see the Client.audioSampleAccess
             * and Client.videoSampleAccess properties in
             * Server-Side ActionScript Language Reference for Adobe Flash Media Server.
             * @param   outputArray A ByteArray object that holds the values associated with the sound.
             *   If any sounds are not available due to security restrictions
             *   (areSoundsInaccessible == true), the outputArray object
             *   is left unchanged. If all sounds are stopped, the outputArray object is
             *   filled with zeros.
             * @param   FFTMode A Boolean value indicating whether a Fourier transformation is performed
             *   on the sound data first. Setting this parameter to true causes the method to return a
             *   frequency spectrum instead of the raw sound wave. In the frequency spectrum, low frequencies
             *   are represented on the left and high frequencies are on the right.
             * @param   stretchFactor   The resolution of the sound samples.
             *   If you set the stretchFactor value to 0, data is sampled at 44.1 KHz;
             *   with a value of 1, data is sampled at 22.05 KHz; with a value of 2, data is sampled 11.025 KHz;
             *   and so on.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @internal    Should confirm if the floating point numbers are single- or double-precision.
             */
        public:
            static void     computeSpectrum(ByteArray *outputArray, bool FFTMode=false, int stretchFactor=0);

            /**
             * Determines whether any sounds are not accessible due to security restrictions. For example,
             * a sound loaded from a domain other than that of the content calling this method is not accessible if
             * the server for the sound has no URL policy file that grants access to
             * the domain of that domain. The sound can still be loaded and played, but low-level
             * operations, such as getting ID3 metadata for the sound, cannot be performed on
             * inaccessible sounds.
             *
             *   For AIR application content in the application security sandbox, calling this method always
             * returns false. All sounds, including those loaded from other domains, are accessible
             * to content in the application security sandbox.
             * @return  The string representation of the boolean.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @refpath
             */
        public:
            static bool  areSoundsInaccessible();
        };
    }
}

#endif // FLEX11_6_FLASH_MEDIA_SOUNDMIXER_AS
#endif // __cplusplus

