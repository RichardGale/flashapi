

    /**
     * The NetGroupSendResult class is an enumeration of constant values used for the return value of the
     * Directed Routing methods associated with a NetGroup instance.
     * @langversion 3.0
     * @playerversion   Flash 10.1
     * @playerversion   AIR 2
     */


namespace flash {
namespace net {


        /**
         * Indicates an error occurred (such as no permission) when using a Directed Routing method.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string NetGroupSendResult::ERROR="error";

        /**
         * Indicates no neighbor could be found to route the message toward its requested destination.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string NetGroupSendResult::NO_ROUTE="no route";

        /**
         * Indicates that a route was found for the message and it was forwarded toward its destination.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string NetGroupSendResult::SENT="sent";

        NetGroupSendResult::NetGroupSendResult();
}
}

