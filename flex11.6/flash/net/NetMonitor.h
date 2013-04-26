#if !defined(FLEX11_6_FLASH_NET_NETMONITOR_AS)
#define FLEX11_6_FLASH_NET_NETMONITOR_AS
#if defined(__cplusplus)


#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace net
    {
        class NetStream;
    }
}

/**
 * Dispatched when a new NetStream object is created within the security context of this NetMonitor instance.
 * @eventType   flash.events.NetMonitorEvent.NET_STREAM_CREATE
 */
//[Event(name="netStreamCreate",type="flash.events.NetMonitorEvent")]

/**
 * The NetMonitor class allows you to monitor the NetStream objects used by an application.
 *
 *   <p class="- topic/p ">Use the NetMonitor class to get the current list of NetStream objects in use in an application. An instance of this class
 * dispatches a <codeph class="+ topic/ph pr-d/codeph ">netStreamCreate</codeph> event whenever a new NetStream object is created.</p><p class="- topic/p ">You can use the NetMonitor class to help track video playback and related events without regard to the specific
 * video player being used. This facility can be helpful when implementing media measurement, analytics, and usage tracking
 * libraries.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> NetStream monitoring is not supported by Flash Player in the browser on Android and Blackberry Tablet OS or
 * by AIR on iOS.</p>
 *
 *   EXAMPLE:
 *
 *   This example demonstrates how the NetMonitor class can be used to gain access to
 * NetStream information without intimate knowledge of the specific video player in use.
 * Here, the MediaPlayerSprite class from the Open Screen Media Framework (OSMF) project is used,
 * but any video player could be substituted.
 *
 *   <p class="- topic/p ">You can use the Space bar to pause and unpause the video in the example and the right and left arrows to seek
 * forward or back 30 seconds to see the effects these actions have on the dispatched events.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package
 * {
 * import flash.display.Sprite;
 * import flash.display.StageAlign;
 * import flash.display.StageScaleMode;
 * import flash.events.KeyboardEvent;
 * import flash.events.NetDataEvent;
 * import flash.events.NetMonitorEvent;
 * import flash.events.NetStatusEvent;
 * import flash.net.NetMonitor;
 * import flash.net.NetStream;
 * import flash.ui.Keyboard;
 *
 *   import org.osmf.elements.VideoElement;
 * import org.osmf.media.MediaPlayer;
 * import org.osmf.media.MediaPlayerSprite;
 * import org.osmf.net.DynamicStreamingItem;
 * import org.osmf.net.DynamicStreamingResource;
 *
 *   public class NetMonitorExample extends Sprite
 * {
 * private var netmon:NetMonitor;
 * private var mediaPlayer:MediaPlayer;
 *
 *   public function NetMonitorExample()
 * {
 * //Configure stage
 * this.stage.align = StageAlign.TOP_LEFT;
 * this.stage.scaleMode = StageScaleMode.NO_SCALE;
 *
 *   //Create NetMonitor object
 * netmon = new flash.net.NetMonitor();
 * netmon.addEventListener(NetMonitorEvent.NET_STREAM_CREATE, newNetStream );
 *
 *   //Setup video player
 * var mediaPlayerSprite:MediaPlayerSprite = new MediaPlayerSprite();
 * var videoElement:VideoElement = new VideoElement();
 * var dynResource:DynamicStreamingResource = new DynamicStreamingResource( "rtmp://cp67126.edgefcs.net/ondemand" );
 *
 *   dynResource.streamItems = Vector.&lt;DynamicStreamingItem&gt;(
 * [     new DynamicStreamingItem( "mp4:mediapm/ovp/content/demo/video/elephants_dream/elephants_dream_768x428_24.0fps_408kbps.mp4", 408, 768, 428 )
 * , new DynamicStreamingItem( "mp4:mediapm/ovp/content/demo/video/elephants_dream/elephants_dream_768x428_24.0fps_608kbps.mp4", 608, 768, 428 )
 * , new DynamicStreamingItem( "mp4:mediapm/ovp/content/demo/video/elephants_dream/elephants_dream_1024x522_24.0fps_908kbps.mp4", 908, 1024, 522 )
 * , new DynamicStreamingItem( "mp4:mediapm/ovp/content/demo/video/elephants_dream/elephants_dream_1024x522_24.0fps_1308kbps.mp4", 1308, 1024, 522 )
 * , new DynamicStreamingItem( "mp4:mediapm/ovp/content/demo/video/elephants_dream/elephants_dream_1280x720_24.0fps_1708kbps.mp4", 1708, 1280, 720 )
 * ]);
 *
 *   videoElement.resource = dynResource;
 *
 *   addChild( mediaPlayerSprite );
 * mediaPlayerSprite.media = videoElement;
 * mediaPlayer = mediaPlayerSprite.mediaPlayer;
 * this.stage.addEventListener( KeyboardEvent.KEY_DOWN, keyControl );
 * }
 *
 *   //On new NetStream
 * private function newNetStream( event:NetMonitorEvent ):void
 * {
 * trace( "New Netstream object ");
 * var stream:NetStream = event.netStream;
 * stream.addEventListener(NetDataEvent.MEDIA_TYPE_DATA, onStreamData);
 * stream.addEventListener(NetStatusEvent.NET_STATUS, onStatus);
 * }
 *
 *   //On data events from a NetStream object
 * private function onStreamData( event:NetDataEvent ):void
 * {
 * trace( "Data event at " + event.timestamp );
 * var netStream:NetStream = event.target as NetStream;
 * switch( event.info.handler )
 * {
 * case "onMetaData":
 * trace( "--MetaData: " +  stringify( netStream.info.metaData ));
 * break;
 * case "onXMPData":
 * trace( "--XMPData: " + stringify( netStream.info.xmpData ));
 * break;
 * default:
 * trace( "--" + event.info.handler + ": " + stringify(event.info.args[0]) );
 *
 *   }
 * }
 *
 *   //On status events from a NetStream object
 * private function onStatus( event:NetStatusEvent ):void
 * {
 * trace( "Status: " + stringify( event.info ) );
 * }
 *
 *   //Utility function to print out object properties
 * private function stringify( object:Object ):String
 * {
 * var string:String = "";
 *
 *   var prop:String;
 * var comma:Boolean = false;
 * for ( prop in object )
 * {
 * if( comma ) string += ", ";
 * else comma = true;
 *
 *   if( typeof(object[prop]) == "object" )
 * {
 * stringify( object[prop] )
 * } else    string +=  prop + " = " + object[prop];
 * }
 * return string;
 * }
 *
 *   //Simple keyboard control for the video player
 * private function keyControl( event:KeyboardEvent ):void
 * {
 * switch ( event.keyCode )
 * {
 * case Keyboard.SPACE:
 * if( mediaPlayer.paused ) mediaPlayer.play();
 * else mediaPlayer.pause();
 * break;
 * case Keyboard.RIGHT:
 * mediaPlayer.seek( mediaPlayer.currentTime + 30 );
 * break;
 * case Keyboard.LEFT:
 * mediaPlayer.seek( mediaPlayer.currentTime - 30 );
 * break;
 * default:
 * //do nothing
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10.3
 * @playerversion   Flash AIR  2.7
 */
using namespace flash::events;
using namespace flash::net;

namespace flash
{
    namespace net
    {
        class NetMonitor: public EventDispatcher
        {
            /**
             * Retrieves all NetStream objects belonging to this NetMonitor object's security context.
             *
             *   Avoid caching the list of NetStream objects. Maintaining a reference to these NetStream objects
             * can introduce memory leaks into an application by preventing the garbage collector from reclaiming
             * an object's resources when it is no longer being used.Note: if the NetStream monitoring is not supported on the current platform, the list returned by
             * this function is always empty.
             * @return  Vector of NetStream objects
             * @langversion 3.0
             * @playerversion   Flash 10.3
             * @playerversion   Flash AIR  2.7
             */
        public:
            std::vector<flash::net::NetStream *> *listStreams();

        public:
            NetMonitor();
        };
    }
}

#endif // FLEX11_6_FLASH_NET_NETMONITOR_AS
#endif // __cplusplus

