

    /**
     * The SharedObjectFlushStatus class provides values for the code returned from a call to the <codeph class="+ topic/ph pr-d/codeph ">SharedObject.flush()</codeph> method.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */


namespace flash {
namespace net {


        /**
         * Indicates that the flush completed successfully.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string SharedObjectFlushStatus::FLUSHED   = "flushed";

        /**
         * Indicates that the user is being prompted to increase disk space for the shared object
         * before the flush can occur.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string SharedObjectFlushStatus::PENDING   = "pending";

        SharedObjectFlushStatus::SharedObjectFlushStatus();
}
}

