#if !defined(FLEX11_6_FLASH_AUTOMATION_MOUSEAUTOMATIONACTION_AS)
#define FLEX11_6_FLASH_AUTOMATION_MOUSEAUTOMATIONACTION_AS
#if defined(__cplusplus)



#include "flex11.6.h"



namespace flash
{
    namespace automation
    {
        class MouseAutomationAction : public AutomationAction
        {
        public:
            static const std::string MOUSE_DOWN;
        public:
            static const std::string MOUSE_MOVE;
        public:
            static const std::string MOUSE_UP;
        public:
            static const std::string MOUSE_WHEEL;
        public:
            static const std::string MIDDLE_MOUSE_DOWN;
        public:
            static const std::string MIDDLE_MOUSE_UP;
        public:
            static const std::string RIGHT_MOUSE_DOWN;
        public:
            static const std::string RIGHT_MOUSE_UP;

        public:
            float       stageX();
        public:
            void         stageX(float value);

        public:
            float       stageY();
        public:
            void         stageY(float value);

        public:
            int          delta();
        public:
            void         delta(int value);

        public:
            MouseAutomationAction(std::string type, float stageX=0, float stageY=0, int delta=0);
        };
    }
}

#endif // FLEX11_6_FLASH_AUTOMATION_MOUSEAUTOMATIONACTION_AS
#endif // __cplusplus

