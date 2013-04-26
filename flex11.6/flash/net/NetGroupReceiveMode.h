#if !defined(FLEX11_6_FLASH_NET_NETGROUPRECEIVEMODE_AS)
#define FLEX11_6_FLASH_NET_NETGROUPRECEIVEMODE_AS
#if defined(__cplusplus)


/**
 * The NetGroupReceiveMode class is an enumeration of constant values used for the <codeph class="+ topic/ph pr-d/codeph ">receiveMode</codeph> property
 * of the NetGroup class.
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */

namespace flash
{
    namespace net
    {
        class NetGroupReceiveMode: public Object
        {
            /**
             * Specifies that this node accepts local messages from neighbors only if the address the neighbor uses
             * matches this node's address exactly. That is, this node considers itself as nearest for any
             * NetGroup.sendToNearest() call only if the groupAddress parameter passed to
             * NetGroup.sendToNearest() matches this node's group address exactly.
             * This value is the default setting.
             *
             *   If you want to enable distributed routing behavior, set this value
             * to NetGroupReceiveMode.NEAREST. With this value set, a node waits for its connectivity to stabilize
             * before participating in the Directed Routing mesh.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string EXACT;

            /**
             * Specifies that this node accepts local messages from neighbors that send messages to group
             * addresses that don't match this node's address exactly. Messages are received when this node is nearest among all neighbors whose
             * receive mode is NetGroupReceiveMode.NEAREST. Distance is measured between addresses on the ring mod 2256.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string NEAREST;

        public:
            NetGroupReceiveMode();
        };
    }
}

#endif // FLEX11_6_FLASH_NET_NETGROUPRECEIVEMODE_AS
#endif // __cplusplus

