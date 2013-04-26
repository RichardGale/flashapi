#if !defined(FLEX11_6_FLASH_AUTOMATION_AUTOMATIONACTION_AS)
#define FLEX11_6_FLASH_AUTOMATION_AUTOMATIONACTION_AS
#if defined(__cplusplus)



namespace flash
{
    namespace automation
    {
        class AutomationAction: public Object
        {
        public:
            std::string  type();
        public:
            void         type(std::string value);

        public:
            AutomationAction();
        };
    }
}

#endif // FLEX11_6_FLASH_AUTOMATION_AUTOMATIONACTION_AS
#endif // __cplusplus

