

    /**
     * The NetGroupReplicationStrategy class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">replicationStrategy</codeph> property
     * of the <codeph class="+ topic/ph pr-d/codeph ">NetGroup</codeph> class.
     * @langversion 3.0
     * @playerversion   Flash 10.1
     * @playerversion   AIR 2
     */


namespace flash {
namespace net {


        /**
         * Specifies that when fetching objects from a neighbor to satisfy a want, the objects with
         * the fewest replicas among all the neighbors are requested first.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string NetGroupReplicationStrategy::RAREST_FIRST="rarestFirst";

        /**
         * Specifies that when fetching objects from a neighbor to satisfy a want, the objects with the
         * lowest index numbers are requested first.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string NetGroupReplicationStrategy::LOWEST_FIRST="lowestFirst";

        NetGroupReplicationStrategy::NetGroupReplicationStrategy();
}
}

