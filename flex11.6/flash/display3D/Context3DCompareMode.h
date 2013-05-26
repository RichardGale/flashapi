#if !defined(FLEX11_6_FLASH_DISPLAY3D_CONTEXT3DCOMPAREMODE_AS)
#define FLEX11_6_FLASH_DISPLAY3D_CONTEXT3DCOMPAREMODE_AS
#if defined(__cplusplus)



#include "flex11.6.h"



namespace flash
{
    namespace display3D
    {
        class Context3DCompareMode : public Object
        {
        public:
            static const std::string ALWAYS;
        public:
            static const std::string NEVER;
        public:
            static const std::string LESS;
        public:
            static const std::string LESS_EQUAL;
        public:
            static const std::string EQUAL;
        public:
            static const std::string GREATER_EQUAL;
        public:
            static const std::string GREATER;
        public:
            static const std::string NOT_EQUAL;

        public:
            Context3DCompareMode();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY3D_CONTEXT3DCOMPAREMODE_AS
#endif // __cplusplus

