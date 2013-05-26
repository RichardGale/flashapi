#if !defined(FLEX11_6_FLASH_NET_NETGROUPSENDMODE_AS)
#define FLEX11_6_FLASH_NET_NETGROUPSENDMODE_AS
#if defined(__cplusplus)


/**
 * The NetGroupSendMode class is an enumeration of constant values used for the <codeph class="+ topic/ph pr-d/codeph ">sendMode</codeph> parameter of the <codeph class="+ topic/ph pr-d/codeph ">NetGroup.sendToNeighbor()</codeph>
 * method.
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */

#include "flex11.6.h"



namespace flash
{
    namespace net
    {
        class NetGroupSendMode : public Object
        {
            /**
             * Specifies the neighbor with the nearest group address in the increasing direction.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string NEXT_INCREASING;

            /**
             * Specifies the neighbor with the nearest group address in the decreasing direction.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string NEXT_DECREASING;

        public:
            NetGroupSendMode();
        };
    }
}

#endif // FLEX11_6_FLASH_NET_NETGROUPSENDMODE_AS
#endif // __cplusplus

