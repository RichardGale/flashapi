#if !defined(FLEX11_6_FLASH_DISPLAY3D_CONTEXT3DMIPFILTER_AS)
#define FLEX11_6_FLASH_DISPLAY3D_CONTEXT3DMIPFILTER_AS
#if defined(__cplusplus)



namespace flash
{
    namespace display3D
    {
        class Context3DMipFilter: public Object
        {
        public:
            static const std::string MIPNONE;
        public:
            static const std::string MIPNEAREST;
        public:
            static const std::string MIPLINEAR;

        public:
            Context3DMipFilter();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY3D_CONTEXT3DMIPFILTER_AS
#endif // __cplusplus

