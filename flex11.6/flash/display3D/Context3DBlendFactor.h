#if !defined(FLEX11_6_FLASH_DISPLAY3D_CONTEXT3DBLENDFACTOR_AS)
#define FLEX11_6_FLASH_DISPLAY3D_CONTEXT3DBLENDFACTOR_AS
#if defined(__cplusplus)



#include "flex11.6.h"



namespace flash
{
    namespace display3D
    {
        class Context3DBlendFactor : public Object
        {
        public:
            static const std::string ONE;
        public:
            static const std::string ZERO;
        public:
            static const std::string SOURCE_ALPHA;
        public:
            static const std::string SOURCE_COLOR;
        public:
            static const std::string ONE_MINUS_SOURCE_ALPHA;
        public:
            static const std::string ONE_MINUS_SOURCE_COLOR;
        public:
            static const std::string DESTINATION_ALPHA;
        public:
            static const std::string DESTINATION_COLOR;
        public:
            static const std::string ONE_MINUS_DESTINATION_ALPHA;
        public:
            static const std::string ONE_MINUS_DESTINATION_COLOR;

        public:
            Context3DBlendFactor();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY3D_CONTEXT3DBLENDFACTOR_AS
#endif // __cplusplus

