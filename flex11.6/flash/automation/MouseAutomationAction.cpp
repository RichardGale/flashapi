


namespace flash {
namespace automation {


        const std::string MouseAutomationAction::MOUSE_DOWN;
        const std::string MouseAutomationAction::MOUSE_MOVE;
        const std::string MouseAutomationAction::MOUSE_UP;
        const std::string MouseAutomationAction::MOUSE_WHEEL;
        const std::string MouseAutomationAction::MIDDLE_MOUSE_DOWN;
        const std::string MouseAutomationAction::MIDDLE_MOUSE_UP;
        const std::string MouseAutomationAction::RIGHT_MOUSE_DOWN;
        const std::string MouseAutomationAction::RIGHT_MOUSE_UP;

        float MouseAutomationAction::stageX()         ;
        void MouseAutomationAction::stageX(float value)       ;

        float MouseAutomationAction::stageY()         ;
        void MouseAutomationAction::stageY(float value)       ;

        int MouseAutomationAction::delta()      ;
        void MouseAutomationAction::delta(int value)       ;

        MouseAutomationAction::MouseAutomationAction(std::string type, float stageX, float stageY, int delta);
}
}

