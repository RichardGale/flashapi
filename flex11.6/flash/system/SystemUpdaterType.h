#if !defined(FLEX11_6_FLASH_SYSTEM_SYSTEMUPDATERTYPE_AS)
#define FLEX11_6_FLASH_SYSTEM_SYSTEMUPDATERTYPE_AS
#if defined(__cplusplus)


/**
 * The SystemUpdaterType class provides constants for a system update. These constants
 * are used in the <codeph class="+ topic/ph pr-d/codeph ">SystemUpdater.update()</codeph> function.
 *
 *   <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note</b>: The SystemUpdater API is supported on desktop platforms.</p>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 */


namespace flash
{
    namespace system
    {
        class SystemUpdaterType : public Object
        {
            /**
             * Updates the player runtime itself.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             */
        public:
            static const std::string SYSTEM;

            /**
             * Updates the DRM module.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             */
        public:
            static const std::string DRM;

        public:
            SystemUpdaterType();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_SYSTEMUPDATERTYPE_AS
#endif // __cplusplus

