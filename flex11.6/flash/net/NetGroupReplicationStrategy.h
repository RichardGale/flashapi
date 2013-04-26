#if !defined(FLEX11_6_FLASH_NET_NETGROUPREPLICATIONSTRATEGY_AS)
#define FLEX11_6_FLASH_NET_NETGROUPREPLICATIONSTRATEGY_AS
#if defined(__cplusplus)


/**
 * The NetGroupReplicationStrategy class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">replicationStrategy</codeph> property
 * of the <codeph class="+ topic/ph pr-d/codeph ">NetGroup</codeph> class.
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */

namespace flash
{
    namespace net
    {
        class NetGroupReplicationStrategy: public Object
        {
            /**
             * Specifies that when fetching objects from a neighbor to satisfy a want, the objects with
             * the fewest replicas among all the neighbors are requested first.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string RAREST_FIRST;

            /**
             * Specifies that when fetching objects from a neighbor to satisfy a want, the objects with the
             * lowest index numbers are requested first.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string LOWEST_FIRST;

        public:
            NetGroupReplicationStrategy();
        };
    }
}

#endif // FLEX11_6_FLASH_NET_NETGROUPREPLICATIONSTRATEGY_AS
#endif // __cplusplus

