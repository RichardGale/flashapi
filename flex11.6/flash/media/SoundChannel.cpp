

#include "SoundChannel.h"
#include "flash/events/EventDispatcher.h"
#include "flash/media/SoundTransform.h"

    /**
     * Dispatched when a sound has finished playing.
     * @eventType   flash.events.Event.SOUND_COMPLETE
     */

using namespace flash::events;
using namespace flash::media;

namespace flash {
namespace media {


        /**
         * When the sound is playing, the position property indicates in milliseconds the current point
         * that is being played in the sound file. When the sound is stopped or paused, the 
         * position property indicates the last point that was played in the sound file.
         * 
         *   A common use case is to save the value of the position property when the
         * sound is stopped. You can resume the sound later by restarting it from that saved position.
         * If the sound is looped, position is reset to 0 at the beginning of each loop.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        float SoundChannel::position()         ;

        /**
         * The SoundTransform object assigned to the sound channel. A SoundTransform object
         * includes properties for setting volume, panning, left speaker assignment, and right
         * speaker assignment.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @refpath
         */
        flash::media::SoundTransform* SoundChannel::soundTransform()                             ;
        void SoundChannel::soundTransform(SoundTransform* sndTransform)       ;

        /**
         * The current amplitude (volume) of the left channel, from 0 (silent) to 1 (full amplitude).
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @refpath
         */
        float SoundChannel::leftPeak()         ;

        /**
         * The current amplitude (volume) of the right channel, from 0 (silent) to 1 (full amplitude).
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @refpath
         */
        float SoundChannel::rightPeak()         ;

        SoundChannel::SoundChannel();

        /**
         * Stops the sound playing in the channel.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @refpath
         */
        void SoundChannel::stop()       ;
}
}

