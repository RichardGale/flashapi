#if !defined(FLEX11_6_FLASH_MEDIA_SOUNDTRANSFORM_AS)
#define FLEX11_6_FLASH_MEDIA_SOUNDTRANSFORM_AS
#if defined(__cplusplus)


/**
 * The SoundTransform class contains properties for volume and panning.
 *
 *   EXAMPLE:
 *
 *   The following example loads and plays an MP3 file. As the MP3 file plays,
 * move the mouse or other user input device; the
 * volume and panning change as you move the user input device over the Stage.
 * To run this example, place a file named MySound.mp3 in the same directory as your SWF file.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.display.StageAlign;
 * import flash.display.StageScaleMode;
 * import flash.events.*;
 * import flash.media.Sound;
 * import flash.media.SoundChannel;
 * import flash.media.SoundTransform;
 * import flash.net.URLRequest;
 * import flash.utils.Timer;
 *
 *   public class SoundTransformExample extends Sprite {
 * private var url:String = "MySound.mp3";
 * private var soundFactory:Sound;
 * private var channel:SoundChannel;
 * private var positionTimer:Timer;
 *
 *   public function SoundTransformExample() {
 * stage.align = StageAlign.TOP_LEFT;
 * stage.scaleMode = StageScaleMode.NO_SCALE;
 *
 *   var request:URLRequest = new URLRequest(url);
 * soundFactory = new Sound();
 * soundFactory.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
 * soundFactory.load(request);
 * channel = soundFactory.play();
 * stage.addEventListener(MouseEvent.MOUSE_MOVE, mouseMoveHandler);
 * }
 *
 *   private function ioErrorHandler(event:Event):void {
 * trace("ioErrorHandler: " + event);
 * }
 *
 *   private function setPan(pan:Number):void {
 * trace("setPan: " + pan.toFixed(2));
 * var transform:SoundTransform = channel.soundTransform;
 * transform.pan = pan;
 * channel.soundTransform = transform;
 * }
 *
 *   private function setVolume(volume:Number):void {
 * trace("setVolume: " + volume.toFixed(2));
 * var transform:SoundTransform = channel.soundTransform;
 * transform.volume = volume;
 * channel.soundTransform = transform;
 * }
 *
 *   private function mouseMoveHandler(event:MouseEvent):void {
 * var halfStage:uint = Math.floor(stage.stageWidth / 2);
 * var xPos:uint = event.stageX;
 * var yPos:uint = event.stageY;
 * var value:Number;
 * var pan:Number;
 *
 *   if (xPos &gt; halfStage) {
 * value = xPos / halfStage;
 * pan = value - 1;
 * } else if (xPos &lt; halfStage) {
 * value = (xPos - halfStage) / halfStage;
 * pan = value;
 * } else {
 * pan = 0;
 * }
 *
 *   var volume:Number = 1 - (yPos / stage.stageHeight);
 *
 *   setVolume(volume);
 * setPan(pan);
 *
 *   }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 * @refpath
 */


namespace flash
{
    namespace media
    {
        class SoundTransform : public Object
        {
            /**
             * The volume, ranging from 0 (silent) to 1 (full volume).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @refpath
             */
        public:
            float        volume();
        public:
            void         volume(float volume);

            /**
             * A value, from 0 (none) to 1 (all), specifying how much of the left input is played in the
             * left speaker.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @refpath
             */
        public:
            float        leftToLeft();
        public:
            void         leftToLeft(float leftToLeft);

            /**
             * A value, from 0 (none) to 1 (all), specifying how much of the left input is played in the
             * right speaker.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @refpath
             */
        public:
            float        leftToRight();
        public:
            void         leftToRight(float leftToRight);

            /**
             * A value, from 0 (none) to 1 (all), specifying how much of the right input is played in the
             * right speaker.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @refpath
             */
        public:
            float        rightToRight();
        public:
            void         rightToRight(float rightToRight);

            /**
             * A value, from 0 (none) to 1 (all), specifying how much of the right input is played in the
             * left speaker.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @refpath
             */
        public:
            float        rightToLeft();
        public:
            void         rightToLeft(float rightToLeft);

            /**
             * The left-to-right panning of the sound, ranging from -1 (full pan left)
             * to 1 (full pan right). A value of 0 represents no panning (balanced center between
             * right and left).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @refpath
             */
        public:
            float        pan();
        public:
            void         pan(float panning);

            /**
             * Creates a SoundTransform object.
             * @param   vol The volume, ranging from 0 (silent) to 1 (full volume).
             * @param   panning The left-to-right panning of the sound, ranging from -1 (full pan left)
             *   to 1 (full pan right). A value of 0 represents no panning (center).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @refpath
             */
        public:
            SoundTransform(float vol =1, float panning =0);
        };
    }
}

#endif // FLEX11_6_FLASH_MEDIA_SOUNDTRANSFORM_AS
#endif // __cplusplus

