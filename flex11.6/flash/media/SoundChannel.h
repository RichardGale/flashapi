#if !defined(FLEX11_6_FLASH_MEDIA_SOUNDCHANNEL_AS)
#define FLEX11_6_FLASH_MEDIA_SOUNDCHANNEL_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace media
    {
        class SoundTransform;
    }
}

/**
 * Dispatched when a sound has finished playing.
 * @eventType   flash.events.Event.SOUND_COMPLETE
 */
//[Event(name="soundComplete",type="flash.events.Event")]

using namespace flash::events;
using namespace flash::media;

namespace flash
{
    namespace media
    {
        /**
         * The SoundChannel class controls a sound in an application. Every sound
         * is assigned to a sound channel, and the application can have multiple
         * sound channels that are mixed together. The SoundChannel class contains a <codeph class="+ topic/ph pr-d/codeph ">stop()</codeph> method,
         * properties for monitoring the amplitude (volume) of the channel, and a property for assigning a
         * SoundTransform object to the channel.
         *
         *   EXAMPLE:
         *
         *   The following example loads an MP3 file, plays it, and displays
         * information about sound events that take place as the MP3 file is loaded and played.  A Timer
         * object provides updated information about the position of the playhead every 50 milliseconds.
         * To run this example, place a file named MySound.mp3 in the same directory as your SWF file.
         *
         *   <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Sprite;
         * import flash.events.*;
         * import flash.media.Sound;
         * import flash.media.SoundChannel;
         * import flash.net.URLRequest;
         * import flash.utils.Timer;
         *
         *   public class SoundChannelExample extends Sprite {
         * private var url:String = "MySound.mp3";
         * private var soundFactory:Sound;
         * private var channel:SoundChannel;
         * private var positionTimer:Timer;
         *
         *   public function SoundChannelExample() {
         * var request:URLRequest = new URLRequest(url);
         * soundFactory = new Sound();
         * soundFactory.addEventListener(Event.COMPLETE, completeHandler);
         * soundFactory.addEventListener(Event.ID3, id3Handler);
         * soundFactory.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
         * soundFactory.addEventListener(ProgressEvent.PROGRESS, progressHandler);
         * soundFactory.load(request);
         *
         *   channel = soundFactory.play();
         * channel.addEventListener(Event.SOUND_COMPLETE, soundCompleteHandler);
         *
         *   positionTimer = new Timer(50);
         * positionTimer.addEventListener(TimerEvent.TIMER, positionTimerHandler);
         * positionTimer.start();
         * }
         *
         *   private function positionTimerHandler(event:TimerEvent):void {
         * trace("positionTimerHandler: " + channel.position.toFixed(2));
         * }
         *
         *   private function completeHandler(event:Event):void {
         * trace("completeHandler: " + event);
         * }
         *
         *   private function id3Handler(event:Event):void {
         * trace("id3Handler: " + event);
         * }
         *
         *   private function ioErrorHandler(event:Event):void {
         * trace("ioErrorHandler: " + event);
         * positionTimer.stop();
         * }
         *
         *   private function progressHandler(event:ProgressEvent):void {
         * trace("progressHandler: " + event);
         * }
         *
         *   private function soundCompleteHandler(event:Event):void {
         * trace("soundCompleteHandler: " + event);
         * positionTimer.stop();
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @refpath
         */
        class SoundChannel : public flash::events::EventDispatcher
        {
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
        public:
            float       position();

            /**
             * The SoundTransform object assigned to the sound channel. A SoundTransform object
             * includes properties for setting volume, panning, left speaker assignment, and right
             * speaker assignment.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @refpath
             */
        public:
            flash::media::SoundTransform *soundTransform();
        public:
            void         soundTransform(SoundTransform *sndTransform);

            /**
             * The current amplitude (volume) of the left channel, from 0 (silent) to 1 (full amplitude).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @refpath
             */
        public:
            float       leftPeak();

            /**
             * The current amplitude (volume) of the right channel, from 0 (silent) to 1 (full amplitude).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @refpath
             */
        public:
            float       rightPeak();

        public:
            SoundChannel();

            /**
             * Stops the sound playing in the channel.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @refpath
             */
        public:
            void     stop();
        };
    }
}

#endif // FLEX11_6_FLASH_MEDIA_SOUNDCHANNEL_AS
#endif // __cplusplus

