#if !defined(FLEX11_6_FLASH_NET_NETSTREAMAPPENDBYTESACTION_AS)
#define FLEX11_6_FLASH_NET_NETSTREAMAPPENDBYTESACTION_AS
#if defined(__cplusplus)


/**
 * The NetStreamAppendBytesAction class is an enumeration of the constants you can pass to the <codeph class="+ topic/ph pr-d/codeph ">NetStream.appendBytesAction()</codeph> method.
 *
 *   <p class="- topic/p ">Two of the constants indicate a timescale discontinuity. Every FLV tag has a timestamp indicating its position in the timescale.
 * Timestamps are used to synchronize video, audio, and script data playback. Timestamps for FLV tags of the same type
 * (video, audio, script data) must not decrease as the FLV progresses.</p>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */

#include "flex11.6.h"



namespace flash
{
    namespace net
    {
        class NetStreamAppendBytesAction : public Object
        {
            /**
             * Indicates a timescale discontinuity. Flushes the FIFO (composed of an incomplete FLV tag) and resets the timescale to begin at the timestamp of the next appended message.
             * On the next call to appendBytes(), the byte parser expects a file header and starts at the beginning of a file.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string RESET_BEGIN;

            /**
             * Indicates a timescale discontinuity. Flushes the FIFO (composed of an incomplete FLV tag) and resets the timescale to begin at the timestamp of the next appended message.
             * On the next call to appendBytes(), the byte parser expects the beginning of an FLV tag, as though you   ve just done a seek to
             * a location in the same FLV, on a tag boundary.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string RESET_SEEK;

            /**
             * Indicates that the media stream data is complete.  For some codecs, such as H.264, the byte parser waits for
             * the buffer to fill to a certain point before beginning playback.  Pass END_SEQUENCE to tell the byte parser to
             * begin playback immediately.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string END_SEQUENCE;

        public:
            NetStreamAppendBytesAction();
        };
    }
}

#endif // FLEX11_6_FLASH_NET_NETSTREAMAPPENDBYTESACTION_AS
#endif // __cplusplus

