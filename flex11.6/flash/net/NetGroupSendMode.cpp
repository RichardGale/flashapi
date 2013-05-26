

    /**
     * The NetGroupSendMode class is an enumeration of constant values used for the <codeph class="+ topic/ph pr-d/codeph ">sendMode</codeph> parameter of the <codeph class="+ topic/ph pr-d/codeph ">NetGroup.sendToNeighbor()</codeph>
     * method.
     * @langversion 3.0
     * @playerversion   Flash 10.1
     * @playerversion   AIR 2
     */


namespace flash {
namespace net {


        /**
         * Specifies the neighbor with the nearest group address in the increasing direction.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string NetGroupSendMode::NEXT_INCREASING   = "nextIncreasing";

        /**
         * Specifies the neighbor with the nearest group address in the decreasing direction.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string NetGroupSendMode::NEXT_DECREASING   = "nextDecreasing";

        NetGroupSendMode::NetGroupSendMode();
}
}

