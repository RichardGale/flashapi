#if !defined(FLEX11_6_FLASH_DISPLAY3D_CONTEXT3DSTENCILACTION_AS)
#define FLEX11_6_FLASH_DISPLAY3D_CONTEXT3DSTENCILACTION_AS
#if defined(__cplusplus)



namespace flash
{
    namespace display3D
    {
        class Context3DStencilAction : public Object
        {
        public:
            static const std::string KEEP;
        public:
            static const std::string ZERO;
        public:
            static const std::string INCREMENT_SATURATE;
        public:
            static const std::string DECREMENT_SATURATE;
        public:
            static const std::string INVERT;
        public:
            static const std::string INCREMENT_WRAP;
        public:
            static const std::string DECREMENT_WRAP;
        public:
            static const std::string SET;

        public:
            Context3DStencilAction();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY3D_CONTEXT3DSTENCILACTION_AS
#endif // __cplusplus

