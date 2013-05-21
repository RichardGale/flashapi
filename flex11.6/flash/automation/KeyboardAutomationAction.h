#if !defined(FLEX11_6_FLASH_AUTOMATION_KEYBOARDAUTOMATIONACTION_AS)
#define FLEX11_6_FLASH_AUTOMATION_KEYBOARDAUTOMATIONACTION_AS
#if defined(__cplusplus)



namespace flash
{
    namespace automation
    {
        class KeyboardAutomationAction : public AutomationAction
        {
        public:
            static const std::string KEY_DOWN;
        public:
            static const std::string KEY_UP;

        public:
            unsigned int keyCode();
        public:
            void         keyCode(unsigned int value);

        public:
            KeyboardAutomationAction(std::string type, unsigned int keyCode=0);
        };
    }
}

#endif // FLEX11_6_FLASH_AUTOMATION_KEYBOARDAUTOMATIONACTION_AS
#endif // __cplusplus

