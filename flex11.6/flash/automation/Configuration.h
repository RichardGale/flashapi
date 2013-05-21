#if !defined(FLEX11_6_FLASH_AUTOMATION_CONFIGURATION_AS)
#define FLEX11_6_FLASH_AUTOMATION_CONFIGURATION_AS
#if defined(__cplusplus)



namespace flash
{
    namespace automation
    {
        class Configuration : public Object
        {
        public:
            static std::string  testAutomationConfiguration();

        public:
            static void         deviceConfiguration(std::string configData);
        public:
            static std::string  deviceConfiguration();

        public:
            Configuration();
        };
    }
}

#endif // FLEX11_6_FLASH_AUTOMATION_CONFIGURATION_AS
#endif // __cplusplus

