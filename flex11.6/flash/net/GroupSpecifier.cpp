

#include "GroupSpecifier.h"
#include "flash/utils/ByteArray.h"

    /**
     * The GroupSpecifier class is used to construct the opaque <codeph class="+ topic/ph pr-d/codeph ">groupspec</codeph> strings
     * that can be passed to NetStream and NetGroup constructors.
     * A <codeph class="+ topic/ph pr-d/codeph ">groupspec</codeph> specifies an RTMFP Peer-to-Peer Group, including
     * the capabilities, restrictions, and authorizations of the member using the <codeph class="+ topic/ph pr-d/codeph ">groupspec</codeph>.
     * 
     *   <p class="- topic/p ">By default, all capabilities are disabled, and peer-to-peer connections are allowed.</p>
     * @langversion 3.0
     * @playerversion   Flash 10.1
     * @playerversion   AIR 2
     */

using namespace flash::utils;

namespace flash {
namespace net {


        int GroupSpecifier::maxSupportedGroupspecVersion()      ;

        /**
         * Specifies whether directed routing methods are enabled for the NetGroup.
         * By default, this property is FALSE (directed routing methods are disabled).
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool GroupSpecifier::routingEnabled()          ;
        void GroupSpecifier::routingEnabled(bool enabled)       ;

        /**
         * Specifies whether streaming is enabled for the NetGroup. Methods used for streaming
         * are NetStream.publish(), NetStream.play(), and NetStream.play2().
         * By default, this property is FALSE (streaming is disabled).
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool GroupSpecifier::multicastEnabled()          ;
        void GroupSpecifier::multicastEnabled(bool enabled)       ;

        /**
         * Specifies whether object replication is enabled for the NetGroup.
         * By default, this property is FALSE (object replication is disabled).
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool GroupSpecifier::objectReplicationEnabled()          ;
        void GroupSpecifier::objectReplicationEnabled(bool enabled)       ;

        /**
         * Specifies whether posting is enabled for the NetGroup.
         * By default, this property is FALSE (posting is disabled).
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool GroupSpecifier::postingEnabled()          ;
        void GroupSpecifier::postingEnabled(bool enabled)       ;

        /**
         * Specifies whether peer-to-peer connections are disabled for the NetGroup or NetStream.
         * By default, this property is FALSE (P2P connections are enabled).
         * 
         *   If P2P connections are disabled (you set this property to TRUE), the P2P warning dialog is suppressed.
         * In this situation, no neighbor connections can be made, and no group members use upstream bandwidth.
         * Disabling P2P connections in this way is generally useful only when receiving multicast streams via pure IP multicast.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool GroupSpecifier::peerToPeerDisabled()          ;
        void GroupSpecifier::peerToPeerDisabled(bool disable)       ;

        /**
         * Specifies whether information about group membership can be exchanged on IP multicast
         * sockets. IP multicast servers may send group membership updates to help bootstrap P2P meshes
         * or heal partitions. Peers may send membership updates on the LAN to help bootstrap LAN P2P
         * meshes and to inform on-LAN neighbors in global meshes that other on-LAN neighbors exist.
         * These updates can improve P2P performance.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool GroupSpecifier::ipMulticastMemberUpdatesEnabled()          ;
        void GroupSpecifier::ipMulticastMemberUpdatesEnabled(bool enabled)       ;

        /**
         * Specifies whether members of the NetGroup can open a channel to the server.
         * By default, this property is FALSE.
         * 
         *   A channel to the server must be opened before the
         * server can provide supporting functions to group members. Depending on server
         * configuration, supporting functions may or may not be provided over this channel.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool GroupSpecifier::serverChannelEnabled()          ;
        void GroupSpecifier::serverChannelEnabled(bool enabled)       ;

        int GroupSpecifier::minGroupspecVersion()      ;
        void GroupSpecifier::minGroupspecVersion(int version)       ;

        /**
         * Encodes and returns a string that represents a posting password. When posting is password-protected,
         * you can concatenate the string to a groupspec to enable posting.
         * @param   password    The password to encode, which must match the posting
         *   password (if set) to enable NetGroup.post().
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string GroupSpecifier::encodePostingAuthorization(std::string password)         ;

        /**
         * Encodes and returns a string that represents a multicast publishing password. When multicast publishing is password-protected,
         * you can concatenate the string to a groupspec to enable publishing.
         * @param   password    The password to encode, which must match the publish
         *   password (if set) to enable NetStream.publish().
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string GroupSpecifier::encodePublishAuthorization(std::string password)         ;

        /**
         * Encodes and returns a string that represents an IP multicast socket address.
         * If you append the string to a groupspec, the associated NetStream or NetGroup
         * joins the specified IP multicast group and listens to the specified UDP port.
         * @param   address A String indicating the address of the IPv4 or IPv6 multicast group to join, optionally followed
         *   by a colon (":") and the UDP port number. If specifying an IPv6 address and a port,
         *   the IPv6 address must be enclosed in square brackets. Examples: "224.0.0.254",
         *   "224.0.0.254:30000", "ff03::ffff", "[ff03::ffff]:30000".
         * @param   port    The UDP port on which to receive IP multicast datagrams. If port is null,
         *   the UDP port must be specified in address. If not null, the
         *   UDP port must not be specified in address.
         * @param   source  If not null, a String specifying the source IP address of a source-specific multicast (SSM).
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string GroupSpecifier::encodeIPMulticastAddressSpec(std::string address, void* port, std::string source)         ;

        /**
         * Encodes and returns a string that represents a bootstrap peerID. If you append the string
         * to a groupspec, the associated NetStream or NetGroup makes an initial neighbor connection to the
         * specified peerID.
         * @param   peerID  The peerID to which an initial neighbor connection should be made to
         *   bootstrap into the peer-to-peer mesh.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string GroupSpecifier::encodeBootstrapPeerIDSpec(std::string peerID)         ;

        /**
         * Creates a new GroupSpecifier object.
         * 
         *   By default, all capabilities are disabled, and peer-to-peer connections are allowed.
         * @param   name    A name for the Group on which all members must agree.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @throws  ArgumentError if name is empty or null.
         */
        GroupSpecifier::GroupSpecifier(std::string name);

        /**
         * Adds a strong pseudorandom tag to the groupspec to make it unique. The opaque groupspec string must then
         * be passed verbatim to other potential members of the Group if they are to successfully join.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        void GroupSpecifier::makeUnique()       ;

        /**
         * Specifies whether a password is required to publish a multicast stream in the NetStream.
         * @param   password    The password that must be given to use NetStream.publish(). If null,
         *   no password is required to publish.
         * @param   salt    Modifies the hash of the password to increase the difficulty of guessing it.
         *   For best security, this parameter should be set to a random value.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        void GroupSpecifier::setPublishPassword(std::string password, std::string salt)       ;

        /**
         * Specifies whether a password is required to post in the NetGroup.
         * @param   password    The password that must be given to use NetGroup.post(). If null,
         *   no password is required to post.
         * @param   salt    Modifies the hash of the password to increase the difficulty of guessing it.
         *   For best security, this parameter should be set to a random value.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        void GroupSpecifier::setPostingPassword(std::string password, std::string salt)       ;

        /**
         * Causes the associated NetStream or NetGroup to make an initial neighbor connection to the
         * specified peerID.
         * @param   peerID  The peerID to which an initial neighbor connection should be made to
         *   bootstrap into the peer-to-peer mesh.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        void GroupSpecifier::addBootstrapPeer(std::string peerID)       ;

        /**
         * Causes the associated NetStream or NetGroup to join the specified IP multicast group and listen
         * to the specified UDP port.
         * @param   address A String specifying the address of the IPv4 or IPv6 multicast group to join, optionally followed
         *   by a colon (":") and the UDP port number. If specifying an IPv6 address and a port,
         *   the IPv6 address must be enclosed in square brackets. Examples: "224.0.0.254",
         *   "224.0.0.254:30000", "ff03::ffff", "[ff03::ffff]:30000".
         * @param   port    The UDP port on which to receive IP multicast datagrams. If port is null,
         *   the UDP port must be specified in address. If not null, the
         *   UDP port must not be specified in address.
         * @param   source  If not null, a String specifying the source IP address of a source-specific multicast (SSM).
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        void GroupSpecifier::addIPMulticastAddress(std::string address, void* port, std::string source)       ;

        /**
         * Identical to the groupspecWithAuthorizations() method.
         * Convenience method to return the opaque groupspec string, including authorizations,
         * that can be passed to NetStream and NetGroup constructors.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string GroupSpecifier::toString()         ;

        /**
         * Returns the opaque groupspec string, without authorizations, that can be passed to NetStream and NetGroup constructors.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string GroupSpecifier::groupspecWithoutAuthorizations()         ;

        /**
         * Returns the opaque groupspec string, including authorizations, that can be passed to NetStream and NetGroup constructors.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string GroupSpecifier::groupspecWithAuthorizations()         ;

        /**
         * Returns a string that represents passwords for IP multicast publishing and for posting.
         * Append the string to an unauthorized groupspec to enable
         * features for which passwords have been set.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string GroupSpecifier::authorizations()         ;
}
}

