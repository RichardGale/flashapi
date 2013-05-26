

    /**
     * The NetStreamPlayTransitions class specifies the valid strings that you can use with the 
     * <codeph class="+ topic/ph pr-d/codeph ">NetStreamPlayOptions.transition</codeph> property. These strings control the 
     * behavior that is used to transition to a new stream or to play a stream, depending on the
     * transition mode that is used.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace net {


        /**
         * Adds the stream to a playlist and begins playback with the first stream. This mode does the same thing as the NetStream.play() 
         * method with the reset flag set to false.
         * 
         *   In this mode, Flash Media Server queues up the stream specified in NetStreamPlayOptions.streamName 
         * at the end of the playlist and ignores the NetStreamPlayOptions.oldStreamName parameter.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string NetStreamPlayTransitions::APPEND   = "append";

        /**
         * Clears any previous play calls and plays the specified stream immediately.
         * This mode does the same thing as the NetStream.play() method with the reset flag set to true
         * (the default behavior for NetStream.play()).
         * 
         *   In this mode, the currently playing stream is flushed and the stream specified in NetStreamPlayOptions.streamName starts to play.
         * The NetStreamPlayOptions.oldStreamName parameter is ignored.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string NetStreamPlayTransitions::RESET   = "reset";

        /**
         * Switches from playing one stream to another stream, typically with streams of the same content.
         * Specify the streams to switch in NetStreamPlayOptions.oldStreamName and NetStreamPlayOptions.streamName.
         * 
         *   Use this mode when you want to switch to a stream that has the same content but is encoded 
         * at a different bit rate or resolution. For example, use this mode when the application queues up streams in a playlist
         * or is playing a single stream at a particular bit rate, then calculates that the bandwidth availability 
         * or the CPU capability is either lower or higher than the stream requirements. The application can then 
         * update the streams with their higher or lower bit rate versions.In this mode, Flash Media Server makes certain assumptions about the relationship between the 
         * oldStreamName and streamName streams.
         * The server assumes that the streams contain the same content and have the same keyframe interval but have different 
         * resolutions or bit rates.When a playlist has been queued up and oldStreamName is one of the streams in the playlist or is currently playing, 
         * oldStreamName is replaced by streamName.If oldStreamName is null or undefined, or if it is not found in the playlist,
         * the server switches to streamName at the next logical point, to ensure a smooth switch.To switch from one stream to another with different content, use the SWAP mode instead.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string NetStreamPlayTransitions::SWITCH   = "switch";

        /**
         * Replaces a content stream with a different content stream and maintains the rest of the playlist.
         * 
         *   This mode replaces the stream specified in NetStreamPlayOptions.oldStreamName 
         * with the stream specified in NetStreamPlayOptions.streamName. The rest of the playlist is maintained. 
         * In this mode, Flash Media Server does not make assumptions about the content of the streams and treats 
         * them like different content. If oldStreamName has not yet been sent, the server performs the switch
         * at the stream boundary and sends the bits for streamName from the beginning.
         * If the server has already started sending the bits for oldStreamName, it doesn't switch to streamName,
         * and a NetStream.Play.Failed event is sent.Use this mode if the streams you want to switch are not related to each other and have different content or lengths. For example,
         * use this mode when you want to swap one commercial for another based on user tracking and past commercial-viewing statistics.To switch from one stream to another with the same content, use the SWITCH mode instead.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string NetStreamPlayTransitions::SWAP   = "swap";

        /**
         * Stops playing the streams in a playlist. This mode does the same thing as calling NetStream.play(false). 
         * It stops and resets the playlist.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string NetStreamPlayTransitions::STOP   = "stop";

        /**
         * Requests data from the new connection starting from the point at which the previous connection ended.
         * The RESUME mode aligns the stream across the two connections so no artifacts or jumps are observed 
         * in the video playback. Use this mode when you reconnect a stream that was dropped due to server issues 
         * or other connection problems.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        const std::string NetStreamPlayTransitions::RESUME   = "resume";

        /**
         * Builds a playlist without starting to play it from the first stream.
         * 
         *   The APPEND_AND_WAIT transition mode is used with the NetStream.play2() method to build a playlist without 
         * immediately starting to play it from the first stream. Use this mode to load each item in the playlist except the last one. 
         * When you load the last stream in the playlist, set the transition mode to RESUME. 
         * At this point, Flash Player begins to stream and play the playlist.You can use this mode to build a playlist from scratch, or to rebuild a playlist after a lost connection is recovered. 
         * For a new playlist, when NetStream.play2() is called with RESUME, Flash Player begins streaming 
         * and playing from the first stream, or from the start position specified.
         * To recover from a lost connection, when you call the NetStream.play2() method with 
         * RESUME, Flash Player determines where the stream was interrupted and instructs the server to start streaming from that location.
         * The server in turn is able to determine which stream in the playlist corresponds to that location, and starts streaming from that location.This transition mode is in contrast to the APPEND mode, where playback starts immediately with the first stream.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @playerversion   Lite 4
         */
        const std::string NetStreamPlayTransitions::APPEND_AND_WAIT   = "appendAndWait";

        NetStreamPlayTransitions::NetStreamPlayTransitions();
}
}

