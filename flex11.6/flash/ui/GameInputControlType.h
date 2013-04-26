#if !defined(FLEX11_6_FLASH_UI_GAMEINPUTCONTROLTYPE_AS)
#define FLEX11_6_FLASH_UI_GAMEINPUTCONTROLTYPE_AS
#if defined(__cplusplus)



namespace flash
{
    namespace ui
    {
        class GameInputControlType: public Object
        {
        public:
            static const std::string MOVEMENT;
        public:
            static const std::string ROTATION;
        public:
            static const std::string DIRECTION;
        public:
            static const std::string ACCELERATION;
        public:
            static const std::string BUTTON;
        public:
            static const std::string TRIGGER;

        public:
            GameInputControlType();
        };
    }
}

#endif // FLEX11_6_FLASH_UI_GAMEINPUTCONTROLTYPE_AS
#endif // __cplusplus

