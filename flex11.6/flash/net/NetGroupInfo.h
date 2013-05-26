#if !defined(FLEX11_6_FLASH_NET_NETGROUPINFO_AS)
#define FLEX11_6_FLASH_NET_NETGROUPINFO_AS
#if defined(__cplusplus)


/**
 * The NetGroupInfo class specifies various Quality of Service (QoS) statistics
 * related to a NetGroup object's underlying RTMFP Peer-to-Peer data transport.
 * The <codeph class="+ topic/ph pr-d/codeph ">NetGroup.info</codeph> property returns a NetGroupInfo object which is
 * a snapshot of the current QoS state.
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */

#include "flex11.6.h"



namespace flash
{
    namespace net
    {
        class NetGroupInfo : public Object
        {
            /**
             * Specifies the rate at which the local node is sending posting data to
             * peers, in bytes per second.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            float       postingSendDataBytesPerSecond();

            /**
             * Specifies the rate at which the local node is sending posting control overhead messages to peers, in bytes per second.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            float       postingSendControlBytesPerSecond();

            /**
             * Specifies the rate at which the local node is receiving posting data from
             * peers, in bytes per second.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            float       postingReceiveDataBytesPerSecond();

            /**
             * Specifies the rate at which the local node is receiving posting control overhead messages from peers, in bytes per second.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            float       postingReceiveControlBytesPerSecond();

            /**
             * Specifies the rate at which the local node is sending directed routing messages to
             * peers, in bytes per second.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            float       routingSendBytesPerSecond();

            /**
             * Specifies the rate at which the local node is receiving directed routing messages
             * from peers, in bytes per second.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            float       routingReceiveBytesPerSecond();

            /**
             * Specifies the rate at which objects are being copied from the local node to peers
             * by the Object Replication system, in bytes per second.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            float       objectReplicationSendBytesPerSecond();

            /**
             * Specifies the rate at which the local node is receiving objects from
             * peers via the Object Replication system, in bytes per second.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            float       objectReplicationReceiveBytesPerSecond();

        public:
            NetGroupInfo(float postingSendDataBytesPerSecond, float postingSendControlBytesPerSecond, float postingReceiveDataBytesPerSecond, float postingReceiveControlBytesPerSecond, float routingSendBytesPerSecond, float routingReceiveBytesPerSecond, float objectReplicationSendBytesPerSecond, float objectReplicationReceiveBytesPerSecond);

            /**
             * Returns a string containing the values of the properties of the NetGroupInfo object.
             * @return  A string containing the values of the properties of the NetGroupInfo object
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string   toString();
        };
    }
}

#endif // FLEX11_6_FLASH_NET_NETGROUPINFO_AS
#endif // __cplusplus

