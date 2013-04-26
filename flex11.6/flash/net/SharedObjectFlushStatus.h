#if !defined(FLEX11_6_FLASH_NET_SHAREDOBJECTFLUSHSTATUS_AS)
#define FLEX11_6_FLASH_NET_SHAREDOBJECTFLUSHSTATUS_AS
#if defined(__cplusplus)


/**
 * The SharedObjectFlushStatus class provides values for the code returned from a call to the <codeph class="+ topic/ph pr-d/codeph ">SharedObject.flush()</codeph> method.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

namespace flash
{
    namespace net
    {
        class SharedObjectFlushStatus: public Object
        {
            /**
             * Indicates that the flush completed successfully.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string FLUSHED;

            /**
             * Indicates that the user is being prompted to increase disk space for the shared object
             * before the flush can occur.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string PENDING;

        public:
            SharedObjectFlushStatus();
        };
    }
}

#endif // FLEX11_6_FLASH_NET_SHAREDOBJECTFLUSHSTATUS_AS
#endif // __cplusplus

