#if !defined(FLEX11_6_FLASH_NET_NETGROUPSENDRESULT_AS)
#define FLEX11_6_FLASH_NET_NETGROUPSENDRESULT_AS
#if defined(__cplusplus)


/**
 * The NetGroupSendResult class is an enumeration of constant values used for the return value of the
 * Directed Routing methods associated with a NetGroup instance.
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */


namespace flash
{
    namespace net
    {
        class NetGroupSendResult : public Object
        {
            /**
             * Indicates an error occurred (such as no permission) when using a Directed Routing method.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string ERROR;

            /**
             * Indicates no neighbor could be found to route the message toward its requested destination.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string NO_ROUTE;

            /**
             * Indicates that a route was found for the message and it was forwarded toward its destination.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string SENT;

        public:
            NetGroupSendResult();
        };
    }
}

#endif // FLEX11_6_FLASH_NET_NETGROUPSENDRESULT_AS
#endif // __cplusplus

