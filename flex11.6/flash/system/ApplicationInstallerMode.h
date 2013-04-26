#if !defined(FLEX11_6_FLASH_SYSTEM_APPLICATIONINSTALLERMODE_AS)
#define FLEX11_6_FLASH_SYSTEM_APPLICATIONINSTALLERMODE_AS
#if defined(__cplusplus)



namespace flash
{
    namespace system
    {
        class ApplicationInstallerMode: public Object
        {
        public:
            static const std::string INSTALL_ONLY;
        public:
            static const std::string SHORTCUTS_ONLY;
        public:
            static const std::string INSTALL_WITH_SHORTCUTS;

        public:
            ApplicationInstallerMode();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_APPLICATIONINSTALLERMODE_AS
#endif // __cplusplus

