#if !defined(FLEX11_6_FLASH_AUTOMATION_ACTIONGENERATOR_AS)
#define FLEX11_6_FLASH_AUTOMATION_ACTIONGENERATOR_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace automation
    {
        class AutomationAction;
    }
}

using namespace flash::automation;

namespace flash
{
    namespace automation
    {
        class ActionGenerator : public Object
        {
        public:
            ActionGenerator();

        public:
            void     generateActions(std::vector<void *> a);

        public:
            void     generateAction(AutomationAction *action);
        };
    }
}

#endif // FLEX11_6_FLASH_AUTOMATION_ACTIONGENERATOR_AS
#endif // __cplusplus

