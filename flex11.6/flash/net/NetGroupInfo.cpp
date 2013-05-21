

    /**
     * The NetGroupInfo class specifies various Quality of Service (QoS) statistics
     * related to a NetGroup object's underlying RTMFP Peer-to-Peer data transport.
     * The <codeph class="+ topic/ph pr-d/codeph ">NetGroup.info</codeph> property returns a NetGroupInfo object which is
     * a snapshot of the current QoS state.
     * @langversion 3.0
     * @playerversion   Flash 10.1
     * @playerversion   AIR 2
     */


namespace flash {
namespace net {


        /**
         * Specifies the rate at which the local node is sending posting data to
         * peers, in bytes per second.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        float NetGroupInfo::postingSendDataBytesPerSecond()         ;

        /**
         * Specifies the rate at which the local node is sending posting control overhead messages to peers, in bytes per second.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        float NetGroupInfo::postingSendControlBytesPerSecond()         ;

        /**
         * Specifies the rate at which the local node is receiving posting data from
         * peers, in bytes per second.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        float NetGroupInfo::postingReceiveDataBytesPerSecond()         ;

        /**
         * Specifies the rate at which the local node is receiving posting control overhead messages from peers, in bytes per second.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        float NetGroupInfo::postingReceiveControlBytesPerSecond()         ;

        /**
         * Specifies the rate at which the local node is sending directed routing messages to
         * peers, in bytes per second.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        float NetGroupInfo::routingSendBytesPerSecond()         ;

        /**
         * Specifies the rate at which the local node is receiving directed routing messages 
         * from peers, in bytes per second.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        float NetGroupInfo::routingReceiveBytesPerSecond()         ;

        /**
         * Specifies the rate at which objects are being copied from the local node to peers
         * by the Object Replication system, in bytes per second.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        float NetGroupInfo::objectReplicationSendBytesPerSecond()         ;

        /**
         * Specifies the rate at which the local node is receiving objects from
         * peers via the Object Replication system, in bytes per second.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        float NetGroupInfo::objectReplicationReceiveBytesPerSecond()         ;

        NetGroupInfo::NetGroupInfo(float postingSendDataBytesPerSecond, float postingSendControlBytesPerSecond, float postingReceiveDataBytesPerSecond, float postingReceiveControlBytesPerSecond, float routingSendBytesPerSecond, float routingReceiveBytesPerSecond, float objectReplicationSendBytesPerSecond, float objectReplicationReceiveBytesPerSecond);

        /**
         * Returns a string containing the values of the properties of the NetGroupInfo object.
         * @return  A string containing the values of the properties of the NetGroupInfo object
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string NetGroupInfo::toString()         ;
}
}

