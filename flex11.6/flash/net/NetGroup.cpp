

#include "NetGroup.h"
#include "flash/events/EventDispatcher.h"
#include "flash/net/NetConnection.h"
#include "flash/net/NetGroupInfo.h"

    /**
     * Dispatched when a NetGroup object is reporting its status or error condition.
     * @eventType   flash.events.NetStatusEvent.NET_STATUS
     */

using namespace flash::events;
using namespace flash::net;

namespace flash {
namespace net {


        /**
         * Specifies the object replication fetch strategy. The value is one of the enumerated values
         * in the NetGroupReplicationStrategy class.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string NetGroup::replicationStrategy()         ;
        void NetGroup::replicationStrategy(std::string s)       ;

        /**
         * Specifies the estimated number of members of the group, based on local neighbor density and
         * assuming an even distribution of group addresses.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @internal    Q for dev: why would someone use this instead of neighborcount? --brs
         */
        float NetGroup::estimatedMemberCount()         ;

        /**
         * Specifies the number of group members to which this node is directly connected.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        float NetGroup::neighborCount()         ;

        /**
         * Specifies this node's routing receive mode as one of values in the NetGroupReceiveMode enum class.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string NetGroup::receiveMode()         ;
        void NetGroup::receiveMode(std::string mode)       ;

        /**
         * Returns a NetGroupInfo object whose properties provide Quality of Service
         * statistics about this NetGroup's RTMFP peer-to-peer data transport.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        flash::net::NetGroupInfo* NetGroup::info()                         ;

        /**
         * Specifies the start of the range of group addresses for which this node is the "nearest" and responsible.
         * The range is specified in the increasing direction along the group address ring mod 2256.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string NetGroup::localCoverageFrom()         ;

        /**
         * Specifies the end of the range of group addresses for which this node is the "nearest" and responsible.
         * The range is specified in the increasing direction along the group address ring mod 2256.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string NetGroup::localCoverageTo()         ;

        /**
         * Disconnect from the group and close this NetGroup. This NetGroup is not usable after calling this method.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        void NetGroup::close()       ;

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
        NetGroup::NetGroup(NetConnection* connection, std::string groupspec);

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
        void NetGroup::addHaveObjects(float startIndex, float endIndex)       ;

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
        void NetGroup::removeHaveObjects(float startIndex, float endIndex)       ;

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
        void NetGroup::addWantObjects(float startIndex, float endIndex)       ;

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
        void NetGroup::removeWantObjects(float startIndex, float endIndex)       ;

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
        void NetGroup::writeRequestedObject(int requestID, Object* object)       ;

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
        void NetGroup::denyRequestedObject(int requestID)       ;

        /**
         * Converts a peerID to a group address suitable for use with the sendToNearest() method.
         * @param   peerID  The peerID to convert.
         * @return  The group address for the peerID.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string NetGroup::convertPeerIDToGroupAddress(std::string peerID)         ;

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
        std::string NetGroup::post(Object* message)         ;

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
        std::string NetGroup::sendToNearest(Object* message, std::string groupAddress)         ;

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
        std::string NetGroup::sendToNeighbor(Object* message, std::string sendMode)         ;

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
        std::string NetGroup::sendToAllNeighbors(Object* message)         ;

        /**
         * Manually adds a neighbor by immediately connecting directly to the specified peerID, which must already be
         * in this group. This direct connection may later be dropped if it is not needed for the topology.
         * @param   peerID  The peerID to which to immediately connect.
         * @return  TRUE for success, FALSE for failure.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool NetGroup::addNeighbor(std::string peerID)          ;

        /**
         * Manually adds a record specifying that peerID is a member of the group.
         * An immediate connection to it is attempted only if it is needed for the topology.
         * @param   peerID  The peerID to add to the set of potential neighbors.
         * @return  TRUE for success, FALSE for failure.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool NetGroup::addMemberHint(std::string peerID)          ;
}
}

