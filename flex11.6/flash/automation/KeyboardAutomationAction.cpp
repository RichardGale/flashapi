


namespace flash {
namespace automation {


        const std::string KeyboardAutomationAction::KEY_DOWN;
        const std::string KeyboardAutomationAction::KEY_UP;

        unsigned int KeyboardAutomationAction::keyCode()       ;
        void KeyboardAutomationAction::keyCode(unsigned int value)       ;

        KeyboardAutomationAction::KeyboardAutomationAction(std::string type, unsigned int keyCode);
}
}

