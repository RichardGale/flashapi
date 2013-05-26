#if !defined(FLEX11_6_FLASH_NET_NETGROUP_AS)
#define FLEX11_6_FLASH_NET_NETGROUP_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace net
    {
        class NetConnection;
    }
}
namespace flash
{
    namespace net
    {
        class NetGroupInfo;
    }
}

/**
 * Dispatched when a NetGroup object is reporting its status or error condition.
 * @eventType   flash.events.NetStatusEvent.NET_STATUS
 */
//[Event(name="netStatus",type="flash.events.NetStatusEvent")]

using namespace flash::events;
using namespace flash::net;

namespace flash
{
    namespace net
    {
        /**
         * Instances of the NetGroup class represent membership in an RTMFP group. Use this class
         * to do the following:
         *
         *   <ul class="- topic/ul "><li class="- topic/li "><b class="+ topic/ph hi-d/b ">Monitor Quality of Service</b>. The <codeph class="+ topic/ph pr-d/codeph ">info</codeph> property contains a NetGroupInfo object whose properties provide
         * QoS statistics for this group.</li><li class="- topic/li "><b class="+ topic/ph hi-d/b ">Posting</b>. Call <codeph class="+ topic/ph pr-d/codeph ">post()</codeph> to broadcast ActionScript messages to all members of a group.</li><li class="- topic/li "><b class="+ topic/ph hi-d/b ">Direct routing</b>. Call <codeph class="+ topic/ph pr-d/codeph ">sendToNearest()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">sendToNeighbor()</codeph>, and
         * <codeph class="+ topic/ph pr-d/codeph ">sendToAllNeighbors()</codeph> to send a short data message to a specific member of a peer-to-peer group.
         * The source and the destination do not need to have a direct connection.</li><li class="- topic/li "><b class="+ topic/ph hi-d/b ">Object replication</b>. Call <codeph class="+ topic/ph pr-d/codeph ">addHaveObjects()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">removeHaveObjects()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">addWantObjects()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">removeWantObjects()</codeph>,
         * <codeph class="+ topic/ph pr-d/codeph ">writeRequestedObject()</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">denyRequestedObject()</codeph> to break up large data into pieces and replicate it to all nodes in a peer-to-peer group.</li></ul><p class="- topic/p ">In the client-side NetGroup class, the NetConnection dispatches the following events:</p><ul class="- topic/ul "><li class="- topic/li ">NetGroup.Connect.Success</li><li class="- topic/li ">NetGroup.Connect.Failed</li><li class="- topic/li ">NetGroup.Connect.Rejected</li></ul><p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">info.group</codeph> property of the event object contains a reference to the event source (the NetGroup).
         * The NetGroup dispatches all other events. In the server-side NetGroup class, the NetGroup dispatches all events.</p><p class="- topic/p ">For information about peer-assisted networking, see <xref href="http://www.flashrealtime.com/basics-of-p2p-in-flash/" scope="external" class="- topic/xref ">
         * Basics of P2P in Flash</xref> by Adobe Evangelist Tom Krcha. For information about using groups with peer-assisted networking, see
         * <xref href="http://tv.adobe.com/watch/max-2009-develop/social-media-experiences-with-flash-media-and-rtmfp/" scope="external" class="- topic/xref ">Social Media Experiences with Flash Media
         * and RTMFP</xref>, also by Tom Krcha.</p><p class="- topic/p ">For information about the technical details behind peer-assisted networking, see <xref href="http://tv.adobe.com/watch/max-2009-develop/p2p-on-the-flash-platform-with-rtmfp" scope="external" class="- topic/xref ">P2P on the Flash Platform with RTMFP</xref> by Adobe Computer Scientist Matthew Kaufman.</p>
         *
         *   EXAMPLE:
         *
         *   This is a simple video chat application that uses peer-to-peer networking.
         * The application connects over RTMFP to Flash Media Server.
         * The server keeps the client applications' fingerprints and manages the peer group as clients connect. However, all data is sent between clients (peers) --
         * data is not sent back to the server.
         * <p class="- topic/p ">When you run the application, you can enter any group name into the text input field. The GroupSpecifier class uses the name (along with any
         * GroupSpecifier properties you've set) to create a string which is the perpetually unique name of the group. To connect another client to the group, that client must use
         * the same group name. For example, if client A uses the group name "firstmesh", other clients that want to communicate with client A must also use the group
         * name "firstmesh". If client B uses the group name "kite", it will connect successfully, but it will create a new group and won't be able to communicate with
         * client A or anyone in the "firstmesh" group.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         *
         *   &lt;?xml version="1.0" encoding="utf-8"?&gt;
         * &lt;mx:Application xmlns:mx="http://www.adobe.com/2006/mxml" layout="absolute" width="100%" height="100%" applicationComplete="OnApplicationComplete()"&gt;
         * &lt;mx:Script&gt;
         * &lt;![CDATA[
         * private var netConnection:NetConnection = null;
         * private var netStream:NetStream = null;
         * private var netGroup:NetGroup = null;
         * private var video:Video = null;
         * private var sequenceNumber:uint = 0;
         * private var resizeTimer:Timer = null;
         *
         *   private const SERVER:String = "rtmfp://fms.example.com/someapp";
         *
         *   [Bindable] private var connected:Boolean = false;
         * [Bindable] private var joinedGroup:Boolean = false;
         *
         *   private function OnApplicationComplete():void
         * {
         * userName.text = "user " + int(Math.random() * 65536);
         *
         *   groupName.text = "channel" + (int(Math.random() * 899) + 101);
         *
         *   resizeTimer = new Timer(2000.0);
         * resizeTimer.addEventListener(TimerEvent.TIMER, DoResizeVideo);
         * resizeTimer.start();
         * }
         *
         *   private function StatusMessage(msg:Object):void
         * {
         * statusLog.text += msg;
         * statusLog.verticalScrollPosition = statusLog.textHeight;
         * statusLog.validateNow();
         * }
         *
         *   private function NetStatusHandler(e:NetStatusEvent):void
         * {
         * StatusMessage(e.info.code);
         * switch(e.info.code)
         * {
         * case "NetConnection.Connect.Success":
         * OnConnect();
         * break;
         *
         *   case "NetConnection.Connect.Closed":
         * case "NetConnection.Connect.Failed":
         * case "NetConnection.Connect.Rejected":
         * case "NetConnection.Connect.AppShutdown":
         * case "NetConnection.Connect.InvalidApp":
         * OnDisconnect();
         * break;
         *
         *   case "NetStream.Connect.Success": // e.info.stream
         * OnNetStreamConnect();
         * break;
         *
         *   case "NetStream.Connect.Rejected": // e.info.stream
         * case "NetStream.Connect.Failed": // e.info.stream
         * DoDisconnect();
         * break;
         *
         *   case "NetGroup.Connect.Success": // e.info.group
         * OnNetGroupConnect();
         * break;
         *
         *   case "NetGroup.Connect.Rejected": // e.info.group
         * case "NetGroup.Connect.Failed": // e.info.group
         * DoDisconnect();
         * break;
         *
         *   case "NetGroup.Posting.Notify": // e.info.message, e.info.messageID
         * OnPosting(e.info.message);
         * break;
         *
         *   case "NetStream.MulticastStream.Reset":
         * case "NetStream.Buffer.Full":
         * DoResizeVideo();
         * break;
         *
         *   case "NetGroup.SendTo.Notify": // e.info.message, e.info.from, e.info.fromLocal
         * case "NetGroup.LocalCoverage.Notify": //
         * case "NetGroup.Neighbor.Connect": // e.info.neighbor
         * case "NetGroup.Neighbor.Disconnect": // e.info.neighbor
         * case "NetGroup.MulticastStream.PublishNotify": // e.info.name
         * case "NetGroup.MulticastStream.UnpublishNotify": // e.info.name
         * case "NetGroup.Replication.Fetch.SendNotify": // e.info.index
         * case "NetGroup.Replication.Fetch.Failed": // e.info.index
         * case "NetGroup.Replication.Fetch.Result": // e.info.index, e.info.object
         * case "NetGroup.Replication.Request": // e.info.index, e.info.requestID
         * default:
         * break;
         * }
         * }
         *
         *   private function DoConnect():void
         * {
         * StatusMessage("Connecting to \"" + SERVER + "\" ...\n");
         * netConnection = new NetConnection();
         * netConnection.addEventListener(NetStatusEvent.NET_STATUS, NetStatusHandler);
         * netConnection.connect(SERVER);
         * }
         *
         *   private function OnConnect():void
         * {
         * var groupSpecifier:GroupSpecifier;
         *
         *   StatusMessage("Connected\n");
         * connected = true;
         *
         *   groupSpecifier = new GroupSpecifier("max2009lab/" + groupName.text);
         * groupSpecifier.multicastEnabled = true;
         * groupSpecifier.postingEnabled = true;
         * groupSpecifier.serverChannelEnabled = true;
         *
         *   netStream = new NetStream(netConnection, groupSpecifier.groupspecWithAuthorizations());
         * netStream.addEventListener(NetStatusEvent.NET_STATUS, NetStatusHandler);
         *
         *   netGroup = new NetGroup(netConnection, groupSpecifier.groupspecWithAuthorizations());
         * netGroup.addEventListener(NetStatusEvent.NET_STATUS, NetStatusHandler);
         *
         *   StatusMessage("Join \"" + groupSpecifier.groupspecWithAuthorizations() + "\"\n");
         * }
         *
         *   private function OnNetStreamConnect():void
         * {
         * netStream.client = this;
         *
         *   var mic:Microphone = Microphone.getMicrophone();
         * if(mic)
         * {
         * mic.codec = SoundCodec.SPEEX;
         * mic.setSilenceLevel(0);
         *
         *   netStream.attachAudio(mic);
         *
         *   StatusMessage("got microphone\n");
         * }
         *
         *   var camera:Camera = Camera.getCamera();
         * if(camera)
         * {
         * camera.setMode(320, 240, 10);
         * camera.setQuality(30000, 0);
         * camera.setKeyFrameInterval(15);
         *
         *   videoDisplay.attachCamera(camera);
         * videoDisplay.maintainAspectRatio = true;
         *
         *   netStream.attachCamera(camera);
         *
         *   StatusMessage("got camera\n");
         * }
         *
         *   netStream.publish("stream");
         * }
         *
         *   private function OnNetGroupConnect():void
         * {
         * joinedGroup = true;
         * }
         *
         *   private function DoDisconnect():void
         * {
         * if(netConnection)
         * netConnection.close();
         * videoDisplay.attachCamera(null);
         * }
         *
         *   private function OnDisconnect():void
         * {
         * StatusMessage("Disconnected\n");
         * netConnection = null;
         * netStream = null;
         * netGroup = null;
         * connected = false;
         * joinedGroup = false;
         * }
         *
         *   private function ClearChatText():void
         * {
         * chatText.text = "";
         * }
         *
         *   private function DoPost():void
         * {
         * var message:Object = new Object;
         *
         *   message.user = userName.text;
         * message.text = chatText.text;
         * message.sequence = sequenceNumber++;
         * message.sender = netConnection.nearID;
         *
         *   netGroup.post(message);
         *
         *   StatusMessage("==&gt; " + chatText.text + "\n");
         *
         *   chatText.callLater(ClearChatText);
         * }
         *
         *   private function OnPosting(message:Object):void
         * {
         * StatusMessage("&lt;" + message.user + "&gt; " + message.text + "\n");
         * }
         *
         *   private function DoResizeVideo(ignored:* = null):void
         * {
         * if(video)
         * {
         * if( (0 == video.videoHeight)
         * || (0 == video.videoWidth)
         * )
         * {
         * video.height = videoDisplay.height;
         * video.width = videoDisplay.width;
         * video.x = 0;
         * video.y = 0;
         * }
         * else
         * {
         * var videoAspect:Number = Number(video.videoWidth) / Number(video.videoHeight);
         * var displayAspect:Number = Number(videoDisplay.width) / Number(videoDisplay.height);
         * var adjustFactor:Number;
         *
         *   if(videoAspect &gt;= displayAspect) // video is wider than display
         * {
         * adjustFactor = Number(video.videoWidth) / Number(videoDisplay.width);
         * video.width = videoDisplay.width;
         * video.height = int(Number(video.videoHeight) / adjustFactor);
         * video.x = 0;
         * video.y = int((videoDisplay.height - video.height) / 2);
         * }
         * else
         * {
         * adjustFactor = Number(video.videoHeight) / Number(videoDisplay.height);
         * video.height = videoDisplay.height;
         * video.width = int(Number(video.videoWidth) / adjustFactor);
         * video.x = int((videoDisplay.width - video.width) / 2);
         * video.y = 0;
         * }
         * }
         * }
         * }
         *
         *   public function onPlayStatus(info:Object):void {}
         * public function onMetaData(info:Object):void {}
         * public function onCuePoint(info:Object):void {}
         * public function onTextData(info:Object):void {}
         *
         *   public function ValidateConnectAllowed(isConnected:Boolean, groupNameText:String):Boolean
         * {
         * return (!isConnected) &amp;&amp; (groupNameText.length &gt; 0);
         * }
         * ]]&gt;
         * &lt;/mx:Script&gt;
         *
         *   &lt;mx:VBox top="10" right="10" left="10" bottom="10" verticalGap="6"&gt;
         * &lt;mx:HBox width="100%"&gt;
         * &lt;mx:Text text="Group:"/&gt;
         * &lt;mx:TextInput id="groupName" width="100%" text="default" enabled="{!connected}"/&gt;
         * &lt;mx:Button label="Connect" click="DoConnect()" enabled="{ValidateConnectAllowed(connected, groupName.text)}" /&gt;
         * &lt;mx:Button label="Disconnect" click="DoDisconnect()" enabled="{connected}" /&gt;
         * &lt;/mx:HBox&gt;
         * &lt;mx:VideoDisplay id="videoDisplay" width="320" height="240" resize="DoResizeVideo()"/&gt;
         * &lt;mx:TextArea id="statusLog" width="100%" height="100%"/&gt;
         * &lt;mx:HBox width="100%"&gt;
         * &lt;mx:TextInput id="userName" width="160" /&gt;
         * &lt;mx:TextInput id="chatText" width="100%" enabled="{joinedGroup}" enter="DoPost()"/&gt;
         * &lt;/mx:HBox&gt;
         * &lt;/mx:VBox&gt;
         *
         *   &lt;/mx:Application&gt;
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        class NetGroup : public flash::events::EventDispatcher
        {
            /**
             * Specifies the object replication fetch strategy. The value is one of the enumerated values
             * in the NetGroupReplicationStrategy class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string       replicationStrategy();
        public:
            void         replicationStrategy(std::string s);

            /**
             * Specifies the estimated number of members of the group, based on local neighbor density and
             * assuming an even distribution of group addresses.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @internal    Q for dev: why would someone use this instead of neighborcount? --brs
             */
        public:
            float       estimatedMemberCount();

            /**
             * Specifies the number of group members to which this node is directly connected.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            float       neighborCount();

            /**
             * Specifies this node's routing receive mode as one of values in the NetGroupReceiveMode enum class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string       receiveMode();
        public:
            void         receiveMode(std::string mode);

            /**
             * Returns a NetGroupInfo object whose properties provide Quality of Service
             * statistics about this NetGroup's RTMFP peer-to-peer data transport.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            flash::net::NetGroupInfo *info();

            /**
             * Specifies the start of the range of group addresses for which this node is the "nearest" and responsible.
             * The range is specified in the increasing direction along the group address ring mod 2256.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string       localCoverageFrom();

            /**
             * Specifies the end of the range of group addresses for which this node is the "nearest" and responsible.
             * The range is specified in the increasing direction along the group address ring mod 2256.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string       localCoverageTo();

            /**
             * Disconnect from the group and close this NetGroup. This NetGroup is not usable after calling this method.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            void     close();

            /**
             * Constructs a NetGroup on the specified NetConnection object and joins it to the group
             * specified by groupspec.
             *
             *   In most cases, a groupspec has the potential for using the network uplink on the local system.
             * When a NetStream or NetGroup object is constructed with a groupspec, Flash Player displays a Privacy Dialog.
             * The dialog asks whether Flash Player can use the connection to share data with a user's peers.
             * If the user clicks "Allow for this domain", the dialog is not displayed the next time the user connects to this application.
             * If a user does not allow peer-assisted networking, all peer features within the group (posting, directed routing, and object replication, and multicast)
             * are disabled. If permission is allowed, a NetStatusEvent is sent to the NetConnection's event listener
             * with NetGroup.Connect.Success in the code property of the info object.
             * If permission is denied, the code property is NetGroup.Connect.Rejected.
             * Until a NetGroup.Connect.Success event is received, an exception is thrown
             * if you try to call any method of the NetGroup object.Note: When a client subscribes to a native-IP multicast stream, the security dialog is not displayed.
             * @param   connection  A NetConnection object.
             * @param   groupspec   A string specifying the RTMFP peer-to-peer group to join, including its name, capabilities,
             *   restrictions, and the authorizations of this member.
             *
             *     <codeblock>
             *
             *     new NetGroup(myConnection, myGroupSpecifier.groupspecWithAuthorizations());
             *
             *     </codeblock>
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  ArgumentError The NetConnection instance is not connected.
             * @throws  Error The groupspec is invalid.
             */
        public:
            NetGroup(NetConnection *connection, std::string groupspec);

            /**
             * Adds objects from startIndex through endIndex, to the set of objects this node
             * advertises to neighbors as objects for which it fulfills requests. By default,
             * the Have set is empty. Indices must be whole numbers from 0 through 9007199254740992.
             *
             *   For more information about object replication,
             * see "Replicate an object within a group" in Flash Media Server Developer   s Guide.This method sends a NetStatusEvent to the NetGroup's event listener with "NetGroup.Replication.Request"
             * in the code property of the info object. NOTE:  Test for the NetGroup.Neighbor.Connect event before calling this method.
             * @param   startIndex  The beginning of the range of object indices to add to the Have set.
             * @param   endIndex    The end of the range of object indices to add to the Have set.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  RangeError A number passed to this method is less than 0
             *   or greater than 9007199254740992.
             */
        public:
            void     addHaveObjects(float startIndex, float endIndex);

            /**
             * Removes objects from startIndex through endIndex, from the set of objects this node
             * advertises to neighbors as objects for which it fulfills requests.
             * Indices must be whole numbers from 0 through 9007199254740992.
             *
             *   For more information about object replication,
             * see "Replicate an object within a group" in Flash Media Server Developer   s Guide.NOTE:  Test for the NetGroup.Neighbor.Connect event before calling this method.
             * @param   startIndex  The beginning of the range of object indices to remove from the Have set.
             * @param   endIndex    The end of the range of object indices to remove from the Have set.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  RangeError A number passed to this method is less than 0
             *   or greater than 9007199254740992.
             */
        public:
            void     removeHaveObjects(float startIndex, float endIndex);

            /**
             * Adds objects from startIndex through endIndex, to the set of objects to retrieve.
             * Indices must be whole numbers from 0 through 9007199254740992.
             * By default, the Want set is empty.
             *
             *   For more information about object replication,
             * see "Replicate an object within a group" in Flash Media Server Developer   s Guide.This method sends a NetStatusEvent to the NetGroup's event listener with
             * NetGroup.Replication.Fetch.SendNotify
             * in the info.code property. This event is followed by an NetGroup.Replication.Fetch.Failed
             * or NetGroup.Replication.Fetch.Result event.NOTE:  Test for the NetGroup.Neighbor.Connect event before calling this method.
             * @param   startIndex  The beginning of the range of object indices to add to the Want set.
             * @param   endIndex    The end of the range of object indices to add to the Want set.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  RangeError A number passed to this method is less than 0
             *   or greater than 9007199254740992.
             */
        public:
            void     addWantObjects(float startIndex, float endIndex);

            /**
             * Removes objects from startIndex through endIndex, from the set of objects to retrieve.
             * Indices must be whole numbers from 0 through 9007199254740992.
             *
             *   For more information about object replication,
             * see "Replicate an object within a group" in Flash Media Server Developer   s Guide.NOTE:  Test for the NetGroup.Neighbor.Connect event before calling this method.
             * @param   startIndex  The beginning of the range of object indices to remove from the Want set.
             * @param   endIndex    The end of the range of object indices to remove from the Want set.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  RangeError A number passed to this method is less than 0
             *   or greater than 9007199254740992.
             */
        public:
            void     removeWantObjects(float startIndex, float endIndex);

            /**
             * Satisfies the request as received by
             * NetStatusEvent NetGroup.Replication.Request for an object previously
             * advertised with the addHaveObjects() method. The object
             * can be any of the following: An Object, an int, a Number, and a String.
             * The object cannot be a MovieClip.
             *
             *   For more information about object replication,
             * see "Replicate an object within a group" in Flash Media Server Developer   s Guide.NOTE:  Test for the NetGroup.Neighbor.Connect event before calling this method.
             * @param   requestID   The request identifier as given in the NetGroup.Replication.Request event.
             * @param   object  The object corresponding to the index given in the NetGroup.Replication.Request event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            void     writeRequestedObject(int requestID, Object *object);

            /**
             * Denies a request received in a NetStatusEvent
             * NetGroup.Replication.Request for an object previously advertised with
             * addHaveObjects(). The requestor can request this object again unless
             * or until it is withdrawn from the Have set.
             *
             *   For more information about object replication,
             * see "Replicate an object within a group" in Flash Media Server Developer   s Guide.NOTE:  Test for the NetGroup.Neighbor.Connect event before calling this method.
             * @param   requestID   The request identifier as given in the NetGroup.Replication.Request event.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            void     denyRequestedObject(int requestID);

            /**
             * Converts a peerID to a group address suitable for use with the sendToNearest() method.
             * @param   peerID  The peerID to convert.
             * @return  The group address for the peerID.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string   convertPeerIDToGroupAddress(std::string peerID);

            /**
             * Sends a message to all members of a group. To call this method,
             * the GroupSpecifier.postingEnabled property must be true in the groupspec passed to the
             * NetGroup constructor. For more information, see "Post messages to a group"
             * in Flash Media Server Developer   s Guide.
             *
             *   All messages must be unique. A message that is identical to one posted
             * earlier might not be propagated. Use a sequence number to make messages unique.Message delivery is not ordered. Message delivery is not guaranteed.Messages are serialized in AMF. The message can be one of the following types:
             * an Object, an int, a Number, or a String. The message cannot be a MovieClip.This method sends a NetStatusEvent to the NetGroup's event listener
             * with "NetGroup.Posting.Notify" in the info.code property. The "NetGroup.Posting.Notify" event
             * is dispatched to the NetGroup on both the client and the server.NOTE:  Test for the NetGroup.Neighbor.Connect event before calling this method.
             * @param   message The message to send to all other members of the group.
             * @return  The messageID of the message if posted, or null on error. The messageID is the hexadecmial of the SHA256 of the raw
             *   bytes of the serialization of the message.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string   post(Object *message);

            /**
             * Sends a message to the neighbor (or local node) nearest to the specified group address.
             * Considers neighbors from the entire ring. Returns NetGroupSendResult.SENT if the message
             * was successfully sent toward its destination.
             *
             *   For more information about routing messages, see
             * "Route messages directly to a peer" in Flash Media Server Developer   s Guide.When a node receives a message, a NetStatusEvent is sent to the NetGroup's event listener
             * with NetGroup.SendTo.Notify
             * in the code property of the info object. NOTE:  Test for the NetGroup.Neighbor.Connect event before calling this method.
             * @param   message The message to send.
             * @param   groupAddress    The group address toward which to route the message.
             * @return  A property of enumeration class NetGroupSendResult indicating the success or failure of the send.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string   sendToNearest(Object *message, std::string groupAddress);

            /**
             * Sends a message to the neighbor specified by the sendMode parameter.
             * Returns NetGroupSendResult.SENT if the message was successfully sent to the requested destination.
             *
             *   For more information about routing messages, see
             * "Route messages directly to a peer" in Flash Media Server Developer   s Guide.When a node receives a message, a NetStatusEvent is sent to the NetGroup's event listener
             * with NetGroup.SendTo.Notify
             * in the code property of the info object. NOTE:  Test for the NetGroup.Neighbor.Connect event before calling this method.
             * @param   message The message to send.
             * @param   sendMode    A property of enumeration class NetGroupSendMode specifying the neighbor to which to send the message.
             * @return  A property of enumeration class NetGroupSendResult indicating the success or failure of the send.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string   sendToNeighbor(Object *message, std::string sendMode);

            /**
             * Sends a message to all neighbors.  Returns NetGroupSendResult.SENT if at least one neighbor was selected.
             *
             *   For more information about routing messages, see
             * "Route messages directly to a peer" in Flash Media Server Developer   s Guide.When a node receives a message, a NetStatusEvent is sent to the NetGroup's event listener
             * with NetGroup.SendTo.Notify
             * in the code property of the info object. NOTE:  Test for the NetGroup.Neighbor.Connect event before calling this method.
             * @param   message The message to send.
             * @return  A property of enumeration class NetGroupSendResult indicating the success or failure of the send.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string   sendToAllNeighbors(Object *message);

            /**
             * Manually adds a neighbor by immediately connecting directly to the specified peerID, which must already be
             * in this group. This direct connection may later be dropped if it is not needed for the topology.
             * @param   peerID  The peerID to which to immediately connect.
             * @return  TRUE for success, FALSE for failure.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            bool  addNeighbor(std::string peerID);

            /**
             * Manually adds a record specifying that peerID is a member of the group.
             * An immediate connection to it is attempted only if it is needed for the topology.
             * @param   peerID  The peerID to add to the set of potential neighbors.
             * @return  TRUE for success, FALSE for failure.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            bool  addMemberHint(std::string peerID);
        };
    }
}

#endif // FLEX11_6_FLASH_NET_NETGROUP_AS
#endif // __cplusplus

